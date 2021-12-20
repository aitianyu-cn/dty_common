/**
 * @file utilize.hh(native/core)
 * @author senyun.yao
 * @brief 用于天宇平台的公用组件核心
 * @brief AiTianyu Platform Public Common Core
 *
 * @version 0.1
 * @date 2021-11-09
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_CORE_INTERNAL_UTILIZE_HH__
#define __DTY_COMMON_NATIVE_PRIME_CORE_INTERNAL_UTILIZE_HH__

#ifndef __cplusplus
#error only develop for C++
#endif // !__cplusplus

 // 天宇开发模式标志
#define __DTY_DEV_MODE__    1

#include"./utilize.h"

#ifdef __DTY_DEV_MODE__
 /**
  * @brief 该标识指示当前天库是否可以支持不安全的内存操作 
  * @brief The flag that allow unsafe memory operations in Tianyu Library when it is defined
  */
  // #define __DTY_UNSAFE_MODE__ "Tianyu Library Unsafe Mode"
    // #define __DTY_DEEP_LEARNING_MODE__
      // #define __DTY_SMART_POINTER_COPY_WEAK_MODE__
#else
#if __cplusplus < 201700
#error library needs C++17 or later
#endif
#endif // !__DTY_DEV_MODE__

// 公有访问权标志 指示修饰的函数与属性外部可访问
#define __PUB__ public:
// 私有访问权标志 指示修饰的函数与属性外部不可访问
#define __PRI__ private:
// 继承访问权标志 指示修饰的函数与属性子类可访问
#define __PRO__ protected:

// 引用类型 标志 用于标识以引用类型保存、传递的属性、变量和参数
#define __REFERENCE__ &
// 指针引用类型 标志 用于标识以指针引用类型保存、传递的属性、变量和参数
#define __PTRREFER__ *&

// 指针→引用类型转换 标志 用于标识指针类型到引用类型的转换
#define __PTR_TO_REF__ *
// 引用→指针类型转换 标志 用于标识引用类型到指针类型的转换
#define __REF_TO_PTR__ &
// 引用→值类型转换 标志 用于标识引用类型到值类型的转换
#define __REF_TO_VAR__
// 值→引用类型转换 标志 用于标识值类型到引用类型的转换
#define __VAR_TO_REF__

//
#define abstract
//
#define _interface abstract class

constexpr auto null = nullptr;

#ifdef __GNUC__
#include <cxxabi.h>
#endif // !__GNUC__

namespace dty
{
    __PREDEFINE__ template<typename T> class Type;
    __PREDEFINE__ template<typename T> Type<T> __VARIABLE__ GetType();
    __PREDEFINE__ template<typename T> Type<T> __VARIABLE__ GetType(T __REFERENCE__ obj);

    template<typename T>
    class Type final
    {
        __PRI__ static bool __VARIABLE__ _dummy;

        __PRI__::string __VARIABLE__ _Name;
        __PRI__ uint64  __VARIABLE__ _InstanceHash;

        __PRI__ Type() : _Name(null), _InstanceHash(0) { }
        __PRI__ Type(uint64 __VARIABLE__ instance) : _Name(null), _InstanceHash(instance) { }
        __PUB__ Type(const Type<T> __REFERENCE__ other) : _Name(null)
        {
            int32 nameLen = ::strlen(other._Name);

            this->_Name = new char[nameLen + 1];
            for (int32 i = 0; i < nameLen; ++i)
                this->_Name[i] = other._Name[i];

            this->_Name[nameLen] = '\0';
        }
        __PUB__ ~Type()
        {
            if (null != this->_Name)
                delete [](this->_Name);
        }

        __PUB__::string __VARIABLE__ Name() const
        {
            return this->_Name;
        }
        __PUB__ uint64  __VARIABLE__ Id()
        {
            return typeid(T).hash_code();
        }
        __PUB__ uint64  __VARIABLE__ InstanceHashCode()
        {
            return this->_InstanceHash;
        }

        friend Type<T> __VARIABLE__ GetType<T>();
        friend Type<T> __VARIABLE__ GetType<T>(T __REFERENCE__ obj);
    };

    template<typename T> bool Type<T>::_dummy = false;

    template<typename T>
    Type<T> __VARIABLE__ GetType()
    {
        ::string sourceName = const_cast<::string>(typeid(T).name());

        Type<T> type;
#ifdef __GNUC__
        int status;
        ::string demangled_name = abi::__cxa_demangle(sourceName, NULL, NULL, &status);
        if (0 != status)
        {
            int32 length = ::strlen(sourceName);
            demangled_name = new char[length + 1];
            for (int32 i = 0; i < length; ++i)
                demangled_name[i] = sourceName[i];
            demangled_name[length] = '\0';
        }
        type._Name = demangled_name;
#else // !__GNUC__

#endif // !__GNUC__
        return type;
    }
    template<typename T>
    Type<T> __VARIABLE__ GetType(T __REFERENCE__ obj)
    {
        ::string sourceName = const_cast<::string>(typeid(obj).name());

        Type<T> type((uint64)(__REF_TO_PTR__ obj));
#ifdef __GNUC__
        int status;
        ::string demangled_name = abi::__cxa_demangle(sourceName, NULL, NULL, &status);
        if (0 != status)
        {
            int32 length = ::strlen(sourceName);
            demangled_name = new char[length + 1];
            for (int32 i = 0; i < length; ++i)
                demangled_name[i] = sourceName[i];
            demangled_name[length] = '\0';
        }
        type._Name = demangled_name;
#else // !__GNUC__

#endif // !__GNUC__
        return type;
    }
}

#endif // !__DTY_COMMON_NATIVE_PRIME_CORE_INTERNAL_UTILIZE_HH__
