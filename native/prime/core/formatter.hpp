/**
 * @file formatter.hpp
 * @author ysydty
 * @brief
 * @version 0.1
 * @date 2021-12-23
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_CORE_FORMATTER_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_CORE_FORMATTER_H_PLUS_PLUS__

#ifdef __cplusplus

#include "../core.hxx"

namespace dty
{
    _interface IFormatter : public virtual dty::TianyuObject
    {
        __PUB__ virtual ~IFormatter() { }

        __PUB__ virtual ::string __VARIABLE__ ToString(const ::string __VARIABLE__ formatter) __pure_virtual_fun;
    };

    _enum NumberSystem : int32
    {
        BIN,
        OCT,
        DEC,
        HEX
    };

    class Formatter final : public virtual dty::TianyuObject
    {
        __PUB__ Property<bool>         __VARIABLE__ ExplicitSign;
        __PUB__ Property<int32>        __VARIABLE__ FullLength;
        __PUB__ Property<int32>        __VARIABLE__ IntegerLength;
        __PUB__ Property<int32>        __VARIABLE__ DecimalsLength;
        __PUB__ Property<NumberSystem> __VARIABLE__ NumberConvert;
        __PUB__ Property<bool>         __VARIABLE__ Percentage;

        __PUB__         Formatter();
        __PUB__         Formatter(const ::string __VARIABLE__ formatter);
        __PUB__ virtual ~Formatter() __override_func;

        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
    };

    // format handler class
    // get an object to indicate the formatter parameters
    // provide a decoder for formatter string
    class FormatHandler final : public virtual dty::TianyuObject
    {

    };

    // format processor class
    // provide static methods to process base type
    class FormatProcessor final : public virtual dty::TianyuObject
    {

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

        __PUB__ template<typename T> static ::string __VARIABLE__ Format(T __VARIABLE__ value, const ::string __VARIABLE__ formatter)
        {
            return ::null;
        }
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

        __PUB__ template<typename T> static void __VARIABLE__ Parse(const ::string __VARIABLE__ s, __OTPUT__ T __REFERENCE__ result)
        {
            // Todo: keep none operation
        }
    };
}

#endif // !__cplusplus

#endif // !__DTY_COMMON_NATIVE_PRIME_CORE_FORMATTER_H_PLUS_PLUS__