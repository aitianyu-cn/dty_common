#include "./test-core.hxx"

// #################################################################################################
// #################################################################################################
// Tianyu Test Core Implementation
// #################################################################################################
// #################################################################################################
// ##################################################################################################
// class methods implementation
// ##################################################################################################

__CMODE__
{
    extern const int32 _tianyu_test_entity_fail_param_too_few;
    extern const int32 _tianyu_test_entity_fail_param_pre_more;
    extern const int32 _tianyu_test_entity_fail_file_open;
}

// TestObjectBase part
#pragma region TestObjectBase Part

#define TEST_OBJ_BASE_DEF tianyu::test::core::TestObjectBase

TEST_OBJ_BASE_DEF::TestObjectBase(bool consolePrint, tianyu::test::TestState state, FILE* file, int32 level)
    : tianyu::TianyuObject(),
    _ConsolePrint(consolePrint),
    _ObjectName(::null),
    _State(state),
    _LogStream(file),
    _Level(level)
{ }

TEST_OBJ_BASE_DEF::~TestObjectBase() { }

tianyu::test::TestState TEST_OBJ_BASE_DEF::GetState()
{
    return this->_State;
}

#undef TEST_OBJ_BASE_DEF

#pragma endregion

// TestObject part
#pragma region TestObject Part

#define TEST_OBJECT_DEF tianyu::test::TestObject

TEST_OBJECT_DEF::TestObject()
    : tianyu::TianyuObject(),
    _State(tianyu::test::TestState::Success)
{ }

TEST_OBJECT_DEF::~TestObject()
{ }

tianyu::test::TestState TEST_OBJECT_DEF::GetState()
{
    return this->_State;
}

void TEST_OBJECT_DEF::SetState(bool result)
{
    if (tianyu::test::TestState::Success == this->_State)
        this->_State = result
        ? tianyu::test::TestState::Success
        : tianyu::test::TestState::Failed;
}

void TEST_OBJECT_DEF::Set()
{
    this->_State = tianyu::test::TestState::Failed;
}

void TEST_OBJECT_DEF::Skip()
{
    this->_State = tianyu::test::TestState::Skipped;
}

void TEST_OBJECT_DEF::Unset()
{
    this->_State = tianyu::test::TestState::Success;
}

bool TEST_OBJECT_DEF::IsNull(object obj)
{
    bool result = ::null == obj;

    this->SetState(result);
    return result;
}

bool TEST_OBJECT_DEF::IsNull(tianyu::TianyuObject& obj)
{
    bool result = tianyu::TianyuObject::IsNull(obj);

    this->SetState(result);
    return result;
}

bool TEST_OBJECT_DEF::IsNotNull(object obj)
{
    bool result = ::null != obj;

    this->SetState(result);
    return result;
}

bool TEST_OBJECT_DEF::IsNotNull(tianyu::TianyuObject& obj)
{
    bool result = !tianyu::TianyuObject::IsNull(obj);

    this->SetState(result);
    return result;
}

bool TEST_OBJECT_DEF::IsEmpty(const ::string str)
{
    bool result = ::null != str && tianyu::strlen(str) == 0;

    this->SetState(result);
    return result;
}

bool TEST_OBJECT_DEF::IsNotEmpty(const ::string str)
{
    bool result = ::null != str && tianyu::strlen(str) > 0;

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
        int32 len1 = tianyu::strlen(str1);
        int32 len2 = tianyu::strlen(str2);

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
        int32 len1 = tianyu::strlen(str1);
        int32 len2 = tianyu::strlen(str2);

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
        int32 len1 = tianyu::strlen(str1);
        int32 len2 = tianyu::strlen(str2);

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
        int32 len1 = tianyu::strlen(str1);
        int32 len2 = tianyu::strlen(str2);

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
    int32 strlen = ::null == str ? 0 : tianyu::strlen(str);

    bool result = strlen == len;

    this->SetState(result);
    return result;
}

bool TEST_OBJECT_DEF::StrLenIsNot(const ::string str, int32 len)
{
    int32 strlen = ::null == str ? 0 : tianyu::strlen(str);

    bool result = strlen != len;

    this->SetState(result);
    return result;
}

bool TEST_OBJECT_DEF::StrLenGT(const ::string str, int32 len)
{
    int32 strlen = ::null == str ? 0 : tianyu::strlen(str);

    bool result = strlen > len;

    this->SetState(result);
    return result;
}

