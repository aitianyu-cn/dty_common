/**
 * @file cross_platform.h(utils)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-11-10
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 * 当前跨平台定义(Current Definitation for crossing platform)：
 * __DTY_WIN: Windows 64bit
 * __DTY_APF: Apple OS serials
 * __DTY_AIS: Apple Iphone Simulator
 * __DTY_AIP: Apple Iphone OS
 * __DTY_AMC: Apple Mac OS
 * __DTY_LNX: Linux OS Serials
 *
 */

#ifndef __DTY_COMMON_NATIVE_CORE_CROSS_PLATFORM_H__
#define __DTY_COMMON_NATIVE_CORE_CROSS_PLATFORM_H__

 /**
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
#define __DTY_WIN 1
#else
/**
 * @brief 定义__DTY_ERR_64设置错误状态：当前系统需要64bit环境
 * @brief Define __DTY_ERR_64 to set error state: 64bit OS is required
 */
#define __DTY_ERR_64 1
#endif // !_WIN64
#endif // !_WIN32

 /**
  * @brief 检查是否为Mac OS操作系统平台
  * @brief Check for Apple MacOS
  */
#if defined(__APPLE__) || defined(__MACH__)
  /**
   * @brief 定义__DTY_APF描述当前系统为：Apple MacOS
   * @brief Define __DTY_APF to describe current system is: Apple MacOS
   */
#define __DTY_APF 1
#include "TargetConditionals.h" // import mac infor header
#if TARGET_IPHONE_SIMULATOR
   /**
    * @brief 当前系统为Apple平台Iphone模拟器
    * @brief Current system is Apple OS for Iphone Simulator
    */
#define __DTY_AIS 1
#elif TARGET_OS_IPHONE
   /**
    * @brief 当前系统为Apple IOS
    * @brief Current system is Apple OS for Iphone
    */
#define __DTY_AIP 1
#elif TARGET_OS_MAC
   /**
    * @brief 当前系统为Apple MacOS
    * @brief Current system is Apple OS for Mac
    */
#define __DTY_AMC 1
#else
   /**
    * @brief 未知的Apple系统平台
    * @brief Throw error for Unknown Apple Platform
    */
#error Unknown Apple Platform
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
#define __DTY_LNX 1
#else
     /**
      * @brief 定义__DTY_ERR_64设置错误状态：当前系统需要64bit环境
      * @brief Define __DTY_ERR_64 to set error state: 64bit OS is required
      */
#define __DTY_ERR_64 1
#endif
#endif // !defined(__linux__) || defined(__gnu_linux__)

      /**
       * @brief 检查64bit操作系统状态
       * @brief Check state of 64bit OS
       */
#ifdef __DTY_ERR_64
#error Tianyu Platform require 64bit OS
#endif // !__DTY_ERR_64

       /**
        * @brief 检查操作系统兼容性
        * @brief Check OS supportable state
        */
#if !defined(__DTY_WIN) && !defined(__DTY_APF) && !defined(__DTY_LNX)
#error Unknown OS is not supported for Tianyu Platform
#endif // !!defined(__DTY_WIN) && !defined(__DTY_APF) && !defined(__DTY_LNX)

#endif // !__DTY_COMMON_NATIVE_CORE_CROSS_PLATFORM_H__