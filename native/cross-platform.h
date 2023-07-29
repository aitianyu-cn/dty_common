/**
 * @file cross-platform.h(native/cross-platform)
 * @author senyun.yao
 * @section C/C++
 * @brief 用于天宇平台的跨平台组件库
 * @brief AiTianyu Platform Public Common Core (C/C++)
 *        including supporting for cross platform, basic supporting for C/C++ and Test Components Core of Tianyu Framework
 *
 * @version 1.0
 * @date 2023-07-29
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */


#ifndef __TIANYU_COMMON_NATIVE_CROSS_PLATFORM_H__
#define __TIANYU_COMMON_NATIVE_CROSS_PLATFORM_H__

 /**
  * 环境信息来源:
  * Environment Defs:
  * https://sourceforge.net/p/predef/wiki/OperatingSystems/
  *
  */

  /**
   * @brief 检查是否为Windows操作系统平台
   * @brief Check for MS Windows
   */
#ifdef _WIN32
   // 检查64bit操作系统
   // Check for 64bit OS
#ifdef _WIN64
/**
 * @brief 定义__DTY_WIN描述当前系统为：微软 Windows
 * @brief Define __DTY_WIN to describe current system is: Microsoft Windows
 */
#define __TIANYU_WIN 1
#else
/**
 * @brief 定义__DTY_ERR_64设置错误状态：当前系统需要64bit环境
 * @brief Define __DTY_ERR_64 to set error state: 64bit OS is required
 */
#define __TIANYU_PLATFORM_ERROR 1
#define __TIANYU_ERROR_PLATFORM_WIN32 1
#endif // !_WIN64
#endif // !_WIN32

 /**
* @brief 检查是否为Mac OS操作系统平台
* @brief Check for Apple MacOS
*/
#if defined(__APPLE__) || defined(__MACH__)
/**
 * @brief 定义__DTY_APF描述当前系统为：Apple 系列操作系统
 * @brief Define __DTY_APF to describe current system is: Apple Operations
 */
#define __TIANYU_APF 1
 // 导入MacOS信息头文件
 // import mac infor header
#include "TargetConditionals.h"
#if TARGET_IPHONE_SIMULATOR
   /**
    * @brief 当前系统为Apple平台Iphone模拟器
    * @brief Current system is Apple OS for Iphone Simulator
    */
#define __TIANYU_APPLE_IS 1
#elif TARGET_OS_IPHONE
   /**
    * @brief 当前系统为Apple IOS
    * @brief Current system is Apple OS for Iphone
    */
#define __TIANYU_APPLE_IP 1
#elif TARGET_OS_MAC
   /**
    * @brief 当前系统为Apple MacOS
    * @brief Current system is Apple OS for Mac
    */
#define __DTY_APPLE_MAC 1
#else
   /**
    * @brief 未知的Apple系统平台
    * @brief Throw error for Unknown Apple Platform
    */
#define __TIANYU_PLATFORM_ERROR 1
#define __TIANYU_ERROR_PLATFORM_APPLE 1
#endif
#endif // !defined(__APPLE__) || defined(__MACH__)

    /**
     * @brief 检查是否为Linux操作系统平台
     * @brief Check for Linux
     */
#if defined(__linux__) || defined(__gnu_linux__)
#if defined(__LP64__) || defined(__x86_64__) || defined(__amd64)
     /**
      * @brief 定义__DTY_LNX描述当前系统为：Linux系列
      * @brief Define __DTY_LNX to describe current system is: Linux Serials System
      */
#define __TIANYU_LINUX 1
#else
     /**
      * @brief 定义__DTY_ERR_64设置错误状态：当前系统需要64bit环境
      * @brief Define __DTY_ERR_64 to set error state: 64bit OS is required
      */
#define __TIANYU_PLATFORM_ERROR 1
#define __TIANYU_ERROR_PLATFORM_LNX32 1
#endif
#endif // !defined(__linux__) || defined(__gnu_linux__)

#ifdef __cplusplus
namespace tianyu
{
    /**
     * @brief 定义天宇平台支持的平台
     * @brief Defination for Tianyu Native Platform Supported
     */
    enum class PlatformID : signed int
    {
        /** @brief Apple Mac 操作系统 */
        MacOSX = 6,
        /** @brief 其他操作系统 */
        Other = 7,
        /** @brief Linux/Unix系列操作系统 */
        Unix = 4,
        /** @brief Windows 操作系统 */
        Windows = 1
    };
}
#endif // !__cplusplus

// 
// 用于C语言的天宇支持平台
// Defination for Tianyu Native platform supporting based on C
/** @brief Apple Mac 操作系统 */
#define __TIANYU_PLATFORM_ID_MAC_OSX    6
/** @brief 其他操作系统 */
#define __TIANYU_PLATFORM_ID_OTHER      7
/** @brief Linux/Unix系列操作系统 */
#define __TIANYU_PLATFORM_ID_UNIX       4
/** @brief Windows 操作系统 */
#define __TIANYU_PLATFORM_ID_WINDOWS    1

#endif // !__TIANYU_COMMON_NATIVE_CROSS_PLATFORM_H__