bool TEST_OBJECT_DEF::StrLenLT(const ::string str, int32 len)
{
    int32 strlen = ::null == str ? 0 : tianyu::strlen(str);

    bool result = strlen < len;

    this->SetState(result);
    return result;
}

bool TEST_OBJECT_DEF::EQ(tianyu::TianyuObject& val1, tianyu::TianyuObject& val2)
{
    ::string str1 = val1.ToString();
    ::string str2 = val2.ToString();
    return this->EQ(str1, str2);
}

bool TEST_OBJECT_DEF::NE(tianyu::TianyuObject& val1, tianyu::TianyuObject& val2)
{
    ::string str1 = val1.ToString();
    ::string str2 = val2.ToString();
    return this->NE(str1, str2);
}

bool TEST_OBJECT_DEF::GT(tianyu::TianyuObject& val1, tianyu::TianyuObject& val2)
{
    ::string str1 = val1.ToString();
    ::string str2 = val2.ToString();
    return this->GT(str1, str2);
}

bool TEST_OBJECT_DEF::LT(tianyu::TianyuObject& val1, tianyu::TianyuObject& val2)
{
    ::string str1 = val1.ToString();
    ::string str2 = val2.ToString();
    return this->LT(str1, str2);
}

#undef TEST_OBJECT_DEF

#pragma endregion

// TestEntity part
#pragma region TestEntity Part

#define TEST_ENTITY_DEF tianyu::test::TestEntity

TEST_ENTITY_DEF::TestEntity(const ::string entityName, TEST_ENTITY_DEF& pentity, FILE* file, int32 level, bool console_print) :
    tianyu::TianyuObject(),
    tianyu::test::core::TestObjectBase(console_print, tianyu::test::TestState::Success, file, level),
    _LogFile(::null),
    _LogOwner(false),
    _Asserted(false),
    _SuccessCount(0),
    _SkippedCount(0),
    _FailureCount(0)
{
    // process entity name
    if (::null == entityName)
        this->_ObjectName = new char[1] { '\0' };
    else
    {
        int32 ename_len = tianyu::strlen(entityName);
        this->_ObjectName = new char[ename_len + 1];
        for (int32 i = 0; i < ename_len; ++i)
            this->_ObjectName[i] = entityName[i];
        this->_ObjectName[ename_len] = '\0';
    }

    this->Record(level);
}

TEST_ENTITY_DEF::TestEntity(const char* entityName, TEST_ENTITY_DEF& pentity, FILE* file, int32 level, bool console_print) :
    tianyu::test::TestEntity((const ::string)entityName, pentity, file, level, console_print)
{ }

TEST_ENTITY_DEF::TestEntity(const char* entityName, int32 argc, char* argv []) :
    tianyu::test::TestEntity((const ::string)entityName, argc, argv)
{ }

TEST_ENTITY_DEF::TestEntity(const ::string entityName, int32 argc, char* argv []) :
    tianyu::TianyuObject(),
    tianyu::test::core::TestObjectBase(false, tianyu::test::TestState::Success, ::null, 0),
    _LogOwner(true),
    _Asserted(false),
    _SuccessCount(0),
    _SkippedCount(0),
    _FailureCount(0)
{
    if (2 > argc)
        throw _tianyu_test_entity_fail_param_too_few;

    ::string file = argv[1];

    bool is_log_overwrite = false;

    for (int32 i = 2; i < argc; ++i)
    {
        ::string param = argv[i];
        int32 parlen = tianyu::strlen(argv[i]);

        if (0 == parlen)
            continue;

        int32 index = 0;
        // remove pre-char
        while ('-' == param[index])
            ++index;
        int32 preCh = index;
        if (3 <= preCh)
            throw _tianyu_test_entity_fail_param_pre_more;

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
        case 'o':
        case 'O':
            is_log_overwrite = true;
            break;
        case 'l':
        case 'L':
            // Todo: to change the log type
            break;
        default:
            break;
        }
    }

    if (is_log_overwrite)
    {
#ifdef __DTY_WIN
        fopen_s(__VAR_TO_PTR__ this->_LogStream, file, "w+");
#else
        this->_LogStream = fopen(file, "w+");
#endif // __DTY_WIN
    }
    else
    {
#ifdef __DTY_WIN
        fopen_s(__VAR_TO_PTR__ this->_LogStream, file, "at+");
#else
        this->_LogStream = fopen(file, "at+");
#endif // __DTY_WIN
    }

    if (::null == this->_LogStream)
        throw _tianyu_test_entity_fail_file_open;

    // process entity name
    if (::null == entityName)
        this->_ObjectName = new char[1] { '\0' };
    else
    {
        int32 ename_len = tianyu::strlen(entityName);
        this->_ObjectName = new char[ename_len + 1];
        for (int32 i = 0; i < ename_len; ++i)
            this->_ObjectName[i] = entityName[i];
        this->_ObjectName[ename_len] = '\0';
    }

    // process file name
    int32 fname_len = tianyu::strlen(file);
    this->_LogFile = new char[fname_len + 1];
    for (int32 i = 0; i < fname_len; ++i)
        this->_LogFile[i] = file[i];
    this->_LogFile[fname_len] = '\0';

    this->Record();
}

