/**
 * @file dty_collection_filter_result.cc(prime/temp)
 * @author victor.yao
 * @brief Implementation for FilterResult template class
 * @version 0.1
 * @date 2021-12-22
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#include "../iterator.hpp"

template<class T>
dty::collection::FilterResult<T>::FilterResult()
    : dty::TianyuObject(),
    _Elems(::null), _Length(0), _Size(0), _NeedFree(false)
{ }

template<class T>
dty::collection::FilterResult<T>::FilterResult(T* elems, int32 length, int32 size, bool needFree = true)
    : dty::TianyuObject(), _NeedFree(needFree)
{
    if (::null == elems)
        throw dty::except::ArgumentNullException();

    if (0 >= length || length > size)
        throw dty::except::ArgumentOutOfRangeException();

    this->_Elems = elems;
    this->_Length = length;
    this->_Size = size;
}

template<class T>
dty::collection::FilterResult<T>::FilterResult(const dty::collection::FilterResult<T>& fr)
    : dty::TianyuObject(),
    _Elems(fr._Elems), _Length(fr._Length), _Size(fr._Size), _NeedFree(fr._NeedFree)
{ }

template<class T>
dty::collection::FilterResult<T>::~FilterResult()
{
    if (!this->_NeedFree)
        return;

    if (1 == this->_Size)
        delete this->Elems;
    else
        delete [] this->Elems;
}

template<class T>
bool dty::collection::FilterResult<T>::IsEmpty()
{
    return 0 == this->_Length;
}

template<class T>
T& dty::collection::FilterResult<T>::operator[](int32 index)
{
    if (index >= this->_Length)
        throw dty::except::ArgumentOutOfRangeException();

    return this->_Elems[index];
}

template<class T>
::string dty::collection::FilterResult<T>::ToString() noexcept
{
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

template<class T>
uint64 dty::collection::FilterResult<T>::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

template<class T>
uint64 dty::collection::FilterResult<T>::GetHashCode()
{
    return (uint64)(this->_Elems);
}
