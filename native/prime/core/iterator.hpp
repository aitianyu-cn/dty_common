/**
 * @file iterator.hpp(prime)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-19
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#pragma once
#ifndef __DTY_COMMON_NATIVE_PRIME_ITERATOR_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_ITERATOR_H_PLUS_PLUS__

#include "./internal.h"
#include "./property.hpp"
#include "./pointer.hpp"

namespace dty::collection
{
    template<class Elem>
    class FilterResult final : public virtual dty::TianyuObject
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
    _interface IIteratorEntity : public virtual dty::TianyuObject
    {
        __PUB__ using ItemMapDelegate = void __VARIABLE__(__POINTER__)(T __REFERENCE__ elem);
        __PUB__ using ItemChkDelegate = bool __VARIABLE__(__POINTER__)(T __REFERENCE__ elem);

        __PRI__ using T_SP = dty::SmartPointer<T>;
        __PRI__ using T_FR = dty::collection::FilterResult<T>;

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
    class Iterator final : public virtual dty::TianyuObject
    {
        __PRI__ using T_SP = dty::SmartPointer<T>;
        __PRI__ using T_FR = dty::collection::FilterResult<T>;

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
        public virtual dty::TianyuObject,
        public virtual dty::collection::IIteratorEntity<T>
    {
        __PUB__ using ItemMapDelegate = void __VARIABLE__(__POINTER__)(T __REFERENCE__ elem);
        __PUB__ using ItemChkDelegate = bool __VARIABLE__(__POINTER__)(T __REFERENCE__ elem);

        __PRI__ using T_SP = dty::SmartPointer<T>;
        __PRI__ using T_FR = dty::collection::FilterResult<T>;

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

#include "./res/iterator.cc"

#endif // !__DTY_COMMON_NATIVE_PRIME_ITERATOR_H_PLUS_PLUS__