
namespace DTY.Dotnet.Tools.Common.Json
{
    internal class JsonEntity : IJsonEntity
    {
        public string FilePath { get; private set; }
        public bool IsOpened { get; private set; }

        private IJsonObject _value;

        public JsonEntity()
        {
            FilePath = string.Empty;
            IsOpened = false;

            // create a root object that must to be not null.
            _value = new JsonObjectValue { IsNull = false };
        }
        public JsonEntity(string filePath) : this()
        {
            FilePath = filePath;
            IsOpened = File.Exists(FilePath) && _OpenFile();
        }

        private bool _OpenFile()
        {
            try
            {
                FileStream fileStream = File.Open(FilePath, FileMode.Open, FileAccess.Read);
                if (0 == fileStream.Length)
                    // should return true to set file is opened
                    // because the empty file that will not cause the result of this function unexpected.
                    return true;

                // only when the file is not empty, to create a stream reader to do the further processing.
                StreamReader reader = new StreamReader(fileStream);

                // create json file reader to provide the char read.
                JsonFileReader jsonFileReader = new JsonFileReader(reader);

                // create the file unserializer to do the final process
                JsonUnserializer jsonUnserializer = new JsonUnserializer(jsonFileReader, _value);
                return jsonUnserializer.Unserialize();
            }
            catch
            {
                return false;
            }
        }

        public bool WriteToFile() => WriteToFile(FilePath);
        public bool WriteToFile(string filePath) => WriteToFile(filePath, new Dictionary<string, object>());
        public bool WriteToFile(string filePath, IDictionary<string, object> parameters)
        {
            // todo: write back to file
        }

        #region operation

        public IJsonObject GetObject() => _value;
        public void SetObject(IJsonObject jsonObject)
        {
            if (!jsonObject.ToBoolean)
                throw new ArgumentNullException();

            _value = jsonObject;
        }
        public void Clean()
        {
            _value = new JsonObjectValue { IsNull = false };
        }
        public bool HasObject() => 0 != _value.ToInt;

        #endregion
    }
}