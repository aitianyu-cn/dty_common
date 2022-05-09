#include "../formatter.hpp"

// ######################################################
// Formatter Exceptions
// ######################################################

constexpr uint64 __VARIABLE__ DTY_Core_Formatter_ParseException = 0xF000000000000001ULL;
constexpr uint64 __VARIABLE__ DTY_Core_Formatter_ParseStringEmptyException = 0xF000000000000002ULL;

// -----------------------------------------------------
// Parse Exception
// -----------------------------------------------------

dty::except::ParseException::ParseException()
    : dty::TianyuObject(),
    dty::except::Exception()
{ }
dty::except::ParseException::~ParseException() { }
uint64 dty::except::ParseException::GetExceptionId()
{
    return DTY_Core_Formatter_ParseException;
}
uint64 dty::except::ParseException::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

// -----------------------------------------------------
// Parse String Empty Exception
// -----------------------------------------------------

dty::except::ParseStringEmptyException::ParseStringEmptyException()
    : dty::TianyuObject(),
    dty::except::ParseException()
{ }
dty::except::ParseStringEmptyException::~ParseStringEmptyException() { }
uint64 dty::except::ParseStringEmptyException::GetExceptionId()
{
    return DTY_Core_Formatter_ParseStringEmptyException;
}
uint64 dty::except::ParseStringEmptyException::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

// ######################################################
// IFormatter interface
// ######################################################

dty::IFormatter::~IFormatter() { }


// ######################################################
// Format Helper
// ######################################################

::string dty::FormatHelper::Format(char value, const ::string formatter)
{
    return ::c2str_f(value, formatter);
}
::string dty::FormatHelper::Format(uchar value, const ::string formatter)
{
    return ::uc2str_f(value, formatter);
}
::string dty::FormatHelper::Format(int16 value, const ::string formatter)
{
    return ::s2str_f(value, formatter);
}
::string dty::FormatHelper::Format(uint16 value, const ::string formatter)
{
    return ::us2str_f(value, formatter);
}
::string dty::FormatHelper::Format(int32 value, const ::string formatter)
{
    return ::i2str_f(value, formatter);
}
::string dty::FormatHelper::Format(uint32 value, const ::string formatter)
{
    return ::ui2str_f(value, formatter);
}
::string dty::FormatHelper::Format(int64 value, const ::string formatter)
{
    return ::l2str_f(value, formatter);
}
::string dty::FormatHelper::Format(uint64 value, const ::string formatter)
{
    return ::ul2str_f(value, formatter);
}
::string dty::FormatHelper::Format(float value, const ::string formatter)
{
    return ::f2str_f(value, formatter);
}
::string dty::FormatHelper::Format(double value, const ::string formatter)
{
    return ::d2str_f(value, formatter);
}
::string dty::FormatHelper::Format(bool value, const ::string formatter)
{
    return ::b2str_f(value, formatter);
}


// ######################################################
// Parse Helper
// ######################################################

// generic parse API for integer type
extern bool _dty_core_parse_base(const ::string s, uint64& value, bool& negative);
// generic parse API for decimal type
// float type should be converted from double
extern bool _dty_core_parse_base(const ::string s, double& value);

void dty::ParseHelper::Parse(const ::string s, char& result)
{
    result = '\0';

    if (::null == s)
        throw dty::except::ArgumentNullException();

    int32 slen = ::strlen(s);
    if (0 == slen)
        throw dty::except::ParseStringEmptyException();

    result = s[0];
}

void dty::ParseHelper::Parse(const ::string s, uchar& result)
{
    result = '\0';

    if (::null == s)
        throw dty::except::ArgumentNullException();

    int32 slen = ::strlen(s);
    if (0 == slen)
        throw dty::except::ParseStringEmptyException();

    result = s[0];
}

void dty::ParseHelper::Parse(const ::string s, int16& result)
{
    result = 0;

    uint64 value = 0;
    bool negative = false;
    if (_dty_core_parse_base(s, value, negative))
        result = (int16)(negative ? -(0xFFFF & value) : 0xFFFF & value);
    else
        throw dty::except::ParseException();
}

void dty::ParseHelper::Parse(const ::string s, uint16& result)
{
    result = 0;

    uint64 value = 0;
    bool negative = false;
    if (_dty_core_parse_base(s, value, negative))
        result = (uint16)(0xFFFF & value);
    else
        throw dty::except::ParseException();
}

void dty::ParseHelper::Parse(const ::string s, int32& result)
{
    result = 0;

    uint64 value = 0;
    bool negative = false;
    if (_dty_core_parse_base(s, value, negative))
        result = (int32)(negative ? -(0xFFFFFFFF & value) : 0xFFFFFFFF & value);
    else
        throw dty::except::ParseException();
}

void dty::ParseHelper::Parse(const ::string s, uint32& result)
{
    result = 0;

    uint64 value = 0;
    bool negative = false;
    if (_dty_core_parse_base(s, value, negative))
        result = (uint32)(0xFFFFFFFF & value);
    else
        throw dty::except::ParseException();
}

void dty::ParseHelper::Parse(const ::string s, int64& result)
{
    result = 0;

    uint64 value = 0;
    bool negative = false;
    if (_dty_core_parse_base(s, value, negative))
        result = (int64)(negative ? -(0xFFFFFFFFFFFFFFFF & value) : 0xFFFFFFFFFFFFFFFF & value);
    else
        throw dty::except::ParseException();
}

void dty::ParseHelper::Parse(const ::string s, uint64& result)
{
    result = 0;

    bool negative = false;
    if (!_dty_core_parse_base(s, result, negative))
        throw dty::except::ParseException();

}

void dty::ParseHelper::Parse(const ::string s, double& result)
{
    result = 0;

    if (!_dty_core_parse_base(s, result))
        throw dty::except::ParseException();
}

void dty::ParseHelper::Parse(const ::string s, float& result)
{
    result = 0;

    double value = 0.0;
    if (_dty_core_parse_base(s, value))
        result = (float)value;
    else
        throw dty::except::ParseException();
}

void dty::ParseHelper::Parse(const ::string s, bool& result)
{
    result = false;

    if (::null == s)
        throw dty::except::ArgumentNullException();

    int32 slen = ::strlen(s);
    if (0 == slen)
        return; // for bool value type, empty string equals to false.

    if (1 == slen)
    {
        // in case of the parse string length is 1, to check it simply.
        switch (s[0])
        {
        case 'f': case 'F': case '0': break;
        default: result = true; break;
        }

        return;
    }

    int32 strCompare = ::strcmp(s, (const ::string)"false", true);
    if (0 == strCompare)
        return; // result should be false if the source string is "false" (no matter the case)

    uint64 value = 0;
    bool negative = false;
    if (!_dty_core_parse_base(s, value, negative))
        value = 1;

    result = 0 != value;
}
