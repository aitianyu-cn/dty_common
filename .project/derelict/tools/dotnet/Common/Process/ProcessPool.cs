using System.Collections.Concurrent;

namespace DTY.Dotnet.Tools.Common.Process
{
    public enum ProcessType
    {
        Console
    }

    public class ProcessStartInfo
    {
        public ProcessType Executor { get; set; } = ProcessType.Console;
        public string Command { get; set; } = "";
        public string Parameter { get; set; } = "";
        public bool IsBackground { get; set; } = true;
        public System.Diagnostics.DataReceivedEventHandler? DataReceivedEvent { get; set; } = null;
        public System.Diagnostics.DataReceivedEventHandler? ErrorReceivedEvent { get; set; } = null;
        public EventHandler<IProcess>? ExitEvent { get; set; } = null;
    }

    public enum ProcessState
    {
        Undefined,
        Running,
        Done
    }

    public class ProcessPool
    {
        public EventHandler? ExitEvent { get; set; } = null;

        public int Count => _Processes.Count;
        public int Running => _RunningJobs.Count;
        public bool HasDone => 0 == _RunningJobs.Count;

        private ConcurrentDictionary<string, IProcess> _Processes;
        private ConcurrentDictionary<int, IProcess> _RunningJobs;

        private ReaderWriterLock _ManagementLock;

        public ProcessPool()
        {
            _Processes = new();
            _RunningJobs = new();
            _ManagementLock = new();
        }

        public bool ContainsProcess(string processId)
        {
            return _Processes.ContainsKey(processId);
        }
        public bool IsDone(string processId)
        {
            return _Processes.TryGetValue(processId, out IProcess? value) && null != value && value.HasExited;
        }
        public bool IsRunning(string processId)
        {
            return _Processes.TryGetValue(processId, out IProcess? value) && null != value && !value.HasExited;
        }
        public int GetPrcessId(string processId)
        {
            return _Processes.TryGetValue(processId, out IProcess? value) && null != value ? value.Id : 0;
        }
        public int GetExitCode(string processId)
        {
            return _Processes.TryGetValue(processId, out IProcess? value) && null != value ? value.ExitCode : 0;
        }
        public IProcess? GetProcess(string processId)
        {
            return _Processes.TryGetValue(processId, out IProcess? value) ? value : null;
        }

