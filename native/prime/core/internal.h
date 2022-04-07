/**
 * @file internal.h(prime/core)
 * @author senyun.yao
 * @brief C++ 本地方法导出模块（公共模块）
 * @brief native export module, common module
 *
 * @version 0.1
 * @date 2021-12-02
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.random?view=net-6.0
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_CORE_INTERNAL_H__
#define __DTY_COMMON_NATIVE_PRIME_CORE_INTERNAL_H__

#ifdef __cplusplus

#include "../../dty-core.hxx"

namespace dty
{
    _interface IObjectConverter : public virtual dty::TianyuObject
    {
        __PUB__ virtual ~IObjectConverter() { }

        __PUB__ virtual object __VARIABLE__ TryConvert(::byte __POINTER__ obj, int32 __VARIABLE__ objSize)                                __pure_virtual_fun;
        __PUB__ virtual object __VARIABLE__ TryConvert(::byte __POINTER__ obj, int32 __VARIABLE__ objSize, int32 __VARIABLE__ startIndex) __pure_virtual_fun;
    };
    _interface IStringConverter : public virtual dty::TianyuObject
    {
        __PUB__ virtual ~IStringConverter() { }

        __PUB__ virtual ::string __VARIABLE__ TryConvert(::byte __POINTER__ obj, int32 __VARIABLE__ objSize)                                const __pure_virtual_fun;
        __PUB__ virtual ::string __VARIABLE__ TryConvert(::byte __POINTER__ obj, int32 __VARIABLE__ objSize, int32 __VARIABLE__ startIndex) const __pure_virtual_fun;
    };

    template<typename _Key, typename _Val>
    class KeyValuePair final : public virtual dty::TianyuObject
    {
        __PUB__ _Key __VARIABLE__ Key;
        __PUB__ _Val __VARIABLE__ Value;

        __PUB__         KeyValuePair(_Key __VARIABLE__ key, _Val __VARIABLE__ val);
        __PUB__         KeyValuePair(const KeyValuePair<_Key, _Val> __REFERENCE__ other);
        __PUB__ virtual ~KeyValuePair() __override_func;

        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;
    };

    namespace collection
    {
        _enum CompareResult : int32
        {
            LESS = -1,
            EQUAL = 0,
            GREAT = 1
        };

        template<class Elem>
        _interface IEquatable : public virtual dty::TianyuObject
        {
            __PUB__         IEquatable() : TianyuObject() { }
            __PUB__ virtual ~IEquatable() __override_func { };

            __PUB__ virtual bool __VARIABLE__ Equals(Elem __REFERENCE__ other)      __pure_virtual_fun;
            __PUB__ virtual bool __VARIABLE__ operator ==(Elem __REFERENCE__ other) __pure_virtual_fun;
            __PUB__ virtual bool __VARIABLE__ operator !=(Elem __REFERENCE__ other) __pure_virtual_fun;
        };

        template<class Elem>
        _interface ICompareable : public virtual dty::TianyuObject
        {
            using CPRT = dty::collection::CompareResult;

            __PUB__         ICompareable() : TianyuObject() { }
            __PUB__ virtual ~ICompareable() __override_func { };

            __PUB__ virtual CPRT __VARIABLE__ CompareTo(Elem __REFERENCE__ other)   __pure_virtual_fun;
            __PUB__ virtual bool __VARIABLE__ operator ==(Elem __REFERENCE__ other) __pure_virtual_fun;
            __PUB__ virtual bool __VARIABLE__ operator !=(Elem __REFERENCE__ other) __pure_virtual_fun;
            __PUB__ virtual bool __VARIABLE__ operator <(Elem __REFERENCE__ other)  __pure_virtual_fun;
            __PUB__ virtual bool __VARIABLE__ operator >(Elem __REFERENCE__ other)  __pure_virtual_fun;
            __PUB__ virtual bool __VARIABLE__ operator <=(Elem __REFERENCE__ other) __pure_virtual_fun;
            __PUB__ virtual bool __VARIABLE__ operator >=(Elem __REFERENCE__ other) __pure_virtual_fun;
        };
    }

    namespace i18n
    {
        _enum LanguageArea : int32
        {

        };

        _enum Location : int32
        {

        };
    }
}

#include "./res/internal.cc"

#endif // !__cplusplus

#endif // !__DTY_COMMON_NATIVE_PRIME_CORE_INTERNAL_H__