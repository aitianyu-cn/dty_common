#include "../../testframe.hxx"
#include "../../../native/prime/core/property.hpp"

_enum TestEnum
{
    AAA,
    BBB,
    CCC
};

dty::Property<int32>* pProp_1 = ::null;
dty::Property<TestEnum>* pProp_2 = ::null;

dty::LProperty<int32>* pLProp_1 = ::null;
dty::LProperty<TestEnum>* pLProp_2 = ::null;

int32 LProp_1_Value;
TestEnum LProp_2_Value;

RUNTEST(PropTest, (const ::string)"dty.Property Unit Test")
{
    PropTest.StartSpec((const ::string)"Property Spec", [](dty::test::TestEntity& entity) -> void
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

            entity.StartSpec((const ::string)"enum type", [](dty::test::TestEntity& entity) -> void
                {
                    entity.RunTest((const ::string)"constructor", (const ::string)"test for property class constructor", [](dty::test::TestObject& tobj) -> void
                        {
                            TestEnum value = TestEnum::AAA;
                            pProp_2 = new dty::Property<TestEnum>(value);

                            tobj.IsNotNull(pProp_2);
                            tobj.EQ(pProp_2->Get(), value);
                        }
                    );
                    entity.RunTest((const ::string)"setter", (const ::string)"test for property getter method", [](dty::test::TestObject& tobj) -> void
                        {
                            pProp_2->Set(TestEnum::BBB);

                            tobj.EQ(pProp_2->Get(), TestEnum::BBB);
                        }
                    );
                    entity.RunTest((const ::string)"operator type", (const ::string)"test for property operator type conversion", [](dty::test::TestObject& tobj) -> void
                        {
                            TestEnum value = __PTR_TO_REF__ pProp_2;
                            tobj.EQ(value, TestEnum::BBB);
                        }
                    );
                    entity.RunTest((const ::string)"operator equal", (const ::string)"test for property operator equal", [](dty::test::TestObject& tobj) -> void
                        {
                            __PTR_TO_REF__ pProp_2 = TestEnum::CCC;
                            tobj.EQ(pProp_2->Get(), TestEnum::CCC);
                        }
                    );
                    entity.RunTest((const ::string)"operator equal", (const ::string)"test for property operator equal", [](dty::test::TestObject& tobj) -> void
                        {
                            dty::Property<TestEnum> p2(TestEnum::AAA);
                            __PTR_TO_REF__ pProp_2 = p2;
                            tobj.EQ(pProp_2->Get(), TestEnum::AAA);
                        }
                    );

                    delete pProp_2;
                }, true);
        });
    PropTest.StartSpec((const ::string)"Lambda Property Spec", [](dty::test::TestEntity& entity) -> void
        {
            entity.StartSpec((const ::string)"integer 32bit", [](dty::test::TestEntity& entity) -> void
                {
                    entity.RunTest((const ::string)"constructor", (const ::string)"test for lambda property class constructor", [](dty::test::TestObject& tobj) -> void
                        {
                            pLProp_1 = new dty::LProperty<int32>(
                                []()->int32 { return LProp_1_Value; },
                                [](int32 value)->void { LProp_1_Value = value; }
                            );

                            tobj.IsNotNull(pLProp_1);
                        }
                    );
                    entity.RunTest((const ::string)"setter and Getter", (const ::string)"test for lambda property getter and setter method", [](dty::test::TestObject& tobj) -> void
                        {
                            pLProp_1->Set(100);

                            tobj.EQ(LProp_1_Value, 100);
                            tobj.EQ(pLProp_1->Get(), 100);
                        }
                    );
                    entity.RunTest((const ::string)"operator type", (const ::string)"test for property operator type conversion", [](dty::test::TestObject& tobj) -> void
                        {
                            int32 value = __PTR_TO_REF__ pLProp_1;
                            tobj.EQ(value, 100);
                        }
                    );
                    entity.RunTest((const ::string)"operator equal", (const ::string)"test for property operator equal", [](dty::test::TestObject& tobj) -> void
                        {
                            __PTR_TO_REF__ pLProp_1 = 200;

                            tobj.EQ(LProp_1_Value, 200);
                            tobj.EQ(pLProp_1->Get(), 200);
                        }
                    );
                    entity.RunTest((const ::string)"operator equal", (const ::string)"test for property operator equal", [](dty::test::TestObject& tobj) -> void
                        {
                            dty::Property<int32> p2(1000);

                            __PTR_TO_REF__ pLProp_1 = p2;

                            tobj.EQ(LProp_1_Value, 1000);
                            tobj.EQ(pLProp_1->Get(), 1000);
                        }
                    );

                    delete pLProp_1;
                }, true);

            entity.StartSpec((const ::string)"enum type", [](dty::test::TestEntity& entity) -> void
                {
                    entity.RunTest((const ::string)"constructor", (const ::string)"test for lambda property class constructor", [](dty::test::TestObject& tobj) -> void
                        {
                            pLProp_2 = new dty::LProperty<TestEnum>(
                                []()->TestEnum { return LProp_2_Value; },
                                [](TestEnum value)->void { LProp_2_Value = value; }
                            );

                            tobj.IsNotNull(pLProp_2);
                        }
                    );
                    entity.RunTest((const ::string)"setter and Getter", (const ::string)"test for lambda property getter and setter method", [](dty::test::TestObject& tobj) -> void
                        {
                            pLProp_2->Set(TestEnum::AAA);

                            tobj.EQ(LProp_2_Value, TestEnum::AAA);
                            tobj.EQ(pLProp_2->Get(), TestEnum::AAA);
                        }
                    );
                    entity.RunTest((const ::string)"operator type", (const ::string)"test for property operator type conversion", [](dty::test::TestObject& tobj) -> void
                        {
                            TestEnum value = __PTR_TO_REF__ pLProp_2;
                            tobj.EQ(value, TestEnum::AAA);
                        }
                    );
                    entity.RunTest((const ::string)"operator equal", (const ::string)"test for property operator equal", [](dty::test::TestObject& tobj) -> void
                        {
                            __PTR_TO_REF__ pLProp_2 = TestEnum::BBB;

                            tobj.EQ(LProp_2_Value, TestEnum::BBB);
                            tobj.EQ(pLProp_2->Get(), TestEnum::BBB);
                        }
                    );
                    entity.RunTest((const ::string)"operator equal", (const ::string)"test for property operator equal", [](dty::test::TestObject& tobj) -> void
                        {
                            dty::Property<TestEnum> p2(TestEnum::CCC);

                            __PTR_TO_REF__ pLProp_2 = p2;

                            tobj.EQ(LProp_2_Value, TestEnum::CCC);
                            tobj.EQ(pLProp_2->Get(), TestEnum::CCC);
                        }
                    );

                    delete pLProp_2;
                }, true);
        });
}