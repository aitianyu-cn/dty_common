using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DTY.Dotnet.Tools.Common.Json
{
    /// <summary>
    /// json value types
    /// </summary>
    public enum JsonValueType
    {
        STRING,
        INTEGER,
        BOOLEAN,
        OBJECT,
        ARRAY
    }

    /// <summary>
    /// the basic of a json value
    /// </summary>
    public interface IJsonValue
    {
        /// <summary>
        /// get a enum that indicates the type of current json value
        /// </summary>
        public JsonValueType ValueType { get; }

        /// <summary>
        /// get a string that equals to the current value
        /// 
        /// value type:
        /// string  - actual value
        /// integer - value to string in Oct
        /// boolean - true->"true" | false->"false"
        /// object  - null->"null" | not null->"object"
        /// array   - "array"
        /// </summary>
        public string ToString { get; }
        /// <summary>
        /// get a integer that equals to the current value
        /// 
        /// value type:
        /// string  - 0
        /// integer - actual value
        /// boolean - true->1 | false->0
        /// object  - null->0 | not null->the keys count of object
        /// array   - length of the array
        /// </summary>
        public int ToInt { get; }
        /// <summary>
        /// get a boolean that equals to the current value
        /// 
        /// value type:
        /// string  - empty string->false | string->true | "false"->false
        /// integer - 0->false | other value->true
        /// boolean - actual value
        /// object  - null->false | not null->true
        /// array   - length of the array is 0->false | is not 0->true
        /// </summary>
        public bool ToBoolean { get; }
        /// <summary>
        /// get an object that equals to the current value
        /// 
        /// value type:
        /// string  - exception
        /// integer - exception
        /// boolean - exception
        /// object  - actual value
        /// array   - exception
        /// </summary>
        /// <exception cref="System.InvalidCastException">
        /// an exception is triggered if the value type is not array type.
        /// </exception>
        public IJsonObject ToObject { get; }
        /// <summary>
        /// get an array that equals to the current value
        /// 
        /// value type:
        /// string  - exception
        /// integer - exception
        /// boolean - exception
        /// object  - actual value
        /// array   - actual value
        /// </summary>
        /// <exception cref="System.InvalidCastException">
        /// an exception is triggered if the value type is not array type or object type.
        /// </exception>
        public IJsonValue ToArray { get; }

        /// <summary>
        /// get a json value by count index.
        /// </summary>
        /// <param name="index">the index of the value in object and array</param>
        /// <returns>return a json value</returns>
        /// <exception cref="System.NotSupportedException">
        /// an exception is triggered if this indexer is not invokered in object or array type
        /// </exception>
        public IJsonValue this[int index] { get; }
    }

    public interface IJsonObject : IJsonValue
    {
        /// <summary>
        /// get a boolean that indicates the key exists in the current object or not.
        /// </summary>
        /// <param name="key">the key name of the value in object</param>
        /// <returns>true:exist | false:not exist</returns>
        public bool Contains(string key);

        /// <summary>
        /// get a boolean that indicates the value is valid or not.
        /// </summary>
        /// <param name="key">value key</param>
        /// <param name="value">the value that should be found and return</param>
        /// <returns>true:value is valid | false:value is invalid or some error happen</returns>
        public bool TryGetValue(string key, out IJsonValue value);

        /// <summary>
        /// get a json value by element key name
        /// </summary>
        /// <param name="key">the key name of the value in object</param>
        /// <returns>return a json value</returns>
        /// <exception cref="System.MissingMemberException">
        /// an exception is triggered if the key is not found in current object
        /// </exception>
        public IJsonValue this[string key] { get; }
    }

    /// <summary>
    /// a json unit that contains a key and its value
    /// </summary>
    public interface IJsonUnit
    {

    }

    public interface IJsonEntity
    {
        // IO part

        // operate part
    }
}