TEST_ENTITY_DEF::TestEntity(const TEST_ENTITY_DEF& entity) :
    tianyu::TianyuObject(),
    tianyu::test::core::TestObjectBase(entity._ConsolePrint, entity._State, entity._LogStream, entity._Level),
    _LogFile(entity._LogFile),
    _LogOwner(entity._LogOwner),
    _Asserted(entity._Asserted),
    _SuccessCount(entity._SuccessCount),
    _SkippedCount(entity._SkippedCount),
    _FailureCount(entity._FailureCount)
{
    TEST_ENTITY_DEF& dynamic_obj = const_cast<TEST_ENTITY_DEF&>(entity);

    // move entity name
    this->_ObjectName = entity._ObjectName;

    // copy means move
    // clean the pre object data
    dynamic_obj._ObjectName = ::null;
    dynamic_obj._LogFile = ::null;
    dynamic_obj._LogStream = ::null;
}

TEST_ENTITY_DEF::~TestEntity()
{
    this->EndRecord();

    if (::null != this->_ObjectName)
        delete [](this->_ObjectName);

    if (::null != this->_LogFile)
        delete [](this->_LogFile);

    if (this->_LogOwner && ::null != this->_LogStream)
        fclose(this->_LogStream);
}

void TEST_ENTITY_DEF::SetAssert()
{
    this->_Asserted = true;
}

void TEST_ENTITY_DEF::CancelAssert()
{
    this->_Asserted = false;
}

void TEST_ENTITY_DEF::StartSpec(const ::string entityName, tianyu::test::TestSpecDelegate spec)
{
    this->StartSpec(entityName, spec, false);
}

void TEST_ENTITY_DEF::StartSpec(const ::string entityName, tianyu::test::TestSpecDelegate spec, bool ignoreException)
{
    this->StartSpec(entityName, spec, ignoreException, false);
}

void TEST_ENTITY_DEF::StartSpec(const ::string entityName, tianyu::test::TestSpecDelegate spec, bool ignoreException, bool depPreState)
{
    TEST_ENTITY_DEF subEntity(entityName, __PTR_TO_REF__ this, this->_LogStream, this->_Level + 1, this->_ConsolePrint);
    subEntity._Asserted = this->_Asserted;

    // should respect the father state
    if (depPreState)
        subEntity._State = this->_State;

    try
    {
        spec(subEntity);
    }
    catch (...)
    {
        if (!ignoreException)
            subEntity._State = tianyu::test::TestState::Failed;
    }

    this->_SuccessCount += subEntity._SuccessCount;
    this->_SkippedCount += subEntity._SkippedCount;
    this->_FailureCount += subEntity._FailureCount;
    this->NotifyState(subEntity.GetState());
}


void TEST_ENTITY_DEF::StartSpec(const char* entityName, tianyu::test::TestSpecDelegate spec)
{
    this->StartSpec((const ::string)entityName, spec, false);
}

void TEST_ENTITY_DEF::StartSpec(const char* entityName, tianyu::test::TestSpecDelegate spec, bool ignoreException)
{
    this->StartSpec((const ::string)entityName, spec, ignoreException, false);
}

void TEST_ENTITY_DEF::StartSpec(const char* entityName, tianyu::test::TestSpecDelegate spec, bool ignoreException, bool depPreState)
{
    this->StartSpec((const ::string)entityName, spec, ignoreException, depPreState);
}


void TEST_ENTITY_DEF::RunTest(const ::string test_name, const ::string test_description, tianyu::test::TestDelegate test_item)
{
    this->RunTest(test_name, test_description, test_item, false);
}

