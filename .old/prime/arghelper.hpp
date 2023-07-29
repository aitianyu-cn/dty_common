/**
 * @file arghelper.hpp(prime/core)
 * @author victor.yao
 * @brief
 * @version 0.1
 * @date 2021-12-31
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 * Reg: (--[xxxx]*|-x)[:(:|=|+[:|=][+|0-9])]
 *      split:
 *              --xxx, -x                   : no value
 *              --xxx::, --xxx:=            : need value in ext-key
 *              --xxx:+, --xxx:+:, --xxx:=: : need value and value is key-value status
 *              --xxx:+0 ... 9,             : need value and value is key-value status
 *                                            (0 means the key-values should have at least one)
 *                                            (1-9 means the key-value(s) should have 1-9 item(s))
 *
 * Summary:
 *      1. Pre-Char                                 -| Key Type: Single or Multi
 *      2. Arg Key Name (Single or Multi-String)    -| Single is only one character, Multi support string
 *      3. Value Type (None Value or Ext Key-Value or Independent Value)    -| this can be multi options to support all type
 *      4. Key-Value Connection (':' or '=' char)                           -| this one is also combine with Value Type to be multi option
 *      5. Value Count (1-9, At least 1) [only for Independent Value, Ext Key-Value Only Support One Value]
 */

 // #ifndef __DTY_COMMON_NATIVE_PRIME_CORE_ARGHELPER_H_PLUS_PLUS__
 // #define __DTY_COMMON_NATIVE_PRIME_CORE_ARGHELPER_H_PLUS_PLUS__

 //  // Only supported in C++
 // #ifdef __cplusplus

 // #include "./internal.h"
 // #include "./error.hpp"
 // #include "./property.hpp"
 // #include "./pointer.hpp"

 // namespace dty
 // {
 //     _enum ArgumentKeyType : int32
 //     {
 //         SingleKey,
 //         MultiKey
 //     };

 //     _enum ArgumentValueType : int32
 //     {
 //         None = 0b00000001,
 //         KeyValue = 0b00000010,
 //         IdpValue = 0b00000100,
 //         ExtValue = 0b00001000,
 //     };

 //     // Argument Item is a package to save a type of arg
 //     // to indicate what the argument name is and the details
 //     class ArgumentItem : public virtual dty::TianyuObject
 //     {
 //         __PUB__ ArgumentKeyType   __VARIABLE__ KeyType;
 //         __PUB__::string           __VARIABLE__ KeyName;
 //         __PUB__ ArgumentValueType __VARIABLE__ ValueType;
 //         __PUB__ int32             __VARIABLE__ ValueCount;
 //     };

 //     // Predefine for Argument Processor
 //     __PREDEFINE__ class ArgumentProcessor;

 //     // Argument Definition
 //     // is an index class for Argument Processor to classify each type of
 //     // arg and whether the arguament and its value is valid.
 //     class ArgumentDefinition
 //     {
 //         // indicate the Processor is a friend class for Argument Definition
 //         friend class ArgumentProcessor;
 //     };

 //     // Arguments
 //     // this class is a package for args which are decoded already,
 //     // save only the available args
 //     // at the same time, recording the error args
 //     class Arguments
 //     {
 //         // indicate the Processor is a friend class for Arguments
 //         friend class ArgumentProcessor;
 //     };

 //     // Argument Processor
 //     // contains the main logics to process argument array
 //     // input the Argument Definitions
 //     // output Arguments
 //     class ArgumentProcessor
 //     {

 //     };

 //     // __PREDEFINE__ class ArgumentHelper;

 //     // _interface IArgValue : public virtual dty::TianyuObject
 //     // {
 //     //     __PRI__ Property<ArgumentValueType> __VARIABLE__ _ArgType;

 //     //     __PUB__ IPropertyGetter<ArgumentValueType> __REFERENCE__ ArgType;

 //     //     __PRO__         IArgValue(ArgumentValueType __VARIABLE__ arg_type);
 //     //     __PUB__ virtual ~IArgValue() override;

 //     //     __PUB__ virtual string_sp __VARIABLE__ Key()   __pure_virtual_fun;
 //     //     __PUB__ virtual string_sp __VARIABLE__ Value() __pure_virtual_fun;

 //     //     __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override;
 //     //     __PUB__ virtual ::string __VARIABLE__ ToString(char __VARIABLE__ link) noexcept;

 //     //     __PUB__ virtual bool     __VARIABLE__ Equals(dty::TianyuObject __REFERENCE__ obj) override;
 //     //     __PUB__ virtual bool     __VARIABLE__ operator==(dty::TianyuObject __REFERENCE__ obj) override;
 //     //     __PUB__ virtual uint64   __VARIABLE__ GetTypeId() override;
 //     // };

 //     // _interface IArgKey : public virtual dty::TianyuObject
 //     // {
 //     //     __PRI__ Property<ArgumentKeyType> __VARIABLE__ _ArgType;
 //     //     __PRI__ int32                     __VARIABLE__ _ValueState;
 //     //     __PRI__ string_sp                 __VARIABLE__ _Key;

 //     //     __PUB__ IPropertyGetter<ArgumentKeyType> __REFERENCE__ ArgType;

 //     //     __PRO__         IArgKey(ArgumentKeyType __VARIABLE__ arg_type, ::string __VARIABLE__ key, int32 __VARIABLE__ ksize);
 //     //     __PUB__ virtual ~IArgKey() override;

 //     //     __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override;

 //     //     __PUB__ virtual bool     __VARIABLE__ Equals(dty::TianyuObject __REFERENCE__ obj) override;
 //     //     __PUB__ virtual bool     __VARIABLE__ operator==(dty::TianyuObject __REFERENCE__ obj) override;
 //     //     __PUB__ virtual uint64   __VARIABLE__ GetTypeId() override;

 //     //     __PUB__ string_sp __VARIABLE__ Key();
 //     //     __PUB__ bool      __VARIABLE__ IsNoneValue();
 //     //     __PUB__ bool      __VARIABLE__ IsSingleValue();
 //     //     __PUB__ bool      __VARIABLE__ IsMultiValue();

 //     //     __PRO__ void      __VARIABLE__ setValueState(ArgumentValueState state);

 //     //     friend class ArgumentHelper;
 //     // };

 //     // static class ArgumentHelper
 //     // {
 //     //     __PUB__ static SmartPointer<IArgValue> __VARIABLE__ CreateSingleValue(const ::string __VARIABLE__ value);
 //     //     __PUB__ static SmartPointer<IArgValue> __VARIABLE__ CreateExtendValue(const ::string __VARIABLE__ key, const ::string __VARIABLE__ value);

 //     //     __PUB__ static SmartPointer<IArgKey>   __VARIABLE__ CreateKey(const ::string __VARIABLE__ key, ArgumentKeyType type);
 //     //     __PUB__ static void                    __VARIABLE__ SetValueType(SmartPointer<IArgKey> __REFERENCE__ key);
 //     // };

 //     // class SingleArgValue final : public virtual dty::TianyuObject, public virtual IArgValue
 //     // {
 //     //     __PRI__ string_sp __VARIABLE__ _Value;

 //     //     __PRO__         SingleArgValue(::string __VARIABLE__ value, int32 __VARIABLE__ size);
 //     //     __PUB__ virtual ~SingleArgValue() override;

 //     //     __PUB__ virtual string_sp __VARIABLE__ Key() override;
 //     //     __PUB__ virtual string_sp __VARIABLE__ Value() override;

 //     //     friend class ArgumentHelper;
 //     // };

 //     // class ExtendArgValue final : public virtual dty::TianyuObject, public virtual IArgValue
 //     // {
 //     //     __PRI__ string_sp __VARIABLE__ _Value;
 //     //     __PRI__ string_sp __VARIABLE__ _Key;

 //     //     __PRO__         ExtendArgValue(::string __VARIABLE__ key, int32 __VARIABLE__ ksize, ::string __VARIABLE__ value, int32 __VARIABLE__ vsize);
 //     //     __PUB__ virtual ~ExtendArgValue() override;

 //     //     __PUB__ virtual string_sp __VARIABLE__ Key() override;
 //     //     __PUB__ virtual string_sp __VARIABLE__ Value() override;

 //     //     friend class ArgumentHelper;
 //     // };

 // }

 // #endif // !__cplusplus

 // #endif // !__DTY_COMMON_NATIVE_PRIME_CORE_ARGHELPER_H_PLUS_PLUS__