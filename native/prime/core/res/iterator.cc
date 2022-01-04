/**
 * @file iterator.cc
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../iterator.hpp"

#define __TEMPLATE_DEF__ template<typename T>

#define __F_RESULT_DEF__ dty::collection::FilterResult<T>
#define __II_ENTIT_DEF__ dty::collection::IIteratorEntity<T>
#define __ITERATOR_DEF__ dty::collection::Iterator<T>
#define __IT_ENTIT_DEF__ dty::collection::IteratorEntity<T>

 //
//##########################################################################
// Implementation for FilterResult class
//##########################################################################
__TEMPLATE_DEF__ __construction__ __F_RESULT_DEF__::FilterResult() :
    dty::TianyuObject(),
    _Elems(::null),
    _Length(0),
    _Size(0),
    _NeedFree(false)
{ }

__TEMPLATE_DEF__ __construction__ __F_RESULT_DEF__::FilterResult(T* elems, int32 length, bool needFree) :
    dty::TianyuObject(),
    _NeedFree(needFree)
{
    if (::null == elems)
        throw dty::except::ArgumentNullException();

    if (0 >= length)
        throw dty::except::ArgumentOutOfRangeException();

    this->_Elems = elems;
    this->_Length = length;
    this->_Size = length;
}

__TEMPLATE_DEF__ __construction__ __F_RESULT_DEF__::FilterResult(T* elems, int32 length, int32 size, bool needFree) :
    dty::TianyuObject(),
    _NeedFree(needFree)
{
    if (::null == elems)
        throw dty::except::ArgumentNullException();

    if (0 >= length || length > size)
        throw dty::except::ArgumentOutOfRangeException();

    this->_Elems = elems;
    this->_Length = length;
    this->_Size = size;
}

__TEMPLATE_DEF__ __cp_construct__ __F_RESULT_DEF__::FilterResult(const __F_RESULT_DEF__& fr)
    : dty::TianyuObject(),
    _Elems(fr._Elems),
    _Length(fr._Length),
    _Size(fr._Size),
    _NeedFree(fr._NeedFree)
{ }

__TEMPLATE_DEF__ __destruction__  __F_RESULT_DEF__::~FilterResult()
{
    if (!this->_NeedFree)
        return;

    delete [] this->_Elems;
}

__TEMPLATE_DEF__ bool __F_RESULT_DEF__::IsEmpty()
{
    return 0 == this->_Length;
}

__TEMPLATE_DEF__ bool __F_RESULT_DEF__::IsNull()
{
    return ::null == this->_Elems;
}

__TEMPLATE_DEF__ T& __F_RESULT_DEF__::operator[](int32 index)
{
    if (index >= this->_Length)
        throw dty::except::ArgumentOutOfRangeException();

    return this->_Elems[index];
}

__TEMPLATE_DEF__::string __F_RESULT_DEF__::ToString() noexcept
{
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

__TEMPLATE_DEF__ uint64 __F_RESULT_DEF__::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

__TEMPLATE_DEF__ uint64 __F_RESULT_DEF__::GetHashCode()
{
    return (uint64)(this->_Elems);
}


//##########################################################################
// Implementation for IIteratorEntity interface
//##########################################################################
__TEMPLATE_DEF__ __construction__ __II_ENTIT_DEF__::IIteratorEntity(int32 size) :
    dty::TianyuObject(),
    _Size(size),
    Size(_Size)
{ }

__TEMPLATE_DEF__ __cp_construct__ __II_ENTIT_DEF__::IIteratorEntity(__II_ENTIT_DEF__& ite) :
    dty::TianyuObject(),
    _Size(ite._Size),
    Size(_Size)
{ }

__TEMPLATE_DEF__ __destruction__  __II_ENTIT_DEF__::~IIteratorEntity()
{ }

__TEMPLATE_DEF__::string __II_ENTIT_DEF__::ToString() noexcept
{
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

__TEMPLATE_DEF__ uint64 __II_ENTIT_DEF__::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

//##########################################################################
// Implementation for Iterator class
//##########################################################################
__TEMPLATE_DEF__ __construction__ __ITERATOR_DEF__::Iterator(__II_ENTIT_DEF__& entity) :
    dty::TianyuObject(),
    _Entity(entity),
    _CurrentIndex(0)
{ }

__TEMPLATE_DEF__ __construction__ __ITERATOR_DEF__::Iterator(const __ITERATOR_DEF__& iterator) :
    dty::TianyuObject(),
    _Entity(iterator._Entity),
    _CurrentIndex(iterator._CurrentIndex)
{ }

__TEMPLATE_DEF__ __destruction__  __ITERATOR_DEF__::~Iterator()
{ }

__TEMPLATE_DEF__ void __ITERATOR_DEF__::Reset()
{
    this->_CurrentIndex = 0;
}

__TEMPLATE_DEF__ dty::SmartPointer<T> __ITERATOR_DEF__::Current()
{
    return this->_Entity.Get(this->_CurrentIndex);
}

__TEMPLATE_DEF__ dty::SmartPointer<T> __ITERATOR_DEF__::Next()
{
    // anyway, move to the next
    this->_CurrentIndex = this->_CurrentIndex + 1;

    return this->_Entity.Get(this->_CurrentIndex);
}

__TEMPLATE_DEF__ dty::SmartPointer<T> __ITERATOR_DEF__::End()
{
    return this->_Entity.End();
}

__TEMPLATE_DEF__ void __ITERATOR_DEF__::ForEach(__ITERATOR_DEF__::ItemMapDelegate delegate)
{
    this->_Entity.ForEach(delegate);
}

__TEMPLATE_DEF__ T* __ITERATOR_DEF__::Some(__ITERATOR_DEF__::ItemChkDelegate delegate)
{
    return this->_Entity.Some(delegate);
}

__TEMPLATE_DEF__ dty::collection::FilterResult<T> __ITERATOR_DEF__::Filter(__ITERATOR_DEF__::ItemChkDelegate delegate)
{
    return this->_Entity.Filter(delegate);
}

__TEMPLATE_DEF__ dty::collection::FilterResult<T> __ITERATOR_DEF__::Never(__ITERATOR_DEF__::ItemChkDelegate delegate)
{
    return this->_Entity.Never(delegate);
}

__TEMPLATE_DEF__ T* __ITERATOR_DEF__::Find(__ITERATOR_DEF__::ItemChkDelegate delegate)
{
    return this->_Entity.Find(delegate);
}

__TEMPLATE_DEF__ int32 __ITERATOR_DEF__::FindIndex(__ITERATOR_DEF__::ItemChkDelegate delegate)
{
    return this->_Entity.FindIndex(delegate);
}

__TEMPLATE_DEF__::string __ITERATOR_DEF__::ToString() noexcept
{
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

__TEMPLATE_DEF__ uint64 __ITERATOR_DEF__::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

__TEMPLATE_DEF__ uint64 __ITERATOR_DEF__::GetHashCode()
{
    return this->_Entity.GetHashCode();
}


//##########################################################################
// Implementation for IteratorEntity class
//##########################################################################
__TEMPLATE_DEF__ __construction__ __IT_ENTIT_DEF__::IteratorEntity(T* pointer, int32 size, bool needFree) :
    dty::TianyuObject(),
    dty::collection::IIteratorEntity<T>(size),
    _Pointer(pointer),
    _Reference(::null),
    _NeedFree(needFree)
{
    if (::null == pointer && 0 != size)
        throw dty::except::ArgumentNullException();

    if (0 > size)
        throw dty::except::ArgumentOutOfRangeException();

    if (this->_NeedFree && 0 < size)
        this->_Reference = new int32(1);
}

__TEMPLATE_DEF__ __cp_construct__ __IT_ENTIT_DEF__::IteratorEntity(const __IT_ENTIT_DEF__& it) :
    dty::TianyuObject(),
    dty::collection::IIteratorEntity<T>(it),
    _Pointer(it._Pointer),
    _NeedFree(it._NeedFree),
    _Reference(it._Reference)
{
    if (this->_NeedFree && 0 < it._Size)
        (__PTR_TO_VAR__(this->_Reference)) += 1;
}

__TEMPLATE_DEF__ __destruction__  __IT_ENTIT_DEF__::~IteratorEntity()
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

__TEMPLATE_DEF__ dty::SmartPointer<T> __IT_ENTIT_DEF__::Get(int32 index)
{
    if (0 == this->_Size)
        return dty::SmartPointer<T>();

    if (0 > index)
        index = 0;
    else if (index >= this->_Size)
        index = this->_Size - 1;

    return dty::SmartPointer<T>((this->_Pointer) + index, 1, true /* weak pointer */);
}

