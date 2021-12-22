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

#include "./core.hxx"

namespace dty::collection
{
    template<class Elem>
    class FilterResult final : dty::TianyuObject
    {
        __PUB__ IPropertyGetter<int32> __REFERENCE__ Length = this->_Length;

        __PRI__ Elem  __POINTER__  Elems;

        __PRI__ Property<int32> __VARIABLE__ _Length;
        __PRI__ Property<int32> __VARIABLE__ _Size;
        __PRI__ Property<bool>  __VARIABLE__ _NeedFree;

        __PUB__ FilterResult()
            : Elems(::null), _Length(0), _Size(0), _NeedFree(false)
        {

        }
        __PUB__ FilterResult(Elem __POINTER__ elems, int32 __VARIABLE__ length, int32 __VARIABLE__ size, bool __VARIABLE__ needFree = true)
            : _NeedFree(needFree)
        {
            if (::null == elems)
                throw dty::except::ArgumentNullException();

            if (0 >= length || length > size)
                throw dty::except::ArgumentOutOfRangeException();

            this->Elems = elems;
            this->_Length = length;
            this->_Size = size;
        }
        __PUB__ ~FilterResult()
        {
            if (!this->_NeedFree)
                return;

            if (1 == this->_Size)
                delete this->Elems;
            else
                delete [] this->Elems;
        }

        __PUB__ bool  __VARIABLE__ IsEmpty()
        {
            return 0 == this->_Length;
        }
        __PUB__ Elem  __REFERENCE__ operator[](int32 __VARIABLE__ index)
        {
            if (index >= this->_Length)
                throw dty::except::ArgumentOutOfRangeException();

            return this->Elems[index];
        }

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override
        {
            return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
        }
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() override
        {
            return dty::GetType(__PTR_TO_REF__ this).Id();
        }
    };

    template<class Elem>
    abstract class IteratorBase : public virtual dty::TianyuObject
    {
        __PUB__ using fnItemMap = void __VARIABLE__(__POINTER__)(Elem __REFERENCE__ elem);
        __PUB__ using fnItemCheck = bool __VARIABLE__(__POINTER__)(Elem __REFERENCE__ elem);

        __PUB__ IteratorBase() { }
        __PUB__ virtual ~IteratorBase() { }

        __PUB__ virtual int32              __VARIABLE__ Size() = 0;

        __PUB__ virtual void               __VARIABLE__ Reset() = 0;
        __PUB__ virtual SmartPointer<Elem> __VARIABLE__ Current() = 0;
        __PUB__ virtual SmartPointer<Elem> __VARIABLE__ Next() = 0;
        __PUB__ virtual SmartPointer<Elem> __VARIABLE__ End() = 0;

        __PUB__ virtual void               __VARIABLE__ ForEach(IteratorBase<Elem>::fnItemMap __VARIABLE__ fnForEach) = 0;
        __PUB__ virtual Elem               __POINTER__  Some(IteratorBase<Elem>::fnItemCheck __VARIABLE__ fnForEach) = 0;
        __PUB__ virtual FilterResult<Elem> __VARIABLE__ Filter(IteratorBase<Elem>::fnItemCheck __VARIABLE__ fnForEach) = 0;
        __PUB__ virtual FilterResult<Elem> __VARIABLE__ Every(IteratorBase<Elem>::fnItemCheck __VARIABLE__ fnForEach) = 0;
        __PUB__ virtual Elem               __POINTER__  Find(IteratorBase<Elem>::fnItemCheck __VARIABLE__ fnForEach) = 0;
        __PUB__ virtual int32              __VARIABLE__ FindIndex(IteratorBase<Elem>::fnItemCheck __VARIABLE__ fnForEach) = 0;

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override
        {
            return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
        }
    };

    template<class Elem>
    class Iterator final : public virtual TianyuObject
    {
        __PUB__ using fnItemMap = void __VARIABLE__(__POINTER__)(Elem __REFERENCE__ elem);
        __PUB__ using fnItemCheck = bool __VARIABLE__(__POINTER__)(Elem __REFERENCE__ elem);

        __PUB__ IPropertyGetter<int32> __REFERENCE__ Size = this->_Size;

        __PRI__ Elem  __POINTER__  _Pointer;
        __PRI__ int32 __POINTER__  _Reference;

        __PRI__ Property<int32> __VARIABLE__ _Size;
        __PRI__ Property<int32> __VARIABLE__ _Current;
        __PRI__ Property<bool>  __VARIABLE__ _NeedFree;

