#include "../basetype.hpp"
#include <math.h>

const float _dty_native_float_default_precision = 1e-5;
const float _dty_native_float_zero = 0.0;

#define __DOUBLE_OPERATE__(ret, type)                   \
    ret dty::Float::operator type(dty::Float & other) \
    {                                                   \
        return this->_Value type other._Value;          \
    }

#define __DOUBLE_EQ_OPERATE__(ret, type)                \
    ret dty::Float::operator type(dty::Float & other) \
    {                                                   \
        this->_Value = this->_Value type other._Value;  \
        return this->_Value;                            \
    }

dty::Float::Float()
    :dty::TianyuObject(), dty::collection::ICompareable<dty::Float>(),
    dty::collection::IEquatable<dty::Float>(), dty::IFormatter(),
    Precision(_dty_native_float_default_precision), _Value()
{ }

dty::Float::Float(float value)
    : dty::TianyuObject(), dty::collection::ICompareable<dty::Float>(),
    dty::collection::IEquatable<dty::Float>(), dty::IFormatter(),
    Precision(_dty_native_float_default_precision), _Value(value)
{ }

dty::Float::Float(float value, float precision)
    : dty::TianyuObject(), dty::collection::ICompareable<dty::Float>(),
    dty::collection::IEquatable<dty::Float>(), dty::IFormatter(),
    Precision(precision), _Value(value)
{ }

dty::Float::Float(const dty::Float& value)
    : dty::TianyuObject(), dty::collection::ICompareable<dty::Float>(),
    dty::collection::IEquatable<dty::Float>(), dty::IFormatter(),
    Precision(value.Precision), _Value(value._Value)
{ }

dty::Float::~Float() { }

::string dty::Float::ToString() noexcept
{
    return this->ToString(::null);
}

uint64 dty::Float::GetTypeId()
{
    return dty::GetType<dty::Float>().Id();
}

uint64 dty::Float::GetHashCode()
{
    return (uint64)(this);
}

::string dty::Float::ToString(const ::string formatter)
{
    return dty::FormatHelper::Format(this->_Value, formatter);
}

float dty::Float::Parse(const ::string s)
{
    float result;
    dty::ParseHelper::Parse(s, result);
    return result;
}

bool dty::Float::TryParse(const ::string s, float& result)
{
    try
    {
        dty::ParseHelper::Parse(s, result);
        return true;
    }
    catch (dty::except::Exception)
    {
        return false;
    }
}

bool dty::Float::TryParse(const ::string s, dty::Float& result)
{
    try
    {
        dty::ParseHelper::Parse(s, result._Value);
        return true;
    }
    catch (dty::except::Exception)
    {
        return false;
    }
}

bool dty::Float::Equals(dty::TianyuObject& obj)
{
    if (this->GetTypeId() != obj.GetTypeId())
        return false;

    dty::Float& cast_obj = dynamic_cast<dty::Float&>(obj);
    return this->Equals(cast_obj);
}

bool dty::Float::operator==(dty::TianyuObject& obj)
{
    return this->Equals(obj);
}

bool dty::Float::Equals(dty::Float& other)
{
    float sub = this->_Value - other._Value;
    sub = ::fabs(sub);
    return sub < this->Precision;
}

bool dty::Float::operator==(dty::Float& other)
{
    return this->Equals(other);
}

bool dty::Float::operator<(dty::Float& other)
{
    return !(*this >= other);
}

bool dty::Float::operator>(dty::Float& other)
{
    return !(*this <= other);
}

bool dty::Float::operator<=(dty::Float& other)
{
    if (*this == other)
        return true;

    return this->_Value < other._Value;
}

bool dty::Float::operator>=(dty::Float& other)
{
    if (*this == other)
        return true;

    return this->_Value > other._Value;
}

dty::Float::operator float()
{
    return this->_Value;
}

float dty::Float::operator++()
{
    this->_Value = this->_Value + 1.0;
    return this->_Value;
}

float dty::Float::operator--()
{
    this->_Value = this->_Value - 1.0;
    return this->_Value;
}

float dty::Float::operator++(int)
{
    float preValue = this->_Value;
    this->_Value = this->_Value + 1.0;
    return preValue;
}

float dty::Float::operator--(int)
{
    float preValue = this->_Value;
    this->_Value = this->_Value - 1.0;
    return preValue;
}

float dty::Float::operator =(dty::Float& other)
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