/**
 * @file utilize.hxx(native)
 * @author senyun.yao
 * @brief C++ 本地方法导出模块（公共模块）
 * @brief native export module, common module
 *
 * @version 0.1
 * @date 2021-12-02
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_COMMON_NATIVE_CORE_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_CORE_H_PLUS_PLUS__

#include"./core/internal.h"

#ifdef __cplusplus

#include "./core/basetype.hpp"
#include "./core/error.hpp"
#include "./core/event.hpp"
#include "./core/formatter.hpp"
#include "./core/icollections.hpp"
#include "./core/iterator.hpp"
#include "./core/pointer.hpp"
#include "./core/property.hpp"

namespace dty::collection
{
    template<typename T>
    _interface IDynamicCollections
        : public virtual dty::TianyuObject,
        public virtual dty::collection::ICollections<T>
    {
        __PUB__         IDynamicCollections(int32 __VARIABLE__ _count)
        : dty::TianyuObject(),
        dty::collection::ICollections<T>(_count)
        { }
        __PUB__         IDynamicCollections(IPropertyGetter<int32> __REFERENCE__ _count)
        : dty::TianyuObject(),
        dty::collection::ICollections<T>(_count)
        { }
        __PUB__ virtual ~IDynamicCollections() __override_func { }

        __PUB__ virtual void __VARIABLE__ Add(T __REFERENCE__ value) __pure_virtual_fun;
        __PUB__ virtual void __VARIABLE__ Insert(T __REFERENCE__ value, int32 __VARIABLE__ index) __pure_virtual_fun;
        __PUB__ virtual void __VARIABLE__ RemoveAt(T __REFERENCE__ value, int32 __VARIABLE__ index) __pure_virtual_fun;
    };
}

#endif // !__cplusplus

#endif // !__DTY_COMMON_NATIVE_H_PLUS_PLUS__