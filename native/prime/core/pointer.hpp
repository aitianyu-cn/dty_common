/**
 * @file pointer.hpp(prime/core)
 * @author senyun.yao
 * @brief 用于天宇平台的智能指针，提供较为安全的指针类型操作
 * @brief Smart Pointer designed for Tianyu Platform to provide little more safe pointer operations.
 * @version 0.1
 * @date 2021-11-18
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_CORE_POINTER_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_CORE_POINTER_H_PLUS_PLUS__

#include "./internal.h"
#include "./error.hpp"
#include "./property.hpp"

namespace dty
{
    template<typename T>
    class SmartPointer : public virtual dty::TianyuObject
    {
#pragma region Tianyu SmartPointer Internal Block
        //
        // 智能指针类型：强指针与弱指针
        // SmartPointer Type: Strong Pointer and Weak Pointer
        // 强指针拥有对象指针的实际使用权，弱指针只是对象指针的副本，不保证访问的可靠性
        // Strong Pointers have the actual use of object Pointers, while weak Pointers 
        // are only copies of object Pointers and do not guarantee access reliability。
        //
        __PRO__ enum SPType : int32
        {
            STRONG = 0,
            WEAK = 1
        };

        __PRI__ SPType __VARIABLE__ _SmartPointerType;

        /**
         * @brief 内部方法：释放对象的指针引用 
         * @brief Internal Function: Release object pointer reference
         */
        __PRI__ void __VARIABLE__ Release();
        /**
         * @brief 内部方法：检测指定对象与当前对象是否为同一个对象
         * @brief Internal Function: Check whether the specified object is same with current instance.
         *
         * @param {SmartPointer<T>&} sp Specified Compared Object
         * @return {bool} return true if they are same object or one is child of another one.
         */
        __PRI__ bool __VARIABLE__ IsSame(SmartPointer<T> __REFERENCE__ sp);
