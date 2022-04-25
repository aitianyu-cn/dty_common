/**
 * @file bitmap.hpp(prime)
 * @author ysydty
 * @brief
 * @version 0.1
 * @date 2022-04-25
 *
 * @copyright aitianyu.cn Copyright (c) 2022
 *
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_BITMAP_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_BITMAP_H_PLUS_PLUS__

#include "./core.hxx"
#include "./core/icollections.hpp"

namespace dty::collection
{
    class Bitmap : public virtual TianyuObject
    {
        __PRI__ Property<int64> __VARIABLE__ _Count;

        __PUB__ IPropertyGetter<int64> __REFERENCE__ Count;

        __PUB__         Bitmap(int64 __VARIABLE__ size);
        __PUB__         Bitmap(int64 __VARIABLE__ size, bool __VARIABLE__ fillState);
        __PUB__         Bitmap(byte __POINTER__ bits, int32 __VARIABLE__ length);
        __PUB__ virtual ~Bitmap();

        __PUB__ void __VARIABLE__ Fill(bool __VARIABLE__ state);
        __PUB__ bool __VARIABLE__ RollOver(int64 __VARIABLE__ bitIndex);
        __PUB__ bool __VARIABLE__ Set(int64 __VARIABLE__ bitIndex, bool __VARIABLE__ state);
        __PUB__ bool __VARIABLE__ Test(int64 __VARIABLE__ bitIndex);

        __PUB__ byte __POINTER__  ToBytes(int32 __REFERENCE__ length);

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId();
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode();
    };
}

#endif // !__DTY_COMMON_NATIVE_PRIME_BITMAP_H_PLUS_PLUS__