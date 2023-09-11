/**
 * @file core.hxx(native/core)
 * @author senyun.yao
 * @section C/C++
 * @brief 用于天宇平台的公用组件核心 包含跨平台支持
 * @brief AiTianyu Platform Public Common Core (C/C++)
 *        including supporting for cross platform, basic supporting for C/C++ and Test Components Core of Tianyu Framework
 *
 * @version 0.1
 * @date 2021-11-09
 * @date 2021-12-28
 * @date 2023-07-29
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __TIANYU_COMMON_NATIVE_CORE_HXX__
#define __TIANYU_COMMON_NATIVE_CORE_HXX__

#pragma region Language_Part
 //
// 引用静态多语言文件
// Includes static Multi-Language file
#include "./res/i18n/language.h"

// 字符串替换宏函数
// message string convert macro-function
#define __TY_CORE_MSG_CONVERT(msg) msg

#pragma endregion

#pragma region Toggle_Part
// 引用静态核心功能描述文件
// Includes static Feature Toggle file
#include "./res/feature/feature_core.h"
#pragma endregion

#pragma region Cross_platform_Part
//
// 引入跨平台定义
// Includes cross Platform Definition
#include "./cross-platform.h"
// 跨平台错误处理 处理不兼容的平台
#ifdef __TIANYU_PLATFORM_ERROR

#ifdef __TIANYU_ERROR_PLATFORM_WIN32
#error __TY_CORE_MSG_CONVERT(__ERROR_CPP_TIANYU_PLATFORM_REQUIRE_64__)
#endif // !__TIANYU_ERROR_PLATFORM_WIN32

#ifdef __TIANYU_ERROR_PLATFORM_APPLE
#error __TY_CORE_MSG_CONVERT(__ERROR_CPP_UNKNOWN_APPLE_PLATFORM__)
#endif // !__TIANYU_ERROR_PLATFORM_APPLE

#ifdef __TIANYU_ERROR_PLATFORM_LNX32
#error __TY_CORE_MSG_CONVERT(__ERROR_CPP_TIANYU_PLATFORM_REQUIRE_64__)
#endif // !__TIANYU_ERROR_PLATFORM_LNX32

#endif // !__TIANYU_PLATFORM_ERROR

#if !defined(__TIANYU_WIN) && !defined(__TIANYU_APF) && !defined(__TIANYU_LINUX)
#error __TY_CORE_MSG_CONVERT(__ERROR_CPP_TIANYU_PLATFORM_UNKNOWN_OS__)
#endif // !!defined(__TIANYU_WIN) && !defined(__TIANYU_APF) && !defined(__TIANYU_LINUX)

#pragma endregion

#pragma region Basic_Type_Def
//
// 引入基本类型定义
// Includes Basic types Definition
#include "./basic-types.h"

// 基本类型定义中的异常处理
// Exception handler for basic types definition
#ifdef __TIANYU_CPP_ENV_LOW
#error __TY_CORE_MSG_CONVERT(__ERROR_CPP_VERSION_LOW__)
#endif // !__TIANYU_CPP_ENV_LOW

#pragma endregion

//
// ################################################################
// 天宇扩展支持部分 C/C++
// Tianyu Extend Supporting Part C/C++
// ################################################################
#ifdef __cplusplus
namespace tianyu
{
    /**
     * @brief 获取一个值指示指定字符串的长度
     * @brief Get a value that equals to string length
     *
     * @param str 指定的字符串 | specified string
     * @return int32 返回字符串长度 （字符串为空时返回0）| return the length of string (return 0 if the string is empty)
     */
    int32    __VARIABLE__ strlen(const ::string __VARIABLE__ str);
    /**
     * @brief 获取一个值，该值指示指定两个字符串的大小关系
     * @brief Get a value that indicates the comparation of the two strings
     *
     * @param s1 字符串1 | first string
     * @param s2 字符串2 | second string
     * @param ignoreCase 指示是否忽略大小写检查（默认检查大小写）| Indicates whether ignore the char case
     * @return int32 返回 0 - 字符串1和字符串2相等 | 1 - 字符串1大于字符串2 | -1 - 字符串1小于字符串2
     * @return int32 return 0 if the first string equals to second | return 1 if first string is greater than second | return -1 if first string is less than second
     */
    int32    __VARIABLE__ strcmp(const ::string __VARIABLE__ s1, const ::string __VARIABLE__ s2, bool __VARIABLE__ ignoreCase = false);
}

