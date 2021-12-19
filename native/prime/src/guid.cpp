#include "../guid.hpp"

#if defined(__DTY_WIN)

#elif defined(__DTY_APF) || defined(__DTY_LNX)
#include <uuid/uuid.h>
#endif // defined(__DTY_WIN)

dty::Guid __VARIABLE__ dty::Guid::NewGuid()
{
    dty::Guid guid;
#if defined(__DTY_WIN)

#elif defined(__DTY_APF) || defined(__DTY_LNX)
    ::uuid_generate(guid._Guid);
#endif // defined(__DTY_WIN)
}