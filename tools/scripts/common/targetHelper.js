/**@format */

const fs = require("fs");
const path = require("path");

const definition = require("./define");
const buildHelper = require("./buildHelper");

/**
 * @param {{source:string;target:string;header:string[];}[]} headerList
 */
function headerCopy(headerList) {
    console.log();
    console.log(`     ** generate target header files`);
    try {
        for (const headers of headerList) {
            const sourcePath = headers.source;
            const targetPath = headers.target;

            if (!fs.existsSync(targetPath)) {
                // to create the path
                fs.mkdirSync(targetPath, { recursive: true });
            }
            for (const file of headers.header) {
                const sourceFile = path.resolve(sourcePath, file);
                const targetFile = path.resolve(targetPath, file);

                fs.copyFileSync(sourceFile, targetFile);

                definition.FULL_CONSOLE_LOG && console.log(`          - copy file: ${sourceFile}`);
                definition.FULL_CONSOLE_LOG && console.log(`                   to: ${targetFile}`);
            }
        }
        console.log(`     ** \x1B[32mgenerate target header files success\x1B[36m`);
    } catch (e) {
        console.log(`     ** \x1B[31mgenerate target header files failed: ( ${e.message} )\x1B[36m`);
    }
}

// generate target header
// console.log(`          start handle`);

/**
 * @param {{source:string;target:string;header:string[];}[]} headerList
 */
function handleTargetHeader(headerList) {
    console.log();
    console.log("\x1B[36m  --------- start handle header ---------");

    let hasError = false;
    try {
        console.log(`     ** generate resources`);
        const resourcesList = buildHelper.generateResource();
        for (const resource of resourcesList) {
            const reslock = path.resolve(resource.source, "list.lock.json");
            const reslist = JSON.parse(fs.readFileSync(reslock, { encoding: "utf-8" }) || "[]");
            if (Array.isArray(reslist) && reslist.length) {
                definition.FULL_CONSOLE_LOG && console.log(`          - detect resource: ${resource.source}`);
                headerList.push({
                    source: resource.source,
                    target: resource.target,
                    header: reslist,
                });
            }
        }
        console.log(`     ** \x1B[32mgenerate resources success\x1B[36m`);
    } catch (e) {
        console.log(`     ** \x1B[31mgenerate resources failed: ( ${e.message} )\x1B[36m`);
        hasError = true;
    }

    headerCopy(headerList);

    console.log("  --------- handle header end -----------\x1B[0m");

    if (hasError) {
        throw new Error();
    }
}

module.exports.handleTargetHeader = handleTargetHeader;
