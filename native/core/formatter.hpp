/**
 * @file formatter.hpp(core)
 * @author ysydty
 * @brief
 * @version 0.1
 * @date 2021-12-23
 * @date 2023-07-31
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __TIANYU_COMMON_NATIVE_CORE_FORMATTER_H_PLUS_PLUS__
#define __TIANYU_COMMON_NATIVE_CORE_FORMATTER_H_PLUS_PLUS__

#include "./internal.h"

#ifdef __cplusplus
__CMODE__
{
#endif // !__cplusplus

    //
    //

/**
 * @brief 将指定字符转换为字符串
 *
 * @param ch 指定的字符
 * @return ::string 返回字符串
 */
::string __VARIABLE__ c2str(char __VARIABLE__ ch);
/**
 * @brief 将指定无符号字符转换为字符串
 *
 * @param ch 指定的字符
 * @return ::string 返回字符串
 */
::string __VARIABLE__ uc2str(uchar __VARIABLE__ ch);
/**
 * @brief 将指定无符号字节数转换为字符串（10进制转换）
 *
 * @param sb 指定的无符号字节数
 * @return ::string 返回等价的字符串
 */
::string __VARIABLE__ sb2str(sbyte __VARIABLE__ sb);
/**
 * @brief 将指定有符号字节数转换为字符串（10进制转换）
 *
 * @param b 指定的有符号字节数
 * @return ::string 返回等价的字符串
 */
::string __VARIABLE__ b2str(::byte __VARIABLE__ b);
/**
 * @brief 将指定无符号16位整数转换为字符串（10进制转换）
 *
 * @param s 指定的无符号16位整数
 * @return ::string 返回等价的字符串
 */
::string __VARIABLE__ s2str(int16 __VARIABLE__ s);
/**
 * @brief 将指定有符号16位整数转换为字符串（10进制转换）
 *
 * @param s 指定的有符号16位整数
 * @return ::string 返回等价的字符串
 */
::string __VARIABLE__ us2str(uint16 __VARIABLE__ us);
/**
 * @brief 将指定有符号32位整数转换为字符串（10进制转换）
 *
 * @param s 指定的有符号32位整数
 * @return ::string 返回等价的字符串
 */
::string __VARIABLE__ i2str(int32 __VARIABLE__ i);
/**
 * @brief 将指定无符号32位整数转换为字符串（10进制转换）
 *
 * @param s 指定的无符号32位整数
 * @return ::string 返回等价的字符串
 */
::string __VARIABLE__ ui2str(uint32 __VARIABLE__ ui);
/**
 * @brief 将指定有符号64位整数转换为字符串（10进制转换）
 *
 * @param s 指定的有符号64位整数
 * @return ::string 返回等价的字符串
 */
::string __VARIABLE__ l2str(int64 __VARIABLE__ l);
/**
 * @brief 将指定无符号64位整数转换为字符串（10进制转换）
 *
 * @param s 指定的无符号64位整数
 * @return ::string 返回等价的字符串
 */
::string __VARIABLE__ ul2str(uint64 __VARIABLE__ ul);
/**
 * @brief 将指定实数转换为字符串（10进制转换）
 *
 * @param s 指定的实数
 * @return ::string 返回等价的字符串
 */
::string __VARIABLE__ f2str(float __VARIABLE__ f);
/**
 * @brief 将指定双精度浮点数转换为字符串（10进制转换）
 *
 * @param s 指定的双精度浮点数
 * @return ::string 返回等价的字符串
 */
::string __VARIABLE__ d2str(double __VARIABLE__ d);

::string __VARIABLE__ c2str_f(char __VARIABLE__ ch, const ::string __VARIABLE__ formatter);
::string __VARIABLE__ uc2str_f(uchar __VARIABLE__ uc, const ::string __VARIABLE__ formatter);
::string __VARIABLE__ sb2str_f(sbyte __VARIABLE__ sb, const ::string __VARIABLE__ formatter);
::string __VARIABLE__ b2str_f(::byte __VARIABLE__ b, const ::string __VARIABLE__ formatter);
::string __VARIABLE__ s2str_f(int16 __VARIABLE__ s, const ::string __VARIABLE__ formatter);
::string __VARIABLE__ us2str_f(uint16 __VARIABLE__ us, const ::string __VARIABLE__ formatter);
::string __VARIABLE__ i2str_f(int32 __VARIABLE__ i, const ::string __VARIABLE__ formatter);
::string __VARIABLE__ ui2str_f(uint32 __VARIABLE__ ui, const ::string __VARIABLE__ formatter);
::string __VARIABLE__ l2str_f(int64 __VARIABLE__ l, const ::string __VARIABLE__ formatter);
::string __VARIABLE__ ul2str_f(uint64 __VARIABLE__ ul, const ::string __VARIABLE__ formatter);
::string __VARIABLE__ f2str_f(float __VARIABLE__ f, const ::string __VARIABLE__ formatter);
::string __VARIABLE__ d2str_f(double __VARIABLE__ d, const ::string __VARIABLE__ formatter);

#ifdef __cplusplus
}
#endif // !__cplusplus

#ifdef __cplusplus

#include "./error.hpp"
#include <type_traits>

namespace tianyu
{
    _interface IFormatter : public virtual tianyu::TianyuObject
    {
        __PUB__ virtual ~IFormatter() __override_func;

        __PUB__ virtual ::string __VARIABLE__ ToString(const ::string __VARIABLE__ formatter) __pure_virtual_fun;
    };

