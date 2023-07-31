/**
 * @file system-errors.hxx(native/system-errors)
 * @author senyun.yao
 * @brief 用于天宇平台默认错误码
 * @brief AiTianyu Default Error Code of Tianyu Framework
 *
 * @version 0.1
 * @date 2023-07-31
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#include "./core.hxx"

#pragma region tianyu_test_error_part_0x00000000

 /**
  * @namespace tianyu::test
  * @brief test entity execution failed: lost parameter
  */
const int32 __VARIABLE__ _tianyu_test_entity_fail_param_too_few = 0xFFFFFFFF;

/**
  * @namespace tianyu::test
 * @brief test entity execution failed: to many parameters
 */
const int32 __VARIABLE__ _tianyu_test_entity_fail_param_pre_more = 0xFFFFFFFE;

/**
 * @namespace tianyu::test
 * @brief test entity execution failed: file could not be opened
 */
const int32 __VARIABLE__ _tianyu_test_entity_fail_file_open = 0xFFFFFFFD;

#pragma endregion

#pragma region tianyu_except_error_part_0x00000000FFFFFFFF

/**
 * @namespace tianyu::except
 * @brief generic exception
 */
const uint64 __VARIABLE__ _tianyu_except_generic_exception = 0x00000001FFFFFFFFULL;

/**
 * @namespace tianyu::except
 * @brief null pointer exception
 */
const uint64 __VARIABLE__ _tianyu_except_generic_nullPointerException = 0x00000002FFFFFFFFULL;

/**
 * @namespace tianyu::except
 * @brief arithmetic exception
 */
const uint64 __VARIABLE__ _tianyu_except_generic_arithmeticException = 0x00000003FFFFFFFFULL;

/**
 * @namespace tianyu::except
 * @brief index out of range exception
 */
const uint64 __VARIABLE__ _tianyu_except_generic_indexOutOfRangeException = 0x00000004FFFFFFFFULL;

/**
 * @namespace tianyu::except
 * @brief function not implementation exception
 */
const uint64 __VARIABLE__ _tianyu_except_generic_notImplementationException = 0x00000005FFFFFFFFULL;

/**
 * @namespace tianyu::except
 * @brief argument exception
 */
const uint64 __VARIABLE__ _tianyu_except_generic_argumentException = 0x10000001FFFFFFFFULL;

/**
 * @namespace tianyu::except
 * @brief argument null exception
 */
const uint64 __VARIABLE__ _tianyu_except_generic_argumentNullException = 0x10000002FFFFFFFFULL;

/**
 * @namespace tianyu::except
 * @brief argument out of range exception
 */
const uint64 __VARIABLE__ _tianyu_except_generic_argumentOutOfRangeException = 0x10000003FFFFFFFFULL;

/**
 * @namespace tianyu::except
 * @brief operation not supported exception
 */
const uint64 __VARIABLE__ _tianyu_except_generic_operationNotSupportException = 0x20000001FFFFFFFFULL;

/**
 * @namespace tianyu::except
 * @brief operation failed exception
 */
const uint64 __VARIABLE__ _tianyu_except_generic_operationFailedException = 0x30000001FFFFFFFFULL;


const uint64 __VARIABLE__ _tianyu_except_formatter_parseException = 0xF0000001FFFFFFFFULL;
const uint64 __VARIABLE__ _tianyu_except_formatter_parseStringEmptyException = 0xF0000002FFFFFFFFULL;

#pragma endregion

#pragma region tianyu_except_formatter_error_part_0x00000000

const int32 _tianyu_except_number_formatter_error_duplicate_scale = 0x1FFFFFFF;
const int32 _tianyu_except_number_formatter_error_duplicate_prefix = 0x1FFFFFFE;
const int32 _tianyu_except_number_formatter_error_duplicate_count_int = 0x1FFFFFFD;
const int32 _tianyu_except_number_formatter_error_duplicate_count_float = 0x1FFFFFFC;
const int32 _tianyu_except_number_formatter_error_duplicate_count_times = 0x1FFFFFFB;
const int32 _tianyu_except_number_formatter_error_duplicate_align = 0x1FFFFFFA;
const int32 _tianyu_except_number_formatter_error_duplicate_sym_force = 0x1FFFFFF9;
const int32 _tianyu_except_number_formatter_error_duplicate_char_case = 0x1FFFFFF8;
const int32 _tianyu_except_number_formatter_error_duplicate_fill_char = 0x1FFFFFF7;
const int32 _tianyu_except_number_formatter_error_fill_char_not_assign = 0x1FFFFFF6;

#pragma endregion
