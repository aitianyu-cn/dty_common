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
        __PUB__ const IPropertyGetter<int32> __REFERENCE__ Length = this->_Length;

        __PRI__ Elem  __POINTER__  _Elems;

        __PRI__ Property<int32> __VARIABLE__ _Length;
        __PRI__ Property<int32> __VARIABLE__ _Size;
        __PRI__ Property<bool>  __VARIABLE__ _NeedFree;

        __PUB__ FilterResult();
        __PUB__ FilterResult(Elem __POINTER__ elems, int32 __VARIABLE__ length, int32 __VARIABLE__ size, bool __VARIABLE__ needFree);
        __PUB__ FilterResult(const FilterResult<Elem> __REFERENCE__ fr);
        __PUB__ ~FilterResult();

        __PUB__ bool __VARIABLE__  IsEmpty();
        __PUB__ Elem __REFERENCE__ operator[](int32 __VARIABLE__ index);

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() override;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() override;
    };

    template<class T>
    _interface IIteratorEntity : public virtual dty::TianyuObject
    {
        __PUB__ using ItemMapDelegate = void __VARIABLE__(__POINTER__)(T __REFERENCE__ elem);
        __PUB__ using ItemChkDelegate = bool __VARIABLE__(__POINTER__)(T __REFERENCE__ elem);

        __PRI__ using T_SP = dty::SmartPointer<T>;
        __PRI__ using T_FR = dty::collection::FilterResult<T>;

        __PUB__ const IPropertyGetter<int32> __REFERENCE__ Size;

        __PUB__ IIteratorEntity(IPropertyGetter<int32> __REFERENCE__ size);
        __PUB__ virtual ~IIteratorEntity();

        __PUB__ virtual T_SP __VARIABLE__ Get(int32 __VARIABLE__ index) = 0;
        __PUB__ virtual T_SP __VARIABLE__ End() = 0;

        __PUB__ virtual void  __VARIABLE__ ForEach(IIteratorEntity<T>::ItemMapDelegate __VARIABLE__ delegate) = 0;
        __PUB__ virtual T     __POINTER__  Some(IIteratorEntity<T>::ItemChkDelegate __VARIABLE__ delegate) = 0;
        __PUB__ virtual T_FR  __VARIABLE__ Filter(IIteratorEntity<T>::ItemChkDelegate __VARIABLE__ delegate) = 0;
        __PUB__ virtual T_FR  __VARIABLE__ Every(IIteratorEntity<T>::ItemChkDelegate __VARIABLE__ delegate) = 0;
        __PUB__ virtual T     __POINTER__  Find(IIteratorEntity<T>::ItemChkDelegate __VARIABLE__ delegate) = 0;
        __PUB__ virtual int32 __VARIABLE__ FindIndex(IIteratorEntity<T>::ItemChkDelegate __VARIABLE__ delegate) = 0;

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() override;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() override;
    };

    template<class T>
    class Iterator final : public virtual dty::TianyuObject
    {
        __PRI__ using T_SP = dty::SmartPointer<T>;
        __PRI__ using T_FR = dty::collection::FilterResult<T>;

        __PUB__ using ItemMapDelegate = void __VARIABLE__(__POINTER__)(T __REFERENCE__ elem);
        __PUB__ using ItemChkDelegate = bool __VARIABLE__(__POINTER__)(T __REFERENCE__ elem);

        __PUB__ IPropertyGetter<int32> __REFERENCE__ Size = this->_Entity.Size;

        __PRI__ IIteratorEntity<T>     __REFERENCE__ _Entity;
        __PRI__ Property<int32>        __VARIABLE__  _CurrentIndex;

        __PUB__ Iterator(IIteratorEntity<T> __REFERENCE__ entity);
        __PUB__ Iterator(const Iterator<T>  __REFERENCE__ iterator);
        __PUB__ virtual ~Iterator() override;

        __PUB__ void __VARIABLE__ Reset();
        __PUB__ T_SP __VARIABLE__ Current();
        __PUB__ T_SP __VARIABLE__ Next();
        __PUB__ T_SP __VARIABLE__ End();

        __PUB__ void  __VARIABLE__ ForEach(Iterator<T>::ItemMapDelegate __VARIABLE__ delegate);
        __PUB__ T     __POINTER__  Some(Iterator<T>::ItemChkDelegate __VARIABLE__ delegate);
        __PUB__ T_FR  __VARIABLE__ Filter(Iterator<T>::ItemChkDelegate __VARIABLE__ delegate);
        __PUB__ T_FR  __VARIABLE__ Every(Iterator<T>::ItemChkDelegate __VARIABLE__ delegate);
        __PUB__ T     __POINTER__  Find(Iterator<T>::ItemChkDelegate __VARIABLE__ delegate);
        __PUB__ int32 __VARIABLE__ FindIndex(Iterator<T>::ItemChkDelegate __VARIABLE__ delegate);

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() override;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() override;
    };

    template<class T>
    class IteratorEntity final : public virtual TianyuObject, public virtual IIteratorEntity<T>
    {
        __PUB__ using ItemMapDelegate = void __VARIABLE__(__POINTER__)(T __REFERENCE__ elem);
        __PUB__ using ItemChkDelegate = bool __VARIABLE__(__POINTER__)(T __REFERENCE__ elem);

        __PRI__ using T_SP = dty::SmartPointer<T>;
        __PRI__ using T_FR = dty::collection::FilterResult<T>;

        __PRI__ T               __POINTER__  _Pointer;

        __PRI__ Property<int32> __VARIABLE__ _Size;
        __PRI__ Property<bool>  __VARIABLE__ _NeedFree;

        __PUB__ explicit IteratorEntity(T __POINTER__ pointer, int32 __VARIABLE__ size, bool __VARIABLE__ needFree = false);
        __PUB__ IteratorEntity(const Iterator<T> __REFERENCE__ it);
        __PUB__ virtual ~IteratorEntity() override;

        __PUB__ virtual T_SP __VARIABLE__ Get(int32 __VARIABLE__ index) override;
        __PUB__ virtual T_SP __VARIABLE__ End() override;

        __PUB__ virtual void  __VARIABLE__ ForEach(IteratorEntity<T>::ItemMapDelegate __VARIABLE__ delegate) override;
        __PUB__ virtual T     __POINTER__  Some(IteratorEntity<T>::ItemChkDelegate __VARIABLE__ delegate) override;
        __PUB__ virtual T_FR  __VARIABLE__ Filter(IteratorEntity<T>::ItemChkDelegate __VARIABLE__ delegate) override;
        __PUB__ virtual T_FR  __VARIABLE__ Every(IteratorEntity<T>::ItemChkDelegate __VARIABLE__ delegate) override;
        __PUB__ virtual T     __POINTER__  Find(IteratorEntity<T>::ItemChkDelegate __VARIABLE__ delegate) override;
        __PUB__ virtual int32 __VARIABLE__ FindIndex(IteratorEntity<T>::ItemChkDelegate __VARIABLE__ delegate) override;

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() override;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() override;
    };
}

#include "./res/dty_collection_filter_result.cc"
#include "./res/dty_collection_i_iterator_entity.cc"
#include "./res/dty_collection_iterator.cc"
#include "./res/dty_collection_iterator_entity.cc"

#endif // !__DTY_COMMON_NATIVE_PRIME_ITERATOR_H_PLUS_PLUS__