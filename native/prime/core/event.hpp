/**
 * @file event.hpp(prime/core)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-16
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_CORE_EVENT_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_CORE_EVENT_H_PLUS_PLUS__

#ifdef __cplusplus

#include "./internal.h"
#include "./property.hpp"

namespace dty
{
    class EventArgs : public virtual TianyuObject
    {
        __PUB__ EventArgs();
        __PUB__ virtual ~EventArgs() override;

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() override;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() override;

        __PUB__ static EventArgs __VARIABLE__ Empty;
    };

    template<class TEventArgs>
    struct EventHandlerItem
    {
        using EventHandlerDelegate = void __VARIABLE__(__POINTER__)(object __VARIABLE__ sender, TEventArgs __VARIABLE__ e);

        int32                        __VARIABLE__ _id;
        EventHandlerDelegate         __VARIABLE__ _handler;

        EventHandlerItem<TEventArgs> __POINTER__  _next;
    };

    template<class TEventArgs>
    class EventHandler : public virtual TianyuObject
    {
        using EventHandlerDelegate = void __VARIABLE__(__POINTER__)(object __VARIABLE__ sender, TEventArgs __VARIABLE__ e);

        __PUB__ const IPropertyGetter<int32> __REFERENCE__ Count = this->_Count;

        __PRI__ Property<int32>              __VARIABLE__ _Count;
        __PRI__ EventHandlerItem<TEventArgs> __POINTER__  _Handlers;

        __PUB__ EventHandler();
        __PUB__ virtual ~EventHandler() override;

        __PUB__ void __VARIABLE__ Invoke(object __VARIABLE__ sender, TEventArgs __VARIABLE__ e);
        __PUB__ void __VARIABLE__ AddHandler(int32 __VARIABLE__ handlerId, EventHandlerDelegate __VARIABLE__ handler);
        __PUB__ void __VARIABLE__ Clear();
        __PUB__ void __VARIABLE__ RemoveHandler(int32 __VARIABLE__ handlerId);

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() override;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() override;
    };
}

#include "./res/event.cc"

#endif // !__cplusplus

#endif // !__DTY_COMMON_NATIVE_PRIME_CORE_EVENT_H_PLUS_PLUS__