__CMODE__
{
#endif // !__cplusplus

#ifdef __cplusplus
}
#endif // !__cplusplus

//
// ################################################################
// 天宇扩展支持部分 C++ Only
// Tianyu Extend Supporting Part C++ Only
// ################################################################
#ifdef __cplusplus
namespace tianyu
{
    /**
     * @brief 对象类型类，获取对象唯一的类型名称和类型ID
     * @brief object type class, get a name and type id to indicate a unified type
     */
    __PREDEFINE__ template<typename T> class Type;

    /**
     * @brief 获取一个对象的类型
     * @brief Get the Type object
     */
    __PREDEFINE__ template<typename T> Type<T>  __VARIABLE__ GetType();

    /**
     * @brief 获取一个指定实例的对象类型
     * @brief Get the Type object from object instance
     *
     * @param obj 指定的对象 ｜ specified object instance
     */
    __PREDEFINE__ template<typename T> Type<T>  __VARIABLE__ GetType(T __REFERENCE__ obj);
    /**
     * @brief 内部方法：用于获取对象的类型全名
     * @brief internal default function: to get a general object full name from a template type
     *        (specified object).
     *
     * @tparam T 模板类型 ｜ template type
     * @param obj 指定的对象实例 ｜specified object
     * @return ::string 返回一个类型的全名 ｜return a full name of the specified object
     *
     * @warning 注意：在不在使用字符串之前，必须释放字符串的内存
     * @warning Pay attention: MUST to release the return value before it is discarded.
     */
    __PREDEFINE__ template<typename T> ::string __VARIABLE__ _tianyu_native_cpp_default_to_string(T __REFERENCE__ obj) noexcept;

    /**
     * @brief 天宇类型类
     * @brief Tianyu Type Class
     *
     * @tparam T Type
     */
    template<typename T> class Type final
    {
        __PRI__ static bool __VARIABLE__ _dummy;

        __PRI__::string __VARIABLE__ _Name;
        __PRI__ uint64  __VARIABLE__ _Id;
        __PRI__ uint64  __VARIABLE__ _InstanceHash;

        __PRI__ __construction__ Type();
        __PRI__ __construction__ Type(uint64        __VARIABLE__  instance);

        /**
         * @brief 从指定的类型实例创建一个新的类型
         * @brief Create a new type instance from another instance
         *
         * @param other 指定的类型实例 ｜a specified type instance
         */
        __PUB__ __cp_construct__ Type(const Type<T> __REFERENCE__ other);
        __PUB__ __destruction__  ~Type();

        /**
         * @brief 获取指定类型的全名
         * @brief Get a name that equals to the template class name
         *
         * @return ::string 返回全名字符串 ｜return a name string
         *
         * @warning 注意：在不在使用字符串之前，必须释放字符串的内存
         * @warning Pay attention: MUST to release the return value before it is discarded.
         */
        __PUB__::string __VARIABLE__ Name() const;
        /**
         * @brief 获取一个64位无符号整数用于唯一标记一个类型
         * @brief Get a 64bit unsigned integer that indicates a data type
         *
         * @return 返回64位无符号整数 ｜ 64bit unsigned integer
         */
        __PUB__ uint64  __VARIABLE__ Id();
        /**
         * @brief 获取一个类型实例的哈希值，只有通过实例获取类型时哈希值有效，否则默认值为0
         * @brief Get a object instance hashcode, only vailable if the type instance is init with a object instance, default value is 0
         *
         * @return 返回64位无符号整数 ｜ 64bit unsigned integer
         */
        __PUB__ uint64  __VARIABLE__ InstanceHashCode();

        friend Type<T>  __VARIABLE__ GetType<T>();
        friend Type<T>  __VARIABLE__ GetType<T>(T __REFERENCE__ obj);
        friend ::string __VARIABLE__ _tianyu_native_cpp_default_to_string<T>(T __REFERENCE__ obj) noexcept;
    };

