/**
 * @file basic-types.h(native/basic-types)
 * @author senyun.yao
 * @section C/C++
 * @brief 用于天宇平台的基本类型定义
 * @brief AiTianyu Basic type definations (C/C++)
 *
 * @version 1.0
 * @date 2023-07-29
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __TIANYU_COMMON_NATIVE_BASIC_TYPES_H__
#define __TIANYU_COMMON_NATIVE_BASIC_TYPES_H__

 //
// ################################################################################################
// ################################################################################################
// ################################################################################################
// 基础信息定义
// Basic Definition in Pure C mode
// ################################################################################################
// ################################################################################################
// ################################################################################################
#pragma region pure c mode macro-def

/** @brief 字符类型有符号数最小值 */
#define __SIGNED_CHAR_MIN__     (-128)
/** @brief 字符类型有符号数最大值 */
#define __SIGNED_CHAR_MAX__     127
/** @brief 字符类型无符号数最小值 */
#define __UNSIGNED_CHAR_MIN__   0
/** @brief 字符类型无符号数最大值 */
#define __UNSIGNED_CHAR_MAX__   0xFF

/** @brief 8位整数类型有符号数最小值 */
#define __SIGNED_INT8_MIN__     (-128)
/** @brief 8位整数类型有符号数最大值 */
#define __SIGNED_INT8_MAX__     127
/** @brief 8位整数类型无符号数最小值 */
#define __UNSIGNED_INT8_MIN__   0
/** @brief 8位整数类型无符号数最大值 */
#define __UNSIGNED_INT8_MAX__   0xFF

/** @brief 16位整数类型有符号数最小值 */
#define __SIGNED_INT16_MIN__    (-32768)
/** @brief 16位整数类型无符号数最小值 */
#define __SIGNED_INT16_MAX__    32767
/** @brief 16位整数类型无符号数最小值 */
#define __UNSIGNED_INT16_MIN__  0
/** @brief 16位整数类型无符号数最大值 */
#define __UNSIGNED_INT16_MAX__  0xFFFF

/** @brief 32位整数类型有符号数最小值 */
#define __SIGNED_INT32_MIN__    (-2147483647 - 1)
/** @brief 32位整数类型无符号数最小值 */
#define __SIGNED_INT32_MAX__    2147483647
/** @brief 32位整数类型无符号数最小值 */
#define __UNSIGNED_INT32_MIN__  0
/** @brief 32位整数类型无符号数最大值 */
#define __UNSIGNED_INT32_MAX__  0xFFFFFFFF

/** @brief 64位整数类型有符号数最小值 */
#define __SIGNED_INT64_MIN__    (-9223372036854775807 - 1)
/** @brief 64位整数类型有符号数最大值 */
#define __SIGNED_INT64_MAX__    9223372036854775807
/** @brief 64位整数类型无符号数最小值 */
#define __UNSIGNED_INT64_MIN__  0
/** @brief 64位整数类型无符号数最大值 */
#define __UNSIGNED_INT64_MAX__  0xFFFFFFFFFFFFFFFF

/** @brief 字符类型位数 */
#define __CHAR_TYPE_BINARY_LENGTH__     8
/** @brief 字节类型位数 */
#define __BYTE_TYPE_BINARY_LENGTH__     8
/** @brief 短整数类型位数 */
#define __SHORT_TYPE_BINARY_LENGTH__    16
/** @brief 整数类型位数 */
#define __INT_TYPE_BINARY_LENGTH__      32
/** @brief 长整数类型位数 */
#define __LONG_TYPE_BINARY_LENGTH__     64
/** @brief 实数（浮点）类型位数 */
#define __FLOAT_TYPE_BINARY_LENGTH__    32
/** @brief 双精度浮点类型位数 */
#define __DOUBLE_TYPE_BINARY_LENGTH__   64
/** @brief 布尔类型位数 */
#define __BOOLEAN_TYPE_BINARY_LENGTH__  8

