#include "../utilize.hh"

int32 strlen(const string str)
{
    int32 length = 0;
    while ('\0' != str[length])
        ++length;

    return length;
}

::string uc2str(uchar ch)
{
    return new char[1]{ '\0' };
}

::string sb2str(sbyte sb, const ::string formatter)
{
    return new char[1]{ '\0' };
}

::string b2str(byte b, const ::string formatter)
{
    return new char[1]{ '\0' };
}

::string s2str(int16 s, const ::string formatter)
{
    return new char[1]{ '\0' };
}

::string us2str(uint16 us, const ::string formatter)
{
    return new char[1]{ '\0' };
}

::string i2str(int32 i, const ::string formatter)
{
    return new char[1]{ '\0' };
}

::string ui2str(uint32 ui, const ::string formatter)
{
    return new char[1]{ '\0' };
}

::string l2str(int64 l, const ::string formatter)
{
    return new char[1]{ '\0' };
}

::string ul2str(uint64 ul, const ::string formatter)
{
    return new char[1]{ '\0' };
}

::string f2str(float f, const ::string formatter)
{
    return new char[1]{ '\0' };
}

::string d2str(double d, const ::string formatter)
{
    return new char[1]{ '\0' };
}
