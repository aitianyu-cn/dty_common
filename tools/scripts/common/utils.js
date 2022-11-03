/**@format */

const fs = require("fs");

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
