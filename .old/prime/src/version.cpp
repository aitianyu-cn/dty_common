#include "../version.hpp"

const int32 _dty_native_version_major = 1;
const int32 _dty_native_version_minor = 0;
const int32 _dty_native_version_build = 0;
const int32 _dty_native_version_revision = 0;
const int32 _dty_native_version_major_revision = 0;
const int32 _dty_native_version_minor_revision = 0;

extern void _dty_native_version_parse(const ::string version, int32& major, int32& minor, int32& build, int32& revision);
extern ::string _dty_native_version_toString(dty::Version& version);

dty::Version::Version()
    : dty::TianyuObject(),
    dty::collection::IEquatable<dty::Version>(),
    dty::collection::ICompareable<dty::Version>(),
    _Major(_dty_native_version_major),
    _Minor(_dty_native_version_minor),
    _Build(_dty_native_version_build),
    _Revision(_dty_native_version_revision),
    _MajorRevision(_dty_native_version_major_revision),
    _MinorRevision(_dty_native_version_minor_revision),
    Major(_Major),
    Minor(_Minor),
    Build(_Build),
    Revision(_Revision),
    MajorRevision(_MajorRevision),
    MinorRevision(_MinorRevision)
{ }

dty::Version::Version(const dty::Version& other)
    : dty::TianyuObject(),
    dty::collection::IEquatable<dty::Version>(),
    dty::collection::ICompareable<dty::Version>(),
    _Major(other._Major),
    _Minor(other._Minor),
    _Build(other._Build),
    _Revision(other._Revision),
    _MajorRevision(other._MajorRevision),
    _MinorRevision(other._MinorRevision),
    Major(_Major),
    Minor(_Minor),
    Build(_Build),
    Revision(_Revision),
    MajorRevision(_MajorRevision),
    MinorRevision(_MinorRevision)
{ }

dty::Version::Version(dty::String version)
    : dty::TianyuObject(),
    dty::collection::IEquatable<dty::Version>(),
    dty::collection::ICompareable<dty::Version>(),
    _Major(),
    _Minor(),
    _Build(),
    _Revision(),
    _MajorRevision(),
    _MinorRevision(),
    Major(_Major),
    Minor(_Minor),
    Build(_Build),
    Revision(_Revision),
    MajorRevision(_MajorRevision),
    MinorRevision(_MinorRevision)
{
    int32 major = _dty_native_version_major;
    int32 minor = _dty_native_version_minor;
    int32 build = _dty_native_version_build;
    int32 revision = _dty_native_version_revision;

    dty::string_sp version_str = version.ToSafeCStr();
    _dty_native_version_parse(version_str, major, minor, build, revision);

    this->_Major = major;
    this->_Minor = minor;
    this->_Build = build;
    this->_Revision = revision;

    this->_MajorRevision = (uint16)((revision >> 16) & 0xFF);
    this->_MinorRevision = (uint16)(revision & 0xFF);
}

dty::Version::Version(const ::string version)
    : dty::TianyuObject(),
    dty::collection::IEquatable<dty::Version>(),
    dty::collection::ICompareable<dty::Version>(),
    _Major(),
    _Minor(),
    _Build(),
    _Revision(),
    _MajorRevision(),
    _MinorRevision(),
    Major(_Major),
    Minor(_Minor),
    Build(_Build),
    Revision(_Revision),
    MajorRevision(_MajorRevision),
    MinorRevision(_MinorRevision)
{
    int32 major = _dty_native_version_major;
    int32 minor = _dty_native_version_minor;
    int32 build = _dty_native_version_build;
    int32 revision = _dty_native_version_revision;

    _dty_native_version_parse(version, major, minor, build, revision);

    this->_Major = major;
    this->_Minor = minor;
    this->_Build = build;
    this->_Revision = revision;

    this->_MajorRevision = (uint16)((revision >> 16) & 0xFF);
    this->_MinorRevision = (uint16)(revision & 0xFF);
}

dty::Version::Version(int32 major, int32 minor)
    : dty::TianyuObject(),
    dty::collection::IEquatable<dty::Version>(),
    dty::collection::ICompareable<dty::Version>(),
    _Major(major), _Minor(minor),
    _Build(_dty_native_version_build),
    _Revision(_dty_native_version_revision),
    _MajorRevision(_dty_native_version_major_revision),
    _MinorRevision(_dty_native_version_minor_revision),
    Major(_Major),
    Minor(_Minor),
    Build(_Build),
    Revision(_Revision),
    MajorRevision(_MajorRevision),
    MinorRevision(_MinorRevision)
{ }

dty::Version::Version(int32 major, int32 minor, int32 build)
    : dty::TianyuObject(),
    dty::collection::IEquatable<dty::Version>(),
    dty::collection::ICompareable<dty::Version>(),
    _Major(major), _Minor(minor), _Build(build),
    _Revision(_dty_native_version_revision),
    _MajorRevision(_dty_native_version_major_revision),
    _MinorRevision(_dty_native_version_minor_revision),
    Major(_Major),
    Minor(_Minor),
    Build(_Build),
    Revision(_Revision),
    MajorRevision(_MajorRevision),
    MinorRevision(_MinorRevision)
{ }

