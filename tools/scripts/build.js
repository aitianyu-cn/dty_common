/**@format */

const fs = require("fs");
const path = require("path");

const definition = require("./common/define");
const buildHelper = require("./common/buildHelper");

// pre-jobs import
const buildI18n = require("./common/i18n");
const { handleTargetHeader } = require("./common/targetHelper");

// pre-jobs done
const aPrePromises = [];
aPrePromises.push(buildI18n.build(definition.BUILD_LANGUAGE));

/**
 * @type {{source:string;target:string;header:string[];}[]}
 */
const aTargetHeaderList = [];

// generate cmake file
function generateCMake() {
    const cmakeFile = path.resolve(definition.PROJECT_BASE_PATH, "CMakeLists.txt");

    const aLibContent = [];
    const libList = [];

    aLibContent.push("");
    const libSource = definition.configure.native.libs;
    const libraries = buildHelper.generateLibaries(libSource, libList);
    for (const library of libraries) {
        const libContent = buildHelper.prepareLibsContent(library, aTargetHeaderList);
        aLibContent.push(...libContent);
    }

    aLibContent.push("");
    const testLibSource = definition.configure.test.libs;
    const testLibraries = buildHelper.generateLibaries(testLibSource, libList);
    for (const library of testLibraries) {
        const libContent = buildHelper.prepareLibsContent(library, aTargetHeaderList);
        aLibContent.push(...libContent);
    }

    aLibContent.push("");
    const testList = [];
    const testCases = buildHelper.generateTestBinaries(testList);
    for (const testCase of testCases) {
        const testContent = buildHelper.prepareBinContent(testCase);
        aLibContent.push(...testContent);
    }

    const content = buildHelper.prepareCMakeContent(aLibContent);
    fs.writeFileSync(cmakeFile, content, { encoding: "utf-8" });

    if (!fs.existsSync(definition.PROJECT_BUILD_TARGET)) {
        fs.mkdirSync(definition.PROJECT_BUILD_TARGET, { recursive: true });
    }
    const testListFile = path.resolve(definition.PROJECT_BUILD_TARGET, "test.list.json");
    fs.writeFileSync(testListFile, JSON.stringify(testList), { encoding: "utf-8" });
    const libListFile = path.resolve(definition.PROJECT_BUILD_TARGET, "lib.list.json");
    fs.writeFileSync(libListFile, JSON.stringify(libList), { encoding: "utf-8" });
}

// run all jobs
function run() {
    Promise.all(aPrePromises).then(
        () => {
            generateCMake();
            handleTargetHeader(aTargetHeaderList);
        },
        (reason) => {
            //
        },
    );
}

// run
run();
