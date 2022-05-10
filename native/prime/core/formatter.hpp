/**
 * @file formatter.hpp
 * @author ysydty
 * @brief
 * @version 0.1
 * @date 2021-12-23
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_CORE_FORMATTER_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_CORE_FORMATTER_H_PLUS_PLUS__

#ifdef __cplusplus

#include "./internal.h"
#include "./error.hpp"
#include <type_traits>

namespace dty
{
    _interface IFormatter : public virtual dty::TianyuObject
    {
        __PUB__ virtual ~IFormatter() __override_func;

        __PUB__ virtual ::string __VARIABLE__ ToString(const ::string __VARIABLE__ formatter) __pure_virtual_fun;
    };

    class FormatHelper final : public virtual dty::TianyuObject
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

        __PUB__ static ::string __VARIABLE__ Format(dty::IToString __REFERENCE__ value);

        __PUB__ template<typename T> static ::string __VARIABLE__ Format(T __REFERENCE__ value);
    };

    class ParseHelper final : public virtual dty::TianyuObject
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
            : public virtual dty::TianyuObject,
            public virtual dty::except::Exception
        {
            __PUB__         ParseException();
            __PUB__ virtual ~ParseException() __override_func;

#pragma region Tianyu Exception Base Function
            __PUB__ virtual uint64 __VARIABLE__ GetExceptionId() __override_func;
            __PUB__ virtual uint64 __VARIABLE__ GetTypeId()      __override_func;
#pragma endregion
        };

        class ParseStringEmptyException
            : public virtual dty::TianyuObject,
            public virtual dty::except::ParseException
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

template<typename T> ::string dty::FormatHelper::Format(T& value)
{
    if (std::is_base_of<dty::IToString, T>::value)
        return dty::FormatHelper::Format((dty::IToString __REFERENCE__)value);

    return dty::_dty_native_cpp_default_to_string(value);
}

template<typename T> void dty::ParseHelper::Parse(const ::string s, T& result)
{
    throw dty::except::OperationNotSupportException();
}

#pragma endregion

#endif // !__cplusplus

#endif // !__DTY_COMMON_NATIVE_PRIME_CORE_FORMATTER_H_PLUS_PLUS__