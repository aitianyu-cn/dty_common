package Tools.Common.IO;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.UUID;

import Tools.Common.LogLevel;

public class Log implements ILog
{
    private static final DateFormat LogDateFormatter = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss.SSS");
    private static final String ERRORConsoleFormat = "\033[31;4m%s\033[0m";
    private static final String WARNConsoleFormat = "\033[33;4m%s\033[0m";
    private static final String INFOConsoleFormat = "\033[32;4m%s\033[0m";
    private static final String FATALConsoleFormat = "\033[46;37;4m%s\033[0m";

    private final UUID _Id;
    private final String _Name;
    private final String _Path;
    private final String _Description;

    private boolean _IsDebugMode;
    private boolean _IsConsoleOutput;
    private FileWriter _Writer;

    private Log(String name, String path, String des)
    {
        _Id = UUID.randomUUID();
        _Name = name;
        _Path = path;
        _Description = des;

        _IsDebugMode = false;
        _IsConsoleOutput = false;
        _Writer = null;
    }

    @Override
    public String GetId()
    {
        return this._Id.toString();
    }

    @Override
    public String GetName()
    {
        return this._Name;
    }

    @Override
    public String GetDescription()
    {
        return this._Description;
    }

    @Override
    public String GetPath()
    {
        return this._Path;
    }

    @Override
    public boolean GetIsDebugMode()
    {
        return this._IsDebugMode;
    }

    @Override
    public boolean GetIsConsoleOutput()
    {
        return this._IsConsoleOutput;
    }

    @Override
    public void SetIsDebugMode(boolean debugMode)
    {
        this._IsDebugMode = debugMode;
    }

    @Override
    public void SetIsConsoleOutput(boolean isConsoleOutput)
    {
        this._IsConsoleOutput = isConsoleOutput;
    }

    @Override
    public void StartLog(boolean append) throws IOException
    {
        this.EndLog();

        File file = new File(this._Path);
        boolean fileExist = file.exists();

        this._Writer = new FileWriter(file, append);

        if (!fileExist || !append)
        {
            this._Writer.write(String.format("%s%s", this._Name, System.getProperty("line.separator")));
            this._Writer.write(String.format("说明：%s%s", this._Description, System.getProperty("line.separator")));
            this._Writer.write(String.format("ID：%s%s", this._Id, System.getProperty("line.separator")));
            this._Writer.write(System.getProperty("line.separator"));

            this._Writer.flush();
        }
    }

    @Override
    public void EndLog() throws IOException
    {
        if (null == this._Writer)
            return;

        this._Writer.close();
        this._Writer = null;
    }

    @Override
    public void Logging(LogLevel level, String message) throws IOException
    {
        this.Logging(level, new Date(), message);
    }

    @Override
    public void Logging(LogLevel level, Date time, String message) throws IOException
    {
        String levelStr = "";

        switch (level)
        {
            case INFO:
                levelStr = "INFO ";
                break;
            case WARN:
                levelStr = "WARN ";
                break;
            case ERROR:
                levelStr = "ERROR";
                break;
            case FATAL:
                levelStr = "FATAL";
                break;
            default:
                levelStr = "INFO ";
                break;
        }

        String timeStr = Log.LogDateFormatter.format(time);
        String formated_msg = String.format("[%s] [%s] %s", levelStr, timeStr, message);
        this.Logging_Internal(level, formated_msg);
    }

    @Override
    public void Logging(String msg) throws IOException
    {
        this.Logging_Internal(LogLevel.INFO, msg);
    }

    private void Logging_Internal(LogLevel level, String msg) throws IOException
    {
        if (null == this._Writer)
            return;

        if (!this._IsDebugMode && LogLevel.ERROR != level && LogLevel.FATAL != level)
            return;

        this._Writer.write(msg);
        this._Writer.write(System.getProperty("line.separator"));
        this._Writer.flush();

        if (this._IsConsoleOutput)
            WriteToConsole(level, msg);
    }

    private void WriteToConsole(LogLevel color, String formated_msg)
    {
        String formatStr = "";

        switch (color)
        {
            case WARN:
                formatStr = Log.WARNConsoleFormat;
                break;
            case ERROR:
                formatStr = Log.ERRORConsoleFormat;
                break;
            case FATAL:
                formatStr = Log.FATALConsoleFormat;
                break;
            case INFO:
            default:
                formatStr = Log.INFOConsoleFormat;
                break;
        }

        System.out.println(String.format(formatStr, formated_msg));
    }

    public static Log GenerateLogger(String name, String path) throws Exception
    {
        return Log.GenerateLogger(name, path, "");
    }

    public static Log GenerateLogger(String name, String path, String des) throws Exception
    {
        if (null == name || null == path)
            throw new Exception("GenerateLogger");

        if (name.isEmpty() || name.isBlank())
            throw new Exception("name");

        return new Log(name, path, des);
    }
}