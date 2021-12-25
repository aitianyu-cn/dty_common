#include "../utilize.hh"

const dty::TianyuObject& dty::null = dty::TianyuEmptyObject();

__construction__ dty::TianyuEmptyObject::TianyuEmptyObject()
    : dty::TianyuObject()
{ }

__destruction__  dty::TianyuEmptyObject::~TianyuEmptyObject()
{ }

::string dty::TianyuEmptyObject::ToString() noexcept
{
    return new char[5]{ 'n', 'u', 'l', 'l', '\0' };
}

uint64   dty::TianyuEmptyObject::GetTypeId()
{
    return 0ULL;
}

uint64   dty::TianyuEmptyObject::GetHashCode()
{
    return 0ULL;
}

bool     dty::TianyuEmptyObject::IsNull()
{
    return true;
}