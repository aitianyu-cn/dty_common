package Tools.Common.IO;

import java.io.IOException;
import java.util.Date;
import Tools.Common.LogLevel;

public interface ILog
{
    public String GetId();

    public String GetName();

    public String GetDescription();

    public String GetPath();

    public boolean GetIsDebugMode();

    public boolean GetIsConsoleOutput();

    public void SetIsDebugMode(boolean debugMode);

    public void SetIsConsoleOutput(boolean isConsoleOutput);

    public void StartLog(boolean append) throws IOException;

    public void EndLog() throws IOException;

    public void Logging(LogLevel level, String message) throws IOException;

    public void Logging(LogLevel level, Date time, String message) throws IOException;

    public void Logging(String msg) throws IOException;
}
