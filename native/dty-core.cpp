#include "./dty-core.hxx"

// #################################################################################################
// #################################################################################################
// Tianyu Base APIs Implementation
// #################################################################################################
// #################################################################################################

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

// #################################################################################################
// #################################################################################################
// Tianyu Base APIs Implementation
// for string convertion
// #################################################################################################
// #################################################################################################

_enum NumberScale : byte
{
    ASC,
    BIN,
    OCT,
    DEC,
    HEX
};

_enum ForcePrefix : byte
{
    Unassign,
    Prefix,
    Unfix
};

const int32 _ty_base_number_string_convertion_formatter_error_duplicate_scale = -1;
const int32 _ty_base_number_string_convertion_formatter_error_duplicate_prefix = -2;
const int32 _ty_base_number_string_convertion_formatter_error_duplicate_count_i = -3;
const int32 _ty_base_number_string_convertion_formatter_error_duplicate_count_f = -4;
const int32 _ty_base_number_string_convertion_formatter_error_duplicate_count_t = -5;

class TYBaseNumberStringConvertionFormatter : public virtual dty::TianyuObject
{
    __PRI__ NumberScale __VARIABLE__ _Scale;
    __PRI__ ForcePrefix __VARIABLE__ _ForcePrefix;
    __PRI__ bool        __VARIABLE__ _Prefix;
    __PRI__ bool        __VARIABLE__ _CharCase;
    __PRI__ int32       __VARIABLE__ _IntegerDigits;
    __PRI__ int32       __VARIABLE__ _FloatDigits;
    __PRI__ int32       __VARIABLE__ _TotalDigits;
    __PRI__ char        __VARIABLE__ _FillChar;

    __PUB__         TYBaseNumberStringConvertionFormatter(const ::string __VARIABLE__ format_str)
        : dty::TianyuObject(),
        _Scale(NumberScale::DEC),
        _ForcePrefix(ForcePrefix::Unassign),
        _Prefix(false),
        _CharCase(false),
        _IntegerDigits(-1),
        _FloatDigits(-1),
        _TotalDigits(-1),
        _FillChar('\0')
    {
        if (::null == format_str)
            return;

        int32 length = ::strlen(format_str);
        if (0 == length)
            return;

        this->_ProcessFormatter(format_str, length);
    }
    __PUB__ virtual ~TYBaseNumberStringConvertionFormatter() __override_func { }

    __PRI__ void _ProcessFormatter(const ::string __VARIABLE__ format_str, int32 __VARIABLE__ length)
    {
        bool hasScaleSet = false;
        int32 index = 0;

        this->_TrimSpace(format_str, length, index);

        switch (format_str[index])
        {
        case 'a': break;
        case 'A': break;
        case 'b': this->_SetScale(hasScaleSet, NumberScale::BIN, false); break;
        case 'B': this->_SetScale(hasScaleSet, NumberScale::BIN, true); break;
        case 'c': this->_SetScale(hasScaleSet, NumberScale::ASC, false); break;
        case 'C': break;
        case 'd':  this->_SetScale(hasScaleSet, NumberScale::DEC, false); break;
        case 'D':
            if (-1 != this->_IntegerDigits)
                throw _ty_base_number_string_convertion_formatter_error_duplicate_count_i;

            this->_IntegerDigits = this->_CountChar(format_str, length, index, 'D');
            break;
        case 'e': break;
        case 'E': break;
        case 'f':
            if (-1 != this->_FloatDigits)
                throw _ty_base_number_string_convertion_formatter_error_duplicate_count_f;

            this->_FloatDigits = this->_CountChar(format_str, length, index, 'f');
            break;
        case 'F': break;
        case 'g': break;
        case 'G': break;
        case 'h': break;
        case 'H': break;
        case 'i': break;
        case 'I': break;
        case 'j': break;
        case 'J': break;
        case 'k': break;
        case 'K': break;
        case 'l': break;
        case 'L': break;
        case 'm': break;
        case 'M': break;
        case 'n': break;
        case 'N': break;
        case 'o': this->_SetScale(hasScaleSet, NumberScale::OCT, false); break;
        case 'O': this->_SetScale(hasScaleSet, NumberScale::OCT, true); break;
        case 'p': this->_SetForcePrefix(false); break;
        case 'P': this->_SetForcePrefix(true); break;
        case 'q': break;
        case 'Q': break;
        case 'r': break;
        case 'R': break;
        case 's': break;
        case 'S': break;
        case 't': break;
        case 'T': break;
        case 'u': break;
        case 'U': break;
        case 'v': break;
        case 'V': break;
        case 'w': break;
        case 'W': break;
        case 'x': this->_SetScale(hasScaleSet, NumberScale::HEX, false); break;
        case 'X': this->_SetScale(hasScaleSet, NumberScale::HEX, true); break;
        case 'y': break;
        case 'Y': break;
        case 'z': break;
        case 'Z': break;

        default: break;
        }
    }
    __PRI__ void _TrimSpace(const ::string __VARIABLE__ format_str, int32 __VARIABLE__ length, int32 __REFERENCE__ index)
    {
        for (;index < length; ++index)
            if
                (
                    'a' <= format_str[index] && 'z' >= format_str[index]
                    || 'A' <= format_str[index] && 'Z' >= format_str[index]
                    || '0' <= format_str[index] && '9' >= format_str[index]
                    )
                break;
    }
    __PRI__ void _SetScale(bool __REFERENCE__ hasScaleSet, NumberScale __VARIABLE__ scale, bool __VARIABLE__ prefix)
    {
        if (hasScaleSet)
            throw _ty_base_number_string_convertion_formatter_error_duplicate_scale;

        this->_Scale = scale;
        this->_Prefix = prefix;
        hasScaleSet = true;
    }
    __PRI__ void _SetForcePrefix(bool __VARIABLE__ hasPrefix)
    {
        if (ForcePrefix::Unassign != this->_ForcePrefix)
            throw _ty_base_number_string_convertion_formatter_error_duplicate_prefix;

        this->_ForcePrefix = hasPrefix ? ForcePrefix::Prefix : ForcePrefix::Unfix;
    }
    __PRI__ int32 _CountChar(const ::string __VARIABLE__ format_str, int32 __VARIABLE__ length, int32 __REFERENCE__ index, const char __VARIABLE__ countCh)
    {
        int count = 1;

        for (; index < length - 1; ++index)
            if (countCh == format_str[index])
                count += 1;
            else
                break;

        return count;
    }

