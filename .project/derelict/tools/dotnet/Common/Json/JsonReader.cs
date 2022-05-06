using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DTY.Dotnet.Tools.Common.Json
{
    internal class JsonFileReader : IDisposable
    {
        private readonly StreamReader JReader;

        public char Current { get; private set; } = '\xFFFF';
        public char Next { get; private set; } = '\xFFFF';
        public bool IsEnd { get; private set; } = false;

        public JsonFileReader(StreamReader reader)
        {
            JReader = reader;

            ReadChar();
        }

        public void ReadChar()
        {
            Current = Next;

            if (IsEnd)
                Next = '\xFFFF';
            else
            {
                Next = (char)JReader.Read();
                IsEnd = JReader.EndOfStream;
            }
        }

        public void Dispose()
        {
            JReader.Close();
            JReader.Dispose();
        }
    }

    internal class JsonUnserializer
    {
        private readonly JsonFileReader JReader;
        private readonly IJsonObject JsonObject;

        public JsonUnserializer(JsonFileReader jsonFileReader, IJsonObject jsonObject)
        {
            JReader = jsonFileReader;
            JsonObject = jsonObject;
        }

        public bool Unserialize()
        {

        }
    }
}