__TEMPLATE_DEF__ dty::SmartPointer<T> __IT_ENTIT_DEF__::End()
{
    if (0 == this->_Size)
        return dty::SmartPointer<T>();

    return dty::SmartPointer<T>((this->_Pointer) + this->_Size - 1, 1, true /* weak pointer */);
}

__TEMPLATE_DEF__ void __IT_ENTIT_DEF__::ForEach(__IT_ENTIT_DEF__::ItemMapDelegate delegate)
{
    if (0 == this->Size())
        return;

    for (int32 i = 0; i < this->_Size; ++i)
        delegate(this->_Pointer[i]);
}

__TEMPLATE_DEF__ T* __IT_ENTIT_DEF__::Some(__IT_ENTIT_DEF__::ItemChkDelegate delegate)
{
    for (int32 i = 0; i < this->_Size; ++i)
        if (!delegate(this->_Pointer[i]))
            return (this->_Pointer) + i;

    return ::null;
}

__TEMPLATE_DEF__ __F_RESULT_DEF__ __IT_ENTIT_DEF__::Filter(__IT_ENTIT_DEF__::ItemChkDelegate delegate)
{
    if (0 == this->Size())
        return __F_RESULT_DEF__();

    int32* filters = new int32[this->_Size];
    int32 filterCount = 0;

    for (int32 i = 0; i < this->_Size; ++i)
        if (delegate(this->_Pointer[i]))
            filters[filterCount++] = i;

    if (0 == filterCount)
    {
        delete []filters;
        return __F_RESULT_DEF__();
    }

    T* results = new T[filterCount];
    for (int32 i = 0; i < filterCount; ++i)
        T[i] = this->_Pointer[filters[i]];

    delete []filters;
    return __F_RESULT_DEF__(results, filterCount);
}

