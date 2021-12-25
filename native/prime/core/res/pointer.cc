/**
 * @file pointer.cc
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-23
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../pointer.hpp"

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
    _Size(0)
{ }

__TEMPLATE_DEF__ __construction__ __DTY_SPTR_DEF__::SmartPointer(T* pointer) :
    dty::TianyuObject(),
    _Size()
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
    _Size()
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
    _Size(sp._Size)
{ }
#else

    // safe copy constructor mode is move pointer owner
    _SmartPointerType(sp._SmartPointerType),
    _Pointer(sp._Pointer),
    _Size(sp._Size)
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
    catch (std::exception)
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
    catch (std::exception)
    {
        return this->_Pointer != other._Pointer;
    }

}

__TEMPLATE_DEF__ bool __DTY_SPTR_DEF__::operator==(__DTY_SPTR_DEF__ other)
{
    try
    {
        return (__PTR_TO_REF__ this->_Pointer) == (__PTR_TO_REF__ other._Pointer);
    }
    catch (std::exception)
    {
        return this->_Pointer == other._Pointer;
    }

}

__TEMPLATE_DEF__ bool __DTY_SPTR_DEF__::operator!=(__DTY_SPTR_DEF__ other)
{
    try
    {
        return (__PTR_TO_REF__ this->_Pointer) != (__PTR_TO_REF__ other._Pointer);
    }
    catch (std::exception)
    {
        return this->_Pointer != other._Pointer;
    }

}

__TEMPLATE_DEF__ __DTY_SPTR_DEF__ __DTY_SPTR_DEF__::GetWeak()
{
    return SmartPointer<T>(this->_Pointer, this->_Size, true);
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