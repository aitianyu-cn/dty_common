#include"../string.hpp"

dty::String dty::String::Empty = dty::String();

dty::String::String()
    : dty::collection::IEquatable<dty::String>(),
    dty::collection::ICompareable<dty::String>()
{
    this->_StringValue = new char[1]{ '\0' };
    this->_StringLength = 0;
    this->_Reference = new int32(1);
}

dty::String::String(dty::string_sp item)
    : dty::collection::IEquatable<dty::String>(),
    dty::collection::ICompareable<dty::String>()
{
    if (item.IsNull())
        throw dty::except::ArgumentNullException();

    this->_StringValue = new char[item.Size + 1];
    this->_StringLength = item.Size;
    this->_Reference = new int32(1);

    for (int i = 0; i < this->_StringLength; ++i)
        this->_StringValue[i] = item[i];
    this->_StringValue[this->_StringLength] = '\0';
}

dty::String::String(const char item, int32 repeat)
    : dty::collection::IEquatable<dty::String>(),
    dty::collection::ICompareable<dty::String>()
{
    if (0 >= repeat)
        throw dty::except::ArgumentOutOfRangeException();

    this->_StringValue = new char[repeat + 1];
    this->_StringLength = repeat;
    this->_Reference = new int32(1);

    for (int i = 0; i < repeat; ++i)
        this->_StringValue[i] = item;

    this->_StringValue[repeat] = '\0';
}

dty::String::String(const string str, int32 length)
    : dty::collection::IEquatable<dty::String>(),
    dty::collection::ICompareable<dty::String>()
{
    if (::null == str)
        throw dty::except::ArgumentNullException();

    int32 strLength = strlen(str);
    if (0 >= length || strLength != length)
        throw dty::except::ArgumentOutOfRangeException();

    this->_StringValue = new char[length + 1];
    this->_StringLength = length;
    this->_Reference = new int32(1);

    for (int i = 0; i < length; ++i)
        this->_StringValue[i] = str[i];
    this->_StringValue[length] = '\0';
}

dty::String::String(const string str, int32 length, bool notCopy)
    : dty::collection::IEquatable<dty::String>(),
    dty::collection::ICompareable<dty::String>()
{
    if (::null == str)
        throw dty::except::ArgumentNullException();

    int32 strLength = strlen(str);
    if (0 >= length || strLength != length)
        throw dty::except::ArgumentOutOfRangeException();

    if (notCopy)
    {
        this->_StringValue = str;
        this->_StringLength = length;
    }
    else
    {
        this->_StringValue = new char[length + 1];
        this->_StringLength = length;

        for (int i = 0; i < length; ++i)
            this->_StringValue[i] = str[i];
        this->_StringValue[length] = '\0';
    }
    this->_Reference = new int32(1);
}

dty::String::String(const string str, int32 startIndex, int32 endIndex)
    : dty::collection::IEquatable<dty::String>(),
    dty::collection::ICompareable<dty::String>()
{
    if (::null == str)
        throw dty::except::ArgumentNullException();

    int32 strLength = strlen(str);
    if (0 > startIndex || 0 > endIndex || startIndex > endIndex || strLength <= startIndex || strLength <= endIndex)
        throw dty::except::ArgumentOutOfRangeException();

    this->_StringLength = endIndex - startIndex + 1;
    this->_StringValue = new char[this->_StringLength + 1];
    this->_Reference = new int32(1);

    for (int i = 0; i < this->_StringLength; ++i)
        this->_StringValue[i] = str[i + startIndex];
    this->_StringValue[this->_StringLength] = '\0';
}

dty::String::String(const String& str)
    : dty::collection::IEquatable<dty::String>(),
    dty::collection::ICompareable<dty::String>(),
    _StringValue(str._StringValue),
    _StringLength(str._StringLength),
    _Reference(str._Reference)
{
    (this->_Reference) += 1;
}

dty::String::String(const string str)
    : dty::collection::IEquatable<dty::String>(),
    dty::collection::ICompareable<dty::String>()
{
    if (::null == str)
        throw dty::except::ArgumentNullException();

    int32 strLength = strlen(str);

    this->_StringValue = new char[strLength + 1];
    this->_StringLength = strLength;
    this->_Reference = new int32(1);

    for (int i = 0; i < strLength; ++i)
        this->_StringValue[i] = str[i];
    this->_StringValue[strLength] = '\0';
}

dty::String::~String()
{
    this->Release();
}

void dty::String::Release()
{
    if (1 < (__PTR_TO_VAR__(this->_Reference)))
        (this->_Reference) -= 1;
    else
    {
        delete this->_Reference;
        delete [] this->_StringValue;
    }
}

