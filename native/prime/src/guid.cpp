#include "../guid.hpp"

void _dty_native_cpp_guid_parse(dty::String g, ::byte* b);
void _dty_native_cpp_guid_parse(const ::string g, ::byte* b);
::string _dty_native_cpp_guid_toString(const ::string formatter);

dty::Guid::Guid()
    : dty::TianyuObject(),
    dty::collection::IEquatable<dty::Guid>(),
    dty::collection::ICompareable<dty::Guid>(),
    _Guid()
{
    for (int32 i = 0; i < ::dty_native_id_default_size; ++i)
        this->_Guid[i] = (byte)0x00;
}
dty::Guid::Guid(::byte b[::dty_native_id_default_size])
    : dty::TianyuObject(),
    dty::collection::IEquatable<dty::Guid>(),
    dty::collection::ICompareable<dty::Guid>()
{
    for (int32 i = 0; i < ::dty_native_id_default_size; ++i)
        this->_Guid[i] = b[i];
}
dty::Guid::Guid(dty::String g)
    : dty::TianyuObject(),
    dty::collection::IEquatable<dty::Guid>(),
    dty::collection::ICompareable<dty::Guid>()
{
    _dty_native_cpp_guid_parse(g, this->_Guid);
}
dty::Guid::Guid(int32 a, int16 b, int16 c, ::byte d, ::byte e, ::byte f, ::byte g, ::byte h, ::byte i, ::byte j, ::byte k)
    : dty::TianyuObject(),
    dty::collection::IEquatable<dty::Guid>(),
    dty::collection::ICompareable<dty::Guid>()
{
    this->_Guid[0] = (::byte)(a & 0xFF); a >>= 8;
    this->_Guid[1] = (::byte)(a & 0xFF); a >>= 8;
    this->_Guid[2] = (::byte)(a & 0xFF); a >>= 8;
    this->_Guid[3] = (::byte)(a & 0xFF);

    this->_Guid[4] = (::byte)(b & 0xFF); b >>= 8;
    this->_Guid[5] = (::byte)(b & 0xFF);

    this->_Guid[6] = (::byte)(c & 0xFF); c >>= 8;
    this->_Guid[7] = (::byte)(c & 0xFF);

    this->_Guid[8] = d;
    this->_Guid[9] = e;
    this->_Guid[10] = f;
    this->_Guid[11] = g;
    this->_Guid[12] = h;
    this->_Guid[13] = i;
    this->_Guid[14] = j;
    this->_Guid[15] = k;
}
dty::Guid::Guid(uint32 a, uint16 b, uint16 c, ::byte d, ::byte e, ::byte f, ::byte g, ::byte h, ::byte i, ::byte j, ::byte k)
    : dty::TianyuObject(),
    dty::collection::IEquatable<dty::Guid>(),
    dty::collection::ICompareable<dty::Guid>()
{
    this->_Guid[0] = (::byte)(a & 0xFF); a >>= 8;
    this->_Guid[1] = (::byte)(a & 0xFF); a >>= 8;
    this->_Guid[2] = (::byte)(a & 0xFF); a >>= 8;
    this->_Guid[3] = (::byte)(a & 0xFF);

    this->_Guid[4] = (::byte)(b & 0xFF); b >>= 8;
    this->_Guid[5] = (::byte)(b & 0xFF);

    this->_Guid[6] = (::byte)(c & 0xFF); c >>= 8;
    this->_Guid[7] = (::byte)(c & 0xFF);

    this->_Guid[8] = d;
    this->_Guid[9] = e;
    this->_Guid[10] = f;
    this->_Guid[11] = g;
    this->_Guid[12] = h;
    this->_Guid[13] = i;
    this->_Guid[14] = j;
    this->_Guid[15] = k;
}
dty::Guid::Guid(const dty::Guid& other)
    : dty::TianyuObject(),
    dty::collection::IEquatable<dty::Guid>(),
    dty::collection::ICompareable<dty::Guid>()
{
    for (int32 i = 0; i < ::dty_native_id_default_size; ++i)
        this->_Guid[i] = other._Guid[i];
}
dty::Guid::~Guid() { }

dty::collection::ByteArray dty::Guid::ToByteArray()
{
    return dty::collection::ByteArray(this->_Guid, ::dty_native_id_default_size, false);
}

::string dty::Guid::ToString() noexcept
{
    return _dty_native_cpp_guid_toString(::null);
}

dty::String dty::Guid::ToString(const ::string formatter)
{
    return dty::String::GetString(_dty_native_cpp_guid_toString(formatter), false);
}

uint64 dty::Guid::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

