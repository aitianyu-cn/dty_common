#include "../event.hpp"

tianyu::EventArgs::EventArgs() : tianyu::TianyuObject() { }

tianyu::EventArgs::~EventArgs() { }

::string tianyu::EventArgs::ToString() noexcept
{
    return tianyu::_tianyu_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

uint64 tianyu::EventArgs::GetTypeId()
{
    return tianyu::GetType(__PTR_TO_REF__ this).Id();
}

uint64 tianyu::EventArgs::GetHashCode()
{
    return (uint64)(this);
}