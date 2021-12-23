/**
 * @file dty_lproperty.cc
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-23
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../property.hpp"
#include "../error.hpp"

template<class T>
dty::LProperty<T>::LProperty
(
    dty::LProperty<T>::PropertyGetDelegate getter,
    dty::LProperty<T>::PropertySetDelegate setter
) : dty::TianyuObject(), _Getter(getter), _Setter(setter) { }

template<class T>
dty::LProperty<T>::~LProperty() { }

template<class T>
T dty::LProperty<T>::Get()
{
    return this->_Getter();
}

template<class T>
void dty::LProperty<T>::Set(T value)
{
    this->_Setter(value);
}

template<class T>
dty::LProperty<T>::operator T()
{
    return this->_Getter();
}

template<class T>
T dty::LProperty<T>::operator=(T value)
{
    this->_Setter(value);

    return this->_Getter();
}

template<class T>
T dty::LProperty<T>::operator=(dty::IPropertyGetter<T>& value)
{
    this->_Setter(value);

    return this->_Getter();
}

template<class T>
::string dty::LProperty<T>::ToString() noexcept
{
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

template<class T>
uint64 dty::LProperty<T>::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

template<class T>
uint64 dty::LProperty<T>::GetHashCode()
{
    return (uint64)(this);
}