void dty::String::UpdateSource(int32 length, string str)
{
    if (1 == (__PTR_TO_REF__(this->_Reference)))
        delete [] this->_StringValue;
    else
    {
        __PTR_TO_VAR__(this->_Reference) -= 1;
        this->_Reference = new int32(1);
    }
    this->_StringLength = length;
    this->_StringValue = str;
}

bool dty::String::IsEmpty()
{
    return 0 == this->_StringLength;
}

bool dty::String::RemoveAt(int32 index)
{
    if (0 > index || index >= this->_StringLength)
        return false;

    try
    {
        string newStr = new char[this->_StringLength];
        int32 newLength = this->_StringLength - 1;
        for (int32 i = 0; i < index; ++i)
            newStr[i] = this->_StringValue[i];

        for (int32 i = index; i < newLength; ++i)
            newStr[i] = this->_StringValue[i + 1];
        newStr[newLength] = '\0';

        this->UpdateSource(newLength, newStr);

        return true;
    }
    catch (const std::exception)
    {
        return false;
    }
}

void dty::String::Clear()
{
    (__PTR_TO_REF__ this) = dty::String::Empty;
}

char dty::String::operator[](int32 index)
{
    if (0 > index || index >= this->_StringLength)
        throw dty::except::ArgumentOutOfRangeException();

    return this->_StringValue[index];
}

bool dty::String::EndWith(const char ch)
{
    if (0 == this->_StringLength || '\0' == ch)
        return false;

    return ch == this->_StringValue[this->_StringLength - 1];
}

bool dty::String::EndWith(String& str)
{
    if (0 == this->_StringLength || 0 == str.Length || str.Length > this->_StringLength)
        return false;

    for (int i = str.Length - 1, j = this->_StringLength - 1; i >= 0; --i, --j)
        if (this->_StringValue[j] != str._StringValue[i])
            return false;

    return true;
}

bool dty::String::Contains(const char ch)
{
    if (0 == this->_StringLength || '\0' == ch)
        return false;

    for (int32 i = 0; i < this->_StringLength; ++i)
        if (ch == this->_StringValue[i])
            return true;

    return false;
}

bool dty::String::Contains(const String& str)
{
    // Todo
    throw dty::except::NotImplementationException();
}

int32 dty::String::IndexOf(const char ch)
{
    if (0 == this->_StringLength || '\0' == ch)
        return -1;

    for (int32 i = 0; i < this->_StringLength; ++i)
        if (ch == this->_StringValue[i])
            return i;

    return -1;
}

int32 dty::String::IndexOf(const char ch, int32 startIndex)
{
    if (0 > startIndex || startIndex >= this->_StringLength)
        throw dty::except::ArgumentOutOfRangeException();

    if (0 == this->_StringLength || '\0' == ch)
        return -1;

    for (int32 i = startIndex; i < this->_StringLength; ++i)
        if (ch == this->_StringValue[i])
            return i;

    return -1;
}

int32 dty::String::IndexOf(const char ch, int32 startIndex, int32 endIndex)
{
    if (0 > startIndex || startIndex >= this->_StringLength
        || 0 > endIndex || startIndex > endIndex || endIndex >= this->_StringLength)
        throw dty::except::ArgumentOutOfRangeException();

    if ('\0' == ch || 0 == this->_StringLength)
        return -1;

    for (int32 i = startIndex; i <= endIndex; ++i)
        if (ch == this->_StringValue[i])
            return i;

    return -1;
}

int32 dty::String::IndexOf(String& str)
{
    // Todo
    throw dty::except::NotImplementationException();
}

int32 dty::String::IndexOf(String& str, int32 startIndex)
{
    // Todo
    throw dty::except::NotImplementationException();
}

int32 dty::String::IndexOf(String& str, int32 startIndex, int32 endIndex)
{
    // Todo
    throw dty::except::NotImplementationException();
}

dty::String dty::String::Insert(int32 insertIndex, const char ch)
{
    if (0 > insertIndex || insertIndex > this->_StringLength)
        throw dty::except::ArgumentOutOfRangeException();

    if ('\0' != ch)
    {
        string newStr = new char[this->_StringLength + 2];
        for (int32 i = 0; i < insertIndex; ++i)
            newStr[i] = this->_StringValue[i];

        newStr[insertIndex] = ch;

        for (int32 i = insertIndex; i <= this->_StringLength; ++i)
            newStr[i + 1] = this->_StringValue[i];

        this->UpdateSource(this->_StringLength + 1, newStr);
    }

    return (__PTR_TO_VAR__ this);
}

