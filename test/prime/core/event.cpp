#include "../../testframe.hxx"
#include "../../../native/prime/core/event.hpp"

class CustomEventArgs : public virtual dty::EventArgs
{
    __PUB__ int32 Value;

    __PUB__         CustomEventArgs(int32 value) :dty::EventArgs(), Value(value)
    { }
    __PUB__ virtual ~CustomEventArgs() __override_func { }
};

dty::EventHandler<dty::EventArgs>* defaultHandler;
dty::EventHandler<CustomEventArgs>* customHandler;

int32 defaultHandlerValue;
int32 customHandlerValue;

TEST_MAIN("dty.Event Unit Test")
{
    TEST_SPEC("default Event Arg",
        {
            defaultHandler = ::null;
            defaultHandlerValue = -1;

            TEST_ITEM("Spec Init", "prepare the test obj",
                {
                    defaultHandler = new dty::EventHandler<dty::EventArgs>();

                    tobj.IsNotNull(defaultHandler);
                    tobj.EQ((int32)(defaultHandler->Count), 0);
                }
            );

            TEST_ITEM("AddHandler", "add handles into Handler object",
                {
                    if (!tobj.IsNotNull(defaultHandler))
                        return;

                    defaultHandler->AddHandler(1, [](object sender, dty::EventArgs e) -> void
                        {
                            defaultHandlerValue |= 0b00000001;
                            return;
                        }
                    );

                    tobj.EQ((int32)(defaultHandler->Count), 1);
                }
            );

            TEST_ITEM("AddHandler (Duplicate)", "add handles into Handler object",
                {
                    if (!tobj.IsNotNull(defaultHandler))
                        return;

                    defaultHandler->AddHandler(2, [](object sender, dty::EventArgs e) -> void
                        {
                            defaultHandlerValue |= 0b00000010;
                            return;
                        }
                    );

                    tobj.EQ((int32)(defaultHandler->Count), 2);
                }
            );

            TEST_ITEM("Invoke", "invoke handles",
                {
                    if (!tobj.IsNotNull(defaultHandler))
                        return;

                    defaultHandlerValue = 0;
                    defaultHandler->Invoke(::null, dty::EventArgs());

                    tobj.EQ(defaultHandlerValue, 0b00000011);
                }
            );

            TEST_ITEM("RemoveHandler", "remove handle from handler",
                {
                    if (!tobj.IsNotNull(defaultHandler))
                        return;

                    defaultHandler->RemoveHandler(1);

                    tobj.EQ((int32)(defaultHandler->Count), 1);
                }
            );

            TEST_ITEM("Invoke(Duplicate)", "invoke handles after removing a handle",
                {
                    if (!tobj.IsNotNull(defaultHandler))
                        return;

                    defaultHandlerValue = 0;
                    defaultHandler->Invoke(::null, dty::EventArgs());

                    tobj.EQ(defaultHandlerValue, 0b00000010);
                }
            );

            TEST_ITEM("Clear", "clear handles from handler",
                {
                    if (!tobj.IsNotNull(defaultHandler))
                        return;

                    defaultHandler->Clear();
                    tobj.EQ((int32)(defaultHandler->Count), 0);
                }
            );

            TEST_ITEM("Invoke(Duplicate)", "invoke handles after clear handler",
                {
                    if (!tobj.IsNotNull(defaultHandler))
                        return;

                    defaultHandlerValue = 0;
                    defaultHandler->Invoke(::null, dty::EventArgs());

                    tobj.EQ(defaultHandlerValue, 0b00000000);
                }
            );

            if (::null != defaultHandler)
                delete defaultHandler;
        }
    );

    TEST_SPEC("Customized Event Arg",
        {
            customHandler = ::null;
            customHandlerValue = -1;

            TEST_ITEM("Spec Init", "prepare the test obj",
                {
                    customHandler = new dty::EventHandler<CustomEventArgs>();

                    tobj.IsNotNull(customHandler);
                    tobj.EQ((int32)(customHandler->Count), 0);
                }
            );

            TEST_ITEM("AddHandler", "add handles into Handler object",
                {
                    if (!tobj.IsNotNull(customHandler))
                        return;

                    customHandler->AddHandler(1, [](object sender, CustomEventArgs e) -> void
                        {
                            customHandlerValue |= e.Value;
                            return;
                        }
                    );

                    tobj.EQ((int32)(customHandler->Count), 1);
                }
            );

            TEST_ITEM("AddHandler (Duplicate)", "add handles into Handler object",
                {
                    if (!tobj.IsNotNull(customHandler))
                        return;

                    customHandler->AddHandler(2, [](object sender, CustomEventArgs e) -> void
                        {
                            customHandlerValue |= (e.Value << 1);
                            return;
                        }
                    );

                    tobj.EQ((int32)(customHandler->Count), 2);
                }
            );

            TEST_ITEM("Invoke", "invoke handles with param = 1",
                {
                    if (!tobj.IsNotNull(customHandler))
                        return;

                    customHandlerValue = 0;
                    customHandler->Invoke(::null, CustomEventArgs(1));

                    tobj.EQ(customHandlerValue, 0b00000011);
                }
            );

            TEST_ITEM("RemoveHandler", "remove handle from handler",
                {
                    if (!tobj.IsNotNull(customHandler))
                        return;

                    customHandler->RemoveHandler(1);

                    tobj.EQ((int32)(customHandler->Count), 1);
                }
            );

            TEST_ITEM("Invoke(Duplicate)", "invoke handles after removing a handle with param = 2",
                {
                    if (!tobj.IsNotNull(customHandler))
                        return;

                    customHandlerValue = 0;
                    customHandler->Invoke(::null, CustomEventArgs(2));

                    tobj.EQ(customHandlerValue, 0b00000100);
                }
            );

            TEST_ITEM("Clear", "clear handles from handler",
                {
                    if (!tobj.IsNotNull(customHandler))
                        return;

                    customHandler->Clear();
                    tobj.EQ((int32)(customHandler->Count), 0);
                }
            );

            TEST_ITEM("Invoke(Duplicate)", "invoke handles after clear handler with param = 4",
                {
                    if (!tobj.IsNotNull(customHandler))
                        return;

                    customHandlerValue = 0;
                    customHandler->Invoke(::null, CustomEventArgs(4));

                    tobj.EQ(customHandlerValue, 0b00000000);
                }
            );

            if (::null != customHandler)
                delete customHandler;
        }
    );
}