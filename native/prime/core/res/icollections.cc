/**
 * @file dty_collection_i_collections.cc
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-23
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../icollections.hpp"

template<typename T>
dty::collection::ICollections<T>::ICollections(dty::IPropertyGetter<int32>& count)
    :dty::TianyuObject(), Count(count)
{ }

template<typename T>
dty::collection::ICollections<T>::~ICollections() { }