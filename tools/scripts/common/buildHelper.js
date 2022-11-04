/**@format */

const fs = require("fs");
const path = require("path");

const definition = require("./define");
const { fileExists, StringHelper } = require("./utils");

/**
 * 生成资源文件的导出信息
 *
 * @returns {{source: string target: string}[]}
 */
function generateResource() {
    const baseURL = path.resolve(definition.PROJECT_SOURCE_ENTRY, definition.configure.native.res?.base || "");
    const includeRes = definition.configure.native.res?.includes || [];

    const aResourcesList = [];
    for (const res of includeRes) {
        const resPath = path.resolve(baseURL, res);
        if (fs.existsSync(resPath)) {
            aResourcesList.push({
                source: resPath,
                target: path.resolve(
                    definition.cmake.CMAKE_OUTPUT_HEADER,
                    definition.TIANYU_NATIVE_NATIVE_RES_OUTPUT,
                    definition.TIANYU_NATIVE_NATIVE_RES_NAME,
                    res,
                ),
            });
        }
    }

    return aResourcesList;
}

/**
 *
 * @param {string[]} libList
 *
 * @returns {{name:string;source:{source:string;target:string;}[];buildType:string;exclude: string[];include: string[];}[]}
 */
function generateLibaries(libSrc, libList) {
    const libraries = libSrc || {};

    const libraryList = [];
    for (const lib of Object.keys(libraries)) {
        const libDef = libraries[lib];

        const libName = lib;
        const sourcePaths = libDef.path;
        const isBuild = libDef.build;
        const buildType = libDef.type || "static";
        const exclude = libDef.exclude;
        const include = libDef.include;

        if (!sourcePaths.length || !isBuild) {
            continue;
        }

        const aSourceList = [];
        for (const srcPath of sourcePaths) {
            const absPath = path.resolve(definition.PROJECT_SOURCE_ENTRY, srcPath);
            if (fs.existsSync(absPath)) {
                aSourceList.push({
                    source: absPath,
                    target: path.resolve(definition.cmake.CMAKE_OUTPUT_HEADER, srcPath),
                });
            }
        }

        const aExcludeList = [];
        for (const file of exclude) {
            const absURL = path.resolve(definition.PROJECT_SOURCE_ENTRY, file);
            if (fileExists(absURL)) {
                aExcludeList.push(absURL);
            }
        }

        const aIncludeList = [];
        for (const file of include) {
            const absURL = path.resolve(definition.PROJECT_SOURCE_ENTRY, file);
            if (aExcludeList.includes(absURL)) {
                // exclude优先
                continue;
            }
            if (fileExists(absURL)) {
                aIncludeList.push(absURL);
            }
        }

        const libray = {
            name: libName,
            source: aSourceList,
            buildType: buildType,
            exclude: aExcludeList,
            include: aIncludeList,
        };

        libraryList.push(libray);
        libList && libList.push(libName);

        definition.FULL_CONSOLE_LOG && console.log(`          - detect library: ${libName}`);
    }

    return libraryList;
}

/**
 *
 * @param {string[]} binList
 *
 * @returns {{name: string;src: string[];include: string[];lib: string[];target: string;}[]}
 */
function generateTestBinaries(binList) {
    const binaries = definition.configure.test?.bin || {};

    // get sources
    const aBinaryPath = [];
    for (const bin of Object.keys(binaries)) {
        const binPath = binaries[bin].path;
        const absURL = path.resolve(definition.PROJECT_TEST_SOURCE, binPath);

        if (fs.existsSync(absURL)) {
            aBinaryPath.push({
                name: bin,
                path: absURL,
                target: binPath,
            });
        }
    }

    const testList = [];
    // to check test case and build
    for (const binPath of aBinaryPath) {
        const testConfig = path.resolve(binPath.path, "test.json");
        if (!fileExists(testConfig)) {
            continue;
        }

        const fileData = fs.readFileSync(testConfig, { encoding: "utf-8" }) || "{}";
        const testSrc = JSON.parse(fileData);
        for (const testItem of Object.keys(testSrc)) {
            const testDef = testSrc[testItem];
            const build = testDef.build;
            const sources = testDef.src || [];
            const includes = testDef.include || [];
            const libs = testDef.lib || [];
            if (!build || !sources.length) {
                continue;
            }

            const testId = testItem;

            const aSourceList = [];
            for (const src of sources) {
                const url = path.resolve(binPath.path, src);
                if (fileExists(url)) {
                    aSourceList.push(url);
                }
            }

            const aIncludeList = [];
            for (const src of includes) {
                const url = path.resolve(definition.PROJECT_SOURCE_ENTRY, src);
                if (fileExists(url)) {
                    aIncludeList.push(url);
                }
            }

            const testCase = `${binPath.name}.${testId}`;
            const test = {
                name: testCase,
                src: aSourceList,
                include: aIncludeList,
                lib: libs,
                target: `${testCase}`,
            };

            testList.push(test);
            binList?.push(testCase);
            definition.FULL_CONSOLE_LOG && console.log(`          - detect test case: ${testCase}`);
        }
    }

    return testList;
}

/**
 *
 * @param {{name:string;source:{source:string;target:string;}[];buildType:string;exclude: string[];include: string[];}} lib
 * @param {{source:string;target:string;header:string[];}[]} targetHeader
 * @returns
 */
