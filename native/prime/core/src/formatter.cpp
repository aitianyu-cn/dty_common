#include "../formatter.hpp"

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

void dty::ParseHelper::Parse(const ::string s, char& result)
{
    result = 0;
}

void dty::ParseHelper::Parse(const ::string s, uchar& result)
{
    result = 0;
}

void dty::ParseHelper::Parse(const ::string s, int16& result)
{
    result = 0;
}

void dty::ParseHelper::Parse(const ::string s, uint16& result)
{
    result = 0;
}

void dty::ParseHelper::Parse(const ::string s, int32& result)
{
    result = 0;
}

void dty::ParseHelper::Parse(const ::string s, uint32& result)
{
    result = 0;
}

void dty::ParseHelper::Parse(const ::string s, int64& result)
{
    result = 0;
}

void dty::ParseHelper::Parse(const ::string s, uint64& result)
{
    result = 0;
}

void dty::ParseHelper::Parse(const ::string s, double& result)
{
    result = 0;
}

void dty::ParseHelper::Parse(const ::string s, float& result)
{
    result = 0;
}

void dty::ParseHelper::Parse(const ::string s, bool& result)
{
    result = false;
}