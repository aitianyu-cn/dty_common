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

TEST_MAIN("dty.Property Unit Test")
{
    TEST_SPEC("Property Spec",
        {
            TEST_SPEC("integer 32bit",
                {
                    TEST_ITEM("constructor", "test for property class constructor",
                        {
                            int32 value = 1;
                            pProp_1 = new dty::Property<int32>(value);

                            tobj.IsNotNull(pProp_1);
                            tobj.EQ(pProp_1->Get(), value);
                        }
                    );
                    TEST_ITEM("setter", "test for property getter method",
                        {
                            pProp_1->Set(100);

                            tobj.EQ(pProp_1->Get(), 100);
                        }
                    );
                    TEST_ITEM("operator type", "test for property operator type conversion",
                        {
                            int32 value = __PTR_TO_REF__ pProp_1;
                            tobj.EQ(value, 100);
                        }
                    );
                    TEST_ITEM("operator equal", "test for property operator equal",
                        {
                            __PTR_TO_REF__ pProp_1 = 200;
                            tobj.EQ(pProp_1->Get(), 200);
                        }
                    );
                    TEST_ITEM("operator equal", "test for property operator equal",
                        {
                            dty::Property p2(1000);
                            __PTR_TO_REF__ pProp_1 = p2;
                            tobj.EQ(pProp_1->Get(), 1000);
                        }
                    );

                    delete pProp_1;
                }, true);

            TEST_SPEC("enum type",
                {
                    TEST_ITEM("constructor", "test for property class constructor",
                        {
                            TestEnum value = TestEnum::AAA;
                            pProp_2 = new dty::Property<TestEnum>(value);

                            tobj.IsNotNull(pProp_2);
                            tobj.EQ(pProp_2->Get(), value);
                        }
                    );
                    TEST_ITEM("setter", "test for property getter method",
                        {
                            pProp_2->Set(TestEnum::BBB);

                            tobj.EQ(pProp_2->Get(), TestEnum::BBB);
                        }
                    );
                    TEST_ITEM("operator type", "test for property operator type conversion",
                        {
                            TestEnum value = __PTR_TO_REF__ pProp_2;
                            tobj.EQ(value, TestEnum::BBB);
                        }
                    );
                    TEST_ITEM("operator equal", "test for property operator equal",
                        {
                            __PTR_TO_REF__ pProp_2 = TestEnum::CCC;
                            tobj.EQ(pProp_2->Get(), TestEnum::CCC);
                        }
                    );
                    TEST_ITEM("operator equal", "test for property operator equal",
                        {
                            dty::Property<TestEnum> p2(TestEnum::AAA);
                            __PTR_TO_REF__ pProp_2 = p2;
                            tobj.EQ(pProp_2->Get(), TestEnum::AAA);
                        }
                    );

                    delete pProp_2;
                }, true);
        });
    TEST_SPEC("Lambda Property Spec",
        {
            TEST_SPEC("integer 32bit",
                {
                    TEST_ITEM("constructor", "test for lambda property class constructor",
                        {
                            pLProp_1 = new dty::LProperty<int32>(
                                []()->int32 { return LProp_1_Value; },
                                [](int32 value)->void { LProp_1_Value = value; }
                            );

                            tobj.IsNotNull(pLProp_1);
                        }
                    );
                    TEST_ITEM("setter and Getter", "test for lambda property getter and setter method",
                        {
                            pLProp_1->Set(100);

                            tobj.EQ(LProp_1_Value, 100);
                            tobj.EQ(pLProp_1->Get(), 100);
                        }
                    );
                    TEST_ITEM("operator type", "test for property operator type conversion",
                        {
                            int32 value = __PTR_TO_REF__ pLProp_1;
                            tobj.EQ(value, 100);
                        }
                    );
                    TEST_ITEM("operator equal", "test for property operator equal",
                        {
                            __PTR_TO_REF__ pLProp_1 = 200;

                            tobj.EQ(LProp_1_Value, 200);
                            tobj.EQ(pLProp_1->Get(), 200);
                        }
                    );
                    TEST_ITEM("operator equal", "test for property operator equal",
                        {
                            dty::Property<int32> p2(1000);

                            __PTR_TO_REF__ pLProp_1 = p2;

                            tobj.EQ(LProp_1_Value, 1000);
                            tobj.EQ(pLProp_1->Get(), 1000);
                        }
                    );

                    delete pLProp_1;
                }, true);

            TEST_SPEC("enum type",
                {
                    TEST_ITEM("constructor", "test for lambda property class constructor",
                        {
                            pLProp_2 = new dty::LProperty<TestEnum>(
                                []()->TestEnum { return LProp_2_Value; },
                                [](TestEnum value)->void { LProp_2_Value = value; }
                            );

                            tobj.IsNotNull(pLProp_2);
                        }
                    );
                    TEST_ITEM("setter and Getter", "test for lambda property getter and setter method",
                        {
                            pLProp_2->Set(TestEnum::AAA);

                            tobj.EQ(LProp_2_Value, TestEnum::AAA);
                            tobj.EQ(pLProp_2->Get(), TestEnum::AAA);
                        }
                    );
                    TEST_ITEM("operator type", "test for property operator type conversion",
                        {
                            TestEnum value = __PTR_TO_REF__ pLProp_2;
                            tobj.EQ(value, TestEnum::AAA);
                        }
                    );
                    TEST_ITEM("operator equal", "test for property operator equal",
                        {
                            __PTR_TO_REF__ pLProp_2 = TestEnum::BBB;

                            tobj.EQ(LProp_2_Value, TestEnum::BBB);
                            tobj.EQ(pLProp_2->Get(), TestEnum::BBB);
                        }
                    );
                    TEST_ITEM("operator equal", "test for property operator equal",
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