#pragma endregion

        __PRI__ T               __POINTER__  _Pointer;
        __PRI__ Property<int64> __VARIABLE__ _Size;

        /**
         * @brief 获取一个值指示当前指针实例的大小
         * @brief Get a int64 indicates the current pointer size
         *
         * @return {int64} return pointer size
         */
        __PUB__ IPropertyGetter<int64> __REFERENCE__ Size;

        /**
         * @brief 创建一个空指针对象
         * @brief Create a ::null pointer
         */
        __PUB__ explicit SmartPointer();
        /**
         * @brief 由指定的指针创建智能指针对象
         * @brief Create a smart pointer from a specified pointer
         *
         * @exception dty::except::NullPointerException: throw an exception if the specified pointer is ::null
         */
        __PUB__ explicit SmartPointer(T __POINTER__ pointer);
        /**
         * @brief 由指定的指针和对象长度创建智能指针对象
         * @brief Create a smart pointer from a specified pointer and object size
         *
         * @exception dty::except::NullPointerException: throw an exception if the specified pointer is ::null
         * @exception dty::except::IndexOutOfRangeException: throw an exception if the specified pointer size is not more than zero.
         */
        __PUB__ explicit SmartPointer(T __POINTER__ pointer, int64 __VARIABLE__ size);
        /**
         * @brief 由指定的指针创建智能指针对象，并指定指针类型
         * @brief Create a smart pointer from a specified pointer and set the default pointer type
         *
         * @exception dty::except::NullPointerException: throw an exception if the specified pointer is ::null
         */
        __PUB__ explicit SmartPointer(T __POINTER__ pointer, bool __VARIABLE__ weak);
        /**
         * @brief 由指定的指针和对象长度创建智能指针对象，并指定指针类型
         * @brief Create a smart pointer from a specified pointer and object size and set the default pointer type
         *
         * @exception dty::except::NullPointerException: throw an exception if the specified pointer is ::null
         * @exception dty::except::IndexOutOfRangeException: throw an exception if the specified pointer size is not more than zero.
         */
        __PUB__ explicit SmartPointer(T __POINTER__ pointer, int64 __VARIABLE__ size, bool __VARIABLE__ weak);
        /**
         * @brief 从指定的智能指针对象创建新的智能指针对象
         * @brief Create a new smart pointer object from a specified smart pointer
         *
         * @param {const SmartPointer<T>&} sp specified source smart pointer.
         */
        __PUB__          SmartPointer(const SmartPointer<T> __REFERENCE__ sp);

        /**
         * @brief 析构函数 
         * @brief disconstructor
         */
        __PUB__ virtual  ~SmartPointer();

        /**
         * @brief 获取一个bool值指示当前实例是否为空指针
         * @brief Get a bool value indicates whether the current pointer is ::null
         *
         * @return {bool} return true if current pointer is ::null, other wise is false
         */
        __PUB__ virtual bool __VARIABLE__ IsNull() override;
        /**
         * @brief
         * @brief
         *
         * @return {SmartPointer<T>}
         */
        __PUB__ SmartPointer<T> __VARIABLE__ GetWeak();
        /**
         * @brief
         * @brief
         *
         * @param {SmartPointer<T>&} sp
         * @return {bool}
         */
        __PUB__ bool   __VARIABLE__ Move(SmartPointer<T> __REFERENCE__ sp);
        /**
         * @brief 运算符 & 重载：获取当前指针的绝对地址
         * @brief __override_func operator &: Get the absoult address of current pointer.
         *
         * @return {uint64} return current address
         */
        __PUB__ uint64 __VARIABLE__  operator __REFERENCE__();
        /**
         * @brief
         * @brief
         *
         * @return {T&}
         */
        __PUB__ T      __REFERENCE__ operator __POINTER__();

        __PUB__                      operator T __POINTER__();
        /**
         * @brief
         * @brief
         *
         * @return {T*}
         */
        __PUB__ T      __POINTER__   operator ->();
        /**
         * @brief
         * @brief
         *
         * @return {T*}
         */
        __PUB__ T      __POINTER__   operator ->() const;
        /**
         * @brief
         * @brief
         *
         * @param {int64} index:
         * @return {T&}
         */
        __PUB__ T      __REFERENCE__ operator[] (int64 __VARIABLE__ index);
        /**
         * @brief
         * @brief
         *
         * @param {int64} index:
         * @return {T&}
         */
        __PUB__ T      __REFERENCE__ operator[] (int64 __VARIABLE__ index) const;
        /**
         * @brief
         * @brief
         *
         * @param {SmartPointer<T>&} other
         * @return {bool}
         */
        __PUB__ bool __VARIABLE__ operator ==(SmartPointer<T> __REFERENCE__ other);
        /**
         * @brief
         * @brief
         *
         * @param {SmartPointer<T>&} other
         * @return {bool}
         */
        __PUB__ bool __VARIABLE__ operator !=(SmartPointer<T> __REFERENCE__ other);
        /**
         * @brief
         * @brief
         *
         * @param {T} other
         * @return {bool}
         */
        __PUB__ bool __VARIABLE__ operator ==(T __VARIABLE__ other);
        /**
         * @brief
         * @brief
         *
         * @param {T} other
         * @return {bool}
         */
        __PUB__ bool __VARIABLE__ operator !=(T __VARIABLE__ other);

        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;
    };
}

// import the implementation from res
#include "./res/pointer.cc"

namespace dty
{
#pragma region Pre-define default safe pointer
    using byte_ptr = SmartPointer<byte>;
    using bool_ptr = SmartPointer<bool>;
    using short_ptr = SmartPointer<int16>;
    using int_ptr = SmartPointer<int32>;
    using long_ptr = SmartPointer<int64>;
    using float_ptr = SmartPointer<float>;
    using double_ptr = SmartPointer<double>;
    using string_sp = SmartPointer<char>;
#pragma endregion
}

#endif // !__DTY_COMMON_NATIVE_PRIME_CORE_POINTER_H_PLUS_PLUS__