void TEST_ENTITY_DEF::RunTest(const ::string test_name, const ::string test_description, tianyu::test::TestDelegate test_item, bool ignore_exception)
{
    tianyu::test::TestObject tobj;

    if (this->_Asserted && this->GetState() != tianyu::test::TestState::Success)
    {
        tobj.Skip();
        ++this->_SkippedCount;
    }
    else
    {
        try
        {
            test_item(tobj);
        }
        catch (...)
        {
            if (!ignore_exception)
                tobj.Set();
        }

        if (tianyu::test::TestState::Success == tobj.GetState())
            ++this->_SuccessCount;
        else
            ++this->_FailureCount;
    }

    this->NotifyState(tobj.GetState());
    this->Record(test_name, test_description, tobj.GetState());
}

void TEST_ENTITY_DEF::RunExceptionTest(const ::string test_name, const ::string test_description, tianyu::test::TestDelegate test_item)
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
        catch (...)
        {
            tobj.Unset();
        }

        if (tianyu::test::TestState::Success == tobj.GetState())
            ++this->_SuccessCount;
        else
            ++this->_FailureCount;
    }

    this->NotifyState(tobj.GetState());
    this->Record(test_name, test_description, tobj.GetState());
}

void TEST_ENTITY_DEF::RunFlow(const ::string flow_name, tianyu::test::FlowDelegate test_flow)
{
    tianyu::test::TestFlow tflow(flow_name, __PTR_TO_REF__ this, this->_LogStream, this->_Level + 1, this->_ConsolePrint);

    if (this->_Asserted && this->GetState() != tianyu::test::TestState::Success)
    {
        tflow.Skip();
        ++this->_SkippedCount;
    }
    else
    {
        try
        {
            test_flow(tflow);
        }
        catch (...)
        {
            tflow.Set();
        }

        if (tianyu::test::TestState::Success == tflow.GetState())
            ++this->_SuccessCount;
        else
            ++this->_FailureCount;
    }

    this->NotifyState(tflow.GetState());
}

void TEST_ENTITY_DEF::RunTest(const char* test_name, const char* test_description, tianyu::test::TestDelegate test_item)
{
    this->RunTest((const ::string)test_name, (const ::string)test_description, test_item, false);
}

void TEST_ENTITY_DEF::RunTest(const char* test_name, const char* test_description, tianyu::test::TestDelegate test_item, bool ignore_exception)
{
    this->RunTest((const ::string)test_name, (const ::string)test_description, test_item, ignore_exception);
}

void TEST_ENTITY_DEF::RunExceptionTest(const char* test_name, const char* test_description, tianyu::test::TestDelegate test_item)
{
    this->RunExceptionTest((const ::string)test_name, (const ::string)test_description, test_item);
}

void TEST_ENTITY_DEF::RunFlow(const char* flow_name, tianyu::test::FlowDelegate test_flow)
{
    this->RunFlow((const ::string)flow_name, test_flow);
}

void TEST_ENTITY_DEF::NotifyState(tianyu::test::TestState state)
{
    if (tianyu::test::TestState::Success == this->_State)
        this->_State = state;
}

void TEST_ENTITY_DEF::Record(int32 level)
{
    fputc('\n', this->_LogStream);
    for (int32 i = 0; i < level; ++i)
        fputs("  ", this->_LogStream);

    fputs(this->_ObjectName, this->_LogStream);

    fflush(this->_LogStream);

    if (this->_ConsolePrint)
    {
        for (int32 i = 0; i < level; ++i)
            printf("  ");

        printf("%s\n", this->_ObjectName);

        fflush(stdin);
    }
}

