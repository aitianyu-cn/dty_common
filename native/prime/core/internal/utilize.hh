/**
 * @file utilize.hh(native/core)
 * @author senyun.yao
 * @brief 用于天宇平台的公用组件核心
 * @brief AiTianyu Platform Public Common Core (C++ only)
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

// abstract class define
#define abstract
// define interface that is an abstract class
#define _interface abstract class

// null value for pointer, must to be used by adding "::" ahead (::null)
constexpr auto null = nullptr;

#ifdef __GNUC__
#include <cxxabi.h>
#endif // !__GNUC__

namespace dty
{
    // general data type class
    // get a name and type id to indicate a specified type
    __PREDEFINE__ template<typename T> class Type;
    __PREDEFINE__ template<typename T> Type<T> __VARIABLE__ GetType();
    __PREDEFINE__ template<typename T> Type<T> __VARIABLE__ GetType(T __REFERENCE__ obj);

    template<typename T>
    class Type final
    {
        __PRI__ static bool __VARIABLE__ _dummy;

        __PRI__::string __VARIABLE__ _Name;
        __PRI__ uint64  __VARIABLE__ _Id;
        __PRI__ uint64  __VARIABLE__ _InstanceHash;

        __PRI__ Type() : _Name(::null), _InstanceHash(0) { }
        __PRI__ Type(uint64 __VARIABLE__ instance) : _Name(::null), _InstanceHash(instance) { }
        __PUB__ Type(const Type<T> __REFERENCE__ other) : _Name(::null)
        {
            int32 nameLen = ::strlen(other._Name);

            this->_Name = new char[nameLen + 1];
            for (int32 i = 0; i < nameLen; ++i)
                this->_Name[i] = other._Name[i];

            this->_Name[nameLen] = '\0';
        }
        __PUB__ ~Type()
        {
            if (::null != this->_Name)
                delete [](this->_Name);
        }

        __PUB__::string __VARIABLE__ Name() const
        {
            return this->_Name;
        }
        __PUB__ uint64  __VARIABLE__ Id()
        {
            return this->_Id;
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
#else // !__GNUC__
        int32 length = ::strlen(sourceName);
        ::string demangled_name = new char[length + 1];
        for (int32 i = 0; i < length; ++i)
            demangled_name[i] = sourceName[i];
        demangled_name[length] = '\0';
#endif // !__GNUC__
        type._Name = demangled_name;
        type._Id = typeid(T).hash_code();

        return type;
    }
    template<typename T>
    Type<T> __VARIABLE__ GetType(T __REFERENCE__ obj)
    {
        ::string sourceName = const_cast<::string>(typeid(T).name());

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
#else // !__GNUC__
        int32 length = ::strlen(sourceName);
        ::string demangled_name = new char[length + 1];
        for (int32 i = 0; i < length; ++i)
            demangled_name[i] = sourceName[i];
        demangled_name[length] = '\0';
#endif // !__GNUC__
        type._Name = demangled_name;
        type._Id = typeid(T).hash_code();

        return type;
    }

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
        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept = 0;
    };

    /**
     * @brief internal default function: to get a general object full name from a template type
     *        (specified object).
     *
     * @tparam T template type
     * @param obj specified object
     * @return __DEFAULT__::string return a full name of the specified object
     *
     * @warning Pay attention: MUST to release the return value before it is discarded.
     */
    template<typename T>
    __DEFAULT__::string __VARIABLE__ _dty_native_cpp_default_to_string(T __REFERENCE__ obj) noexcept
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
        __PRO__ TianyuObject() { }

        __PUB__ virtual ~TianyuObject() { }

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override
        {
            return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
        }
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()
        {
            return dty::GetType(__PTR_TO_REF__ this).Id();
        }
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode()
        {
            return (uint64)(this);
        }

        __PUB__ virtual bool   __VARIABLE__ IsNull()
        {
            return false;
        }
        __PUB__ virtual bool   __VARIABLE__ Equals(TianyuObject __REFERENCE__ obj)
        {
            return this->GetTypeId() == obj.GetTypeId() && this->GetHashCode() == obj.GetHashCode();
        }
        __PUB__ bool __VARIABLE__ operator==(TianyuObject __REFERENCE__ obj)
        {
            return this->GetTypeId() == obj.GetTypeId() && this->GetHashCode() == obj.GetHashCode();
        }

        __PUB__ static bool __VARIABLE__ IsNull(TianyuObject __REFERENCE__ obj)
        {
            return 0ULL == obj.GetHashCode();
        }
    };

    class TianyuEmptyObject final : TianyuObject
    {
        __PUB__ virtual ~TianyuEmptyObject() { }

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override
        {
            return new char[5]{ 'n', 'u', 'l', 'l', '\0' };
        }
        __PUB__ virtual uint64 __VARIABLE__ GetTypeId() override
        {
            return 0ULL;
        }
        __PUB__ virtual uint64 __VARIABLE__ GetHashCode() override
        {
            return 0ULL;
        }
        __PUB__ virtual bool   __VARIABLE__ IsNull() override
        {
            return true;
        }
    };

    // null value of Tianyu Object
    // should be used by adding namespace dty (dty::null)
    // if not, some unexpected error could be happended.
    const TianyuEmptyObject __VARIABLE__ null;
}

// internal macro definition for tianyu class type
#define _ty_class(cname, ...) class cname : __VA_ARGS__

// Macro Definition for Tianyu Class Type
// Default externed from dty::TianyuObject, provide external functions
#define _class(cname, ...) _ty_class(cname, public virtual dty::TianyuObject, ##__VA_ARGS__)

// Macro Definition for Tianyu Class final Type
// Default externed from dty::TianyuObject, provide external functions
#define _sealed(cname, ...) _ty_class(cname final, public virtual dty::TianyuObject, ##__VA_ARGS__)

// Macro Definition for clearly enum define
// enum class
#define _enum enum class

#endif // !__DTY_COMMON_NATIVE_PRIME_CORE_INTERNAL_UTILIZE_HH__