dty::String dty::String::Insert(int32 insertIndex, string str)
{
    if (::null == str)
        throw dty::except::ArgumentNullException();

    if (0 > insertIndex || insertIndex > this->_StringLength)
        throw dty::except::ArgumentOutOfRangeException();

    int32 otherStrLength = strlen(str);
    if (0 != otherStrLength)
    {
        int32 newStrLength = this->_StringLength + otherStrLength;
        string newStr = new char[newStrLength + 1];

        for (int32 i = 0; i < insertIndex; ++i)
            newStr[i] = this->_StringValue[i];

        for (int32 i = 0; i < otherStrLength; ++i)
            newStr[i + insertIndex] = str[i];

        for (int32 i = insertIndex; i <= this->_StringLength; ++i)
            newStr[i + otherStrLength] = this->_StringValue[i];

        this->UpdateSource(newStrLength, newStr);
    }

    return (__PTR_TO_VAR__ this);
}

dty::String dty::String::Insert(int32 insertIndex, dty::String& str)
{
    return this->Insert(insertIndex, str._StringValue);
}

int32 dty::String::LastIndexOf(const char ch)
{
    if ('\0' == ch || 0 == this->_StringLength)
        return -1;

    for (int32 i = this->_StringLength - 1; i >= 0; --i)
        if (ch == this->_StringValue[i])
            return i;

    return -1;
}

int32 dty::String::LastIndexOf(const char ch, int32 startIndex)
{
    if (0 > startIndex || startIndex >= this->_StringLength)
        throw dty::except::ArgumentOutOfRangeException();

    if ('\0' == ch || 0 == this->_StringLength)
        return -1;

    for (int32 i = this->_StringLength - 1; i >= startIndex; --i)
        if (ch == this->_StringValue[i])
            return i;

    return -1;
}

int32 dty::String::LastIndexOf(const char ch, int32 startIndex, int32 endIndex)
{
    if (0 > startIndex || startIndex >= this->_StringLength || 0 > endIndex || startIndex > endIndex || endIndex >= this->_StringLength)
        throw dty::except::ArgumentOutOfRangeException();

    if ('\0' == ch || 0 == this->_StringLength)
        return -1;

    for (int32 i = endIndex; i >= startIndex; --i)
        if (ch == this->_StringValue[i])
            return i;

    return -1;
}

int32 dty::String::LastIndexOf(String& str)
{
    // Todo
    throw dty::except::NotImplementationException();
}

int32 dty::String::LastIndexOf(String& str, int32 startIndex)
{
    // Todo
    throw dty::except::NotImplementationException();
}

int32 dty::String::LastIndexOf(String& str, int32 startIndex, int32 endIndex)
{
    // Todo
    throw dty::except::NotImplementationException();
}

dty::String dty::String::PadLeft(int32 length)
{
    return this->PadLeft(length, ' ');
}

dty::String dty::String::PadLeft(int32 length, const char ch)
{
    if (0 >= length)
        throw dty::except::ArgumentOutOfRangeException();

    if ('\0' == ch)
        throw dty::except::ArgumentException();

    if (length > this->_StringLength)
    {
        string newStr = new char[length + 1];
        int32 fillLength = length - this->_StringLength;
        for (int32 i = 0; i < fillLength; ++i)
            newStr[i] = ch;

        for (int32 i = 0; i < this->_StringLength; ++i)
            newStr[i + fillLength] = this->_StringValue[i];

        newStr[length] = '\0';

        this->UpdateSource(length, newStr);
    }

    return (__PTR_TO_VAR__ this);
}

dty::String dty::String::PadRight(int32 length)
{
    return this->PadRight(length, ' ');
}

dty::String dty::String::PadRight(int32 length, const char ch)
{
    if (0 >= length)
        throw dty::except::ArgumentOutOfRangeException();

    if ('\0' == ch)
        throw dty::except::ArgumentException();

    if (length > this->_StringLength)
    {
        string newStr = new char[length + 1];
        for (int32 i = 0; i < this->_StringLength; ++i)
            newStr[i] = this->_StringValue[i];

        for (int32 i = this->_StringLength; i < length; ++i)
            newStr[i] = ch;

        newStr[length] = '\0';

        this->UpdateSource(length, newStr);
    }

    return (__PTR_TO_VAR__ this);
}

