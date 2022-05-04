using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DTY.Native.Tools.I18N.Creater
{
    internal class MacroWriter
    {
        public const string LanguageFile = @"..\i18n\language.h";
        public const string ItemFormatter = "#define {0} \"{1}\"";
        public const string MacroFormatter = "__DTY_COMMON_NATIVE_RES_I18N_{0}_H__";

        private readonly StreamWriter _writer;
        private readonly LanguageArea _area;
        private readonly string _macroText;

        public MacroWriter(LanguageArea area = LanguageArea.zh_CN)
        {
            _writer = new(LanguageFile, false, Encoding.UTF8);
            _area = area;
            _macroText = string.Format(MacroFormatter, AreaHelper.AreaString(_area).ToUpper());

            _StartMacro();
        }

        public void AddEmpty()
        {
            _writer.WriteLine();
        }
        public void AddNote(string note)
        {
            _writer.WriteLine("// {0}", note);
        }
        public void AddItem(string key, string value)
        {
            string item = string.Format(ItemFormatter, key, value);
            _writer.WriteLine(item);
        }

        public void Close()
        {
            _EndMacro();

            _writer.Close();
        }

        private void _StartMacro()
        {
            _writer.WriteLine("// ################################################");
            _writer.WriteLine("// 天宇静态多语言文件");
            _writer.WriteLine("// Dev Tianyu Static Language File");
            _writer.WriteLine("//");
            _writer.WriteLine("// 文件创建时间:   {0}", DateTime.Now.ToString("yyyy-MM-dd"));
            _writer.WriteLine("// 语       言:   {0}", AreaHelper.AreaString(_area));
            _writer.WriteLine("// 版       权:   aitianyu.cn");
            _writer.WriteLine("//");
            _writer.WriteLine("// Create Time:  {0}", DateTime.Now.ToString("yyyy-MM-dd"));
            _writer.WriteLine("// Language   :  {0}", AreaHelper.AreaString(_area));
            _writer.WriteLine("// Copyright  :  aitianyu.cn");
            _writer.WriteLine("//");
            _writer.WriteLine("// ################################################");
            _writer.WriteLine();

            _writer.WriteLine("#ifndef {0}", _macroText);
            _writer.WriteLine("#define {0}", _macroText);
            _writer.WriteLine();
        }
        private void _EndMacro()
        {
            _writer.WriteLine("#endif // !{0}", _macroText);
        }
    }
}
