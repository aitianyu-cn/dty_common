/**
 * @file array.hpp(prime)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-19
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_ARRAY_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_ARRAY_H_PLUS_PLUS__

#include "./core.hxx"

namespace dty::collection
{
    template<class Elem>
    class Array final : public virtual TianyuObject, public virtual ICollections<Elem>
    {
        __PRI__ Elem  __POINTER__  _Array;
        __PRI__ int32 __POINTER__  _Reference;

        __PRI__ Property<bool>       __VARIABLE__ _NeedFree;
        __PRI__ IteratorEntity<Elem> __POINTER__ _IteratorEntity;

        __PUB__ Array(Elem __POINTER__ arraySrc, int32 __VARIABLE__ count, bool __VARIABLE__ needFree = true)
            : TianyuObject(),
            ICollections<Elem>(count),
            _Reference(::null),
            _NeedFree(needFree),
            _IteratorEntity(::null)
        {
            if (::null == arraySrc && 0 != count)
                throw dty::except::ArgumentNullException();

            if (0 > count)
                throw dty::except::ArgumentOutOfRangeException();

            this->_Array = arraySrc;

            // record the instance reference
            // it works only when the lifecycle of current pointer is mananged by Array
            // other wise this is a counter only
            if (0 != count)
                this->_Reference = new int32(1);
        }
        __PUB__ Array(const Array<Elem> __REFERENCE__ arr)
            : TianyuObject(),
            ICollections<Elem>(arr.Count),
            _Array(arr._Array),
            _Reference(arr._Reference),
            _NeedFree(arr._NeedFree),
            _IteratorEntity(::null)
        {
            if (0 != arr.Count)
                (__PTR_TO_VAR__(this->_Reference)) += 1;
        }
        __PUB__ ~Array()
        {
            if (::null != this->_IteratorEntity)
                delete this->_IteratorEntity;

            if (0 == this->_Count)
                return;

            if (1 == (__PTR_TO_VAR__(this->_Reference)))
            {
                delete this->_Reference;
                if (this->_NeedFree)
                    delete [] this->_Array;
            }
            else
                (__PTR_TO_VAR__(this->_Reference)) -= 1;
        }

        __PUB__ virtual bool           __VARIABLE__   IsNull() override
        {
            return ::null == this->_Array;
        }
        __PUB__ Elem           __REFERENCE__  operator[](int32 __VARIABLE__ index)
        {
            if (index >= this->_Count)
                throw dty::except::ArgumentOutOfRangeException();

            return this->_Array[index];
        }
        __PUB__ virtual Iterator<Elem> __VARIABLE__   GetIterator() override
        {
            if (::null == this->_IteratorEntity)
                this->_IteratorEntity = new IteratorEntity<Elem>(this->_Array, (int32)(this->Count), false);

            return Iterator<Elem>(__PTR_TO_REF__ this->_IteratorEntity);
        }

#ifdef __DTY_UNSAFE_MODE__
        __PUB__ void           __VARIABLE__   SetNoDelete()
        {
            this->_NeedFree = false;
        }
        __PUB__ void           __VARIABLE__   SetNeedDelete()
        {
            this->_NeedFree = true;
    }
#endif // !__DTY_UNSAFE_MODE__

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override
        {
            return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
        }
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() override
        {
            return dty::GetType(__PTR_TO_REF__ this).Id();
        }
};

    using ByteArray = Array<byte>;
    using BoolArray = Array<bool>;
    using ShortArray = Array<int16>;
    using IntArray = Array<int32>;
    using LongArray = Array<int64>;
    using FloatArray = Array<float>;
    using DoubleArray = Array<double>;
    using CharArray = Array<char>;
}

#endif // !__DTY_COMMON_NATIVE_PRIME_ARRAY_H_PLUS_PLUS__