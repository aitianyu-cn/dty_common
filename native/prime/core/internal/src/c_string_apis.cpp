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
    return new char[1]{ (char)ch };
}
