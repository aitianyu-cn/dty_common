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
        __PRO__ enum class SPType : int32
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

        __PRO__ T               __POINTER__  _Pointer;
        __PRO__ Property<int64> __VARIABLE__ _Size;

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
         * @brief
         *
         * @param {const SmartPointer<T>&} sp
         * @return {void}
         */
        __PUB__ void   __VARIABLE__ Copy(const SmartPointer<T> __REFERENCE__ sp);
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

        __PUB__ template<class NT> operator NT __REFERENCE__()
        {
            // set a assert to make sure the converted type is correct
            static_assert(
                std::is_base_of<NT, T>::value || std::is_base_of<T, NT>::value,
                "convert type should be child or parent of current type"
                );

            if (::null == this->_Pointer)
                throw dty::except::NullPointerException();

            return dynamic_cast<NT __REFERENCE__>(__PTR_TO_REF__(this->_Pointer));
        }

        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;
    };
}

#pragma region template realization

// ##########################################################
// SmartPointer Implementation
// ##########################################################

#define __TEMPLATE_DEF__ template<typename T>
#define __DTY_SPTR_DEF__ dty::SmartPointer<T>

#pragma region Tianyu SmartPointer Internal Block

__TEMPLATE_DEF__ void __DTY_SPTR_DEF__::Release()
{
    if (::null == this->_Pointer)
        return;

    // 选择是释放单个对象还是多个数组
    // Choose whether the pointer is a single object or an array.
    if (1 == this->_Size)
        delete this->_Pointer;
    else
        delete [] this->_Pointer;
}

__TEMPLATE_DEF__ bool __DTY_SPTR_DEF__::IsSame(__DTY_SPTR_DEF__& sp)
{
    // 检查是否为相同对象
    if (this->_Pointer == sp._Pointer)
        return true;

    // 检查是否为包含的对象
    if (this->operator&() + this->_Size > &sp && this->operator&() < &sp)
        return true;

    if (&sp + sp._Size > this->operator&() && &sp < this->operator&())
        return true;

    return false;
}

#pragma endregion

__TEMPLATE_DEF__ __construction__ __DTY_SPTR_DEF__::SmartPointer() :
    dty::TianyuObject(),
    _SmartPointerType(__DTY_SPTR_DEF__::SPType::STRONG),
    _Pointer(::null),
    _Size(0),
    Size(_Size)
{ }

__TEMPLATE_DEF__ __construction__ __DTY_SPTR_DEF__::SmartPointer(T* pointer) :
    dty::TianyuObject(),
    _Size(),
    Size(_Size)
{
    if (::null == pointer)
        throw dty::except::NullPointerException();

    // create a strong pointer in default.
    this->_SmartPointerType = __DTY_SPTR_DEF__::SPType::STRONG;
    this->_Pointer = pointer;
    this->_Size = 1;
}

__TEMPLATE_DEF__ __construction__ __DTY_SPTR_DEF__::SmartPointer(T* pointer, int64 size) :
    dty::TianyuObject(),
    _Size(),
    Size(_Size)
{
    if (::null == pointer)
        throw dty::except::NullPointerException();

    if (0 >= size)
        throw dty::except::IndexOutOfRangeException();

    // create a strong pointer in default.
    this->_SmartPointerType = __DTY_SPTR_DEF__::SPType::STRONG;
    this->_Pointer = pointer;
    this->_Size = size;
}

__TEMPLATE_DEF__ __construction__ __DTY_SPTR_DEF__::SmartPointer(T* pointer, bool weak) :
    __DTY_SPTR_DEF__(pointer)
{
    // To reset pointer type only if weak is true
    if (weak)
        this->_SmartPointerType = __DTY_SPTR_DEF__::SPType::WEAK;
}

__TEMPLATE_DEF__ __construction__ __DTY_SPTR_DEF__::SmartPointer(T* pointer, int64 size, bool weak) :
    __DTY_SPTR_DEF__(pointer, size)
{
    // To reset pointer type only if weak is true
    if (weak)
        this->_SmartPointerType = __DTY_SPTR_DEF__::SPType::WEAK;
}

__TEMPLATE_DEF__ __cp_construct__ __DTY_SPTR_DEF__::SmartPointer(const __DTY_SPTR_DEF__& sp) :
    // to copy a weak smart pointer by copy constructor only when in __DTY_SMART_POINTER_COPY_WEAK_MODE__
    // and in __DTY_UNSAFE_MODE__ mode
#if defined(__DTY_SMART_POINTER_COPY_WEAK_MODE__) && defined(__DTY_UNSAFE_MODE__)
    _SmartPointerType(__DTY_SPTR_DEF__::SPType::WEAK),
    _Pointer(sp._Pointer),
    _Size(sp._Size),
    Size(_Size)
{ }
#else

    // safe copy constructor mode is move pointer owner
    _SmartPointerType(sp._SmartPointerType),
    _Pointer(sp._Pointer),
    _Size(sp._Size),
    Size(_Size)
{
    // move pointer from source pointer only when it is strong pointer
    // weak pointer just to copy
    if (__DTY_SPTR_DEF__::SPType::STRONG == sp._SmartPointerType)
    {
        // unsafe mode should change const to normal reference
        // --dty-cpp-lint: unsafe-convert-constRef_to_Ref
        __DTY_SPTR_DEF__& spMove = const_cast<__DTY_SPTR_DEF__&>(sp);
        spMove._Pointer = ::null;
        spMove._Size = 0;
    }
}
#endif // !defined(__DTY_SMART_POINTER_COPY_WEAK_MODE__) && defined(__DTY_UNSAFE_MODE__)

