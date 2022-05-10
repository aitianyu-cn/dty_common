#include "../../../testframe.hxx"
#include "../../../../native/prime/core/basetype.hpp"
#include "math.h"

const double test_dty_native_double_default_precision = 1e-10;
const float test_dty_native_float_default_precision = 1e-5;

template<typename T, class VT, bool is_float_precision>
void test_spec_basetype_decimal_template(dty::test::TestEntity& entity)
{
    std::function<double()> fnGetPrecision = [&]() -> double
    {
        if (is_float_precision)
            return test_dty_native_float_default_precision;

        return test_dty_native_double_default_precision;
    };

    std::function<int32(VT, VT)> fnCmpValue = [&](VT v1, VT v2) -> int32
    {
        double sub = v1 - v2;
        sub = ::fabs(sub);
        if (sub < fnGetPrecision())
            return 0;

        return v1 > v2 ? 1 : -1;
    };

    std::function<int32(VT, VT, double)> fnCmpValueWithPrecision = [&](VT v1, VT v2, double precision) -> int32
    {
        double sub = v1 - v2;
        sub = ::fabs(sub);
        if (sub < precision)
            return 0;

        return v1 > v2 ? 1 : -1;
    };

    entity.StartSpec("constructor", [&](dty::test::TestEntity& entity) -> void
        {
            entity.RunTest("no parameter", "value as default", [&](dty::test::TestObject& tobj) -> void
                {
                    T value;

                    tobj.EQ(fnCmpValue((VT)value, (VT)0.0), 0);
                });
            entity.RunTest("one parameter", "value is set", [&](dty::test::TestObject& tobj) -> void
                {
                    T value((VT)10.5);

                    tobj.EQ(fnCmpValue((VT)value, (VT)10.5), 0);
                });
            entity.RunTest("two parameter", "value is set and precision is set", [&](dty::test::TestObject& tobj) -> void
                {
                    T value((VT)10.5, (VT)1e-3);

                    tobj.EQ(fnCmpValue((VT)value, (VT)10.5), 0);
                    tobj.EQ(fnCmpValue((VT)(value.Precision), (VT)1e-3), 0);
                });
            entity.RunTest("copy object", "value and precision are same as source object", [&](dty::test::TestObject& tobj) -> void
                {
                    T value((VT)10.5, (VT)1e-3);
                    T copy(value);

                    tobj.EQ(fnCmpValue((VT)value, (VT)copy), 0);
                    tobj.EQ(fnCmpValue((VT)(value.Precision), (VT)(copy.Precision)), 0);
                });
        });

    entity.StartSpec("Equals", [&](dty::test::TestEntity& entity) -> void
        {
            entity.StartSpec("Tianyu Object", [&](dty::test::TestEntity& entity) -> void
                {
                    entity.RunTest("Type not match", "get false", [&](dty::test::TestObject& tobj) -> void
                        {
                            dty::except::Exception other;
                            T value;

                            tobj.ToBeFalse(value.Equals(other));
                        });

                    entity.RunTest("Type match", "get true", [&](dty::test::TestObject& tobj) -> void
                        {
                            T other;
                            T value;

                            tobj.ToBeTrue(value.Equals((dty::TianyuObject __REFERENCE__)other));
                        });
                    entity.RunTest("Same Value Object", "get true", [&](dty::test::TestObject& tobj) -> void
                        {
                            T value;

                            tobj.ToBeTrue(value.Equals(value));
                        });
                });

            entity.StartSpec("Type match", [&](dty::test::TestEntity& entity) -> void
                {
                    entity.RunTest("different value", "get false", [&](dty::test::TestObject& tobj) -> void
                        {
                            T other((VT)1.0);
                            T value;

                            tobj.ToBeFalse(value.Equals(other));
                        });
                    entity.RunTest("same value", "get true", [&](dty::test::TestObject& tobj) -> void
                        {
                            T other;
                            T value;

                            tobj.ToBeTrue(value.Equals(other));
                        });
                    entity.RunTest("values differ less than precision", "get true", [&](dty::test::TestObject& tobj) -> void
                        {
                            T other((VT)(is_float_precision ? 1.0000098 : 1.000000000098));
                            T value((VT)1.0);

                            tobj.ToBeTrue(value.Equals(other));
                        });
                    entity.RunTest("values differ greate than precision", "get false", [&](dty::test::TestObject& tobj) -> void
                        {
                            T other((VT)(is_float_precision ? 1.00001 : 1.0000000001));
                            T value((VT)1.0);

                            tobj.ToBeFalse(value.Equals(other));
                        });
                });
        });

    entity.StartSpec("CompareTo", [&](dty::test::TestEntity& entity) -> void
        {
            entity.RunTest("different values", "get great", [&](dty::test::TestObject& tobj) -> void
                {
                    T other;
                    T value((VT)1.0);

                    tobj.EQ(value.CompareTo(other), dty::collection::CompareResult::GREAT);
                });
            entity.RunTest("different value", "get less", [&](dty::test::TestObject& tobj) -> void
                {
                    T other((VT)1.0);
                    T value;

                    tobj.EQ(value.CompareTo(other), dty::collection::CompareResult::LESS);
                });
            entity.RunTest("values differ less than precision", "get Equals", [&](dty::test::TestObject& tobj) -> void
                {
                    T other((VT)(is_float_precision ? 1.0000098 : 1.000000000098));
                    T value((VT)1.0);

                    tobj.EQ(value.CompareTo(other), dty::collection::CompareResult::EQUAL);

                    // to check the higher precision, the compare result should be not equal.
                    int32 checkCmp = fnCmpValueWithPrecision((VT)value, (VT)other, (is_float_precision ? 1e-6 : 1e-11));
                    tobj.NE(checkCmp, 0);
                });
        });

    entity.StartSpec("operator compare", [&](dty::test::TestEntity& entity) -> void
        {
            // Due to operator compare functions use basic compare apis which are tested above, 
            // to test code for code coverage here.

            entity.RunTest("operator ==", "TianyuObject type not same type get false", [&](dty::test::TestObject& tobj) -> void
                {
                    dty::except::Exception other;
                    T value;

                    tobj.ToBeFalse(value == other);
                });
            entity.RunTest("operator ==", "Same type get true", [&](dty::test::TestObject& tobj) -> void
                {
                    T other;
                    T value;

                    tobj.ToBeTrue(value == other);
                });
            entity.RunTest("operator !=", "Same type", [&](dty::test::TestObject& tobj) -> void
                {
                    T other;
                    T value;

                    tobj.ToBeFalse(value != other);
                });
            entity.RunTest("operator <", "Same type", [&](dty::test::TestObject& tobj) -> void
                {
                    T other((VT)1.0);
                    T value;

                    tobj.ToBeTrue(value < other);
                });
            entity.RunTest("operator >", "Same type", [&](dty::test::TestObject& tobj) -> void
                {
                    T other((VT)1.0);
                    T value;

                    tobj.ToBeFalse(value > other);
                });
            entity.RunTest("operator <=", "Same type", [&](dty::test::TestObject& tobj) -> void
                {
                    T other((VT)1.0);
                    T value;

                    tobj.ToBeTrue(value <= other);
                });
            entity.RunTest("operator >=", "Same type", [&](dty::test::TestObject& tobj) -> void
                {
                    T other((VT)1.0);
                    T value;

                    tobj.ToBeFalse(value >= other);
                });
        });

    entity.StartSpec("operator calculation", [&](dty::test::TestEntity& entity) -> void
        {
            entity.RunTest("operator ++", "value should add 1.0", [&](dty::test::TestObject& tobj) -> void
                {
                    T value;
                    VT addedValue = ++value;

                    tobj.EQ(fnCmpValue(addedValue, (VT)1.0), 0);
                    tobj.EQ(fnCmpValue((VT)value, (VT)1.0), 0);
                });
            entity.RunTest("operator ++(int)", "pre value should be returned and the object value should be added 1.0", [&](dty::test::TestObject& tobj) -> void
                {
                    T value;
                    VT addedValue = value++;

                    tobj.EQ(fnCmpValue(addedValue, (VT)0.0), 0);
                    tobj.EQ(fnCmpValue((VT)value, (VT)1.0), 0);
                });
            entity.RunTest("operator --", "value should sub 1.0", [&](dty::test::TestObject& tobj) -> void
                {
                    T value((VT)1.0);
                    VT subbedValue = --value;

                    tobj.EQ(fnCmpValue(subbedValue, (VT)0.0), 0);
                    tobj.EQ(fnCmpValue((VT)value, (VT)0.0), 0);
                });
            entity.RunTest("operator --(int)", "pre value should be returned and the object value should be subbed 1.0", [&](dty::test::TestObject& tobj) -> void
                {
                    T value((VT)1.0);
                    VT subbedValue = value--;

                    tobj.EQ(fnCmpValue(subbedValue, (VT)1.0), 0);
                    tobj.EQ(fnCmpValue((VT)value, (VT)0.0), 0);
                });

            entity.RunTest("operator +", "calculating two object and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    T value1((VT)1.0);
                    T value2((VT)2.0);

                    tobj.EQ(fnCmpValue(value1 + value2, (VT)3.0), 0);
                });
            entity.RunTest("operator -", "calculating two object and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    T value1((VT)5.0);
                    T value2((VT)2.0);

                    tobj.EQ(fnCmpValue(value1 - value2, (VT)3.0), 0);
                });
            entity.RunTest("operator *", "calculating two object and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    T value1((VT)5.125);
                    T value2((VT)2.25);

                    tobj.EQ(fnCmpValue(value1 * value2, (VT)(2.25 * 5.125)), 0);
                });
            entity.RunTest("operator /", "calculating two object and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    T value1((VT)5.125);
                    T value2((VT)2.25);

                    tobj.EQ(fnCmpValue(value1 / value2, (VT)(5.125 / 2.25)), 0);
                });
            entity.RunTest("operator =", "set and return new value", [&](dty::test::TestObject& tobj) -> void
                {
                    T value((VT)5.125);
                    T value2((VT)2.375);
                    tobj.EQ(fnCmpValue(value, (VT)5.125), 0);

                    VT newValue = value = value2;

                    tobj.EQ(fnCmpValue(value, (VT)2.375), 0);
                    tobj.EQ(fnCmpValue(newValue, (VT)2.375), 0);
                });

            entity.RunTest("operator +=", "self calculation and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    T value1((VT)1.0);
                    T value2((VT)2.0);

                    VT calcValue = value1 += value2;

                    tobj.EQ(fnCmpValue((VT)value1, (VT)3.0), 0);
                    tobj.EQ(fnCmpValue(calcValue, (VT)3.0), 0);
                });
            entity.RunTest("operator -=", "self calculation and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    T value1((VT)5.0);
                    T value2((VT)2.0);

                    VT calcValue = value1 -= value2;

                    tobj.EQ(fnCmpValue((VT)value1, (VT)3.0), 0);
                    tobj.EQ(fnCmpValue(calcValue, (VT)3.0), 0);
                });
            entity.RunTest("operator *=", "self calculation and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    T value1((VT)5.125);
                    T value2((VT)2.25);

                    VT calcValue = value1 *= value2;

                    tobj.EQ(fnCmpValue((VT)value1, (VT)(2.25 * 5.125)), 0);
                    tobj.EQ(fnCmpValue(calcValue, (VT)(2.25 * 5.125)), 0);
                });
            entity.RunTest("operator /=", "self calculation and return value", [&](dty::test::TestObject& tobj) -> void
                {
                    T value1((VT)5.125);
                    T value2((VT)2.25);

                    VT calcValue = value1 /= value2;

                    tobj.EQ(fnCmpValue((VT)value1, (VT)(5.125 / 2.25)), 0);
                    tobj.EQ(fnCmpValue(calcValue, (VT)(5.125 / 2.25)), 0);
                });
        });

    entity.StartSpec("ToString", [&](dty::test::TestEntity& entity) -> void
        {
            // due to ToString uses dty::FormatHelper::Format public api which is tested in dty.common.native.test.prime.core.formatter
            // to test for code coverage here.

            // currently, decimal type will get null value due to the format function has not been implementation.            
            entity.RunTest("no parameter", "default", [&](dty::test::TestObject& tobj) -> void
                {
                    T value;

                    ::string format = value.ToString();

                    if (!tobj.IsNull(format))
                        delete [] format;
                });

            entity.RunTest("has parameter", "default", [&](dty::test::TestObject& tobj) -> void
                {
                    T value;

                    ::string format = value.ToString((::string)"ffff");

                    if (!tobj.IsNull(format))
                        delete [] format;
                });
        });

    entity.RunTest("GetTypeId", "default", [&](dty::test::TestObject& tobj) -> void
        {
            T value;

            uint64 typeId = dty::GetType<T>().Id();

            tobj.EQ(value.GetTypeId(), typeId);
        });

    entity.RunTest("GetHashCode", "default", [&](dty::test::TestObject& tobj) -> void
        {
            T value;

            uint64 hashCode = dty::GetType<T>(value).InstanceHashCode();

            tobj.EQ(value.GetHashCode(), hashCode);
        });

    entity.StartSpec("Parse & TryParse", [&](dty::test::TestEntity& entity) -> void
        {
            // TryParse and Parse will invoke dty::ParseHelper::Parse which is common parse center.
            // Due to ParseHelper has been tested fully, test here simply.

            entity.RunTest("Parse", "success", [&](dty::test::TestObject& tobj) -> void
                {
                    VT parseValue = T::Parse((::string)"123.125");

                    tobj.EQ(fnCmpValue(parseValue, (VT)123.125), 0);
                });

            entity.RunTest("TryParse", "true", [&](dty::test::TestObject& tobj) -> void
                {
                    VT parseValue = 0.0;
                    bool result = T::TryParse((::string)"123.125", parseValue);

                    tobj.ToBeTrue(result);
                    tobj.EQ(fnCmpValue(parseValue, (VT)123.125), 0);
                });

            entity.RunTest("TryParse", "parse fail", [&](dty::test::TestObject& tobj) -> void
                {
                    VT parseValue = 1.0;
                    bool result = T::TryParse(::null, parseValue);

                    tobj.ToBeFalse(result);
                    tobj.EQ(fnCmpValue(parseValue, (VT)0.0), 0);
                });

            entity.RunTest("TryParse Object", "true", [&](dty::test::TestObject& tobj) -> void
                {
                    T parseValue(1.0);
                    bool result = T::TryParse((::string)"123.125", parseValue);

                    tobj.ToBeTrue(result);
                    tobj.EQ(fnCmpValue(parseValue, (VT)123.125), 0);
                });

            entity.RunTest("TryParse Object", "parse fail", [&](dty::test::TestObject& tobj) -> void
                {
                    T parseValue(1.0);
                    bool result = T::TryParse(::null, parseValue);

                    tobj.ToBeFalse(result);
                    tobj.EQ(fnCmpValue(parseValue, (VT)0.0), 0);
                });

        });
}
