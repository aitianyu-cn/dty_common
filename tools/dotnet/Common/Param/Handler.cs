using System;
using System.Collections.Generic;

namespace DTY.Dotnet.Tools.Common.Param
{
    internal class ParameterProcessor
    {
        private readonly Parameters _Parameters;
        private readonly ComparisonCollection _Comparison;
        private readonly Stack<string> _MessageCollection;

        public ParameterProcessor(ComparisonCollection comparison)
        {
            this._Parameters = new Parameters();
            this._Comparison = comparison;
            this._MessageCollection = new Stack<string>();
        }

        public void Process(string[] args)
        {
            if (args is null || 0 == args.Length)
                return;

            int index = 0;
            while (index < args.Length)
            {
                string source = args[index++];
                bool isControl = this.IsControl(source, out string control);

                if (isControl && control is not null)
                    this.Process(control, args, ref index);
                else if (control is null)
                    this._MessageCollection.Push(string.Format("无法识别的参数: {0} 控制符无效", source));
                else
                    this._MessageCollection.Push(string.Format("无法识别的参数: {0} 需要控制符", source));
            }
        }

        public Parameters GetParameters()
        {
            return this._Parameters;
        }

        public ICollection<string> GetMessage()
        {
            return this._MessageCollection.ToArray();
        }

        private bool IsControl(string source, out string control)
        {
            control = "";
            bool isControl = false;

            if (IsSingle(source, out char single))
            {
                isControl = true;
                control = this.ExpandSingle(single);
            }
            else if (IsFull(source, out string control_internal))
            {
                isControl = true;
                control = control_internal;
            }

            return isControl;
        }
        private static bool IsSingle(string str, out char single)
        {
            single = '\0';

            // clean white-space
            str = str.Trim();
            if (2 != str.Length)
                return false;

            if ('-' != str[0] || !IsCharVaild(str[1]))
                return false;

            single = str[1];
            return true;
        }
        private static bool IsFull(string str, out string full)
        {
            full = "";

            if (2 >= str.Length)
                return false;

            if (!str.StartsWith("--"))
                return false;

            if (!IsCharVaild(str[2]))
                return false;

            full = str.TrimStart('-');
            return true;
        }
        private static bool IsCharVaild(char ch)
        {
            if ((int)ch > 0x4E00 && (int)ch < 0x9FA5)
                return true;

            if (ch >= 'A' && ch <= 'Z')
                return true;

            if (ch >= 'a' && ch <= 'z')
                return true;

            return false;
        }
        private string ExpandSingle(char str)
        {
            return this._Comparison.GetItem(str, out ComparisonItem? item)
                ? item is not null
                ? item.FullName ?? "" : ""
                : "";
        }
        private void Process(string control, string[] args, ref int index)
        {
            if (!this._Comparison.GetItem(control, out ComparisonItem? compar))
            {
                this._MessageCollection.Push(string.Format("无法识别的参数: {0} 控制符无效", args[index - 1]));
                return;
            }

            if (compar is null)
                return;

            switch (compar.AdditionState)
            {
                case ParamAdditionState.ONCE:
                    if (index < args.Length && !this.IsControl(args[index], out _))
                    {
                        this._Parameters.AddParam(compar.FullName, compar.Handler);
                        this._Parameters.AddAddition(compar.FullName, args[index++]);
                    }
                    else
                        this._MessageCollection.Push(string.Format("控制符: --{0}(-{1}) 需要一个参数", compar.FullName, compar.SingleName));
                    break;
                case ParamAdditionState.TWICE:
                    if (index + 1 < args.Length && !this.IsControl(args[index], out _) && !this.IsControl(args[index + 1], out _))
                    {
                        this._Parameters.AddParam(compar.FullName, compar.Handler);
                        this._Parameters.AddAddition(compar.FullName, args[index++]);
                        this._Parameters.AddAddition(compar.FullName, args[index++]);
                    }
                    else
                        this._MessageCollection.Push(string.Format("控制符: --{0}(-{1}) 需要两个参数", compar.FullName, compar.SingleName));
                    break;
                case ParamAdditionState.SELECTABLE:
                    this._Parameters.AddParam(compar.FullName, compar.Handler);
                    while (index < args.Length && !this.IsControl(args[index], out _))
                        this._Parameters.AddAddition(compar.FullName, args[index++]);
                    break;
                case ParamAdditionState.MORE:
                    if (index < args.Length && !this.IsControl(args[index], out _))
                    {
                        do
                        {
                            this._Parameters.AddParam(compar.FullName, compar.Handler);
                            this._Parameters.AddAddition(compar.FullName, args[index++]);
                        }
                        while (index < args.Length && !this.IsControl(args[index], out _));
                    }
                    else
                        this._MessageCollection.Push(string.Format("控制符: --{0}(-{1}) 需要至少一个参数", compar.FullName, compar.SingleName));
                    break;
                case ParamAdditionState.NONE:
                default:
                    this._Parameters.AddParam(compar.FullName, compar.Handler);
                    break;
            }
        }
    }

    public class ParameterHandler
    {
        private readonly ComparisonCollection _Comparisons;

        public ParameterHandler()
        {
            this._Comparisons = new ComparisonCollection();
        }

        public void AddComparison(string fname, char sname, ParamAdditionState astate, int code, ParameterHandlerDelegate handle)
        {
            this._Comparisons.AddItem(fname, sname, astate, code, handle);
        }

        public Parameters ProcessParameter(string[] args, out ICollection<string> message)
        {
            ParameterProcessor processor = new(this._Comparisons);

            processor.Process(args);

            message = processor.GetMessage();

            return processor.GetParameters();
        }
    }
}