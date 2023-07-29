/**@format */

const path = require("path");

const buildConfiguration = require("../../../config/make/build.json");
const buildNativeConfig = require("../../../config/make/build-native.json");
const buildTestConfig = require("../../../config/make/build-test.json");

const PROJECT_BASE_PATH = path.resolve(__dirname, "../../..");
const TIANYU_NATIVE_NATIVE_RES_OUTPUT = buildNativeConfig.res.output;
const TIANYU_NATIVE_NATIVE_RES_NAME = "res";
const TIANYU_NATIVE_NATIVE_RES_PATH = path.resolve(PROJECT_BASE_PATH, "native", TIANYU_NATIVE_NATIVE_RES_NAME);

const PROJECT_SOURCE_ENTRY = path.resolve(PROJECT_BASE_PATH, buildConfiguration.baseURL || "");
const PROJECT_BUILD_TARGET = path.resolve(PROJECT_BASE_PATH, buildConfiguration.output);
const PROJECT_TEST_SOURCE = path.resolve(PROJECT_BASE_PATH, buildTestConfig.base);
const DEVELOPMENT_MODE = buildConfiguration.dev || true;
const BUILD_LANGUAGE = buildConfiguration.language || null;

const FULL_CONSOLE_LOG = (() => {
    const logType = buildConfiguration.log;
    if (!!!logType) {
        return false;
    }

    switch (logType.toLowerCase()) {
        case "full":
            return true;
        default:
            return false;
    }
})();

const CMAKE_VERSION = buildConfiguration.cmake?.version || "3.18";
const CMAKE_PROJECT_NAME = buildConfiguration.cmake?.project?.name || "Tianyu Native";
const CMAKE_PROJECT_VERSION = buildConfiguration.cmake?.project?.version || "0.0.0";
const CMAKE_CPP_STANDARD = buildConfiguration.cmake?.cpp?.standard || 17;
const CMAKE_OUTPUT_BIN = path.resolve(PROJECT_BUILD_TARGET, buildConfiguration.cmake?.output?.bin || "bin");
const CMAKE_OUTPUT_LIB = path.resolve(PROJECT_BUILD_TARGET, buildConfiguration.cmake?.output?.lib || "lib");
const CMAKE_OUTPUT_HEADER = path.resolve(PROJECT_BUILD_TARGET, buildConfiguration.cmake?.output?.header || "header");

const oConfigure = {
    build: buildConfiguration,
    native: buildNativeConfig,
    test: buildTestConfig,
};

const oCmake = {
    CMAKE_VERSION: CMAKE_VERSION,
    CMAKE_PROJECT_NAME: CMAKE_PROJECT_NAME,
    CMAKE_PROJECT_VERSION: CMAKE_PROJECT_VERSION,
    CMAKE_CPP_STANDARD: CMAKE_CPP_STANDARD,
    CMAKE_OUTPUT_BIN: CMAKE_OUTPUT_BIN,
    CMAKE_OUTPUT_LIB: CMAKE_OUTPUT_LIB,
    CMAKE_OUTPUT_HEADER: CMAKE_OUTPUT_HEADER,
};

module.exports = {
    configure: oConfigure,
    cmake: oCmake,

    PROJECT_BUILD_TARGET: PROJECT_BUILD_TARGET,

    PROJECT_BASE_PATH: PROJECT_BASE_PATH,
    PROJECT_SOURCE_ENTRY: PROJECT_SOURCE_ENTRY,
    PROJECT_TEST_SOURCE: PROJECT_TEST_SOURCE,
    DEVELOPMENT_MODE: DEVELOPMENT_MODE,
    BUILD_LANGUAGE: BUILD_LANGUAGE,
    FULL_CONSOLE_LOG: FULL_CONSOLE_LOG,

    TIANYU_NATIVE_NATIVE_RES_PATH: TIANYU_NATIVE_NATIVE_RES_PATH,
    TIANYU_NATIVE_NATIVE_RES_I18N_NAME: "i18n",
    TIANYU_NATIVE_NATIVE_RES_FEATURE_NAME: "feature",
    TIANYU_NATIVE_NATIVE_RES_NAME: TIANYU_NATIVE_NATIVE_RES_NAME,
    TIANYU_NATIVE_NATIVE_RES_OUTPUT: TIANYU_NATIVE_NATIVE_RES_OUTPUT,
};
