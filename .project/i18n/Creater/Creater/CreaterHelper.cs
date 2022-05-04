using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DTY.Native.Tools.I18N.Creater
{
    internal class CreaterHelper
    {
        public static string DefaultAreaString(string key) => string.Format("转换的消息(converted msg)：{0}");

        private readonly FileInfo[] _sources;
        private readonly LanguageArea _area;

        public CreaterHelper(LanguageArea area)
        {
            DirectoryInfo directory = new(@"..\i18n");
            //DirectoryInfo directory = new(@"C:\Dev\tianyu-native\native\res\i18n");
            if (directory.Exists)
            {
                List<FileInfo> sources = new List<FileInfo>();
                foreach (FileInfo file in directory.GetFiles())
                    if (file.Extension.ToLower() == ".json")
                        sources.Add(file);

                _sources = sources.ToArray();
            }
            else
                _sources = Array.Empty<FileInfo>();

            _area = area;
        }

        public void Building()
        {
            MacroWriter macro = new(_area);

            foreach (FileInfo file in _sources)
            {
                macro.AddNote(file.Name);
                LanguageReader reader = new LanguageReader(file.FullName);
                if (reader.IsInited)
                    _BuildLanguage(reader, macro);
                macro.AddEmpty();
            }

            macro.Close();
        }

        private void _BuildLanguage(LanguageReader language, MacroWriter macro)
        {
            string areaKey = AreaHelper.AreaKey(_area);
            foreach (KeyValuePair<string, JToken?> item in language.JObj)
            {
                string key = item.Key;
                JObject value = (JObject?)item.Value ?? new JObject();

                string valueString = value[areaKey]?.ToString()
                    ?? value[AreaHelper.AreaKeyDefault]?.ToString()
                    ?? DefaultAreaString(key);

                macro.AddItem(key, valueString);
            }
        }
    }
}