        __PUB__ explicit Iterator(Elem __POINTER__ pointer, int32 __VARIABLE__ size, bool __VARIABLE__ needFree = false)
            : _Current(0), _NeedFree(needFree), _Reference(::null)
        {
            if (::null == pointer && 0 != size)
                throw dty::except::ArgumentNullException();

            if (0 > size)
                throw dty::except::ArgumentOutOfRangeException();

            this->_Pointer = pointer;
            this->_Size = size;

            // record the instance reference only when 
            // the lifecycle of current pointer is mananged by iterator
            if (this->_NeedFree && 0 < size)
                this->_Reference = new int32(1);
        }
        __PUB__ Iterator(const Iterator<Elem> __REFERENCE__ it)
            : _Pointer(it._Pointer), _Size(it._Size), _Current(0),
            _NeedFree(it._NeedFree), _Reference(it._Reference)
        {
            if (this->_NeedFree && 0 < it._Size)
                (__PTR_TO_VAR__(this->_Reference)) += 1;
        }
        __PUB__ virtual ~Iterator() override
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

        __PUB__ void               __VARIABLE__ Reset()
        {
            this->_Current = 0;
        }
        __PUB__ SmartPointer<Elem> __VARIABLE__ Current()
        {
            if (0 == this->Size())
                return SmartPointer<Elem>();

            return SmartPointer<Elem>((this->_Pointer) + this->_Current, 1, true);
        }
        __PUB__ SmartPointer<Elem> __VARIABLE__ Next()
        {
            if (0 == this->Size())
                return SmartPointer<Elem>();

            if (this->_Current < this->_Size - 1)
                ++(this->_Current);

            return SmartPointer<Elem>((this->_Pointer) + this->_Current, 1, true);
        }
        __PUB__ SmartPointer<Elem> __VARIABLE__ End()
        {
            if (0 == this->Size())
                return SmartPointer<Elem>();

            return SmartPointer<Elem>((this->_Pointer) + this->_Size - 1, 1, true);
        }

        __PUB__ void               __VARIABLE__ ForEach(Iterator<Elem>::fnItemMap __VARIABLE__ fnForEach)
        {
            if (0 == this->Size())
                return;

            for (int32 i = 0; i < this->_Size; ++i)
                fnForEach(this->_Pointer[i]);
        }
        __PUB__ Elem               __POINTER__  Some(Iterator<Elem>::fnItemCheck __VARIABLE__ fnForEach)
        {
            for (int32 i = 0; i < this->_Size; ++i)
                if (!fnForEach(this->_Pointer[i]))
                    return (this->_Pointer) + i;

            return ::null;
        }
        __PUB__ FilterResult<Elem> __VARIABLE__ Filter(Iterator<Elem>::fnItemCheck __VARIABLE__ fnForEach)
        {
            if (0 == this->Size())
                return FilterResult<Elem>();

            Elem __POINTER__ results = new Elem[this->_Size];
            int32 length = 0;

            for (int32 i = 0; i < this->_Size; ++i)
                if (fnForEach(this->_Pointer[i]))
                    results[length++] = (this->_Pointer) + i;

            if (0 == length)
            {
                delete [] results;
                return FilterResult<Elem>();
            }

            return FilterResult<Elem>(results, length, this->_Size);
        }
        __PUB__ FilterResult<Elem> __VARIABLE__ Every(Iterator<Elem>::fnItemCheck __VARIABLE__ fnForEach)
        {
            if (0 == this->Size())
                return FilterResult<Elem>();

            Elem __POINTER__ results = new Elem[this->_Size];
            int32 length = 0;

            for (int32 i = 0; i < this->_Size; ++i)
                if (!fnForEach(this->_Pointer[i]))
                    results[length++] = (this->_Pointer) + i;

            if (0 == length)
            {
                delete [] results;
                return FilterResult<Elem>();
            }

            return FilterResult<Elem>(results, length, this->_Size);
        }
        __PUB__ Elem               __POINTER__  Find(Iterator<Elem>::fnItemCheck __VARIABLE__ fnForEach)
        {
            for (int32 i = 0; i < this->_Size; ++i)
                if (fnForEach(this->_Pointer[i]))
                    return (this->_Pointer) + i;

            return ::null;
        }
        __PUB__ int32              __VARIABLE__ FindIndex(Iterator<Elem>::fnItemCheck __VARIABLE__ fnForEach)
        {
            for (int32 i = 0; i < this->_Size; ++i)
                if (fnForEach(this->_Pointer[i]))
                    return i;

            return -1;
        }

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override
        {
            return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
        }
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() override
        {
            return dty::GetType(__PTR_TO_REF__ this).Id();
        }
    };
}


#endif // !__DTY_COMMON_NATIVE_PRIME_ITERATOR_H_PLUS_PLUS__