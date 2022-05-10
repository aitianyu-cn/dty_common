/**
 * @file property.hpp(prime/core)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-16
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_CORE_PROPERTY_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_CORE_PROPERTY_H_PLUS_PLUS__

#ifdef __cplusplus

#include "./internal.h"

namespace dty
{
    template<class T>
    _interface IPropertyGetter : public virtual dty::TianyuObject
    {
        __PUB__ virtual ~IPropertyGetter() __override_func { }

        __PUB__ virtual T __VARIABLE__ Get()      __pure_virtual_fun;
        __PUB__ virtual operator T __VARIABLE__() __pure_virtual_fun;
    };

    template<class T>
    _interface IPropertySetter : public virtual dty::TianyuObject
    {
        __PUB__ virtual ~IPropertySetter() __override_func { }

        __PUB__ virtual void __VARIABLE__ Set(T __VARIABLE__ value)                          __pure_virtual_fun;
        __PUB__ virtual T    __VARIABLE__ operator =(T __VARIABLE__ value)                   __pure_virtual_fun;
        __PUB__ virtual T    __VARIABLE__ operator =(IPropertyGetter<T> __REFERENCE__ value) __pure_virtual_fun;
    };

    template<class T>
    _interface IProperty
        : public virtual dty::TianyuObject,
        public virtual dty::IPropertyGetter<T>,
        public virtual dty::IPropertySetter<T>
    {
        __PUB__ virtual ~IProperty() __override_func { }
    };

    template<class T>
    class Property final :
        public virtual dty::TianyuObject,
        public virtual dty::IProperty<T>
    {
        __PRI__ T __VARIABLE__ _Elem;

        __PUB__         Property();
        __PUB__         Property(T __VARIABLE__ value);
        __PUB__ virtual ~Property() __override_func;

        __PUB__ virtual T    __VARIABLE__ Get()                     __override_func;
        __PUB__ virtual void __VARIABLE__ Set(T __VARIABLE__ value) __override_func;

        __PUB__ virtual                operator T __VARIABLE__()                          __override_func;
        __PUB__ virtual T __VARIABLE__ operator =(T __VARIABLE__ value)                   __override_func;
        __PUB__ virtual T __VARIABLE__ operator =(IPropertyGetter<T> __REFERENCE__ value) __override_func;

        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;
    };

    template<class T>
    class LProperty final :
        public virtual dty::TianyuObject,
        public virtual dty::IProperty<T>
    {
        __PUB__ using PropertyGetDelegate = T    __VARIABLE__(__POINTER__)();
        __PUB__ using PropertySetDelegate = void __VARIABLE__(__POINTER__)(T __VARIABLE__ value);

        __PRI__ PropertyGetDelegate __VARIABLE__ _Getter;
        __PRI__ PropertySetDelegate __VARIABLE__ _Setter;

        __PUB__         LProperty(PropertyGetDelegate __VARIABLE__ getter, PropertySetDelegate __VARIABLE__ setter);
        __PUB__         LProperty(const LProperty<T> __REFERENCE__ lp);
        __PUB__ virtual ~LProperty() __override_func;

        __PUB__ virtual T    __VARIABLE__ Get()                     __override_func;
        __PUB__ virtual void __VARIABLE__ Set(T __VARIABLE__ value) __override_func;

        __PUB__ virtual                operator T __VARIABLE__()                          __override_func;
        __PUB__ virtual T __VARIABLE__ operator =(T __VARIABLE__ value)                   __override_func;
        __PUB__ virtual T __VARIABLE__ operator =(IPropertyGetter<T> __REFERENCE__ value) __override_func;

        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;
    };
}

#pragma region template realization

// ##########################################################
// Properties Implementation
// ##########################################################

#define __PROPERTY_TEMPLATE_DEF__ template<class T>
#define __TPROPERTY_DEF__ dty::Property<T>
#define __TLPROPERTY_DEF__ dty::LProperty<T>

// ####################################################################################################
// Implementation for Property class
// ####################################################################################################

__PROPERTY_TEMPLATE_DEF__ __construction__ __TPROPERTY_DEF__::Property() :
    dty::TianyuObject(),
    _Elem()
{ }

__PROPERTY_TEMPLATE_DEF__ __construction__ __TPROPERTY_DEF__::Property(T value) :
    dty::TianyuObject(),
    _Elem(value)
{ }

__PROPERTY_TEMPLATE_DEF__ __destruction__  __TPROPERTY_DEF__::~Property()
{ }

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

__PROPERTY_TEMPLATE_DEF__ __construction__ __TLPROPERTY_DEF__::LProperty
(
    __TLPROPERTY_DEF__::PropertyGetDelegate getter,
    __TLPROPERTY_DEF__::PropertySetDelegate setter
) :
    dty::TianyuObject(),
    _Getter(getter),
    _Setter(setter)
{ }

__PROPERTY_TEMPLATE_DEF__ __destruction__  __TLPROPERTY_DEF__::~LProperty()
{ }

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

#pragma endregion

#endif // !__cplusplus

#endif // !__DTY_COMMON_NATIVE_PRIME_CORE_PROPERTY_H_PLUS_PLUS__