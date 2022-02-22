using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DTY.Dotnet.Tools.Common.IO
{
    public enum LogLevel
    {
        INFO,
        WARN,
        ERROR,
        FATAL
    }

    public interface ILog
    {
        public bool IsDebugMode { get; set; }
        public bool IsConsoleOutput { get; set; }
        public string Id { get; }
        public string Name { get; }
        public string Description { get; }
        public string Path { get; }

        public void StartLog(bool append);
        public void EndLog();
        public void Logging(LogLevel level, string message);
        public void Logging(LogLevel level, DateTime time, string message);
        public void Logging(string msg = "");
    }

    internal class Log : ILog
    {
        public bool IsDebugMode { get; set; }
        public bool IsConsoleOutput { get; set; }

        public string Id { get; }
        public string Name { get; }
        public string Description { get; }
        public string Path { get; }

        private StreamWriter? _Writer;

        private Log(string name, FileInfo path, string des = "")
        {
            IsConsoleOutput = false;

            Id = Guid.NewGuid().ToString();
            Name = name;
            Path = path.FullName;
            Description = des;

            _Writer = null;
        }

        public void StartLog(bool append)
        {
            EndLog();

            bool fileExist = File.Exists(Path);

            _Writer = new StreamWriter(Path, append, Encoding.UTF8);

            if (!fileExist || !append)
            {
                _Writer?.WriteLine(Name);
                _Writer?.WriteLine(string.Format("说明：{0}", Description));
                _Writer?.WriteLine(string.Format("ID：{0}", Id));
                _Writer?.WriteLine();

                _Writer?.Flush();
            }
        }

        public void EndLog()
        {
            _Writer?.Close();
            _Writer?.Dispose();
            _Writer = null;
        }

        public void Logging(LogLevel level, string message)
        {
            Logging(level, DateTime.Now, message);
        }

        public void Logging(LogLevel level, DateTime time, string message)
        {
            string levelStr = level switch
            {
                LogLevel.INFO => "INFO ",
                LogLevel.WARN => "WARN ",
                LogLevel.ERROR => "ERROR",
                LogLevel.FATAL => "FATAL",
                _ => "INFO "
            };
            string timeStr = time.ToString("yyyy-MM-dd HH:mm:ss.fff");

            string formated_msg = string.Format("[{0}] [{1}] {2}", levelStr, timeStr, message);
            Logging_Internal(level, formated_msg);
        }

        public void Logging(string msg = "")
        {
            Logging_Internal(LogLevel.INFO, msg);

            if (IsConsoleOutput)
                Console.WriteLine(msg);
        }

        private void Logging_Internal(LogLevel level, string msg)
        {
            if (!IsDebugMode && LogLevel.ERROR != level && LogLevel.FATAL != level)
                return;

            _Writer?.WriteLine(msg);
            _Writer?.Flush();

            if (IsConsoleOutput)
                WriteToConsole(level, msg);
        }

        private void WriteToConsole(LogLevel color, string formated_msg)
        {
            Console.ForegroundColor = color switch
            {
                LogLevel.ERROR => ConsoleColor.Red,
                LogLevel.INFO => ConsoleColor.Green,
                LogLevel.WARN => ConsoleColor.Yellow,
                LogLevel.FATAL => ConsoleColor.Magenta,
                _ => ConsoleColor.Green,
            };

            Console.WriteLine(formated_msg);

            Console.ForegroundColor = ConsoleColor.White;
        }

        public static Log GenerateLogger(string name, string path, string des = "")
        {
            if (name is null || path is null)
                throw new ArgumentNullException(nameof(GenerateLogger));

            if (name.Trim().Length == 0)
                throw new ArgumentException(nameof(name));

            FileInfo info = new(path);

            return new Log(name, info, des);
        }
    }
}
