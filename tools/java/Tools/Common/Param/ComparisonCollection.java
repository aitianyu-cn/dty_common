package Tools.Common.Param;

import java.util.HashMap;

public class ComparisonCollection
{
    private HashMap<ComparisonKey, ComparisonItem> _Comparisons;

    public ComparisonCollection()
    {
        _Comparisons = new HashMap<ComparisonKey, ComparisonItem>();
    }

    public int Count()
    {
        return this._Comparisons.size();
    }

    public void AddItem(String fname, char sname, ParamAdditionState astate, int code, ParameterHandlerDelegate handle)
    {
        if (null == fname || fname.isBlank())
            return;

        ComparisonKey key = new ComparisonKey(fname, sname);
        ComparisonItem item = new ComparisonItem(code, key, astate, handle);

        if (!this._Comparisons.containsKey(key))
            this._Comparisons.put(key, item);
    }

    public ComparisonItem GetItem(String fname)
    {
        ComparisonKey key = new ComparisonKey(fname, '\0');

        return this._Comparisons.get(key);
    }

    public ComparisonItem GetItem(char sname)
    {
        if ('\0' == sname)
            return null;

        ComparisonKey key = new ComparisonKey("", sname);

        return this._Comparisons.get(key);
    }
}
