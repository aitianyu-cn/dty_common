#include "../arghelper.hpp"

// ######################################################################################
// ######################################################################################
// IArgValue class Implementation
// ######################################################################################
// ######################################################################################

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

    dty::string_sp key = this->Key();
    dty::string_sp value = this->Value();
    if (::null == key)
        return ::null;

    int32 key_len = key.Size - 1;
    int32 val_len = value.Size - 1;
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
        dty::string_sp source = 0 == key_len ? value : key;
        for (int32 i = 0; i < total_len; ++i)
            result[i] = source[i];
    }
    result[total_len] = '\0';

    return result;
}

bool dty::IArgValue::Equals(dty::TianyuObject& obj)
{
    return (__PTR_TO_REF__ this) == obj;
}

bool dty::IArgValue::operator==(dty::TianyuObject& obj)
{
    if (this->GetTypeId() != obj.GetTypeId())
        return false;

    dty::IArgValue& cast_obj = dynamic_cast<dty::IArgValue&>(obj);

    if (this->Key().Size != cast_obj.Key().Size || this->Value().Size != cast_obj.Value().Size)
        return false;

    bool is_equal = true;
    for (int32 i = 0; i < this->Key().Size && is_equal; ++i)
        is_equal = this->Key()[i] == cast_obj.Key()[i];
    for (int32 i = 0; i < this->Value().Size && is_equal; ++i)
        is_equal = this->Value()[i] == cast_obj.Value()[i];

    return is_equal;
}

uint64 dty::IArgValue::GetTypeId()
{
    return dty::GetType<dty::IArgValue>().Id();
}

// ######################################################################################
// ######################################################################################
// IArgValue class Implementation
// ######################################################################################
// ######################################################################################

dty::IArgKey::IArgKey(dty::ArgumentKeyType arg_type, ::string key, int32 ksize) :
    dty::TianyuObject(),
    _ArgType(arg_type),
    ArgType(_ArgType),
    _ValueState(0),
    _Key(key, (int64)ksize)
{ }

dty::IArgKey::~IArgKey()
{ }

::string dty::IArgKey::ToString()
{
    dty::string_sp key = this->Key();

    ::string result = new char[key.Size];
    for (int32 i = 0; i < key.Size; ++i)
        result[i] = this->Key()[i];

    return result;
}

bool dty::IArgKey::Equals(dty::TianyuObject& obj)
{
    return (__PTR_TO_REF__ this) == obj;
}

bool dty::IArgKey::operator==(dty::TianyuObject& obj)
{
    if (this->GetTypeId() != obj.GetTypeId())
        return false;

    dty::IArgKey& cast_obj = dynamic_cast<dty::IArgKey&>(obj);

    bool is_equal = true;
    for (int32 i = 0; i < this->Key().Size && is_equal; ++i)
        is_equal = this->Key()[i] == cast_obj.Key()[i];

    return is_equal;
}

uint64 dty::IArgKey::GetTypeId()
{
    return dty::GetType<dty::IArgKey>().Id();
}

dty::string_sp dty::IArgKey::Key()
{
    return this->_Key.GetWeak();
}

bool dty::IArgKey::IsNoneValue()
{
    return 0 != (this->_ValueState & (int32)dty::ArgumentValueState::None);
}

bool dty::IArgKey::IsSingleValue()
{
    return 0 != (this->_ValueState & (int32)dty::ArgumentValueState::Single);
}

bool dty::IArgKey::IsMultiValue()
{
    return 0 != (this->_ValueState & (int32)dty::ArgumentValueState::Multi);
}

void dty::IArgKey::setValueState(dty::ArgumentValueState state)
{
    this->_ValueState |= (int32)state;
}

// ######################################################################################
// ######################################################################################
// SingleArgValue class Implementation
// ######################################################################################
// ######################################################################################

dty::SingleArgValue::SingleArgValue(::string value, int32 size) :
    dty::TianyuObject(),
    dty::IArgValue(dty::ArgumentValueType::SingleValue),
    _Value(value, (int64)size)
{ }

dty::SingleArgValue::~SingleArgValue()
{ }

dty::string_sp dty::SingleArgValue::Key()
{
    return dty::string_sp();
}

dty::string_sp dty::SingleArgValue::Value()
{
    return this->_Value.GetWeak();
}

// ######################################################################################
// ######################################################################################
// ExtendArgValue class Implementation
// ######################################################################################
// ######################################################################################

dty::ExtendArgValue::ExtendArgValue(::string key, int32 ksize, ::string value, int32 vsize) :
    dty::TianyuObject(),
    dty::IArgValue(dty::ArgumentValueType::ExtendValue),
    _Key(key, (int64)ksize),
    _Value(value, (int64)vsize)
{ }

dty::ExtendArgValue::~ExtendArgValue()
{ }

dty::string_sp dty::ExtendArgValue::Key()
{
    return this->_Key.GetWeak();
}

dty::string_sp dty::ExtendArgValue::Value()
{
    return this->_Value.GetWeak();
}

// ######################################################################################
// ######################################################################################
// ArgumentHelper class Implementation
// ######################################################################################
// ######################################################################################



// ######################################################################################
// ######################################################################################
// ArgumentHelper class Implementation
// ######################################################################################
// ######################################################################################

dty::SmartPointer<dty::IArgValue> dty::ArgumentHelper::CreateSingleValue(const ::string value)
{
    if (::null == value)
        throw dty::except::ArgumentNullException();

    int32 value_len = ::strlen(value);
    if (0 == value_len)
        throw dty::except::ArgumentException();

    ::string dyn_value = new char[value_len + 1];
    for (int32 i = 0; i < value_len; ++i)
        dyn_value[i] = value[i];

    dyn_value[value_len] = '\0';

    return dty::SmartPointer<dty::IArgValue>(new dty::SingleArgValue(dyn_value, value_len + 1));
}

dty::SmartPointer<dty::IArgValue> dty::ArgumentHelper::CreateExtendValue(const ::string key, const ::string value)
{
    if (::null == key || ::null == value)
        throw dty::except::ArgumentNullException();

    int32 key_len = ::strlen(key);
    int32 value_len = ::strlen(value);
    if (0 == key_len || 0 == value_len)
        throw dty::except::ArgumentException();

    ::string dyn_key = new char[key_len + 1];
    for (int32 i = 0; i < key_len; ++i)
        dyn_key[i] = key[i];

    dyn_key[key_len] = '\0';

    ::string dyn_value = new char[value_len + 1];
    for (int32 i = 0; i < value_len; ++i)
        dyn_value[i] = value[i];

    dyn_value[value_len] = '\0';

    return dty::SmartPointer<dty::IArgValue>(new dty::ExtendArgValue(dyn_key, key_len, dyn_value, value_len));
}

dty::SmartPointer<dty::IArgKey> dty::ArgumentHelper::CreateKey(const ::string key, dty::ArgumentKeyType type)
{
    if (::null == key)
        throw dty::except::ArgumentNullException();

    int32 len = ::strlen(key);
    if (0 == len)
        throw dty::except::ArgumentException();


}
