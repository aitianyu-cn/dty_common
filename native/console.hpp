/**
 * @file console.hpp(native/ext)
 * @author victor.yao
 * @brief
 * @version 0.1
 * @date 2021-12-15
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_COMMON_NATIVE_EXT_CONSOLE_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_EXT_CONSOLE_H_PLUS_PLUS__

#include "./stdin.hpp"

#ifdef __cplusplus
__CMODE__
{
#endif // !__cplusplus
    // pure C mode

#ifdef __cplusplus
}
#endif // !__cplusplus

#ifdef __cplusplus

namespace dty
{
    class ConsoleDevice final : public IStdioDevice
    {

    };

    __DEFAULT__ const ConsoleDevice __VARIABLE__ Console;
}

#endif // !__cplusplus

#endif // !__DTY_COMMON_NATIVE_EXT_CONSOLE_H_PLUS_PLUS__