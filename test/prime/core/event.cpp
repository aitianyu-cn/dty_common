#include "../../frame.hxx"

void TestItem1(dty::test::TestObject& tobj);

TestsEntry_Main()
{
    TestEntityCreator(TEntity, "test");

    TEntity.RunTest("test item 1", "this is a demo test", TestItem1, dty::test::TestType::Expect);

    Test_Main_Return(TEntity);
}