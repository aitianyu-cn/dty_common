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
#include <iostream>

#define TestsEntry_Main() \
    int32 __VARIABLE__ main(int32 __VARIABLE__ argc,char __POINTER__ argv __ARRAY__)

#define TestEntityCreator(entityName, entityDes) dty::test::TestEntity entityName(entityDes, argc, argv)

#define Test_Main_Return(testEntity) return (int32)(testEntity .GetState())

#define RUNTEST(testName, testDes)                                                                      \
    void TestEntry_TestRunner(dty::test::TestEntity&);                                                  \
    TestsEntry_Main()                                                                                   \
    {                                                                                                   \
        try                                                                                             \
        {                                                                                               \
            TestEntityCreator(TEntity, testDes);                                                        \
            TestEntry_TestRunner(TEntity);                                                              \
            Test_Main_Return(TEntity);                                                                  \
        }                                                                                               \
        catch(int32 err)                                                                                \
        {                                                                                               \
            switch (err)                                                                                \
            {                                                                                           \
                case dty::test::_dty_test_entity_fail_param_too_few:                                    \
                    std::cout << "Test Program need at least 1 parameter." << std::endl;                \
                    break;                                                                              \
                case dty::test::_dty_test_entity_fail_param_pre_more:                                   \
                    std::cout << "Program parameter error with wrong pre '-' character." << std::endl;  \
                    break;                                                                              \
                case dty::test::_dty_test_entity_fail_file_open:                                        \
                    std::cout << "Output file open failed!" << std::endl;                               \
                    break;                                                                              \
                default:                                                                                \
                    std::cout << "Unknown Error" << std::endl;                                          \
                    break;                                                                              \
            }                                                                                           \
        }                                                                                               \
        catch(...)                                                                                      \
        {                                                                                               \
            std::cout << "Unknown Error" << std::endl;                                                  \
        }                                                                                               \
        return -1;                                                                                      \
    }                                                                                                   \
    void TestEntry_TestRunner(dty::test::TestEntity& testName)

#endif // !__DTY_COMMON_NATIVE_TEST_FRAME_DEFINITION_H_PLUS_PLUS__