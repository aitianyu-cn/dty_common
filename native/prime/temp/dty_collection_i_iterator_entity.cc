/**
 * @file dty_collection_i_iterator_entity.cc(prime/temp)
 * @author victor.yao
 * @brief Implementation for Iterator Entity Interface template class
 * @version 0.1
 * @date 2021-12-22
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#include "../new_iterator.hpp"

template<class T>
dty::collection::IIteratorEntity<T>::IIteratorEntity(dty::IPropertyGetter<int32>& size)
    : dty::TianyuObject()
{
    this->Size = size;
}

template<class T>
::string dty::collection::IIteratorEntity<T>::ToString() noexcept
{
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

template<class T>
uint64 dty::collection::IIteratorEntity<T>::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}