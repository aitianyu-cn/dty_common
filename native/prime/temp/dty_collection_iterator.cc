/**
 * @file dty_collection_iterator.cc(prime/temp)
 * @author victor.yao
 * @brief Implementation for Iterator template class
 * @version 0.1
 * @date 2021-12-22
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#include "../new_iterator.hpp"

template<class T>
dty::collection::Iterator<T>::Iterator(dty::collection::IIteratorEntity<T>& entity)
    : dty::TianyuObject(), _Entity(entity), _CurrentIndex(0)
{ }

template<class T>
dty::collection::Iterator<T>::Iterator(const dty::collection::Iterator<T>& iterator)
    : dty::TianyuObject(), _Entity(iterator._Entity), _CurrentIndex(iterator._CurrentIndex)
{ }

template<class T>
dty::collection::Iterator<T>::~Iterator() { }

template<class T>
void dty::collection::Iterator<T>::Reset()
{
    this->_CurrentIndex = 0;
}

template<class T>
void dty::collection::Iterator<T>::Reset()
{
    this->_CurrentIndex = 0;
}

template<class T>
dty::collection::Iterator<T>::T_SP dty::collection::Iterator<T>::Current()
{
    return this->_Entity.Get(this->_CurrentIndex);
}

template<class T>
dty::collection::Iterator<T>::T_SP dty::collection::Iterator<T>::Next()
{
    // anyway, move to the next
    this->_CurrentIndex = this->_CurrentIndex + 1;

    return this->_Entity.Get(this->_CurrentIndex);
}

template<class T>
dty::collection::Iterator<T>::T_SP dty::collection::Iterator<T>::End()
{
    return this->_Entity.End();
}

template<class T>
void dty::collection::Iterator<T>::ForEach(dty::collection::Iterator<T>::ItemMapDelegate delegate)
{
    this->_Entity.ForEach(delegate);
}

template<class T>
T* dty::collection::Iterator<T>::Some(dty::collection::Iterator<T>::ItemChkDelegate delegate)
{
    return this->_Entity.Some(delegate);
}

template<class T>
dty::collection::Iterator<T>::T_FR dty::collection::Iterator<T>::Filter(dty::collection::Iterator<T>::ItemChkDelegate delegate)
{
    return this->_Entity.Filter(delegate);
}

template<class T>
dty::collection::Iterator<T>::T_FR dty::collection::Iterator<T>::Every(dty::collection::Iterator<T>::ItemChkDelegate delegate)
{
    return this->_Entity.Every(delegate);
}

template<class T>
T* dty::collection::Iterator<T>::Find(dty::collection::Iterator<T>::ItemChkDelegate delegate)
{
    return this->_Entity.Find(delegate);
}

template<class T>
int32 dty::collection::Iterator<T>::FindIndex(dty::collection::Iterator<T>::ItemChkDelegate delegate)
{
    return this->_Entity.FindIndex(delegate);
}

template<class T>
::string dty::collection::Iterator<T>::ToString() noexcept
{
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

template<class T>
uint64 dty::collection::Iterator<T>::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

template<class T>
uint64 dty::collection::Iterator<T>::GetHashCode()
{
    return this->_Entity.GetHashCode();
}
