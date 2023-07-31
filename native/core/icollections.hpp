/**
 * @file icollection.hpp(core)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-22
 * @date 2023-07-31
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.icollection?view=net-6.0
 */

#ifndef __TIANYU_COMMON_NATIVE_CORE_ICOLLECTION_H_PLUS_PLUS__
#define __TIANYU_COMMON_NATIVE_CORE_ICOLLECTION_H_PLUS_PLUS__

#include "./iterator.hpp"

namespace tianyu::collection
{
    template<typename T>
    _interface ICollections : public virtual tianyu::TianyuObject
    {
        __PRO__ Property<int32>        __VARIABLE__ _Count;

        __PUB__ IPropertyGetter<int32> __REFERENCE__ Count;

        __PUB__         ICollections(int32 __VARIABLE__ _count);
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
__construction__ tianyu::collection::ICollections<T>::ICollections(tianyu::IPropertyGetter<int32>& count) :
    tianyu::TianyuObject(),
    _Count(count),
    Count(_Count)
{ }

template<typename T>
__construction__ tianyu::collection::ICollections<T>::ICollections(int32 count) :
    tianyu::TianyuObject(),
    _Count(count),
    Count(_Count)
{ }

template<typename T>
__destruction__  tianyu::collection::ICollections<T>::~ICollections() { }

#pragma endregion

#endif // !__TIANYU_COMMON_NATIVE_CORE_ICOLLECTION_H_PLUS_PLUS__