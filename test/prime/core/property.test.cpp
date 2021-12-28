#include "../../testframe.hxx"
#include "../../../native/prime/core/property.hpp"

void PropertyValTypeSpec(dty::test::TestEntity& entity);
// void PropertyRefTypeSpec(dty::test::TestEntity& entity);
// void PropertyPtrTypeSpec(dty::test::TestEntity& entity);

void PropertyTest(dty::test::TestEntity& entity)
{
    entity.StartSpec("Value Type", [](dty::test::TestEntity& entity) -> void
        {
            entity.StartSpec("integer", PropertyValTypeSpec);
            // entity.StartSpec("float", PropertyValTypeSpec<float>);
            // entity.StartSpec("integer", PropertyValTypeSpec<bool>);
        });
    // entity.StartSpec("Reference Type", [](dty::test::TestEntity& entity) -> void
    //     {
    //         entity.StartSpec("integer", PropertyRefTypeSpec);
    //         // entity.StartSpec("float", PropertyRefTypeSpec<float>);
    //         // entity.StartSpec("integer", PropertyRefTypeSpec<bool>);
    //     });
    // entity.StartSpec("Pointer Type", [](dty::test::TestEntity& entity) -> void
    //     {
    //         entity.StartSpec("integer", PropertyPtrTypeSpec);
    //         // entity.StartSpec("float", PropertyPtrTypeSpec<float>);
    //         // entity.StartSpec("integer", PropertyPtrTypeSpec<bool>);
    //     });
}

dty::Property<int32>* pProp = ::null;

void PropertyValTypeSpec(dty::test::TestEntity& entity)
{
    entity.RunTest("constructor", "test for property class constructor", [](dty::test::TestObject& tobj) -> void
        {
            int32 value = 1;
            pProp = new dty::Property<int32>(value);

            tobj.IsNotNull(pProp);
            tobj.EQ(pProp->Get(), value);
        }
    );
    entity.RunTest("setter", "test for property getter method", [](dty::test::TestObject& tobj) -> void
        {
            pProp->Set(100);

            tobj.EQ(pProp->Get(), 100);
        }
    );
    entity.RunTest("operator type", "test for property operator type conversion", [](dty::test::TestObject& tobj) -> void
        {
            int32 value = __PTR_TO_REF__ pProp;
            tobj.EQ(value, 100);
        }
    );
    entity.RunTest("operator equal", "test for property operator equal", [](dty::test::TestObject& tobj) -> void
        {
            __PTR_TO_REF__ pProp = 200;
            tobj.EQ(pProp->Get(), 200);
        }
    );
    entity.RunTest("operator equal", "test for property operator equal", [](dty::test::TestObject& tobj) -> void
        {
            dty::Property p2(1000);
            __PTR_TO_REF__ pProp = p2;
            tobj.EQ(pProp->Get(), 1000);
        }
    );
}