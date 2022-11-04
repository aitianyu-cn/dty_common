/**@format */

const fs = require("fs");

const definition = require("./define");

module.exports.fileExists = function (file) {
    try {
        fs.accessSync(file);
        return true;
    } catch {
        return false;
    }
};

module.exports.StringHelper = {
    /**
     * @param {string} str
     * @param {string} raw
     * @param {string} replace
     */
    replaceAll: (str, raw, replace) => {
        let result = str;
        while (result.includes(raw)) {
            result = result.replace(raw, replace);
        }

        return `"${result}"`;
    },
};

/**
 *
 * @param {string[]} insert
 */
module.exports.printStart = function printStart(insert) {
    const date = new Date(Date.now());
    console.log(`\x1B[33m`);
    console.log(`#######################################################`);
    console.log(`     ______   ____    ____   ____    __ __   __ __ `);
    console.log(`    |      | |    |  /    | |    \  |  |  | |  |  |`);
    console.log(`    |      |  |  |  |  o  | |  _  | |  |  | |  |  |`);
    console.log(`    |_|  |_|  |  |  |     | |  |  | |  ~  | |  |  |`);
    console.log(`      |  |    |  |  |  _  | |  |  | |___, | |  :  |`);
    console.log(`      |  |    |  |  |  |  | |  |  | |     | |     |`);
    console.log(`      |__|   |____| |__|__| |__|__| |____/   \\__,_|`);
    // console.log(` ----------------------------------------------------`);
    console.log();
    console.log(`  ${definition.cmake.CMAKE_PROJECT_NAME}`);
    console.log(`  ${definition.cmake.CMAKE_PROJECT_VERSION}`);
    console.log(`  ${date.getFullYear()}-${date.getMonth()}-${date.getDate()} ${date.toLocaleTimeString()}`);
    console.log();
    if (insert && insert.length) {
        for (const str of insert) {
            console.log(`  ${str}`);
        }
        console.log();
    }
    console.log(`#######################################################`);
    console.log(`\x1B[0m`);
};
