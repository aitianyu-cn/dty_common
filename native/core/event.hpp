/**
 * @file event.hpp(core)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-16
 * @date 2023-07-31
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __TIANYU_COMMON_NATIVE_CORE_EVENT_H_PLUS_PLUS__
#define __TIANYU_COMMON_NATIVE_CORE_EVENT_H_PLUS_PLUS__

#ifdef __cplusplus

#include "./internal.h"
#include "./property.hpp"

namespace tianyu
{
    class EventArgs : public virtual tianyu::TianyuObject
    {
        __PUB__         EventArgs();
        __PUB__ virtual ~EventArgs() __override_func;

        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;

        __PUB__ static EventArgs __VARIABLE__ Empty;
    };

    template<class TEventArgs = EventArgs>
    struct EventHandlerItem
    {
        using EventHandlerDelegate = void __VARIABLE__(__POINTER__)(object __VARIABLE__ sender, TEventArgs __VARIABLE__ e);

        int32                        __VARIABLE__ _id;
        EventHandlerDelegate         __VARIABLE__ _handler;

        EventHandlerItem<TEventArgs> __POINTER__  _next;
    };

    template<class TEventArgs = EventArgs>
    class EventHandler : public virtual tianyu::TianyuObject
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

#pragma region template realization

// ##########################################################
// Event Implementation
// ##########################################################

#include <type_traits>

#define __TEMPLATE_DEF__ template<class T>
#define __EVENT_HD_DEF__ tianyu::EventHandler<T>

__TEMPLATE_DEF__ __construction__ __EVENT_HD_DEF__::EventHandler() :
    tianyu::TianyuObject(),
    _Count(0),
    _Handlers(new tianyu::EventHandlerItem<T>()),
    Count(_Count)
{
    static_assert(std::is_base_of<tianyu::EventArgs, T>::value, "expect tianyu::EventArgs or its child class");

    this->_Handlers->_id = 0;
    this->_Handlers->_next = ::null;
}

__TEMPLATE_DEF__ __destruction__  __EVENT_HD_DEF__::~EventHandler()
{
    this->Clear();

    delete (this->_Handlers);
}

__TEMPLATE_DEF__ void __EVENT_HD_DEF__::Invoke(object sender, T e)
{
    if (0 == this->_Count)
        return;

    EventHandlerItem<T>* head = this->_Handlers;
    while (::null != head->_next)
    {
        head->_next->_handler(sender, e);
        head = head->_next;
    }
}

__TEMPLATE_DEF__ void __EVENT_HD_DEF__::AddHandler(int32 handlerId, __EVENT_HD_DEF__::EventHandlerDelegate handler)
{
    bool hasFind = false;
    tianyu::EventHandlerItem<T>* head = this->_Handlers;
    while (::null != head->_next && !hasFind)
    {
        if (handlerId == head->_next->_id)
            hasFind = true;

        if (handlerId < head->_next->_id)
            break;

        head = head->_next;
    }

    if (!hasFind)
    {
        tianyu::EventHandlerItem<T>* newHandler = new EventHandlerItem<T>();
        newHandler->_handler = handler;
        newHandler->_id = handlerId;

        newHandler->_next = head->_next;
        head->_next = newHandler;
        this->_Count = this->_Count + 1;
    }
}

__TEMPLATE_DEF__ void __EVENT_HD_DEF__::Clear()
{
    if (0 == this->_Count)
        return;

    tianyu::EventHandlerItem<T>* head = this->_Handlers;
    while (::null != head->_next)
    {
        tianyu::EventHandlerItem<T>* del = head->_next;
        head->_next = del->_next;
        delete del;
    }

    this->_Count = 0;
}

__TEMPLATE_DEF__ void __EVENT_HD_DEF__::RemoveHandler(int32 handlerId)
{
    if (0 == this->_Count)
        return;

    tianyu::EventHandlerItem<T>* head = this->_Handlers;
    tianyu::EventHandlerItem<T>* del = ::null;
    while (::null != head->_next && ::null == del)
    {
        if (handlerId == head->_next->_id)
        {
            del = head->_next;
            head->_next = del->_next;
        }
        head = head->_next;
    }

    if (::null != del)
    {
        delete del;
        this->_Count = this->_Count - 1;
    }
}

__TEMPLATE_DEF__::string __EVENT_HD_DEF__::ToString() noexcept
{
    return tianyu::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

__TEMPLATE_DEF__ uint64 __EVENT_HD_DEF__::GetTypeId()
{
    return tianyu::GetType(__PTR_TO_REF__ this).Id();
}

__TEMPLATE_DEF__ uint64 __EVENT_HD_DEF__::GetHashCode()
{
    return (uint64)(this);
}

// to cancel the macro definitions
#undef __TEMPLATE_DEF__
#undef __EVENT_HD_DEF__

#pragma endregion

#endif // !__cplusplus

#endif // !__TIANYU_COMMON_NATIVE_CORE_EVENT_H_PLUS_PLUS__