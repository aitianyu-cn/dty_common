package build.handler;

import java.util.HashMap;

// Parameter Structure
/**
 * 1. single parameter: '-' + 'single char', this will function to a full parameter
 * 2. full parameter: '--' + 'full name', each full name will have a unified code
 * 
 * 3. additional parameter: by a definition, each parameter code will have a introduction to
 * describe whether an additional parameter should exist or not, and how many of the additions are
 * required.
 */

public class ParameterHandler
{
    private HashMap<Character, String> _SingleList;
    private HashMap<String, Integer> _ParameterList;
    private HashMap<Integer, IParamHandle> _HandleList;

    private HashMap<Integer, ParameterItem> _Parameters;

    public ParameterHandler(String[] args)
    {
        this._SingleList = new HashMap<Character, String>();
        this._ParameterList = new HashMap<String, Integer>();
        this._HandleList = new HashMap<Integer, IParamHandle>();

        // create a empty Parameter list and insert the Invalid parameter to be default.
        this._Parameters = new HashMap<>();
        this._Parameters.put(ParameterItem.ParameterInvalidCode, new ParameterItem());
    }

    public void AddParaName(String fullName, int code, IParamHandle handle)
    {
        this.AddParaName('\0', fullName, code, handle);
    }

    public void AddParaName(char singleName, String fullName, int code, IParamHandle handle)
    {
        // if the parameter name existed, do not replace
        if (this._ParameterList.containsKey(fullName))
            return;

        // insert the parameter
        this._ParameterList.put(fullName, code);

        // when the handle is not null, push it into handle list, old one will be replaced.
        if (null != handle)
            this._HandleList.put(code, handle);

        // anyhow to insert or replace the single name when the single name is not invalid.
        if ('\0' != singleName)
            this._SingleList.put(singleName, fullName);
    }

    public void ProcessParameter(String[] args)
    {
        if (null == args)
            return;

        for (String arg : args)
        {
            if (null == arg || arg.isBlank())
                continue;

        }
    }
}

class ParameterProcessor
{

}