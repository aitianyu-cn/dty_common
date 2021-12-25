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

#define __TEMPLATE_DEF__ template<typename K, typename V>
#define __KEY_VAL_DEF__ dty::KeyValuePair<K, V>

__TEMPLATE_DEF__ __construction__ __KEY_VAL_DEF__::KeyValuePair(K key, V val) :
    dty::TianyuObject(),
    Key(key),
    Value(val)
{

}

__TEMPLATE_DEF__ __cp_construct__ __KEY_VAL_DEF__::KeyValuePair(const __KEY_VAL_DEF__& other) :
    dty::TianyuObject(),
    Key(other.Key),
    Value(other.Value)
{ }

__TEMPLATE_DEF__ __destruction__  __KEY_VAL_DEF__::~KeyValuePair() { }

__TEMPLATE_DEF__::string __KEY_VAL_DEF__::ToString() noexcept
{
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

__TEMPLATE_DEF__ uint64 __KEY_VAL_DEF__::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

__TEMPLATE_DEF__ uint64 __KEY_VAL_DEF__::GetHashCode()
{
    return  (uint64)(this);
}

// to cancel the macro definitions
#undef __TEMPLATE_DEF__
#undef __KEY_VAL_DEF__