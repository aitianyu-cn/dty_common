#include "../../testframe.hxx"
#include "../../../native/prime/core/property.hpp"

extern void PropertyTest(dty::test::TestEntity& entity);
// extern void LambdaPropertyTest(dty::test::TestEntity& entity);

dty::Property<int32>* pProp_1 = ::null;

RUNTEST(PropTest, (const ::string)"dty.Property Unit Test")
{
    PropTest.StartSpec((const ::string)"Property Spec", [](dty::test::TestEntity& entity) -> void
        {
            entity.StartSpec((const ::string)"Value Type", [](dty::test::TestEntity& entity) -> void
                {
                    entity.StartSpec((const ::string)"integer 32bit", [](dty::test::TestEntity& entity) -> void
                        {
                            entity.RunTest((const ::string)"constructor", (const ::string)"test for property class constructor", [](dty::test::TestObject& tobj) -> void
                                {
                                    int32 value = 1;
                                    pProp_1 = new dty::Property<int32>(value);

                                    tobj.IsNotNull(pProp_1);
                                    tobj.EQ(pProp_1->Get(), value);
                                }
                            );
                            entity.RunTest((const ::string)"setter", (const ::string)"test for property getter method", [](dty::test::TestObject& tobj) -> void
                                {
                                    pProp_1->Set(100);

                                    tobj.EQ(pProp_1->Get(), 100);
                                }
                            );
                            entity.RunTest((const ::string)"operator type", (const ::string)"test for property operator type conversion", [](dty::test::TestObject& tobj) -> void
                                {
                                    int32 value = __PTR_TO_REF__ pProp_1;
                                    tobj.EQ(value, 100);
                                }
                            );
                            entity.RunTest((const ::string)"operator equal", (const ::string)"test for property operator equal", [](dty::test::TestObject& tobj) -> void
                                {
                                    __PTR_TO_REF__ pProp_1 = 200;
                                    tobj.EQ(pProp_1->Get(), 200);
                                }
                            );
                            entity.RunTest((const ::string)"operator equal", (const ::string)"test for property operator equal", [](dty::test::TestObject& tobj) -> void
                                {
                                    dty::Property p2(1000);
                                    __PTR_TO_REF__ pProp_1 = p2;
                                    tobj.EQ(pProp_1->Get(), 1000);
                                }
                            );

                            delete pProp_1;
                        }, true);
                    // entity.StartSpec("float", PropertyValTypeSpec<float>);
                    // entity.StartSpec("integer", PropertyValTypeSpec<bool>);
                });
        });
    // PropTest.StartSpec("Lambda Property Spec", LambdaPropertyTest);
}