        public IProcess? CreateOne(string processId, string command, string parameters = "")
        {
            return CreateOne(processId, new ProcessStartInfo
            {
                Command = command,
                Parameter = parameters
            });
        }
        public IProcess? CreateOne(string processId, ProcessStartInfo startInfo)
        {
            if (string.IsNullOrEmpty(processId) || string.IsNullOrWhiteSpace(processId))
                return null;

            IProcess? process = null;
            switch (startInfo.Executor)
            {
                case ProcessType.Console:
                    process = new ConsoleExecutor(startInfo.Command, startInfo.Parameter)
                    {
                        IsBackground = startInfo.IsBackground,
                        DataReceivedEvent = startInfo.DataReceivedEvent,
                        ErrorReceivedEvent = startInfo.ErrorReceivedEvent,
                        ExitEvent = new EventHandler<IProcess>((object? sender, IProcess e) =>
                         {
                             // invoke customized exit event
                             startInfo.ExitEvent?.Invoke(sender, e);

                             // invoke the basic exit event
                             exited(e);
                         })
                    };
                    break;
                default:
                    break;
            }

            if (process is not null)
            {
                _ManagementLock.AcquireReaderLock(-1);
                _Processes.AddOrUpdate(processId, process, (string id, IProcess old) =>
                {
                    if (!old.HasExited)
                        old.Kill();

                    return process;
                });
                _ManagementLock.ReleaseReaderLock();
            }

            return process;
        }
        public bool StartOne(string processId)
        {
            return StartOne(processId, -1);
        }
        public bool StartOne(string processId, int milliseconds)
        {
            // warning: this is a blocked process
            if (string.IsNullOrEmpty(processId) || string.IsNullOrWhiteSpace(processId))
                return false;

            bool state = false;
            _ManagementLock.AcquireReaderLock(milliseconds);

            if (_ManagementLock.IsReaderLockHeld)
            {
                if (_Processes.TryGetValue(processId, out IProcess? process) && null != process)
                {
                    try
                    {
                        state = process.Start();
                    }
                    catch { }
                }

                _ManagementLock.ReleaseReaderLock();
            }

            return state;
        }
        public void KillOne(string processId)
        {
            KillOne(processId, -1);
        }
        public void KillOne(string processId, int milliseconds)
        {
            // warning: this is a blocked process
            if (string.IsNullOrEmpty(processId) || string.IsNullOrWhiteSpace(processId))
                return;

            _ManagementLock.AcquireReaderLock(milliseconds);

            if (_ManagementLock.IsReaderLockHeld)
            {
                if (_Processes.TryGetValue(processId, out IProcess? process) && null != process)
                {
                    try
                    {
                        process.Kill();
                    }
                    catch { }
                }

                _ManagementLock.ReleaseReaderLock();
            }
        }
        public void CloseOne(string processId)
        {
            CloseOne(processId, -1);
        }
        public void CloseOne(string processId, int milliseconds)
        {
            // warning: this is a blocked process
            if (string.IsNullOrEmpty(processId) || string.IsNullOrWhiteSpace(processId))
                return;

            _ManagementLock.AcquireReaderLock(milliseconds);

            if (_ManagementLock.IsReaderLockHeld)
            {
                if (_Processes.TryGetValue(processId, out IProcess? process) && null != process)
                {
                    try
                    {
                        process.Close();
                    }
                    catch { }
                }

                _ManagementLock.ReleaseReaderLock();
            }
        }
        public bool RemoveOne(string processId)
        {
            return RemoveOne(processId, -1);
        }
        public bool RemoveOne(string processId, int milliseconds)
        {
            // warning: this is a blocked process
            if (string.IsNullOrEmpty(processId) || string.IsNullOrWhiteSpace(processId))
                return false;

            bool state = false;
            _ManagementLock.AcquireReaderLock(milliseconds);

            if (_ManagementLock.IsReaderLockHeld)
            {
                if (_Processes.TryRemove(processId, out IProcess? process) && null != process)
                {
                    try
                    {
                        process.Close();
                        state = true;
                    }
                    catch
                    {
                        state = false;
                    }
                }

                _ManagementLock.ReleaseReaderLock();
            }

            return state;
        }
        public bool StartAll()
        {
            bool result = true;
            _ManagementLock.AcquireWriterLock(-1);

            try
            {
                foreach (KeyValuePair<string, IProcess> process in _Processes)
                {
                    bool startState = process.Value.Start();
                    if (startState)
                        _RunningJobs.AddOrUpdate(process.Value.Id, process.Value, (int id, IProcess processOld) => process.Value);

                    result = result && startState;
                }
            }
            catch
            {
                result = false;
            }
            finally
            {
                _ManagementLock.ReleaseWriterLock();
            }

            return result;
        }
        public bool StartAll(int milliseconds)
        {
            bool result = true;
            _ManagementLock.AcquireWriterLock(milliseconds);
            if (_ManagementLock.IsWriterLockHeld)
            {
                try
                {
                    foreach (KeyValuePair<string, IProcess> process in _Processes)
                    {
                        bool startState = process.Value.Start();
                        if (startState)
                            _RunningJobs.AddOrUpdate(process.Value.Id, process.Value, (int id, IProcess processOld) => process.Value);

                        result = result && startState;
                    }
                }
                catch
                {
                    result = false;
                }
                finally
                {
                    _ManagementLock.ReleaseWriterLock();
                }
            }
            else
                result = false;

            return result;
        }
        public void KillAll()
        {
            if (0 == _RunningJobs.Count)
                return;

            _ManagementLock.AcquireWriterLock(-1);

            foreach (KeyValuePair<string, IProcess> process in _Processes)
            {
                try
                {
                    int id = process.Value.Id;
                    process.Value.Kill();
                }
                finally
                {

                }
            }

            _ManagementLock.ReleaseWriterLock();
        }
        public void KillAll(int milliseconds)
        {
            if (0 == _RunningJobs.Count)
                return;

            _ManagementLock.AcquireWriterLock(milliseconds);

            if (_ManagementLock.IsWriterLockHeld)
            {
                foreach (KeyValuePair<string, IProcess> process in _Processes)
                {
                    try
                    {
                        int id = process.Value.Id;
                        process.Value.Kill();
                    }
                    finally
                    {

                    }
                }

                _ManagementLock.ReleaseWriterLock();
            }
        }
        public void CloseAll()
        {
            if (0 == _RunningJobs.Count)
                return;

            _ManagementLock.AcquireWriterLock(-1);

            foreach (KeyValuePair<string, IProcess> process in _Processes)
            {
                try
                {
                    int id = process.Value.Id;
                    process.Value.Kill();
                }
                finally
                {

                }
            }

            _ManagementLock.ReleaseWriterLock();
        }
        public void CloseAll(int milliseconds)
        {
            if (0 == _RunningJobs.Count)
                return;

            _ManagementLock.AcquireWriterLock(milliseconds);

            if (_ManagementLock.IsWriterLockHeld)
            {
                foreach (KeyValuePair<string, IProcess> process in _Processes)
                {
                    try
                    {
                        int id = process.Value.Id;
                        process.Value.Close();
                    }
                    finally
                    {

                    }
                }

                _ManagementLock.ReleaseWriterLock();
            }
        }
        public ProcessState GetProcessState(int id)
        {
            ProcessState state = ProcessState.Undefined;
            _ManagementLock.AcquireReaderLock(-1);

            if (_RunningJobs.ContainsKey(id))
                state = ProcessState.Running;
            else
            {
                foreach (KeyValuePair<string, IProcess> process in _Processes)
                    if (process.Value.Id == id)
                    {
                        state = ProcessState.Done;
                        break;
                    }
            }

            _ManagementLock.ReleaseReaderLock();

            return state;
        }
        public ProcessState GetProcessState(string id)
        {
            ProcessState state = ProcessState.Undefined;
            _ManagementLock.AcquireReaderLock(-1);

            foreach (KeyValuePair<string, IProcess> process in _Processes)
                if (process.Key == id)
                {
                    state = process.Value.HasExited ? ProcessState.Done : ProcessState.Running;
                    break;
                }

            _ManagementLock.ReleaseReaderLock();

            return state;
        }

