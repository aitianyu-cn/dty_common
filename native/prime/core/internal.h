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

#include "./internal/cross_platform.h"
#include "./internal/utilize.h"

#ifdef __cplusplus

#include "./internal/utilize.hh"

namespace dty
{
    _interface IObjectConverter
    {
        __PUB__ virtual object __VARIABLE__ TryConvert(::byte __POINTER__ obj, int32 __VARIABLE__ objSize) = 0;
        __PUB__ virtual object __VARIABLE__ TryConvert(::byte __POINTER__ obj, int32 __VARIABLE__ objSize, int32 __VARIABLE__ startIndex) = 0;
    };
    _interface IStringConverter
    {
        __PUB__ virtual ::string __VARIABLE__ TryConvert(::byte __POINTER__ obj, int32 __VARIABLE__ objSize) const = 0;
        __PUB__ virtual ::string __VARIABLE__ TryConvert(::byte __POINTER__ obj, int32 __VARIABLE__ objSize, int32 __VARIABLE__ startIndex) const = 0;
    };

    /**
     * @brief Convert an object to string type
     * @note must to convert to a pointer that can be delete by caller, like Console.WriteLine(obj),
     *       when ToString is called in Console function implicitly, the ToString return should confirm
     *       the string can be released.
     *
     * @warning if the ToString function does just return a reference pointer, unexpected things will happen.
     *          Please make sure the incorrect realization does not be used for basic components of Tianyu
     *          Library.
     */
    _interface IToString
    {
        __PUB__ virtual ::string __VARIABLE__ ToString() = 0;
    };

    template<typename T>
    __DEFAULT__::string __VARIABLE__ _dty_native_cpp_default_to_string(T __REFERENCE__ obj)
    {
        ::string typeName = const_cast<::string>(dty::GetType(obj).Name());
        int32 typeNameLen = ::strlen(typeName);

        ::string str = new char[typeNameLen + 1];
        for (int32 i = 0; i < typeNameLen; ++i)
            str[i] = typeName[i];
        str[typeNameLen] = '\0';

        return str;
    }

    abstract class TianyuObject : IToString
    {
        __PUB__ virtual ~TianyuObject() { }

        __PUB__ virtual ::string __VARIABLE__ ToString() override
        {
            return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
        }
    };

    template<typename _Key, typename _Val>
    class KeyValuePair final : public virtual TianyuObject
    {
        __PUB__ _Key __VARIABLE__ Key;
        __PUB__ _Val __VARIABLE__ Value;

        __PUB__ KeyValuePair(_Key key, _Val val)
            : Key(key), Value(val)
        {

        }
        __PUB__ virtual ~KeyValuePair() override { }

        __PUB__ virtual ::string __VARIABLE__ ToString() override
        {
            return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
        }
    };

    namespace collection
    {
        enum class CompareResult : int32
        {
            LESS = -1,
            EQUAL = 0,
            GREAT = 1
        };

        template<class Elem>
        _interface IEquatable : public virtual TianyuObject
        {
            __PUB__ virtual ~IEquatable() override { };

            __PUB__ virtual bool __VARIABLE__ Equals(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator ==(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator !=(Elem __REFERENCE__ other) = 0;
        };

        template<class Elem>
        _interface ICompareable : public virtual TianyuObject
        {
            __PUB__ virtual ~ICompareable() override { };

            __PUB__ virtual CompareResult __VARIABLE__ CompareTo(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator ==(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator !=(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator <(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator >(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator <=(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator >=(Elem __REFERENCE__ other) = 0;
        };
    }
}

#endif // !__cplusplus

#endif // !__DTY_COMMON_NATIVE_PRIME_CORE_INTERNAL_H__