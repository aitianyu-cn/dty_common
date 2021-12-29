
namespace DTY.Dotnet.Tools.Common.IO
{
    public class IOHelper
    {
        public static ILog CreateLogger(string name, string path, string des = "")
        {
            return Log.GenerateLogger(name, path, des);
        }
    }
}