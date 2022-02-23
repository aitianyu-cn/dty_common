/**
 * @file maker.h
 * @author victor.yao
 * @brief i18n maker is used for creating an i18n pre-head file for compiling progress
 * @version 0.1
 * @date 2022-02-23
 *
 * @copyright aitianyu.cn Copyright (c) 2022
 *
 */

 // __DTY_NATIVE_DEV_TOOLS_INTERNATIONAL_TOOL_HEADER_MAKER__
 // dty-native development tools
 // international tool
 // header maker
#ifndef __DTY_NATIVE_DEV_TOOLS_INTERNATIONAL_TOOL_HEADER_MAKER__
#define __DTY_NATIVE_DEV_TOOLS_INTERNATIONAL_TOOL_HEADER_MAKER__

#define __DTY_NATIVE_DEV_TOOLS_INTERNATIONAL_TOOL_LANG_ZH_CN "zh-CN"
#define __DTY_NATIVE_DEV_TOOLS_INTERNATIONAL_TOOL_LANG_EN_US "en-US"

#define __DTY_NATIVE_DEV_TOOLS_INTERNATIONAL_TOOL_LANG_ASIA 0x100 // Asia
#define __DTY_NATIVE_DEV_TOOLS_INTERNATIONAL_TOOL_LANG_EUP  0x200 // Europe
#define __DTY_NATIVE_DEV_TOOLS_INTERNATIONAL_TOOL_LANG_SA   0x300 // South America
#define __DTY_NATIVE_DEV_TOOLS_INTERNATIONAL_TOOL_LANG_NA   0x400 // North America
#define __DTY_NATIVE_DEV_TOOLS_INTERNATIONAL_TOOL_LANG_AFR  0x500 // Africa
#define __DTY_NATIVE_DEV_TOOLS_INTERNATIONAL_TOOL_LANG_OCE  0x600 // Oceania

// Asia
#define __DTY_NATIVE_DEV_TOOLS_INTERNATIONAL_TOOL_LANG_ZH_CN_CODE (__DTY_NATIVE_DEV_TOOLS_INTERNATIONAL_TOOL_LANG_ASIA + 0x01) // China Mainland

// North America
#define __DTY_NATIVE_DEV_TOOLS_INTERNATIONAL_TOOL_LANG_EN_US_CODE (__DTY_NATIVE_DEV_TOOLS_INTERNATIONAL_TOOL_LANG_NA + 0x01) // USA

#ifdef __cplusplus
extern "C"
{
#endif // !__cplusplus

    // for dty-native development tools
    // c language supported only

    // i18n source file structure for header maker
    // start symbol: #
    // split symbol: ,
    // ending symbol: \n
    // escape symbol: '\'

    // reading progress
    // 1. read char until '#'
    // 2. start read macro-define until ','. For macro-def that the '_' and english chars are supported only
    // 3. start read default string if has. in this place, any char can be recognition
    // 4. read specified language string that be indicated if has until ',' or ending
    // 5. start the next reading

    // there is an exception will be thrown if any unexpected char exists for step-2
    // there are some flags will be set automated for step-3 and step-4

    // mentioned:
    // 1. macro-define for output header file needs to be given by run-params
    // 2. input file needs to be given like above
    // 3. output file also needs to be given like above
    // 4. language selected needs a unique char or code

    /**
     * @brief function to convert language string to language code
     *
     * @param lang_str the specified language string (case insensitive)
     * @return int return the language code (different with language index)
     *
     * @note language code is a unique integer includes country informations (Continent and Country Id of the Continent)
     */
    int _dty_native_lang_code_translation(const char* lang_str);
    /**
     * @brief function to convert language code to file index
     *
     * @param lang_code input language code
     * @return int return the index of language file of the indicated language
     */
    int _dty_native_lang_index_conversion(int lang_code);

#ifdef __cplusplus
}
#endif // !__cplusplus

#endif // !__DTY_NATIVE_DEV_TOOLS_INTERNATIONAL_TOOL_HEADER_MAKER__