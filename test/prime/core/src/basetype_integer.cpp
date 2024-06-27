#include "../../../testframe.hxx"
#include "../../../../native/core/basetype.hpp"

void test_spec_basetype_integer(tianyu::test::TestEntity& entity)
{
    entity.StartSpec("constructor", [](tianyu::test::TestEntity& entity) -> void
        {
            entity.RunTest("no init parameter", "false as default", [](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value;

                    tobj.EQ((int64)value, (int64)0);
                });
            entity.RunTest("init with value", "equals to value", [](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value(100LL);

                    tobj.EQ((int64)value, (int64)100);
                });
            entity.RunTest("init by other obj", "equals to obj", [](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value(100LL);
                    tianyu::Long copy_value(value);

                    tobj.EQ((int64)value, (int64)100);
                    tobj.EQ((int64)copy_value, (int64)100);
                });
        });

    entity.StartSpec("Equals", [&](tianyu::test::TestEntity& entity) -> void
        {
            entity.RunTest("not same type", "should false", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::except::Exception other;
                    tianyu::Long value(100LL);

                    tobj.ToBeFalse(value.Equals(other));
                });
            entity.RunTest("same type with different value", "should false", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long other;
                    tianyu::Long value(100LL);

                    tobj.ToBeFalse(value.Equals((tianyu::TianyuObject __REFERENCE__)other));
                });
            entity.RunTest("same type with same value", "should true", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long other(100LL);
                    tianyu::Long value(100LL);

                    tobj.ToBeTrue(value.Equals((tianyu::TianyuObject __REFERENCE__)other));
                });
        });

    entity.StartSpec("CompareTo", [&](tianyu::test::TestEntity& entity) -> void
        {
            entity.RunTest("same value", "should equal", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long other(100LL);
                    tianyu::Long value(100LL);

                    tobj.EQ(value.CompareTo(other), tianyu::collection::CompareResult::EQUAL);
                });
            entity.RunTest("100 and 0", "should great", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long other;
                    tianyu::Long value(100LL);

                    tobj.EQ(value.CompareTo(other), tianyu::collection::CompareResult::GREAT);
                });
            entity.RunTest("0 & 100", "should less", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long other(100LL);
                    tianyu::Long value;

                    tobj.EQ(value.CompareTo(other), tianyu::collection::CompareResult::LESS);
                });
        });

    entity.StartSpec("operator compare", [&](tianyu::test::TestEntity& entity) -> void
        {
            // Due to operator compare functions use basic compare apis which are tested above, 
            // to test code for code coverage here.

            entity.RunTest("operator ==", "TianyuObject type not same type get false", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::except::Exception other;
                    tianyu::Long value;

                    tobj.ToBeFalse(value == other);
                });
            entity.RunTest("operator ==", "Same type get true", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long other;
                    tianyu::Long value;

                    tobj.ToBeTrue(value == other);
                });
            entity.RunTest("operator !=", "Same type", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long other;
                    tianyu::Long value;

                    tobj.ToBeFalse(value != other);
                });
            entity.RunTest("operator <", "Same type", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long other(1LL);
                    tianyu::Long value;

                    tobj.ToBeTrue(value < other);
                });
            entity.RunTest("operator >", "Same type", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long other(1LL);
                    tianyu::Long value;

                    tobj.ToBeFalse(value > other);
                });
            entity.RunTest("operator <=", "Same type", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long other(1LL);
                    tianyu::Long value;

                    tobj.ToBeTrue(value <= other);
                });
            entity.RunTest("operator >=", "Same type", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long other(1LL);
                    tianyu::Long value;

                    tobj.ToBeFalse(value >= other);
                });
        });

    entity.StartSpec("operator calculation", [&](tianyu::test::TestEntity& entity) -> void
        {
            entity.RunTest("operator ++", "value should add 1.0", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value;
                    int64 addedValue = ++value;

                    tobj.EQ(addedValue, 1LL);
                    tobj.EQ((int64)value, 1LL);
                });
            entity.RunTest("operator ++(int)", "pre value should be returned and the object value should be added 1.0", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value;
                    int64 addedValue = value++;

                    tobj.EQ(addedValue, 0LL);
                    tobj.EQ((int64)value, 1LL);
                });
            entity.RunTest("operator --", "value should sub 1.0", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value(1LL);
                    int64 subbedValue = --value;

                    tobj.EQ(subbedValue, 0LL);
                    tobj.EQ((int64)value, 0LL);
                });
            entity.RunTest("operator --(int)", "pre value should be returned and the object value should be subbed 1.0", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value(1LL);
                    int64 subbedValue = value--;

                    tobj.EQ(subbedValue, 1LL);
                    tobj.EQ((int64)value, 0LL);
                });

            entity.RunTest("operator +", "calculating two object and return value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value1(1LL);
                    tianyu::Long value2(2LL);

                    tobj.EQ(value1 + value2, 3LL);
                });
            entity.RunTest("operator -", "calculating two object and return value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value1(5LL);
                    tianyu::Long value2(2LL);

                    tobj.EQ(value1 - value2, 3LL);
                });
            entity.RunTest("operator *", "calculating two object and return value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value1(5LL);
                    tianyu::Long value2(2LL);

                    tobj.EQ(value1 * value2, 10LL);
                });
            entity.RunTest("operator /", "calculating two object and return value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value1(5LL);
                    tianyu::Long value2(2LL);

                    tobj.EQ(value1 / value2, 2LL);
                });
            entity.RunTest("operator %", "calculating two object and return value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value1(5LL);
                    tianyu::Long value2(2LL);

                    tobj.EQ(value1 % value2, 1LL);
                });
            entity.RunTest("operator !", "get the logic not value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value(5LL);

                    tobj.EQ(!value, 0LL);
                });
            entity.RunTest("operator &", "calculating two object and return value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value1(5LL);
                    tianyu::Long value2(7LL);

                    tobj.EQ(value1 & value2, 5LL);
                });
            entity.RunTest("operator |", "calculating two object and return value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value1(1LL);
                    tianyu::Long value2(8LL);

                    tobj.EQ(value1 | value2, 9LL);
                });
            entity.RunTest("operator ~", "get the logic not value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value(5LL);

                    tobj.EQ(~value, -6LL);
                });
            entity.RunTest("operator ^", "calculating two object and return value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value1(5LL);
                    tianyu::Long value2(8LL);

                    tobj.EQ(value1 ^ value2, 13LL);
                });
            entity.RunTest("operator <<", "calculating two object and return value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value1(5LL);
                    tianyu::Long value2(8LL);

                    tobj.EQ(value1 << value2, 1280LL);
                });
            entity.RunTest("operator >>", "calculating two object and return value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value1(59430LL);
                    tianyu::Long value2(8LL);

                    tobj.EQ(value1 >> value2, 232LL);
                });

            entity.RunTest("operator =", "set and return new value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value(5LL);
                    tianyu::Long value2(2LL);
                    tobj.EQ((int64)value, 5LL);

                    int64 newValue = value = value2;

                    tobj.EQ((int64)value, 2LL);
                    tobj.EQ(newValue, 2LL);
                });

            entity.RunTest("operator +=", "self calculation and return value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value1(1LL);
                    tianyu::Long value2(2LL);

                    int64 calcValue = value1 += value2;

                    tobj.EQ((int64)value1, 3LL);
                    tobj.EQ(calcValue, 3LL);
                });
            entity.RunTest("operator -=", "self calculation and return value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value1(5LL);
                    tianyu::Long value2(2LL);

                    int64 calcValue = value1 -= value2;

                    tobj.EQ((int64)value1, 3LL);
                    tobj.EQ(calcValue, 3LL);
                });
            entity.RunTest("operator *=", "self calculation and return value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value1(5LL);
                    tianyu::Long value2(2LL);

                    int64 calcValue = value1 *= value2;

                    tobj.EQ((int64)value1, 10LL);
                    tobj.EQ(calcValue, 10LL);
                });
            entity.RunTest("operator /=", "self calculation and return value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value1(5LL);
                    tianyu::Long value2(2LL);

                    int64 calcValue = value1 /= value2;

                    tobj.EQ((int64)value1, 2LL);
                    tobj.EQ(calcValue, 2LL);
                });
            entity.RunTest("operator %=", "calculating two object and return value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value1(5LL);
                    tianyu::Long value2(2LL);

                    int64 calcValue = value1 %= value2;

                    tobj.EQ((int64)value1, 1LL);
                    tobj.EQ(calcValue, 1LL);
                });
            entity.RunTest("operator &=", "calculating two object and return value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value1(5LL);
                    tianyu::Long value2(7LL);

                    int64 calcValue = value1 &= value2;

                    tobj.EQ((int64)value1, 5LL);
                    tobj.EQ(calcValue, 5LL);
                });
            entity.RunTest("operator |=", "calculating two object and return value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value1(1LL);
                    tianyu::Long value2(8LL);

                    int64 calcValue = value1 |= value2;

                    tobj.EQ((int64)value1, 9LL);
                    tobj.EQ(calcValue, 9LL);
                });
            entity.RunTest("operator ^=", "calculating two object and return value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value1(5LL);
                    tianyu::Long value2(8LL);

                    int64 calcValue = value1 ^= value2;

                    tobj.EQ((int64)value1, 13LL);
                    tobj.EQ(calcValue, 13LL);
                });
            entity.RunTest("operator <<=", "calculating two object and return value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value1(5LL);
                    tianyu::Long value2(8LL);

                    int64 calcValue = value1 <<= value2;

                    tobj.EQ((int64)value1, 1280LL);
                    tobj.EQ(calcValue, 1280LL);
                });
            entity.RunTest("operator >>=", "calculating two object and return value", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value1(59430LL);
                    tianyu::Long value2(8LL);

                    int64 calcValue = value1 >>= value2;

                    tobj.EQ((int64)value1, 232LL);
                    tobj.EQ(calcValue, 232LL);
                });
        });


    entity.StartSpec("ToString", [&](tianyu::test::TestEntity& entity) -> void
        {
            // due to ToString uses tianyu::FormatHelper::Format public api which is tested in dty.common.native.test.prime.core.formatter
            // to test for code coverage here.

            entity.RunTest("no parameter", "default", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value(100LL);

                    ::string format = value.ToString();

                    if (tobj.IsNotNull(format))
                    {
                        tobj.EQ(format, (::string)"100");
                        delete [] format;
                    }
                });

            entity.RunTest("has parameter", "default", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long value(100LL);

                    ::string format = value.ToString((::string)"DDDDDsr ");

                    if (tobj.IsNotNull(format))
                    {
                        tobj.EQ(format, (::string)"+ 100");
                        delete [] format;
                    }
                });
        });

    entity.RunTest("GetTypeId", "default", [&](tianyu::test::TestObject& tobj) -> void
        {
            tianyu::Long value;

            uint64 typeId = tianyu::GetType<int64>().Id();

            tobj.EQ(value.GetTypeId(), typeId);
        });

    entity.RunTest("GetHashCode", "default", [&](tianyu::test::TestObject& tobj) -> void
        {
            tianyu::Long value;

            uint64 hashCode = tianyu::GetType<tianyu::Long>(value).InstanceHashCode();

            tobj.EQ(value.GetHashCode(), hashCode);
        });

    entity.StartSpec("Parse & TryParse", [&](tianyu::test::TestEntity& entity) -> void
        {
            // TryParse and Parse will invoke tianyu::ParseHelper::Parse which is common parse center.
            // Due to ParseHelper has been tested fully, test here simply.

            entity.RunTest("Parse", "success", [&](tianyu::test::TestObject& tobj) -> void
                {
                    int64 parseValue = tianyu::Long::Parse((::string)"123");

                    tobj.EQ(parseValue, 123LL);
                });

            entity.RunTest("TryParse", "true", [&](tianyu::test::TestObject& tobj) -> void
                {
                    int64 parseValue = 0LL;
                    bool result = tianyu::Long::TryParse((::string)"123", parseValue);

                    tobj.ToBeTrue(result);
                    tobj.EQ(parseValue, 123LL);
                });

            entity.RunTest("TryParse", "parse fail", [&](tianyu::test::TestObject& tobj) -> void
                {
                    int64 parseValue = 1LL;
                    bool result = tianyu::Long::TryParse(::null, parseValue);

                    tobj.ToBeFalse(result);
                    tobj.EQ(parseValue, 0LL);
                });

            entity.RunTest("TryParse Object", "true", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long parseValue(1LL);
                    bool result = tianyu::Long::TryParse((::string)"123", parseValue);

                    tobj.ToBeTrue(result);
                    tobj.EQ((int64)parseValue, 123LL);
                });

            entity.RunTest("TryParse Object", "parse fail", [&](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Long parseValue(1LL);
                    bool result = tianyu::Long::TryParse(::null, parseValue);

                    tobj.ToBeFalse(result);
                    tobj.EQ((int64)parseValue, 0LL);
                });

        });
}