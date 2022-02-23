/**
 * @file error.h
 * @author victor.yao
 * @brief errors for i18n maker
 * @version 0.1
 * @date 2022-02-23
 *
 * @copyright aitianyu.cn Copyright (c) 2022
 *
 */

#ifndef __DTY_NATIVE_DEV_TOOLS_INTERNATIONAL_TOOL_HEADER_MAKER_ERROR__
#define __DTY_NATIVE_DEV_TOOLS_INTERNATIONAL_TOOL_HEADER_MAKER_ERROR__

#ifdef __cplusplus
extern "C"
{
#endif // !__cplusplus

    typedef struct _dty_native_lang_error_struct
    {
        int   line;
        int   row;
        char* msg;
        char* file;
        int   additions;
    } ErrorInfo;

    // error tracker for C language

    /**
     * @brief get errors count
     *
     * @return int return the count of errors
     */
    int _dty_native_lang_error_count();

    /**
     * @brief clean all the errors
     *
     */
    void _dty_native_lang_error_clean();

    /**
     * @brief delete specified error(s)
     *
     * @param error_code specified error code
     * @return int return the deleted count of the specified errors
     */
    int _dty_native_lang_error_delete(int error_code);

    /**
     * @brief add a new error
     *
     * @param error_code new error code
     * @param msg new error description
     * @return int return new errors count
     */
    int _dty_native_lang_error_push(int error_code, ErrorInfo* msg);

    /**
     * @brief return the lastest error
     *
     * @param error_code the lastest error code
     * @param msg the error description
     * @return int return the count of current errors
     */
    int _dty_native_lang_error_peek(int* error_code, ErrorInfo** msg);

    /**
     * @brief get an error that is the lastest
     *
     * @param error_code the lastest error code
     * @param msg the error description
     * @return int return the count of current errors
     */
    int _dty_native_lang_error_pop(int* error_code, ErrorInfo** msg);

    /**
     * @brief check the specified error can be found or not
     *
     * @param error_code the searched error code
     * @return int return a value that indicates the count of the error code or 0 if the error code could not be found
     */
    int _dty_native_lang_error_contains(int error_code);

    /**
     * @brief get specified error(s)
     *
     * @param error_code give the indicated error code
     * @param msg return an array of the errors
     * @param remove set a value that indicates the gotten errors need to be deleted or not
     * @return int return a value that is the count of returned array
     */
    int _dty_native_lang_error_get(int error_code, ErrorInfo** msg, int remove);

#ifdef __cplusplus
}
#endif // !__cplusplus

#endif // !__DTY_NATIVE_DEV_TOOLS_INTERNATIONAL_TOOL_HEADER_MAKER_ERROR__