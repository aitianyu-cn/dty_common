#include "../version.hpp"

class VersionParseHelper
{
    __PUB__ int32 Major;
    __PUB__ int32 Minor;
    __PUB__ int32 Build;
    __PUB__ int32 Revision;

    __PUB__ VersionParseHelper(const ::string versionStr)
        : Major(1), Minor(0), Build(0), Revision(0)
    {
        if (::null == versionStr)
            throw dty::except::ArgumentNullException();

        this->_processString(versionStr);
    }

    __PRI__ void _processString(const ::string versionStr)
    {

    }
};

void _dty_native_version_parse(const ::string version, int32& major, int32& minor, int32& build, int32& revision)
{
    VersionParseHelper helper(version);

    major = helper.Major;
    minor = helper.Minor;
    build = helper.Build;
    revision = helper.Revision;
}