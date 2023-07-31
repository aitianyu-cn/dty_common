/**@format */

const definition = require("../common/define");

// pre-jobs import
const buildI18n = require("./i18n");
const buildFeature = require("./features");

module.exports.run = async function () {
    const aPrePromises = [];

    console.log(`\x1B[34m # Pre-build Start \x1B[0m`);
    console.log(`\x1B[36m`);

    aPrePromises.push(buildI18n.build(definition.BUILD_LANGUAGE));
    aPrePromises.push(buildFeature.build());

    return new Promise((resolve, reject) => {
        Promise.all(aPrePromises).then(
            (_value) => {
                console.log();
                console.log(`\x1B[32m # Pre-build Successful \x1B[0m`);
                console.log();
                resolve();
            },
            (reason) => {
                console.log();
                console.log(`\x1B[31m # Pre-build Failed`);
                if (reason) {
                    console.log(`\x1B[31m Failure:`);
                    console.log(`\x1B[31m ${typeof reason === "string" ? reason : reason.message} \x1B[0m`);
                }
                reject(reason);
            },
        );
    });
};