    __PUB__ NumberScale GetScale()
    {
        return this->_Scale;
    }
    __PUB__ bool        HasPrefix()
    {
        return ForcePrefix::Unassign == this->_ForcePrefix && this->_Prefix
            || ForcePrefix::Prefix == this->_ForcePrefix;
    }
    __PUB__ bool        IsUpperCase()
    {
        return this->_CharCase;
    }
    __PUB__ bool        HasDigitLimit()
    {
        // only when the total digits count is -1, the limit is false
        return -1 != this->GetValueDigits();
    }
    __PUB__ int32       GetIntegerDigits()
    {
        return this->_IntegerDigits;
    }
    __PUB__ int32       GetFloatDigits()
    {
        return this->_FloatDigits;
    }
    __PUB__ int32       GetValueDigits()
    {
        // to check cases to return integer digits:
        // 1. integer digits is set and larger than total
        // 2. integer digits is not set
        return this->_IntegerDigits > this->_TotalDigits || -1 == this->_IntegerDigits
            ? this->_IntegerDigits
            : this->_TotalDigits;
    }
    __PUB__ char        GetFillChar()
    {
        return '\0' == this->_FillChar ? '0' : this->_FillChar;
    }
};


// #################################################################################################
// #################################################################################################
// Tianyu Object Base (TianyuObject) Implementation
// #################################################################################################
// #################################################################################################

__construction__ dty::TianyuObject::TianyuObject()
    : dty::IToString()
{ }

__destruction__  dty::TianyuObject::~TianyuObject()
{ }

bool dty::TianyuObject::IsNull()
{
    return false;
}

bool dty::TianyuObject::Equals(dty::TianyuObject& obj)
{
    return this->GetTypeId() == obj.GetTypeId() && this->GetHashCode() == obj.GetHashCode();
}

bool dty::TianyuObject::operator==(dty::TianyuObject& obj)
{
    return this->GetTypeId() == obj.GetTypeId() && this->GetHashCode() == obj.GetHashCode();
}

::string dty::TianyuObject::ToString() noexcept
{
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

uint64 dty::TianyuObject::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

uint64   dty::TianyuObject::GetHashCode()
{
    return (uint64)(this);
}

bool dty::TianyuObject::IsNull(dty::TianyuObject& obj)
{
    return obj.IsNull();
}


// #################################################################################################
// #################################################################################################
// Tianyu Base Tools Implementation
// #################################################################################################
// #################################################################################################

const int32 _ty_base_value_align_error_base_zero = -1;

int32 __VARIABLE__ dty::ValueAlign(int32 __VARIABLE__ value, int32 __VARIABLE__ base)
{
    if (0 >= base)
        throw _ty_base_value_align_error_base_zero;

    if (0 == value)
        return base;

    int32 integerMultiple = value / base;
    bool isMoreThanBase = value % base != 0;

    return integerMultiple * base + isMoreThanBase ? base : 0;
}
int32 __VARIABLE__ dty::ValueAlignByPow(int32 __VARIABLE__ value, int32 __VARIABLE__ power)
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

    return value & andBase == 0 ? value : (value & (~andBase)) + base;
}