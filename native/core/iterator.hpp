/**
 * @file iterator.hpp(core)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-19
 * @date 2023-07-31
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#pragma once
#ifndef __TIANYU_COMMON_NATIVE_CORE_ITERATOR_H_PLUS_PLUS__
#define __TIANYU_COMMON_NATIVE_CORE_ITERATOR_H_PLUS_PLUS__

#include "./internal.h"
#include "./property.hpp"
#include "./pointer.hpp"

namespace tianyu::collection
{
    template<class Elem>
    class FilterResult final : public virtual tianyu::TianyuObject
    {
        __PRI__ Elem  __POINTER__  _Elems;

        __PRI__ Property<int32> __VARIABLE__ _Length;
        __PRI__ Property<int32> __VARIABLE__ _Size;
        __PRI__ Property<bool>  __VARIABLE__ _NeedFree;

        __PUB__ IPropertyGetter<int32> __REFERENCE__ Length = this->_Length;

        __PUB__         FilterResult();
        __PUB__         FilterResult(Elem __POINTER__ elems, int32 __VARIABLE__ length, bool __VARIABLE__ needFree = true);
        __PUB__         FilterResult(Elem __POINTER__ elems, int32 __VARIABLE__ length, int32 __VARIABLE__ size, bool __VARIABLE__ needFree = true);
        __PUB__         FilterResult(const FilterResult<Elem> __REFERENCE__ fr);
        __PUB__ virtual ~FilterResult() __override_func;

        __PUB__         bool __VARIABLE__  IsEmpty();
        __PUB__ virtual bool __VARIABLE__  IsNull() __override_func;
        __PUB__         Elem __REFERENCE__ operator[](int32 __VARIABLE__ index);

        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;
    };

    template<class T>
    _interface IIteratorEntity : public virtual tianyu::TianyuObject
    {
        __PUB__ using ItemMapDelegate = void __VARIABLE__(__POINTER__)(T __REFERENCE__ elem);
        __PUB__ using ItemChkDelegate = bool __VARIABLE__(__POINTER__)(T __REFERENCE__ elem);

        __PRI__ using T_SP = tianyu::SmartPointer<T>;
        __PRI__ using T_FR = tianyu::collection::FilterResult<T>;

        __PRO__ Property<int32> __VARIABLE__ _Size;

        __PUB__ IPropertyGetter<int32> __REFERENCE__ Size;

        __PUB__         IIteratorEntity(int32 __VARIABLE__ size);
        __PUB__         IIteratorEntity(const IIteratorEntity __REFERENCE__ ite);
        __PUB__ virtual ~IIteratorEntity();

        __PUB__ virtual T_SP __VARIABLE__ Get(int32 __VARIABLE__ index) __pure_virtual_fun;
        __PUB__ virtual T_SP __VARIABLE__ End()                         __pure_virtual_fun;

        __PUB__ virtual void  __VARIABLE__ ForEach(IIteratorEntity<T>::ItemMapDelegate   __VARIABLE__ delegate) __pure_virtual_fun;
        __PUB__ virtual T     __POINTER__  Some(IIteratorEntity<T>::ItemChkDelegate      __VARIABLE__ delegate) __pure_virtual_fun;
        __PUB__ virtual T_FR  __VARIABLE__ Filter(IIteratorEntity<T>::ItemChkDelegate    __VARIABLE__ delegate) __pure_virtual_fun;
        __PUB__ virtual T_FR  __VARIABLE__ Never(IIteratorEntity<T>::ItemChkDelegate     __VARIABLE__ delegate) __pure_virtual_fun;
        __PUB__ virtual T     __POINTER__  Find(IIteratorEntity<T>::ItemChkDelegate      __VARIABLE__ delegate) __pure_virtual_fun;
        __PUB__ virtual int32 __VARIABLE__ FindIndex(IIteratorEntity<T>::ItemChkDelegate __VARIABLE__ delegate) __pure_virtual_fun;

        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;
    };

    template<class T>
    class Iterator final : public virtual tianyu::TianyuObject
    {
        __PRI__ using T_SP = tianyu::SmartPointer<T>;
        __PRI__ using T_FR = tianyu::collection::FilterResult<T>;

        __PUB__ using ItemMapDelegate = void __VARIABLE__(__POINTER__)(T __REFERENCE__ elem);
        __PUB__ using ItemChkDelegate = bool __VARIABLE__(__POINTER__)(T __REFERENCE__ elem);

        __PRI__ IIteratorEntity<T>     __REFERENCE__ _Entity;
        __PRI__ Property<int32>        __VARIABLE__  _CurrentIndex;

        __PUB__ IPropertyGetter<int32> __REFERENCE__ Size = this->_Entity.Size;

        __PUB__         Iterator(IIteratorEntity<T> __REFERENCE__ entity);
        __PUB__         Iterator(const Iterator<T>  __REFERENCE__ iterator);
        __PUB__ virtual ~Iterator() __override_func;

        __PUB__ void __VARIABLE__ Reset();
        __PUB__ T_SP __VARIABLE__ Current();
        __PUB__ T_SP __VARIABLE__ Next();
        __PUB__ T_SP __VARIABLE__ End();

        __PUB__ void  __VARIABLE__ ForEach(Iterator<T>::ItemMapDelegate   __VARIABLE__ delegate);
        __PUB__ T     __POINTER__  Some(Iterator<T>::ItemChkDelegate      __VARIABLE__ delegate);
        __PUB__ T_FR  __VARIABLE__ Filter(Iterator<T>::ItemChkDelegate    __VARIABLE__ delegate);
        __PUB__ T_FR  __VARIABLE__ Never(Iterator<T>::ItemChkDelegate     __VARIABLE__ delegate);
        __PUB__ T     __POINTER__  Find(Iterator<T>::ItemChkDelegate      __VARIABLE__ delegate);
        __PUB__ int32 __VARIABLE__ FindIndex(Iterator<T>::ItemChkDelegate __VARIABLE__ delegate);

        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;
    };

    template<class T>
    class IteratorEntity final :
        public virtual tianyu::TianyuObject,
        public virtual tianyu::collection::IIteratorEntity<T>
    {
        __PUB__ using ItemMapDelegate = void __VARIABLE__(__POINTER__)(T __REFERENCE__ elem);
        __PUB__ using ItemChkDelegate = bool __VARIABLE__(__POINTER__)(T __REFERENCE__ elem);

        __PRI__ using T_SP = tianyu::SmartPointer<T>;
        __PRI__ using T_FR = tianyu::collection::FilterResult<T>;

        __PRI__ T               __POINTER__  _Pointer;
        __PRI__ int32           __POINTER__  _Reference;

        __PRI__ Property<bool>  __VARIABLE__ _NeedFree;

        __PUB__ explicit IteratorEntity(T __POINTER__ pointer, int32 __VARIABLE__ size, bool __VARIABLE__ needFree = false);
        __PUB__          IteratorEntity(const IteratorEntity<T> __REFERENCE__ it);
        __PUB__ virtual  ~IteratorEntity() __override_func;

        __PUB__ virtual T_SP __VARIABLE__ Get(int32 __VARIABLE__ index) __override_func;
        __PUB__ virtual T_SP __VARIABLE__ End()                         __override_func;

        __PUB__ virtual void  __VARIABLE__ ForEach(IteratorEntity<T>::ItemMapDelegate   __VARIABLE__ delegate) __override_func;
        __PUB__ virtual T     __POINTER__  Some(IteratorEntity<T>::ItemChkDelegate      __VARIABLE__ delegate) __override_func;
        __PUB__ virtual T_FR  __VARIABLE__ Filter(IteratorEntity<T>::ItemChkDelegate    __VARIABLE__ delegate) __override_func;
        __PUB__ virtual T_FR  __VARIABLE__ Never(IteratorEntity<T>::ItemChkDelegate     __VARIABLE__ delegate) __override_func;
        __PUB__ virtual T     __POINTER__  Find(IteratorEntity<T>::ItemChkDelegate      __VARIABLE__ delegate) __override_func;
        __PUB__ virtual int32 __VARIABLE__ FindIndex(IteratorEntity<T>::ItemChkDelegate __VARIABLE__ delegate) __override_func;

        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;
    };
}

#pragma region template realization

// ##########################################################
// Iterators Implementation
// ##########################################################

#define __TEMPLATE_DEF__ template<typename T>

#define __F_RESULT_DEF__ tianyu::collection::FilterResult<T>
#define __II_ENTIT_DEF__ tianyu::collection::IIteratorEntity<T>
#define __ITERATOR_DEF__ tianyu::collection::Iterator<T>
#define __IT_ENTIT_DEF__ tianyu::collection::IteratorEntity<T>

 //
//##########################################################################
// Implementation for FilterResult class
//##########################################################################

__TEMPLATE_DEF__ __construction__ __F_RESULT_DEF__::FilterResult() :
    tianyu::TianyuObject(),
    _Elems(::null),
    _Length(0),
    _Size(0),
    _NeedFree(false)
{ }

__TEMPLATE_DEF__ __construction__ __F_RESULT_DEF__::FilterResult(T* elems, int32 length, bool needFree) :
    tianyu::TianyuObject(),
    _NeedFree(needFree)
{
    if (::null == elems)
        throw tianyu::except::ArgumentNullException();

    if (0 >= length)
        throw tianyu::except::ArgumentOutOfRangeException();

    this->_Elems = elems;
    this->_Length = length;
    this->_Size = length;
}

__TEMPLATE_DEF__ __construction__ __F_RESULT_DEF__::FilterResult(T* elems, int32 length, int32 size, bool needFree) :
    tianyu::TianyuObject(),
    _NeedFree(needFree)
{
    if (::null == elems)
        throw tianyu::except::ArgumentNullException();

    if (0 >= length || length > size)
        throw tianyu::except::ArgumentOutOfRangeException();

    this->_Elems = elems;
    this->_Length = length;
    this->_Size = size;
}

__TEMPLATE_DEF__ __cp_construct__ __F_RESULT_DEF__::FilterResult(const __F_RESULT_DEF__& fr)
    : tianyu::TianyuObject(),
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
        throw tianyu::except::ArgumentOutOfRangeException();

    return this->_Elems[index];
}

__TEMPLATE_DEF__::string __F_RESULT_DEF__::ToString() noexcept
{
    return tianyu::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

__TEMPLATE_DEF__ uint64 __F_RESULT_DEF__::GetTypeId()
{
    return tianyu::GetType(__PTR_TO_REF__ this).Id();
}

__TEMPLATE_DEF__ uint64 __F_RESULT_DEF__::GetHashCode()
{
    return (uint64)(this->_Elems);
}


//##########################################################################
// Implementation for IIteratorEntity interface
//##########################################################################

__TEMPLATE_DEF__ __construction__ __II_ENTIT_DEF__::IIteratorEntity(int32 size) :
    tianyu::TianyuObject(),
    _Size(size),
    Size(_Size)
{ }

__TEMPLATE_DEF__ __cp_construct__ __II_ENTIT_DEF__::IIteratorEntity(const __II_ENTIT_DEF__& ite) :
    tianyu::TianyuObject(),
    _Size(ite._Size),
    Size(_Size)
{ }

__TEMPLATE_DEF__ __destruction__  __II_ENTIT_DEF__::~IIteratorEntity()
{ }

__TEMPLATE_DEF__::string __II_ENTIT_DEF__::ToString() noexcept
{
    return tianyu::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

__TEMPLATE_DEF__ uint64 __II_ENTIT_DEF__::GetTypeId()
{
    return tianyu::GetType(__PTR_TO_REF__ this).Id();
}

__TEMPLATE_DEF__ uint64 __II_ENTIT_DEF__::GetHashCode()
{
    throw tianyu::except::NotImplementationException();
}

//##########################################################################
// Implementation for Iterator class
//##########################################################################

__TEMPLATE_DEF__ __construction__ __ITERATOR_DEF__::Iterator(__II_ENTIT_DEF__& entity) :
    tianyu::TianyuObject(),
    _Entity(entity),
    _CurrentIndex(0)
{ }

__TEMPLATE_DEF__ __construction__ __ITERATOR_DEF__::Iterator(const __ITERATOR_DEF__& iterator) :
    tianyu::TianyuObject(),
    _Entity(iterator._Entity),
    _CurrentIndex(iterator._CurrentIndex)
{ }

__TEMPLATE_DEF__ __destruction__  __ITERATOR_DEF__::~Iterator()
{ }

__TEMPLATE_DEF__ void __ITERATOR_DEF__::Reset()
{
    this->_CurrentIndex = 0;
}

__TEMPLATE_DEF__ tianyu::SmartPointer<T> __ITERATOR_DEF__::Current()
{
    return this->_Entity.Get(this->_CurrentIndex);
}

__TEMPLATE_DEF__ tianyu::SmartPointer<T> __ITERATOR_DEF__::Next()
{
    // anyway, move to the next
    this->_CurrentIndex = this->_CurrentIndex + 1;

    return this->_Entity.Get(this->_CurrentIndex);
}

__TEMPLATE_DEF__ tianyu::SmartPointer<T> __ITERATOR_DEF__::End()
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

__TEMPLATE_DEF__ tianyu::collection::FilterResult<T> __ITERATOR_DEF__::Filter(__ITERATOR_DEF__::ItemChkDelegate delegate)
{
    return this->_Entity.Filter(delegate);
}

__TEMPLATE_DEF__ tianyu::collection::FilterResult<T> __ITERATOR_DEF__::Never(__ITERATOR_DEF__::ItemChkDelegate delegate)
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
    return tianyu::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

__TEMPLATE_DEF__ uint64 __ITERATOR_DEF__::GetTypeId()
{
    return tianyu::GetType(__PTR_TO_REF__ this).Id();
}

__TEMPLATE_DEF__ uint64 __ITERATOR_DEF__::GetHashCode()
{
    return this->_Entity.GetHashCode();
}


//##########################################################################
// Implementation for IteratorEntity class
//##########################################################################

__TEMPLATE_DEF__ __construction__ __IT_ENTIT_DEF__::IteratorEntity(T* pointer, int32 size, bool needFree) :
    tianyu::TianyuObject(),
    tianyu::collection::IIteratorEntity<T>(size),
    _Pointer(pointer),
    _Reference(::null),
    _NeedFree(needFree)
{
    if (::null == pointer && 0 != size)
        throw tianyu::except::ArgumentNullException();

    if (0 > size)
        throw tianyu::except::ArgumentOutOfRangeException();

    if (this->_NeedFree && 0 < size)
        this->_Reference = new int32(1);
}

__TEMPLATE_DEF__ __cp_construct__ __IT_ENTIT_DEF__::IteratorEntity(const __IT_ENTIT_DEF__& it) :
    tianyu::TianyuObject(),
    tianyu::collection::IIteratorEntity<T>(it),
    _Pointer(it._Pointer),
    _NeedFree(it._NeedFree),
    _Reference(it._Reference)
{
    __IT_ENTIT_DEF__& cast_obj = const_cast<__IT_ENTIT_DEF__&>(it);

    if (this->_NeedFree && 0 < cast_obj._Size)
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

__TEMPLATE_DEF__ tianyu::SmartPointer<T> __IT_ENTIT_DEF__::Get(int32 index)
{
    if (0 == this->_Size)
        return tianyu::SmartPointer<T>();

    if (0 > index)
        index = 0;
    else if (index >= this->_Size)
        index = this->_Size - 1;

    return tianyu::SmartPointer<T>((this->_Pointer) + index, 1, true /* weak pointer */);
}

