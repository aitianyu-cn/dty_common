#include "../../../testframe.hxx"
#include "../../../../native/prime/core/iterator.hpp"

void test_spec_iterator_entity(dty::test::TestEntity& entity)
{
    entity.StartSpec("construct", [](TE& entity) -> void
        {
            entity.StartSpec("constructor", [](TE& entity) -> void
                {
                    entity.RunExceptionTest("constructor", "expect an error if pointer is null and size does not equal 0", [](TO& t) -> void
                        {

                        }
                    );

                    entity.RunExceptionTest("constructor", "expect an error if size is not great than 0", [](TO& t) -> void
                        {

                        }
                    );

                    entity.RunTest("constructor", "new object from specified pointer successful", [](TO& t) -> void
                        {

                        }
                    );
                }
            );

            entity.RunTest("construct", "copy constructor", [](TO& t) -> void
                {

                }
            );

            entity.StartSpec("destructor", [](TE& entity) -> void
                {
                    entity.RunTest("destructor", "nothing needs to do if does not need to free or size is 0", [](TO& t) -> void
                        {

                        }
                    );

                    entity.RunTest("destructor", "do not need to free if the pointer is still using", [](TO& t) -> void
                        {

                        }
                    );

                    entity.RunTest("destructor", "release pointer", [](TO& t) -> void
                        {

                        }
                    );
                }
            );
        }
    );

    entity.StartSpec("Get", [](TE& entity) -> void
        {
            entity.RunTest("Get", "size = 0", [](TO& t) -> void
                {

                }
            );

            entity.RunTest("Get", "correct index should return indicated item", [](TO& t) -> void
                {

                }
            );

            entity.RunTest("Get", "wrong index(less than 0) should return the first item", [](TO& t) -> void
                {

                }
            );

            entity.RunTest("Get", "wrong index(over size) should return the last item", [](TO& t) -> void
                {

                }
            );
        }
    );

    entity.StartSpec("End", [](TE& entity) -> void
        {
            entity.RunTest("End", "size = 0", [](TO& t) -> void
                {

                }
            );

            entity.RunTest("End", "size != 0", [](TO& t) -> void
                {

                }
            );
        }
    );

    entity.StartSpec("Enum APIs", [](TE& entity) -> void
        {
            entity.StartSpec("ForEach", [](TE& entity) -> void
                {

                }
            );

            entity.StartSpec("Some", [](TE& entity) -> void
                {

                }
            );

            entity.StartSpec("Filter", [](TE& entity) -> void
                {

                }
            );

            entity.StartSpec("Never", [](TE& entity) -> void
                {

                }
            );

            entity.StartSpec("Find", [](TE& entity) -> void
                {

                }
            );

            entity.StartSpec("FindIndex", [](TE& entity) -> void
                {

                }
            );
        }
    );
}