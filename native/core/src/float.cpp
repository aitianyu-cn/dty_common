#include "../basetype.hpp"
#include <math.h>

const float _dty_native_float_default_precision = 1e-5;
const float _dty_native_float_zero = 0.0;

#define __DOUBLE_OPERATE__(ret, type)                   \
    ret tianyu::Float::operator type(tianyu::Float & other) \
    {                                                   \
        return this->_Value type other._Value;          \
    }

#define __DOUBLE_EQ_OPERATE__(ret, type)                \
    ret tianyu::Float::operator type(tianyu::Float & other) \
    {                                                   \
        this->_Value = this->_Value type other._Value;  \
        return this->_Value;                            \
    }

tianyu::Float::Float()
    :tianyu::TianyuObject(), tianyu::collection::ICompareable<tianyu::Float>(),
    tianyu::collection::IEquatable<tianyu::Float>(), tianyu::IFormatter(),
    Precision(_dty_native_float_default_precision), _Value()
{ }

tianyu::Float::Float(float value)
    : tianyu::TianyuObject(), tianyu::collection::ICompareable<tianyu::Float>(),
    tianyu::collection::IEquatable<tianyu::Float>(), tianyu::IFormatter(),
    Precision(_dty_native_float_default_precision), _Value(value)
{ }

tianyu::Float::Float(float value, float precision)
    : tianyu::TianyuObject(), tianyu::collection::ICompareable<tianyu::Float>(),
    tianyu::collection::IEquatable<tianyu::Float>(), tianyu::IFormatter(),
    Precision(precision), _Value(value)
{ }

tianyu::Float::Float(const tianyu::Float& value)
    : tianyu::TianyuObject(), tianyu::collection::ICompareable<tianyu::Float>(),
    tianyu::collection::IEquatable<tianyu::Float>(), tianyu::IFormatter(),
    Precision(value.Precision), _Value(value._Value)
{ }

tianyu::Float::~Float() { }

::string tianyu::Float::ToString() noexcept
{
    return this->ToString(::null);
}

uint64 tianyu::Float::GetTypeId()
{
    return tianyu::GetType<tianyu::Float>().Id();
}

uint64 tianyu::Float::GetHashCode()
{
    return (uint64)(this);
}

::string tianyu::Float::ToString(const ::string formatter)
{
    return tianyu::FormatHelper::Format(this->_Value, formatter);
}

float tianyu::Float::Parse(const ::string s)
{
    float result;
    tianyu::ParseHelper::Parse(s, result);
    return result;
}

bool tianyu::Float::TryParse(const ::string s, float& result)
{
    try
    {
        tianyu::ParseHelper::Parse(s, result);
        return true;
    }
    catch (tianyu::except::Exception)
    {
        return false;
    }
}

bool tianyu::Float::TryParse(const ::string s, tianyu::Float& result)
{
    try
    {
        tianyu::ParseHelper::Parse(s, result._Value);
        return true;
    }
    catch (tianyu::except::Exception)
    {
        return false;
    }
}

bool tianyu::Float::Equals(tianyu::TianyuObject& obj)
{
    if (this->GetTypeId() != obj.GetTypeId())
        return false;

    tianyu::Float& cast_obj = dynamic_cast<tianyu::Float&>(obj);
    return this->Equals(cast_obj);
}

bool tianyu::Float::operator==(tianyu::TianyuObject& obj)
{
    return this->Equals(obj);
}

bool tianyu::Float::Equals(tianyu::Float& other)
{
    if (this->GetHashCode() == other.GetHashCode())
        return true;

    float sub = this->_Value - other._Value;
    sub = ::fabs(sub);
    return sub < this->Precision;
}

tianyu::collection::CompareResult tianyu::Float::CompareTo(tianyu::Float& other)
{
    if (this->Equals(other))
        return tianyu::collection::CompareResult::EQUAL;

    return (__PTR_TO_REF__ this) > other ? tianyu::collection::CompareResult::GREAT : tianyu::collection::CompareResult::LESS;
}

bool tianyu::Float::operator==(tianyu::Float& other)
{
    return this->Equals(other);
}

bool tianyu::Float::operator!=(tianyu::Float& other)
{
    return !this->Equals(other);
}

bool tianyu::Float::operator<(tianyu::Float& other)
{
    return !(__PTR_TO_REF__ this >= other);
}

bool tianyu::Float::operator>(tianyu::Float& other)
{
    return !(__PTR_TO_REF__ this <= other);
}

bool tianyu::Float::operator<=(tianyu::Float& other)
{
    if (__PTR_TO_REF__ this == other)
        return true;

    return this->_Value < other._Value;
}

bool tianyu::Float::operator>=(tianyu::Float& other)
{
    if (__PTR_TO_REF__ this == other)
        return true;

    return this->_Value > other._Value;
}

tianyu::Float::operator float()
{
    return this->_Value;
}

float tianyu::Float::operator++()
{
    this->_Value = this->_Value + 1.0;
    return this->_Value;
}

float tianyu::Float::operator--()
{
    this->_Value = this->_Value - 1.0;
    return this->_Value;
}

float tianyu::Float::operator++(int)
{
    float preValue = this->_Value;
    this->_Value = this->_Value + 1.0;
    return preValue;
}

float tianyu::Float::operator--(int)
{
    float preValue = this->_Value;
    this->_Value = this->_Value - 1.0;
    return preValue;
}

float tianyu::Float::operator =(tianyu::Float& other)
{
    this->_Value = other._Value;
    return this->_Value;
}

__DOUBLE_OPERATE__(float, +)
__DOUBLE_OPERATE__(float, -)
__DOUBLE_OPERATE__(float, *)
__DOUBLE_OPERATE__(float, / )

__DOUBLE_EQ_OPERATE__(float, +=)
__DOUBLE_EQ_OPERATE__(float, -=)
__DOUBLE_EQ_OPERATE__(float, *=)
__DOUBLE_EQ_OPERATE__(float, /=)