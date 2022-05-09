#include "./ostream.hpp"

namespace dty::io
{
    std::ostream __REFERENCE__ operator<<(std::ostream __REFERENCE__ os, String __REFERENCE__ str)
    {
        ::string cStr = str.ToCStr();
        if (::null != cStr)
        {
            os << cStr;
            delete [] cStr;
        }

        return os;
    }

    std::ostream __REFERENCE__ operator<<(std::ostream __REFERENCE__ os, TimeSpan __REFERENCE__ span);
    std::ostream __REFERENCE__ operator<<(std::ostream __REFERENCE__ os, DateTime __REFERENCE__ date);
}