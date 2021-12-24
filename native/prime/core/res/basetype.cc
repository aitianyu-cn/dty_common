/**
 * @file dty_t_integer_base.cc
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../basetype.hpp"
#include "../error.hpp"
#include <type_traits>

#define __TEMPLATE_DEF__ template<class TB, TB _Max, TB _Min>
#define __TINTEGER_DEF__ dty::TIntegerBase<TB, _Max, _Min>

#define __OPERATOR_OVERRIDE_DEF__(ret, type)                                    \
    __TEMPLATE_DEF__ ret __TINTEGER_DEF__::operator type(__TINTEGER_DEF__& obj) \
    {                                                                           \
        return this->_Value type obj->_Value;                                   \
    }

#define __OPERATOR_EQ_OVERRIDE_DEF__(ret, type)                                 \
    __TEMPLATE_DEF__ ret __TINTEGER_DEF__::operator type(__TINTEGER_DEF__& obj) \
    {                                                                           \
        this->_Value = this->_Value type obj->_Value;                           \
        return this->_Value;                                                    \
    }

#define __STATIC_ASSERT_DEF__                       \
    static_assert(                                  \
        std::is_base_of<char, TB>::value            \
        || std::is_base_of<uchar, T>::value         \
        || std::is_base_of<int16, T>::value         \
        || std::is_base_of<uint16, T>::value        \
        || std::is_base_of<int32, T>::value         \
        || std::is_base_of<uint32, T>::value        \
        || std::is_base_of<int64, T>::value         \
        || std::is_base_of<uint64, T>::value,       \
        "only basic value data type is supported"   \
    )

__TEMPLATE_DEF__ __TINTEGER_DEF__::TIntegerBase()
    : dty::TianyuObject(),
    dty::collection::ICompareable<TIntegerBase<TB, _Max, _Min>>(),
    dty::collection::IEquatable<TIntegerBase<TB, _Max, _Min>>(),
    dty::IFormatter(), _Value()
{
    __STATIC_ASSERT_DEF__;
}

__TEMPLATE_DEF__ __TINTEGER_DEF__::TIntegerBase(TB value)
    : dty::TianyuObject(),
    dty::collection::ICompareable<TIntegerBase<TB, _Max, _Min>>(),
    dty::collection::IEquatable<TIntegerBase<TB, _Max, _Min>>(),
    dty::IFormatter(), _Value(value)
{
    __STATIC_ASSERT_DEF__;
}

__TEMPLATE_DEF__ __TINTEGER_DEF__::TIntegerBase(TB value)
    : dty::TianyuObject(),
    dty::collection::ICompareable<TIntegerBase<TB, _Max, _Min>>(),
    dty::collection::IEquatable<TIntegerBase<TB, _Max, _Min>>(),
    dty::IFormatter(), _Value(value)
{
    __STATIC_ASSERT_DEF__;
}

__TEMPLATE_DEF__ __TINTEGER_DEF__::TIntegerBase(const __TINTEGER_DEF__& value)
    : dty::TianyuObject(),
    dty::collection::ICompareable<TIntegerBase<TB, _Max, _Min>>(),
    dty::collection::IEquatable<TIntegerBase<TB, _Max, _Min>>(),
    dty::IFormatter(), _Value(value._Value)
{ }

__TEMPLATE_DEF__ __TINTEGER_DEF__::~TIntegerBase() { }

__TEMPLATE_DEF__ bool __TINTEGER_DEF__::Equals(dty::TianyuObject& obj)
{
    if (this->GetTypeId() != obj.GetTypeId())
        return false;

    __TINTEGER_DEF__& cast_obj = dynamic_cast<__TINTEGER_DEF__&>(obj);
    return this->Equals(cast_obj);
}

__TEMPLATE_DEF__ bool __TINTEGER_DEF__::operator==(dty::TianyuObject& obj)
{
    return this->Equals(obj);
}

__TEMPLATE_DEF__ bool __TINTEGER_DEF__::Equals(__TINTEGER_DEF__& obj)
{
    return this->_Value == obj->_Value;
}

__TEMPLATE_DEF__ __TINTEGER_DEF__::operator TB()
{
    return this->_Value;
}

__TEMPLATE_DEF__ TB __TINTEGER_DEF__::operator++()
{
    this->_Value = this->_Value + 1;
    return this->_Value;
}

__TEMPLATE_DEF__ TB __TINTEGER_DEF__::operator--()
{
    this->_Value = this->_Value - 1;
    return this->_Value;
}

__TEMPLATE_DEF__ TB __TINTEGER_DEF__::operator++(int)
{
    TB preValue = this->_Value;
    this->_Value = this->_Value + 1;
    return preValue;
}

__TEMPLATE_DEF__ TB __TINTEGER_DEF__::operator--(int)
{
    TB preValue = this->_Value;
    this->_Value = this->_Value - 1;
    return preValue;
}

__TEMPLATE_DEF__ TB __TINTEGER_DEF__::operator!()
{
    return !(this->_Value);
}

__TEMPLATE_DEF__ TB __TINTEGER_DEF__::operator~()
{
    return ~(this->_Value);
}

__TEMPLATE_DEF__ TB __TINTEGER_DEF__::operator=(__TINTEGER_DEF__& obj)
{
    this->_Value = obj._Value;
    return this->_Value;
}

__TEMPLATE_DEF__::string __TINTEGER_DEF__::ToString() noexcept
{
    //return dty::FormatHelper::Format(this->_Value, ::null);
    return this->ToString(::null);
}

__TEMPLATE_DEF__ uint64 __TINTEGER_DEF__::GetTypeId()
{
    return dty::GetType<TB>().Id();
}

__TEMPLATE_DEF__ uint64 __TINTEGER_DEF__::GetHashCode()
{
    return (uint64)(this);
}

__TEMPLATE_DEF__::string __TINTEGER_DEF__::ToString(const ::string formatter)
{
    return dty::FormatHelper::Format(this->_Value, formatter);
}

__TEMPLATE_DEF__ TB __TINTEGER_DEF__::Parse(const ::string s)
{
    TB value;

    dty::ParseHelper::Parse(s, value);

    return value;
}

__TEMPLATE_DEF__ bool __TINTEGER_DEF__::TryParse(const ::string s, TB& result)
{
    try
    {
        dty::ParseHelper::Parse(s, result);

        return true;
    }
    catch (const dty::except::Exception&)
    {
        return false;
    }
}

__TEMPLATE_DEF__ bool __TINTEGER_DEF__::TryParse(const ::string s, __TINTEGER_DEF__& result)
{
    try
    {
        dty::ParseHelper::Parse(s, result._Value);

        return true;
    }
    catch (const dty::except::Exception&)
    {
        return false;
    }
}

// implement some operator by macro define
// because they have the totally same structure
__OPERATOR_OVERRIDE_DEF__(bool, == )
__OPERATOR_OVERRIDE_DEF__(bool, != )
__OPERATOR_OVERRIDE_DEF__(bool, <= )
__OPERATOR_OVERRIDE_DEF__(bool, >= )
__OPERATOR_OVERRIDE_DEF__(bool, > )
__OPERATOR_OVERRIDE_DEF__(bool, < );

//
__OPERATOR_OVERRIDE_DEF__(TB, +)
__OPERATOR_OVERRIDE_DEF__(TB, -)
__OPERATOR_OVERRIDE_DEF__(TB, *)
__OPERATOR_OVERRIDE_DEF__(TB, / )
__OPERATOR_OVERRIDE_DEF__(TB, %)
__OPERATOR_OVERRIDE_DEF__(TB, &)
__OPERATOR_OVERRIDE_DEF__(TB, | )
__OPERATOR_OVERRIDE_DEF__(TB, ^)
__OPERATOR_OVERRIDE_DEF__(TB, << )
__OPERATOR_OVERRIDE_DEF__(TB, >> )

__OPERATOR_EQ_OVERRIDE_DEF__(TB, +=)
__OPERATOR_EQ_OVERRIDE_DEF__(TB, -=)
__OPERATOR_EQ_OVERRIDE_DEF__(TB, *=)
__OPERATOR_EQ_OVERRIDE_DEF__(TB, /=)
__OPERATOR_EQ_OVERRIDE_DEF__(TB, %=)
__OPERATOR_EQ_OVERRIDE_DEF__(TB, &=)
__OPERATOR_EQ_OVERRIDE_DEF__(TB, |=)
__OPERATOR_EQ_OVERRIDE_DEF__(TB, ^=)
__OPERATOR_EQ_OVERRIDE_DEF__(TB, >>=)
__OPERATOR_EQ_OVERRIDE_DEF__(TB, <<=)

// to cancel the macro definitions
#undef __TEMPLATE_DEF__
#undef __TINTEGER_DEF__

#undef __OPERATOR_OVERRIDE_DEF__
#undef __OPERATOR_EQ_OVERRIDE_DEF__
#undef __STATIC_ASSERT_DEF__