__TEMPLATE_DEF__ __destruction__  __DTY_SPTR_DEF__::~SmartPointer()
{
    // to release pointer only when the current instance is strong type
    if (__DTY_SPTR_DEF__::SPType::STRONG == this->_SmartPointerType)
        this->Release();
}

__TEMPLATE_DEF__ bool __DTY_SPTR_DEF__::IsNull()
{
    return ::null == this->_Pointer;
}

__TEMPLATE_DEF__ __DTY_SPTR_DEF__::operator T* ()
{
    return this->_Pointer;
}

__TEMPLATE_DEF__ uint64 __DTY_SPTR_DEF__::operator &()
{
    if (this->IsNull())
        return 0ULL;

    return (uint64)(this->_Pointer);
}

__TEMPLATE_DEF__ T& __DTY_SPTR_DEF__::operator *()
{
    if (::null == this->_Pointer)
        throw dty::except::NullPointerException();

    return __PTR_TO_REF__(this->_Pointer);
}

__TEMPLATE_DEF__ T* __DTY_SPTR_DEF__::operator ->()
{
    if (::null == this->_Pointer)
        throw dty::except::NullPointerException();

    return this->_Pointer;
}

__TEMPLATE_DEF__ T* __DTY_SPTR_DEF__::operator ->() const
{
    if (::null == this->_Pointer)
        throw dty::except::NullPointerException();

    return this->_Pointer;
}

__TEMPLATE_DEF__ T& __DTY_SPTR_DEF__::operator[] (int64 index)
{
    if (::null == this->_Pointer)
        throw dty::except::NullPointerException();

    if (0 > index || this->_Size <= index)
        throw dty::except::ArgumentOutOfRangeException();

    return (this->_Pointer)[index];
}

__TEMPLATE_DEF__ T& __DTY_SPTR_DEF__::operator[] (int64 index) const
{
    if (::null == this->_Pointer)
        throw dty::except::NullPointerException();

    if (0 > index || this->_Size <= index)
        throw dty::except::ArgumentOutOfRangeException();

    return (this->_Pointer)[index];
}

__TEMPLATE_DEF__ bool __DTY_SPTR_DEF__::operator==(__DTY_SPTR_DEF__& other)
{
    try
    {
        return (__PTR_TO_REF__ this->_Pointer) == (__PTR_TO_REF__ other._Pointer);
    }
    catch (...)
    {
        return this->_Pointer == other._Pointer;
    }

}

__TEMPLATE_DEF__ bool __DTY_SPTR_DEF__::operator!=(__DTY_SPTR_DEF__& other)
{
    try
    {
        return (__PTR_TO_REF__ this->_Pointer) != (__PTR_TO_REF__ other._Pointer);
    }
    catch (...)
    {
        return this->_Pointer != other._Pointer;
    }

}

__TEMPLATE_DEF__ bool __DTY_SPTR_DEF__::operator==(T other)
{
    try
    {
        return (__PTR_TO_REF__ this->_Pointer) == other;
    }
    catch (...)
    {
        return this->_Pointer == &other;
    }

}

__TEMPLATE_DEF__ bool __DTY_SPTR_DEF__::operator!=(T other)
{
    try
    {
        return (__PTR_TO_REF__ this->_Pointer) != other;
    }
    catch (...)
    {
        return this->_Pointer != &other;
    }

}

__TEMPLATE_DEF__ __DTY_SPTR_DEF__ __DTY_SPTR_DEF__::GetWeak()
{
    return SmartPointer<T>(this->_Pointer, this->_Size, true);
}

__TEMPLATE_DEF__ void __DTY_SPTR_DEF__::Copy(const __DTY_SPTR_DEF__& sp)
{
    if (this->_Pointer == sp._Pointer)
        return;

    if (__DTY_SPTR_DEF__::SPType::STRONG == this->_SmartPointerType && ::null != this->_Pointer)
    {
        if (1 < this->_Size)
            delete [] this->_Pointer;
        else
            delete this->_Pointer;
    }

    this->_SmartPointerType = sp._SmartPointerType;
    this->_Pointer = sp._Pointer;
    this->_Size = sp._Size;
}

__TEMPLATE_DEF__ bool __DTY_SPTR_DEF__::Move(__DTY_SPTR_DEF__& sp)
{
    if (__DTY_SPTR_DEF__::SPType::STRONG != sp._SmartPointerType)
        return false;

    if (this->_Pointer == sp._Pointer)
        return false;

    if (__DTY_SPTR_DEF__::SPType::STRONG == this->_SmartPointerType && ::null != this->_Pointer)
    {
        if (1 < this->_Size)
            delete [] this->_Pointer;
        else
            delete this->_Pointer;
    }

    this->_SmartPointerType = sp._SmartPointerType;
    this->_Pointer = sp._Pointer;
    this->_Size = sp._Size;

    sp._Pointer = ::null;
    sp._Size = 0;

    return true;
}

__TEMPLATE_DEF__::string __DTY_SPTR_DEF__::ToString() noexcept
{
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

__TEMPLATE_DEF__ uint64 __DTY_SPTR_DEF__::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

__TEMPLATE_DEF__ uint64 __DTY_SPTR_DEF__::GetHashCode()
{
    return (uint64)(this->_Pointer);
}

// to cancel the macro definitions
#undef __TEMPLATE_DEF__
#undef __DTY_SPTR_DEF__

#pragma endregion

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