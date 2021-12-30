
namespace DTY.Dotnet.Tools.Common.Process
{
    public interface IProcess
    {
        public string Command { get; }
        public string Parameter { get; set; }

        public System.Diagnostics.DataReceivedEventHandler? DataReceivedEvent { set; }
        public System.Diagnostics.DataReceivedEventHandler? ErrorReceivedEvent { set; }
        public EventHandler<IProcess>? ExitEvent { set; }

        public int ExitCode { get; }
        public bool HasExited { get; }
        public int Id { get; }
        public string Name { get; }

        public void Close();
        public void Kill(bool entireProcessTree = true);
        public bool Start();
        public void WaitForExit();
        public bool WaitForExit(int milliseconds);
        public Task WaitForExitAsync(CancellationToken cancellationToken);
    }
}