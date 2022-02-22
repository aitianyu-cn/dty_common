package Tools.Common.Param;

import java.util.Stack;

public class ParameterHandler
{
    private ComparisonCollection _Comparisons;

    public ParameterHandler()
    {
        this._Comparisons = new ComparisonCollection();
    }

    public void AddComparison(String fname, char sname, ParamAdditionState astate, int code,
            ParameterHandlerDelegate handle)
    {
        this._Comparisons.AddItem(fname, sname, astate, code, handle);
    }

    public ParameterHandlerResult ProcessParameter(String[] args)
    {
        ParameterProcessor processor = new ParameterProcessor(this._Comparisons);
        processor.Process(args);

        ParameterHandlerResult result = new ParameterHandlerResult();
        result.Message = processor.GetMessage();
        result.Params = processor.GetParameters();

        return result;
    }
}

class ParameterProcessor
{
    private Parameters _Parameters;
    private ComparisonCollection _Comparison;
    private Stack<String> _MessageCollection;

    public ParameterProcessor(ComparisonCollection comparison)
    {
        this._Parameters = new Parameters();
        this._Comparison = comparison;
        this._MessageCollection = new Stack<String>();
    }

    public void Process(String[] args)
    {
        if (null == args || 0 == args.length)
            return;

        int index = 0;
        while (index < args.length)
        {
            String source = args[index++];

            String control = this.IsControl(source);
            if (null != control)
                index = this.Process(control, args, index);
            else
                this._MessageCollection.push(String.format("无法识别的参数: %s 需要控制符/控制符无效", source));
        }
    }

    public Parameters GetParameters()
    {
        return this._Parameters;
    }

    public String[] GetMessage()
    {
        String[] mess = new String[this._MessageCollection.size()];

        for (int i = 0; i < mess.length; ++i)
            mess[i] = this._MessageCollection.get(i);

        return mess;
    }

    private int Process(String control, String[] args, int index)
    {
        ComparisonItem compar = this._Comparison.GetItem(control);
        if (null == compar)
        {
            this._MessageCollection.push(String.format("无法识别的参数: %s 控制符无效", args[index - 1]));
            return index;
        }

        switch (compar.GetState())
        {
            case ONCE:
                if (index < args.length && null == this.IsControl(args[index]))
                {
                    this._Parameters.AddParam(compar.GetFullName(), compar.GetHandler());
                    this._Parameters.AddAddition(compar.GetFullName(), args[index++]);
                }
                else
                    this._MessageCollection
                            .push(String.format("控制符: --%s(-%c) 需要一个参数", compar.GetFullName(), compar.GetSingleName()));
                break;
            case TWICE:
                if (index + 1 < args.length && null == this.IsControl(args[index])
                        && null == this.IsControl(args[index + 1]))
                {
                    this._Parameters.AddParam(compar.GetFullName(), compar.GetHandler());
                    this._Parameters.AddAddition(compar.GetFullName(), args[index++]);
                    this._Parameters.AddAddition(compar.GetFullName(), args[index++]);
                }
                else
                    this._MessageCollection
                            .push(String.format("控制符: --%s(-%c) 需要两个参数", compar.GetFullName(), compar.GetSingleName()));
                break;
            case SELECTABLE:
                this._Parameters.AddParam(compar.GetFullName(), compar.GetHandler());
                while (index < args.length && null == this.IsControl(args[index]))
                    this._Parameters.AddAddition(compar.GetFullName(), args[index++]);
                break;
            case MORE:
                if (index < args.length && null == this.IsControl(args[index]))
                {
                    do
                    {
                        this._Parameters.AddParam(compar.GetFullName(), compar.GetHandler());
                        this._Parameters.AddAddition(compar.GetFullName(), args[index++]);
                    } while (index < args.length && null == this.IsControl(args[index]));
                }
                else
                    this._MessageCollection.push(
                            String.format("控制符: --%s(-%c) 需要至少一个参数", compar.GetFullName(), compar.GetSingleName()));
                break;
            case NONE:
            default:
                this._Parameters.AddParam(compar.GetFullName(), compar.GetHandler());
                break;
        }

        return index;
    }

    private String IsControl(String source)
    {
        String control = null;

        char single = ParameterProcessor.IsSingle(source);
        if ('\0' != single)
            control = this.ExpandSingle(single);
        else
            control = ParameterProcessor.IsFull(source);

        return control;
    }

    private String ExpandSingle(char ch)
    {
        ComparisonItem item = this._Comparison.GetItem(ch);
        if (null == item)
            return null;

        return item.GetFullName();
    }

    private static char IsSingle(String str)
    {
        char single = '\0';

        str = str.trim();
        if (2 == str.length() && '-' == str.charAt(0) && IsCharVaild(str.charAt(1)))
            single = str.charAt(1);

        return single;
    }

    private static String IsFull(String str)
    {
        String full = null;

        if (2 < str.length() && str.startsWith("--") && IsCharVaild(str.charAt(2)))
            full = str.substring(2);

        return full;
    }

    private static boolean IsCharVaild(char ch)
    {
        if ((int) ch > 0x4E00 && (int) ch < 0x9FA5)
            return true;

        if (ch >= 'A' && ch <= 'Z')
            return true;

        if (ch >= 'a' && ch <= 'z')
            return true;

        return false;
    }
}