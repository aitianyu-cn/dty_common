/**@format */

const fs = require("fs");
const path = require("path");

const definition = require("./common/define");
const buildHelper = require("./common/buildHelper");
const prebuild = require("./common/prebuild");

/**
 * @type {{source:string;target:string;header:string[];}[]}
 */
const aTargetHeaderList = [];

// generate cmake file
function generateCMake() {
    const cmakeFile = path.resolve(definition.PROJECT_BASE_PATH, "CMakeLists.txt");

    const aLibContent = [];

    aLibContent.push("");
    const libSource = definition.configure.test.libs;
    const libraries = buildHelper.generateLibaries(libSource);
    for (const library of libraries) {
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
}

// run all jobs
function run() {
    prebuild.run().then(
        () => {
            generateCMake();
        },
        (reason) => {
            //
        },
    );
}

// run
run();
