/**
 * @file event.cc
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../event.hpp"

#include <type_traits>

 // to cancel the macro definitions
#define __TEMPLATE_DEF__ template<class T>
#define __EVENT_HD_DEF__ dty::EventHandler<T>

__TEMPLATE_DEF__ __EVENT_HD_DEF__::EventHandler()
    : dty::TianyuObject(), _Count(0), _Handlers(new dty::EventHandlerItem<T>())
{
    static_assert(std::is_base_of<dty::EventArgs, T>::value, "expect dty::EventArgs or its child class");

    this->_Handlers->_id = 0;
    this->_Handlers->_next = ::null;
}

__TEMPLATE_DEF__ __EVENT_HD_DEF__::~EventHandler()
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
    dty::EventHandlerItem<T>* head = this->_Handlers;
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
        dty::EventHandlerItem<T>* newHandler = new EventHandlerItem<T>();
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

    dty::EventHandlerItem<T>* head = this->_Handlers;
    while (::null != head->_next)
    {
        dty::EventHandlerItem<T>* del = head->_next;
        head->_next = del->_next;
        delete del;
    }

    this->_Count = 0;
}

__TEMPLATE_DEF__ void __EVENT_HD_DEF__::RemoveHandler(int32 handlerId)
{
    if (0 == this->_Count)
        return;

    dty::EventHandlerItem<T>* head = this->_Handlers;
    dty::EventHandlerItem<T>* del = ::null;
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
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

__TEMPLATE_DEF__ uint64 __EVENT_HD_DEF__::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

__TEMPLATE_DEF__ uint64 __EVENT_HD_DEF__::GetHashCode()
{
    return (uint64)(this);
}

// to cancel the macro definitions
#undef __TEMPLATE_DEF__
#undef __EVENT_HD_DEF__