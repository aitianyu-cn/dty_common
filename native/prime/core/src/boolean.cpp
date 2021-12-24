#include "../basetype.hpp"

#define __DOUBLE_OPERATOR__(ret, type, operate) \
    ret type::operator operate(type & value)    \
    {                                           \
      return this->_Value operate value._Value; \
    }

dty::Boolean::Boolean()
    : dty::TianyuObject(), dty::collection::IEquatable<dty::Boolean>(), dty::IFormatter(),
    _Value(false)
{ }

dty::Boolean::Boolean(bool value)
    : dty::TianyuObject(), dty::collection::IEquatable<dty::Boolean>(), dty::IFormatter(),
    _Value(value)
{ }

dty::Boolean::Boolean(const dty::Boolean& value)
    : dty::TianyuObject(), dty::collection::IEquatable<dty::Boolean>(), dty::IFormatter(),
    _Value(value._Value)
{ }

dty::Boolean::~Boolean() { }

bool dty::Boolean::Equals(dty::TianyuObject& obj)
{
    if (this->GetTypeId() != obj.GetTypeId())
        return false;

    dty::Boolean& cast_obj = dynamic_cast<dty::Boolean&>(obj);
    return this->Equals(cast_obj);
}

bool dty::Boolean::operator==(dty::TianyuObject& obj)
{
    return this->Equals(obj);
}

bool dty::Boolean::Equals(dty::Boolean& obj)
{
    return this->_Value == obj._Value;
}

dty::Boolean::operator bool()
{
    return this->_Value;
}

dty::Boolean::operator int32()
{
    return this->_Value ? 1 : 0;
}

bool dty::Boolean::operator!()
{
    return !(this->_Value);
}

__DOUBLE_OPERATOR__(bool, dty::Boolean, == )
__DOUBLE_OPERATOR__(bool, dty::Boolean, != )
__DOUBLE_OPERATOR__(bool, dty::Boolean, &&)
__DOUBLE_OPERATOR__(bool, dty::Boolean, || )

::string dty::Boolean::ToString() noexcept
{
    return this->ToString(::null);
}

uint64 dty::Boolean::GetTypeId()
{
    return dty::GetType<dty::Boolean>().Id();
}

uint64 dty::Boolean::GetHashCode()
{
    return (uint64)(this);
}

::string dty::Boolean::ToString(const ::string formatter)
{
    return dty::FormatHelper::Format(this->_Value, formatter);
}

bool dty::Boolean::Parse(const ::string s)
{
    bool result;
    dty::ParseHelper::Parse(s, result);
    return result;
}

bool dty::Boolean::TryParse(const ::string s, bool& result)
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

bool dty::Boolean::TryParse(const ::string s, dty::Boolean& result)
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

#undef __DOUBLE_OPERATOR__