dty::String dty::String::Remove(const char ch)
{
    if ('\0' == ch)
        throw dty::except::ArgumentException();

    if (0 == this->_StringLength)
        return (__PTR_TO_VAR__ this);

    int32 removeLen = 0;
    for (int32 i = 0; i < this->_StringLength; ++i)
        if (ch == this->_StringValue[i])
            ++removeLen;

    if (0 < removeLen)
    {
        int32 newLen = this->_StringLength - removeLen;
        string newStr = new char[newLen + 1];

        for (int32 i = 0, j = 0;j < this->_StringLength; ++i, ++j)
            if (ch == this->_StringValue[j])
                --i;
            else
                newStr[i] = this->_StringValue[j];
        newStr[newLen] = '\0';

        this->UpdateSource(newLen, newStr);
    }
    return (__PTR_TO_VAR__ this);
}

dty::String dty::String::Remove(int32 removeIndex)
{
    this->RemoveAt(removeIndex);

    return (__PTR_TO_VAR__ this);
}

dty::String dty::String::Remove(int32 startIndex, int32 endIndex)
{
    if (0 > startIndex || startIndex >= this->_StringLength || 0 > endIndex || startIndex > endIndex || endIndex >= this->_StringLength)
        throw dty::except::ArgumentOutOfRangeException();

    if (0 < this->_StringLength)
    {
        int32 newLen = this->_StringLength - (endIndex - startIndex + 1);
        string newStr = new char[newLen + 1];

        for (int32 i = 0; i < startIndex; ++i)
            newStr[i] = this->_StringValue[i];

        for (int32 i = endIndex + 1, j = startIndex; i < this->_StringLength; ++i, ++j)
            newStr[j] = this->_StringValue[i];

        newStr[newLen] = '\0';

        this->UpdateSource(newLen, newStr);
    }

    return (__PTR_TO_VAR__ this);
}

dty::String dty::String::Replace(const char findChar, const char replaceChar)
{
    if ('\0' == findChar || '\0' == replaceChar)
        throw dty::except::ArgumentException();

    if (0 < this->_StringLength)
    {
        for (int32 i = 0; i < this->_StringLength; ++i)
            if (findChar == this->_StringValue[i])
                this->_StringValue[i] = replaceChar;
    }

    return (__PTR_TO_VAR__ this);
}

dty::String dty::String::Replace(String& findStr, String& replaceStr)
{
    throw dty::except::NotImplementationException();
}

bool dty::String::StartWith(const char ch)
{
    if ('\0' == ch || 0 == this->_StringLength)
        return false;

    return ch == this->_StringValue[0];
}

bool dty::String::StartWith(String& str)
{
    if (0 == this->_StringLength || 0 == str.Length || this->_StringLength < str.Length)
        return false;

    for (int32 i = 0; i < str.Length; ++i)
        if (this->_StringValue[i] != str._StringValue[i])
            return false;

    return true;
}

dty::String dty::String::ToLower()
{
    if (0 < this->_StringLength)
    {
        for (int32 i = 0; i < this->_StringLength; ++i)
            if ('A' <= this->_StringValue[i] && 'Z' >= this->_StringValue[i])
                this->_StringValue[i] = (char __VARIABLE__)(((int32 __VARIABLE__)this->_StringValue[i]) + 32);
    }

    return (__PTR_TO_VAR__ this);
}

dty::String dty::String::ToUpper()
{
    if (0 < this->_StringLength)
    {
        for (int32 i = 0; i < this->_StringLength; ++i)
            if ('a' <= this->_StringValue[i] && 'z' >= this->_StringValue[i])
                this->_StringValue[i] = (char __VARIABLE__)(((int32 __VARIABLE__)this->_StringValue[i]) - 32);
    }

    return (__PTR_TO_VAR__ this);
}

void dty::String::Trim()
{
    this->TrimStart();
    this->TrimEnd();
}

void dty::String::Trim(const char ch)
{
    this->TrimStart(ch);
    this->TrimEnd(ch);
}

void dty::String::Trim(char ch [], int32 length)
{
    this->TrimStart(ch, length);
    this->TrimEnd(ch, length);
}

void dty::String::TrimStart()
{
    this->TrimStart(' ');
}

void dty::String::TrimStart(const char ch)
{
    if ('\0' == ch)
        throw dty::except::ArgumentException();

    if (0 < this->_StringLength)
    {
        int32 removeLen = 0;
        for (int32 i = 0; i < this->_StringLength; ++i)
            if (ch == this->_StringValue[i])
                ++removeLen;
            else
                break;

        if (0 < removeLen)
        {
            int32 newLen = this->_StringLength - removeLen;
            string newStr = new char[newLen + 1];

            for (int32 i = 0; i < this->_StringLength; ++i)
                newStr[i] = this->_StringValue[i + removeLen];
            newStr[newLen] = '\0';

            this->UpdateSource(newLen, newStr);
        }
    }
}

