#include "../basetype.hpp"

#define __DOUBLE_OPERATOR__(ret, type, operate) \
    ret type::operator operate(type & value)    \
    {                                           \
      return this->_Value operate value._Value; \
    }

tianyu::Boolean::Boolean()
    : tianyu::TianyuObject(), tianyu::collection::IEquatable<tianyu::Boolean>(), tianyu::IFormatter(),
    _Value(false)
{ }

tianyu::Boolean::Boolean(bool value)
    : tianyu::TianyuObject(), tianyu::collection::IEquatable<tianyu::Boolean>(), tianyu::IFormatter(),
    _Value(value)
{ }

tianyu::Boolean::Boolean(const tianyu::Boolean& value)
    : tianyu::TianyuObject(), tianyu::collection::IEquatable<tianyu::Boolean>(), tianyu::IFormatter(),
    _Value(value._Value)
{ }

tianyu::Boolean::~Boolean() { }

bool tianyu::Boolean::Equals(tianyu::TianyuObject& obj)
{
    if (this->GetTypeId() != obj.GetTypeId())
        return false;

    tianyu::Boolean& cast_obj = dynamic_cast<tianyu::Boolean&>(obj);
    return this->Equals(cast_obj);
}

bool tianyu::Boolean::operator==(tianyu::TianyuObject& obj)
{
    return this->Equals(obj);
}

bool tianyu::Boolean::Equals(tianyu::Boolean& obj)
{
    return this->_Value == obj._Value;
}

tianyu::Boolean::operator bool()
{
    return this->_Value;
}

tianyu::Boolean::operator int32()
{
    return this->_Value ? 1 : 0;
}

bool tianyu::Boolean::operator!()
{
    return !(this->_Value);
}

::string tianyu::Boolean::ToString() noexcept
{
    return this->ToString((::string)"");
}

uint64 tianyu::Boolean::GetTypeId()
{
    return tianyu::GetType<tianyu::Boolean>().Id();
}

uint64 tianyu::Boolean::GetHashCode()
{
    return (uint64)(this);
}

::string tianyu::Boolean::ToString(const ::string formatter)
{
    return tianyu::FormatHelper::Format(this->_Value, formatter);
}

bool tianyu::Boolean::Parse(const ::string s)
{
    bool result;
    tianyu::ParseHelper::Parse(s, result);
    return result;
}

bool tianyu::Boolean::TryParse(const ::string s, bool& result)
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

bool tianyu::Boolean::TryParse(const ::string s, tianyu::Boolean& result)
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

__DOUBLE_OPERATOR__(bool, tianyu::Boolean, == )
__DOUBLE_OPERATOR__(bool, tianyu::Boolean, != )
__DOUBLE_OPERATOR__(bool, tianyu::Boolean, &&)
__DOUBLE_OPERATOR__(bool, tianyu::Boolean, || )

#undef __DOUBLE_OPERATOR__