__TEMPLATE_DEF__ tianyu::SmartPointer<T> __IT_ENTIT_DEF__::End()
{
    if (0 == this->_Size)
        return tianyu::SmartPointer<T>();

    return tianyu::SmartPointer<T>((this->_Pointer) + this->_Size - 1, 1, true /* weak pointer */);
}

__TEMPLATE_DEF__ void __IT_ENTIT_DEF__::ForEach(__IT_ENTIT_DEF__::ItemMapDelegate delegate)
{
    if (0 == this->_Size)
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
    if (0 == this->_Size)
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
        results[i] = this->_Pointer[filters[i]];

    delete []filters;
    return __F_RESULT_DEF__(results, filterCount);
}

__TEMPLATE_DEF__ __F_RESULT_DEF__ __IT_ENTIT_DEF__::Never(__IT_ENTIT_DEF__::ItemChkDelegate delegate)
{
    if (0 == this->_Size)
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
        results[i] = this->_Pointer[filters[i]];

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
    return tianyu::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

__TEMPLATE_DEF__ uint64 __IT_ENTIT_DEF__::GetTypeId()
{
    return tianyu::GetType(__PTR_TO_REF__ this).Id();
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

#pragma endregion

#endif // !__TIANYU_COMMON_NATIVE_CORE_ITERATOR_H_PLUS_PLUS__