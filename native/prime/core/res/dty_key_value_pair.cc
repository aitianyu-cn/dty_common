/**
 * @file dty_key_value_pair.cc
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-23
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../internal.h"

#include <type_traits>

template<typename K, typename V>
dty::KeyValuePair<K, V>::KeyValuePair(K key, V val)
    : dty::TianyuObject(), Key(key), Value(val)
{
    static_assert(std::is_base_of<dty::TianyuObject, K>::value, "require dty::TianyuObject or its child class as Key");
}

template<typename K, typename V>
dty::KeyValuePair<K, V>::KeyValuePair(const dty::KeyValuePair<K, V>& other)
    : dty::TianyuObject(), Key(other.Key), Value(other.Value)
{ }

template<typename K, typename V>
dty::KeyValuePair<K, V>::~KeyValuePair() { }

template<typename K, typename V>
::string dty::KeyValuePair<K, V>::ToString() noexcept
{
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

template<typename K, typename V>
uint64 dty::KeyValuePair<K, V>::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

template<typename K, typename V>
uint64 dty::KeyValuePair<K, V>::GetHashCode()
{
    return  (uint64)(this);
}