dty::collection::CompareResult dty::Guid::CompareTo(dty::Guid& other)
{
    int32 compareResult = 0;
    for (int32 i = 0; i < ::dty_native_id_default_size && 0 == compareResult; ++i)
        compareResult = this->_Guid[i] - other._Guid[i];

    return 0 == compareResult ? dty::collection::CompareResult::EQUAL
        : 0 > compareResult ? dty::collection::CompareResult::LESS
        : dty::collection::CompareResult::GREAT;
}
bool dty::Guid::Equals(dty::Guid& other)
{
    for (int32 i = 0; i < ::dty_native_id_default_size; ++i)
        if (this->_Guid[i] != other._Guid[i])
            return false;

    return true;
}
bool dty::Guid::operator==(dty::Guid& other)
{
    return this->Equals(other);
}
bool dty::Guid::operator!=(dty::Guid& other)
{
    return !(this->Equals(other));
}
bool dty::Guid::operator<(dty::Guid& other)
{
    return dty::collection::CompareResult::LESS == this->CompareTo(other);
}
bool dty::Guid::operator>(dty::Guid& other)
{
    return dty::collection::CompareResult::GREAT == this->CompareTo(other);
}
bool dty::Guid::operator<=(dty::Guid& other)
{
    return dty::collection::CompareResult::GREAT != this->CompareTo(other);
}
bool dty::Guid::operator>=(dty::Guid& other)
{
    return dty::collection::CompareResult::LESS != this->CompareTo(other);
}

dty::Guid dty::Guid::Empty()
{
    return Guid();
}

dty::Guid dty::Guid::Parse(dty::String g)
{
    dty::Guid guid;
    _dty_native_cpp_guid_parse(g, guid._Guid);

    return guid;
}
dty::Guid dty::Guid::Parse(const ::string g)
{
    dty::Guid guid;
    _dty_native_cpp_guid_parse(g, guid._Guid);

    return guid;
}

bool dty::Guid::TryParse(dty::String guid, dty::Guid& result)
{
    try
    {
        _dty_native_cpp_guid_parse(guid, result._Guid);
        return true;
    }
    catch (std::exception)
    {
        return false;
    }
}
bool dty::Guid::TryParse(const ::string guid, dty::Guid& result)
{
    try
    {
        _dty_native_cpp_guid_parse(guid, result._Guid);
        return true;
    }
    catch (std::exception)
    {
        return false;
    }
}

#if defined(__DTY_WIN)
#include<combaseapi.h>
#elif defined(__DTY_APF) || defined(__DTY_LNX)
#include <uuid/uuid.h>
#endif // defined(__DTY_WIN)
dty::Guid dty::Guid::NewGuid()
{
    dty::Guid guid;

#if defined(__DTY_WIN)
    ::GUID ms_guid;
    if (S_OK == ::CoCreateGuid(__VAR_TO_PTR__ ms_guid))
    {
        guid._Guid[0] = (::byte)(ms_guid.Data1 & 0xFF); ms_guid.Data1 >>= 8;
        guid._Guid[1] = (::byte)(ms_guid.Data1 & 0xFF); ms_guid.Data1 >>= 8;
        guid._Guid[2] = (::byte)(ms_guid.Data1 & 0xFF); ms_guid.Data1 >>= 8;
        guid._Guid[3] = (::byte)(ms_guid.Data1 & 0xFF);

        guid._Guid[4] = (::byte)(ms_guid.Data2 & 0xFF); ms_guid.Data2 >>= 8;
        guid._Guid[5] = (::byte)(ms_guid.Data2 & 0xFF);

        guid._Guid[6] = (::byte)(ms_guid.Data3 & 0xFF); ms_guid.Data3 >>= 8;
        guid._Guid[7] = (::byte)(ms_guid.Data3 & 0xFF);

        guid._Guid[8] = ms_guid.Data4[0];
        guid._Guid[9] = ms_guid.Data4[1];
        guid._Guid[10] = ms_guid.Data4[2];
        guid._Guid[11] = ms_guid.Data4[3];
        guid._Guid[12] = ms_guid.Data4[4];
        guid._Guid[13] = ms_guid.Data4[5];
        guid._Guid[14] = ms_guid.Data4[6];
        guid._Guid[15] = ms_guid.Data4[7];
    }
#elif defined(__DTY_APF) || defined(__DTY_LNX)
    ::uuid_generate(guid._Guid);
#endif // defined(__DTY_WIN)

    return guid;
}

void _dty_native_cpp_guid_parse(dty::String g, ::byte* b)
{
    throw dty::except::NotImplementationException();
}
void _dty_native_cpp_guid_parse(const ::string g, ::byte* b)
{
    throw dty::except::NotImplementationException();
}