void dty::String::TrimStart(char ch [], int32 length)
{
    throw dty::except::NotImplementationException();
}

void dty::String::TrimEnd()
{
    this->TrimEnd(' ');
}

void dty::String::TrimEnd(const char ch)
{
    if ('\0' == ch)
        throw dty::except::ArgumentException();

    if (0 < this->_StringLength)
    {
        int32 removeLen = 0;
        for (int32 i = this->_StringLength - 1; i >= 0; --i)
            if (ch == this->_StringValue[i])
                ++removeLen;
            else
                break;

        if (0 < removeLen)
        {
            int32 newLen = this->_StringLength - removeLen;
            string newStr = new char[newLen + 1];

            for (int32 i = 0; i < newLen; ++i)
                newStr[i] = this->_StringValue[i];
            newStr[newLen] = '\0';

            this->UpdateSource(newLen, newStr);
        }
    }
}

void dty::String::TrimEnd(char ch [], int32 length)
{
    throw dty::except::NotImplementationException();
}

::string dty::String::ToCStr()
{
    string cstr = new char[this->_StringLength + 1];
    for (int32 i = 0; i < this->_StringLength; ++i)
        cstr[i] = this->_StringValue[i];
    cstr[this->_StringLength] = '\0';

    return cstr;
}

dty::string_sp dty::String::ToSafeCStr()
{
    return dty::string_sp(this->_StringValue, this->_StringLength, true);
}

dty::collection::CharArray dty::String::ToArray()
{
    return dty::collection::CharArray(this->ToCStr(), this->_StringLength, true);
}

dty::collection::Array<dty::String> dty::String::Split(const char splitChar)
{
    return this->Split(splitChar, false);
}

dty::collection::Array<dty::String> dty::String::Split(const char splitChar, bool ignoreEmpty)
{
    return this->Split(splitChar, -1, false);
}

dty::collection::Array<dty::String> dty::String::Split(const char splitChar, int32 maxSplit)
{
    return this->Split(splitChar, maxSplit, false);
}

dty::collection::Array<dty::String> dty::String::Split(const char splitChar, int32 maxSplit, bool ignoreEmpty)
{
    throw dty::except::NotImplementationException();
}

dty::collection::Array<dty::String> dty::String::Split(String& splitStr, int32 maxSplit)
{
    return this->Split(splitStr, maxSplit, false);
}

dty::collection::Array<dty::String> dty::String::Split(String& splitStr, int32 maxSplit, bool ignoreEmpty)
{
    throw dty::except::NotImplementationException();
}

dty::String dty::String::operator+(dty::String& str)
{
    return (__PTR_TO_REF__ this) + (str._StringValue);
}

dty::String dty::String::operator+(string str)
{
    int32 otherStr = strlen(str);
    if (0 == otherStr)
        return (__PTR_TO_VAR__ this);

    int32 newLen = this->_StringLength + otherStr;
    string newStr = new char[newLen + 1];

    for (int32 i = 0; i < this->_StringLength; ++i)
        newStr[i] = this->_StringValue[i];
    for (int32 i = 0; i < otherStr; ++i)
        newStr[i + this->_StringLength] = str[i];
    newStr[newLen] = '\0';

    return dty::String(newStr, newLen, true);
}

dty::String dty::String::operator+(const char ch)
{
    if ('\0' == ch)
        return (__PTR_TO_VAR__ this);

    string newStr = new char[this->_StringLength + 2];
    for (int32 i = 0; i < this->_StringLength; ++i)
        newStr[i] = this->_StringValue[i];
    newStr[this->_StringLength] = ch;
    newStr[this->_StringLength + 1] = '\0';

    return dty::String(newStr, this->_StringLength + 2, true);
}

dty::String dty::String::operator=(dty::String& source)
{
    if (this->_StringValue != source._StringValue)
    {
        this->Release();
        this->_StringValue = source._StringValue;
        this->_StringLength = source._StringLength;
        this->_Reference = source._Reference;
        (__PTR_TO_VAR__(this->_Reference)) += 1;
    }

    return (__PTR_TO_VAR__ this);
}

dty::String dty::String::operator=(const string source)
{
    if (::null == source)
        throw dty::except::ArgumentNullException();

    this->UpdateSource(strlen(source), source);

    return (__PTR_TO_VAR__ this);
}

dty::String::operator string()
{
    return this->ToCStr();
}

dty::String::operator dty::string_sp()
{
    return this->ToSafeCStr();
}

