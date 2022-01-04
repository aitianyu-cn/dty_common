#include "../../testframe.hxx"
#include "../../../native/prime/core/iterator.hpp"

extern void test_spec_filter_result(dty::test::TestEntity& entity);
extern void test_spec_iterator_entity(dty::test::TestEntity& entity);
extern void test_spec_iterator_object(dty::test::TestEntity& entity);

RUNTEST(entity, "dty.Iterator(&components) Unit Test")
{
    // test sub spec for FilterResult
    entity.StartSpec("FilterResult Class", test_spec_filter_result);

    // test sub spec for IteratorEntity
    entity.StartSpec("IteratorEntity Class", test_spec_iterator_entity);

    // test sub spec for IteratorObject
    entity.StartSpec("IteratorObject Class", test_spec_iterator_object);
}