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

#ifndef __DTY_COMMON_NATIVE_PRIME_CORE_ICOLLECTION_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_CORE_ICOLLECTION_H_PLUS_PLUS__

#include "./iterator.hpp"

namespace dty::collection
{
    template<typename T>
    _interface ICollections : public virtual dty::TianyuObject
    {
        __PUB__ IPropertyGetter<int32> __REFERENCE__ Count;

        __PUB__         ICollections(IPropertyGetter<int32> __REFERENCE__ _count);
        __PUB__ virtual ~ICollections() __override_func;

        __PUB__ virtual Iterator<T> __VARIABLE__ GetIterator() __pure_virtual_fun;
    };
}

#pragma region template realization

// ##########################################################
// ICollections Implementation
// ##########################################################

template<typename T>
__construction__ dty::collection::ICollections<T>::ICollections(dty::IPropertyGetter<int32>& count) :
    dty::TianyuObject(),
    Count(count)
{ }

template<typename T>
__destruction__  dty::collection::ICollections<T>::~ICollections() { }

#pragma endregion

#endif // !__DTY_COMMON_NATIVE_PRIME_CORE_ICOLLECTION_H_PLUS_PLUS__