void TEST_ENTITY_DEF::Record(const ::string name, const ::string description, tianyu::test::TestState state)
{
    fputc('\n', this->_LogStream);
    for (int32 i = 0; i <= this->_Level; ++i)
        fputs("  ", this->_LogStream);

    if (tianyu::test::TestState::Success == state)
        fputs(__TY_CORE_MSG_CONVERT(__DTY_TEST_CORE_SUCCESS_OUTPUT__), this->_LogStream);
    else if (tianyu::test::TestState::Skipped == state)
        fputs(__TY_CORE_MSG_CONVERT(__DTY_TEST_CORE_SKIPPED_OUTPUT__), this->_LogStream);
    else
        fputs(__TY_CORE_MSG_CONVERT(__DTY_TEST_CORE_FAILED_OUTPUT__), this->_LogStream);

    fputs(" ", this->_LogStream);
    fputs(name, this->_LogStream);
    fputs(" - ", this->_LogStream);
    fputs(description, this->_LogStream);

    fflush(this->_LogStream);

    if (this->_ConsolePrint)
    {
        for (int32 i = 0; i <= this->_Level; ++i)
            printf("  ");

        if (tianyu::test::TestState::Success == state)
            printf(__TY_CORE_MSG_CONVERT(__DTY_TEST_CORE_SUCCESS_CONSOLE_OUTPUT__), name, description);
        else if (tianyu::test::TestState::Skipped == state)
            printf(__TY_CORE_MSG_CONVERT(__DTY_TEST_CORE_SKIPPED_CONSOLE_OUTPUT__), name, description);
        else
            printf(__TY_CORE_MSG_CONVERT(__DTY_TEST_CORE_FAILED_CONSOLE_OUTPUT__), name, description);

        fflush(stdin);
    }
}

void TEST_ENTITY_DEF::EndRecord()
{
    fputc('\n', this->_LogStream);
    for (int32 i = 0; i < this->_Level; ++i)
        fputs("  ", this->_LogStream);

    fprintf(this->_LogStream, __TY_CORE_MSG_CONVERT(__DTY_TEST_CORE_TOTAL_COLLECTION__), this->_SuccessCount, this->_FailureCount, this->_SkippedCount);

    fflush(this->_LogStream);

    if (this->_ConsolePrint)
    {
        for (int32 i = 0; i < this->_Level; ++i)
            printf("  ");

        printf(__TY_CORE_MSG_CONVERT(__DTY_TEST_CORE_CONSOLE_TOTAL_COLLECTION__), this->_SuccessCount, this->_FailureCount, this->_SkippedCount);

        fflush(stdin);
    }
}

#undef TEST_ENTITY_DEF

#pragma endregion

// TestFlow part
#pragma region TestFlow Part

#define TEST_FLOW_DEF tianyu::test::TestFlow

TEST_FLOW_DEF::TestFlow
(
    const ::string flowName,
    tianyu::test::TestEntity& pentity,
    FILE* file,
    int32 level,
    bool console_printf
) :
    tianyu::TianyuObject(),
    tianyu::test::core::TestObjectBase(console_printf, tianyu::test::TestState::Success, file, level)
{
    if (::null == flowName)
        this->_ObjectName = new char[1] { '\0' };
    else
    {
        int32 name_len = tianyu::strlen(flowName);
        this->_ObjectName = new char[name_len + 1];
        for (int32 i = 0; i < name_len; ++i)
            this->_ObjectName[i] = flowName[i];
        this->_ObjectName[name_len] = '\0';
    }

    this->Record(this->_Level - 1);
}

TEST_FLOW_DEF::TestFlow(const TEST_FLOW_DEF& tf) :
    tianyu::TianyuObject(),
    tianyu::test::core::TestObjectBase(tf._ConsolePrint, tf._State, tf._LogStream, tf._Level)
{
    TEST_FLOW_DEF& dynamic_flow = const_cast<TEST_FLOW_DEF&>(tf);

    this->_ObjectName = dynamic_flow._ObjectName;

    dynamic_flow._ObjectName = ::null;
    dynamic_flow._LogStream = ::null;
}

TEST_FLOW_DEF::~TestFlow()
{
    this->EndRecord();

    delete [] this->_ObjectName;
}

void TEST_FLOW_DEF::Skip()
{
    this->_State = tianyu::test::TestState::Skipped;
}

void TEST_FLOW_DEF::Set()
{
    this->_State = tianyu::test::TestState::Failed;
}

void TEST_FLOW_DEF::Item(const ::string item_name, tianyu::test::TestDelegate item_delegate, bool ignore_exception)
{
    tianyu::test::TestObject tobj;

    if (this->GetState() != tianyu::test::TestState::Success)
        tobj.Skip();
    else
    {
        try
        {
            item_delegate(tobj);
        }
        catch (...)
        {
            if (!ignore_exception)
                tobj.Set();
        }

        this->_State = tobj.GetState();
    }

    this->Record(item_name, tobj.GetState());
}

void TEST_FLOW_DEF::ItemException(const ::string item_name, tianyu::test::TestDelegate item_delegate)
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
        catch (...)
        {
            tobj.Unset();
        }

        this->_State = tobj.GetState();
    }

    this->Record(item_name, tobj.GetState());
}