bool dty::String::Equals(dty::String& other)
{
    return (__PTR_TO_REF__ this) == other;
}

bool dty::String::operator==(dty::String& other)
{
    if (this->_StringLength != other._StringLength)
        return false;

    for (int32 i = 0; i < this->_StringLength; ++i)
        if (this->_StringValue[i] != other._StringValue[i])
            return false;

    return true;
}

bool dty::String::operator!=(dty::String& other)
{
    return !((__PTR_TO_REF__ this) == other);
}

dty::collection::CompareResult dty::String::CompareTo(dty::String& other)
{
    dty::String __REFERENCE__ _this = (__PTR_TO_REF__ this);
    return _this == other ? dty::collection::CompareResult::EQUAL
        : _this > other ? dty::collection::CompareResult::GREAT
        : dty::collection::CompareResult::LESS;
}

bool dty::String::operator<(dty::String& other)
{
    for (int32 i = 0; i < this->_StringLength && i < other._StringLength; ++i)
        if (this->_StringValue[i] >= other._StringValue[i])
            return false;

    if (this->_StringLength >= other._StringLength)
        return false;

    return true;
}

bool dty::String::operator>(dty::String& other)
{
    for (int32 i = 0; i < this->_StringLength && i < other._StringLength; ++i)
        if (this->_StringValue[i] <= other._StringValue[i])
            return false;

    if (this->_StringLength <= other._StringLength)
        return false;

    return true;
}

bool dty::String::operator<=(dty::String& other)
{
    return !((__PTR_TO_REF__ this) > other);
}

bool dty::String::operator>=(dty::String& other)
{
    return !((__PTR_TO_REF__ this) < other);
}

dty::String dty::String::Concat(dty::String& str0, dty::String& str1)
{
    int32 newStrLen = str0._StringLength + str1._StringLength;
    string newStr = new char[newStrLen + 1];

    int32 i = 0;
    for (int32 j = 0; j < str0._StringLength; ++j, ++i)
        newStr[i] = str0._StringValue[j];

    for (int32 j = 0; j < str1._StringLength; ++j, ++i)
        newStr[i] = str1._StringValue[j];

    newStr[newStrLen] = '\0';

    return dty::String(newStr, newStrLen, true);
}

dty::String dty::String::Concat(dty::String& str0, dty::String& str1, dty::String& str2)
{
    int32 newStrLen = str0._StringLength + str1._StringLength + str2._StringLength;
    string newStr = new char[newStrLen + 1];

    int32 i = 0;
    for (int32 j = 0; j < str0._StringLength; ++j, ++i)
        newStr[i] = str0._StringValue[j];

    for (int32 j = 0; j < str1._StringLength; ++j, ++i)
        newStr[i] = str1._StringValue[j];

    for (int32 j = 0; j < str2._StringLength; ++j, ++i)
        newStr[i] = str2._StringValue[j];

    newStr[newStrLen] = '\0';

    return dty::String(newStr, newStrLen, true);
}

dty::String dty::String::Join(const char joinChar, dty::String& str1, dty::String& str2)
{
    if ('\0' == joinChar)
        throw dty::except::ArgumentException();

    int32 newLen = str1._StringLength + str2._StringLength + 1;
    string newStr = new char[newLen + 1];
    int32 newStrI = 0;
    for (int32 i = 0; i < str1._StringLength; ++i, ++newStrI)
        newStr[newStrI] = str1._StringValue[i];
    newStr[newStrI++] = joinChar;
    for (int32 i = 0; i < str2._StringLength; ++i, ++newStrI)
        newStr[newStrI] = str2._StringValue[i];
    newStr[newStrI] = '\0';

    return dty::String(newStr, newLen, true);
}

dty::String dty::String::Join(const char joinChar, dty::String& str1, dty::String& str2, bool forceEmpty)
{
    if ('\0' == joinChar)
        throw dty::except::ArgumentException();

    if (!forceEmpty)
    {
        if (0 == str1._StringLength && 0 == str2._StringLength)
            return dty::String::Empty;

        if (0 == str1._StringLength && 0 != str2._StringLength)
            return str2;

        if (0 == str2._StringLength && 0 != str1._StringLength)
            return str1;
    }

    return dty::String::Join(joinChar, str1, str2);
}

