/**@format */

const fs = require("fs");
const path = require("path");

const definition = require("./define");

module.exports.readFiles = async function (source, sourceDir) {
    const aFileReadPromise = [];
    for (const sourceFile of source) {
        const filePath = path.resolve(__dirname, sourceDir, `${sourceFile}.json`);
        readFilePromise = new Promise((resolve, reject) => {
            fs.readFile(
                filePath,
                {
                    encoding: "utf-8",
                },
                (err, data) => {
                    if (!!err) {
                        definition.FULL_CONSOLE_LOG && console.error(`       - read file ${sourceFile} failed. ${err}`);
                        reject();
                    } else {
                        definition.FULL_CONSOLE_LOG && console.log(`       - read File :${sourceFile}.json SUCCESS`);
                        resolve({ source: sourceFile, data: JSON.parse(data) });
                    }
                },
            );
        });
        aFileReadPromise.push(readFilePromise);
    }

    return Promise.all(aFileReadPromise);
};
