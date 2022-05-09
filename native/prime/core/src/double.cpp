#include "../basetype.hpp"
#include <math.h>

const double _dty_native_double_default_precision = 1e-10;
const double _dty_native_double_zero = 0.0;

#define __DOUBLE_OPERATE__(ret, type)                   \
    ret dty::Double::operator type(dty::Double & other) \
    {                                                   \
        return this->_Value type other._Value;          \
    }

#define __DOUBLE_EQ_OPERATE__(ret, type)                \
    ret dty::Double::operator type(dty::Double & other) \
    {                                                   \
        this->_Value = this->_Value type other._Value;  \
        return this->_Value;                            \
    }

dty::Double::Double()
    :dty::TianyuObject(), dty::collection::ICompareable<dty::Double>(),
    dty::collection::IEquatable<dty::Double>(), dty::IFormatter(),
    Precision(_dty_native_double_default_precision), _Value()
{ }

dty::Double::Double(double value)
    : dty::TianyuObject(), dty::collection::ICompareable<dty::Double>(),
    dty::collection::IEquatable<dty::Double>(), dty::IFormatter(),
    Precision(_dty_native_double_default_precision), _Value(value)
{ }

dty::Double::Double(double value, double precision)
    : dty::TianyuObject(), dty::collection::ICompareable<dty::Double>(),
    dty::collection::IEquatable<dty::Double>(), dty::IFormatter(),
    Precision(precision), _Value(value)
{ }

dty::Double::Double(const dty::Double& value)
    : dty::TianyuObject(), dty::collection::ICompareable<dty::Double>(),
    dty::collection::IEquatable<dty::Double>(), dty::IFormatter(),
    Precision(value.Precision), _Value(value._Value)
{ }

dty::Double::~Double() { }

::string dty::Double::ToString() noexcept
{
    return this->ToString(::null);
}

uint64 dty::Double::GetTypeId()
{
    return dty::GetType<dty::Double>().Id();
}

uint64 dty::Double::GetHashCode()
{
    return (uint64)(this);
}

::string dty::Double::ToString(const ::string formatter)
{
    return dty::FormatHelper::Format(this->_Value, formatter);
}

double dty::Double::Parse(const ::string s)
{
    double result;
    dty::ParseHelper::Parse(s, result);
    return result;
}

bool dty::Double::TryParse(const ::string s, double& result)
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

bool dty::Double::TryParse(const ::string s, dty::Double& result)
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

bool dty::Double::Equals(dty::TianyuObject& obj)
{
    if (this->GetTypeId() != obj.GetTypeId())
        return false;

    dty::Double& cast_obj = dynamic_cast<dty::Double&>(obj);
    return this->Equals(cast_obj);
}

bool dty::Double::operator==(dty::TianyuObject& obj)
{
    return this->Equals(obj);
}

bool dty::Double::Equals(dty::Double& other)
{
    double sub = this->_Value - other._Value;
    sub = ::fabs(sub);
    return sub < this->Precision;
}

bool dty::Double::operator==(dty::Double& other)
{
    return this->Equals(other);
}

bool dty::Double::operator<(dty::Double& other)
{
    return !(*this >= other);
}

bool dty::Double::operator>(dty::Double& other)
{
    return !(*this <= other);
}

bool dty::Double::operator<=(dty::Double& other)
{
    if (*this == other)
        return true;

    return this->_Value < other._Value;
}

bool dty::Double::operator>=(dty::Double& other)
{
    if (*this == other)
        return true;

    return this->_Value > other._Value;
}

dty::Double::operator double()
{
    return this->_Value;
}

double dty::Double::operator++()
{
    this->_Value = this->_Value + 1.0;
    return this->_Value;
}

double dty::Double::operator--()
{
    this->_Value = this->_Value - 1.0;
    return this->_Value;
}

double dty::Double::operator++(int)
{
    double preValue = this->_Value;
    this->_Value = this->_Value + 1.0;
    return preValue;
}

double dty::Double::operator--(int)
{
    double preValue = this->_Value;
    this->_Value = this->_Value - 1.0;
    return preValue;
}

double dty::Double::operator =(dty::Double& other)
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