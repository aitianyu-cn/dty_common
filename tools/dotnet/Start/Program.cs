// See https://aka.ms/new-console-template for more information
using DTY.Dotnet.Tools.Common.IO;
using DTY.Dotnet.Tools.Common.Param;

Console.WriteLine("Hello, World!");

ILog logger = IOHelper.CreateLogger("test.log", ".\\", "");

logger.IsDebugMode = true;
logger.IsConsoleOutput = true;

Console.WriteLine(logger.Path);

logger.StartLog(true);

logger.Logging(LogLevel.INFO, "this is a INFO");
logger.Logging(LogLevel.WARN, "this is a WARN!");
logger.Logging(LogLevel.ERROR, "!this is a ERROR");
logger.Logging(LogLevel.FATAL, "!!!this is a FATAL");

logger.EndLog();

//ParameterHandler parameterHandler = new();

//parameterHandler.AddComparison("help", 'h', ParamAdditionState.NONE, 1, (ICollection<string> collection) =>
//{
//    Console.WriteLine("Help");
//    foreach (string item in collection)
//        Console.WriteLine("\t{0}", item);
//});

//parameterHandler.AddComparison("param1", 'a', ParamAdditionState.ONCE, 1, (ICollection<string> collection) =>
//{
//    Console.WriteLine("Param1");
//    foreach (string item in collection)
//        Console.WriteLine("\t{0}", item);
//});

//parameterHandler.AddComparison("param2", 'b', ParamAdditionState.TWICE, 1, (ICollection<string> collection) =>
//{
//    Console.WriteLine("Param2");
//    foreach (string item in collection)
//        Console.WriteLine("\t{0}", item);
//});

//parameterHandler.AddComparison("param3", 'c', ParamAdditionState.SELECTABLE, 1, (ICollection<string> collection) =>
//{
//    Console.WriteLine("Param3");
//    foreach (string item in collection)
//        Console.WriteLine("\t{0}", item);
//});

//parameterHandler.AddComparison("param4", 'd', ParamAdditionState.MORE, 1, (ICollection<string> collection) =>
//{
//    Console.WriteLine("Param4");
//    foreach (string item in collection)
//        Console.WriteLine("\t{0}", item);
//});

//Parameters parameters = parameterHandler.ProcessParameter(args, out ICollection<string> message);

//foreach (string msg in message)
//    Console.WriteLine("[MESSAGE] {0}", msg);

//parameters.HandleAll();