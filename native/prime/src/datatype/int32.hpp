#include "../../basetype.hpp"

dty::Int32::Int32()
    : dty::TianyuObject(),
    dty::collection::ICompareable<Int32>(),
    dty::collection::IEquatable<Int32>(),
    dty::IFormatter(),
    _Value(0)
{ }

dty::Int32::Int32(int32 value)
    : dty::TianyuObject(),
    dty::collection::ICompareable<Int32>(),
    dty::collection::IEquatable<Int32>(),
    dty::IFormatter(),
    _Value(value)
{ }

dty::Int32::Int32(const Int32& value)
    : dty::TianyuObject(),
    dty::collection::ICompareable<Int32>(),
    dty::collection::IEquatable<Int32>(),
    dty::IFormatter(),
    _Value(value._Value)
{ }

dty::Int32::~Int32() { }

bool dty::Int32::Equals(dty::TianyuObject& obj)
{
    return this->operator==(obj);
}

bool dty::Int32::operator ==(dty::TianyuObject& obj)
{
    if (this->GetTypeId() != obj.GetTypeId())
        return false;

    dty::Int32& cast_obj = dynamic_cast<dty::Int32&>(obj);
    return this->_Value == cast_obj._Value;
}

bool dty::Int32::Equals(dty::Int32& other)
{
    return this->operator==(other);
}

dty::collection::CompareResult dty::Int32::CompareTo(dty::Int32& other)
{
    return this->_Value == other._Value ? dty::collection::CompareResult::EQUAL
        : this->_Value > other._Value ? dty::collection::CompareResult::GREAT
        : dty::collection::CompareResult::LESS;
}

bool dty::Int32::operator ==(dty::Int32& other)
{
    return this->_Value == other._Value;
}

bool dty::Int32::operator !=(dty::Int32& other)
{
    return this->_Value != other._Value;
}

bool dty::Int32::operator >=(dty::Int32& other)
{
    return this->_Value >= other._Value;
}

bool dty::Int32::operator >=(dty::Int32& other)
{
    return this->_Value >= other._Value;
}

bool dty::Int32::operator >(dty::Int32& other)
{
    return this->_Value > other._Value;
}

bool dty::Int32::operator >(dty::Int32& other)
{
    return this->_Value > other._Value;
}

dty::Int32::operator int32()
{
    return this->_Value;
}

int32 dty::Int32::operator ++()
{
    this->_Value = this->_Value + 1;
    return this->_Value;
}

int32 dty::Int32::operator --()
{
    this->_Value = this->_Value - 1;
    return this->_Value;
}

int32 dty::Int32::operator ++(int)
{
    int32 pre = this->_Value;
    this->_Value = this->_Value + 1;
    return pre;
}

int32 dty::Int32::operator --(int)
{
    int32 pre = this->_Value;
    this->_Value = this->_Value - 1;
    return pre;
}

int32 dty::Int32::operator +(Int32& value)
{
    return this->_Value + value._Value;
}

int32 dty::Int32::operator -(Int32& value)
{
    return this->_Value - value._Value;
}

int32 dty::Int32::operator *(Int32& value)
{
    return this->_Value * value._Value;
}

int32 dty::Int32::operator /(Int32& value)
{
    return this->_Value / value._Value;
}

int32 dty::Int32::operator !()
{
    return !(this->_Value);
}

int32 dty::Int32::operator &(Int32& value)
{
    return this->_Value & value._Value;
}

int32 dty::Int32::operator |(Int32& value)
{
    return this->_Value | value._Value;
}

int32 dty::Int32::operator ~()
{
    return ~(this->_Value);
}

int32 dty::Int32::operator ^(Int32& value)
{
    return this->_Value ^ value._Value;
}

int32 dty::Int32::operator <<(Int32& value)
{
    return this->_Value << value._Value;
}

int32 dty::Int32::operator >>(Int32& value)
{
    return this->_Value >> value._Value;
}

int32 dty::Int32::operator =(Int32& value)
{
    this->_Value = value._Value;
    return this->_Value;
}

int32 dty::Int32::operator +=(Int32& value)
{
    this->_Value = this->_Value + value._Value;
    return this->_Value;
}

int32 dty::Int32::operator -=(Int32& value)
{
    this->_Value = this->_Value - value._Value;
    return this->_Value;
}

int32 dty::Int32::operator *=(Int32& value)
{
    this->_Value = this->_Value * value._Value;
    return this->_Value;
}

int32 dty::Int32::operator /=(Int32& value)
{
    this->_Value = this->_Value / value._Value;
    return this->_Value;
}

int32 dty::Int32::operator &=(Int32& value)
{
    this->_Value = this->_Value & value._Value;
    return this->_Value;
}

int32 dty::Int32::operator |=(Int32& value)
{
    this->_Value = this->_Value | value._Value;
    return this->_Value;
}

int32 dty::Int32::operator ^=(Int32& value)
{
    this->_Value = this->_Value ^ value._Value;
    return this->_Value;
}

int32 dty::Int32::operator <<=(Int32& value)
{
    this->_Value = this->_Value << value._Value;
    return this->_Value;
}

int32 dty::Int32::operator >>=(Int32& value)
{
    this->_Value = this->_Value >> value._Value;
    return this->_Value;
}

::string dty::Int32::ToString() noexcept
{
    return this->ToString("");
}

uint64 dty::Int32::GetTypeId()
{
    return dty::GetType<dty::Int32>().Id();
}

uint64 dty::Int32::GetHashCode()
{
    return (uint64)(this);
}

::string dty::Int32::ToString(const ::string formatter)
{
    throw dty::except::NotImplementationException();
}

int32 dty::Int32::Parse(const ::string s)
{
    throw dty::except::NotImplementationException();
}

bool dty::Int32::TryParse(const ::string s, Int32& result)
{
    throw dty::except::NotImplementationException();
}

bool dty::Int32::TryParse(const ::string s, int32& result)
{
    throw dty::except::NotImplementationException();
}