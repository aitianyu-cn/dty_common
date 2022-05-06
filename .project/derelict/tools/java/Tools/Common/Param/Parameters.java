package Tools.Common.Param;

import java.util.Dictionary;
import java.util.HashMap;

public class Parameters
{
    private HashMap<String, ParametersItem> _Params;

    public Parameters()
    {
        this._Params = new HashMap<String, ParametersItem>();
    }

    public void AddParam(String pname, ParameterHandlerDelegate handler)
    {
        if (null == pname || pname.isBlank())
            return;

        if (this._Params.containsKey(pname))
            return;

        this._Params.put(pname, new ParametersItem(handler));
    }

    public void AddAddition(String pname, String addition)
    {
        if (null == pname || null == addition || pname.isBlank())
            return;

        if (!this._Params.containsKey(pname))
            return;

        ParametersItem item = this._Params.get(pname);
        item.AddAddition(addition);
    }

    public void HandleAll()
    {
        if (0 == this._Params.size())
            return;

        for (ParametersItem item : this._Params.values())
            item.Handle();
    }

    public void HandleOne(String pname)
    {
        if (0 == this._Params.size())
            return;

        if (!this._Params.containsKey(pname))
            return;

        ParametersItem item = this._Params.get(pname);
        item.Handle();
    }
}
