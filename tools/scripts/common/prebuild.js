/**@format */

const definition = require("./define");

// pre-jobs import
const buildI18n = require("./i18n");

module.exports.run = async function () {
    const aPrePromises = [];

    aPrePromises.push(buildI18n.build(definition.BUILD_LANGUAGE));

    return new Promise((resolve, reject) => {
        Promise.all(aPrePromises).then(
            (_value) => {
                resolve();
            },
            (reason) => {
                reject(reason);
            },
        );
    });
};
