/**
 * @file dty_property.cc
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-23
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../property.hpp"

template<class T>
dty::Property<T>::Property() :dty::TianyuObject(), _Elem() { }

template<class T>
dty::Property<T>::Property(T value) : dty::TianyuObject(), _Elem(value) { }

template<class T>
dty::Property<T>::~Property() { }

template<class T>
T dty::Property<T>::Get()
{
    return this->_Elem;
}

template<class T>
void dty::Property<T>::Set(T value)
{
    this->_Elem = value;
}

template<class T>
dty::Property<T>::operator T()
{
    return this->_Elem;
}

template<class T>
T dty::Property<T>::operator=(T value)
{
    this->_Elem = value;
    return value;
}

template<class T>
T dty::Property<T>::operator=(dty::IPropertyGetter<T>& value)
{
    this->_Elem = value;
    return value;
}

template<class T>
::string dty::Property<T>::ToString() noexcept
{
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

template<class T>
uint64 dty::Property<T>::GetTypeId() noexcept
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

template<class T>
uint64 dty::Property<T>::GetHashCode() noexcept
{
    return (uint64)(this);
}