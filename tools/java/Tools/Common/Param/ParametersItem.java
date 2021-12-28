package Tools.Common.Param;

import java.util.LinkedList;

public class ParametersItem
{
    private ParameterHandlerDelegate _Handler;
    private LinkedList<String> _Additional;

    public ParametersItem()
    {
        this._Handler = null;
        this._Additional = new LinkedList<String>();
    }

    public ParametersItem(ParameterHandlerDelegate handler)
    {
        this._Handler = handler;
        this._Additional = new LinkedList<String>();
    }

    public void AddAddition(String addition)
    {
        if (null == addition || addition.isBlank())
            return;

        if (this._Additional.contains(addition))
            return;

        this._Additional.add(addition);
    }

    public void Handle()
    {
        if (null == this._Handler)
            return;

        this._Handler.Handler(this._Additional.iterator());
    }
}
