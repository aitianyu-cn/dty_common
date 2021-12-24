/**
 * @file property.cc
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-23
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../property.hpp"

#define __PROPERTY_TEMPLATE_DEF__ template<class T>
#define __TPROPERTY_DEF__ dty::Property<T>
#define __TLPROPERTY_DEF__ dty::LProperty<T>

 //
// ####################################################################################################
// Implementation for Property class
// ####################################################################################################

__PROPERTY_TEMPLATE_DEF__ __TPROPERTY_DEF__::Property() :dty::TianyuObject(), _Elem() { }

__PROPERTY_TEMPLATE_DEF__ __TPROPERTY_DEF__::Property(T value) : dty::TianyuObject(), _Elem(value) { }

__PROPERTY_TEMPLATE_DEF__ __TPROPERTY_DEF__::~Property() { }

__PROPERTY_TEMPLATE_DEF__ T __TPROPERTY_DEF__::Get()
{
    return this->_Elem;
}

__PROPERTY_TEMPLATE_DEF__ void __TPROPERTY_DEF__::Set(T value)
{
    this->_Elem = value;
}

__PROPERTY_TEMPLATE_DEF__ __TPROPERTY_DEF__::operator T()
{
    return this->_Elem;
}

__PROPERTY_TEMPLATE_DEF__ T __TPROPERTY_DEF__::operator=(T value)
{
    this->_Elem = value;
    return value;
}

__PROPERTY_TEMPLATE_DEF__ T __TPROPERTY_DEF__::operator=(dty::IPropertyGetter<T>& value)
{
    this->_Elem = value;
    return value;
}

__PROPERTY_TEMPLATE_DEF__::string __TPROPERTY_DEF__::ToString() noexcept
{
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

__PROPERTY_TEMPLATE_DEF__ uint64 __TPROPERTY_DEF__::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

__PROPERTY_TEMPLATE_DEF__ uint64 __TPROPERTY_DEF__::GetHashCode()
{
    return (uint64)(this);
}

// ####################################################################################################
// Implementation for Lambda Property class
// ####################################################################################################

__PROPERTY_TEMPLATE_DEF__ __TLPROPERTY_DEF__::LProperty
(
    __TLPROPERTY_DEF__::PropertyGetDelegate getter,
    __TLPROPERTY_DEF__::PropertySetDelegate setter
) : dty::TianyuObject(), _Getter(getter), _Setter(setter) { }

__PROPERTY_TEMPLATE_DEF__ __TLPROPERTY_DEF__::~LProperty() { }

__PROPERTY_TEMPLATE_DEF__ T __TLPROPERTY_DEF__::Get()
{
    return this->_Getter();
}

__PROPERTY_TEMPLATE_DEF__ void __TLPROPERTY_DEF__::Set(T value)
{
    this->_Setter(value);
}

__PROPERTY_TEMPLATE_DEF__ __TLPROPERTY_DEF__::operator T()
{
    return this->_Getter();
}

__PROPERTY_TEMPLATE_DEF__ T __TLPROPERTY_DEF__::operator=(T value)
{
    this->_Setter(value);

    return this->_Getter();
}

__PROPERTY_TEMPLATE_DEF__ T __TLPROPERTY_DEF__::operator=(dty::IPropertyGetter<T>& value)
{
    this->_Setter(value);

    return this->_Getter();
}

__PROPERTY_TEMPLATE_DEF__::string __TLPROPERTY_DEF__::ToString() noexcept
{
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

__PROPERTY_TEMPLATE_DEF__ uint64 __TLPROPERTY_DEF__::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

__PROPERTY_TEMPLATE_DEF__ uint64 __TLPROPERTY_DEF__::GetHashCode()
{
    return (uint64)(this);
}

// to cancel the macro definitions
#undef __PROPERTY_TEMPLATE_DEF__
#undef __TPROPERTY_DEF__
#undef __TLPROPERTY_DEF__