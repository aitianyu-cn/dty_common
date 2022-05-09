#include "../../../testframe.hxx"
#include "../../../../native/prime/core/iterator.hpp"

class TestClass_Entity
{
public:
    TestClass_Entity()
    {
        ++TestClass_Entity::Counter;
    }
    ~TestClass_Entity()
    {
        --TestClass_Entity::Counter;
    }

public:
    object operator new[](size_t size)
    {
        ++TestClass_Entity::NewCounter;
        return ::operator new [](size);
    }

public:
    void operator delete[](object obj)
    {
        --TestClass_Entity::NewCounter;
        ::operator delete [](obj);
    }

public:
    static int32 Counter;

    static int32 NewCounter;
};

int32 TestClass_Entity::Counter = 0;
int32 TestClass_Entity::NewCounter = 0;

using IE = dty::collection::IteratorEntity<int32>;
using IEC = dty::collection::IteratorEntity<TestClass_Entity>;

IE* pIterator = ::null;
int32 EnumCounter = 0;

void test_spec_iterator_entity(dty::test::TestEntity& entity)
{
    entity.StartSpec("construct", [](TE& entity) -> void
        {
            entity.StartSpec("constructor", [](TE& entity) -> void
                {
                    entity.RunExceptionTest("constructor", "expect an error if pointer is null and size does not equal 0", [](TO& t) -> void
                        {
                            IE e(::null, 1);
                        }
                    );

                    entity.RunExceptionTest("constructor", "expect an error if size is less than 0", [](TO& t) -> void
                        {
                            IE e((int32*)1, -1);
                        }
                    );

                    entity.RunTest("constructor", "new object from specified pointer successful", [](TO& t) -> void
                        {
                            IE e((int32*)1, 1, false);
                        }
                    );
                }
            );

            entity.StartSpec("copy constructor", [](TE& entity) -> void
                {
                    entity.RunTest("copy constructor", "do not need to free", [](TO& t) -> void
                        {
                            int32* p = new int32[10]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
                            IE e1(p, 10, false);
                            IE e2(e1);

                            for (int32 i = 0; i < 10; ++i)
                                t.EQ(i, *(e2.Get(i)));

                            delete [] p;
                        }
                    );

                    entity.RunTest("copy constructor", "need to free", [](TO& t) -> void
                        {
                            int32* p = new int32[10]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
                            IE e1(p, 10, true);
                            IE e2(e1);

                            for (int32 i = 0; i < 10; ++i)
                                t.EQ(i, *(e2.Get(i)));
                        }
                    );
                }
            );

            entity.StartSpec("destructor", [](TE& entity) -> void
                {
                    entity.RunTest("destructor", "nothing needs to do if does not need to free", [](TO& t) -> void
                        {
                            TestClass_Entity* p = new TestClass_Entity[10];
                            IEC* e = new IEC(p, 10, false);

                            int32 pre_counter = TestClass_Entity::NewCounter;

                            delete e;
                            if (t.EQ(pre_counter, TestClass_Entity::NewCounter))
                                delete [] p;
                        }
                    );

                    entity.RunTest("destructor", "nothing needs to do if size is 0", [](TO& t) -> void
                        {
                            IE* p = new IE(::null, 0, true);

                            delete p;
                        }
                    );

                    entity.RunTest("destructor", "release pointer only when the pointer is not used", [](TO& t) -> void
                        {
                            TestClass_Entity* p = new TestClass_Entity[10];
                            IEC* e1 = new IEC(p, 10, true);
                            IEC* e2 = new IEC(*e1);

                            int32 pre_counter = TestClass_Entity::NewCounter;

                            delete e1;
                            t.EQ(pre_counter, TestClass_Entity::NewCounter);

                            delete e2;
                            if (!t.NE(pre_counter, TestClass_Entity::NewCounter))
                                delete [] p;
                        }
                    );
                }
            );
        }
    );

    entity.RunTest("Before All", "", [](TO& t) -> void
        {
            int32* p = new int32[10]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            if (!t.IsNotNull(p))
                return;

            pIterator = new IE(p, 10, true);
            if (!t.IsNotNull(pIterator))
            {
                pIterator = ::null;
                delete [] p;
                return;
            }
        }
    );

    // only when the pre-state is not success, skip all the follow tests
    if (TS::Success != entity.GetState())
        entity.SetAssert();

    entity.StartSpec("Get", [](TE& entity) -> void
        {
            entity.RunTest("Get", "size = 0", [](TO& t) -> void
                {
                    IE e(::null, 0);

                    t.ToBeTrue(e.Get(0).IsNull());
                }
            );

            entity.RunTest("Get", "correct index should return indicated item", [](TO& t) -> void
                {
                    for (int32 i = 0; i < pIterator->Size; ++i)
                        t.EQ(i, *(pIterator->Get(i)));
                }
            );

            entity.RunTest("Get", "wrong index(less than 0) should return the first item", [](TO& t) -> void
                {
                    t.EQ(0, *(pIterator->Get(-1)));
                }
            );

            entity.RunTest("Get", "wrong index(over size) should return the last item", [](TO& t) -> void
                {
                    t.EQ(9, *(pIterator->Get(10)));
                }
            );

            entity.RunTest("Get", "got value can be edited successfully", [](TO& t) -> void
                {
                    *(pIterator->Get(6)) = 60;
                    t.EQ(60, *(pIterator->Get(6)));

                    *(pIterator->Get(6)) = 6;
                    t.EQ(6, *(pIterator->Get(6)));
                }
            );
        }
    );

    entity.StartSpec("End", [](TE& entity) -> void
        {
            entity.RunTest("End", "size = 0", [](TO& t) -> void
                {
                    IE e(::null, 0);

                    t.ToBeTrue(e.End().IsNull());
                }
            );

            entity.RunTest("End", "size != 0", [](TO& t) -> void
                {
                    t.EQ(9, *(pIterator->End()));
                }
            );
        }
    );

    // should stop the Enum APIs tests if error happened.
    if (TS::Success != entity.GetState())
        entity.SetAssert();

    entity.StartSpec("Enum APIs", [](TE& entity) -> void
        {
            entity.StartSpec("ForEach", [](TE& entity) -> void
                {
                    entity.RunTest("ForEach", "Size = 0", [](TO& t) -> void
                        {
                            IE e(::null, 0);

                            e.ForEach([](int32& value) -> void
                                {
                                    ++EnumCounter;
                                }
                            );

                            t.EQ(0, EnumCounter);

                            // anyway, to reset the counter
                            EnumCounter = 0;
                        }
                    );

                    entity.RunTest("ForEach", "Size > 0 needs to foreach all elements", [](TO& t) -> void
                        {
                            pIterator->ForEach([](int32& value) -> void
                                {
                                    ++EnumCounter;
                                }
                            );

                            t.EQ(10, EnumCounter);

                            // anyway, to reset the counter
                            EnumCounter = 0;
                        }
                    );
                }
            );

            entity.StartSpec("Some", [](TE& entity) -> void
                {
                    entity.RunTest("Some", "return an element which one is invalid firstly", [](TO& t) -> void
                        {
                            int32* res = pIterator->Some([](int32& value) -> bool
                                {
                                    return value < 5;
                                }
                            );

                            if (t.IsNotNull(res))
                                t.EQ(5, *res);
                        }
                    );

                    entity.RunTest("Some", "return null if all elements are valid", [](TO& t) -> void
                        {
                            int32* res = pIterator->Some([](int32& value) -> bool
                                {
                                    return value < 10;
                                }
                            );

                            t.IsNull(res);
                        }
                    );
                }
            );

            entity.StartSpec("Filter", [](TE& entity) -> void
                {
                    entity.RunTest("Filter", "return empty FilterResult object if size = 0", [](TO& t) -> void
                        {
                            IE e(::null, 0);

                            dty::collection::FilterResult<int32> fr = e.Filter([](int32& value) -> bool
                                {
                                    return true;
                                }
                            );

                            t.ToBeTrue(fr.IsEmpty());
                            t.ToBeTrue(fr.IsNull());
                        }
                    );

                    entity.RunTest("Filter", "return empty FilterResult object if no element mapping", [](TO& t) -> void
                        {
                            dty::collection::FilterResult<int32> fr = pIterator->Filter([](int32& value) -> bool
                                {
                                    return value >= 10;
                                }
                            );

                            t.ToBeTrue(fr.IsEmpty());
                            t.ToBeTrue(fr.IsNull());
                        }
                    );

                    entity.RunTest("Filter", "get a not empty FilterResult if at least one element mapping", [](TO& t) -> void
                        {
                            dty::collection::FilterResult<int32> fr = pIterator->Filter([](int32& value) -> bool
                                {
                                    return value == 9;
                                }
                            );

                            t.ToBeFalse(fr.IsEmpty());
                            t.EQ(1, (int32)fr.Length);
                            t.EQ(9, fr[0]);
                        }
                    );
                }
            );

            entity.StartSpec("Never", [](TE& entity) -> void
                {
                    entity.RunTest("Never", "return empty FilterResult object if size = 0", [](TO& t) -> void
                        {
                            IE e(::null, 0);

                            dty::collection::FilterResult<int32> fr = e.Never([](int32& value) -> bool
                                {
                                    return true;
                                }
                            );

                            t.ToBeTrue(fr.IsEmpty());
                            t.ToBeTrue(fr.IsNull());
                        }
                    );

                    entity.RunTest("Never", "return empty FilterResult object if all element mapping", [](TO& t) -> void
                        {
                            dty::collection::FilterResult<int32> fr = pIterator->Never([](int32& value) -> bool
                                {
                                    return value < 10;
                                }
                            );

                            t.ToBeTrue(fr.IsEmpty());
                            t.ToBeTrue(fr.IsNull());
                        }
                    );

                    entity.RunTest("Never", "get a not empty FilterResult if at least one element not mapping", [](TO& t) -> void
                        {
                            dty::collection::FilterResult<int32> fr = pIterator->Never([](int32& value) -> bool
                                {
                                    return value != 9;
                                }
                            );

                            t.ToBeFalse(fr.IsEmpty());
                            t.EQ(1, (int32)fr.Length);
                            t.EQ(9, fr[0]);
                        }
                    );
                }
            );

            entity.StartSpec("Find", [](TE& entity) -> void
                {
                    entity.RunTest("Find", "return an element which one is valid firstly", [](TO& t) -> void
                        {
                            int32* res = pIterator->Find([](int32& value) -> bool
                                {
                                    return value > 5;
                                }
                            );

                            if (t.IsNotNull(res))
                                t.EQ(6, *res);
                        }
                    );

                    entity.RunTest("Find", "return null if all elements are invalid", [](TO& t) -> void
                        {
                            int32* res = pIterator->Find([](int32& value) -> bool
                                {
                                    return value >= 10;
                                }
                            );

                            t.IsNull(res);
                        }
                    );
                }
            );

            entity.StartSpec("FindIndex", [](TE& entity) -> void
                {
                    entity.RunTest("FindIndex", "return a valid index if there is at least one valid element", [](TO& t) -> void
                        {
                            int32 res = pIterator->FindIndex([](int32& value) -> bool
                                {
                                    return value > 5;
                                }
                            );

                            t.EQ(6, res);
                        }
                    );

                    entity.RunTest("FindIndex", "return -1 if all elements are invalid", [](TO& t) -> void
                        {
                            int32 res = pIterator->FindIndex([](int32& value) -> bool
                                {
                                    return value >= 10;
                                }
                            );

                            t.EQ(-1, res);
                        }
                    );
                }
            );
        }
    );

    entity.RunTest("After All", "", [](TO& t) -> void
        {
            if (::null != pIterator)
                delete pIterator;
        }
    );
}