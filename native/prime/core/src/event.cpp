#include "../event.hpp"

dty::EventArgs::EventArgs() : dty::TianyuObject() { }

dty::EventArgs::~EventArgs() { }

::string dty::EventArgs::ToString() noexcept
{
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

uint64 dty::EventArgs::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

uint64 dty::EventArgs::GetHashCode()
{
    return (uint64)(this);
}