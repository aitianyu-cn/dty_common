#include "../testframe.hxx"
#include "../../native/prime/array.hpp"

class TestClass_StaticArray
{
public:
    TestClass_StaticArray()
    {
        ++TestClass_StaticArray::Counter;
    }
    ~TestClass_StaticArray()
    {
        --TestClass_StaticArray::Counter;
    }

public:
    object operator new[](size_t size)
    {
        ++TestClass_StaticArray::NewCounter;
        return ::operator new [](size);
    }

public:
    void operator delete[](object obj)
    {
        --TestClass_StaticArray::NewCounter;
        ::operator delete [](obj);
    }

public:
    static int32 Counter;

    static int32 NewCounter;
};

int32 TestClass_StaticArray::Counter = 0;
int32 TestClass_StaticArray::NewCounter = 0;

using StaticArray = dty::collection::Array<TestClass_StaticArray>;

TEST_MAIN("dty.common.native.test.prime.array")
{
    entity.StartSpec("Static Array", [](dty::test::TestEntity& entity) -> void
        {
            entity.StartSpec("constructor", [](dty::test::TestEntity& entity) -> void
                {
                    entity.RunExceptionTest<dty::except::ArgumentNullException>("constructor", "null array src should throw an error", [](dty::test::TestObject& obj) -> void
                        {
                            StaticArray sa(::null, 1);
                        });

                    entity.RunExceptionTest<dty::except::ArgumentOutOfRangeException>("constructor", "array length less than 0 should throw an error", [](dty::test::TestObject& obj) -> void
                        {
                            StaticArray sa((TestClass_StaticArray*)1, -1);
                        });

                    entity.StartSpec("normal", [](dty::test::TestEntity& entity) -> void
                        {
                            entity.RunTest("constructor", "null array", [](dty::test::TestObject& obj) -> void
                                {
                                    StaticArray sa(::null, 0);

                                    obj.ToBeTrue(sa.IsNull());
                                });

                            entity.RunTest("constructor", "not need free", [](dty::test::TestObject& obj) -> void
                                {
                                    TestClass_StaticArray* src = new TestClass_StaticArray[1];
                                    obj.EQ(1, TestClass_StaticArray::NewCounter);

                                    StaticArray* sap = new StaticArray(src, 1, false);
                                    obj.ToBeFalse(sap->IsNull());
                                    obj.EQ(1, (int32)(sap->Count));

                                    delete sap;
                                    obj.EQ(1, TestClass_StaticArray::NewCounter);

                                    delete [] src;
                                    obj.EQ(0, TestClass_StaticArray::NewCounter);
                                });

                            entity.RunTest("constructor", "need free", [](dty::test::TestObject& obj) -> void
                                {
                                    TestClass_StaticArray* src = new TestClass_StaticArray[1];
                                    obj.EQ(1, TestClass_StaticArray::NewCounter);

                                    StaticArray* sap = new StaticArray(src, 1);
                                    obj.ToBeFalse(sap->IsNull());
                                    obj.EQ(1, (int32)(sap->Count));

                                    delete sap;
                                    if (!obj.EQ(0, TestClass_StaticArray::NewCounter))
                                        delete [] src;
                                });
                        });

                    entity.RunFlow("constructor & copy & destroy", [](dty::test::TestFlow& flow) -> void
                        {
                            StaticArray* arr1 = ::null;
                            StaticArray* arr2 = ::null;

                            TestClass_StaticArray* src = ::null;

                            flow.Item("init", [&](dty::test::TestObject& obj) -> void
                                {
                                    src = new TestClass_StaticArray[3];

                                    obj.IsNotNull(src);
                                    obj.EQ(1, TestClass_StaticArray::NewCounter);
                                });

                            flow.Item("create object", [&](dty::test::TestObject& obj) -> void
                                {
                                    arr1 = new StaticArray(src, 3);
                                    obj.ToBeFalse(arr1->IsNull());
                                    obj.EQ(3, (int32)(arr1->Count));
                                });

                            flow.Item("copy object", [&](dty::test::TestObject& obj) -> void
                                {
                                    arr2 = new StaticArray(__PTR_TO_REF__ arr1);
                                    obj.ToBeFalse(arr2->IsNull());
                                    obj.EQ(3, (int32)(arr2->Count));
                                });

                            flow.Item("destroy one object", [&](dty::test::TestObject& obj) -> void
                                {
                                    delete arr1;
                                    arr1 = ::null;

                                    obj.ToBeFalse(arr2->IsNull());
                                    obj.EQ(3, (int32)(arr2->Count));
                                    obj.EQ(1, TestClass_StaticArray::NewCounter);
                                });

                            flow.Item("destroy all", [&](dty::test::TestObject& obj) -> void
                                {
                                    delete arr2;
                                    arr2 = ::null;

                                    if (!obj.EQ(0, TestClass_StaticArray::NewCounter))
                                        delete [] src;
                                });

                            if (::null != arr1)
                                delete arr1;
                            if (::null != arr2)
                                delete arr2;
                            if (0 != TestClass_StaticArray::NewCounter)
                                delete [] src;
                        });
                });

            entity.RunTest("operator []", "", [](dty::test::TestObject& obj) -> void
                {
                    int32* src = new int32[10];
                    for (int32 i = 0; i < 10; ++i)
                        src[i] = i + 1;
                    dty::collection::Array<int32> arr(src, 10);

                    obj.EQ((int32)arr.Count, 10);

                    for (int32 i = 0; i < (int32)arr.Count; ++i)
                        obj.EQ(i + 1, arr[i]);
                });

            entity.RunTest("GetIterator", "", [](dty::test::TestObject& obj) -> void
                {
                    int32* src = new int32[10];
                    for (int32 i = 0; i < 10; ++i)
                        src[i] = i + 1;
                    dty::collection::Array<int32> arr(src, 10);

                    dty::collection::Iterator<int32> it = arr.GetIterator();

                    it.Reset();
                    int32 i = 1;
                    for (dty::int_ptr isp(it.Current()); isp != it.End(); isp.Copy(it.Next()), ++i)
                        obj.EQ(i, *isp);

                    obj.EQ(i, *it.End());
                });
        });

    entity.StartSpec("Dynamic Array", [](dty::test::TestEntity& entity) -> void
        {

        });
}