/** @brief 前向引用 标志 用于标识未定义实体的方法、结构体、类等元素 */
#define __PREDEFINE__
/** @brief 前向引用 标志 用于标识__PREDEFINE__定义的方法、结构体、类等元素的实现 */
#define __PREREALIZ__
/** @brief 默认实现 标志 用于标识可重载函数和拓展类型、数据的默认实现 */
#define __DEFAULT__
/** @brief 构造函数 标志 用于标识类的构造函数（包含模拟OO） */
#define __CONSTRUCTOR__
/** @brief 析构函数 标志 用于标识类的析构函数（包含模拟OO） */
#define __DESTRUCTOR__
/** @brief 复制构造函数 标志 用于标识类的复制构造函数（包含模拟OO） */
#define __COPYSTRUCTOR__
/** @brief 值类型 标志 用于标识以值类型保存、传递的属性、变量和参数 */
#define __VARIABLE__
/** @brief 数组类型 后缀 用于标识当前值类型保存为数组 */
#define __ARRAY__ []
/** @brief 指针类型 标志 用于标识以指针类型保存、传递的属性、变量和参数 */
#define __POINTER__ *
/** @brief 二级指针类型 标志 用于标识以二级指针类型保存、传递的属性、变量和参数  */
#define __DPOINTER__ **
/** @brief 指针→值类型转换 标志 用于标识指针类型到值类型的转换 */
#define __PTR_TO_VAR__ *
/** @brief 值→指针类型转换 标志 用于标识值类型到指针类型的转换 */
#define __VAR_TO_PTR__ &
/** @brief 方法/函数纯输入参数 标志 用于标识方法与函数的参数类型为输入 */
#define __INPUT__
/** @brief 方法/函数纯输出参数 标志 用于标识方法与函数的参数类型为输出 */
#define __OTPUT__
/** @brief 方法/函数输入输出参数 标志 用于标识方法与函数的参数类型既可以进行输入也可作为返回 */
#define __INOUT__
/** @brief 传入实例标志 标志 用于标识方法的传入参数为当前操作的实例（用于C语言的模拟OO） */
#define __INSTE__

#pragma endregion


#ifdef __cplusplus
/** @brief C语言编译模式 标志 用于标识所修饰的元素以C语言的方式进行编译 */
#define __CMODE__ extern "C"
#endif // !__cplusplus

#pragma region redefine for base data type  
#ifdef __cplusplus
__CMODE__
{
#endif // !__cplusplus && __CMODE__ {

    // pure C mode
    // 

/** @brief 无符号字符 数据类型 */
typedef      unsigned char __VARIABLE__ uchar;
// 
/** @brief 有符号字节 数据类型 */
typedef        signed char __VARIABLE__ sbyte;
// 
/** @brief 无符号字节 数据类型 */
typedef      unsigned char __VARIABLE__ byte;
// 
/** @brief 有符号16位整数 数据类型 */
typedef       signed short __VARIABLE__ int16;
// 
/** @brief 无符号16位整数 数据类型 */
typedef     unsigned short __VARIABLE__ uint16;
// 
/** @brief 有符号32位整数 数据类型 */
typedef         signed int __VARIABLE__ int32;
// 
/** @brief 无符号32位整数 数据类型 */
typedef       unsigned int __VARIABLE__ uint32;
// 
/** @brief 有符号64位整数 数据类型 */
typedef   signed long long __VARIABLE__ int64;
// 
/** @brief 无符号64位整数 数据类型 */
typedef unsigned long long __VARIABLE__ uint64;
// 
/** @brief 对象类型（任意类型） 数据类型 指针类型 */
typedef               void __POINTER__  object;
// 
/** @brief 字符串类型 数据类型 指针类型 */
typedef               char __POINTER__  string;

#ifndef __cplusplus
// 
/** @brief 布尔类型（C） 数据类型 */
typedef      unsigned char __VARIABLE__ bool;

/** @brief 布尔类型值 - 真 */
#define TRUE ((bool)1)
    /** @brief 布尔类型值 - 否 */
#define FALSE ((bool)0)
#endif // !__cplusplus }

    /** @brief 定义用于tianyu native的通用id字节长度 */
    __DEFAULT__ const int32 __VARIABLE__ tianyu_native_id_default_size = 16;
#ifdef __cplusplus
}
#endif // !__cplusplus }

