#include"./core.hxx"

#pragma region tianyu_core_base

int32 tianyu_core_cpp_imp_str_len(const ::string str)
{
    int32 length = 0;
    while ('\0' != str[length])
        ++length;

    return length;
}

int32 tianyu::strlen(const ::string str)
{
    if (::null == str)
        return 0;

    return ::tianyu_core_cpp_imp_str_len(str);
}

int32 tianyu::strcmp(const ::string s1, const ::string s2, bool ignoreCase)
{
    if (::null == s1 && ::null == s2)
        return 0;
    if (::null != s1 && ::null == s2)
        return 1;
    if (::null == s1 && ::null != s2)
        return -1;

    int32 s1L = ::tianyu_core_cpp_imp_str_len(s1);
    int32 s2L = ::tianyu_core_cpp_imp_str_len(s2);
    int32 s1I = 0;
    int32 s2I = 0;

    int32 result = 0;
    for (; s1I < s1L && s2I < s2L && 0 == result; ++s1I, ++s2I)
    {
        if (s1[s1I] == s2[s2I])
            continue;

        if (ignoreCase)
        {
            bool isEnglishChar =
                ('a' <= s1[s1I] && 'z' >= s1[s1I] || 'A' <= s1[s1I] && 'Z' >= s1[s1I])
                && ('a' <= s2[s2I] && 'z' >= s2[s2I] || 'A' <= s2[s2I] && 'Z' >= s2[s2I]);

            if (isEnglishChar)
            {
                bool isEqual = (s1[s1I] - 32) == s2[s2I] || (s1[s1I] + 32) == s2[s2I];
                if (isEqual)
                    continue;
            }
        }

        result = s1[s1I] - s2[s2I];
    }

    if (0 != result)
        return result; // if result is not equal, return the result directly.

    // if the result is equal, needs to check the length
    return s1L - s2L;
}

const int32 _ty_base_value_align_error_base_zero = -1;

int32 __VARIABLE__ tianyu::ValueAlign(int32 __VARIABLE__ value, int32 __VARIABLE__ base)
{
    if (0 >= base)
        throw _ty_base_value_align_error_base_zero;

    if (0 == value)
        return base;

    int32 integerMultiple = value / base;
    bool isMoreThanBase = value % base != 0;

    return integerMultiple * base + (isMoreThanBase ? base : 0);
}

int32 __VARIABLE__ tianyu::ValueAlignByPow(int32 __VARIABLE__ value, int32 __VARIABLE__ power)
{
    if (0 >= power)
        throw _ty_base_value_align_error_base_zero;

    // pre process the power
    // since the power only support 2^31
    power = power & 0b11111;
    if (0 == value)
        return 0b1 << power;

    int32 base = 0b1 << power;
    int32 andBase = base - 1;

    return (value & andBase) == 0 ? value : (value & (~andBase)) + base;
}

#pragma endregion

#pragma region tianyu_core_object_base

__construction__      tianyu::TianyuObject::TianyuObject()
    : tianyu::IToString()
{ }

__destruction__       tianyu::TianyuObject::~TianyuObject()
{ }

bool __VARIABLE__     tianyu::TianyuObject::IsNull()
{
    return false;
}

bool __VARIABLE__     tianyu::TianyuObject::Equals(tianyu::TianyuObject& obj)
{
    return this->GetTypeId() == obj.GetTypeId() && this->GetHashCode() == obj.GetHashCode();
}

bool __VARIABLE__     tianyu::TianyuObject::operator==(tianyu::TianyuObject& obj)
{
    return this->GetTypeId() == obj.GetTypeId() && this->GetHashCode() == obj.GetHashCode();
}

::string __VARIABLE__ tianyu::TianyuObject::ToString() noexcept
{
    return tianyu::_tianyu_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

uint64 __VARIABLE__   tianyu::TianyuObject::GetTypeId()
{
    return tianyu::GetType(__PTR_TO_REF__ this).Id();
}

uint64 __VARIABLE__   tianyu::TianyuObject::GetHashCode()
{
    return (uint64)(this);
}

bool __VARIABLE__     tianyu::TianyuObject::IsNull(tianyu::TianyuObject& obj)
{
    return obj.IsNull();
}

#pragma endregion

