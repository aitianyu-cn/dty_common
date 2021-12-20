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

    abstract class TianyuObject : IToString
    {
        __PRI__ const ::string __VARIABLE__ ObjectName = "dty.object";

        __PUB__ virtual ~TianyuObject() { }

        __PUB__ virtual ::string __VARIABLE__ ToString() override
        {
            ::string str = new char[11];
            for (int32 i = 0; i < 10; ++i)
                str[i] = TianyuObject::ObjectName[i];
            str[10] = '\0';

            return str;
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

        __PRI__ const ::string __VARIABLE__ ObjectName = "dty.KeyValuePair";
        __PUB__ virtual ::string __VARIABLE__ ToString() override
        {
            int32 strLen = 16;
            ::string str = new char[strLen + 1];
            for (int32 i = 0; i < strLen; ++i)
                str[i] = KeyValuePair::ObjectName[i];
            str[strLen] = '\0';

            return str;
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

namespace dty
{
    class Random : public virtual TianyuObject
    {
        __PUB__ Random();
        __PUB__ Random(int32 __VARIABLE__ seed);

        __PUB__ virtual int32  __VARIABLE__ Next();
        __PUB__ virtual int32  __VARIABLE__ Next(int32 __VARIABLE__ maxValue);
        __PUB__ virtual int32  __VARIABLE__ Next(int32 __VARIABLE__ minValue, int32 __VARIABLE__ maxValue);
        __PUB__ virtual void   __VARIABLE__ NextBytes(::byte __POINTER__ buffer, int32 __VARIABLE__ blength);
        __PUB__ virtual double __VARIABLE__ NextDouble();

        __PRO__ virtual double __VARIABLE__ Sample();

        __PRI__ const ::string __VARIABLE__ ObjectName = "dty.Random";
        __PUB__ virtual ::string __VARIABLE__ ToString() override
        {
            int32 strLen = 10;
            ::string str = new char[strLen + 1];
            for (int32 i = 0; i < strLen; ++i)
                str[i] = Random::ObjectName[i];
            str[strLen] = '\0';

            return str;
        }
    };
}

#endif // !__cplusplus

#endif // !__DTY_COMMON_NATIVE_PRIME_CORE_INTERNAL_H__