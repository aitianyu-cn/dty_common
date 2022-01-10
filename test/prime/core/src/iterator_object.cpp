#include "../../../testframe.hxx"
#include "../../../../native/prime/core/iterator.hpp"

class TestClass_ItObject
{
public:
    TestClass_ItObject()
    {
        ++TestClass_ItObject::Counter;
    }
    ~TestClass_ItObject()
    {
        --TestClass_ItObject::Counter;
    }

public:
    object operator new[](size_t size)
    {
        ++TestClass_ItObject::NewCounter;
        return ::operator new [](size);
    }

public:
    void operator delete[](object obj)
    {
        --TestClass_ItObject::NewCounter;
        ::operator delete [](obj);
    }

public:
    static int32 Counter;

    static int32 NewCounter;
};

int32 TestClass_ItObject::Counter = 0;
int32 TestClass_ItObject::NewCounter = 0;

using IE = dty::collection::IteratorEntity<int32>;
using IO = dty::collection::Iterator<int32>;

IE* IteratorEntityInstance = ::null;
IO* pIteratorObj = ::null;

void test_spec_iterator_object(dty::test::TestEntity& entity)
{
    entity.RunTest("Before All", "constructor", [](TO& t) -> void
        {
            int32* p = new int32[10]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            IteratorEntityInstance = new IE(p, 10, true);

            pIteratorObj = new IO(*IteratorEntityInstance);
        }
    );

    entity.RunTest("copy constructr", "create an iterator object from an iterator object", [](TO& t) -> void
        {
            IO cpobj(*pIteratorObj);
        }
    );

    entity.StartSpec("integration test", [](TE& entity) -> void
        {
            entity.SetAssert();

            // this is a integration test for iterator object
            // to test function flow: Next -> End -> Reset -> Next -> End
        }
    );

    entity.StartSpec("enum function test", [](TE& entity) -> void
        {
            entity.RunTest("ForEach", "", [](TO& t) -> void
                {

                }
            );

            entity.RunTest("Some", "", [](TO& t) -> void
                {

                }
            );

            entity.RunTest("Filter", "", [](TO& t) -> void
                {

                }
            );

            entity.RunTest("Never", "", [](TO& t) -> void
                {

                }
            );

            entity.RunTest("Find", "", [](TO& t) -> void
                {

                }
            );

            entity.RunTest("FindIndex", "", [](TO& t) -> void
                {

                }
            );
        }
    );

    entity.RunTest("After All", "destructor", [](TO& t) -> void
        {
            if (::null != pIteratorObj)
                delete pIteratorObj;

            if (::null != IteratorEntityInstance)
                delete IteratorEntityInstance;
        }
    );
}