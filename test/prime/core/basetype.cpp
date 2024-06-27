#include "../../testframe.hxx"
#include "../../../native/core/basetype.hpp"
#include "./src/basetype_decimal.hpp"

extern void test_spec_basetype_boolean(tianyu::test::TestEntity& entity);
extern void test_spec_basetype_integer(tianyu::test::TestEntity& entity);

TEST_MAIN("tianyu.common.native.test.prime.core.basetype")
{
    entity.StartSpec("Boolean", test_spec_basetype_boolean);
    entity.StartSpec("Double", test_spec_basetype_decimal_template<tianyu::Double, double, false>);
    entity.StartSpec("Float", test_spec_basetype_decimal_template<tianyu::Float, float, true>);

    // due to all the integer type use the same template
    // to use int64 for all tests
    entity.StartSpec("IntegerBase", test_spec_basetype_integer);

    entity.StartSpec("Other Integer Type", [](tianyu::test::TestEntity& entity) -> void
        {
            entity.RunTest("8bit integer", "char & uchar & byte & sbyte", [](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Char chart;
                    tianyu::UChar uchart;
                    tianyu::Byte bytet;
                    tianyu::SByte sbytet;
                });
            entity.RunTest("16bit integer", "int16 & uint16 & short & ushort", [](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Int16 int16t;
                    tianyu::UInt16 uint16t;
                    tianyu::Short shortt;
                    tianyu::UShort ushortt;
                });
            entity.RunTest("32bit integer", "int32 & uint32", [](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Int32 int32t;
                    tianyu::UInt32 uint32t;
                });
            entity.RunTest("64bit integer", "int64 & uint64", [](tianyu::test::TestObject& tobj) -> void
                {
                    tianyu::Int64 int64t;
                    tianyu::UInt64 uint64t;
                    tianyu::Long longt;
                    tianyu::ULong ulongt;
                });
        });
}