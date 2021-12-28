using System;
using System.Collections.Generic;

namespace DTY.Dotnet.Tools.Common.Param
{
    public enum ParamAdditionState
    {
        NONE,
        SELECTABLE,
        ONCE,
        TWICE,
        MORE
    }

    public delegate void ParameterHandler(ICollection<string> collection);

    public class ComparisonKey
    {
        public string FullName { get; private set; }
        public char SingleName { get; private set; }
        public ComparisonKey(string fname, char sname)
        {
            this.FullName = fname;
            this.SingleName = sname;
        }

        protected ComparisonKey(ComparisonKey key)
        {
            this.FullName = key.FullName;
            this.SingleName = key.SingleName;
        }

        public override int GetHashCode()
        {
            return this.FullName.GetHashCode() ^ this.SingleName.GetHashCode();
        }
        public override bool Equals(object obj)
        {
            return obj is ComparisonItem @item && (item.FullName == this.FullName || item.SingleName == this.SingleName);
        }
        public override string ToString()
        {
            return string.Format("{0}-{1}", this.SingleName, this.FullName);
        }
    }

    public class ComparisonItem : ComparisonKey
    {
        public int Code { get; private set; }
        public ParamAdditionState AdditionState { get; private set; }
        public ParameterHandler Handler { get; private set; }

        public ComparisonItem(int code, ComparisonKey key, ParamAdditionState astate, ParameterHandler handle) : base(key)
        {
            this.Code = code;
            this.AdditionState = astate;
            this.Handler = handle;
        }
    }

    public class ComparisonCollection
    {
        public int Count => _Comparisons.Count;

        private Dictionary<ComparisonItem, ComparisonItem> _Comparisons;

        public ComparisonCollection()
        {
            _Comparisons = new Dictionary<ComparisonItem, ComparisonItem>();
        }

        public void AddItem(string fname, char sname, ParamAdditionState astate, int code, ParameterHandler handle)
        {
            // return directly if fname is null or empty(including all chars is white-space)
            if (fname is null)
                return;

            fname = fname.Trim();
            if (0 == fname.Length)
                return;

            ComparisonKey key = new ComparisonKey(fname, sname);
            ComparisonItem newItem = new ComparisonItem(code, key, astate, handle);
            // if no item which is equals to current one has not been saved, save it.
            if (!this._Comparisons.ContainsKey(key))
                this._Comparisons.Add(key, newItem);
        }

        public bool GetItem(string fname, out ComparisonItem item)
        {
            ComparisonKey key = new ComparisonKey(fname, '\0');
            return this._Comparisons.TryGetValue(key, out item);
        }

        public bool GetItem(char sname, out ComparisonItem item)
        {
            item = null;

            if ('\0' == sname)
                return false;

            ComparisonKey key = new ComparisonKey("", sname);
            return this._Comparisons.TryGetValue(key, out item);
        }
    }
}