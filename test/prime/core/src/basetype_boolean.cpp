#include "../../../testframe.hxx"
#include "../../../../native/core/basetype.hpp"



void test_spec_basetype_boolean(tianyu::test::TestEntity& entity)
{
    entity.StartSpec("constructor", [](tianyu::test::TestEntity& entity) -> void
        {
            entity.RunTest("no init parameter", "false as default", [](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Boolean boolean;

                    tobj.ToBeFalse(boolean);
                });
            entity.RunTest("init with value", "equals to value", [](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Boolean boolean(true);

                    tobj.ToBeTrue(boolean);
                });
            entity.RunTest("init by other obj", "equals to obj", [](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Boolean boolean(true);

                    tianyu::Boolean copy_boolean(boolean);

                    tobj.ToBeTrue(boolean);
                    tobj.ToBeTrue(copy_boolean);
                });
        });

    tianyu::Boolean boolean;

    entity.StartSpec("Equals", [&](tianyu::test::TestEntity& entity) -> void
        {
            entity.RunTest("not boolean type", "should false", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::except::Exception other;

                    tobj.ToBeFalse(boolean.Equals(other));
                });
            entity.RunTest("boolean type with true value", "should false", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Boolean other(true);

                    tobj.ToBeFalse(boolean.Equals((tianyu::TianyuObject __REFERENCE__)other));
                });
            entity.RunTest("boolean type with false value", "should true", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Boolean other(false);

                    tobj.ToBeTrue(boolean.Equals((tianyu::TianyuObject __REFERENCE__)other));
                });
        });

    entity.StartSpec("operator", [&](tianyu::test::TestEntity& entity) -> void
        {
            entity.StartSpec("operator ==", [&](tianyu::test::TestEntity& entity) -> void
                {
                    entity.RunTest("boolean type with false value", "should true", [&](tianyu::test::TestObject& tobj) -> void
                        {
                            tianyu::Boolean other(false);

                            tobj.ToBeTrue(boolean == other);
                        });
                    entity.RunTest("boolean type with true value", "should false", [&](tianyu::test::TestObject& tobj) -> void
                        {
                            tianyu::Boolean other(true);

                            tobj.ToBeFalse(boolean == other);
                        });

                    entity.RunTest("TianyuObject type", "can be convert to boolean type, should true", [&](tianyu::test::TestObject& tobj) -> void
                        {
                            tianyu::Boolean other(false);

                            tobj.ToBeTrue(boolean == (tianyu::TianyuObject __REFERENCE__)other);
                        });
                    entity.RunTest("TianyuObject type", "cannot be convert to boolean type, should false", [&](tianyu::test::TestObject& tobj) -> void
                        {
                            tianyu::except::Exception other;

                            tobj.ToBeFalse(boolean == other);
                        });
                });

            entity.RunTest("operator bool", "get the true state", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Boolean other(true);

                    tobj.ToBeTrue(other);
                });

            entity.StartSpec("operator int32", [&](tianyu::test::TestEntity& entity) -> void
                {
                    entity.RunTest("true value", "should get 1", [&](tianyu::test::TestObject& tobj) -> void
                        {
                            tianyu::Boolean other(true);

                            tobj.EQ((int32)other, 1);
                        });
                    entity.RunTest("false value", "should get 0", [&](tianyu::test::TestObject& tobj) -> void
                        {
                            tianyu::Boolean other(false);

                            tobj.EQ((int32)other, 0);
                        });
                });

            entity.RunTest("operator !", "get the ture state", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tobj.ToBeFalse(boolean);
                    tobj.ToBeTrue(!boolean);
                });

            entity.StartSpec("operator !=", [&](tianyu::test::TestEntity& entity) -> void
                {
                    entity.RunTest("false and true", "should true", [&](tianyu::test::TestObject& tobj) -> void
                        {
                            tianyu::Boolean other(true);

                            tobj.ToBeTrue(boolean != other);
                        });
                    entity.RunTest("false and false", "should false", [&](tianyu::test::TestObject& tobj) -> void
                        {
                            tianyu::Boolean other(false);

                            tobj.ToBeFalse(boolean != other);
                        });
                });

            entity.StartSpec("operator &&", [&](tianyu::test::TestEntity& entity) -> void
                {
                    entity.RunTest("false and true", "should false", [&](tianyu::test::TestObject& tobj) -> void
                        {
                            tianyu::Boolean other(true);

                            tobj.ToBeFalse(boolean && other);
                        });
                    entity.RunTest("false and false", "should false", [&](tianyu::test::TestObject& tobj) -> void
                        {
                            tianyu::Boolean other(false);

                            tobj.ToBeFalse(boolean && other);
                        });
                    entity.RunTest("true and true", "should true", [&](tianyu::test::TestObject& tobj) -> void
                        {
                            tianyu::Boolean other1(true);
                            tianyu::Boolean other2(true);

                            tobj.ToBeTrue(other1 && other2);
                        });
                });

            entity.StartSpec("operator ||", [&](tianyu::test::TestEntity& entity) -> void
                {
                    entity.RunTest("false and true", "should true", [&](tianyu::test::TestObject& tobj) -> void
                        {
                            tianyu::Boolean other(true);

                            tobj.ToBeTrue(boolean || other);
                        });
                    entity.RunTest("false and false", "should false", [&](tianyu::test::TestObject& tobj) -> void
                        {
                            tianyu::Boolean other(false);

                            tobj.ToBeFalse(boolean || other);
                        });
                    entity.RunTest("true and true", "should true", [&](tianyu::test::TestObject& tobj) -> void
                        {
                            tianyu::Boolean other1(true);
                            tianyu::Boolean other2(true);

                            tobj.ToBeTrue(other1 || other2);
                        });
                });
        });

    entity.StartSpec("ToString", [&](tianyu::test::TestEntity& entity) -> void
        {
            // ToString will invoke tianyu::FormatHelper::Format which is common format center.
            // Due to FormatHelper has been tested fully, test here simply.
            entity.RunTest("no parameter", "true value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Boolean other(true);

                    tobj.EQ(other.ToString(), (::string)"true");
                });
            entity.RunTest("no parameter", "false value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Boolean other(false);

                    tobj.EQ(other.ToString(), (::string)"false");
                });

            entity.RunTest("parameter 'U'", "upper value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Boolean other(true);

                    tobj.EQ(other.ToString((::string)"U"), (::string)"TRUE");
                });
            entity.RunTest("parameter 'xDD", "hex integer value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Boolean other(true);

                    tobj.EQ(other.ToString((::string)"xDD"), (::string)"0x01");
                });
        });

    entity.RunTest("GetTypeId", "not 0", [&](tianyu::test::TestObject& tobj) -> void
        {
            uint64 typeId = tianyu::GetType(boolean).Id();

            tobj.EQ(boolean.GetTypeId(), typeId);
        });

    entity.RunTest("GetHashCode", "not 0", [&](tianyu::test::TestObject& tobj) -> void
        {
            uint64 hashCode = tianyu::GetType(boolean).InstanceHashCode();

            tobj.EQ(boolean.GetHashCode(), hashCode);
        });

    entity.StartSpec("Parse & TryParse", [&](tianyu::test::TestEntity& entity) -> void
        {
            // TryParse and Parse will invoke tianyu::ParseHelper::Parse which is common parse center.
            // Due to ParseHelper has been tested fully, test here simply.

            entity.RunTest("Parse", "true", [&](tianyu::test::TestObject& tobj) -> void
                {
                    bool parseValue = tianyu::Boolean::Parse((::string)"true");

                    tobj.ToBeTrue(parseValue);
                });

            entity.RunTest("TryParse", "true", [&](tianyu::test::TestObject& tobj) -> void
                {
                    bool parseValue = false;
                    bool result = tianyu::Boolean::TryParse((::string)"true", parseValue);

                    tobj.ToBeTrue(result);
                    tobj.ToBeTrue(parseValue);
                });

            entity.RunTest("TryParse", "parse fail", [&](tianyu::test::TestObject& tobj) -> void
                {
                    bool parseValue = false;
                    bool result = tianyu::Boolean::TryParse(::null, parseValue);

                    tobj.ToBeFalse(result);
                    tobj.ToBeFalse(parseValue);
                });

            entity.RunTest("TryParse Boolean Obj", "true", [&](tianyu::test::TestObject& tobj) -> void
                {
                    bool result = tianyu::Boolean::TryParse((::string)"true", boolean);

                    tobj.ToBeTrue(result);
                    tobj.ToBeTrue(boolean);
                });

            entity.RunTest("TryParse Boolean Obj", "parse fail", [&](tianyu::test::TestObject& tobj) -> void
                {
                    bool result = tianyu::Boolean::TryParse(::null, boolean);

                    tobj.ToBeFalse(result);
                    tobj.ToBeFalse(boolean);
                });

        });
}