dty::Version::Version(int32 major, int32 minor, int32 build, int32 revision)
    : dty::TianyuObject(),
    dty::collection::IEquatable<dty::Version>(),
    dty::collection::ICompareable<dty::Version>(),
    _Major(major), _Minor(minor), _Build(build), _Revision(revision),
    _MajorRevision((int16)((revision >> 16) & 0xFF)),
    _MinorRevision((int16)(revision & 0xFF)),
    Major(_Major),
    Minor(_Minor),
    Build(_Build),
    Revision(_Revision),
    MajorRevision(_MajorRevision),
    MinorRevision(_MinorRevision)
{ }

uint64 dty::Version::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

::string dty::Version::ToString() noexcept
{
    return _dty_native_version_toString(__PTR_TO_REF__ this);
}

dty::Version& dty::Version::operator=(const dty::Version& version)
{
    dty::Version& cast_version = const_cast<dty::Version __REFERENCE__>(version);
    if (this->GetHashCode() != cast_version.GetHashCode())
    {
        this->_Build = cast_version._Build;
        this->_Major = cast_version._Major;
        this->_Minor = cast_version._Minor;
        this->_Revision = cast_version._Revision;
        this->_MajorRevision = cast_version._MajorRevision;
        this->_MinorRevision = cast_version._MinorRevision;
    }

    return __PTR_TO_REF__ this;
}

dty::collection::CompareResult dty::Version::CompareTo(dty::Version& other)
{
    int32 cmp = this->_Major - other._Major;
    if (0 > cmp)
        return dty::collection::CompareResult::LESS;
    else if (0 < cmp)
        return dty::collection::CompareResult::GREAT;

    cmp = this->_Minor - other._Minor;
    if (0 > cmp)
        return dty::collection::CompareResult::LESS;
    else if (0 < cmp)
        return dty::collection::CompareResult::GREAT;

    cmp = this->_Build - other._Build;
    if (0 > cmp)
        return dty::collection::CompareResult::LESS;
    else if (0 < cmp)
        return dty::collection::CompareResult::GREAT;

    cmp = this->_Revision - other._Revision;
    if (0 > cmp)
        return dty::collection::CompareResult::LESS;
    else if (0 < cmp)
        return dty::collection::CompareResult::GREAT;

    return dty::collection::CompareResult::EQUAL;
}

bool dty::Version::Equals(dty::Version& other)
{
    return (__PTR_TO_REF__ this) == other;
}

bool dty::Version::Equals(dty::TianyuObject& other)
{
    if (this->GetTypeId() != other.GetTypeId())
        return false;

    return this->Equals(dynamic_cast<dty::Version __REFERENCE__>(other));
}

bool dty::Version::operator==(dty::Version& other)
{
    return this->_Major.Get() == other._Major
        && this->_Minor.Get() == other._Minor
        && this->_Build.Get() == other._Build
        && this->_Revision.Get() == other._Revision;
}
bool dty::Version::operator!=(dty::Version& other)
{
    return this->_Major != other._Major
        || this->_Minor != other._Minor
        || this->_Build != other._Build
        || this->_Revision != other._Revision;
}
bool dty::Version::operator<(dty::Version& other)
{
    return dty::collection::CompareResult::LESS == this->CompareTo(other);
}
bool dty::Version::operator<=(dty::Version& other)
{
    return dty::collection::CompareResult::GREAT != this->CompareTo(other);
}
bool dty::Version::operator>(dty::Version& other)
{
    return dty::collection::CompareResult::GREAT == this->CompareTo(other);
}
bool dty::Version::operator>=(dty::Version& other)
{
    return dty::collection::CompareResult::LESS != this->CompareTo(other);
}

dty::Version dty::Version::Parse(dty::String version)
{
    return dty::Version(version);
}

dty::Version dty::Version::Parse(const ::string version)
{
    return dty::Version(version);
}

bool dty::Version::TryParse(dty::String version, dty::Version& result)
{
    try
    {
        dty::Version parsed_version(version);

        result._Major = parsed_version._Major.Get();
        result._Minor = parsed_version._Minor.Get();
        result._Build = parsed_version._Build.Get();
        result._Revision = parsed_version._Revision.Get();
        result._MajorRevision = parsed_version._MajorRevision.Get();
        result._MinorRevision = parsed_version._MinorRevision.Get();

        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool dty::Version::TryParse(const ::string version, dty::Version& result)
{
    try
    {
        dty::Version parsed_version(version);

        result._Major = parsed_version._Major.Get();
        result._Minor = parsed_version._Minor.Get();
        result._Build = parsed_version._Build.Get();
        result._Revision = parsed_version._Revision.Get();
        result._MajorRevision = parsed_version._MajorRevision.Get();
        result._MinorRevision = parsed_version._MinorRevision.Get();

        return true;
    }
    catch (...)
    {
        return false;
    }
}