/**
 * @file icollection.hpp(prime)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-22
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.icollection?view=net-6.0
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_ICOLLECTION_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_ICOLLECTION_H_PLUS_PLUS__

#include "./core.hxx"
#include "./iterator.hpp"

namespace dty::collection
{
    template<typename T>
    _interface ICollections : public virtual TianyuObject
    {
        __PUB__ IPropertyGetter<int32> __REFERENCE__ Count;

        __PUB__ ICollections(IPropertyGetter<int32> __REFERENCE__ _count)
            : TianyuObject(), Count(_count)
        { }

        __PUB__ virtual ~ICollections() { }

        __PUB__ virtual Iterator<T> __VARIABLE__ GetIterator() = 0;
    };
}

#endif // !__DTY_COMMON_NATIVE_PRIME_ICOLLECTION_H_PLUS_PLUS__