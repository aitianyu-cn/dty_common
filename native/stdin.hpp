/**
 * @file stdin.h(native/ext)
 * @author victor.yao
 * @brief Provide Stdin Tools in Pure C Mode
 * @version 0.1
 * @date 2021-12-15
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.console?view=net-6.0
 */

#ifndef __DTY_COMMON_NATIVE_EXT_STDIN_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_EXT_STDIN_H_PLUS_PLUS__

#include "./core/utilize.h"
#include "./core/cross_platform.h"

#ifdef __cplusplus
__CMODE__
{
#endif // !__cplusplus
    // pure C mode

#ifdef __cplusplus
}
#endif // !__cplusplus

#ifdef __cplusplus

#include "./core/utilize.hh"

namespace dty
{
    enum class StdinColor : int32
    {
        Blach = 0,
        Blue = 9,
        Cyan = 11,
        DarkBlue = 1,
        DarkCyan = 3,
        DarkGray = 8,
        DarkGreen = 2,
        DarkMagenta = 5,
        DarkRed = 4,
        DarkYellow = 6,
        Gray = 7,
        Green = 10,
        Magenta = 13,
        Red = 12,
        White = 15,
        Yellow = 14
    };

    _interface IStdout
    {
        __PUB__ virtual string __VARIABLE__ ToString() = 0;
        __PUB__ virtual string __VARIABLE__ ToString() const = 0;
    };

    _interface IStdioDevice
    {

    };

    class Stdio final
    {
        __PRI__ IStdioDevice __VARIABLE__ _IODevice;

        __PUB__ Stdio(IStdioDevice __REFERENCE__ stdDevice);

#pragma region Properties
        __PUB__ Property<StdinColor> __VARIABLE__ BackgroundColor;
        __PUB__ Property<int>        __VARIABLE__ BufferHeight;
        __PUB__ Property<int>        __VARIABLE__ BufferWedth;
        __PUB__ ReadOnlyProp<bool>   __VARIABLE__ CapsLock;
        __PUB__ Property<int>        __VARIABLE__ CursorLeft;
        __PUB__ Property<int>        __VARIABLE__ CursorSize;
        __PUB__ Property<int>        __VARIABLE__ CursorTop;
        __PUB__ Property<int>        __VARIABLE__ CursorVisible;
        __PUB__ Property<StdinColor> __VARIABLE__ ForegroundColor;
#pragma endregion

#pragma region Methods
#pragma endregion
    };
}

#endif // !__cplusplus

#endif // !__DTY_COMMON_NATIVE_EXT_STDIN_H_PLUS_PLUS__