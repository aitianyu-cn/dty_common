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
// ################################################################
// 多语言部分
// Multi-language Part
// ################################################################
// 引用静态多语言文件
// Includes static Multi-Language file
#include "./res/i18n/language.h"
// 字符串替换宏函数
// message string convert macro-function
#define __TY_CORE_MSG_CONVERT(msg) msg
// ################################################################
// 多语言部分结束
// End
// ################################################################
#pragma endregion

#pragma region Toggle_Part
// 引用静态核心功能描述文件
// Includes static Feature Toggle file
#include "./res/feature/feature_core.h"
#pragma endregion

#pragma region Cross_platform_Part
//
// ################################################################
// 平台定义部分
// Cross-platform Part
// ################################################################
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
// ################################################################
// 平台定义部分结束
// End
// ################################################################
#pragma endregion

#pragma region basic_type_def
//
// ################################################################
// 基本类型定义部分
// Basic type defs Part
// ################################################################
// 引入基本类型定义
// Includes Basic types Definition
#include "./basic-types.h"

// 基本类型定义中的异常处理
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
     *
     * @param str 指定的字符串
     * @return int32 返回字符串长度 （字符串为空时返回0）
     */
    int32    __VARIABLE__ strlen(const ::string __VARIABLE__ str);
    /**
     * @brief 获取一个值，该值指示指定两个字符串的大小关系
     *
     * @param s1 字符串1
     * @param s2 字符串2
     * @param ignoreCase 指示是否忽略大小写检查（默认检查大小写）
     * @return int32 返回 0 - 字符串1和字符串2相等 | 1 - 字符串1大于字符串2 | -1 - 字符串1小于字符串2
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
    // general data type class
    // get a name and type id to indicate a specified type
    __PREDEFINE__ template<typename T> class Type;

    __PREDEFINE__ template<typename T> Type<T>  __VARIABLE__ GetType();
    __PREDEFINE__ template<typename T> Type<T>  __VARIABLE__ GetType(T __REFERENCE__ obj);
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
    __PREDEFINE__ template<typename T> ::string __VARIABLE__ _tianyu_native_cpp_default_to_string(T __REFERENCE__ obj) noexcept;

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

        __PRI__ __construction__ Type();
        __PRI__ __construction__ Type(uint64        __VARIABLE__  instance);
        __PUB__ __cp_construct__ Type(const Type<T> __REFERENCE__ other);
        __PUB__ __destruction__  ~Type();

        __PUB__::string __VARIABLE__ Name() const;
        __PUB__ uint64  __VARIABLE__ Id();
        __PUB__ uint64  __VARIABLE__ InstanceHashCode();

        friend Type<T>  __VARIABLE__ GetType<T>();
        friend Type<T>  __VARIABLE__ GetType<T>(T __REFERENCE__ obj);
        friend ::string __VARIABLE__ _tianyu_native_cpp_default_to_string<T>(T __REFERENCE__ obj) noexcept;
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
        __PUB__ virtual __destruction__ ~IToString() { }

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept __pure_virtual_fun;
    };

    // Tianyu Object 
    // this is a basic object type for Tianyu Native and all of the sub type in Tianyu Native
    // this is a hierarchy root for Data Type in Tianyu Native
    // Tianyu Object provides the basic and generic interfaces.
    abstract class TianyuObject : public virtual tianyu::IToString
    {
        __PRO__         __construction__ TianyuObject();
        __PUB__ virtual __destruction__  ~TianyuObject() __override_func;

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId();
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode();

        __PUB__ virtual bool __VARIABLE__ IsNull();
        __PUB__ virtual bool __VARIABLE__ Equals(TianyuObject __REFERENCE__ obj);
        __PUB__ virtual bool __VARIABLE__ operator==(TianyuObject __REFERENCE__ obj);

        __PUB__ static  bool __VARIABLE__ IsNull(TianyuObject __REFERENCE__ obj);
    };

    constexpr int32 ValueAlignBaseDefault = 2;
    constexpr int32 ValueAlignPowerDefault = 2;

    /**
     * @brief align value to be a new value that is integer multiple of base
     *
     * @param value {int32} source value
     * @param base {int32} the base value
     * @return int32 {int32} return the aligned value
     */
    int32 __VARIABLE__ ValueAlign(int32 __VARIABLE__ value, int32 __VARIABLE__ base = ValueAlignBaseDefault);
    /**
     * @brief align value to be a new value that is integer multiple of 2^n
     *
     * @param value {int32} source value
     * @param power {int32} the pow value
     * @return int32 {int32} return the aligned value
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
    ::string sourceName = const_cast<::string>(typeid(T).name());

    __TY_TYPE_DEF__ type;
#ifdef __GNUC__
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
    int32 length = tianyu::strlen(sourceName);
    ::string demangled_name = new char[length + 1];
    for (int32 i = 0; i < length; ++i)
        demangled_name[i] = sourceName[i];
    demangled_name[length] = '\0';
#endif // !__GNUC__
    type._Name = demangled_name;
    type._Id = typeid(T).hash_code();

    return type;
}

__TEMPLATE_DEF__ __TY_TYPE_DEF__ __GET_TYPE_DEF__(T& obj)
{
    ::string sourceName = const_cast<::string>(typeid(T).name());

    __TY_TYPE_DEF__ type((uint64)(__REF_TO_PTR__ obj));
#ifdef __GNUC__
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
    int32 length = tianyu::strlen(sourceName);
    ::string demangled_name = new char[length + 1];
    for (int32 i = 0; i < length; ++i)
        demangled_name[i] = sourceName[i];
    demangled_name[length] = '\0';
#endif // !__GNUC__
    type._Name = demangled_name;
    type._Id = typeid(T).hash_code();

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