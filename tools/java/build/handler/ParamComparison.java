package build.handler;

import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;

public class ParamComparison
{
    public enum ParamAdditionState
    {
        NONE, SELECTABLE, ONCE, TWICE, MORE
    }

    public class ComparisonItem
    {
        private String _FullName;
        private char _SingleName;
        private ParamAdditionState _AdditionalState;
        private IParamHandle _Handle;
        private int _Code;

        public ComparisonItem(String fname, char sname, ParamAdditionState astate, int code, IParamHandle handle)
        {
            this._FullName = fname;
            this._SingleName = sname;
            this._AdditionalState = astate;
            this._Code = code;
            this._Handle = handle;
        }

        public String FullName()
        {
            return this._FullName;
        }

        public char SingleName()
        {
            return this._SingleName;
        }

        public ParamAdditionState AdditionalState()
        {
            return this._AdditionalState;
        }

        public int Code()
        {
            return this._Code;
        }

        public void Handle(Iterator<String> iterator)
        {
            if (null != this._Handle)
                this._Handle.Handle(iterator);
        }

        @Override
        public int hashCode()
        {
            Character ch = this._SingleName;
            return this._FullName.hashCode() ^ ch.hashCode();
        }

        @Override
        public boolean equals(Object obj)
        {
            if (obj.getClass() != this.getClass())
                return false;

            ComparisonItem item = (ComparisonItem) obj;
            return this._FullName == item._FullName || this._SingleName == item._SingleName;
        }
    }

    private HashSet<ComparisonItem> _Comparisons;

    public ParamComparison()
    {
        this._Comparisons = new HashSet<ComparisonItem>();
    }

    public void InsertItem(String fname, char sname, ParamAdditionState astate, int code, IParamHandle handle)
    {
        if (null == fname || fname.isBlank())
            return;

        this._Comparisons.add(new ComparisonItem(fname, sname, astate, code, handle));
    }

    public void InsertRange(Collection<ComparisonItem> iterator)
    {
        this._Comparisons.addAll(iterator);
    }

    public ComparisonItem GetComparison(String name, boolean is_single)
    {
        if (null == name || name.isBlank())
            return null;

        ComparisonItem search = is_single
                ? new ComparisonItem("", name.charAt(0), ParamAdditionState.NONE, -1, null)
                : new ComparisonItem(name, '\0', ParamAdditionState.NONE, -1, null);

        return null;
    }
}
