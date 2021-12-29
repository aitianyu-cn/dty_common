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
    class EventArgs : public virtual dty::TianyuObject
    {
        __PUB__         EventArgs();
        __PUB__ virtual ~EventArgs() __override_func;

        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;

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
    class EventHandler : public virtual dty::TianyuObject
    {
        using EventHandlerDelegate = void __VARIABLE__(__POINTER__)(object __VARIABLE__ sender, TEventArgs __VARIABLE__ e);

        __PRI__ Property<int32>              __VARIABLE__ _Count;
        __PRI__ EventHandlerItem<TEventArgs> __POINTER__  _Handlers;

        __PUB__ IPropertyGetter<int32> __REFERENCE__ Count;

        __PUB__         EventHandler();
        __PUB__ virtual ~EventHandler() __override_func;

        __PUB__ void __VARIABLE__ Invoke(object __VARIABLE__ sender, TEventArgs __VARIABLE__ e);
        __PUB__ void __VARIABLE__ AddHandler(int32 __VARIABLE__ handlerId, EventHandlerDelegate __VARIABLE__ handler);
        __PUB__ void __VARIABLE__ Clear();
        __PUB__ void __VARIABLE__ RemoveHandler(int32 __VARIABLE__ handlerId);

        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;
    };
}

#include "./res/event.cc"

#endif // !__cplusplus

#endif // !__DTY_COMMON_NATIVE_PRIME_CORE_EVENT_H_PLUS_PLUS__