__TEMPLATE_DEF__ __F_RESULT_DEF__ __IT_ENTIT_DEF__::Never(__IT_ENTIT_DEF__::ItemChkDelegate delegate)
{
    if (0 == this->Size())
        return __F_RESULT_DEF__();

    int32* filters = new int32[this->_Size];
    int32 filterCount = 0;

    for (int32 i = 0; i < this->_Size; ++i)
        if (!delegate(this->_Pointer[i]))
            filters[filterCount++] = i;

    if (0 == filterCount)
    {
        delete []filters;
        return __F_RESULT_DEF__();
    }

    T* results = new T[filterCount];
    for (int32 i = 0; i < filterCount; ++i)
        T[i] = this->_Pointer[filters[i]];

    delete []filters;
    return __F_RESULT_DEF__(results, filterCount);
}

__TEMPLATE_DEF__ T* __IT_ENTIT_DEF__::Find(__IT_ENTIT_DEF__::ItemChkDelegate delegate)
{
    for (int32 i = 0; i < this->_Size; ++i)
        if (delegate(this->_Pointer[i]))
            return (this->_Pointer) + i;

    return ::null;
}

__TEMPLATE_DEF__ int32 __IT_ENTIT_DEF__::FindIndex(__IT_ENTIT_DEF__::ItemChkDelegate delegate)
{
    for (int32 i = 0; i < this->_Size; ++i)
        if (delegate(this->_Pointer[i]))
            return i;

    return -1;
}

__TEMPLATE_DEF__::string __IT_ENTIT_DEF__::ToString() noexcept
{
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

__TEMPLATE_DEF__ uint64 __IT_ENTIT_DEF__::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

__TEMPLATE_DEF__ uint64 __IT_ENTIT_DEF__::GetHashCode()
{
    return (uint64)(this);
}

// to cancel the macro definitions
#undef __TEMPLATE_DEF__

#undef __F_RESULT_DEF__
#undef __II_ENTIT_DEF__
#undef __ITERATOR_DEF__
#undef __IT_ENTIT_DEF__