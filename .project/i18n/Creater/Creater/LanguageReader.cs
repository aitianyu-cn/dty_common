using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace DTY.Native.Tools.I18N.Creater
{
    internal class LanguageReader
    {
        public bool IsInited { get; private set; } = false;

        private readonly JObject? _JsonObject = null;

        public JObject JObj => _JsonObject ?? new JObject();

        public LanguageReader(string langFile)
        {
            if (!File.Exists(langFile))
                return;

            try
            {
                StreamReader file = File.OpenText(langFile);
                JsonTextReader reader = new JsonTextReader(file);

                _JsonObject = (JObject)JToken.ReadFrom(reader);

                IsInited = true;
            }
            catch
            {
                IsInited = false;
            }
        }
    }
}