        public void WaitForExit()
        {
            while (!HasDone)
                Thread.Sleep(50);
        }
        public bool WaitForExit(int milliseconds)
        {
            int eachTime = milliseconds / 100;
            for (int i = 0; i < 101 && !HasDone; ++i)
                Thread.Sleep(eachTime);

            return HasDone;
        }
        public void WaitForExitAsync(Action exitCallback)
        {
            // start a new thread to wait all of the processes are done
            Thread thread = new Thread(() =>
            {
                while (!HasDone)
                    Thread.Sleep(100);

                exitCallback();
            });
            thread.Start();
        }
        public void WaitForExitAsync(Action<bool> exitCallback, int milliseconds)
        {
            // start a new thread to wait all of the processes are done
            Thread thread = new Thread(() =>
            {
                Thread internalThread = new Thread(() =>
                {
                    while (!HasDone)
                        Thread.Sleep(100);
                });
                internalThread.Start();
                internalThread.Join(milliseconds);

                exitCallback(HasDone);
            });
            thread.Start();
        }

        public bool JoinOne(string processId, IProcess process, EventHandler<IProcess>? exit = null)
        {
            // unsafe way to manage the process
            // if the process has done, but the Running callback does not have been set
            // there will be a dead loop
            bool state = false;

            _ManagementLock.AcquireWriterLock(-1);

            try
            {
                process.ExitEvent = (object? sender, IProcess e) =>
                {
                    if (null != exit)
                        exit(sender, e);

                    exited(e);
                };
                _Processes.AddOrUpdate(processId, process, (string id, IProcess old) =>
                {
                    if (!old.HasExited)
                        old.Kill();

                    return process;
                });
                if (!process.HasExited)
                    _RunningJobs.AddOrUpdate(process.Id, process, (int id, IProcess old) =>
                    {
                        // release the binding of old process object
                        // then close the pre process
                        // Note: this is function that should never be invoked, eache process should be
                        // indicated a unified id.
                        old.ExitEvent = null;
                        old.Close();

                        return process;
                    });

                state = true;
            }
            catch { }

            _ManagementLock.ReleaseWriterLock();

            return state;
        }
        public ProcessState StartConsoleProcess(string processId, string command, out int id)
        {
            return StartNew(processId, new ProcessStartInfo
            {
                Executor = ProcessType.Console,
                Command = command
            }, out id);
        }
        public ProcessState StartConsoleProcess(string processId, string command, string parameters, out int id)
        {
            return StartNew(processId, new ProcessStartInfo
            {
                Executor = ProcessType.Console,
                Command = command,
                Parameter = parameters
            }, out id);
        }
        public ProcessState StartNew(string processId, ProcessStartInfo startInfo, out int id)
        {
            id = 0;
            IProcess? process = CreateOne(processId, startInfo);

            if (null == process)
                return ProcessState.Undefined;

            ProcessState state = ProcessState.Done;
            if (process.HasExited)
            {
                _ManagementLock.AcquireReaderLock(-1);

                try
                {
                    if (process.Start())
                    {
                        state = ProcessState.Running;
                        id = process.Id;
                    }
                }
                catch { }

                _ManagementLock.ReleaseReaderLock();
            }

            return state;
        }

        private void exited(IProcess process)
        {
            _ManagementLock.AcquireReaderLock(-1);

            _RunningJobs.Remove(process.Id, out _);

            _ManagementLock.ReleaseReaderLock();
        }
    }
}