/**@format */

const fs = require("fs");
const path = require("path");

const definition = require("./define");
const buildHelper = require("./buildHelper");

/**
 * @type {{source:string;target:string;header:string[];}[]}
 */
const aTargetHeaderList = [];

// generate cmake file

/**
 *
 * @param {"TEST" | "NATIVE" | "FULL"} buildType
 * @returns
 */
function generateCMake(buildType) {
    console.log("\x1B[36m  ---------- start build file -----------");

    const cmakeFile = path.resolve(definition.PROJECT_BASE_PATH, "CMakeLists.txt");

    let hasError = false;

    const aLibContent = [];
    const libList = [];
    const testList = [];

    if (buildType !== "TEST") {
        console.log(`     ** generate source libraries`);
        try {
            aLibContent.push("");
            const libSource = definition.configure.native.libs;
            const libraries = buildHelper.generateLibaries(libSource, libList);
            for (const library of libraries) {
                const libContent = buildHelper.prepareLibsContent(library, aTargetHeaderList);
                aLibContent.push(...libContent);
            }
            console.log(`     ** \x1B[32mgenerate source libraries success\x1B[36m`);
        } catch (e) {
            console.log(`     ** \x1B[31mgenerate source libraries failed: ( ${e.message} )\x1B[36m`);
            hasError = true;
        }
    }

    if (!hasError && buildType !== "NATIVE") {
        console.log();
        console.log(`     ** generate test libraries`);
        try {
            aLibContent.push("");
            const testLibSource = definition.configure.test.libs;
            const testLibraries = buildHelper.generateLibaries(testLibSource, libList);
            for (const library of testLibraries) {
                const libContent = buildHelper.prepareLibsContent(library, aTargetHeaderList);
                aLibContent.push(...libContent);
            }
            console.log(`     ** \x1B[32mgenerate test libraries success\x1B[36m`);
        } catch (e) {
            console.log(`     ** \x1B[31mgenerate test libraries failed: ( ${e.message} )\x1B[36m`);
            hasError = true;
        }
    }

    if (!hasError && buildType !== "NATIVE") {
        console.log();
        console.log(`     ** generate test binaries`);
        try {
            aLibContent.push("");
            const testCases = buildHelper.generateTestBinaries(testList);
            for (const testCase of testCases) {
                const testContent = buildHelper.prepareBinContent(testCase);
                aLibContent.push(...testContent);
            }
            console.log(`     ** \x1B[32mgenerate test binaries success\x1B[36m`);
        } catch (e) {
            console.log(`     ** \x1B[31mgenerate test binaries failed: ( ${e.message} )\x1B[36m`);
            hasError = true;
        }
    }

    if (!hasError) {
        console.log();
        console.log(`     ** create cmake file`);
        try {
            definition.FULL_CONSOLE_LOG && console.log(`          - write cmake file: ${cmakeFile}`);
            const content = buildHelper.prepareCMakeContent(aLibContent);
            fs.writeFileSync(cmakeFile, content, { encoding: "utf-8" });
            console.log(`     ** \x1B[32mcreate cmake file success\x1B[36m`);
        } catch (e) {
            console.log(`     ** \x1B[31mcreate cmake file failed: ( ${e.message} )\x1B[36m`);
            hasError = true;
        }
    }

    if (!hasError) {
        console.log();
        console.log(`     ** export manifest`);
        try {
            if (!fs.existsSync(definition.PROJECT_BUILD_TARGET)) {
                fs.mkdirSync(definition.PROJECT_BUILD_TARGET, { recursive: true });
            }
            if (buildType !== "NATIVE") {
                const testListFile = path.resolve(definition.PROJECT_BUILD_TARGET, "test.list.json");
                definition.FULL_CONSOLE_LOG && console.log(`          - export test cases to file: ${testListFile}`);
                fs.writeFileSync(testListFile, JSON.stringify(testList), { encoding: "utf-8" });
            }
            const libListFile = path.resolve(definition.PROJECT_BUILD_TARGET, "lib.list.json");
            definition.FULL_CONSOLE_LOG && console.log(`          - export libraries list to file: ${libListFile}`);
            fs.writeFileSync(libListFile, JSON.stringify(libList), { encoding: "utf-8" });
            console.log(`     ** \x1B[32mexport manifest success\x1B[36m`);
        } catch (e) {
            console.log(`     ** \x1B[31mexport manifest failed: ( ${e.message} )\x1B[36m`);
            hasError = true;
        }
    }

    console.log("  ---------- build file end -----------\x1B[0m");

    if (hasError) {
        throw new Error();
    }

    return aTargetHeaderList;
}

module.exports.generateCMake = generateCMake;
