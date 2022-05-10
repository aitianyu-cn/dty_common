#include "../../../testframe.hxx"
#include "../../../../native/prime/core/basetype.hpp"



void test_spec_basetype_boolean(dty::test::TestEntity& entity)
{
    entity.StartSpec("constructor", [](dty::test::TestEntity& entity) -> void
        {
            entity.RunTest("no init parameter", "false as default", [](dty::test::TestObject& tobj) -> void
                {
                    dty::Boolean boolean;

                    tobj.ToBeFalse(boolean);
                });
            entity.RunTest("init with value", "equals to value", [](dty::test::TestObject& tobj) -> void
                {
                    dty::Boolean boolean(true);

                    tobj.ToBeTrue(boolean);
                });
            entity.RunTest("init by other obj", "equals to obj", [](dty::test::TestObject& tobj) -> void
                {
                    dty::Boolean boolean(true);

                    dty::Boolean copy_boolean(boolean);

                    tobj.ToBeTrue(boolean);
                    tobj.ToBeTrue(copy_boolean);
                });
        });

    dty::Boolean boolean;

    entity.StartSpec("Equals", [&](dty::test::TestEntity& entity) -> void
        {
            entity.RunTest("not boolean type", "should false", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::except::Exception other;

                    tobj.ToBeFalse(boolean.Equals(other));
                });
            entity.RunTest("boolean type with true value", "should false", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Boolean other(true);

                    tobj.ToBeFalse(boolean.Equals((dty::TianyuObject __REFERENCE__)other));
                });
            entity.RunTest("boolean type with false value", "should true", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Boolean other(false);

                    tobj.ToBeTrue(boolean.Equals((dty::TianyuObject __REFERENCE__)other));
                });
        });

    entity.StartSpec("operator", [&](dty::test::TestEntity& entity) -> void
        {
            entity.StartSpec("operator ==", [&](dty::test::TestEntity& entity) -> void
                {
                    entity.RunTest("boolean type with false value", "should true", [&](dty::test::TestObject& tobj) -> void
                        {
                            dty::Boolean other(false);

                            tobj.ToBeTrue(boolean == other);
                        });
                    entity.RunTest("boolean type with true value", "should false", [&](dty::test::TestObject& tobj) -> void
                        {
                            dty::Boolean other(true);

                            tobj.ToBeFalse(boolean == other);
                        });

                    entity.RunTest("TianyuObject type", "can be convert to boolean type, should true", [&](dty::test::TestObject& tobj) -> void
                        {
                            dty::Boolean other(false);

                            tobj.ToBeTrue(boolean == (dty::TianyuObject __REFERENCE__)other);
                        });
                    entity.RunTest("TianyuObject type", "cannot be convert to boolean type, should false", [&](dty::test::TestObject& tobj) -> void
                        {
                            dty::except::Exception other;

                            tobj.ToBeFalse(boolean == other);
                        });
                });

            entity.RunTest("operator bool", "get the true state", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Boolean other(true);

                    tobj.ToBeTrue(other);
                });

            entity.StartSpec("operator int32", [&](dty::test::TestEntity& entity) -> void
                {
                    entity.RunTest("true value", "should get 1", [&](dty::test::TestObject& tobj) -> void
                        {
                            dty::Boolean other(true);

                            tobj.EQ((int32)other, 1);
                        });
                    entity.RunTest("false value", "should get 0", [&](dty::test::TestObject& tobj) -> void
                        {
                            dty::Boolean other(false);

                            tobj.EQ((int32)other, 0);
                        });
                });

            entity.RunTest("operator !", "get the ture state", [&](dty::test::TestObject& tobj) -> void
                {
                    tobj.ToBeFalse(boolean);
                    tobj.ToBeTrue(!boolean);
                });

            entity.StartSpec("operator !=", [&](dty::test::TestEntity& entity) -> void
                {
                    entity.RunTest("false and true", "should true", [&](dty::test::TestObject& tobj) -> void
                        {
                            dty::Boolean other(true);

                            tobj.ToBeTrue(boolean != other);
                        });
                    entity.RunTest("false and false", "should false", [&](dty::test::TestObject& tobj) -> void
                        {
                            dty::Boolean other(false);

                            tobj.ToBeFalse(boolean != other);
                        });
                });

            entity.StartSpec("operator &&", [&](dty::test::TestEntity& entity) -> void
                {
                    entity.RunTest("false and true", "should false", [&](dty::test::TestObject& tobj) -> void
                        {
                            dty::Boolean other(true);

                            tobj.ToBeFalse(boolean && other);
                        });
                    entity.RunTest("false and false", "should false", [&](dty::test::TestObject& tobj) -> void
                        {
                            dty::Boolean other(false);

                            tobj.ToBeFalse(boolean && other);
                        });
                    entity.RunTest("true and true", "should true", [&](dty::test::TestObject& tobj) -> void
                        {
                            dty::Boolean other1(true);
                            dty::Boolean other2(true);

                            tobj.ToBeTrue(other1 && other2);
                        });
                });

            entity.StartSpec("operator ||", [&](dty::test::TestEntity& entity) -> void
                {
                    entity.RunTest("false and true", "should true", [&](dty::test::TestObject& tobj) -> void
                        {
                            dty::Boolean other(true);

                            tobj.ToBeTrue(boolean || other);
                        });
                    entity.RunTest("false and false", "should false", [&](dty::test::TestObject& tobj) -> void
                        {
                            dty::Boolean other(false);

                            tobj.ToBeFalse(boolean || other);
                        });
                    entity.RunTest("true and true", "should true", [&](dty::test::TestObject& tobj) -> void
                        {
                            dty::Boolean other1(true);
                            dty::Boolean other2(true);

                            tobj.ToBeTrue(other1 || other2);
                        });
                });
        });

    entity.StartSpec("ToString", [&](dty::test::TestEntity& entity) -> void
        {
            // ToString will invoke dty::FormatHelper::Format which is common format center.
            // Due to FormatHelper has been tested fully, test here simply.
            entity.RunTest("no parameter", "true value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Boolean other(true);

                    tobj.EQ(other.ToString(), (::string)"true");
                });
            entity.RunTest("no parameter", "false value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Boolean other(false);

                    tobj.EQ(other.ToString(), (::string)"false");
                });

            entity.RunTest("parameter 'U'", "upper value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Boolean other(true);

                    tobj.EQ(other.ToString((::string)"U"), (::string)"TRUE");
                });
            entity.RunTest("parameter 'xDD", "hex integer value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Boolean other(true);

                    tobj.EQ(other.ToString("xDD"), (::string)"0x01");
                });
        });

    entity.RunTest("GetTypeId", "not 0", [&](dty::test::TestObject& tobj) -> void
        {
            uint64 typeId = dty::GetType(boolean).Id();

            tobj.EQ(boolean.GetTypeId(), typeId);
        });

    entity.RunTest("GetHashCode", "not 0", [&](dty::test::TestObject& tobj) -> void
        {
            uint64 hashCode = dty::GetType(boolean).InstanceHashCode();

            tobj.EQ(boolean.GetHashCode(), hashCode);
        });

    entity.StartSpec("Parse & TryParse", [&](dty::test::TestEntity& entity) -> void
        {
            // TryParse and Parse will invoke dty::ParseHelper::Parse which is common parse center.
            // Due to ParseHelper has been tested fully, test here simply.

            entity.RunTest("Parse", "true", [&](dty::test::TestObject& tobj) -> void
                {
                    bool parseValue = dty::Boolean::Parse((::string)"true");

                    tobj.ToBeTrue(parseValue);
                });

            entity.RunTest("TryParse", "true", [&](dty::test::TestObject& tobj) -> void
                {
                    bool parseValue = false;
                    bool result = dty::Boolean::TryParse((::string)"true", parseValue);

                    tobj.ToBeTrue(result);
                    tobj.ToBeTrue(parseValue);
                });

            entity.RunTest("TryParse", "parse fail", [&](dty::test::TestObject& tobj) -> void
                {
                    bool parseValue = false;
                    bool result = dty::Boolean::TryParse(::null, parseValue);

                    tobj.ToBeFalse(result);
                    tobj.ToBeFalse(parseValue);
                });

            entity.RunTest("TryParse Boolean Obj", "true", [&](dty::test::TestObject& tobj) -> void
                {
                    bool result = dty::Boolean::TryParse((::string)"true", boolean);

                    tobj.ToBeTrue(result);
                    tobj.ToBeTrue(boolean);
                });

            entity.RunTest("TryParse Boolean Obj", "parse fail", [&](dty::test::TestObject& tobj) -> void
                {
                    bool result = dty::Boolean::TryParse(::null, boolean);

                    tobj.ToBeFalse(result);
                    tobj.ToBeFalse(boolean);
                });

        });
}