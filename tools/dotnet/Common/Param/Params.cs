using System;
using System.Collections.Generic;

namespace DTY.Dotnet.Tools.Common.Param
{
    public class ParametersItem
    {
        private readonly ParameterHandler _Handler;
        private readonly List<string> _Additional;

        public ParametersItem()
        {
            this._Handler = null;
            this._Additional = new SortedList<string>();
        }
        public ParametersItem(ParameterHandler handler)
        {
            this._Handler = handler;
            this._Additional = new List<string>();
        }

        public void AddAddition(string addition)
        {
            if (addition is null)
                return;

            addition = addition.Trim();
            if (0 == addition.Length)
                return;

            if (this._Additional.Contains(addition))
                return;

            this._Additional.Add(addition);
        }

        public void Handle()
        {
            if (this._Handler is null)
                return;

            this._Handler(this._Additional);
        }
    }

    public class Parameters
    {
        private Dictionary<string, ParametersItem> _Params;

        public Parameters()
        {
            this._Params = new Dictionary<string, ParametersItem>();
        }

        public void AddParam(string pname, ParameterHandler handler)
        {
            if (pname is null)
                return;

            pname = pname.Trim();
            if (0 == pname.Length)
                return;

            if (this._Params.ContainsKey(pname))
                return;

            this._Params.Add(pname, new ParametersItem(handler));
        }

        public void AddAddition(string pname, string addition)
        {
            if (pname is null || addition is null)
                return;

            pname = pname.Trim();
            if (0 == pname.Length)
                return;

            if (this._Params.TryGetValue(pname, out ParametersItem value))
                value.AddAddition(addition);
        }

        public void HandleAll()
        {
            if (0 == this._Params.Count)
                return;

            foreach (ParametersItem item in this._Params.Values)
                item.Handle();
        }

        public void HandleOne(string pname)
        {
            if (0 == this._Params.Count)
                return;

            if (this._Params.TryGetValue(pname, out ParametersItem item))
                item.Handle();
        }
    }
}