/**
 * @file random.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-20
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_RANDOM_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_RANDOM_H_PLUS_PLUS__

#include "./core.hxx"

namespace dty
{
    class Random : public virtual TianyuObject
    {
        __PUB__ Random();
        __PUB__ Random(int32 __VARIABLE__ seed);

        __PUB__ virtual int32  __VARIABLE__ Next();
        __PUB__ virtual int32  __VARIABLE__ Next(int32 __VARIABLE__ maxValue);
        __PUB__ virtual int32  __VARIABLE__ Next(int32 __VARIABLE__ minValue, int32 __VARIABLE__ maxValue);
        __PUB__ virtual void   __VARIABLE__ NextBytes(::byte __POINTER__ buffer, int32 __VARIABLE__ blength);
        __PUB__ virtual double __VARIABLE__ NextDouble();

        __PRO__ virtual double __VARIABLE__ Sample();

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() override;

        __PUB__ static int32 __VARIABLE__ Dicing();
        __PUB__ static int32 __VARIABLE__ Dicing(int32 __VARIABLE__ maxValue);
        __PUB__ static int32 __VARIABLE__ Dicing(int32 __VARIABLE__ minValue, int32 __VARIABLE__ maxValue);
    };
}

#endif // !__DTY_COMMON_NATIVE_PRIME_RANDOM_H_PLUS_PLUS__