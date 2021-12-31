#include "../arghelper.hpp"

dty::IArgValue::IArgValue(dty::ArgumentValueType arg_type) :
    dty::TianyuObject(),
    _ArgType(arg_type),
    ArgType(_ArgType)
{ }

dty::IArgValue::~IArgValue() { }

::string dty::IArgValue::ToString()
{
    return this->ToString(':');
}

::string dty::IArgValue::ToString(char link)
{
    if ('\0' == link)
        throw dty::except::ArgumentException();

    const ::string key = this->Key();
    const ::string value = this->Value();
    if (::null == key)
        return ::null;

    int32 key_len = ::strlen(key);
    int32 val_len = ::null == value ? 0 : ::strlen(value);
    if (0 == key_len && 0 == val_len)
        return ::null;

    bool is_kv = 0 != key_len && 0 != val_len;
    int32 total_len = key_len + val_len + (is_kv ? 1 : 0) + 1;

    ::string result = new char[total_len];
    if (is_kv)
    {
        int32 index = 0;
        for (int32 i = 0; i < key_len; ++i, ++index)
            result[index] = key[i];

        result[index++] = link;

        for (int32 i = 0; i < val_len; ++i, ++index)
            result[index] = value[i];
    }
    else
    {
        const ::string source = 0 == key_len ? value : key;
        for (int32 i = 0; i < total_len; ++i)
            result[i] = source[i];
    }
    result[total_len] = '\0';

    return result;
}