/**
 * @file dty_type.cc(native/core/ext)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-22
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#include "../utilize.hh"

template<typename T> bool dty::Type<T>::_dummy = false;

template<typename T>
dty::Type<T>::Type() : _Name(::null), _Id(0), _InstanceHash(0ULL) { }

template<typename T>
dty::Type<T>::Type(uint64 instance) : _Name(::null), _Id(0), _InstanceHash(instance) { }

template<typename T>
dty::Type<T>::Type(const dty::Type<T>& other)
    : _Name(::null), _Id(other._Id), _InstanceHash(other._InstanceHash)
{
    dty::Type<T>& copy = const_cast<dty::Type<T>&>(other);
    this->_Name = copy._Name;

    copy._Name = ::null;
}

template<typename T>
dty::Type<T>::~Type()
{
    if (::null != this->_Name)
        delete [](this->_Name);
}

template<typename T>
::string dty::Type<T>::Name() const
{
    return this->_Name;
}

template<typename T>
uint64 dty::Type<T>::Id()
{
    return this->_Id;
}

template<typename T>
uint64 dty::Type<T>::InstanceHashCode()
{
    return this->_InstanceHash;
}
