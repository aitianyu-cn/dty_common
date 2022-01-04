#include "../../../testframe.hxx"
#include "../../../../native/prime/core/iterator.hpp"

class TestClass
{
public:
    TestClass()
    {
        ++TestClass::Counter;
    }
    ~TestClass()
    {
        --TestClass::Counter;
    }

public:
    object operator new[](size_t size)
    {
        ++TestClass::NewCounter;
        return ::operator new [](size);
    }

public:
    void operator delete[](object obj)
    {
        --TestClass::NewCounter;
        ::operator delete [](obj);
    }

public:
    static int32 Counter;

    static int32 NewCounter;
};

int32 TestClass::Counter = 0;
int32 TestClass::NewCounter = 0;

using FR = dty::collection::FilterResult<int32>;
using FRC = dty::collection::FilterResult<TestClass>;

FR* pFilter;

void test_spec_filter_result(dty::test::TestEntity& entity)
{
    entity.StartSpec("constructor", [](TE& entity) -> void
        {
            entity.RunTest("constructor", "new object with no params", [](TO& t) -> void
                {
                    FR filter;

                    t.EQ(0, (int32)filter.Length);
                    t.ToBeTrue(filter.IsEmpty());
                    t.ToBeTrue(filter.IsNull());
                }
            );

            entity.StartSpec("constructor(3 params)", [](TE& entity) -> void
                {
                    entity.RunExceptionTest("constructor(3 params)", "expect an error if elems is null", [](TO& t) -> void
                        {
                            FR filter(::null, 1, false);
                        }
                    );

                    entity.RunExceptionTest("constructor(3 params)", "expect an error if length is not great than 0", [](TO& t) -> void
                        {
                            FR filter((int32*)1, 0, false);
                        }
                    );

                    entity.RunTest("constructor(3 params)", "create a object successful", [](TO& t) -> void
                        {
                            FR filter((int32*)1, 1, false);
                        }
                    );
                }
            );

            entity.StartSpec("constructor(4 params)", [](TE& entity) -> void
                {
                    entity.RunExceptionTest("constructor(4 params)", "expect an error if elems is null", [](TO& t) -> void
                        {
                            FR filter(::null, 1, 0, false);
                        }
                    );

                    entity.RunExceptionTest("constructor(4 params)", "expect an error if length is not great than 0", [](TO& t) -> void
                        {
                            FR filter((int32*)1, 0, 0, false);
                        }
                    );

                    entity.RunExceptionTest("constructor(4 params)", "expect an error if length is great than size", [](TO& t) -> void
                        {
                            FR filter((int32*)1, 1, 0, false);
                        }
                    );

                    entity.RunTest("constructor(4 params)", "create a object successful", [](TO& t) -> void
                        {
                            FR filter((int32*)1, 1, 1, false);
                        }
                    );
                }
            );

            entity.RunTest("copy constructor", "new object from specified filter", [](TO& t) -> void
                {
                    FR filter1((int32*)1, 1, false);
                    FR filter_cp(filter1);

                    t.EQ(filter1.Length.Get(), filter_cp.Length.Get());
                }
            );

            entity.StartSpec("destructor", [](TE& entity) -> void
                {
                    entity.RunTest("destructor", "not need free", [](TO& t) -> void
                        {
                            TestClass* p = new TestClass[1];
                            int32 pre_counter = TestClass::Counter;

                            FRC* filter = new FRC(p, 1, false);
                            t.EQ(pre_counter, TestClass::Counter);

                            delete filter;
                            t.EQ(pre_counter, TestClass::Counter);

                            delete[] p;
                        }
                    );

                    entity.RunTest("destructor", "need free", [](TO& t) -> void
                        {
                            TestClass* p = new TestClass[3];
                            int32 pre_counter = TestClass::NewCounter;

                            FRC* filter = new FRC(p, 3);
                            t.EQ(pre_counter, TestClass::NewCounter);

                            delete filter;
                            if (!t.NE(pre_counter, TestClass::NewCounter))
                                delete [] p;
                        }
                    );
                }
            );
        }
    );

    entity.StartSpec("operator []", [](TE& entity) -> void
        {
            // enable assert mode for this spec
            entity.SetAssert();

            entity.RunTest("operator []", "Before All", [](TO& t) -> void
                {
                    int32* source = new int32[10]{ 0,1,2,3,4,5,6,7,8,9 };
                    if (!t.IsNotNull(source))
                        return;

                    pFilter = new FR(source, 10);

                    if (t.IsNotNull(pFilter))
                    {
                        t.EQ(10, (int32)pFilter->Length);
                        t.ToBeFalse(pFilter->IsEmpty());
                        t.ToBeFalse(pFilter->IsNull());
                    }
                    else
                        delete [] source;
                }
            );

            entity.RunExceptionTest("operator []", "expect an error if over range", [](TO& t) -> void
                {
                    int32 i = (*pFilter)[10];
                }
            );

            entity.RunTest("operator []", "can get the values correctly", [](TO& t) -> void
                {
                    for (int32 i = 0; i < 10; ++i)
                        t.EQ(i, (*pFilter)[i]);
                }
            );

            entity.RunTest("operator []", "can update the values correctly", [](TO& t) -> void
                {
                    for (int32 i = 0; i < 10; ++i)
                        (*pFilter)[i] = i * 10;

                    for (int32 i = 0; i < 10; ++i)
                        t.EQ(i * 10, (*pFilter)[i]);
                }
            );

            if (::null != pFilter)
                delete pFilter;
        }
    );
}