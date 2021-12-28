package Tools.Common.Param;

public class ComparisonItem extends ComparisonKey
{
    private int _Code;
    private ParamAdditionState _AdditionState;
    private ParameterHandlerDelegate _Handler;

    public ComparisonItem(int code, ComparisonKey key, ParamAdditionState astate, ParameterHandlerDelegate handler)
    {
        super(key);

        this._Code = code;
        this._AdditionState = astate;
        this._Handler = handler;
    }

    public int GetCode()
    {
        return this._Code;
    }

    public ParamAdditionState GetState()
    {
        return this._AdditionState;
    }

    public ParameterHandlerDelegate GetHandler()
    {
        return this._Handler;
    }
}
