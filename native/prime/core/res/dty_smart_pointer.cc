/**
 * @file dty_smart_pointer.cc
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-23
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../pointer.hpp"

#pragma region Tianyu SmartPointer Internal Block

template<typename T>
void dty::SmartPointer<T>::Release()
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

template<typename T>
bool dty::SmartPointer<T>::IsSame(dty::SmartPointer<T>& sp)
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

template<typename T>
dty::SmartPointer<T>::SmartPointer()
    : dty::TianyuObject(),
    _SmartPointerType(dty::SmartPointer<T>::SPType::STRONG), _Pointer(::null), _Size(0)
{ }

template<typename T>
dty::SmartPointer<T>::SmartPointer(T* pointer) : dty::TianyuObject(), _Size()
{
    if (::null == pointer)
        throw dty::except::NullPointerException();

    // create a strong pointer in default.
    this->_SmartPointerType = dty::SmartPointer<T>::SPType::STRONG;
    this->_Pointer = pointer;
    this->_Size = 1;
}

template<typename T>
dty::SmartPointer<T>::SmartPointer(T* pointer, int64 size) : dty::TianyuObject(), _Size()
{
    if (::null == pointer)
        throw dty::except::NullPointerException();

    if (0 >= size)
        throw dty::except::IndexOutOfRangeException();

    // create a strong pointer in default.
    this->_SmartPointerType = dty::SmartPointer<T>::SPType::STRONG;
    this->_Pointer = pointer;
    this->_Size = size;
}

template<typename T>
dty::SmartPointer<T>::SmartPointer(T* pointer, bool weak) : dty::SmartPointer<T>(pointer)
{
    // To reset pointer type only if weak is true
    if (weak)
        this->_SmartPointerType = dty::SmartPointer<T>::SPType::WEAK;
}

template<typename T>
dty::SmartPointer<T>::SmartPointer(T* pointer, int64 size, bool weak) : dty::SmartPointer<T>(pointer, size)
{
    // To reset pointer type only if weak is true
    if (weak)
        this->_SmartPointerType = dty::SmartPointer<T>::SPType::WEAK;
}

template<typename T>
dty::SmartPointer<T>::SmartPointer(const dty::SmartPointer<T>& sp)
// to copy a weak smart pointer by copy constructor only when in __DTY_SMART_POINTER_COPY_WEAK_MODE__
// and in __DTY_UNSAFE_MODE__ mode
#if defined(__DTY_SMART_POINTER_COPY_WEAK_MODE__) && defined(__DTY_UNSAFE_MODE__)
    : _SmartPointerType(dty::SmartPointer<T>::SPType::WEAK),
    _Pointer(sp._Pointer),
    _Size(sp._Size)
{ }
#else

            // safe copy constructor mode is move pointer owner
    : _SmartPointerType(sp._SmartPointerType),
    _Pointer(sp._Pointer),
    _Size(sp._Size)
{
    // move pointer from source pointer only when it is strong pointer
    // weak pointer just to copy
    if (dty::SmartPointer<T>::SPType::STRONG == sp._SmartPointerType)
    {
        // unsafe mode should change const to normal reference
        // --dty-cpp-lint: unsafe-convert-constRef_to_Ref
        dty::SmartPointer<T>& spMove = const_cast<dty::SmartPointer<T> &>(sp);
        spMove._Pointer = ::null;
        spMove._Size = 0;
    }
}
#endif // !defined(__DTY_SMART_POINTER_COPY_WEAK_MODE__) && defined(__DTY_UNSAFE_MODE__)

template<typename T>
dty::SmartPointer<T>::~SmartPointer()
{
    // to release pointer only when the current instance is strong type
    if (dty::SmartPointer<T>::SPType::STRONG == this->_SmartPointerType)
        this->Release();
}

template<typename T>
bool dty::SmartPointer<T>::IsNull()
{
    return ::null == this->_Pointer;
}

template<typename T>
dty::SmartPointer<T>::operator T* ()
{
    return this->_Pointer;
}

template<typename T>
uint64 dty::SmartPointer<T>::operator &()
{
    if (this->IsNull())
        return 0ULL;

    return (uint64)(this->_Pointer);
}

template<typename T>
T& dty::SmartPointer<T>::operator *()
{
    if (::null == this->_Pointer)
        throw dty::except::NullPointerException();

    return __PTR_TO_REF__(this->_Pointer);
}

template<typename T>
T* dty::SmartPointer<T>::operator ->()
{
    if (::null == this->_Pointer)
        throw dty::except::NullPointerException();

    return this->_Pointer;
}

template<typename T>
T* dty::SmartPointer<T>::operator ->() const
{
    if (::null == this->_Pointer)
        throw dty::except::NullPointerException();

    return this->_Pointer;
}

template<typename T>
T& dty::SmartPointer<T>::operator[] (int64 index)
{
    if (::null == this->_Pointer)
        throw dty::except::NullPointerException();

    if (0 > index || this->_Size <= index)
        throw dty::except::ArgumentOutOfRangeException();

    return (this->_Pointer)[index];
}

template<typename T>
T& dty::SmartPointer<T>::operator[] (int64 index) const
{
    if (::null == this->_Pointer)
        throw dty::except::NullPointerException();

    if (0 > index || this->_Size <= index)
        throw dty::except::ArgumentOutOfRangeException();

    return (this->_Pointer)[index];
}

template<typename T>
bool dty::SmartPointer<T>::operator==(dty::SmartPointer<T>& other)
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

template<typename T>
bool dty::SmartPointer<T>::operator!=(dty::SmartPointer<T>& other)
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

template<typename T>
bool dty::SmartPointer<T>::operator==(dty::SmartPointer<T> other)
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

template<typename T>
bool dty::SmartPointer<T>::operator!=(dty::SmartPointer<T> other)
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

template<typename T>
dty::SmartPointer<T> dty::SmartPointer<T>::GetWeak()
{
    return SmartPointer<T>(this->_Pointer, this->_Size, true);
}

template<typename T>
bool dty::SmartPointer<T>::Move(dty::SmartPointer<T>& sp)
{
    if (dty::SmartPointer<T>::SPType::STRONG != sp._SmartPointerType)
        return false;

    if (this->_Pointer == sp._Pointer)
        return false;

    if (dty::SmartPointer<T>::SPType::STRONG == this->_SmartPointerType && ::null != this->_Pointer)
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

template<typename T>
::string dty::SmartPointer<T>::ToString() noexcept
{
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

template<typename T>
uint64 dty::SmartPointer<T>::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

template<typename T>
uint64 dty::SmartPointer<T>::GetHashCode()
{
    return (uint64)(this->_Pointer);
}