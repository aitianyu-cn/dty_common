#include "../utilize.hh"

int32 __VARIABLE__ strlen(const string __VARIABLE__ str)
{
    int32 length = 0;
    while ('\0' != str[length])
        ++length;

    return length;
}