#ifndef __cplusplus
/** @brief 指针空值（C） */
#define nullptr ((object)0)
#endif // !__cplusplus }

#pragma endregion

#pragma region cpp definition
#ifdef __cplusplus

// 处理C++版本
// Handle Version of Cpp
#ifndef __TIANYU_DEV_MODE__
#if __cplusplus < 201700L
#define __TIANYU_CPP_ENV_LOW 1
#endif // !__cplusplus < 201700L
#endif // !__TIANYU_DEV_MODE__

/** @brief 公有访问权标志 指示修饰的函数与属性外部可访问 */
#define __PUB__ public:
/** @brief 私有访问权标志 指示修饰的函数与属性外部不可访问 */
#define __PRI__ private:
/** @brief 继承访问权标志 指示修饰的函数与属性子类可访问 */
#define __PRO__ protected:

/** @brief 构造函数返回值替换宏定义 */
#define __construction__
/** @brief 复制构造函数返回值替换宏定义 */
#define __cp_construct__
/** @brief 析构函数返回值替换宏定义 */
#define __destruction__

/** @brief 纯虚函数后缀 */
#define __pure_virtual_fun = 0
/** @brief 纯虚常函数后缀 */
#define __pure_const_fn const = 0
/** @brief 函数重载 */
#define __override_func override
/** @brief 常函数重载 */
#define __override_cfun const override

/** @brief 引用类型 标志 用于标识以引用类型保存、传递的属性、变量和参数 */
#define __REFERENCE__ &
/** @brief 指针引用类型 标志 用于标识以指针引用类型保存、传递的属性、变量和参数 */
#define __PTRREFER__ *&

/** @brief 指针→引用类型转换 标志 用于标识指针类型到引用类型的转换 */
#define __PTR_TO_REF__ *
/** @brief 引用→指针类型转换 标志 用于标识引用类型到指针类型的转换 */
#define __REF_TO_PTR__ &
/** @brief 引用→值类型转换 标志 用于标识引用类型到值类型的转换 */
#define __REF_TO_VAR__
/** @brief 值→引用类型转换 标志 用于标识值类型到引用类型的转换 */
#define __VAR_TO_REF__

// abstract class define
/** @brief 抽象类定义标识符 */
#define abstract
// define interface that is an abstract class
/** @brief 接口类型定义标识符 */
#define _interface abstract class
// define the export lable in internal code
/** @brief 内部导出标签 */
#define _internal_export

// null value for pointer, must to be used by adding "::" ahead (::null)
/** @brief 空指针类型值（使用时必须添加 "::" 作为前缀 - "::null"） */
constexpr auto null = nullptr;

// internal macro definition for tianyu class type
#define _ty_class(cname, ...) class cname : __VA_ARGS__

// Macro Definition for Tianyu Class Type
// Default externed from tianyu::TianyuObject, provide external functions
#define _class(cname, ...) _ty_class(cname, public virtual tianyu::TianyuObject, ##__VA_ARGS__)

// Macro Definition for Tianyu Class final Type
// Default externed from tianyu::TianyuObject, provide external functions
#define _sealed(cname, ...) _ty_class(cname final, public virtual tianyu::TianyuObject, ##__VA_ARGS__)

// Macro Definition for clearly enum define
// enum class
#define _enum enum class

#endif // !__cplusplus
#pragma endregion

#pragma region extension type define

#pragma region pure c

#define __TIANYU_NUMBER_SCALE_ASC 0
#define __TIANYU_NUMBER_SCALE_BIN 1
#define __TIANYU_NUMBER_SCALE_OCT 2
#define __TIANYU_NUMBER_SCALE_DEC 3
#define __TIANYU_NUMBER_SCALE_HEX 4

#pragma endregion

#pragma region cpp
#ifdef __cplusplus
_enum NumberScale : byte
{
    ASC,
    BIN,
    OCT,
    DEC,
    HEX
};
#endif // !__cplusplus
#pragma endregion

#pragma endregion

#endif // !__TIANYU_COMMON_NATIVE_BASIC_TYPES_H__