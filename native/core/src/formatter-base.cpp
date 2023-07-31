#include "../internal.h"
#include "../formatter.hpp"

_enum ForcePrefix : byte
{
    Unassign,
    Prefix,
    Unfix
};

_enum FormatAlign : byte
{
    Unassign,
    Left,
    Right
};

_enum CharCase : byte
{
    Unassign,
    Upper,
    Lower
};

extern const int32 _tianyu_except_number_formatter_error_duplicate_scale;
extern const int32 _tianyu_except_number_formatter_error_duplicate_prefix;
extern const int32 _tianyu_except_number_formatter_error_duplicate_count_int;
extern const int32 _tianyu_except_number_formatter_error_duplicate_count_float;
extern const int32 _tianyu_except_number_formatter_error_duplicate_count_times;
extern const int32 _tianyu_except_number_formatter_error_duplicate_align;
extern const int32 _tianyu_except_number_formatter_error_duplicate_sym_force;
extern const int32 _tianyu_except_number_formatter_error_duplicate_char_case;
extern const int32 _tianyu_except_number_formatter_error_duplicate_fill_char;
extern const int32 _tianyu_except_number_formatter_error_fill_char_not_assign;

class TYBaseNumberStringConvertionFormatter : public virtual tianyu::TianyuObject
{
    __PRI__ NumberScale __VARIABLE__ _Scale;
    __PRI__ ForcePrefix __VARIABLE__ _ForcePrefix;
    __PRI__ bool        __VARIABLE__ _Prefix;
    __PRI__ CharCase    __VARIABLE__ _CharCase;
    __PRI__ bool        __VARIABLE__ _CharCase_S;
    __PRI__ int32       __VARIABLE__ _IntegerDigits;
    __PRI__ int32       __VARIABLE__ _FloatDigits;
    __PRI__ int32       __VARIABLE__ _TotalDigits;
    __PRI__ char        __VARIABLE__ _FillChar;
    __PRI__ bool        __VARIABLE__ _FillCharSet;
    __PRI__ FormatAlign __VARIABLE__ _ValueAlign;
    __PRI__ bool        __VARIABLE__ _ForceSymbol;

