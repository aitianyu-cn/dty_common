/**@format */

const fs = require("fs");
const path = require("path");

const buildHelper = require("./buildHelper");

/**
 * @param {{source:string;target:string;header:string[];}[]} headerList
 */
function headerCopy(headerList) {
    for (const headers of headerList) {
        const sourcePath = headers.source;
        const targetPath = headers.target;

        // to create the path
        fs.mkdirSync(targetPath, { recursive: true });
        for (const file of headers.header) {
            const sourceFile = path.resolve(sourcePath, file);
            const targetFile = path.resolve(targetPath, file);

            fs.copyFileSync(sourceFile, targetFile);
        }
    }
}

// generate target header

/**
 * @param {{source:string;target:string;header:string[];}[]} headerList
 */
function handleTargetHeader(headerList) {
    const resourcesList = buildHelper.generateResource();
    for (const resource of resourcesList) {
        const reslock = path.resolve(resource.source, "list.lock.json");
        const reslist = JSON.parse(fs.readFileSync(reslock, { encoding: "utf-8" }) || "[]");
        if (Array.isArray(reslist) && reslist.length) {
            headerList.push({
                source: resource.source,
                target: resource.target,
                header: reslist,
            });
        }
    }

    headerCopy(headerList);
}

module.exports.handleTargetHeader = handleTargetHeader;