dty::String dty::String::Join(const char joinChar, string str1, int32 length1, string str2, int32 length2)
{
    if ('\0' == joinChar)
        throw dty::except::ArgumentException();

    if (::null == str1 || ::null == str2)
        throw dty::except::ArgumentNullException();

    if (0 > length1 || 0 > length2)
        throw dty::except::ArgumentOutOfRangeException();

    int32 acturLen1 = strlen(str1);
    int32 acturLen2 = strlen(str2);

    if (acturLen1 < length1 || acturLen2 < length2)
        throw dty::except::ArgumentOutOfRangeException();

    int32 newLen = length1 + length2 + 1;
    string newStr = new char[newLen + 1];
    int32 newStrI = 0;
    for (int32 i = 0; i < length1; ++i, ++newStrI)
        newStr[newStrI] = str1[i];
    newStr[newStrI++] = joinChar;
    for (int32 i = 0; i < length2; ++i, ++newStrI)
        newStr[newStrI] = str2[i];
    newStr[newStrI] = '\0';

    return dty::String(newStr, newLen, true);
}

#if __cplusplus >= 201103
bool dty::String::Contains(std::initializer_list<dty::String> strs)
{
    if (0 == strs.size())
        return false;

    bool contains = false;
    for (const dty::String* it = strs.begin(); it != strs.end() && !contains; ++it)
        contains = this->Contains(__PTR_TO_REF__ it);

    return contains;
}

dty::String dty::String::Concat(std::initializer_list<dty::String> strs)
{
    int32 totalLen = 0;
    for (const dty::String* it = strs.begin(); it != strs.end(); ++it)
        totalLen += const_cast<dty::String __POINTER__>(it)->_StringLength;

    if (0 == totalLen)
        return dty::String::Empty;

    string newStr = new char[totalLen + 1];
    int32 newStrI = 0;
    for (const dty::String* it = strs.begin(); it != strs.end(); ++it)
    {
        dty::String __POINTER__ cast_string = const_cast<dty::String __POINTER__>(it);
        for (int32 i = 0; i < cast_string->_StringLength; ++i, ++newStrI)
            newStr[newStrI] = cast_string->_StringValue[i];
    }

    newStr[newStrI] = '\0';

    return dty::String(newStr, totalLen, true);
}

dty::String dty::String::Join(const char joinChar, std::initializer_list<dty::String> strs)
{
    if ('\0' == joinChar)
        throw dty::except::ArgumentException();

    if (0 == strs.size())
        return dty::String::Empty;

    int32 totalLen = 0;
    int32 joinCharCount = strs.size() - 1;
    for (const dty::String* it = strs.begin(); it != strs.end(); ++it)
        totalLen += const_cast<dty::String __POINTER__>(it)->_StringLength;

    string newStr = new char[totalLen + joinCharCount + 1];
    int32 newStrI = 0;
    for (const dty::String* it = strs.begin(); it != strs.end(); ++it)
    {
        dty::String __POINTER__ cast_string = const_cast<dty::String __POINTER__>(it);
        for (int32 i = 0; i < cast_string->_StringLength; ++i, ++newStrI)
            newStr[newStrI] = cast_string->_StringValue[i];
        if (0 != joinCharCount)
        {
            newStr[newStrI++] = joinChar;
            --joinCharCount;
        }
    }

    return dty::String(newStr, totalLen + joinCharCount, true);
}

dty::String dty::String::Join(const char joinChar, std::initializer_list<string> strs)
{
    if ('\0' == joinChar)
        throw dty::except::ArgumentException();

    if (0 == strs.size())
        return dty::String::Empty;

    int32 totalLen = 0;
    int32 totalCount = 0;
    for (const string* it = strs.begin(); it != strs.end(); ++it)
        if (::null != (__PTR_TO_VAR__ it))
        {
            totalLen += strlen(__PTR_TO_VAR__ it);
            ++totalCount;
        }

    if (0 == totalCount)
        return dty::String::Empty;

    int32 joinCharCount = totalCount - 1;
    string newStr = new char[totalLen + joinCharCount + 1];
    int32 newStrI = 0;
    for (const string* it = strs.begin(); it != strs.end(); ++it)
    {
        const string itv = (__PTR_TO_VAR__ it);
        if (::null == itv)
            continue;
        int32 len = strlen(itv);
        for (int32 i = 0; i < len; ++i, ++newStrI)
            newStr[newStrI] = itv[i];
        if (0 != joinCharCount)
        {
            newStr[newStrI++] = joinChar;
            --joinCharCount;
        }
    }

    return dty::String(newStr, totalLen + joinCharCount, true);
}

