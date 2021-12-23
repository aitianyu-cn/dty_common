/**
 * @file dty_collection_iterator_entity.cc(prime/temp)
 * @author victor.yao
 * @brief Implementation for Default Iterator Entity template class
 * @version 0.1
 * @date 2021-12-22
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#include "../iterator.hpp"

template<class T>
dty::collection::IteratorEntity<T>::IteratorEntity(T* pointer, int32 size, bool needFree = false)
    : dty::TianyuObject(), _Pointer(pointer), _Reference(::null), _Current(0), _NeedFree(needFree)
{
    if (::null == pointer && 0 != size)
        throw dty::except::ArgumentNullException();

    if (0 > size)
        throw dty::except::ArgumentOutOfRangeException();

    if (this->_NeedFree && 0 < size)
        this->_Reference = new int32(1);
}

template<class T>
dty::collection::IteratorEntity<T>::IteratorEntity(const dty::collection::IteratorEntity<T>& it)
    :dty::TianyuObject(),
    _Pointer(it._Pointer), _Size(it._Size), _NeedFree(it._NeedFree), _Reference(it._Reference)
{
    if (this->_NeedFree && 0 < it._Size)
        (__PTR_TO_VAR__(this->_Reference)) += 1;
}

template<class T>
dty::collection::IteratorEntity<T>::~IteratorEntity()
{
    if (!this->_NeedFree || 0 == this->_Size)
        return;

    if (1 == (__PTR_TO_VAR__(this->_Reference)))
    {
        delete [] this->_Pointer;
        delete this->_Reference;
    }
    else
        (__PTR_TO_VAR__(this->_Reference)) -= 1;
}

template<class T>
dty::SmartPointer<T> dty::collection::IteratorEntity<T>::Get(int32 index)
{
    if (0 == this->_Size)
        return dty::SmartPointer<T>();

    if (index >= this->_Size)
        index = this->_Size - 1;

    return dty::SmartPointer<T>((this->_Pointer) + index, 1, true /*weak pointer*/);
}

template<class T>
dty::SmartPointer<T> dty::collection::IteratorEntity<T>::End()
{
    if (0 == this->_Size)
        return dty::SmartPointer<T>();

    return dty::SmartPointer<T>((this->_Pointer) + this->_Size - 1, 1, true /*weak pointer*/);
}

template<class T>
void dty::collection::IteratorEntity<T>::ForEach(dty::collection::IteratorEntity<T>::ItemMapDelegate delegate)
{
    if (0 == this->Size())
        return;

    for (int32 i = 0; i < this->_Size; ++i)
        delegate(this->_Pointer[i]);
}

template<class T>
T* dty::collection::IteratorEntity<T>::Some(dty::collection::IteratorEntity<T>::ItemChkDelegate delegate)
{
    for (int32 i = 0; i < this->_Size; ++i)
        if (!delegate(this->_Pointer[i]))
            return (this->_Pointer) + i;

    return ::null;
}

template<class T>
dty::collection::FilterResult<T> dty::collection::IteratorEntity<T>::Filter(dty::collection::IteratorEntity<T>::ItemChkDelegate delegate)
{
    if (0 == this->Size())
        return dty::collection::FilterResult<T>();

    int32* filters = new int32[this->_Size];
    int32 filterCount = 0;

    for (int32 i = 0; i < this->_Size; ++i)
        if (delegate(this->_Pointer[i]))
            filters[filterCount++] = i;

    if (0 == filterCount)
    {
        delete []filters;
        return dty::collection::FilterResult<T>();
    }

    T* results = new T[filterCount];
    for (int32 i = 0; i < filterCount; ++i)
        T[i] = this->_Pointer[filters[i]];

    delete []filters;
    return dty::collection::FilterResult<T>(results, filterCount);
}

template<class T>
dty::collection::FilterResult<T> dty::collection::IteratorEntity<T>::Every(dty::collection::IteratorEntity<T>::ItemChkDelegate delegate)
{
    if (0 == this->Size())
        return dty::collection::FilterResult<T>();

    int32* filters = new int32[this->_Size];
    int32 filterCount = 0;

    for (int32 i = 0; i < this->_Size; ++i)
        if (!delegate(this->_Pointer[i]))
            filters[filterCount++] = i;

    if (0 == filterCount)
    {
        delete []filters;
        return dty::collection::FilterResult<T>();
    }

    T* results = new T[filterCount];
    for (int32 i = 0; i < filterCount; ++i)
        T[i] = this->_Pointer[filters[i]];

    delete []filters;
    return dty::collection::FilterResult<T>(results, filterCount);
}

template<class T>
T* dty::collection::IteratorEntity<T>::Find(dty::collection::IteratorEntity<T>::ItemChkDelegate delegate)
{
    for (int32 i = 0; i < this->_Size; ++i)
        if (delegate(this->_Pointer[i]))
            return (this->_Pointer) + i;

    return ::null;
}

template<class T>
int32 dty::collection::IteratorEntity<T>::FindIndex(dty::collection::IteratorEntity<T>::ItemChkDelegate delegate)
{
    for (int32 i = 0; i < this->_Size; ++i)
        if (delegate(this->_Pointer[i]))
            return i;

    return -1;
}

template<class T>
::string dty::collection::IteratorEntity<T>::ToString() noexcept
{
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

template<class T>
uint64 dty::collection::IteratorEntity<T>::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

template<class T>
uint64 dty::collection::IteratorEntity<T>::GetHashCode()
{
    return (uint64)(this);
}