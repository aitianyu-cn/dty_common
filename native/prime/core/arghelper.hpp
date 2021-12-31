/**
 * @file arghelper.hpp(prime/core)
 * @author victor.yao
 * @brief
 * @version 0.1
 * @date 2021-12-31
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_CORE_ARGHELPER_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_CORE_ARGHELPER_H_PLUS_PLUS__

 // Only supported in C++
#ifdef __cplusplus

#include "./internal.h"
#include "./error.hpp"
#include "./property.hpp"
#include "./pointer.hpp"

namespace dty
{
    _enum ArgumentKeyType : int32
    {
        ShortKey,
        LongKey,
        Ext_Semicolon,
        Ext_Equal
    };

    _enum ArgumentValueState : int32
    {
        None = 0b00000001,
        Single = 0b00000010,
        Multi = 0b00000100
    };

    _enum ArgumentValueType : int32
    {
        SingleValue = 0b00000001,
        ExtendValue = 0b00000010
    };

    _interface IArgValue : public virtual dty::TianyuObject
    {
        __PRI__ Property<ArgumentValueType> __VARIABLE__ _ArgType;

        __PUB__ IPropertyGetter<ArgumentValueType> __REFERENCE__ ArgType;

        __PRO__         IArgValue(ArgumentValueType __VARIABLE__ arg_type);
        __PUB__ virtual ~IArgValue() override;

        __PUB__ virtual const ::string __VARIABLE__ Key()   __pure_virtual_fun;
        __PUB__ virtual const ::string __VARIABLE__ Value() __pure_virtual_fun;

        __PUB__ virtual ::string       __VARIABLE__ ToString() noexcept override;
        __PUB__ virtual ::string       __VARIABLE__ ToString(char __VARIABLE__ link) noexcept;
    };

    class SingleArgValue final : public virtual dty::TianyuObject, public virtual IArgValue
    {
        __PUB__         SingleArgValue();
        __PUB__ virtual ~SingleArgValue() override;

        __PUB__ virtual const ::string __VARIABLE__ Key() override;
        __PUB__ virtual const ::string __VARIABLE__ Value() override;
    };

    class ExtendArgValue final : public virtual dty::TianyuObject, public virtual IArgValue
    {
        __PUB__         ExtendArgValue();
        __PUB__ virtual ~ExtendArgValue() override;

        __PUB__ virtual const ::string __VARIABLE__ Key() override;
        __PUB__ virtual const ::string __VARIABLE__ Value() override;
    };

    static class ArgumentHelper
    {
        __PUB__ static SmartPointer<IArgValue> __VARIABLE__ CreateSingleValue(const ::string __VARIABLE__ value);
        __PUB__ static SmartPointer<IArgValue> __VARIABLE__ CreateExtendValue(const ::string __VARIABLE__ key, const ::string __VARIABLE__ value);
    };
}

#endif // !__cplusplus

#endif // !__DTY_COMMON_NATIVE_PRIME_CORE_ARGHELPER_H_PLUS_PLUS__