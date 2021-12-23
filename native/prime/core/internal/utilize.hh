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
constexpr std::nullptr_t null = nullptr;

// #################################################################################################
// The Core APIs for Tianyu Native
// String Base APIs: in order to do some string operations without including a huge header files
// #################################################################################################

#pragma region c_string basic APIs
int32    __VARIABLE__ strlen(const ::string __VARIABLE__ str);

::string __VARIABLE__ uc2str(uchar __VARIABLE__ ch);
::string __VARIABLE__ sb2str(sbyte __VARIABLE__ sb, const ::string __VARIABLE__ formatter);
::string __VARIABLE__ b2str(::byte __VARIABLE__ b, const ::string __VARIABLE__ formatter);
::string __VARIABLE__ s2str(int16 __VARIABLE__ s, const ::string __VARIABLE__ formatter);
::string __VARIABLE__ us2str(uint16 __VARIABLE__ us, const ::string __VARIABLE__ formatter);
::string __VARIABLE__ i2str(int32 __VARIABLE__ i, const ::string __VARIABLE__ formatter);
::string __VARIABLE__ ui2str(uint32 __VARIABLE__ ui, const ::string __VARIABLE__ formatter);
::string __VARIABLE__ l2str(int64 __VARIABLE__ l, const ::string __VARIABLE__ formatter);
::string __VARIABLE__ ul2str(uint64 __VARIABLE__ ul, const ::string __VARIABLE__ formatter);
::string __VARIABLE__ f2str(float __VARIABLE__ f, const ::string __VARIABLE__ formatter);
::string __VARIABLE__ d2str(double __VARIABLE__ d, const ::string __VARIABLE__ formatter);
#pragma endregion

// #################################################################################################
// Data Type definition for Tianyu Class base
// Tianyu Type Helper (Type<T>)
// Tianyu ToString Interface (IToString)
// Tianyu Object Base (TianyuObject)
// Tianyu Object Null Pointer (TianyuEmptyObject)
// 
// Tianyu Class Type Marco Definition
// #################################################################################################

namespace dty
{
    // general data type class
    // get a name and type id to indicate a specified type
    __PREDEFINE__ template<typename T> class Type;
    __PREDEFINE__ template<typename T> Type<T> __VARIABLE__ GetType();
    __PREDEFINE__ template<typename T> Type<T> __VARIABLE__ GetType(T __REFERENCE__ obj);
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
    __PREDEFINE__ template<typename T> ::string __VARIABLE__ _dty_native_cpp_default_to_string(T __REFERENCE__ obj) noexcept;

    /**
     * @brief Tianyu Type Operation Object
     *
     * @tparam T Type
     */
    template<typename T> class Type final
    {
        // static object for each object
        // to make diffs for different data type
        __PRI__ static bool __VARIABLE__ _dummy;

        __PRI__::string __VARIABLE__ _Name;
        __PRI__ uint64  __VARIABLE__ _Id;
        __PRI__ uint64  __VARIABLE__ _InstanceHash;

        __PRI__ Type();
        __PRI__ Type(uint64        __VARIABLE__  instance);
        __PUB__ Type(const Type<T> __REFERENCE__ other);
        __PUB__ ~Type();

        __PUB__::string __VARIABLE__ Name() const;
        __PUB__ uint64  __VARIABLE__ Id();
        __PUB__ uint64  __VARIABLE__ InstanceHashCode();

        friend Type<T>  __VARIABLE__ GetType<T>();
        friend Type<T>  __VARIABLE__ GetType<T>(T __REFERENCE__ obj);
        friend ::string __VARIABLE__ _dty_native_cpp_default_to_string<T>(T __REFERENCE__ obj) noexcept;
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
        __PUB__ virtual ~IToString() { }

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept = 0;
    };

    // Tianyu Object 
    // this is a basic object type for Tianyu Native and all of the sub type in Tianyu Native
    // this is a hierarchy root for Data Type in Tianyu Native
    // Tianyu Object provides the basic and generic interfaces.
    abstract class TianyuObject : public virtual IToString
    {
        __PRO__ TianyuObject();
        __PUB__ virtual ~TianyuObject() override;

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId();
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode();

        __PUB__ virtual bool __VARIABLE__ IsNull();
        __PUB__ virtual bool __VARIABLE__ Equals(TianyuObject __REFERENCE__ obj);
        __PUB__ virtual bool __VARIABLE__ operator==(TianyuObject __REFERENCE__ obj);

        __PUB__ static  bool __VARIABLE__ IsNull(TianyuObject __REFERENCE__ obj);
    };

    // Internal Implementation for Tianyu Null Object
    // this is a sealed class and only provides null object replacement
    class TianyuEmptyObject final : public virtual TianyuObject
    {
        __PUB__ TianyuEmptyObject();
        __PUB__ virtual ~TianyuEmptyObject() override;

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() override;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() override;
        __PUB__ virtual bool     __VARIABLE__ IsNull() override;
    };

    // null value of Tianyu Object
    // should be used by adding namespace dty (dty::null)
    // if not, some unexpected error could be happended.
    extern const TianyuObject __REFERENCE__ null;
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

// #################################################################################################
// Import all of the Template class implementation files
// #################################################################################################
#include "./res/dty_get_type.cc"
#include "./res/dty_type.cc"

#endif // !__DTY_COMMON_NATIVE_PRIME_CORE_INTERNAL_UTILIZE_HH__
