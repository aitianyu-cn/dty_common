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

// import implementation of Property and LProperty
#include "./res/property.cc"

#endif // !__cplusplus

#endif // !__DTY_COMMON_NATIVE_PRIME_CORE_PROPERTY_H_PLUS_PLUS__