    /**
     * @brief 字符串转换接口，用于提供字符串转换的默认方法
     * @brief Convert an object to string type
     * @note 转换完成的字符串必须为外部可释放的指针类型，例如使用Console.WriteLine(obj)方法调用中，
     *       当ToString方法在Console内部实现调用时，必须可以通过delete进行内存释放。
     * @note must to convert to a pointer that can be delete by caller, like Console.WriteLine(obj),
     *       when ToString is called in Console function implicitly, the ToString return should confirm
     *       the string can be released.
     *
     * @warning 如果ToString函数仅仅只返回一个指针的引用时，将会引发不可意料的错误。请确保错误的实现不被使用在天宇库中
     * @warning if the ToString function does just return a reference pointer, unexpected things will happen.
     *          Please make sure the incorrect realization does not be used for basic components of Tianyu
     *          Library.
     */
    _interface IToString
    {
        __PUB__ virtual __destruction__ ~IToString() { }

    /**
     * @brief 获取一个字符串等价于当前的实例
     * @brief Get a string value that equals to current instance
     *
     * @return 返回一个字符串值 ｜ return a string value
     *
     * @warning 请谨慎使用当前函数，特别是当实现函数只返回指定字符串的指针引用时
     * @warning Please carefully to use this function since the returned value is only a reference from actual
     */
    __PUB__ virtual ::string __VARIABLE__ ToString() noexcept __pure_virtual_fun;
    };

    /**
     * @brief 天宇对象
     *        这是天宇Native库的根类型，所有子类型都继承于该类型。该类型中提供基本和通用的接口。
     * @brief Tianyu Object
     *        this is a basic object type for Tianyu Native and all of the sub type in Tianyu Native
     *        this is a hierarchy root for Data Type in Tianyu Native
     *        Tianyu Object provides the basic and generic interfaces.
     */
    abstract class TianyuObject : public virtual tianyu::IToString
    {
        /**
         * @brief 默认构造函数
         * @brief Default construction
         */
        __PRO__         __construction__ TianyuObject();
        __PUB__ virtual __destruction__  ~TianyuObject() __override_func;

        /**
         * @brief 获取一个字符串等价于当前实例
         * @brief Get a string that equals to current instance
         *
         * @return 返回一个字符串 ｜ return a string
         */
        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept __override_func;
        /**
         * @brief 获取当前类型的类型ID
         * @brief Get the object type id
         *
         * @return 返回类型ID ｜ return type id
         */
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId();
        /**
         * @brief 返回当前实例的哈希值
         * @brief Get the instance hash code
         *
         * @return 返回一个64位无符号整数哈希值 ｜ return a 64bit unsigned integer as hashcode
         */
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode();

        /**
         * @brief 获取一个布尔值指示当前对象是否为空
         * @brief Get a boolean value that indicates the current instance is null.
         *
         * @return 返回一个布尔值 ｜ return a boolean value
         */
        __PUB__ virtual bool __VARIABLE__ IsNull();
        /**
         * @brief 比较指定实例是否等价于当前实例
         * @brief Get whether the specified object does equal to current instance
         *
         * @param obj 指定的实例 ｜ the specified object instance
         * @return 返回true则指定实例等于当前实例，否则为false ｜ return does the specified object equals to current instance
         */
        __PUB__ virtual bool __VARIABLE__ Equals(TianyuObject __REFERENCE__ obj);
        /**
         * @brief ==运算符重载（详情参考Equals方法）
         * @brief Operator override for Equals (See function - Equals)
         *
         * @param obj 指定的对象实例 ｜ the specified object instance
         * @return 返回true则指定实例等于当前实例，否则为false ｜ return does the specified object equals to current instance
         */
        __PUB__ virtual bool __VARIABLE__ operator==(TianyuObject __REFERENCE__ obj);

