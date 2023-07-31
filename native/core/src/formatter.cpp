#include "../formatter.hpp"

// ######################################################
// Formatter Exceptions
// ######################################################

extern const uint64 __VARIABLE__ _tianyu_except_formatter_parseException;
extern const uint64 __VARIABLE__ _tianyu_except_formatter_parseStringEmptyException;

// -----------------------------------------------------
// Parse Exception
// -----------------------------------------------------

tianyu::except::ParseException::ParseException()
    : tianyu::TianyuObject(),
    tianyu::except::Exception()
{ }
tianyu::except::ParseException::~ParseException() { }
uint64 tianyu::except::ParseException::GetExceptionId()
{
    return _tianyu_except_formatter_parseException;
}
uint64 tianyu::except::ParseException::GetTypeId()
{
    return tianyu::GetType(__PTR_TO_REF__ this).Id();
}

// -----------------------------------------------------
// Parse String Empty Exception
// -----------------------------------------------------

tianyu::except::ParseStringEmptyException::ParseStringEmptyException()
    : tianyu::TianyuObject(),
    tianyu::except::ParseException()
{ }
tianyu::except::ParseStringEmptyException::~ParseStringEmptyException() { }
uint64 tianyu::except::ParseStringEmptyException::GetExceptionId()
{
    return _tianyu_except_formatter_parseStringEmptyException;
}
uint64 tianyu::except::ParseStringEmptyException::GetTypeId()
{
    return tianyu::GetType(__PTR_TO_REF__ this).Id();
}

// ######################################################
// IFormatter interface
// ######################################################

tianyu::IFormatter::~IFormatter() { }


// ######################################################
// Format Helper
// ######################################################

::string tianyu::FormatHelper::Format(char value, const ::string formatter)
{
    return ::c2str_f(value, formatter);
}
::string tianyu::FormatHelper::Format(uchar value, const ::string formatter)
{
    return ::uc2str_f(value, formatter);
}
::string tianyu::FormatHelper::Format(int16 value, const ::string formatter)
{
    return ::s2str_f(value, formatter);
}
::string tianyu::FormatHelper::Format(uint16 value, const ::string formatter)
{
    return ::us2str_f(value, formatter);
}
::string tianyu::FormatHelper::Format(int32 value, const ::string formatter)
{
    return ::i2str_f(value, formatter);
}
::string tianyu::FormatHelper::Format(uint32 value, const ::string formatter)
{
    return ::ui2str_f(value, formatter);
}
::string tianyu::FormatHelper::Format(int64 value, const ::string formatter)
{
    return ::l2str_f(value, formatter);
}
::string tianyu::FormatHelper::Format(uint64 value, const ::string formatter)
{
    return ::ul2str_f(value, formatter);
}
::string tianyu::FormatHelper::Format(float value, const ::string formatter)
{
    return ::f2str_f(value, formatter);
}
::string tianyu::FormatHelper::Format(double value, const ::string formatter)
{
    return ::d2str_f(value, formatter);
}
::string tianyu::FormatHelper::Format(bool value, const ::string formatter)
{
    bool isDefault = 0 == tianyu::strcmp(formatter, (::string)"");
    bool isLower = 0 == tianyu::strcmp(formatter, (::string)"u");
    bool isUpper = 0 == tianyu::strcmp(formatter, (::string)"U");
    if (isDefault || isLower || isUpper)
    {
        if (value)
        {
            ::string result = new char[5];
            result[0] = isUpper ? 'T' : 't';
            result[1] = isUpper ? 'R' : 'r';
            result[2] = isUpper ? 'U' : 'u';
            result[3] = isUpper ? 'E' : 'e';
            result[4] = '\0';

            return result;
        }
        else
        {
            ::string result = new char[6];
            result[0] = isUpper ? 'F' : 'f';
            result[1] = isUpper ? 'A' : 'a';
            result[2] = isUpper ? 'L' : 'l';
            result[3] = isUpper ? 'S' : 's';
            result[4] = isUpper ? 'E' : 'e';
            result[5] = '\0';

            return result;
        }
    }

    return ::b2str_f(value, formatter);
}

