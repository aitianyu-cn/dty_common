using System;
using System.Collections.Generic;

namespace DTY.Dotnet.Tools.Common.Param
{
    public class ParametersItem
    {
        private readonly ParameterHandlerDelegate? _Handler;
        private readonly List<List<string>> _Additional;

        public int AdditionCount => this._Additional.Count;

        public ParametersItem()
        {
            this._Handler = null;
            this._Additional = new List<List<string>>();
        }
        public ParametersItem(ParameterHandlerDelegate handler)
        {
            this._Handler = handler;
            this._Additional = new List<List<string>>();
        }

        public void NewParameter()
        {
            this._Additional.Add(new List<string>());
        }

        public void AddAddition(string addition)
        {
            if (addition is null)
                return;

            addition = addition.Trim();
            if (0 == addition.Length)
                return;

            if (0 == this._Additional.Count)
                return;

            this._Additional[this._Additional.Count - 1].Add(addition);
        }

        public void HandleOne(int index)
        {
            if (this._Handler is null)
                return;

            if (0 > index || this._Additional.Count <= index)
                return;

            this._Handler(this._Additional[index]);
        }
        public void HandleAll()
        {
            if (this._Handler is null)
                return;

            foreach (List<string> list in this._Additional)
                this._Handler(list);
        }
    }

    public class Parameters
    {
        private readonly Dictionary<string, ParametersItem> _Params;

        public Parameters()
        {
            this._Params = new Dictionary<string, ParametersItem>();
        }

        public bool AddParam(string pname, ParameterHandlerDelegate handler)
        {
            if (pname is null)
                return false;

            pname = pname.Trim();
            if (0 == pname.Length)
                return false;

            if (!this._Params.ContainsKey(pname))
                this._Params.Add(pname, new ParametersItem(handler));

            if (this._Params.TryGetValue(pname, out ParametersItem item))
            {
                item.NewParameter();
                return true;
            }

            return false;
        }

        public void AddAddition(string pname, string addition)
        {
            if (pname is null || addition is null)
                return;

            pname = pname.Trim();
            if (0 == pname.Length)
                return;

            if (this._Params.TryGetValue(pname, out ParametersItem? value))
                value.AddAddition(addition);
        }

        public int ParameterAdditionCount(string name)
        {
            if (name is null)
                return -1;

            name = name.Trim();
            if (0 == name.Length)
                return -1;

            if (this._Params.TryGetValue(name, out ParametersItem? value))
                return value?.AdditionCount ?? -1;

            return -1;
        }

        public void HandleAll()
        {
            if (0 == this._Params.Count)
                return;

            foreach (ParametersItem item in this._Params.Values)
                item.HandleAll();
        }

        public void HandleOne(string pname)
        {
            if (0 == this._Params.Count)
                return;

            if (this._Params.TryGetValue(pname, out ParametersItem? item))
                item.HandleAll();
        }

        public void HandleOne(string pname, int index)
        {
            if (0 == this._Params.Count)
                return;

            if (this._Params.TryGetValue(pname, out ParametersItem? item))
                item.HandleOne(index);
        }
    }
}