dty::String dty::String::Join(const char joinChar, std::initializer_list<dty::String> strs, bool forceEmpty)
{
    if (forceEmpty)
        return dty::String::Join(joinChar, strs);

    if ('\0' == joinChar)
        throw dty::except::ArgumentException();

    if (0 == strs.size())
        return dty::String::Empty;

    dty::String* firstFact = ::null;
    int32 totalLen = 0;
    int32 totalCount = 0;
    for (const dty::String* it = strs.begin(); it != strs.end(); ++it)
    {
        dty::String __POINTER__ cast_string = const_cast<dty::String __POINTER__>(it);
        if (0 != cast_string->_StringLength)
        {
            totalLen += cast_string->_StringLength;
            ++totalCount;
            if (::null == firstFact)
                firstFact = (dty::String __POINTER__)it;
        }
    }

    if (0 == totalCount)
        return dty::String::Empty;

    if (1 == totalCount)
        return ::null != firstFact
        ? (__PTR_TO_VAR__ firstFact)
        : throw dty::except::Exception();

    int32 joinCharCount = totalCount - 1;
    string newStr = new char[totalLen + joinCharCount + 1];
    int32 newStrI = 0;
    for (const dty::String* it = strs.begin(); it != strs.end(); ++it)
    {
        dty::String __POINTER__ cast_string = const_cast<dty::String __POINTER__>(it);
        if (0 != cast_string->_StringLength)
        {
            for (int32 i = 0; i < cast_string->_StringLength; ++i, ++newStrI)
                newStr[newStrI] = cast_string->_StringValue[i];

            if (0 != joinCharCount)
            {
                newStr[newStrI++] = joinChar;
                --joinCharCount;
            }
        }
    }

    newStr[newStrI] = '\0';

    return dty::String(newStr, totalLen + joinCharCount, true);
}

dty::String dty::String::Join(const char joinChar, std::initializer_list<string> strs, bool forceEmpty)
{
    throw dty::except::NotImplementationException();
    // if (forceEmpty)
    //     return dty::String::Join(joinChar, strs);

    // if ('\0' == joinChar)
    //     throw dty::except::ArgumentException();

    // if (0 == strs.size())
    //     return dty::String::Empty;

    // dty::int_ptr eachLen(new int32[strs.size()], (int64)strs.size());
    // string firstFact = ::null;
    // int32 totalLen = 0;
    // int32 totalCount = 0;
    // int32 i = 0;
    // for (const string* it = strs.begin(); it != strs.end(); ++it, ++i)
    // {
    //     eachLen[i] = strlen(__PTR_TO_VAR__ it);
    //     if (0 != eachLen[i])
    //     {
    //         totalLen += eachLen[i];
    //         ++totalCount;
    //         if (::null == firstFact)
    //             firstFact = __PTR_TO_VAR__ it;
    //     }
    // }

    // if (0 == totalCount)
    //     return dty::String::Empty;

    // if (1 == totalCount)
    //     return ::null != firstFact
    //     ? dty::String(firstFact)
    //     : throw dty::except::Exception();

    // int32 joinCharCount = totalCount - 1;
    // string newStr = new char[totalLen + joinCharCount + 1];
    // int32 newStrI = 0;
    // i = 0;
    // for (const string* it = strs.begin(); it != strs.end(); ++it, ++i)
    // {
    //     if (0 != eachLen[i])
    //     {
    //         for (int32 i = 0; i < eachLen[i]; ++i, ++newStrI)
    //             newStr[newStrI] = (__PTR_TO_VAR__ it)[i];

    //         if (0 != joinCharCount)
    //         {
    //             newStr[newStrI++] = joinChar;
    //             --joinCharCount;
    //         }
    //     }
    // }

    // newStr[newStrI] = '\0';

    // return dty::String(newStr, totalLen + joinCharCount, true);
}
#endif // !__cplusplus >= 201103

dty::String dty::String::GetString(const ::string source, bool needCopy = true)
{
    if (::null == source)
        throw dty::except::ArgumentNullException();

    return dty::String::GetString(source, dty::strlen(source), needCopy);
}
dty::String dty::String::GetString(const ::string source, int32 sourceLen, bool needCopy = true)
{
    if (::null == source)
        throw dty::except::ArgumentNullException();

    return dty::String(source, sourceLen, !needCopy);
}

::string dty::String::ToString() noexcept
{
    return this->ToCStr();
}

uint64 dty::String::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

uint64 dty::String::GetHashCode()
{
    return (uint64)(::string)(this->_StringValue);
}

bool dty::String::IsNull()
{
    return ::null == this->_StringValue;
}

bool dty::String::Equals(dty::TianyuObject& other)
{
    if (this->GetTypeId() != other.GetTypeId())
        return false;

    if (this->GetHashCode() == other.GetHashCode())
        return true;

    return (__PTR_TO_REF__ this) == dynamic_cast<dty::String __REFERENCE__>(other);
}
