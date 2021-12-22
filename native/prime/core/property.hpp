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
    _interface IPropertyGetter : public virtual TianyuObject
    {
        __PUB__ virtual ~IPropertyGetter() { }

        __PUB__ virtual T __VARIABLE__ Get() = 0;

        __PUB__ virtual operator T() = 0;
    };

    template<class T>
    _interface IPropertySetter : public virtual TianyuObject
    {
        __PUB__ virtual ~IPropertySetter() { }

        __PUB__ virtual void __VARIABLE__ Set(T __VARIABLE__ value) = 0;
        __PUB__ virtual T    __VARIABLE__ operator =(T __VARIABLE__ value) = 0;
    };

    template<class T>
    _interface IProperty
        : public virtual TianyuObject,
        public virtual IPropertyGetter<T>,
        public virtual IPropertySetter<T>
    {
        __PUB__ virtual ~IProperty() override { }
    };

    template<class T>
    class Property final : public virtual TianyuObject, public virtual IProperty<T>
    {
        __PRI__ T __VARIABLE__ _Elem;

        __PUB__ Property() : TianyuObject(), IProperty<T>(), _Elem() { }
        __PUB__ Property(T __VARIABLE__ value) : TianyuObject(), IProperty<T>(), _Elem(value) { }
        __PUB__ virtual ~Property() override { }

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override
        {
            return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
        }
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() override
        {
            return dty::GetType(__PTR_TO_REF__ this).Id();
        }

        __PUB__ virtual T    __VARIABLE__ Get() override
        {
            return this->_Elem;
        }
        __PUB__ virtual void __VARIABLE__ Set(T __VARIABLE__ value) override
        {
            this->_Elem = value;
        }

        __PUB__ virtual operator T() override
        {
            return this->_Elem;
        }
        __PUB__ virtual T __VARIABLE__ operator =(T __VARIABLE__ value) override
        {
            this->_Elem = value;
            return this->_Elem;
        }
    };

    // template<class T>
    // class CProperty final : public IProperty<T>
    // {
    //     __PUB__ using PropertyGetDelegate = T    __VARIABLE__(__POINTER__)();
    //     __PUB__ using PropertySetDelegate = void __VARIABLE__(__POINTER__)(T __VARIABLE__ value);

    //     __PUB__ CProperty(PropertyGetDelegate __VARIABLE__ getter, PropertySetDelegate __VARIABLE__ setter)
    //     {

    //     }
    //     __PUB__ virtual ~CProperty() override { }

    //     __PUB__ virtual T    __VARIABLE__ Get() override
    //     {
    //         return this->_Elem;
    //     }
    //     __PUB__ virtual void __VARIABLE__ Set(T __VARIABLE__ value) override
    //     {
    //         this->_Elem = value;
    //     }

    //     __PUB__ virtual operator T() override
    //     {
    //         return this->_Elem;
    //     }
    //     __PUB__ virtual T __VARIABLE__ operator =(T __VARIABLE__ value) override
    //     {
    //         this->_Elem = value;
    //         return this->_Elem;
    //     }
    // };
}

#endif // !__cplusplus

#endif // !__DTY_COMMON_NATIVE_PRIME_CORE_PROPERTY_H_PLUS_PLUS__