::string tianyu::FormatHelper::Format(tianyu::IToString& value)
{
    return value.ToString();
}

// ######################################################
// Parse Helper
// ######################################################

// generic parse API for integer type
extern bool _dty_core_parse_base(const ::string s, uint64& value, bool& negative);
// generic parse API for decimal type
// float type should be converted from double
extern bool _dty_core_parse_base(const ::string s, double& value);

void tianyu::ParseHelper::Parse(const ::string s, char& result)
{
    result = '\0';

    if (::null == s)
        throw tianyu::except::ArgumentNullException();

    int32 slen = tianyu::strlen(s);
    if (0 == slen)
        throw tianyu::except::ParseStringEmptyException();

    result = s[0];
}

void tianyu::ParseHelper::Parse(const ::string s, uchar& result)
{
    result = '\0';

    if (::null == s)
        throw tianyu::except::ArgumentNullException();

    int32 slen = tianyu::strlen(s);
    if (0 == slen)
        throw tianyu::except::ParseStringEmptyException();

    result = s[0];
}

void tianyu::ParseHelper::Parse(const ::string s, int16& result)
{
    result = 0;

    uint64 value = 0;
    bool negative = false;
    if (_dty_core_parse_base(s, value, negative))
        result = (int16)(negative ? -(0xFFFF & value) : 0xFFFF & value);
    else
        throw tianyu::except::ParseException();
}

void tianyu::ParseHelper::Parse(const ::string s, uint16& result)
{
    result = 0;

    uint64 value = 0;
    bool negative = false;
    if (_dty_core_parse_base(s, value, negative))
        result = (uint16)(0xFFFF & value);
    else
        throw tianyu::except::ParseException();
}

void tianyu::ParseHelper::Parse(const ::string s, int32& result)
{
    result = 0;

    uint64 value = 0;
    bool negative = false;
    if (_dty_core_parse_base(s, value, negative))
        result = (int32)(negative ? -(0xFFFFFFFF & value) : 0xFFFFFFFF & value);
    else
        throw tianyu::except::ParseException();
}

void tianyu::ParseHelper::Parse(const ::string s, uint32& result)
{
    result = 0;

    uint64 value = 0;
    bool negative = false;
    if (_dty_core_parse_base(s, value, negative))
        result = (uint32)(0xFFFFFFFF & value);
    else
        throw tianyu::except::ParseException();
}

void tianyu::ParseHelper::Parse(const ::string s, int64& result)
{
    result = 0;

    uint64 value = 0;
    bool negative = false;
    if (_dty_core_parse_base(s, value, negative))
        result = (int64)(negative ? -(0xFFFFFFFFFFFFFFFF & value) : 0xFFFFFFFFFFFFFFFF & value);
    else
        throw tianyu::except::ParseException();
}

void tianyu::ParseHelper::Parse(const ::string s, uint64& result)
{
    result = 0;

    bool negative = false;
    if (!_dty_core_parse_base(s, result, negative))
        throw tianyu::except::ParseException();
}

void tianyu::ParseHelper::Parse(const ::string s, double& result)
{
    result = 0;

    if (!_dty_core_parse_base(s, result))
        throw tianyu::except::ParseException();
}

void tianyu::ParseHelper::Parse(const ::string s, float& result)
{
    result = 0;

    double value = 0.0;
    if (_dty_core_parse_base(s, value))
        result = (float)value;
    else
        throw tianyu::except::ParseException();
}

void tianyu::ParseHelper::Parse(const ::string s, bool& result)
{
    result = false;

    if (::null == s)
        throw tianyu::except::ArgumentNullException();

    int32 slen = tianyu::strlen(s);
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

    int32 strCompare = tianyu::strcmp(s, (const ::string)"false", true);
    if (0 == strCompare)
        return; // result should be false if the source string is "false" (no matter the case)

    uint64 value = 0;
    bool negative = false;
    if (!_dty_core_parse_base(s, value, negative))
        value = 1;

    result = 0 != value;
}
