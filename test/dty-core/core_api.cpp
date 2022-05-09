#include "../testframe.hxx"

TEST_MAIN("dty.common.native.test.dty-core.core_api")
{
    entity.StartSpec("strlen", [](dty::test::TestEntity& entity) -> void
        {
            entity.RunTest("null value", "length should be 0", [](dty::test::TestObject& tobj) -> void
                {
                    int32 len = dty::strlen(::null);
                    tobj.EQ(len, 0);
                });
            entity.RunTest("empty value", "length should be 0", [](dty::test::TestObject& tobj) -> void
                {
                    int32 len = dty::strlen("");
                    tobj.EQ(len, 0);
                });
            entity.RunTest("not empty value with '\\0' fills", "length should be 0", [](dty::test::TestObject& tobj) -> void
                {
                    int32 len = dty::strlen("\0\0\0\0");
                    tobj.EQ(len, 0);
                });
            entity.RunTest("'\\0' insert into str", "length should be less than actual", [](dty::test::TestObject& tobj) -> void
                {
                    int32 len = dty::strlen("abc\0def\0");
                    tobj.EQ(len, 3);
                });
            entity.RunTest("normal str", "length should be correct", [](dty::test::TestObject& tobj) -> void
                {
                    int32 len = dty::strlen("abcdef\0");
                    tobj.EQ(len, 6);
                });
        });
    entity.StartSpec("strcmp", [](dty::test::TestEntity& entity) -> void
        {
            entity.RunTest("null & null", "should equal", [](dty::test::TestObject& tobj) -> void
                {
                    int32 cmp = dty::strcmp(::null, ::null);
                    tobj.EQ(cmp, 0);
                });
            entity.RunTest("not null & null", "should greate", [](dty::test::TestObject& tobj) -> void
                {
                    int32 cmp = dty::strcmp("", ::null);
                    tobj.GT(cmp, 0);
                });
            entity.RunTest("null & not null", "should less", [](dty::test::TestObject& tobj) -> void
                {
                    int32 cmp = dty::strcmp(::null, "");
                    tobj.LT(cmp, 0);
                });
            entity.RunTest("empty string", "should equal", [](dty::test::TestObject& tobj) -> void
                {
                    int32 cmp = dty::strcmp("", "");
                    tobj.EQ(cmp, 0);
                });
            entity.RunTest("not empty string", "should equal", [](dty::test::TestObject& tobj) -> void
                {
                    int32 cmp = dty::strcmp("123", "123");
                    tobj.EQ(cmp, 0);
                });
            entity.RunTest("not empty string", "should greate", [](dty::test::TestObject& tobj) -> void
                {
                    int32 cmp = dty::strcmp("1234", "123");
                    tobj.GT(cmp, 0);
                });
            entity.RunTest("not empty string", "should less", [](dty::test::TestObject& tobj) -> void
                {
                    int32 cmp = dty::strcmp("123", "1234");
                    tobj.LT(cmp, 0);
                });
            entity.StartSpec("ignore case", [](dty::test::TestEntity& entity) -> void
                {
                    entity.RunTest("different case for English char", "should equal", [](dty::test::TestObject& tobj) -> void
                        {
                            int32 cmp = dty::strcmp("abC", "Abc", true);
                            tobj.EQ(cmp, 0);
                        });
                    entity.RunTest("different for not English char", "should not equal", [](dty::test::TestObject& tobj) -> void
                        {
                            int32 cmp = dty::strcmp("abC#", "Abc@", true);
                            tobj.NE(cmp, 0);
                        });
                });
        });
}