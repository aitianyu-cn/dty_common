/**@format */

const fs = require("fs");
const path = require("path");

const definition = require("./common/define");
const buildHelper = require("./common/buildHelper");
const prebuild = require("./common/prebuild");
const { handleTargetHeader } = require("./common/targetHelper");

/**
 * @type {{source:string;target:string;header:string[];}[]}
 */
const aTargetHeaderList = [];

// generate cmake file
function generateCMake() {
    const cmakeFile = path.resolve(definition.PROJECT_BASE_PATH, "CMakeLists.txt");

    const libList = [];

    const libSource = definition.configure.native.libs;
    const libraries = buildHelper.generateLibaries(libSource, libList);
    const aLibContent = [];
    for (const library of libraries) {
        const libContent = buildHelper.prepareLibsContent(library, aTargetHeaderList);
        aLibContent.push(...libContent);
    }

    const content = buildHelper.prepareCMakeContent(aLibContent);
    fs.writeFileSync(cmakeFile, content, { encoding: "utf-8" });

    if (!fs.existsSync(definition.PROJECT_BUILD_TARGET)) {
        fs.mkdirSync(definition.PROJECT_BUILD_TARGET, { recursive: true });
    }
    const libListFile = path.resolve(definition.PROJECT_BUILD_TARGET, "lib.list.json");
    fs.writeFileSync(libListFile, JSON.stringify(libList), { encoding: "utf-8" });
}

// run all jobs
function run() {
    prebuild.run().then(
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