    __PUB__         TYBaseNumberStringConvertionFormatter(const ::string __VARIABLE__ format_str)
        : tianyu::TianyuObject(),
        _Scale(NumberScale::DEC),
        _ForcePrefix(ForcePrefix::Unassign),
        _Prefix(false),
        _CharCase(CharCase::Unassign),
        _CharCase_S(false),
        _IntegerDigits(-1),
        _FloatDigits(-1),
        _TotalDigits(-1),
        _FillChar('0'),
        _FillCharSet(false),
        _ForceSymbol(false),
        _ValueAlign(FormatAlign::Unassign)
    {
        if (::null == format_str)
            return;

        int32 length = tianyu::strlen(format_str);
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

        for (; index < length; ++index)
        {
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
                    throw _tianyu_except_number_formatter_error_duplicate_count_int;

                this->_IntegerDigits = this->_CountChar(format_str, length, index, 'D');
                break;
            case 'e': break;
            case 'E': break;
            case 'f':
                if (-1 != this->_FloatDigits)
                    throw _tianyu_except_number_formatter_error_duplicate_count_float;

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
            case 'L':
                if (FormatAlign::Unassign != this->_ValueAlign)
                    throw _tianyu_except_number_formatter_error_duplicate_align;

                this->_ValueAlign = FormatAlign::Left;
                break;
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
            case 'r':
                if (this->_FillCharSet)
                    throw _tianyu_except_number_formatter_error_duplicate_fill_char;

                if (index + 1 < length)
                {
                    this->_FillChar = format_str[++index];
                    this->_FillCharSet = true;
                }
                else
                    throw _tianyu_except_number_formatter_error_fill_char_not_assign;
                break;
            case 'R':
                if (FormatAlign::Unassign != this->_ValueAlign)
                    throw _tianyu_except_number_formatter_error_duplicate_align;

                this->_ValueAlign = FormatAlign::Right;
                break;
            case 's':
                if (this->_ForceSymbol)
                    throw _tianyu_except_number_formatter_error_duplicate_sym_force;

                this->_ForceSymbol = true;
                break;
            case 'S': break;
            case 't': break;
            case 'T': break;
            case 'u':
                if (CharCase::Unassign != this->_CharCase)
                    throw _tianyu_except_number_formatter_error_duplicate_char_case;

                this->_CharCase = CharCase::Lower;
                break;
            case 'U':
                if (CharCase::Unassign != this->_CharCase)
                    throw _tianyu_except_number_formatter_error_duplicate_char_case;

                this->_CharCase = CharCase::Upper;
                break;
            case 'v': break;
            case 'V': break;
            case 'w': break;
            case 'W': break;
            case 'x':
                this->_SetScale(hasScaleSet, NumberScale::HEX, true);
                this->_CharCase_S = false;
                break;
            case 'X':
                this->_SetScale(hasScaleSet, NumberScale::HEX, true);
                this->_CharCase_S = true;
                break;
            case 'y': break;
            case 'Y': break;
            case 'z': break;
            case 'Z': break;

            default: break;
            }
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
            throw _tianyu_except_number_formatter_error_duplicate_scale;

        this->_Scale = scale;
        this->_Prefix = prefix;
        hasScaleSet = true;
    }
    __PRI__ void _SetForcePrefix(bool __VARIABLE__ hasPrefix)
    {
        if (ForcePrefix::Unassign != this->_ForcePrefix)
            throw _tianyu_except_number_formatter_error_duplicate_prefix;

        this->_ForcePrefix = hasPrefix ? ForcePrefix::Prefix : ForcePrefix::Unfix;
    }
    __PRI__ int32 _CountChar(const ::string __VARIABLE__ format_str, int32 __VARIABLE__ length, int32 __REFERENCE__ index, const char __VARIABLE__ countCh)
    {
        int count = 1;

        for (index = index + 1; index < length; ++index)
            if (countCh == format_str[index])
                count += 1;
            else
            {
                // the current char is not matched, roll back the index
                index -= 1;
                break;
            }

        return count;
    }

