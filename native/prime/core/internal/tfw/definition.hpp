/**
 * @file definition.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-27
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef __DTY_COMMON_NATIVE_TEST_FRAME_DEFINITION_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_TEST_FRAME_DEFINITION_H_PLUS_PLUS__

#include "./test_entity.hpp"

#define TestsEntry_Main() \
    int32 __VARIABLE__ main(int32 __VARIABLE__ argc,char __POINTER__ argv __ARRAY__)

#define TestEntityCreator(entityName, entityDes) dty::test::TestEntity entityName(entityDes, argc, argv)

#define Test_Main_Return(testEntity) return (int32) testEntity ##.GetState()

#endif // !__DTY_COMMON_NATIVE_TEST_FRAME_DEFINITION_H_PLUS_PLUS__