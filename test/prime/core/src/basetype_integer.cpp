#include "../../../testframe.hxx"
#include "../../../../native/prime/core/basetype.hpp"

void test_spec_basetype_integer(dty::test::TestEntity& entity)
{
    entity.StartSpec("constructor", [](dty::test::TestEntity& entity) -> void
        {
            entity.RunTest("no init parameter", "false as default", [](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value;

                    tobj.EQ((int64)value, (int64)0);
                });
            entity.RunTest("init with value", "equals to value", [](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value(100LL);

                    tobj.EQ((int64)value, (int64)100);
                });
            entity.RunTest("init by other obj", "equals to obj", [](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value(100LL);
                    dty::Long copy_value(value);

                    tobj.EQ((int64)value, (int64)100);
                    tobj.EQ((int64)copy_value, (int64)100);
                });
        });

    entity.StartSpec("Equals", [&](dty::test::TestEntity& entity) -> void
        {
            entity.RunTest("not same type", "should false", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::except::Exception other;
                    dty::Long value(100LL);

                    tobj.ToBeFalse(value.Equals(other));
                });
            entity.RunTest("same type with different value", "should false", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long other;
                    dty::Long value(100LL);

                    tobj.ToBeFalse(value.Equals((dty::TianyuObject __REFERENCE__)other));
                });
            entity.RunTest("same type with same value", "should true", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long other(100LL);
                    dty::Long value(100LL);

                    tobj.ToBeTrue(value.Equals((dty::TianyuObject __REFERENCE__)other));
                });
        });

    entity.StartSpec("CompareTo", [&](dty::test::TestEntity& entity) -> void
        {
            entity.RunTest("same value", "should equal", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long other(100LL);
                    dty::Long value(100LL);

                    tobj.EQ(value.CompareTo(other), dty::collection::CompareResult::EQUAL);
                });
            entity.RunTest("100 and 0", "should great", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long other;
                    dty::Long value(100LL);

                    tobj.EQ(value.CompareTo(other), dty::collection::CompareResult::GREAT);
                });
            entity.RunTest("0 & 100", "should less", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long other(100LL);
                    dty::Long value;

                    tobj.EQ(value.CompareTo(other), dty::collection::CompareResult::LESS);
                });
        });

    entity.StartSpec("operator compare", [&](dty::test::TestEntity& entity) -> void
        {
            // Due to operator compare functions use basic compare apis which are tested above, 
            // to test code for code coverage here.

            entity.RunTest("operator ==", "TianyuObject type not same type get false", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::except::Exception other;
                    dty::Long value;

                    tobj.ToBeFalse(value == other);
                });
            entity.RunTest("operator ==", "Same type get true", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long other;
                    dty::Long value;

                    tobj.ToBeTrue(value == other);
                });
            entity.RunTest("operator !=", "Same type", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long other;
                    dty::Long value;

                    tobj.ToBeFalse(value != other);
                });
            entity.RunTest("operator <", "Same type", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long other(1LL);
                    dty::Long value;

                    tobj.ToBeTrue(value < other);
                });
            entity.RunTest("operator >", "Same type", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long other(1LL);
                    dty::Long value;

                    tobj.ToBeFalse(value > other);
                });
            entity.RunTest("operator <=", "Same type", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long other(1LL);
                    dty::Long value;

                    tobj.ToBeTrue(value <= other);
                });
            entity.RunTest("operator >=", "Same type", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long other(1LL);
                    dty::Long value;

                    tobj.ToBeFalse(value >= other);
                });
        });

    entity.StartSpec("operator calculation", [&](dty::test::TestEntity& entity) -> void
        {
            entity.RunTest("operator ++", "value should add 1.0", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value;
                    int64 addedValue = ++value;

                    tobj.EQ(addedValue, 1LL);
                    tobj.EQ((int64)value, 1LL);
                });
            entity.RunTest("operator ++(int)", "pre value should be returned and the object value should be added 1.0", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value;
                    int64 addedValue = value++;

                    tobj.EQ(addedValue, 0LL);
                    tobj.EQ((int64)value, 1LL);
                });
            entity.RunTest("operator --", "value should sub 1.0", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value(1LL);
                    int64 subbedValue = --value;

                    tobj.EQ(subbedValue, 0LL);
                    tobj.EQ((int64)value, 0LL);
                });
            entity.RunTest("operator --(int)", "pre value should be returned and the object value should be subbed 1.0", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value(1LL);
                    int64 subbedValue = value--;

                    tobj.EQ(subbedValue, 1LL);
                    tobj.EQ((int64)value, 0LL);
                });

            entity.RunTest("operator +", "calculating two object and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value1(1LL);
                    dty::Long value2(2LL);

                    tobj.EQ(value1 + value2, 3LL);
                });
            entity.RunTest("operator -", "calculating two object and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value1(5LL);
                    dty::Long value2(2LL);

                    tobj.EQ(value1 - value2, 3LL);
                });
            entity.RunTest("operator *", "calculating two object and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value1(5LL);
                    dty::Long value2(2LL);

                    tobj.EQ(value1 * value2, 10LL);
                });
            entity.RunTest("operator /", "calculating two object and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value1(5LL);
                    dty::Long value2(2LL);

                    tobj.EQ(value1 / value2, 2LL);
                });
            entity.RunTest("operator %", "calculating two object and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value1(5LL);
                    dty::Long value2(2LL);

                    tobj.EQ(value1 % value2, 1LL);
                });
            entity.RunTest("operator !", "get the logic not value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value(5LL);

                    tobj.EQ(!value, 0LL);
                });
            entity.RunTest("operator &", "calculating two object and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value1(5LL);
                    dty::Long value2(7LL);

                    tobj.EQ(value1 & value2, 5LL);
                });
            entity.RunTest("operator |", "calculating two object and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value1(1LL);
                    dty::Long value2(8LL);

                    tobj.EQ(value1 | value2, 9LL);
                });
            entity.RunTest("operator ~", "get the logic not value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value(5LL);

                    tobj.EQ(~value, -6LL);
                });
            entity.RunTest("operator ^", "calculating two object and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value1(5LL);
                    dty::Long value2(8LL);

                    tobj.EQ(value1 ^ value2, 13LL);
                });
            entity.RunTest("operator <<", "calculating two object and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value1(5LL);
                    dty::Long value2(8LL);

                    tobj.EQ(value1 << value2, 1280LL);
                });
            entity.RunTest("operator >>", "calculating two object and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value1(59430LL);
                    dty::Long value2(8LL);

                    tobj.EQ(value1 >> value2, 232LL);
                });

            entity.RunTest("operator =", "set and return new value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value(5LL);
                    dty::Long value2(2LL);
                    tobj.EQ((int64)value, 5LL);

                    int64 newValue = value = value2;

                    tobj.EQ((int64)value, 2LL);
                    tobj.EQ(newValue, 2LL);
                });

            entity.RunTest("operator +=", "self calculation and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value1(1LL);
                    dty::Long value2(2LL);

                    int64 calcValue = value1 += value2;

                    tobj.EQ((int64)value1, 3LL);
                    tobj.EQ(calcValue, 3LL);
                });
            entity.RunTest("operator -=", "self calculation and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value1(5LL);
                    dty::Long value2(2LL);

                    int64 calcValue = value1 -= value2;

                    tobj.EQ((int64)value1, 3LL);
                    tobj.EQ(calcValue, 3LL);
                });
            entity.RunTest("operator *=", "self calculation and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value1(5LL);
                    dty::Long value2(2LL);

                    int64 calcValue = value1 *= value2;

                    tobj.EQ((int64)value1, 10LL);
                    tobj.EQ(calcValue, 10LL);
                });
            entity.RunTest("operator /=", "self calculation and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value1(5LL);
                    dty::Long value2(2LL);

                    int64 calcValue = value1 /= value2;

                    tobj.EQ((int64)value1, 2LL);
                    tobj.EQ(calcValue, 2LL);
                });
            entity.RunTest("operator %=", "calculating two object and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value1(5LL);
                    dty::Long value2(2LL);

                    int64 calcValue = value1 %= value2;

                    tobj.EQ((int64)value1, 1LL);
                    tobj.EQ(calcValue, 1LL);
                });
            entity.RunTest("operator &=", "calculating two object and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value1(5LL);
                    dty::Long value2(7LL);

                    int64 calcValue = value1 &= value2;

                    tobj.EQ((int64)value1, 5LL);
                    tobj.EQ(calcValue, 5LL);
                });
            entity.RunTest("operator |=", "calculating two object and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value1(1LL);
                    dty::Long value2(8LL);

                    int64 calcValue = value1 |= value2;

                    tobj.EQ((int64)value1, 9LL);
                    tobj.EQ(calcValue, 9LL);
                });
            entity.RunTest("operator ^=", "calculating two object and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value1(5LL);
                    dty::Long value2(8LL);

                    int64 calcValue = value1 ^= value2;

                    tobj.EQ((int64)value1, 13LL);
                    tobj.EQ(calcValue, 13LL);
                });
            entity.RunTest("operator <<=", "calculating two object and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value1(5LL);
                    dty::Long value2(8LL);

                    int64 calcValue = value1 <<= value2;

                    tobj.EQ((int64)value1, 1280LL);
                    tobj.EQ(calcValue, 1280LL);
                });
            entity.RunTest("operator >>=", "calculating two object and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value1(59430LL);
                    dty::Long value2(8LL);

                    int64 calcValue = value1 >>= value2;

                    tobj.EQ((int64)value1, 232LL);
                    tobj.EQ(calcValue, 232LL);
                });
        });


    entity.StartSpec("ToString", [&](dty::test::TestEntity& entity) -> void
        {
            // due to ToString uses dty::FormatHelper::Format public api which is tested in dty.common.native.test.prime.core.formatter
            // to test for code coverage here.

            entity.RunTest("no parameter", "default", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value(100LL);

                    ::string format = value.ToString();

                    if (tobj.IsNotNull(format))
                    {
                        tobj.EQ(format, (::string)"100");
                        delete [] format;
                    }
                });

            entity.RunTest("has parameter", "default", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long value(100LL);

                    ::string format = value.ToString((::string)"DDDDDsr ");

                    if (tobj.IsNotNull(format))
                    {
                        tobj.EQ(format, (::string)"+ 100");
                        delete [] format;
                    }
                });
        });

    entity.RunTest("GetTypeId", "default", [&](dty::test::TestObject& tobj) -> void
        {
            dty::Long value;

            uint64 typeId = dty::GetType<int64>().Id();

            tobj.EQ(value.GetTypeId(), typeId);
        });

    entity.RunTest("GetHashCode", "default", [&](dty::test::TestObject& tobj) -> void
        {
            dty::Long value;

            uint64 hashCode = dty::GetType<dty::Long>(value).InstanceHashCode();

            tobj.EQ(value.GetHashCode(), hashCode);
        });

    entity.StartSpec("Parse & TryParse", [&](dty::test::TestEntity& entity) -> void
        {
            // TryParse and Parse will invoke dty::ParseHelper::Parse which is common parse center.
            // Due to ParseHelper has been tested fully, test here simply.

            entity.RunTest("Parse", "success", [&](dty::test::TestObject& tobj) -> void
                {
                    int64 parseValue = dty::Long::Parse((::string)"123");

                    tobj.EQ(parseValue, 123LL);
                });

            entity.RunTest("TryParse", "true", [&](dty::test::TestObject& tobj) -> void
                {
                    int64 parseValue = 0LL;
                    bool result = dty::Long::TryParse((::string)"123", parseValue);

                    tobj.ToBeTrue(result);
                    tobj.EQ(parseValue, 123LL);
                });

            entity.RunTest("TryParse", "parse fail", [&](dty::test::TestObject& tobj) -> void
                {
                    int64 parseValue = 1LL;
                    bool result = dty::Long::TryParse(::null, parseValue);

                    tobj.ToBeFalse(result);
                    tobj.EQ(parseValue, 0LL);
                });

            entity.RunTest("TryParse Object", "true", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long parseValue(1LL);
                    bool result = dty::Long::TryParse((::string)"123", parseValue);

                    tobj.ToBeTrue(result);
                    tobj.EQ((int64)parseValue, 123LL);
                });

            entity.RunTest("TryParse Object", "parse fail", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::Long parseValue(1LL);
                    bool result = dty::Long::TryParse(::null, parseValue);

                    tobj.ToBeFalse(result);
                    tobj.EQ((int64)parseValue, 0LL);
                });

        });
}