function prepareLibsContent(lib, targetHeader) {
    const resultLines = [];

    const aBuildFiles = [];
    for (const source of lib.source) {
        const listFile = path.resolve(source.source, "list.json");
        const listData = JSON.parse(fs.readFileSync(listFile, { encoding: "utf-8" }) || `{ "src": [], "header": [] }`);
        const src = listData.src;
        for (const srcFile of src) {
            const url = path.resolve(source.source, srcFile);
            if (fileExists(url) && !lib.exclude.includes(url)) {
                aBuildFiles.push(url);
            }
        }

        targetHeader?.push({
            target: source.target,
            source: source.source,
            header: listData.header,
        });
    }

    for (const include of lib.include) {
        if (!aBuildFiles.includes(include)) {
            aBuildFiles.push(include);
        }
    }

    resultLines.push(`message("   detect lib - ${lib.name}")`);
    resultLines.push(`add_library(${lib.name} ${lib.buildType.toUpperCase()}`);
    for (const file of aBuildFiles) {
        resultLines.push(`    ${StringHelper.replaceAll(file, "\\", "/")}`);
    }
    resultLines.push(`)`);

    return resultLines;
}

/**
 *
 * @param {string[]} insert
 * @returns {string}
 */
function prepareCMakeContent(insert) {
    const resultLines = [];

    // set CMake basic config
    resultLines.push(`cmake_minimum_required(VERSION ${definition.cmake.CMAKE_VERSION})`);
    resultLines.push(
        `project("${definition.cmake.CMAKE_PROJECT_NAME}" LANGUAGES "CXX" VERSION "${definition.cmake.CMAKE_PROJECT_VERSION}")`,
    );

    // set CMake compiler config
    resultLines.push(`set(CMAKE_CXX_STANDARD ${definition.cmake.CMAKE_CPP_STANDARD})`);
    // set for Microsoft Visual Studio
    resultLines.push(`if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")`);
    resultLines.push(`    set(CXX_STANDARD_REQUIRED ON)`);
    resultLines.push(`    message(\${CMAKE_CXX_FLAGS})`);
    resultLines.push(`    set(CMAKE_CXX_FLAGS "\${CMAKE_CXX_FLAGS} /Zc:__cplusplus")`);
    resultLines.push(`endif()`);
    resultLines.push(`set(EXECUTABLE_OUTPUT_PATH ${StringHelper.replaceAll(definition.cmake.CMAKE_OUTPUT_BIN, "\\", "/")})`);
    resultLines.push(
        `set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${StringHelper.replaceAll(definition.cmake.CMAKE_OUTPUT_BIN, "\\", "/")})`,
    );
    resultLines.push(
        `set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${StringHelper.replaceAll(definition.cmake.CMAKE_OUTPUT_BIN, "\\", "/")})`,
    );
    resultLines.push(`set(LIBRARY_OUTPUT_PATH ${StringHelper.replaceAll(definition.cmake.CMAKE_OUTPUT_LIB, "\\", "/")})`);
    resultLines.push(
        `set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${StringHelper.replaceAll(definition.cmake.CMAKE_OUTPUT_LIB, "\\", "/")})`,
    );
    resultLines.push(
        `set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${StringHelper.replaceAll(definition.cmake.CMAKE_OUTPUT_LIB, "\\", "/")})`,
    );
    resultLines.push(
        `set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${StringHelper.replaceAll(definition.cmake.CMAKE_OUTPUT_LIB, "\\", "/")})`,
    );
    resultLines.push(
        `set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${StringHelper.replaceAll(definition.cmake.CMAKE_OUTPUT_LIB, "\\", "/")})`,
    );
    // set development state
    if (definition.DEVELOPMENT_MODE) {
        resultLines.push(`ADD_DEFINITIONS(-D__DTY_DEV_MODE__)`);
    }

    // in progress
    resultLines.push(`message("------------------------ start build ------------------------")`);
    resultLines.push(`message("项目(Project): ${definition.cmake.CMAKE_PROJECT_NAME}")`);
    resultLines.push(`message("版本(Version): ${definition.cmake.CMAKE_PROJECT_VERSION}")`);

    resultLines.push(...insert);

    resultLines.push(`message("------------------------     end     ------------------------")`);

    return resultLines.join("\r\n");
}

/**
 *
 * @param {{name: string;src: string[];include: string[];lib: string[];target: string;}} bin
 * @returns
 */
function prepareBinContent(bin) {
    const resultLines = [];

    const binTarget = StringHelper.replaceAll(bin.target, "\\", "/");

    resultLines.push(``);
    resultLines.push(`message("   detect test - ${bin.name}")`);
    resultLines.push(`add_executable(`);
    resultLines.push(`    ${binTarget}`);
    resultLines.push(``);
    for (const url of bin.src) {
        resultLines.push(`    ${StringHelper.replaceAll(url, "\\", "/")}`);
    }
    resultLines.push(``);
    for (const url of bin.include) {
        if (!bin.src.includes(url)) {
            resultLines.push(`    ${StringHelper.replaceAll(url, "\\", "/")}`);
        }
    }
    resultLines.push(`)`);
    if (bin.lib.length) {
        resultLines.push(`target_link_libraries(`);
        resultLines.push(`    ${binTarget}`);
        resultLines.push(``);
        for (const lib of bin.lib) {
            resultLines.push(`    ${lib}`);
        }
        resultLines.push(`)`);
    }

    return resultLines;
}

module.exports.generateResource = generateResource;
module.exports.generateLibaries = generateLibaries;
module.exports.generateTestBinaries = generateTestBinaries;
module.exports.prepareLibsContent = prepareLibsContent;
module.exports.prepareCMakeContent = prepareCMakeContent;
module.exports.prepareBinContent = prepareBinContent;
