/**
 * @file test-core.hxx(native/test-core)
 * @author senyun.yao
 * @brief 用于天宇平台的测试组件核心
 * @brief AiTianyu Test Components Core of Tianyu Framework
 *
 * @version 0.1
 * @date 2023-07-29
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __TIANYU_COMMON_NATIVE_TEST_CORE_HXX__
#define __TIANYU_COMMON_NATIVE_TEST_CORE_HXX__

#include "./core.hxx"

#ifdef __cplusplus
 //
 // import the core definition of Tianyu Native
#include "stdio.h"
#include <iostream>
#include <functional> 

namespace tianyu::test
{
    _enum TestState : int32
    {
        Success = 0,
        Failed = -1,
        Skipped = -2
    };

    _enum TestType : int32
    {
        Skipped = 0,
        Expect = 1,
        Assert = 2
    };

    // ####################################################################################
    // tianyu test core
    // used to define base structures and functions
    // ####################################################################################
    namespace core
    {
        // Test Object Basic Class
        // this class is a base class of TestEntity and TestFlow
        class TestObjectBase : public virtual tianyu::TianyuObject
        {
            __PRO__ bool       __VARIABLE__  _ConsolePrint;
            __PRO__::string    __VARIABLE__  _ObjectName;
            __PRO__ TestState  __VARIABLE__  _State;
            __PRO__ FILE       __POINTER__   _LogStream;
            __PRO__ int32      __VARIABLE__  _Level;

            __PUB__         TestObjectBase
            (
                bool      __VARIABLE__ consolePrint,
                TestState __VARIABLE__ state,
                FILE      __POINTER__  logStream,
                int32     __VARIABLE__ level
            );
            __PUB__ virtual ~TestObjectBase() __override_func;

            __PUB__ TestState  __VARIABLE__ GetState();
        };
    }

    // Test Object
    // test object to provide the basic APIs for test result exporter and some expect/assert
    // operations.
    // each test item must to use the object to record the test progress.
    class TestObject final : public virtual tianyu::TianyuObject
    {
        __PRI__ TestState __VARIABLE__  _State;


        __PUB__         __construction__ TestObject();
        __PUB__ virtual __destruction__  ~TestObject() __override_func;

        __PUB__ TestState __VARIABLE__ GetState();

        __PRI__ void      __VARIABLE__ SetState(bool __VARIABLE__ result);

        // ##############################################################################################################
        // expects area
        // ##############################################################################################################

        __PUB__ void __VARIABLE__ Set();
        __PUB__ void __VARIABLE__ Skip();
        __PUB__ void __VARIABLE__ Unset();

        __PUB__ bool __VARIABLE__ IsNull(object __VARIABLE__ obj);
        __PUB__ bool __VARIABLE__ IsNull(tianyu::TianyuObject __REFERENCE__ obj);
        __PUB__ bool __VARIABLE__ IsNotNull(object __VARIABLE__ obj);
        __PUB__ bool __VARIABLE__ IsNotNull(tianyu::TianyuObject __REFERENCE__ obj);

        __PUB__ bool __VARIABLE__ IsEmpty(const ::string __VARIABLE__ str);
        __PUB__ bool __VARIABLE__ IsNotEmpty(const ::string __VARIABLE__ str);

        __PUB__ bool __VARIABLE__ ToBeTrue(bool __VARIABLE__ value);
        __PUB__ bool __VARIABLE__ ToBeFalse(bool __VARIABLE__ value);

        __PUB__ bool __VARIABLE__ EQ(const ::string __VARIABLE__ str1, const ::string __VARIABLE__ str2);
        __PUB__ bool __VARIABLE__ NE(const ::string __VARIABLE__ str1, const ::string __VARIABLE__ str2);
        __PUB__ bool __VARIABLE__ GT(const ::string __VARIABLE__ str1, const ::string __VARIABLE__ str2);
        __PUB__ bool __VARIABLE__ LT(const ::string __VARIABLE__ str1, const ::string __VARIABLE__ str2);
        __PUB__ bool __VARIABLE__ StrLenIs(const ::string __VARIABLE__ str, int32 __VARIABLE__ len);
        __PUB__ bool __VARIABLE__ StrLenIsNot(const ::string __VARIABLE__ str, int32 __VARIABLE__ len);
        __PUB__ bool __VARIABLE__ StrLenGT(const ::string __VARIABLE__ str, int32 __VARIABLE__ len);
        __PUB__ bool __VARIABLE__ StrLenLT(const ::string __VARIABLE__ str, int32 __VARIABLE__ len);

        __PUB__ bool __VARIABLE__ EQ(tianyu::TianyuObject __REFERENCE__ val1, tianyu::TianyuObject __REFERENCE__ val2);
        __PUB__ bool __VARIABLE__ NE(tianyu::TianyuObject __REFERENCE__ val1, tianyu::TianyuObject __REFERENCE__ val2);
        __PUB__ bool __VARIABLE__ GT(tianyu::TianyuObject __REFERENCE__ val1, tianyu::TianyuObject __REFERENCE__ val2);
        __PUB__ bool __VARIABLE__ LT(tianyu::TianyuObject __REFERENCE__ val1, tianyu::TianyuObject __REFERENCE__ val2);

        // ##############################################################################################################
        // template expects and asserts
        // ##############################################################################################################

        __PUB__ template<typename T> bool __VARIABLE__ EQ(T __VARIABLE__ val1, T __VARIABLE__ val2) noexcept;
        __PUB__ template<typename T> bool __VARIABLE__ NE(T __VARIABLE__ val1, T __VARIABLE__ val2) noexcept;
        __PUB__ template<typename T> bool __VARIABLE__ GT(T __VARIABLE__ val1, T __VARIABLE__ val2) noexcept;
        __PUB__ template<typename T> bool __VARIABLE__ LT(T __VARIABLE__ val1, T __VARIABLE__ val2) noexcept;
    };

    template<typename T> bool tianyu::test::TestObject::EQ(T val1, T val2) noexcept
    {
        bool result = val1 == val2;

        this->SetState(result);
        return result;
    }

    template<typename T> bool tianyu::test::TestObject::NE(T val1, T val2) noexcept
    {
        bool result = val1 != val2;

        this->SetState(result);
        return result;
    }

    template<typename T> bool tianyu::test::TestObject::GT(T val1, T val2) noexcept
    {
        bool result = val1 > val2;

        this->SetState(result);
        return result;
    }

    template<typename T> bool tianyu::test::TestObject::LT(T val1, T val2) noexcept
    {
        bool result = val1 < val2;

        this->SetState(result);
        return result;
    }

    // test function
    // use a test function delegate to import a test item
    using TestDelegate = std::function<void __VARIABLE__(TestObject __REFERENCE__ tobj)>;

    __PREDEFINE__ class TestEntity;

    class TestFlow final : public virtual tianyu::TianyuObject, public virtual core::TestObjectBase
    {
        __PUB__         TestFlow
        (
            const ::string __VARIABLE__  flowName,
            TestEntity     __REFERENCE__ pentity,
            FILE           __POINTER__   file,
            int32          __VARIABLE__  level,
            bool           __VARIABLE__  console_print
        );
        __PUB__         TestFlow(const TestFlow __REFERENCE__ tf);
        __PUB__ virtual ~TestFlow() __override_func;

        __PUB__ void       __VARIABLE__ Skip();
        __PUB__ void       __VARIABLE__ Set();

        __PUB__ void       __VARIABLE__ Item
        (
            const ::string __VARIABLE__ item_name,
            TestDelegate   __VARIABLE__ item_delegate,
            bool           __VARIABLE__ expect_exception = false
        );
        __PUB__ void       __VARIABLE__ ItemException
        (
            const ::string __VARIABLE__ item_name,
            TestDelegate   __VARIABLE__ item_delegate
        );

        __PUB__ void       __VARIABLE__ Item
        (
            const char   __POINTER__  item_name,
            TestDelegate __VARIABLE__ item_delegate,
            bool         __VARIABLE__ expect_exception = false
        );
        __PUB__ void       __VARIABLE__ ItemException
        (
            const char   __POINTER__  item_name,
            TestDelegate __VARIABLE__ item_delegate
        );

        __PUB__ template<class exception_type>
            void __VARIABLE__ ItemException
            (
                const char   __POINTER__  item_name,
                TestDelegate __VARIABLE__ item_delegate
            );

        __PUB__ template<class exception_type>
            void __VARIABLE__ ItemException
            (
                const ::string __VARIABLE__ item_name,
                TestDelegate   __VARIABLE__ item_delegate
            );

        __PRI__ void       __VARIABLE__ Record(int32 __VARIABLE__ level = 0);
        __PRI__ void       __VARIABLE__ Record(const ::string __VARIABLE__ name, TestState __VARIABLE__ state);
        __PRI__ void       __VARIABLE__ EndRecord();
    };

    // flow test function
    // use a flow test function delegate to import a group of tests which are need to run
    // one by one and not assert any error.
    // if any error happened, the next tests of this flow will be skipped.
    using FlowDelegate = std::function<void __VARIABLE__(TestFlow __REFERENCE__ tobj)>;

    using TestSpecDelegate = std::function<void __VARIABLE__(TestEntity __REFERENCE__ entity)>;

    // test entity
    // as its name showing, each test should start a test entity to process the actual tests.
    // for each test group, test entity could be created multiable times and there are not
    // dependent with each other.
    class TestEntity final : public virtual tianyu::TianyuObject, public virtual core::TestObjectBase
    {
        __PRI__::string    __VARIABLE__  _LogFile;
        __PRI__ bool       __VARIABLE__  _LogOwner;
        __PRI__ bool       __VARIABLE__  _Asserted;
        __PRI__ int32      __VARIABLE__  _SuccessCount;
        __PRI__ int32      __VARIABLE__  _SkippedCount;
        __PRI__ int32      __VARIABLE__  _FailureCount;

        __PRI__         __construction__ TestEntity
        (
            const ::string __VARIABLE__  entityName,
            TestEntity     __REFERENCE__ pentity,
            FILE           __POINTER__   file,
            int32          __VARIABLE__  level,
            bool           __VARIABLE__  console_print
        );
        __PUB__         __construction__ TestEntity
        (
            const ::string __VARIABLE__ entityName,
            int32          __VARIABLE__ argc,
            char           __POINTER__  argv __ARRAY__
        );
        __PUB__         __cp_construct__ TestEntity(const TestEntity __REFERENCE__ entity);
        __PUB__ virtual __destruction__  ~TestEntity() __override_func;

        __PUB__ void       __VARIABLE__ SetAssert();
        __PUB__ void       __VARIABLE__ CancelAssert();

        __PUB__ void       __VARIABLE__ StartSpec(const ::string __VARIABLE__ entityName, TestSpecDelegate __VARIABLE__ spec);
        __PUB__ void       __VARIABLE__ StartSpec
        (
            const ::string   __VARIABLE__ entityName,
            TestSpecDelegate __VARIABLE__ spec,
            bool             __VARIABLE__ ignoreException
        );
        __PUB__ void       __VARIABLE__ StartSpec
        (
            const ::string   __VARIABLE__ entityName,
            TestSpecDelegate __VARIABLE__ spec,
            bool             __VARIABLE__ ignoreException,
            bool             __VARIABLE__ depPreState
        );
        __PUB__ void       __VARIABLE__ RunTest
        (
            const ::string __VARIABLE__ test_name,
            const ::string __VARIABLE__ test_description,
            TestDelegate   __VARIABLE__ test_item
        );
        __PUB__ void       __VARIABLE__ RunTest
        (
            const ::string __VARIABLE__ test_name,
            const ::string __VARIABLE__ test_description,
            TestDelegate   __VARIABLE__ test_item,
            bool           __VARIABLE__ ignore_exception
        );
        __PUB__ void       __VARIABLE__ RunExceptionTest
        (
            const ::string __VARIABLE__ test_name,
            const ::string __VARIABLE__ test_description,
            TestDelegate   __VARIABLE__ test_item
        );
        __PUB__ template<class exception_type> void __VARIABLE__ RunExceptionTest
        (
            const ::string __VARIABLE__ item_name,
            const ::string __VARIABLE__ test_description,
            TestDelegate   __VARIABLE__ item_delegate
        );
        __PUB__ void       __VARIABLE__ RunFlow
        (
            const ::string __VARIABLE__ flow_name,
            FlowDelegate   __VARIABLE__ test_flow
        );

        // ###################################################################################################################
        // const char* define
        // ###################################################################################################################

        __PRI__         __construction__ TestEntity
        (
            const char __POINTER__   entityName,
            TestEntity __REFERENCE__ pentity,
            FILE       __POINTER__   file,
            int32      __VARIABLE__  level,
            bool       __VARIABLE__  console_print
        );
        __PUB__         __construction__ TestEntity(const char __POINTER__ entityName, int32 __VARIABLE__ argc, char __POINTER__ argv __ARRAY__);

        __PUB__ void       __VARIABLE__ StartSpec(const char __POINTER__ entityName, TestSpecDelegate __VARIABLE__ spec);
        __PUB__ void       __VARIABLE__ StartSpec
        (
            const char       __POINTER__ entityName,
            TestSpecDelegate __VARIABLE__ spec,
            bool             __VARIABLE__ ignoreException
        );
        __PUB__ void       __VARIABLE__ StartSpec
        (
            const char       __POINTER__  entityName,
            TestSpecDelegate __VARIABLE__ spec,
            bool             __VARIABLE__ ignoreException,
            bool             __VARIABLE__ depPreState
        );

        __PUB__ void       __VARIABLE__ RunTest
        (
            const char   __POINTER__  test_name,
            const char   __POINTER__  test_description,
            TestDelegate __VARIABLE__ test_item
        );
        __PUB__ void       __VARIABLE__ RunTest
        (
            const char   __POINTER__  test_name,
            const char   __POINTER__  test_description,
            TestDelegate __VARIABLE__ test_item,
            bool         __VARIABLE__ ignore_exception
        );
        __PUB__ void       __VARIABLE__ RunExceptionTest
        (
            const char   __POINTER__  test_name,
            const char   __POINTER__  test_description,
            TestDelegate __VARIABLE__ test_item
        );
        __PUB__ template<class exception_type> void __VARIABLE__ RunExceptionTest
        (
            const char   __POINTER__  item_name,
            const char   __POINTER__  test_description,
            TestDelegate __VARIABLE__ item_delegate
        );
        __PUB__ void       __VARIABLE__ RunFlow
        (
            const char   __POINTER__  flow_name,
            FlowDelegate __VARIABLE__ test_flow
        );

        __PRI__ void       __VARIABLE__ NotifyState(TestState __VARIABLE__ state);
        __PRI__ void       __VARIABLE__ Record(int32 __VARIABLE__ level = 0);
        __PRI__ void       __VARIABLE__ Record(const ::string __VARIABLE__ name, const ::string __VARIABLE__ description, TestState __VARIABLE__ state);
        __PRI__ void       __VARIABLE__ EndRecord();
    };
}

#pragma region template function implementation

// Test Flow Part

template<class exception_type> void __VARIABLE__ tianyu::test::TestFlow::ItemException
(
    const ::string __VARIABLE__ item_name,
    TestDelegate   __VARIABLE__ item_delegate
)
{
    tianyu::test::TestObject tobj;

    if (this->GetState() != tianyu::test::TestState::Success)
        tobj.Skip();
    else
    {
        tobj.Set();
        try
        {
            item_delegate(tobj);
        }
        catch (exception_type& e)
        {
            tobj.Unset();
        }
        catch (...)
        {
            // exception check failed
            // not match the specified exception
        }

        this->_State = tobj.GetState();
    }

    this->Record(item_name, tobj.GetState());
}

template<class exception_type> void __VARIABLE__ tianyu::test::TestFlow::ItemException
(
    const char   __POINTER__  item_name,
    TestDelegate __VARIABLE__ item_delegate
)
{
    this->ItemException<exception_type>((const ::string)item_name, item_delegate);
}


// Test Entity Part

template<class exception_type> void __VARIABLE__ tianyu::test::TestEntity::RunExceptionTest
(
    const ::string __VARIABLE__ test_name,
    const ::string __VARIABLE__ test_description,
    TestDelegate   __VARIABLE__ test_item
)
{
    tianyu::test::TestObject tobj;

    if (this->_Asserted && this->GetState() != tianyu::test::TestState::Success)
    {
        tobj.Skip();
        ++this->_SkippedCount;
    }
    else
    {
        // set the default state is Failed
        tobj.Set();
        try
        {
            test_item(tobj);
        }
        catch (exception_type& e)
        {
            tobj.Unset();
        }
        catch (...)
        {
            // exception check failed
            // not match the specified exception
        }

        if (tianyu::test::TestState::Success == tobj.GetState())
            ++this->_SuccessCount;
        else
            ++this->_FailureCount;
    }

    this->NotifyState(tobj.GetState());
    this->Record(test_name, test_description, tobj.GetState());
}

template<class exception_type> void __VARIABLE__ tianyu::test::TestEntity::RunExceptionTest
(
    const char   __POINTER__  item_name,
    const char   __POINTER__  test_description,
    TestDelegate __VARIABLE__ item_delegate
)
{
    this->RunExceptionTest<exception_type>
        (
            (const ::string)item_name,
            (const ::string)test_description,
            item_delegate
        );
}

#pragma endregion

using TO = tianyu::test::TestObject;
using TD = tianyu::test::TestDelegate;
using TSD = tianyu::test::TestSpecDelegate;
using TFD = tianyu::test::FlowDelegate;
using TE = tianyu::test::TestEntity;
using TF = tianyu::test::TestFlow;
using TS = tianyu::test::TestState;
using TT = tianyu::test::TestType;
using N = const ::string;

#define TestsEntry_Main() \
    int32 __VARIABLE__ main(int32 __VARIABLE__ argc,char __POINTER__ argv __ARRAY__)

#define TestEntityCreator(entityName, entityDes) tianyu::test::TestEntity entityName(entityDes, argc, argv)

#define Test_Main_Return(testEntity) return (int32)(testEntity .GetState())

#define RUNTEST(testName, testDes)                                                                      \
    void TestEntry_TestRunner(tianyu::test::TestEntity&);                                               \
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
                case tianyu::test::_tianyu_test_entity_fail_param_too_few:                              \
                    std::cout << __TY_CORE_MSG_CONVERT(__ERROR_CPP_DTEST_AT_LEAST_ONE_PARAM__)          \
                              << std::endl;                                                             \
                    break;                                                                              \
                case tianyu::test::_tianyu_test_entity_fail_param_pre_more:                             \
                    std::cout << __TY_CORE_MSG_CONVERT(__ERROR_CPP_DTEST_WRONG_PARAM_PRE___)            \
                              << std::endl;                                                             \
                    break;                                                                              \
                case tianyu::test::_tianyu_test_entity_fail_file_open:                                  \
                    std::cout << __TY_CORE_MSG_CONVERT(__ERROR_CPP_DTEST_FILE_OPEN_FAILED__)            \
                              << std::endl;                                                             \
                    break;                                                                              \
                default:                                                                                \
                    std::cout << __TY_CORE_MSG_CONVERT(__ERROR_CPP_UNKNOWN_ERROR__) << std::endl;       \
                    break;                                                                              \
            }                                                                                           \
        }                                                                                               \
        catch(...)                                                                                      \
        {                                                                                               \
            std::cout << __TY_CORE_MSG_CONVERT(__ERROR_CPP_UNKNOWN_ERROR__) << std::endl;               \
        }                                                                                               \
        return -1;                                                                                      \
    }                                                                                                   \
    void TestEntry_TestRunner(tianyu::test::TestEntity& testName)

#define TEST_MAIN(des) RUNTEST(entity, (const ::string)des)

#define TEST_SPEC(specName, statements)                                                     \
    entity.StartSpec((const ::string)specName, [](tianyu::test::TestEntity& entity) -> void \
        statements                                                                          \
    )

#define TEST_ITEM(itemName, itemDes, statements)    \
    entity.RunTest(                                 \
        (const ::string)itemName,                   \
        (const ::string)itemDes,                    \
        [](tianyu::test::TestObject& tobj) -> void  \
        statements                                  \
    )

#endif // !__cplusplus

#endif // !__TIANYU_COMMON_NATIVE_TEST_CORE_HXX__