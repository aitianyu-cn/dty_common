#include "./dty-core.hxx"

// #################################################################################################
// #################################################################################################
// Tianyu Base APIs Implementation
// #################################################################################################
// #################################################################################################

int32 strlen(const string str)
{
    int32 length = 0;
    while ('\0' != str[length])
        ++length;

    return length;
}

::string uc2str(uchar ch)
{
    return new char[1]{ (char)ch };
}

// #################################################################################################
// #################################################################################################
// Tianyu Object Base (TianyuObject) Implementation
// #################################################################################################
// #################################################################################################

__construction__ dty::TianyuObject::TianyuObject()
    : dty::IToString()
{ }

__destruction__  dty::TianyuObject::~TianyuObject()
{ }

bool dty::TianyuObject::IsNull()
{
    return false;
}

bool dty::TianyuObject::Equals(dty::TianyuObject& obj)
{
    return this->GetTypeId() == obj.GetTypeId() && this->GetHashCode() == obj.GetHashCode();
}

bool dty::TianyuObject::operator==(dty::TianyuObject& obj)
{
    return this->GetTypeId() == obj.GetTypeId() && this->GetHashCode() == obj.GetHashCode();
}

::string dty::TianyuObject::ToString() noexcept
{
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

uint64 dty::TianyuObject::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

uint64   dty::TianyuObject::GetHashCode()
{
    return (uint64)(this);
}

bool dty::TianyuObject::IsNull(dty::TianyuObject& obj)
{
    return 0ULL == obj.GetHashCode();
}