        /**
         * @brief 获取一个布尔值指示指定对象是否为空
         * @brief Get a boolean value that indicates the current instance is null.
         *
         * @param obj 指定对象的实例 ｜ a specified object instance
         * @return 返回一个布尔值 ｜ return a boolean value
         */
        __PUB__ static  bool __VARIABLE__ IsNull(TianyuObject __REFERENCE__ obj);
    };

    /**
     * @brief 值对齐基本值 - 默认对齐至2进制
     * @brief Value align base assigned to binary value
     */
    constexpr int32 ValueAlignBaseDefault = 2;
    /**
     * @brief 值对齐基本指数 - 默认对齐到2进制的指定次方
     * @brief Value align exp assigned to binary value
     */
    constexpr int32 ValueAlignPowerDefault = 2;

    /**
     * @brief 将指定值对齐至指定基底的整数倍
     * @brief align value to be a new value that is integer multiple of base
     *
     * @param value 原值 ｜ source value
     * @param base 对齐基底 ｜ the base value
     * @return int32 返回对齐后的值 ｜ return the aligned value
     */
    int32 __VARIABLE__ ValueAlign(int32 __VARIABLE__ value, int32 __VARIABLE__ base = ValueAlignBaseDefault);
    /**
     * @brief 将制定值对齐值2的指定次方的整数倍
     * @brief align value to be a new value that is integer multiple of 2^n
     *
     * @param value 原值 ｜ source value
     * @param power 对齐二进制次方 ｜ the pow value
     * @return int32 返回对齐后的值 ｜ return the aligned value
     */
    int32 __VARIABLE__ ValueAlignByPow(int32 __VARIABLE__ value, int32 __VARIABLE__ power = ValueAlignPowerDefault);
}

//
// ################################################################
// 天宇扩展支持部分实现 C++ Only
// Tianyu Extend Supporting Implementation Part C++ Only
// ################################################################
#pragma region implementation_tianyu_type

#define __TEMPLATE_DEF__ template<typename T>
#define __TY_TYPE_DEF__  tianyu::Type<T>
#define __GET_TYPE_DEF__ tianyu::GetType

#ifdef __GNUC__
#include <cxxabi.h>
#endif // !__GNUC__

#include <typeinfo>

__TEMPLATE_DEF__ __TY_TYPE_DEF__ __GET_TYPE_DEF__()
{
    // 通过typeid方法获取默认类型信息
    // get class default info by typeid function
    std::type_info typeInfo = typeid(T);
    ::string sourceName = const_cast<::string>(typeInfo.name());

    // 创建天宇类型实例
    // create Tianyu Type instance
    __TY_TYPE_DEF__ type;
#ifdef __GNUC__
    // 基于GNUC平台的系统
    // if system based on GNUC platform
    int32 status;
    ::string demangled_name = abi::__cxa_demangle(sourceName, NULL, NULL, __VAR_TO_PTR__ status);
    if (0 != status)
    {
        int32 length = tianyu::strlen(sourceName);
        demangled_name = new char[length + 1];
        for (int32 i = 0; i < length; ++i)
            demangled_name[i] = sourceName[i];
        demangled_name[length] = '\0';
    }
#else // !__GNUC__
    // 非GNUC的系统
    // if system based on other system
    int32 length = tianyu::strlen(sourceName);
    ::string demangled_name = new char[length + 1];
    for (int32 i = 0; i < length; ++i)
        demangled_name[i] = sourceName[i];
    demangled_name[length] = '\0';
#endif // !__GNUC__

    // 设置最后的类型名称与ID
    // set target type name and id
    type._Name = demangled_name;
    type._Id = typeInfo.hash_code();

    return type;
}

