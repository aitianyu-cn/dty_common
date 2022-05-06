package Tools.Common.IO;

public class IOHelper
{
    public static ILog CreateLogger(String name, String path, String des)
    {
        try
        {
            return Log.GenerateLogger(name, path, des);
        }
        catch (Exception e)
        {
            return null;
        }
    }
}
