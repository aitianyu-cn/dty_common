// https://docs.microsoft.com/zh-cn/dotnet/api/system.diagnostics.process?view=net-6.0

namespace DTY.Dotnet.Tools.Common.Process
{
    public class ConsoleExecutor : IProcess
    {
        public string Command { get; }
        public string Parameter { get; set; }

        public bool IsBackground { get; set; } = true;
        public System.Diagnostics.DataReceivedEventHandler? DataReceivedEvent { private get; set; } = null;
        public System.Diagnostics.DataReceivedEventHandler? ErrorReceivedEvent { private get; set; } = null;
        public EventHandler<IProcess>? ExitEvent { private get; set; } = null;

        public int ExitCode => !_IsStarted ? 0 : _Process.ExitCode;
        public bool HasExited => !_IsStarted || _IsStarted && _Process.HasExited;
        public int Id => !_IsStarted ? 0 : _Process.Id;
        public string Name => HasExited ? "" : _Process.ProcessName;

        private System.Diagnostics.Process _Process;
        private bool _IsStarted;
        public ConsoleExecutor(string command, string parameters = "")
        {
            Command = command;
            Parameter = parameters;
            _IsStarted = false;

            _Process = new();
        }

        public void Close()
        {
            _Process.Close();
        }

        public void Kill(bool entireProcessTree = true)
        {
            if (!_IsStarted || _Process.HasExited)
                return;

            _Process.Kill(entireProcessTree);
        }

        public bool Start()
        {
            if (_IsStarted && !_Process.HasExited)
                return false;

            _Process.StartInfo = new System.Diagnostics.ProcessStartInfo(Command, Parameter)
            {
                CreateNoWindow = IsBackground,
                RedirectStandardOutput = true,
                RedirectStandardError = true,
                UseShellExecute = false,
            };
            _Process.OutputDataReceived += new System.Diagnostics.DataReceivedEventHandler(outputReceived);
            _Process.ErrorDataReceived += new System.Diagnostics.DataReceivedEventHandler(errorReceived);
            _Process.Exited += new EventHandler(exited);

            _Process.EnableRaisingEvents = true;

            bool startResult = _Process.Start();

            _IsStarted = true;
            _Process.BeginOutputReadLine();
            _Process.BeginErrorReadLine();

            return startResult;
        }

        public void WaitForExit()
        {
            _Process.WaitForExit();
        }

        public bool WaitForExit(int milliseconds)
        {
            return _Process.WaitForExit(milliseconds);
        }

        public System.Threading.Tasks.Task WaitForExitAsync(System.Threading.CancellationToken cancellationToken)
        {
            return _Process.WaitForExitAsync(cancellationToken);
        }

        private void outputReceived(object sender, System.Diagnostics.DataReceivedEventArgs e)
        {
            if (null == DataReceivedEvent)
                return;

            try
            {
                DataReceivedEvent(sender, e);
            }
            catch
            {

            }
        }

        private void errorReceived(object sender, System.Diagnostics.DataReceivedEventArgs e)
        {
            if (null == ErrorReceivedEvent)
                return;

            try
            {
                ErrorReceivedEvent(sender, e);
            }
            catch
            {

            }
        }

        private void exited(object? sender, EventArgs e)
        {
            if (null == ExitEvent)
                return;

            try
            {
                ExitEvent(sender, this);
            }
            catch
            {

            }
        }
    }
}
