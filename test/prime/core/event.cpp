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

RUNTEST(PropTest, (const ::string)"dty.Event Unit Test")
{
    PropTest.StartSpec((const ::string)"default Event Arg", [](dty::test::TestEntity& entity) -> void
        {
            defaultHandler = ::null;
            defaultHandlerValue = -1;

            entity.RunTest((const ::string)"Spec Init", (const ::string)"prepare the test obj", [](dty::test::TestObject& tobj) -> void
                {
                    defaultHandler = new dty::EventHandler<dty::EventArgs>();

                    tobj.IsNotNull(defaultHandler);
                    tobj.EQ((int32)(defaultHandler->Count), 0);
                }
            );

            entity.RunTest((const ::string)"AddHandler", (const ::string)"add handles into Handler object", [](dty::test::TestObject& tobj) -> void
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

            entity.RunTest((const ::string)"AddHandler (Duplicate)", (const ::string)"add handles into Handler object", [](dty::test::TestObject& tobj) -> void
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

            entity.RunTest((const ::string)"Invoke", (const ::string)"invoke handles", [](dty::test::TestObject& tobj) -> void
                {
                    if (!tobj.IsNotNull(defaultHandler))
                        return;

                    defaultHandlerValue = 0;
                    defaultHandler->Invoke(::null, dty::EventArgs());

                    tobj.EQ(defaultHandlerValue, 0b00000011);
                }
            );

            entity.RunTest((const ::string)"RemoveHandler", (const ::string)"remove handle from handler", [](dty::test::TestObject& tobj) -> void
                {
                    if (!tobj.IsNotNull(defaultHandler))
                        return;

                    defaultHandler->RemoveHandler(1);

                    tobj.EQ((int32)(defaultHandler->Count), 1);
                }
            );

            entity.RunTest((const ::string)"Invoke(Duplicate)", (const ::string)"invoke handles after removing a handle", [](dty::test::TestObject& tobj) -> void
                {
                    if (!tobj.IsNotNull(defaultHandler))
                        return;

                    defaultHandlerValue = 0;
                    defaultHandler->Invoke(::null, dty::EventArgs());

                    tobj.EQ(defaultHandlerValue, 0b00000010);
                }
            );

            entity.RunTest((const ::string)"Clear", (const ::string)"clear handles from handler", [](dty::test::TestObject& tobj) -> void
                {
                    if (!tobj.IsNotNull(defaultHandler))
                        return;

                    defaultHandler->Clear();
                    tobj.EQ((int32)(defaultHandler->Count), 0);
                }
            );

            entity.RunTest((const ::string)"Invoke(Duplicate)", (const ::string)"invoke handles after clear handler", [](dty::test::TestObject& tobj) -> void
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

    PropTest.StartSpec((const ::string)"Customized Event Arg", [](dty::test::TestEntity& entity) -> void
        {
            customHandler = ::null;
            customHandlerValue = -1;

            entity.RunTest((const ::string)"Spec Init", (const ::string)"prepare the test obj", [](dty::test::TestObject& tobj) -> void
                {
                    customHandler = new dty::EventHandler<CustomEventArgs>();

                    tobj.IsNotNull(customHandler);
                    tobj.EQ((int32)(customHandler->Count), 0);
                }
            );

            entity.RunTest((const ::string)"AddHandler", (const ::string)"add handles into Handler object", [](dty::test::TestObject& tobj) -> void
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

            entity.RunTest((const ::string)"AddHandler (Duplicate)", (const ::string)"add handles into Handler object", [](dty::test::TestObject& tobj) -> void
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

            entity.RunTest((const ::string)"Invoke", (const ::string)"invoke handles with param = 1", [](dty::test::TestObject& tobj) -> void
                {
                    if (!tobj.IsNotNull(customHandler))
                        return;

                    customHandlerValue = 0;
                    customHandler->Invoke(::null, CustomEventArgs(1));

                    tobj.EQ(customHandlerValue, 0b00000011);
                }
            );

            entity.RunTest((const ::string)"RemoveHandler", (const ::string)"remove handle from handler", [](dty::test::TestObject& tobj) -> void
                {
                    if (!tobj.IsNotNull(customHandler))
                        return;

                    customHandler->RemoveHandler(1);

                    tobj.EQ((int32)(customHandler->Count), 1);
                }
            );

            entity.RunTest((const ::string)"Invoke(Duplicate)", (const ::string)"invoke handles after removing a handle with param = 2", [](dty::test::TestObject& tobj) -> void
                {
                    if (!tobj.IsNotNull(customHandler))
                        return;

                    customHandlerValue = 0;
                    customHandler->Invoke(::null, CustomEventArgs(2));

                    tobj.EQ(customHandlerValue, 0b00000100);
                }
            );

            entity.RunTest((const ::string)"Clear", (const ::string)"clear handles from handler", [](dty::test::TestObject& tobj) -> void
                {
                    if (!tobj.IsNotNull(customHandler))
                        return;

                    customHandler->Clear();
                    tobj.EQ((int32)(customHandler->Count), 0);
                }
            );

            entity.RunTest((const ::string)"Invoke(Duplicate)", (const ::string)"invoke handles after clear handler with param = 4", [](dty::test::TestObject& tobj) -> void
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