/**@format */

const fs = require("fs");
const path = require("path");
const basicDefs = require("./define");

const args = process.argv;
const configuration = require("../../../resource/i18n/config.json");
const globalConfig = require("../../../config/res.config.json");

const FEATURE_SOURCE_PATH = "../../../resource/i18n";
const FEATURE_RES_PATH_RELATION = `${basicDefs.TIANYU_NATIVE_NATIVE_RES_PATH}/${basicDefs.TIANYU_NATIVE_NATIVE_RES_FEATURE_NAME}`;
