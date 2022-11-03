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

    const libSource = definition.configure.native.libs;
    const libraries = buildHelper.generateLibaries(libSource);
    const aLibContent = [];
    for (const library of libraries) {
        const libContent = buildHelper.prepareLibsContent(library, aTargetHeaderList);
        aLibContent.push(...libContent);
    }

    const content = buildHelper.prepareCMakeContent(aLibContent);
    fs.writeFileSync(cmakeFile, content, { encoding: "utf-8" });
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
