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
        /// object  - null->-1 | not null->the keys count of object
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
        public IEnumerator<IJsonValue> ToArray { get; }

        /// <summary>
        /// get a json value by count index.
        /// </summary>
        /// <param name="index">the index of the value in object and array</param>
        /// <returns>return a json value</returns>
        /// <exception cref="System.NotSupportedException">
        /// an exception is triggered if this indexer is not invokered in object or array type
        /// </exception>
        /// <exception cref="System.IndexOutOfRangeException">
        /// throw an exception when the index is not in the valid index range
        /// </exception>
        public IJsonValue this[int index] { get; }

        /// <summary>
        /// write current json value into file
        /// </summary>
        /// <param name="fileStream">the opened file stream</param>
        /// <returns>return true if write successfully, else false</returns>
        internal bool WriteToFile(FileStream fileStream);
        /// <summary>
        /// write current json value into file with the customized style.
        /// </summary>
        /// <param name="fileStream">the opened file stream</param>
        /// <param name="writingParams">the json style of writing file</param>
        /// <returns>return true if write successfully, else false</returns>
        internal bool WriteToFileWithStructure(FileStream fileStream, JsonWritingParams writingParams);
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
        /// <exception cref="NullReferenceException">
        /// throw an exception when the object is null
        /// </exception>
        public IJsonValue this[string key] { get; }
    }

    public interface IJsonEntity
    {
        #region Fields
        /// <summary>
        /// get a string that indicates the file path of current json entity
        /// 
        /// null value will be returned if the json entity is not created by reading file
        /// </summary>
        public string FilePath { get; }
        #endregion

        #region IO part
        /// <summary>
        /// write current json entity to file
        /// </summary>
        /// <returns>return false if writing has error or true is success</returns>
        /// <exception cref="FileNotFoundException">
        /// an excetion thrown if the json entity is not created by reading file
        /// </exception>
        public bool WriteToFile();
        /// <summary>
        /// write current json entity to file
        /// 
        /// if the file path of current json entity is null, the file path will be updated by what indicates in params.
        /// </summary>
        /// <param name="filePath">a new file path which need to write</param>
        /// <returns>return false if writing has error or true is success</returns>
        /// <exception cref="IOException">
        /// an excetion thrown if any error happens when writing
        /// </exception>
        public bool WriteToFile(string filePath);
        /// <summary>
        /// write current json entity to file with writing parameters
        /// 
        /// if the file path of current json entity is null, the file path will be updated by what indicates in params.
        /// </summary>
        /// <param name="filePath">a new file path which need to write</param>
        /// <param name="parameters">parameters of file writing</param>
        /// <returns>return false if writing has error or true is success</returns>
        /// <exception cref="IOException">
        /// an excetion thrown if any error happens when writing
        /// </exception>
        public bool WriteToFile(string filePath, IDictionary<string, object> parameters);
        #endregion

        #region operate part
        /// <summary>
        /// get a json object from json entity.
        /// </summary>
        /// <returns>return a json object or return an empty json object if this is a initial entity</returns>
        public IJsonObject GetObject();
        /// <summary>
        /// set a json object to current entity. this operation will overwrite current json object.
        /// </summary>
        /// <param name="jsonObject">a new json object</param>
        /// <exception cref="ArgumentNullException">
        /// throw an exception when the new json object is null.
        /// </exception>
        /// <exception cref="InvalidCastException">
        /// throw an exception when the new json object interface can not cast to json object
        /// (this exception should not be thrown in any time)
        /// </exception>
        public void SetObject(IJsonObject jsonObject);
        /// <summary>
        /// delete current json object and set an empty one.
        /// </summary>
        public void Clean();
        /// <summary>
        /// get a boolean value that indicates current json entity is empty or not
        /// </summary>
        /// <returns>empty json object will return true, else return false</returns>
        public bool HasObject();
        /// <summary>
        /// merge other json objects to current entity, same fields would be ignored.
        /// </summary>
        /// <param name="jsonObject">other json objects</param>
        /// <returns>return true if merge successful, else return false</returns>
        public bool Merge(params IJsonObject[] jsonObject);
        /// <summary>
        /// merge other json objects to current entity, same fields would be ignored or overwrite.
        /// </summary>
        /// <param name="jsonObject">other json objects</param>
        /// <param name="updateExist">a flag indicates the same fields should be updated or keep the first one. if the true value is set, last field will win.</param>
        /// <returns>return true if merge successful, else return false</returns>
        public bool Merge(bool updateExist, params IJsonObject[] jsonObject);
        #endregion
    }
}
