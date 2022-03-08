using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;

namespace DTY.Dotnet.Tools.Common.Param
{
    /// <summary>
    /// indicates the state of the parameter how many data should be provided follow the param-key
    /// </summary>
    public enum ParamAdditionState
    {
        /// <summary>
        /// indicates the parameter is a single param without any data
        /// </summary>
        NONE,
        /// <summary>
        /// indicates the parameter that could has 0 or more datas
        /// </summary>
        SELECTABLE,
        /// <summary>
        /// indicates the parameter that only one data should be provided
        /// </summary>
        ONCE,
        /// <summary>
        /// indicates the parameter that only two datas should be provided
        /// </summary>
        TWICE,
        /// <summary>
        /// indicates the parameter that should be provided more than one data
        /// </summary>
        MORE
    }

    /// <summary>
    /// declare a delegate that is used to process a specific parameter
    /// </summary>
    /// <param name="collection"></param>
    public delegate void ParameterHandlerDelegate(ICollection<string> collection);

    /// <summary>
    /// comparsion key class
    /// 对照关键字类
    ///
    /// be used to save the long name and/or short name of a parameter.
    /// </summary>
    public class ComparisonKey
    {
        /// <summary>
        /// get the long name of a parameter.
        /// full name should follow the '--' prefix.
        /// </summary>
        public string FullName { get; private set; }
        /// <summary>
        /// get the short name of a parameter.
        /// short name should follow the '-' prefix
        /// </summary>
        public char SingleName { get; private set; }

        /// <summary>
        /// construct a comparison key that is created by indicating full name and/or single name
        /// </summary>
        /// <param name="fname">long name of the key</param>
        /// <param name="sname">short name of the key</param>
        public ComparisonKey(string fname, char sname)
        {
            this.FullName = fname;
            this.SingleName = sname;
        }

        /// <summary>
        /// copy construct a comparison key that equals to the indicate key
        /// </summary>
        /// <param name="key">copy source object</param>
        protected ComparisonKey(ComparisonKey key)
        {
            this.FullName = key.FullName;
            this.SingleName = key.SingleName;
        }

        /// <summary>
        /// get an int that equals to the hash code of current object.
        ///
        /// calculated by xoring the hash codes of long name and short name
        /// </summary>
        /// <returns>return the hash code</returns>
        public override int GetHashCode()
        {
            return this.FullName.GetHashCode() ^ this.SingleName.GetHashCode();
        }
        /// <summary>
        /// get a boolean value that indicates the specified object equals current object or not.
        /// </summary>
        /// <param name="obj">specified object</param>
        /// <returns>return true if long name or short name is same, otherwise false</returns>
        public override bool Equals(object? obj)
        {
            return obj is not null && obj is ComparisonItem @item && (item.FullName == this.FullName || item.SingleName == this.SingleName);
        }
        /// <summary>
        /// get a string that equals short name with '-' and plus long name.
        /// </summary>
        /// <returns>return the formatted string</returns>
        public override string ToString()
        {
            return string.Format("{0}-{1}", this.SingleName, this.FullName);
        }
    }

    /// <summary>
    /// comparison key combined class
    ///
    /// provides the additional infors to comparison key
    /// </summary>
    public class ComparisonItem : ComparisonKey
    {
        /// <summary>
        /// get an int value that indicates a key in order to improve the process perfermence.
        /// </summary>
        public int Code { get; private set; }
        /// <summary>
        /// get a state that indicates the state of the parameter how many data should be provided follow the param-key.
        /// </summary>
        public ParamAdditionState AdditionState { get; private set; }
        /// <summary>
        /// get a delegate that used to process the parameter and its data(s).
        /// </summary>
        public ParameterHandlerDelegate Handler { get; private set; }

        /// <summary>
        /// construct a comparison item that is created by indicating key code, key, parameter state and parameter process delegate.
        /// </summary>
        /// <param name="code">code of comparison key</param>
        /// <param name="key">comparison key</param>
        /// <param name="astate">parameter data state</param>
        /// <param name="handle">parameter handler</param>
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