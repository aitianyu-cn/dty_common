using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;

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

    public delegate void ParameterHandlerDelegate(ICollection<string> collection);

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
        public override bool Equals(object? obj)
        {
            return obj is not null && obj is ComparisonItem @item && (item.FullName == this.FullName || item.SingleName == this.SingleName);
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
        public ParameterHandlerDelegate Handler { get; private set; }

        public ComparisonItem(int code, ComparisonKey key, ParamAdditionState astate, ParameterHandlerDelegate handle) : base(key)
        {
            this.Code = code;
            this.AdditionState = astate;
            this.Handler = handle;
        }
    }

    public class ComparisonCollection
    {
        private class ComparisonComparer : IEqualityComparer<ComparisonKey>
        {
            public bool Equals(ComparisonKey? x, ComparisonKey? y)
            {
                if (x is null && y is null)
                    return true;

                return x?.FullName == y?.FullName || x?.SingleName == y?.SingleName;
            }

            public int GetHashCode([DisallowNull] ComparisonKey obj)
            {
                return 0;
            }
        }

        public int Count => _Comparisons.Count;

        private readonly Dictionary<ComparisonKey, ComparisonItem> _Comparisons;

        public ComparisonCollection()
        {
            _Comparisons = new Dictionary<ComparisonKey, ComparisonItem>(new ComparisonComparer());
        }

        public void AddItem(string fname, char sname, ParamAdditionState astate, int code, ParameterHandlerDelegate handle)
        {
            // return directly if fname is null or empty(including all chars is white-space)
            if (fname is null)
                return;

            fname = fname.Trim();
            if (0 == fname.Length)
                return;

            ComparisonKey key = new(fname, sname);
            ComparisonItem newItem = new(code, key, astate, handle);
            // if no item which is equals to current one has not been saved, save it.
            if (!this._Comparisons.ContainsKey(key))
                this._Comparisons.Add(key, newItem);
        }

        public bool GetItem(string fname, out ComparisonItem? item)
        {
            ComparisonKey key = new(fname, '\0');
            return this._Comparisons.TryGetValue(key, out item);
        }

        public bool GetItem(char sname, out ComparisonItem? item)
        {
            item = null;

            if ('\0' == sname)
                return false;

            ComparisonKey key = new("", sname);
            return this._Comparisons.TryGetValue(key, out item);
        }
    }
}