package build.handler;

import java.util.HashSet;
import java.util.Iterator;

public class ParameterItem
{
    private String _FullName;
    private HashSet<String> _Additional;

    public ParameterItem()
    {
        this._FullName = "";
        this._Additional = new HashSet<String>();
    }

    public ParameterItem(String fullName)
    {
        this._FullName = fullName;
        this._Additional = new HashSet<String>();
    }

    public String GetName()
    {
        return this._FullName;
    }

    public void AddAddition(String param)
    {
        this._Additional.add(param);
    }

    public void RemoveAddition(String param)
    {
        this._Additional.remove(param);
    }

    public Iterator<String> GetIterator()
    {
        return this._Additional.iterator();
    }

    public void Handle(IParamHandle handle)
    {
        if (null != handle)
            handle.Handle(this._Additional.iterator());
    }

    public static final int ParameterInvalidCode = -1;
}
