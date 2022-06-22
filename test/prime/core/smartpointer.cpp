#include "../../testframe.hxx"
#include "../../../native/prime/core/pointer.hpp"

class TestClass
{
    __PUB__ TestClass()
    {
        ++TestClass::Counter;
    }
    __PUB__ ~TestClass()
    {
        --TestClass::Counter;
    }

    __PUB__ int32 GetValue()
    {
        return TestClass::Counter;
    }

    __PUB__ static int32 Counter;
};
int32 TestClass::Counter = 0;

class EQTestClass
{
    __PUB__ bool operator ==(EQTestClass& other)
    {
        throw 1;
    }
    __PUB__ bool operator !=(EQTestClass& other)
    {
        throw 1;
    }
};

class F
{
    __PUB__ virtual ~F() { }

    __PUB__ virtual int32 GetValue()
    {
        return 1;
    }
};

class C : public F
{
    __PUB__ int32 Value;

    __PUB__ C() : F(), Value() { }
    __PUB__ C(int32 value) : F(), Value(value) { }
    __PUB__ virtual ~C() override { }

    __PUB__ virtual int32 GetValue() override
    {
        return this->Value;
    }
};

dty::SmartPointer<TestClass>* sp;

RUNTEST(entity, "dty.common.native.test.prime.core.pointer")
{
    sp = ::null;

    entity.StartSpec("constructor", [](TE& entity) -> void
        {
            entity.RunTest("constructor", "default", [](TO& t) -> void
                {
                    int32 pre_counter = TestClass::Counter;
                    sp = new dty::SmartPointer<TestClass>();

                    if (!t.IsNotNull(sp))
                        return;

                    t.ToBeTrue(sp->IsNull());
                    t.EQ(TestClass::Counter, pre_counter);

                    // pointer size should be empty
                    int64 size = sp->Size;
                    t.EQ(size, 0LL);

                    delete sp;
                    sp = ::null;
                }
            );

            entity.RunTest("constructor", "create from a pointer, size = 1", [](TO& t) -> void
                {
                    TestClass* test_p = new TestClass();
                    if (!t.IsNotNull(test_p))
                        return;

                    int32 pre_counter = TestClass::Counter;
                    sp = new dty::SmartPointer<TestClass>(test_p);
                    if (!t.IsNotNull(sp))
                    {
                        delete test_p;
                        return;
                    }
                    // check the new SP is created and the test class object is still single
                    t.ToBeFalse(sp->IsNull());
                    t.EQ(TestClass::Counter, pre_counter);

                    // pointer size should be equal 1
                    int64 size = sp->Size;
                    t.EQ(size, 1LL);

                    delete sp;
                    sp = ::null;
                    // delete the SP, test class object should be deleted
                    if (!t.EQ(TestClass::Counter, pre_counter - 1))
                        delete test_p; // if not be deleted, delete it
                }
            );

            entity.RunTest("constructor", "create from a pointer, size = 2", [](TO& t) -> void
                {
                    TestClass* test_p = new TestClass[2];
                    if (!t.IsNotNull(test_p))
                        return;

                    int32 pre_counter = TestClass::Counter;
                    sp = new dty::SmartPointer<TestClass>(test_p, (int64)2);
                    if (!t.IsNotNull(sp))
                    {
                        delete [] test_p;
                        return;
                    }
                    // check the new SP is created and the test class object is still single
                    t.ToBeFalse(sp->IsNull());
                    t.EQ(TestClass::Counter, pre_counter);

                    // pointer size should be equal 1
                    int64 size = sp->Size;
                    t.EQ(size, 2LL);

                    delete sp;
                    sp = ::null;
                    // delete the SP, test class object should be deleted
                    if (!t.EQ(TestClass::Counter, pre_counter - 2))
                        delete [] test_p; // if not be deleted, delete it
                }
            );

            entity.StartSpec("constructor (weak mode)", [](TE& entity) -> void
                {
                    entity.RunTest("constructor (weak mode)", "create from a pointer, size = 1, weak mode = false", [](TO& t) -> void
                        {
                            TestClass* test_p = new TestClass();
                            if (!t.IsNotNull(test_p))
                                return;

                            int32 pre_counter = TestClass::Counter;
                            sp = new dty::SmartPointer<TestClass>(test_p, false);
                            if (!t.IsNotNull(sp))
                            {
                                delete test_p;
                                return;
                            }
                            // check the new SP is created and the test class object is still single
                            t.ToBeFalse(sp->IsNull());
                            t.EQ(TestClass::Counter, pre_counter);

                            // pointer size should be equal 1
                            int64 size = sp->Size;
                            t.EQ(size, 1LL);

                            delete sp;
                            sp = ::null;
                            // delete the SP, test class object should be deleted
                            if (!t.EQ(TestClass::Counter, pre_counter - 1))
                                delete test_p; // if not be deleted, delete it
                        }
                    );

                    entity.RunTest("constructor (weak mode)", "create from a pointer, size = 1, weak mode = true", [](TO& t) -> void
                        {
                            TestClass* test_p = new TestClass();
                            if (!t.IsNotNull(test_p))
                                return;

                            int32 pre_counter = TestClass::Counter;
                            sp = new dty::SmartPointer<TestClass>(test_p, true);
                            if (!t.IsNotNull(sp))
                            {
                                delete test_p;
                                return;
                            }
                            // check the new SP is created and the test class object is still single
                            t.ToBeFalse(sp->IsNull());
                            t.EQ(TestClass::Counter, pre_counter);

                            // pointer size should be equal 1
                            int64 size = sp->Size;
                            t.EQ(size, 1LL);

                            delete sp;
                            sp = ::null;
                            // delete the SP, test class object should not be deleted
                            if (t.EQ(TestClass::Counter, pre_counter))
                                delete test_p; // if not be deleted, delete it
                        }
                    );

                    entity.RunTest("constructor (weak mode)", "create from a pointer, size = 2, weak mode = false", [](TO& t) -> void
                        {
                            TestClass* test_p = new TestClass[2];
                            if (!t.IsNotNull(test_p))
                                return;

                            int32 pre_counter = TestClass::Counter;
                            sp = new dty::SmartPointer<TestClass>(test_p, (int64)2, false);
                            if (!t.IsNotNull(sp))
                            {
                                delete [] test_p;
                                return;
                            }
                            // check the new SP is created and the test class object is still single
                            t.ToBeFalse(sp->IsNull());
                            t.EQ(TestClass::Counter, pre_counter);

                            // pointer size should be equal 1
                            int64 size = sp->Size;
                            t.EQ(size, 2LL);

                            delete sp;
                            sp = ::null;
                            // delete the SP, test class object should be deleted
                            if (!t.EQ(TestClass::Counter, pre_counter - 2))
                                delete [] test_p; // if not be deleted, delete it
                        }
                    );

                    entity.RunTest("constructor (weak mode)", "create from a pointer, size = 2, weak mode = true", [](TO& t) -> void
                        {
                            TestClass* test_p = new TestClass[2];
                            if (!t.IsNotNull(test_p))
                                return;

                            int32 pre_counter = TestClass::Counter;
                            sp = new dty::SmartPointer<TestClass>(test_p, (int64)2, true);
                            if (!t.IsNotNull(sp))
                            {
                                delete [] test_p;
                                return;
                            }
                            // check the new SP is created and the test class object is still single
                            t.ToBeFalse(sp->IsNull());
                            t.EQ(TestClass::Counter, pre_counter);

                            // pointer size should be equal 1
                            int64 size = sp->Size;
                            t.EQ(size, 2LL);

                            delete sp;
                            sp = ::null;
                            // delete the SP, test class object should be deleted
                            if (t.EQ(TestClass::Counter, pre_counter))
                                delete [] test_p; // if not be deleted, delete it
                        }
                    );
                }
            );

            entity.StartSpec("copy constructor", [](TE& entity) -> void
                {
                    entity.RunTest("copy constructor", "copy from a strong pointer", [](TO& t) -> void
                        {
                            TestClass* test_p = new TestClass();
                            if (!t.IsNotNull(test_p))
                                return;
                            sp = new dty::SmartPointer<TestClass>(test_p);
                            if (!t.IsNotNull(sp))
                            {
                                delete test_p;
                                return;
                            }

                            // record the pre counter
                            int32 pre_counter = TestClass::Counter;

                            // copy data from sp
                            dty::SmartPointer<TestClass>* csp = new dty::SmartPointer(*sp);
                            if (!t.IsNotNull(csp))
                            {
                                delete sp;
                                delete test_p;
                                return;
                            }

                            // new object should not be created
                            t.EQ(TestClass::Counter, pre_counter);
                            t.ToBeFalse(csp->IsNull());
                            t.EQ((int64)(csp->Size), (int64)1);
                            t.ToBeTrue(sp->IsNull());
                            t.EQ((int64)(sp->Size), (int64)0);

                            // delete sp
                            delete sp;
                            sp = ::null;
                            // delete the SP, test class object should not be deleted
                            t.EQ(TestClass::Counter, pre_counter);

                            delete csp;
                            if (!t.EQ(TestClass::Counter, pre_counter - 1))
                                delete test_p; // if not be deleted, delete it
                        }
                    );

                    entity.RunTest("copy constructor", "copy from a weak pointer", [](TO& t) -> void
                        {
                            TestClass* test_p = new TestClass();
                            if (!t.IsNotNull(test_p))
                                return;
                            sp = new dty::SmartPointer<TestClass>(test_p, true);
                            if (!t.IsNotNull(sp))
                            {
                                delete test_p;
                                return;
                            }

                            // record the pre counter
                            int32 pre_counter = TestClass::Counter;

                            // copy data from sp
                            dty::SmartPointer<TestClass>* csp = new dty::SmartPointer(*sp);
                            if (!t.IsNotNull(csp))
                            {
                                delete sp;
                                delete test_p;
                                return;
                            }

                            // new object should not be created
                            t.EQ(TestClass::Counter, pre_counter);
                            t.ToBeFalse(csp->IsNull());
                            t.EQ((int64)(csp->Size), (int64)1);
                            t.ToBeFalse(sp->IsNull());
                            t.EQ((int64)(sp->Size), (int64)1);

                            // delete sp
                            delete sp;
                            sp = ::null;
                            // delete the SP, test class object should not be deleted
                            t.EQ(TestClass::Counter, pre_counter);

                            delete csp;
                            if (t.EQ(TestClass::Counter, pre_counter))
                                delete test_p; // if not be deleted, delete it
                        }
                    );
                }
            );

            entity.StartSpec("constructor (exception handler)", [](TE& entity) -> void
                {
                    entity.RunExceptionTest("single", "create from a pointer", [](TO& t) -> void
                        {
                            // create a sp from a null object
                            sp = new dty::SmartPointer<TestClass>(::null);
                        }
                    );

                    entity.StartSpec("p & size", [](TE& entity) -> void
                        {
                            entity.RunExceptionTest("p & size (null)", "create from a null pointer", [](TO& t) -> void
                                {
                                    // create a sp from a null object
                                    sp = new dty::SmartPointer<TestClass>(::null, (int64)1);
                                }
                            );

                            entity.RunExceptionTest("p & size (size = 0)", "create from a size equals 0", [](TO& t) -> void
                                {
                                    // create a sp from a null object
                                    sp = new dty::SmartPointer<TestClass>((TestClass*)1 /** only for test */, (int64)0);
                                }
                            );

                            entity.RunExceptionTest("p & size (size = 0)", "create from a size less than 0", [](TO& t) -> void
                                {
                                    // create a sp from a null object
                                    sp = new dty::SmartPointer<TestClass>((TestClass*)1 /** only for test */, (int64)-1);
                                }
                            );
                        }
                    );
                }
            );
        }
    );

    entity.StartSpec("GetWeak", [](TE& entity) -> void
        {
            entity.RunTest("GetWeak (Strong)", "Before Test", [](TO& t) -> void
                {
                    TestClass* test_p = new TestClass();
                    if (!t.IsNotNull(test_p))
                        return;

                    sp = new dty::SmartPointer<TestClass>(test_p);
                    t.IsNotNull(sp);
                    if (!t.IsNotNull(sp))
                    {
                        delete test_p;
                        return;
                    }
                }
            );

            entity.RunTest("GetWeak (Strong)", "get a weak object from sp", [](TO& t) -> void
                {
                    int32 pre_counter = TestClass::Counter;
                    dty::SmartPointer<TestClass> wsp = sp->GetWeak();

                    t.EQ(TestClass::Counter, pre_counter);
                }
            );

            if (!sp->IsNull())
                delete sp;

            // ########################################################################################################################
            entity.StartSpec("GetWeak (from Weak)", [](TE& entity) -> void
                {
                    TestClass* test_p = new TestClass();
                    sp = new dty::SmartPointer<TestClass>(test_p, true);

                    entity.RunTest("GetWeak (from Weak)", "Before Test", [](TO& t) -> void
                        {
                            t.IsNotNull(sp);
                        }
                    );

                    entity.RunTest("GetWeak (from Weak)", "get a weak object from sp", [](TO& t) -> void
                        {
                            int32 pre_counter = TestClass::Counter;
                            dty::SmartPointer<TestClass> wsp = sp->GetWeak();

                            t.EQ(TestClass::Counter, pre_counter);
                        }
                    );

                    if (!sp->IsNull())
                        delete sp;
                },
                false,
                    true
                    );
        }
    );

    entity.StartSpec("Move", [](TE& entity) -> void
        {
            entity.RunTest("Move", "move from weak pointer should return false", [](TO& t) -> void
                {
                    // create a weak pointer
                    TestClass* test_p = new TestClass();
                    dty::SmartPointer<TestClass> p1(test_p, true);
                    dty::SmartPointer<TestClass> p2;

                    t.ToBeFalse(p1.IsNull());

                    if (t.ToBeFalse(p2.Move(p1)))
                        delete test_p;
                }
            );

            entity.RunTest("Move", "move equals pointer should return false", [](TO& t) -> void
                {
                    // create a weak pointer
                    TestClass* test_p = new TestClass();
                    dty::SmartPointer<TestClass> p1(test_p);
                    dty::SmartPointer<TestClass> p2(test_p, true);

                    t.ToBeFalse(p1.IsNull());

                    t.ToBeFalse(p1.Move(p2));
                }
            );

            entity.RunTest("Move", "move pointer succcess should return true", [](TO& t) -> void
                {
                    // create a weak pointer
                    TestClass* test_p1 = new TestClass();
                    TestClass* test_p2 = new TestClass();
                    dty::SmartPointer<TestClass> p1(test_p1);
                    dty::SmartPointer<TestClass> p2(test_p2);

                    t.ToBeFalse(p1.IsNull());
                    t.ToBeFalse(p2.IsNull());

                    int32 pre_counter = TestClass::Counter;
                    t.ToBeTrue(p1.Move(p2));

                    t.EQ(TestClass::Counter, pre_counter - 1);
                }
            );
        }
    );

    entity.StartSpec("operator", [](TE& entity) -> void
        {
            entity.StartSpec("operator &", [](TE& entity) -> void
                {
                    entity.RunTest("operator &", "null object should return 0", [](TO& t) -> void
                        {
                            dty::SmartPointer<int32> p;

                            t.EQ(0ULL, &p);
                        }
                    );
                    entity.RunTest("operator &", "not null object should return address", [](TO& t) -> void
                        {
                            int32* ip = new int32(0);
                            dty::SmartPointer<int32> p(ip);

                            t.EQ((uint64)ip, &p);
                        }
                    );
                }
            );

            entity.StartSpec("operator *", [](TE& entity) -> void
                {
                    entity.RunTest("operator *", "return real value", [](TO& t) -> void
                        {
                            int32* ip = new int32(1);
                            dty::SmartPointer<int32> p(ip);

                            *ip = 10;
                            t.EQ(*p, 10);
                        }
                    );

                    entity.RunTest("operator *", "should return a reference, should be set value", [](TO& t) -> void
                        {
                            int32* ip = new int32(1);
                            dty::SmartPointer<int32> p(ip);

                            *p = 10;
                            t.EQ(*ip, 10);
                        }
                    );

                    entity.RunExceptionTest("operator *", "throw an exception if try to require from null object", [](TO& t) -> void
                        {
                            dty::SmartPointer<int32> p;

                            *p;
                        }
                    );
                }
            );

            entity.StartSpec("operator ->", [](TE& entity) -> void
                {
                    entity.RunTest("operator ->", "should access successful", [](TO& t) -> void
                        {
                            dty::SmartPointer<TestClass> p(new TestClass());

                            int32 counter = TestClass::Counter;
                            t.EQ(p->GetValue(), counter);
                        }
                    );
                    entity.RunExceptionTest("operator ->", "throw an exception if try to require from null object", [](TO& t) -> void
                        {
                            dty::SmartPointer<TestClass> p;

                            p->GetValue();
                        }
                    );
                }
            );

            entity.StartSpec("operator []", [](TE& entity) -> void
                {
                    entity.RunExceptionTest("operator []", "throw an exception if try to require from null object", [](TO& t) -> void
                        {
                            dty::SmartPointer<int32> p;

                            p[0];
                        }
                    );

                    entity.RunExceptionTest("operator []", "throw an exception if index less than 0", [](TO& t) -> void
                        {
                            dty::SmartPointer<int32> p(new int32[2], 2LL);

                            p[-1];
                        }
                    );

                    entity.RunExceptionTest("operator []", "throw an exception if index out of range", [](TO& t) -> void
                        {
                            dty::SmartPointer<int32> p(new int32[2], 2LL);

                            p[2];
                        }
                    );

                    entity.RunTest("operator []", "return the value", [](TO& t) -> void
                        {
                            dty::SmartPointer<int32> p(new int32[2]{ 1,2 }, 2LL);

                            t.EQ(p[0], 1);
                            t.EQ(p[1], 2);
                        }
                    );

                    entity.RunTest("operator []", "value can be set through reference", [](TO& t) -> void
                        {
                            int32* ip = new int32[2]{ 1,2 };
                            dty::SmartPointer<int32> p(ip, 2LL);

                            t.EQ(p[0], 1);
                            t.EQ(p[1], 2);

                            p[0] = 10;
                            p[1] = 20;

                            t.EQ(p[0], 10);
                            t.EQ(p[1], 20);
                        }
                    );
                }
            );

            entity.StartSpec("operator ==", [](TE& entity) -> void
                {
                    entity.StartSpec("valueable", [](TE& entity) -> void
                        {
                            entity.RunTest("valueable", "should return true if equals", [](TO& t) -> void
                                {
                                    dty::SmartPointer<int32> p(new int32(0));

                                    t.ToBeTrue(p == 0);
                                }
                            );

                            entity.RunTest("valueable", "should return false if address is not equal", [](TO& t) -> void
                                {
                                    dty::SmartPointer<EQTestClass> p(new EQTestClass());
                                    EQTestClass tc;

                                    t.ToBeFalse(p == tc);
                                }
                            );
                        }
                    );

                    entity.StartSpec("reference", [](TE& entity) -> void
                        {
                            entity.RunTest("reference", "should return true if address is equal", [](TO& t) -> void
                                {
                                    EQTestClass* tp = new EQTestClass();
                                    dty::SmartPointer<EQTestClass> p(tp, true);
                                    dty::SmartPointer<EQTestClass> wp(tp, true);

                                    t.ToBeTrue(p == wp);

                                    delete tp;
                                }
                            );

                            entity.RunTest("reference", "should return false if address is not equal", [](TO& t) -> void
                                {
                                    dty::SmartPointer<EQTestClass> p1(new EQTestClass());
                                    dty::SmartPointer<EQTestClass> p2(new EQTestClass());

                                    t.ToBeFalse(p1 == p2);
                                }
                            );
                        }
                    );
                }
            );

            entity.StartSpec("operator !=", [](TE& entity) -> void
                {
                    entity.StartSpec("valueable", [](TE& entity) -> void
                        {
                            entity.RunTest("valueable", "should return true if not equals", [](TO& t) -> void
                                {
                                    dty::SmartPointer<int32> p(new int32(0));

                                    t.ToBeTrue(p != 1);
                                }
                            );

                            entity.RunTest("valueable", "should return true if address is not equal", [](TO& t) -> void
                                {
                                    dty::SmartPointer<EQTestClass> p1(new EQTestClass());
                                    dty::SmartPointer<EQTestClass> p2(new EQTestClass());

                                    t.ToBeTrue(p1 != p2);
                                }
                            );

                            entity.RunTest("valueable", "should return false if address is equal", [](TO& t) -> void
                                {
                                    EQTestClass tc;
                                    dty::SmartPointer<EQTestClass> p1(&tc, true);
                                    dty::SmartPointer<EQTestClass> p2(&tc, true);

                                    t.ToBeFalse(p1 != p2);
                                }
                            );
                        }
                    );

                    entity.StartSpec("reference", [](TE& entity) -> void
                        {
                            entity.RunTest("reference", "should return true if address is not equal", [](TO& t) -> void
                                {
                                    dty::SmartPointer<EQTestClass> p1(new EQTestClass());
                                    dty::SmartPointer<EQTestClass> p2(new EQTestClass());

                                    t.ToBeTrue(p1 != p2);
                                }
                            );

                            entity.RunTest("reference", "should return false if address is equal", [](TO& t) -> void
                                {
                                    EQTestClass* tp = new EQTestClass();
                                    dty::SmartPointer<EQTestClass> p1(tp, true);
                                    dty::SmartPointer<EQTestClass> p2(tp, true);

                                    t.ToBeFalse(p1 != p2);

                                    delete tp;
                                }
                            );
                        }
                    );
                }
            );
        }
    );
}