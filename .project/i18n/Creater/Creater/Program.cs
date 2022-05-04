// See https://aka.ms/new-console-template for more information

using DTY.Native.Tools.I18N.Creater;

string[] appParam = args;

LanguageArea area = LanguageArea.zh_CN;

if (appParam.Length > 0)
{
    for (int i = 0; i < appParam.Length - 1; i+=2)
    {
        switch (appParam[i])
        {
            case "--language":
            case "-l":
                area = AreaHelper.ConvertAreaString(appParam[i + 1]);
                break;
        }
    }
}

CreaterHelper creater = new(area);
creater.Building();