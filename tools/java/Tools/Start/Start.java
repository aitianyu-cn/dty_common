package Tools.Start;

import java.util.Iterator;

import Tools.Common.Param.*;

public class Start
{
    public static void main(String[] args)
    {
        ParameterHandler parameterHandler = new ParameterHandler();

        parameterHandler.AddComparison("help", 'h', ParamAdditionState.NONE, 1, new ParameterHandlerDelegate()
        {
            @Override
            public void Handler(Iterator<String> iterator)
            {
                if (null == iterator)
                    return;

                System.out.println("Help");
                while (iterator.hasNext())
                    System.out.println(String.format("\t%s", iterator.next()));
            }
        });

        parameterHandler.AddComparison("param1", 'a', ParamAdditionState.ONCE, 1, new ParameterHandlerDelegate()
        {
            @Override
            public void Handler(Iterator<String> iterator)
            {
                if (null == iterator)
                    return;

                System.out.println("Param1");
                while (iterator.hasNext())
                    System.out.println(String.format("\t%s", iterator.next()));
            }
        });

        parameterHandler.AddComparison("param2", 'b', ParamAdditionState.TWICE, 1, new ParameterHandlerDelegate()
        {
            @Override
            public void Handler(Iterator<String> iterator)
            {
                if (null == iterator)
                    return;

                System.out.println("Param2");
                while (iterator.hasNext())
                    System.out.println(String.format("\t%s", iterator.next()));
            }
        });

        parameterHandler.AddComparison("param3", 'c', ParamAdditionState.SELECTABLE, 1, new ParameterHandlerDelegate()
        {
            @Override
            public void Handler(Iterator<String> iterator)
            {
                if (null == iterator)
                    return;

                System.out.println("Param3");
                while (iterator.hasNext())
                    System.out.println(String.format("\t%s", iterator.next()));
            }
        });

        parameterHandler.AddComparison("param4", 'd', ParamAdditionState.MORE, 1, new ParameterHandlerDelegate()
        {
            @Override
            public void Handler(Iterator<String> iterator)
            {
                if (null == iterator)
                    return;

                System.out.println("Param4");
                while (iterator.hasNext())
                    System.out.println(String.format("\t%s", iterator.next()));
            }
        });

        ParameterHandlerResult parameters = parameterHandler.ProcessParameter(args);

        for (String msg : parameters.Message)
            System.out.println(String.format("[MESSAGE] %s", msg));

        parameters.Params.HandleAll();
    }
}