    __PUB__ NumberScale GetScale()
    {
        return this->_Scale;
    }
    __PUB__ bool        HasPrefix()
    {
        return (
            ForcePrefix::Unassign == this->_ForcePrefix && this->_Prefix
            || ForcePrefix::Prefix == this->_ForcePrefix
            )
            && NumberScale::DEC != this->_Scale;
    }
    __PUB__ bool        IsUpperCase()
    {
        return CharCase::Upper == this->_CharCase || CharCase::Unassign == this->_CharCase && this->_CharCase_S;
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
    __PUB__ bool        IsLeftAlign()
    {
        return FormatAlign::Left == this->_ValueAlign;
    }
    __PUB__ bool        IsForceSymbol()
    {
        return this->_ForceSymbol;
    }
};

const int32 tianyu_core_cpp_imp_str_cmp_eq = 0;
const int32 tianyu_core_cpp_imp_str_cmp_gt = 1;
const int32 tianyu_core_cpp_imp_str_cmp_lt = -1;

int32 tianyu_core_cpp_imp_str_cmp(::string str1, ::string str2)
{
    if (::null == str1 && ::null == str2)
        return tianyu_core_cpp_imp_str_cmp_eq;

    if (::null == str1 && ::null != str2)
        return tianyu_core_cpp_imp_str_cmp_lt;

    if (::null != str1 && ::null == str2)
        return tianyu_core_cpp_imp_str_cmp_gt;

    int32 str1Len = tianyu::strlen(str1);
    int32 str2Len = tianyu::strlen(str2);

    for (int32 i = 0; i < str1Len && i < str2Len; ++i)
    {
        if (str1[i] < str2[i])
            return tianyu_core_cpp_imp_str_cmp_lt;
        if (str1[i] > str2[i])
            return tianyu_core_cpp_imp_str_cmp_gt;
    }

    return str1Len == str2Len
        ? tianyu_core_cpp_imp_str_cmp_eq : str1Len < str2Len
        ? tianyu_core_cpp_imp_str_cmp_lt : tianyu_core_cpp_imp_str_cmp_gt;
}

const ::string tianyu_core_to_string_no_formatter = (const ::string)"";

// integer part
::string tianyu_core_cpp_imp_num2str_formatter_combiner
(
    ::string value,
    int32 valueLength,
    bool negative,
    TYBaseNumberStringConvertionFormatter& formatter
)
{
    // to calculate the result string length
    // consider three conditions:
    // 1. add 2, if has prefix
    // 2. set value length is that the maximum value between converted length and value digits defined in format object
    // 3. add 1, if force positive or negative symbol
    int32 resultLength =
        (formatter.HasPrefix() ? 2 : 0)
        + (formatter.HasDigitLimit() && formatter.GetValueDigits() > valueLength ? formatter.GetValueDigits() - (formatter.IsForceSymbol() || negative ? 1 : 0) : valueLength)
        + (formatter.IsForceSymbol() || negative ? 1 : 0);

    // create the result string and set the result ending. 
    ::string result = new char[resultLength + 1];
    result[resultLength] = '\0';

    int32 resultIndex = 0;
    // set pre-negative symbol
    if (formatter.IsForceSymbol() || negative)
        result[resultIndex++] = negative ? '-' : '+';
    // set prefix, consider the upper case
    if (formatter.HasPrefix())
    {
        if (NumberScale::OCT == formatter.GetScale())
        {
            result[resultIndex++] = '\\';
            result[resultIndex++] = '0';
        }
        else
        {
            result[resultIndex++] = '0';
            result[resultIndex++] = NumberScale::BIN == formatter.GetScale()
                ? formatter.IsUpperCase() ? 'B' : 'b'
                : 'x';
        }
    }

    // consider left align
    if (formatter.IsLeftAlign())
    {
        // copy value
        for (int32 i = 0; i < valueLength; ++i, ++resultIndex)
            result[resultIndex] = value[i];

        // set blank space to fill result.
        for (; resultIndex < resultLength; ++resultIndex)
            result[resultIndex] = ' ';
    }
    else
    {
        // calculate the fill chars count
        int32 fillLength = resultLength - valueLength;

        // set Fill-Char to fill result.
        char fillChar = formatter.GetFillChar();
        for (; resultIndex < fillLength; ++resultIndex)
            result[resultIndex] = fillChar;

        // copy value
        for (int32 i = 0; i < valueLength && resultIndex < resultLength; ++i, ++resultIndex)
            result[resultIndex] = value[valueLength - i - 1];
    }

    return result;
}
::string tianyu_core_cpp_imp_num2str_bin_formatter
(
    uint64 value,
    int32 binSize,
    bool negative,
    TYBaseNumberStringConvertionFormatter& formatter
)
{
    int32 stackIndex = 0;
    ::string buffer = new char[binSize];

    // to get the pure converted string
    if (0 == value)
        buffer[stackIndex++] = '0';
    else
    {
        for (; stackIndex < binSize && 0 != value; ++stackIndex)
        {
            buffer[stackIndex] = (char)(48 + (value & 0b01));
            value = value >> 1;
        }
    }

    ::string result = ::tianyu_core_cpp_imp_num2str_formatter_combiner(buffer, stackIndex, negative, formatter);
    delete [] buffer;

    return result;
}
::string tianyu_core_cpp_imp_num2str_oct_formatter
(
    uint64 value,
    int32 binSize,
    bool negative,
    TYBaseNumberStringConvertionFormatter& formatter
)
{
    int32 stackIndex = 0;
    ::string buffer = new char[binSize / 3 + 1];

    // to get the pure converted string
    if (0 == value)
        buffer[stackIndex++] = '0';
    else
    {
        for (; stackIndex < binSize && 0 != value; ++stackIndex)
        {
            buffer[stackIndex] = (char)(48 + (value & 0b111));
            value = value >> 3;
        }
    }

    ::string result = ::tianyu_core_cpp_imp_num2str_formatter_combiner(buffer, stackIndex, negative, formatter);
    delete [] buffer;

    return result;
}
::string tianyu_core_cpp_imp_num2str_dec_formatter
(
    uint64 value,
    int32 binSize,
    bool negative,
    TYBaseNumberStringConvertionFormatter& formatter
)
{
    int32 stackIndex = 0;
    ::string buffer = new char[binSize / 3 + 1];

    // to get the pure converted string
    if (0 == value)
        buffer[stackIndex++] = '0';
    else
    {
        for (; stackIndex < binSize && 0 != value; ++stackIndex)
        {
            buffer[stackIndex] = (char)(48 + (value % 10));
            value = value / 10;
        }
    }

    ::string result = ::tianyu_core_cpp_imp_num2str_formatter_combiner(buffer, stackIndex, negative, formatter);
    delete [] buffer;

    return result;
}
::string tianyu_core_cpp_imp_num2str_hex_formatter
(
    uint64 value,
    int32 binSize,
    bool negative,
    TYBaseNumberStringConvertionFormatter& formatter
)
{
    int32 stackIndex = 0;
    ::string buffer = new char[binSize >> 2];

    // to get the pure converted string
    if (0 == value)
        buffer[stackIndex++] = '0';
    else
    {
        bool isUpper = formatter.IsUpperCase();
        for (; stackIndex < binSize && 0 != value; ++stackIndex)
        {
            int32 temp = value & 0b1111;
            buffer[stackIndex] = (char)((10 > temp ? 48 : isUpper ? 55 : 87) + temp);
            value = value >> 4;
        }
    }

    ::string result = ::tianyu_core_cpp_imp_num2str_formatter_combiner(buffer, stackIndex, negative, formatter);
    delete [] buffer;

    return result;
}
::string tianyu_core_cpp_imp_num2str_asc_formatter
(
    uint64 value,
    int32 binSize,
    bool negative,
    TYBaseNumberStringConvertionFormatter& formatter
)
{
    int32 stackIndex = 0;
    ::string buffer = new char[binSize >> 3];

    // to get the pure converted string
    for (; stackIndex < binSize && 0 != value; ++stackIndex)
    {
        buffer[stackIndex] = (char)(value & 0xFF);
        value = value >> 8;
    }

    ::string result = ::tianyu_core_cpp_imp_num2str_formatter_combiner(buffer, stackIndex, negative, formatter);
    delete [] buffer;

    return result;
}

::string tianyu_core_cpp_imp_num2str_formatter
(
    uint64 value,
    int32 binSize,
    bool negative,
    TYBaseNumberStringConvertionFormatter& formatter
)
{
    switch (formatter.GetScale())
    {
    case ::NumberScale::BIN: return ::tianyu_core_cpp_imp_num2str_bin_formatter(value, binSize, negative, formatter);
    case ::NumberScale::OCT: return ::tianyu_core_cpp_imp_num2str_oct_formatter(value, binSize, negative, formatter);
    case ::NumberScale::DEC: return ::tianyu_core_cpp_imp_num2str_dec_formatter(value, binSize, negative, formatter);
    case ::NumberScale::HEX: return ::tianyu_core_cpp_imp_num2str_hex_formatter(value, binSize, negative, formatter);
    case ::NumberScale::ASC:
    default: return ::tianyu_core_cpp_imp_num2str_asc_formatter(value, binSize, negative, formatter);
    }

}

::string tianyu_core_cpp_imp_c2str(char ch, const ::string formatter)
{
    if (tianyu_core_cpp_imp_str_cmp_eq == ::tianyu_core_cpp_imp_str_cmp(formatter, ::tianyu_core_to_string_no_formatter))
    {
        ::string result = new char[2];
        result[0] = ch;
        result[1] = '\0';

        return result;
    }

    // to get the formate object from formatter string
    TYBaseNumberStringConvertionFormatter formatObj(formatter);

    // prepare inital datas
    bool isNegative = false;
    if (0 > ch)
    {
        // need to handle negative case
        isNegative = true;
        ch = -ch;
    }

    return ::tianyu_core_cpp_imp_num2str_formatter(ch, __CHAR_TYPE_BINARY_LENGTH__, isNegative, formatObj);
}
::string tianyu_core_cpp_imp_uc2str(uchar uc, const ::string formatter)
{
    if (tianyu_core_cpp_imp_str_cmp_eq == ::tianyu_core_cpp_imp_str_cmp(formatter, ::tianyu_core_to_string_no_formatter))
    {
        ::string result = new char[2];
        result[0] = (char)uc;
        result[1] = '\0';

        return result;
    }

    // to get the formate object from formatter string
    TYBaseNumberStringConvertionFormatter formatObj(formatter);

    return ::tianyu_core_cpp_imp_num2str_formatter(uc, __CHAR_TYPE_BINARY_LENGTH__, false, formatObj);
}
::string tianyu_core_cpp_imp_sb2str(sbyte sb, const ::string formatter)
{
    // to get the formate object from formatter string
    TYBaseNumberStringConvertionFormatter formatObj(formatter);

    // prepare inital datas
    bool isNegative = false;
    if (0 > sb)
    {
        // need to handle negative case
        isNegative = true;
        sb = -sb;
    }

    return ::tianyu_core_cpp_imp_num2str_formatter(sb, __BYTE_TYPE_BINARY_LENGTH__, isNegative, formatObj);
}
::string tianyu_core_cpp_imp_b2str(::byte b, const ::string formatter)
{
    // to get the formate object from formatter string
    TYBaseNumberStringConvertionFormatter formatObj(formatter);

    return ::tianyu_core_cpp_imp_num2str_formatter(b, __BYTE_TYPE_BINARY_LENGTH__, false, formatObj);
}
::string tianyu_core_cpp_imp_s2str(int16 s, const ::string formatter)
{
    // to get the formate object from formatter string
    TYBaseNumberStringConvertionFormatter formatObj(formatter);

    // prepare inital datas
    bool isNegative = false;
    if (0 > s)
    {
        // need to handle negative case
        isNegative = true;
        s = -s;
    }

    return ::tianyu_core_cpp_imp_num2str_formatter(s, __SHORT_TYPE_BINARY_LENGTH__, isNegative, formatObj);
}
::string tianyu_core_cpp_imp_us2str(uint16 us, const ::string formatter)
{
    // to get the formate object from formatter string
    TYBaseNumberStringConvertionFormatter formatObj(formatter);

    return ::tianyu_core_cpp_imp_num2str_formatter(us, __SHORT_TYPE_BINARY_LENGTH__, false, formatObj);
}
::string tianyu_core_cpp_imp_i2str(int32 i, const ::string formatter)
{
    // to get the formate object from formatter string
    TYBaseNumberStringConvertionFormatter formatObj(formatter);

    // prepare inital datas
    bool isNegative = false;
    if (0 > i)
    {
        // need to handle negative case
        isNegative = true;
        i = -i;
    }

    return ::tianyu_core_cpp_imp_num2str_formatter(i, __INT_TYPE_BINARY_LENGTH__, isNegative, formatObj);
}
::string tianyu_core_cpp_imp_ui2str(uint32 ui, const ::string formatter)
{
    // to get the formate object from formatter string
    TYBaseNumberStringConvertionFormatter formatObj(formatter);

    return ::tianyu_core_cpp_imp_num2str_formatter(ui, __INT_TYPE_BINARY_LENGTH__, false, formatObj);
}
::string tianyu_core_cpp_imp_l2str(int64 l, const ::string formatter)
{
    // to get the formate object from formatter string
    TYBaseNumberStringConvertionFormatter formatObj(formatter);

    // prepare inital datas
    bool isNegative = false;
    if (0 > l)
    {
        // need to handle negative case
        isNegative = true;
        l = -l;
    }

    return ::tianyu_core_cpp_imp_num2str_formatter(l, __LONG_TYPE_BINARY_LENGTH__, isNegative, formatObj);
}
::string tianyu_core_cpp_imp_ul2str(uint64 ul, const ::string formatter)
{
    // to get the formate object from formatter string
    TYBaseNumberStringConvertionFormatter formatObj(formatter);

    return ::tianyu_core_cpp_imp_num2str_formatter(ul, __LONG_TYPE_BINARY_LENGTH__, false, formatObj);
}

// float format part: should be processed in another way (corrently is not relized)
::string tianyu_core_cpp_imp_f2str(float f, const ::string formatter)
{
    TYBaseNumberStringConvertionFormatter formatObj(formatter);

    return ::null;
}
::string tianyu_core_cpp_imp_d2str(double d, const ::string formatter)
{
    TYBaseNumberStringConvertionFormatter formatObj(formatter);

    return ::null;
}

::string c2str(char ch)
{
    return ::tianyu_core_cpp_imp_c2str(ch, tianyu_core_to_string_no_formatter);
}
::string uc2str(uchar ch)
{
    return ::tianyu_core_cpp_imp_uc2str(ch, tianyu_core_to_string_no_formatter);
}
::string sb2str(sbyte sb)
{
    return ::tianyu_core_cpp_imp_sb2str(sb, tianyu_core_to_string_no_formatter);
}
::string b2str(::byte b)
{
    return ::tianyu_core_cpp_imp_sb2str(b, tianyu_core_to_string_no_formatter);
}
::string s2str(int16 s)
{
    return ::tianyu_core_cpp_imp_sb2str(s, tianyu_core_to_string_no_formatter);
}
::string us2str(uint16 us)
{
    return ::tianyu_core_cpp_imp_sb2str(us, tianyu_core_to_string_no_formatter);
}
::string i2str(int32 i)
{
    return ::tianyu_core_cpp_imp_sb2str(i, tianyu_core_to_string_no_formatter);
}
::string ui2str(uint32 ui)
{
    return ::tianyu_core_cpp_imp_sb2str(ui, tianyu_core_to_string_no_formatter);
}
::string l2str(int64 l)
{
    return ::tianyu_core_cpp_imp_sb2str(l, tianyu_core_to_string_no_formatter);
}
::string ul2str(uint64 ul)
{
    return ::tianyu_core_cpp_imp_sb2str(ul, tianyu_core_to_string_no_formatter);
}
::string f2str(float f)
{
    return ::tianyu_core_cpp_imp_f2str(f, tianyu_core_to_string_no_formatter);
}
::string d2str(double d)
{
    return ::tianyu_core_cpp_imp_d2str(d, tianyu_core_to_string_no_formatter);
}

::string c2str_f(char ch, const ::string formatter)
{
    return ::tianyu_core_cpp_imp_c2str(ch, formatter);
}
::string uc2str_f(uchar sb, const ::string formatter)
{
    return ::tianyu_core_cpp_imp_uc2str(sb, formatter);
}
::string sb2str_f(sbyte sb, const ::string formatter)
{
    return ::tianyu_core_cpp_imp_sb2str(sb, formatter);
}
::string b2str_f(::byte b, const ::string formatter)
{
    return ::tianyu_core_cpp_imp_b2str(b, formatter);
}
::string s2str_f(int16 s, const ::string formatter)
{
    return ::tianyu_core_cpp_imp_s2str(s, formatter);
}
::string us2str_f(uint16 us, const ::string formatter)
{
    return ::tianyu_core_cpp_imp_us2str(us, formatter);
}
::string i2str_f(int32 i, const ::string formatter)
{
    return ::tianyu_core_cpp_imp_i2str(i, formatter);
}
::string ui2str_f(uint32 ui, const ::string formatter)
{
    return ::tianyu_core_cpp_imp_ui2str(ui, formatter);
}
::string l2str_f(int64 l, const ::string formatter)
{
    return ::tianyu_core_cpp_imp_l2str(l, formatter);
}
::string ul2str_f(uint64 ul, const ::string formatter)
{
    return ::tianyu_core_cpp_imp_ul2str(ul, formatter);
}
::string f2str_f(float f, const ::string formatter)
{
    return ::tianyu_core_cpp_imp_f2str(f, formatter);
}
::string d2str_f(double d, const ::string formatter)
{
    return ::tianyu_core_cpp_imp_d2str(d, formatter);
}


