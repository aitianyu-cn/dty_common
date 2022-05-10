#include "../../testframe.hxx"
#include "../../../native/prime/core/basetype.hpp"
#include "./src/basetype_decimal.hpp"

extern void test_spec_basetype_boolean(dty::test::TestEntity& entity);
extern void test_spec_basetype_integer(dty::test::TestEntity& entity);

TEST_MAIN("dty.common.native.test.prime.core.basetype")
{
    entity.StartSpec("Boolean", test_spec_basetype_boolean);
    entity.StartSpec("Double", test_spec_basetype_decimal_template<dty::Double, double, false>);
    entity.StartSpec("Float", test_spec_basetype_decimal_template<dty::Float, float, true>);

    // due to all the integer type use the same template
    // to use int64 for all tests
    entity.StartSpec("IntegerBase", test_spec_basetype_integer);

    entity.StartSpec("Other Integer Type", [](dty::test::TestEntity& entity) -> void
        {
            entity.RunTest("8bit integer", "char & uchar & byte & sbyte", [](dty::test::TestObject& tobj) -> void
                {
                    dty::Char chart;
                    dty::UChar uchart;
                    dty::Byte bytet;
                    dty::SByte sbytet;
                });
            entity.RunTest("16bit integer", "int16 & uint16 & short & ushort", [](dty::test::TestObject& tobj) -> void
                {
                    dty::Int16 int16t;
                    dty::UInt16 uint16t;
                    dty::Short shortt;
                    dty::UShort ushortt;
                });
            entity.RunTest("32bit integer", "int32 & uint32", [](dty::test::TestObject& tobj) -> void
                {
                    dty::Int32 int32t;
                    dty::UInt32 uint32t;
                });
            entity.RunTest("64bit integer", "int64 & uint64", [](dty::test::TestObject& tobj) -> void
                {
                    dty::Int64 int64t;
                    dty::UInt64 uint64t;
                    dty::Long longt;
                    dty::ULong ulongt;
                });
        });
}