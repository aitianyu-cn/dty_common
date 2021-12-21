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

#include <type_traits>

namespace dty
{
    class EventArgs : public virtual TianyuObject
    {
        __PUB__ EventArgs() { }
        __PUB__ virtual ~EventArgs() { }

        __PUB__ virtual ::string __VARIABLE__ ToString() override
        {
            return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
        }

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

        __PUB__ Property<int32>              __VARIABLE__ Count;

        __PRI__ EventHandlerItem<TEventArgs> __POINTER__  _Handlers;

        __PUB__ EventHandler() : Count(0), _Handlers(new EventHandlerItem<TEventArgs>())
        {
            static_assert(std::is_base_of<EventArgs, TEventArgs>::value, "expect EventArgs or its child class");

            this->_Handlers->_id = 0;
            this->_Handlers->_next = ::null;
        }
        __PUB__ virtual ~EventHandler()
        {
            this->Clear();

            delete (this->_Handlers);
        }

        __PUB__ void __VARIABLE__ Invoke(object __VARIABLE__ sender, TEventArgs __VARIABLE__ e)
        {
            if (0 == this->Count)
                return;

            EventHandlerItem<TEventArgs> __POINTER__ head = this->_Handlers;
            while (::null != head->_next)
            {
                head->_next->_handler(sender, e);
                head = head->_next;
            }
        }

        __PUB__ void __VARIABLE__ AddHandler(int32 __VARIABLE__ handlerId, EventHandlerDelegate __VARIABLE__ handler)
        {
            bool hasFind = false;
            EventHandlerItem<TEventArgs> __POINTER__ head = this->_Handlers;
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
                EventHandlerItem<TEventArgs> __POINTER__ newHandler = new EventHandlerItem<TEventArgs>();
                newHandler->_handler = handler;
                newHandler->_id = handlerId;

                newHandler->_next = head->_next;
                head->_next = newHandler;
                this->Count = this->Count + 1;
            }
        }
        __PUB__ void __VARIABLE__ Clear()
        {
            if (0 == this->Count)
                return;

            EventHandlerItem<TEventArgs> __POINTER__ head = this->_Handlers;
            while (::null != head->_next)
            {
                EventHandlerItem<TEventArgs> __POINTER__ del = head->_next;
                head->_next = del->_next;
                delete del;
            }

            this->Count = 0;
        }
        __PUB__ void __VARIABLE__ RemoveHandler(int32 __VARIABLE__ handlerId)
        {
            if (0 == this->Count)
                return;

            EventHandlerItem<TEventArgs> __POINTER__ head = this->_Handlers;
            EventHandlerItem<TEventArgs> __POINTER__ del = ::null;
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
                this->Count = this->Count - 1;
            }
        }

        __PUB__ virtual ::string __VARIABLE__ ToString() override
        {
            return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
        }
    };
}

#endif // !__cplusplus

#endif // !__DTY_COMMON_NATIVE_PRIME_CORE_EVENT_H_PLUS_PLUS__