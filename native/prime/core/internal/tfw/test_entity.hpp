/**
 * @file test_entity.hpp
 * @author senyun.yao
 * @brief Tianyu native test framework common definitions
 * @version 0.1
 * @date 2021-12-27
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_COMMON_NATIVE_TEST_FRAME_TEST_ENTITY_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_TEST_FRAME_TEST_ENTITY_H_PLUS_PLUS__

#include "./common.h"
#include "stdio.h"

namespace dty::test
{
    _enum TestState : int32
    {
        Success = 0,
        Failed = -1,
        Aborted = -2
    };

    _enum TestType : int32
    {
        Skipped = 0,
        Expect = 1,
        Assert = 2
    };

    // Test Object
    // test object to provide the basic APIs for test result exporter and some expect/assert
    // operations.
    // each test item must to use the object to record the test progress.
    class TestObject final : public virtual dty::TianyuObject
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
        __PUB__ void __VARIABLE__ Unset();

        __PUB__ bool __VARIABLE__ IsNull(object __VARIABLE__ obj);
        __PUB__ bool __VARIABLE__ IsNull(dty::TianyuObject __REFERENCE__ obj);
        __PUB__ bool __VARIABLE__ IsNotNull(object __VARIABLE__ obj);
        __PUB__ bool __VARIABLE__ IsNotNull(dty::TianyuObject __REFERENCE__ obj);

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

        __PUB__ bool __VARIABLE__ EQ(dty::TianyuObject __REFERENCE__ val1, dty::TianyuObject __REFERENCE__ val2);
        __PUB__ bool __VARIABLE__ NE(dty::TianyuObject __REFERENCE__ val1, dty::TianyuObject __REFERENCE__ val2);
        __PUB__ bool __VARIABLE__ GT(dty::TianyuObject __REFERENCE__ val1, dty::TianyuObject __REFERENCE__ val2);
        __PUB__ bool __VARIABLE__ LT(dty::TianyuObject __REFERENCE__ val1, dty::TianyuObject __REFERENCE__ val2);

        // ##############################################################################################################
        // template expects and asserts
        // ##############################################################################################################

        __PUB__ template<typename T> bool __VARIABLE__ EQ(T __VARIABLE__ val1, T __VARIABLE__ val2) noexcept;
        __PUB__ template<typename T> bool __VARIABLE__ NE(T __VARIABLE__ val1, T __VARIABLE__ val2) noexcept;
        __PUB__ template<typename T> bool __VARIABLE__ GT(T __VARIABLE__ val1, T __VARIABLE__ val2) noexcept;
        __PUB__ template<typename T> bool __VARIABLE__ LT(T __VARIABLE__ val1, T __VARIABLE__ val2) noexcept;
    };

    // test function
    // use a test function delegate to import a test item
    using TestDelegate = void __VARIABLE__(__POINTER__)(TestObject __REFERENCE__ tobj);

    __PREDEFINE__ class TestEntity;

    using TestSpecDelegate = void __VARIABLE__(__POINTER__)(TestEntity __REFERENCE__ entity);

    // test entity
    // as its name showing, each test should start a test entity to process the actual tests.
    // for each test group, test entity could be created multiable times and there are not
    // dependent with each other.
    class TestEntity final : public virtual dty::TianyuObject
    {
        __PRI__ bool       __VARIABLE__  _ConsolePrint;
        __PRI__::string    __VARIABLE__  _EntityName;
        __PRI__::string    __VARIABLE__  _LogFile;
        __PRI__ FILE       __POINTER__   _LogStream;
        __PRI__ bool       __VARIABLE__  _LogOwner;
        __PRI__ TestState  __VARIABLE__  _State;
        __PRI__ bool       __VARIABLE__  _Asserted;
        __PRI__ int32      __VARIABLE__  _Level;
        __PRI__ int32      __VARIABLE__  _SuccessCount;
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

        __PUB__ TestState  __VARIABLE__ GetState();
        __PUB__ void       __VARIABLE__ StartSpec(const ::string __VARIABLE__ entityName, TestSpecDelegate __VARIABLE__ spec);
        __PUB__ void       __VARIABLE__ StartSpec
        (
            const ::string   __VARIABLE__ entityName,
            TestSpecDelegate __VARIABLE__ spec,
            bool             __VARIABLE__ ignoreException
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

        __PRI__ void       __VARIABLE__ NotifyState(TestState __VARIABLE__ state);
        __PRI__ void       __VARIABLE__ Record(int32 __VARIABLE__ level = 0);
        __PRI__ void       __VARIABLE__ Record(const ::string __VARIABLE__ name, const ::string __VARIABLE__ description, TestState __VARIABLE__ state);
        __PRI__ void       __VARIABLE__ EndRecord();
    };

    constexpr int32 _dty_test_entity_fail_param_too_few = -1;
    constexpr int32 _dty_test_entity_fail_param_pre_more = -2;
    constexpr int32 _dty_test_entity_fail_file_open = -3;
}

// ##################################################################################################
// class methods implementation
// ##################################################################################################

// TestObject part

#define TEST_OBJECT_DEF dty::test::TestObject

TEST_OBJECT_DEF::TestObject()
    : dty::TianyuObject(),
    _State(dty::test::TestState::Success)
{ }

TEST_OBJECT_DEF::~TestObject()
{ }

dty::test::TestState TEST_OBJECT_DEF::GetState()
{
    return this->_State;
}

void TEST_OBJECT_DEF::SetState(bool result)
{
    if (dty::test::TestState::Success == this->_State)
        this->_State = result
        ? dty::test::TestState::Success
        : dty::test::TestState::Failed;
}

void TEST_OBJECT_DEF::Set()
{
    this->_State = dty::test::TestState::Failed;
}

void TEST_OBJECT_DEF::Unset()
{
    this->_State = dty::test::TestState::Success;
}

bool TEST_OBJECT_DEF::IsNull(object obj)
{
    bool result = ::null == obj;

    this->SetState(result);
    return result;
}

bool TEST_OBJECT_DEF::IsNull(dty::TianyuObject& obj)
{
    bool result = dty::TianyuObject::IsNull(obj);

    this->SetState(result);
    return result;
}

bool TEST_OBJECT_DEF::IsNotNull(object obj)
{
    bool result = ::null != obj;

    this->SetState(result);
    return result;
}

bool TEST_OBJECT_DEF::IsNotNull(dty::TianyuObject& obj)
{
    bool result = !dty::TianyuObject::IsNull(obj);

    this->SetState(result);
    return result;
}

bool TEST_OBJECT_DEF::IsEmpty(const ::string str)
{
    bool result = ::null != str && ::strlen(str) == 0;

    this->SetState(result);
    return result;
}

bool TEST_OBJECT_DEF::IsNotEmpty(const ::string str)
{
    bool result = ::null != str && ::strlen(str) > 0;

    this->SetState(result);
    return result;
}

bool TEST_OBJECT_DEF::ToBeTrue(bool value)
{
    this->SetState(value);
    return value;
}

bool TEST_OBJECT_DEF::ToBeFalse(bool value)
{
    this->SetState(!value);
    return !value;
}

bool TEST_OBJECT_DEF::EQ(const ::string str1, const ::string str2)
{
    bool result = false;
    if (::null == str1 && ::null == str2)
        result = true;
    else if (::null == str1 || ::null == str2)
        result = false;
    else
    {
        int32 len1 = ::strlen(str1);
        int32 len2 = ::strlen(str2);

        if (len1 != len2)
            result = false;
        else
        {
            result = true;
            for (int32 i = 0; i < len1 && result; ++i)
                if (str1[i] != str2[i])
                    result = false;
        }
    }

    this->SetState(result);
    return result;
}

bool TEST_OBJECT_DEF::NE(const ::string str1, const ::string str2)
{
    bool result = false;
    if (::null == str1 && ::null == str2)
        result = false;
    else if (::null == str1 || ::null == str2)
        result = true;
    else
    {
        int32 len1 = ::strlen(str1);
        int32 len2 = ::strlen(str2);

        if (len1 != len2)
            result = true;
        else
        {
            result = false;
            for (int32 i = 0; i < len1 && !result; ++i)
                if (str1[i] != str2[i])
                    result = true;
        }
    }

    this->SetState(result);
    return result;
}

bool TEST_OBJECT_DEF::GT(const ::string str1, const ::string str2)
{
    bool result = false;
    if (::null == str1 && ::null == str2)
        result = false;
    else if (::null != str1 && ::null == str2)
        result = true;
    else if (::null == str1 && ::null != str2)
        result = false;
    else
    {
        int32 len1 = ::strlen(str1);
        int32 len2 = ::strlen(str2);

        int32 i = 0, j = 0;
        result = true;
        for (; i < len1 && j < len2 && result;++i, ++j)
            if (str1[i] <= str2[j])
                result = false;

        if (result && len1 != len2)
            result = len1 > len2;
    }

    this->SetState(result);
    return result;
}

bool TEST_OBJECT_DEF::LT(const ::string str1, const ::string str2)
{
    bool result = false;
    if (::null == str1 && ::null == str2)
        result = false;
    else if (::null != str1 && ::null == str2)
        result = false;
    else if (::null == str1 && ::null != str2)
        result = true;
    else
    {
        int32 len1 = ::strlen(str1);
        int32 len2 = ::strlen(str2);

        int32 i = 0, j = 0;
        result = true;
        for (; i < len1 && j < len2 && result;++i, ++j)
            if (str1[i] >= str2[j])
                result = false;

        if (result && len1 != len2)
            result = len1 < len2;
    }

    this->SetState(result);
    return result;
}

bool TEST_OBJECT_DEF::StrLenIs(const ::string str, int32 len)
{
    int32 strlen = ::null == str ? 0 : ::strlen(str);

    bool result = strlen == len;

    this->SetState(result);
    return result;
}

bool TEST_OBJECT_DEF::StrLenIsNot(const ::string str, int32 len)
{
    int32 strlen = ::null == str ? 0 : ::strlen(str);

    bool result = strlen != len;

    this->SetState(result);
    return result;
}

bool TEST_OBJECT_DEF::StrLenGT(const ::string str, int32 len)
{
    int32 strlen = ::null == str ? 0 : ::strlen(str);

    bool result = strlen > len;

    this->SetState(result);
    return result;
}

bool TEST_OBJECT_DEF::StrLenLT(const ::string str, int32 len)
{
    int32 strlen = ::null == str ? 0 : ::strlen(str);

    bool result = strlen < len;

    this->SetState(result);
    return result;
}

bool TEST_OBJECT_DEF::EQ(dty::TianyuObject& val1, dty::TianyuObject& val2)
{
    ::string str1 = val1.ToString();
    ::string str2 = val2.ToString();
    return this->EQ(str1, str2);
}

bool TEST_OBJECT_DEF::NE(dty::TianyuObject& val1, dty::TianyuObject& val2)
{
    ::string str1 = val1.ToString();
    ::string str2 = val2.ToString();
    return this->NE(str1, str2);
}

bool TEST_OBJECT_DEF::GT(dty::TianyuObject& val1, dty::TianyuObject& val2)
{
    ::string str1 = val1.ToString();
    ::string str2 = val2.ToString();
    return this->GT(str1, str2);
}

bool TEST_OBJECT_DEF::LT(dty::TianyuObject& val1, dty::TianyuObject& val2)
{
    ::string str1 = val1.ToString();
    ::string str2 = val2.ToString();
    return this->LT(str1, str2);
}

template<typename T> bool TEST_OBJECT_DEF::EQ(T val1, T val2) noexcept
{
    bool result = val1 == val2;

    this->SetState(result);
    return result;
}

template<typename T> bool TEST_OBJECT_DEF::NE(T val1, T val2) noexcept
{
    bool result = val1 != val2;

    this->SetState(result);
    return result;
}

template<typename T> bool TEST_OBJECT_DEF::GT(T val1, T val2) noexcept
{
    bool result = val1 > val2;

    this->SetState(result);
    return result;
}

template<typename T> bool TEST_OBJECT_DEF::LT(T val1, T val2) noexcept
{
    bool result = val1 < val2;

    this->SetState(result);
    return result;
}

#undef TEST_OBJECT_DEF

// TestEntity part

#define TEST_ENTITY_DEF dty::test::TestEntity

TEST_ENTITY_DEF::TestEntity(const ::string entityName, TEST_ENTITY_DEF& pentity, FILE* file, int32 level, bool console_print) :
    dty::TianyuObject(),
    _ConsolePrint(console_print),
    _LogFile(::null),
    _LogStream(file),
    _LogOwner(false),
    _State(dty::test::TestState::Success),
    _Asserted(false),
    _Level(level),
    _SuccessCount(0),
    _FailureCount(0)
{
    // process entity name
    if (::null == entityName)
        this->_EntityName = new char[1]{ '\0' };
    else
    {
        int32 ename_len = ::strlen(entityName);
        this->_EntityName = new char[ename_len + 1];
        for (int32 i = 0; i < ename_len; ++i)
            this->_EntityName[i] = entityName[i];
        this->_EntityName[ename_len] = '\0';
    }

    this->Record(level - 1);
}

TEST_ENTITY_DEF::TestEntity(const ::string entityName, int32 argc, char* argv []) :
    dty::TianyuObject(),
    _ConsolePrint(false),
    _LogOwner(true),
    _State(dty::test::TestState::Success),
    _Asserted(false),
    _Level(0),
    _SuccessCount(0),
    _FailureCount(0)
{
    if (2 > argc)
        throw dty::test::_dty_test_entity_fail_param_too_few;

    ::string file = argv[1];

    for (int32 i = 2; i < argc; ++i)
    {
        ::string param = argv[i];
        int32 parlen = ::strlen(argv[i]);

        if (0 == parlen)
            continue;

        int32 index = 0;
        // remove pre-char
        while ('-' == param[index])
            ++index;
        int32 preCh = index;
        if (3 <= preCh)
            throw dty::test::_dty_test_entity_fail_param_pre_more;

        if (index == parlen)
        {
            // empty param
            // todo: unassigned
        }

        switch (param[index])
        {
        case 'a':
        case 'A':
            this->_Asserted = true;
            break;
        case 'c':
        case 'C':
            this->_ConsolePrint = true;
            break;
        default:
            break;
        }
    }

#ifdef __DTY_WIN
    fopen_s(__VAR_TO_PTR__ this->_LogStream, file, "at+");
#else
    this->_LogStream = fopen(file, "at+");
#endif // __DTY_WIN
    if (::null == this->_LogStream)
        throw dty::test::_dty_test_entity_fail_file_open;

    // process entity name
    if (::null == entityName)
        this->_EntityName = new char[1]{ '\0' };
    else
    {
        int32 ename_len = ::strlen(entityName);
        this->_EntityName = new char[ename_len + 1];
        for (int32 i = 0; i < ename_len; ++i)
            this->_EntityName[i] = entityName[i];
        this->_EntityName[ename_len] = '\0';
    }

    // process file name
    int32 fname_len = ::strlen(file);
    this->_LogFile = new char[fname_len + 1];
    for (int32 i = 0; i < fname_len; ++i)
        this->_LogFile[i] = file[i];
    this->_LogFile[fname_len] = '\0';

    this->Record();
}

TEST_ENTITY_DEF::TestEntity(const TEST_ENTITY_DEF& entity) :
    dty::TianyuObject(),
    _ConsolePrint(entity._ConsolePrint),
    _EntityName(entity._EntityName),
    _LogFile(entity._LogFile),
    _LogStream(entity._LogStream),
    _LogOwner(entity._LogOwner),
    _State(entity._State),
    _Asserted(entity._Asserted),
    _Level(entity._Level),
    _SuccessCount(entity._SuccessCount),
    _FailureCount(entity._FailureCount)
{
    TEST_ENTITY_DEF& dynamic_obj = const_cast<TEST_ENTITY_DEF&>(entity);

    // copy means move
    // clean the pre object data
    dynamic_obj._EntityName = ::null;
    dynamic_obj._LogFile = ::null;
    dynamic_obj._LogStream = ::null;
}

TEST_ENTITY_DEF::~TestEntity()
{
    this->EndRecord();

    if (::null != this->_EntityName)
        delete [](this->_EntityName);

    if (::null != this->_LogFile)
        delete [](this->_LogFile);

    if (this->_LogOwner && ::null != this->_LogStream)
        fclose(this->_LogStream);
}

dty::test::TestState TEST_ENTITY_DEF::GetState()
{
    return this->_State;
}

void TEST_ENTITY_DEF::StartSpec(const ::string entityName, dty::test::TestSpecDelegate spec)
{
    this->StartSpec(entityName, spec, false);
}

void TEST_ENTITY_DEF::StartSpec(const ::string entityName, dty::test::TestSpecDelegate spec, bool ignoreException)
{
    TEST_ENTITY_DEF subEntity(entityName, __PTR_TO_REF__ this, this->_LogStream, this->_Level + 1, this->_ConsolePrint);

    try
    {
        spec(subEntity);
    }
    catch (...)
    {
        if (!ignoreException)
            subEntity._State = dty::test::TestState::Failed;
    }

    this->_SuccessCount += subEntity._SuccessCount;
    this->_FailureCount += subEntity._FailureCount;
    this->NotifyState(subEntity.GetState());
}

void TEST_ENTITY_DEF::RunTest(const ::string test_name, const ::string test_description, dty::test::TestDelegate test_item)
{
    dty::test::TestObject tobj;

    try
    {
        test_item(tobj);
    }
    catch (...)
    {
        tobj.Set();
    }

    dty::test::TestState state = tobj.GetState();
    if (dty::test::TestState::Success == state)
        ++this->_SuccessCount;
    else
        ++this->_FailureCount;

    this->NotifyState(tobj.GetState());
    this->Record(test_name, test_description, tobj.GetState());
}

void TEST_ENTITY_DEF::RunTest(const ::string test_name, const ::string test_description, dty::test::TestDelegate test_item, bool ignore_exception)
{
    dty::test::TestObject tobj;

    try
    {
        test_item(tobj);
    }
    catch (...)
    {
        if (!ignore_exception)
            tobj.Set();
    }

    dty::test::TestState state = tobj.GetState();
    if (dty::test::TestState::Success == state)
        ++this->_SuccessCount;
    else
        ++this->_FailureCount;

    this->NotifyState(state);
    this->Record(test_name, test_description, state);
}

void TEST_ENTITY_DEF::NotifyState(dty::test::TestState state)
{
    if (dty::test::TestState::Success == this->_State)
        this->_State = state;
}

void TEST_ENTITY_DEF::Record(int32 level)
{
    fputc('\n', this->_LogStream);
    for (int32 i = 0; i < level; ++i)
        fputs("  ", this->_LogStream);

    fputs(this->_EntityName, this->_LogStream);

    fflush(this->_LogStream);

    if (this->_ConsolePrint)
    {
        for (int32 i = 0; i < level; ++i)
            printf("  ");

        printf("%s\n", this->_EntityName);
    }
}

void TEST_ENTITY_DEF::Record(const ::string name, const ::string description, dty::test::TestState state)
{
    fputc('\n', this->_LogStream);
    for (int32 i = 0; i < this->_Level; ++i)
        fputs("  ", this->_LogStream);

    if (dty::test::TestState::Success == state)
        fputs("[SUCCESS] ", this->_LogStream);
    else
        fputs("[FAILED ] ", this->_LogStream);

    fputs("[", this->_LogStream);
    fputs(name, this->_LogStream);
    fputs("]: ", this->_LogStream);
    fputs(description, this->_LogStream);

    fflush(this->_LogStream);

    if (this->_ConsolePrint)
    {
        for (int32 i = 0; i < this->_Level; ++i)
            printf("  ");

        if (dty::test::TestState::Success == state)
            printf("\033[1;32;40m[SUCCESS] %s (%s) \033[0m\n", name, description);
        else
            printf("\033[1;31;40m[FAILED ] %s (%s) \033[0m\n", name, description);
    }
}

void TEST_ENTITY_DEF::EndRecord()
{
    fputc('\n', this->_LogStream);
    for (int32 i = 0; i < this->_Level; ++i)
        fputs("  ", this->_LogStream);

    fprintf(this->_LogStream, "Total: Success(%d)  Failed(%d)", this->_SuccessCount, this->_FailureCount);

    fflush(this->_LogStream);

    if (this->_ConsolePrint)
    {
        for (int32 i = 0; i < this->_Level; ++i)
            printf("  ");

        printf("Total: \033[1;32;40mSuccess(%d) \033[0m \033[1;31;40mFailed(%d)\033[0m\n", this->_SuccessCount, this->_FailureCount);
    }
}

#undef TEST_ENTITY_DEF

#endif // !__DTY_COMMON_NATIVE_TEST_FRAME_TEST_ENTITY_H_PLUS_PLUS__