    class FormatHelper final : public virtual tianyu::TianyuObject
    {
        __PUB__ static ::string __VARIABLE__ Format(char __VARIABLE__ value, const ::string __VARIABLE__ formatter);
        __PUB__ static ::string __VARIABLE__ Format(uchar __VARIABLE__ value, const ::string __VARIABLE__ formatter);
        __PUB__ static ::string __VARIABLE__ Format(int16 __VARIABLE__ value, const ::string __VARIABLE__ formatter);
        __PUB__ static ::string __VARIABLE__ Format(uint16 __VARIABLE__ value, const ::string __VARIABLE__ formatter);
        __PUB__ static ::string __VARIABLE__ Format(int32 __VARIABLE__ value, const ::string __VARIABLE__ formatter);
        __PUB__ static ::string __VARIABLE__ Format(uint32 __VARIABLE__ value, const ::string __VARIABLE__ formatter);
        __PUB__ static ::string __VARIABLE__ Format(int64 __VARIABLE__ value, const ::string __VARIABLE__ formatter);
        __PUB__ static ::string __VARIABLE__ Format(uint64 __VARIABLE__ value, const ::string __VARIABLE__ formatter);
        __PUB__ static ::string __VARIABLE__ Format(float __VARIABLE__ value, const ::string __VARIABLE__ formatter);
        __PUB__ static ::string __VARIABLE__ Format(double __VARIABLE__ value, const ::string __VARIABLE__ formatter);
        __PUB__ static ::string __VARIABLE__ Format(bool __VARIABLE__ value, const ::string __VARIABLE__ formatter);

        __PUB__ static ::string __VARIABLE__ Format(tianyu::IToString __REFERENCE__ value);

        __PUB__ template<typename T> static ::string __VARIABLE__ Format(T __REFERENCE__ value);
    };

    class ParseHelper final : public virtual tianyu::TianyuObject
    {
        __PUB__ static void __VARIABLE__ Parse(const ::string __VARIABLE__ s, __OTPUT__ char __REFERENCE__ result);
        __PUB__ static void __VARIABLE__ Parse(const ::string __VARIABLE__ s, __OTPUT__ uchar __REFERENCE__ result);
        __PUB__ static void __VARIABLE__ Parse(const ::string __VARIABLE__ s, __OTPUT__ int16 __REFERENCE__ result);
        __PUB__ static void __VARIABLE__ Parse(const ::string __VARIABLE__ s, __OTPUT__ uint16 __REFERENCE__ result);
        __PUB__ static void __VARIABLE__ Parse(const ::string __VARIABLE__ s, __OTPUT__ int32 __REFERENCE__ result);
        __PUB__ static void __VARIABLE__ Parse(const ::string __VARIABLE__ s, __OTPUT__ uint32 __REFERENCE__ result);
        __PUB__ static void __VARIABLE__ Parse(const ::string __VARIABLE__ s, __OTPUT__ int64 __REFERENCE__ result);
        __PUB__ static void __VARIABLE__ Parse(const ::string __VARIABLE__ s, __OTPUT__ uint64 __REFERENCE__ result);
        __PUB__ static void __VARIABLE__ Parse(const ::string __VARIABLE__ s, __OTPUT__ float __REFERENCE__ result);
        __PUB__ static void __VARIABLE__ Parse(const ::string __VARIABLE__ s, __OTPUT__ double __REFERENCE__ result);
        __PUB__ static void __VARIABLE__ Parse(const ::string __VARIABLE__ s, __OTPUT__ bool __REFERENCE__ result);

        __PUB__ template<typename T> static void __VARIABLE__ Parse(const ::string __VARIABLE__ s, __OTPUT__ T __REFERENCE__ result);
    };

    namespace except
    {
        class ParseException
            : public virtual tianyu::TianyuObject,
            public virtual tianyu::except::Exception
        {
            __PUB__         ParseException();
            __PUB__ virtual ~ParseException() __override_func;

#pragma region Tianyu Exception Base Function
            __PUB__ virtual uint64 __VARIABLE__ GetExceptionId() __override_func;
            __PUB__ virtual uint64 __VARIABLE__ GetTypeId()      __override_func;
#pragma endregion
        };

        class ParseStringEmptyException
            : public virtual tianyu::TianyuObject,
            public virtual tianyu::except::ParseException
        {
            __PUB__         ParseStringEmptyException();
            __PUB__ virtual ~ParseStringEmptyException() __override_func;

#pragma region Tianyu Exception Base Function
            __PUB__ virtual uint64 __VARIABLE__ GetExceptionId() __override_func;
            __PUB__ virtual uint64 __VARIABLE__ GetTypeId()      __override_func;
#pragma endregion
        };
    }
}

#pragma region template realization

template<typename T> ::string tianyu::FormatHelper::Format(T& value)
{
    if (std::is_base_of<tianyu::IToString, T>::value)
        return tianyu::FormatHelper::Format((tianyu::IToString __REFERENCE__)value);

    return tianyu::_tianyu_native_cpp_default_to_string(value);
}

template<typename T> void tianyu::ParseHelper::Parse(const ::string s, T& result)
{
    throw tianyu::except::OperationNotSupportException();
}

#pragma endregion

#endif // !__cplusplus

#endif // !__TIANYU_COMMON_NATIVE_CORE_FORMATTER_H_PLUS_PLUS__