__TEMPLATE_DEF__ __TY_TYPE_DEF__ __GET_TYPE_DEF__(T& obj)
{
    // 通过typeid方法获取默认类型信息
    // get class default info by typeid function
    std::type_info typeInfo = typeid(T);
    ::string sourceName = const_cast<::string>(typeInfo.name());

    // 创建天宇类型实例
    // create Tianyu Type instance
    __TY_TYPE_DEF__ type((uint64)(__REF_TO_PTR__ obj));
#ifdef __GNUC__
    // 基于GNUC平台的系统
    // if system based on GNUC platform
    int32 status;
    ::string demangled_name = abi::__cxa_demangle(sourceName, NULL, NULL, __VAR_TO_PTR__ status);
    if (0 != status)
    {
        int32 length = tianyu::strlen(sourceName);
        demangled_name = new char[length + 1];
        for (int32 i = 0; i < length; ++i)
            demangled_name[i] = sourceName[i];
        demangled_name[length] = '\0';
}
#else // !__GNUC__
    // 非GNUC的系统
    // if system based on other system
    int32 length = tianyu::strlen(sourceName);
    ::string demangled_name = new char[length + 1];
    for (int32 i = 0; i < length; ++i)
        demangled_name[i] = sourceName[i];
    demangled_name[length] = '\0';
#endif // !__GNUC__

    // 设置最后的类型名称与ID
    // set target type name and id
    type._Name = demangled_name;
    type._Id = typeInfo.hash_code();

    return type;
    }

__TEMPLATE_DEF__::string tianyu::_tianyu_native_cpp_default_to_string(T& obj) noexcept
{
    __TY_TYPE_DEF__ otype = __GET_TYPE_DEF__(obj);
    ::string str = otype._Name;

    otype._Name = ::null;

    return str;
}

//#######################################################################################
// Implementation for Type class
//#######################################################################################

__TEMPLATE_DEF__ bool __TY_TYPE_DEF__::_dummy = false;

__TEMPLATE_DEF__ __construction__ __TY_TYPE_DEF__::Type()
    : _Name(::null),
    _Id(0ULL),
    _InstanceHash(0ULL)
{ }

__TEMPLATE_DEF__ __construction__ __TY_TYPE_DEF__::Type(uint64 instance)
    : _Name(::null),
    _Id(0ULL),
    _InstanceHash(instance)
{ }

__TEMPLATE_DEF__ __cp_construct__ __TY_TYPE_DEF__::Type(const __TY_TYPE_DEF__& other)
    : _Name(::null),
    _Id(other._Id),
    _InstanceHash(other._InstanceHash)
{
    __TY_TYPE_DEF__& copy = const_cast<__TY_TYPE_DEF__&>(other);
    this->_Name = copy._Name;

    copy._Name = ::null;
}

__TEMPLATE_DEF__ __destruction__  __TY_TYPE_DEF__::~Type()
{
    if (::null != this->_Name)
        delete [](this->_Name);
}

__TEMPLATE_DEF__::string __TY_TYPE_DEF__::Name() const
{
    return this->_Name;
}

__TEMPLATE_DEF__ uint64 __TY_TYPE_DEF__::Id()
{
    return this->_Id;
}

__TEMPLATE_DEF__ uint64 __TY_TYPE_DEF__::InstanceHashCode()
{
    return this->_InstanceHash;
}

// to cancel the macro definitions
#undef __TEMPLATE_DEF__
#undef __TY_TYPE_DEF__
#undef __GET_TYPE_DEF__

#pragma endregion

#endif // !__cplusplus

#endif // !__TIANYU_COMMON_NATIVE_CORE_HXX__