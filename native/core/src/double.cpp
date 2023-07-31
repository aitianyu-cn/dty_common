#include "../basetype.hpp"
#include <math.h>

const double _dty_native_double_default_precision = 1e-10;
const double _dty_native_double_zero = 0.0;

#define __DOUBLE_OPERATE__(ret, type)                         \
    ret tianyu::Double::operator type(tianyu::Double & other) \
    {                                                         \
        return this->_Value type other._Value;                \
    }

#define __DOUBLE_EQ_OPERATE__(ret, type)                      \
    ret tianyu::Double::operator type(tianyu::Double & other) \
    {                                                         \
        this->_Value = this->_Value type other._Value;        \
        return this->_Value;                                  \
    }

tianyu::Double::Double()
    :tianyu::TianyuObject(), tianyu::collection::ICompareable<tianyu::Double>(),
    tianyu::collection::IEquatable<tianyu::Double>(), tianyu::IFormatter(),
    Precision(_dty_native_double_default_precision), _Value()
{ }

tianyu::Double::Double(double value)
    : tianyu::TianyuObject(), tianyu::collection::ICompareable<tianyu::Double>(),
    tianyu::collection::IEquatable<tianyu::Double>(), tianyu::IFormatter(),
    Precision(_dty_native_double_default_precision), _Value(value)
{ }

tianyu::Double::Double(double value, double precision)
    : tianyu::TianyuObject(), tianyu::collection::ICompareable<tianyu::Double>(),
    tianyu::collection::IEquatable<tianyu::Double>(), tianyu::IFormatter(),
    Precision(precision), _Value(value)
{ }

tianyu::Double::Double(const tianyu::Double& value)
    : tianyu::TianyuObject(), tianyu::collection::ICompareable<tianyu::Double>(),
    tianyu::collection::IEquatable<tianyu::Double>(), tianyu::IFormatter(),
    Precision(value.Precision), _Value(value._Value)
{ }

tianyu::Double::~Double() { }

::string tianyu::Double::ToString() noexcept
{
    return this->ToString((::string)"");
}

uint64 tianyu::Double::GetTypeId()
{
    return tianyu::GetType<tianyu::Double>().Id();
}

uint64 tianyu::Double::GetHashCode()
{
    return (uint64)(this);
}

::string tianyu::Double::ToString(const ::string formatter)
{
    return tianyu::FormatHelper::Format(this->_Value, formatter);
}

double tianyu::Double::Parse(const ::string s)
{
    double result;
    tianyu::ParseHelper::Parse(s, result);
    return result;
}

bool tianyu::Double::TryParse(const ::string s, double& result)
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

bool tianyu::Double::TryParse(const ::string s, tianyu::Double& result)
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

bool tianyu::Double::Equals(tianyu::TianyuObject& obj)
{
    if (this->GetTypeId() != obj.GetTypeId())
        return false;

    tianyu::Double& cast_obj = dynamic_cast<tianyu::Double&>(obj);
    return this->Equals(cast_obj);
}

bool tianyu::Double::operator==(tianyu::TianyuObject& obj)
{
    return this->Equals(obj);
}

bool tianyu::Double::Equals(tianyu::Double& other)
{
    if (this->GetHashCode() == other.GetHashCode())
        return true;

    double sub = this->_Value - other._Value;
    sub = ::fabs(sub);
    return sub < this->Precision;
}

tianyu::collection::CompareResult tianyu::Double::CompareTo(tianyu::Double& other)
{
    if (this->Equals(other))
        return tianyu::collection::CompareResult::EQUAL;

    return (__PTR_TO_REF__ this) > other ? tianyu::collection::CompareResult::GREAT : tianyu::collection::CompareResult::LESS;
}

bool tianyu::Double::operator==(tianyu::Double& other)
{
    return this->Equals(other);
}

bool tianyu::Double::operator!=(tianyu::Double& other)
{
    return !this->Equals(other);
}

bool tianyu::Double::operator<(tianyu::Double& other)
{
    return !(__PTR_TO_REF__ this >= other);
}

bool tianyu::Double::operator>(tianyu::Double& other)
{
    return !(__PTR_TO_REF__ this <= other);
}

bool tianyu::Double::operator<=(tianyu::Double& other)
{
    if (__PTR_TO_REF__ this == other)
        return true;

    return this->_Value < other._Value;
}

bool tianyu::Double::operator>=(tianyu::Double& other)
{
    if (__PTR_TO_REF__ this == other)
        return true;

    return this->_Value > other._Value;
}

tianyu::Double::operator double()
{
    return this->_Value;
}

double tianyu::Double::operator++()
{
    this->_Value = this->_Value + 1.0;
    return this->_Value;
}

double tianyu::Double::operator--()
{
    this->_Value = this->_Value - 1.0;
    return this->_Value;
}

double tianyu::Double::operator++(int)
{
    double preValue = this->_Value;
    this->_Value = this->_Value + 1.0;
    return preValue;
}

double tianyu::Double::operator--(int)
{
    double preValue = this->_Value;
    this->_Value = this->_Value - 1.0;
    return preValue;
}

double tianyu::Double::operator =(tianyu::Double& other)
{
    this->_Value = other._Value;
    return this->_Value;
}

__DOUBLE_OPERATE__(double, +)
__DOUBLE_OPERATE__(double, -)
__DOUBLE_OPERATE__(double, *)
__DOUBLE_OPERATE__(double, / )

__DOUBLE_EQ_OPERATE__(double, +=)
__DOUBLE_EQ_OPERATE__(double, -=)
__DOUBLE_EQ_OPERATE__(double, *=)
__DOUBLE_EQ_OPERATE__(double, /=)