void TEST_FLOW_DEF::Item(const char* item_name, tianyu::test::TestDelegate item_delegate, bool ignore_exception)
{
    this->Item((const ::string)item_name, item_delegate, ignore_exception);
}

void TEST_FLOW_DEF::ItemException(const char* item_name, tianyu::test::TestDelegate item_delegate)
{
    this->ItemException((const ::string)item_name, item_delegate);
}

void TEST_FLOW_DEF::Record(int32 level)
{
    fputc('\n', this->_LogStream);
    for (int32 i = 0; i < level; ++i)
        fputs("  ", this->_LogStream);

    fputs(__TY_CORE_MSG_CONVERT(__DTY_TEST_CORE_FLOW_START__), this->_LogStream);
    fputs(" ", this->_LogStream);
    fputs(this->_ObjectName, this->_LogStream);

    fflush(this->_LogStream);

    if (this->_ConsolePrint)
    {
        for (int32 i = 0; i < level; ++i)
            printf("  ");

        printf(__TY_CORE_MSG_CONVERT(__DTY_TEST_CORE_CONSOLE_FLOW_START__));

        fflush(stdin);
    }
}

void TEST_FLOW_DEF::Record(const ::string name, tianyu::test::TestState state)
{
    fputc('\n', this->_LogStream);
    for (int32 i = 0; i < this->_Level; ++i)
        fputs("  ", this->_LogStream);

    if (tianyu::test::TestState::Success == state)
        fputs("V ", this->_LogStream);
    else if (tianyu::test::TestState::Skipped == state)
        fputs("  ", this->_LogStream);
    else
        fputs("X ", this->_LogStream);

    fputs(name, this->_LogStream);

    fflush(this->_LogStream);

    if (this->_ConsolePrint)
    {
        for (int32 i = 0; i < this->_Level; ++i)
            printf("  ");

        if (tianyu::test::TestState::Success == state)
            printf(__TY_CORE_MSG_CONVERT(__DTY_TEST_CORE_FLOW_SUCCESS_CONSOLE_OUTPUT__), name);
        else if (tianyu::test::TestState::Skipped == state)
            printf(__TY_CORE_MSG_CONVERT(__DTY_TEST_CORE_FLOW_SKIPPED_CONSOLE_OUTPUT__), name);
        else
            printf(__TY_CORE_MSG_CONVERT(__DTY_TEST_CORE_FLOW_FAILED_CONSOLE_OUTPUT__), name);

        fflush(stdin);
    }
}

void TEST_FLOW_DEF::EndRecord()
{
    putc('\n', this->_LogStream);
    for (int32 i = 0; i < this->_Level - 1; ++i)
        fputs("  ", this->_LogStream);

    if (tianyu::test::TestState::Success == this->_State)
        fputs(__TY_CORE_MSG_CONVERT(__DTY_TEST_CORE_SUCCESS_OUTPUT__), this->_LogStream);
    else if (tianyu::test::TestState::Skipped == this->_State)
        fputs(__TY_CORE_MSG_CONVERT(__DTY_TEST_CORE_SKIPPED_OUTPUT__), this->_LogStream);
    else
        fputs(__TY_CORE_MSG_CONVERT(__DTY_TEST_CORE_FAILED_OUTPUT__), this->_LogStream);

    fputs(__TY_CORE_MSG_CONVERT(__DTY_TEST_CORE_FLOW_END__), this->_LogStream);
    fputs(" ", this->_LogStream);
    fputs(this->_ObjectName, this->_LogStream);

    fflush(this->_LogStream);

    if (this->_ConsolePrint)
    {
        for (int32 i = 0; i < this->_Level - 1; ++i)
            printf("  ");

        if (tianyu::test::TestState::Success == this->_State)
            printf(__TY_CORE_MSG_CONVERT(__DTY_TEST_CORE_FLOW_END_CONSOLE_SUCCESS__), this->_ObjectName);
        else if (tianyu::test::TestState::Skipped == this->_State)
            printf(__TY_CORE_MSG_CONVERT(__DTY_TEST_CORE_FLOW_END_CONSOLE_SKIPPED__), this->_ObjectName);
        else
            printf(__TY_CORE_MSG_CONVERT(__DTY_TEST_CORE_FLOW_END_CONSOLE_FAILED__), this->_ObjectName);

        fflush(stdin);
    }
}

#undef TEST_FLOW_DEF

#pragma endregion