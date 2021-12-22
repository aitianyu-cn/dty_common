#include "../event.hpp"

#include <type_traits>

template<class T>
dty::EventHandler<T>::EventHandler()
    : dty::TianyuObject(), _Count(0), _Handlers(new dty::EventHandlerItem<T>())
{
    static_assert(std::is_base_of<dty::EventArgs, T>::value, "expect dty::EventArgs or its child class");

    this->_Handlers->_id = 0;
    this->_Handlers->_next = ::null;
}

template<class T>
dty::EventHandler<T>::~EventHandler()
{
    this->Clear();

    delete (this->_Handlers);
}

template<class T>
void dty::EventHandler<T>::Invoke(object sender, T e)
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

template<class T>
void dty::EventHandler<T>::AddHandler(int32 handlerId, dty::EventHandler<T>::EventHandlerDelegate handler)
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

template<class T>
void dty::EventHandler<T>::Clear()
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

template<class T>
void dty::EventHandler<T>::RemoveHandler(int32 handlerId)
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

template<class T>
::string dty::EventHandler<T>::ToString() noexcept
{
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

template<class T>
uint64 dty::EventHandler<T>::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

template<class T>
uint64 dty::EventHandler<T>::GetHashCode()
{
    return (uint64)(this);
}