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

                                });

                            entity.RunTest("constructor", "need free", [](dty::test::TestObject& obj) -> void
                                {

                                });
                        });

                    entity.RunFlow("constructor & copy & destroy", [](dty::test::TestFlow& flow) -> void
                        {
                            flow.Item("create object", [&](dty::test::TestObject& obj) -> void
                                {

                                });

                            flow.Item("copy object", [&](dty::test::TestObject& obj) -> void
                                {

                                });

                            flow.Item("destroy one object", [&](dty::test::TestObject& obj) -> void
                                {

                                });

                            flow.Item("destroy all", [&](dty::test::TestObject& obj) -> void
                                {

                                });
                        });
                });
        });

    entity.StartSpec("Dynamic Array", [](dty::test::TestEntity& entity) -> void
        {

        });
}