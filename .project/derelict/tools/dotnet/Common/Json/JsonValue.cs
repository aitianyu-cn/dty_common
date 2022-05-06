using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DTY.Dotnet.Tools.Common.Json
{
    internal class JsonStringValue : IJsonValue
    {
        public string Value { get; set; } = string.Empty;

        public JsonValueType ValueType =>  JsonValueType.STRING;
        public int ToInt => 0;
        public bool ToBoolean => !(string.IsNullOrEmpty(Value) || Value.ToLower() == "false");

        public IJsonObject ToObject => throw new InvalidCastException();
        public IEnumerator<IJsonValue> ToArray => throw new InvalidCastException();
        string IJsonValue.ToString => Value;
        public IJsonValue this[int index] => throw new NotSupportedException();
    }

    internal class JsonIntValue : IJsonValue
    {
        public int Value { get; set; } = 0;

        public JsonValueType ValueType => JsonValueType.INTEGER;
        public int ToInt => Value;
        public bool ToBoolean => 0 != Value;

        public IJsonObject ToObject => throw new InvalidCastException();
        public IEnumerator<IJsonValue> ToArray => throw new InvalidCastException();
        string IJsonValue.ToString => Value.ToString();
        public IJsonValue this[int index] => throw new NotSupportedException();
    }
    
    internal class JsonBoolValue : IJsonValue
    {
        public bool Value { get; set; } = false;

        public JsonValueType ValueType => JsonValueType.BOOLEAN;
        public int ToInt => Value ? 1 : 0;
        public bool ToBoolean => Value;

        public IJsonObject ToObject => throw new InvalidCastException();
        public IEnumerator<IJsonValue> ToArray => throw new InvalidCastException();
        string IJsonValue.ToString => Value.ToString();
        public IJsonValue this[int index] => throw new NotSupportedException();
    }

    internal class JsonArrayValue : IJsonValue
    {
        public List<IJsonValue> Value { get; } = new List<IJsonValue>();

        public JsonValueType ValueType => JsonValueType.ARRAY;
        public int ToInt => Value.Count;
        public bool ToBoolean => 0 != Value.Count;

        public IJsonObject ToObject => throw new InvalidCastException();
        public IEnumerator<IJsonValue> ToArray => Value.GetEnumerator();
        string IJsonValue.ToString => "array";
        public IJsonValue this[int index]
        {
            get
            {
                if (0 > index || Value.Count <= index)
                    throw new IndexOutOfRangeException();

                return Value[index];
            }
        }
    }

    internal class JsonObjectValue : IJsonObject
    {
        public Dictionary<string, IJsonValue> Value { get; } = new Dictionary<string, IJsonValue>();
        public bool IsNull { get; set; } = true;

        public JsonValueType ValueType => JsonValueType.OBJECT;
        public int ToInt => IsNull ? -1 : Value.Count;
        public bool ToBoolean => IsNull;

        public IJsonObject ToObject => this;
        public IEnumerator<IJsonValue> ToArray => Value.Values.GetEnumerator();
        string IJsonValue.ToString => IsNull ? "null" : "object";

        public IJsonValue this[int index]
        {
            get
            {
                if (IsNull || 0 > index || Value.Count <= index)
                    throw new IndexOutOfRangeException();

                return Value.Values.ToArray()[index];
            }
        }
        public IJsonValue this[string key]
        {
            get
            {
                if (IsNull)
                    throw new NullReferenceException();

                if (Value.TryGetValue(key, out IJsonValue? value))
                    if (value is not null)
                        return value;

                throw new MissingMemberException();
            }
        }

        public bool Contains(string key) => Value.ContainsKey(key);
        public bool TryGetValue(string key, out IJsonValue value)
        {
            bool getResult = Value.TryGetValue(key, out IJsonValue? result);

            if (result is null)
                result = new JsonObjectValue
                {
                    IsNull = true
                };

            value = result;
            return getResult;
        }
    }
}
