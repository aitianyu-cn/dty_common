#include "../../testframe.hxx"
#include "../../../native/core/iterator.hpp"

extern void test_spec_filter_result(tianyu::test::TestEntity& entity);
extern void test_spec_iterator_entity(tianyu::test::TestEntity& entity);
extern void test_spec_iterator_object(tianyu::test::TestEntity& entity);

RUNTEST(entity, "tianyu.common.native.test.prime.core.iterator")
{
    // test sub spec for FilterResult
    entity.StartSpec("FilterResult Class", test_spec_filter_result);

    // test sub spec for IteratorEntity
    entity.StartSpec("IteratorEntity Class", test_spec_iterator_entity);

    // test sub spec for IteratorObject
    entity.StartSpec("IteratorObject Class", test_spec_iterator_object);
}