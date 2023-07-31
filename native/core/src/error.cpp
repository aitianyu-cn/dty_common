#include"../error.hpp"
#include<string>

#define __TIANYU_EXCEPT_NS__ tianyu::except

#pragma region Exception ID Macros
__CMODE__
{
    extern const uint64 __VARIABLE__ _tianyu_except_generic_exception;
    extern const uint64 __VARIABLE__ _tianyu_except_generic_nullPointerException;
    extern const uint64 __VARIABLE__ _tianyu_except_generic_arithmeticException;
    extern const uint64 __VARIABLE__ _tianyu_except_generic_indexOutOfRangeException;
    extern const uint64 __VARIABLE__ _tianyu_except_generic_notImplementationException;

    extern const uint64 __VARIABLE__ _tianyu_except_generic_argumentException;
    extern const uint64 __VARIABLE__ _tianyu_except_generic_argumentNullException;
    extern const uint64 __VARIABLE__ _tianyu_except_generic_argumentOutOfRangeException;

    extern const uint64 __VARIABLE__ _tianyu_except_generic_operationNotSupportException;

    extern const uint64 __VARIABLE__ _tianyu_except_generic_operationFailedException;
}
#pragma endregion

// #######################################################
// Tianyu Exception Base
// #######################################################

#pragma region Tianyu Exception Base
__TIANYU_EXCEPT_NS__::Exception::Exception()
    : tianyu::TianyuObject(),
    std::exception(),
    tianyu::collection::IEquatable<Exception>(),
    tianyu::collection::ICompareable<Exception>()
{ }

__TIANYU_EXCEPT_NS__::Exception::~Exception() { }

uint64 __TIANYU_EXCEPT_NS__::Exception::GetExceptionId()
{
    return _tianyu_except_generic_exception;
}
const char* __TIANYU_EXCEPT_NS__::Exception::what() const noexcept
{
    return std::exception::what();
}

::string __TIANYU_EXCEPT_NS__::Exception::ToString() noexcept
{
    return tianyu::_tianyu_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

uint64 __TIANYU_EXCEPT_NS__::Exception::GetTypeId()
{
    return tianyu::GetType(__PTR_TO_REF__ this).Id();
}

bool __TIANYU_EXCEPT_NS__::Exception::Equals(__TIANYU_EXCEPT_NS__::Exception& other)
{
    return (__PTR_TO_REF__ this) == other;
}

bool __TIANYU_EXCEPT_NS__::Exception::operator==(__TIANYU_EXCEPT_NS__::Exception& other)
{
    return this->GetExceptionId() == other.GetExceptionId();
}

bool __TIANYU_EXCEPT_NS__::Exception::operator!=(__TIANYU_EXCEPT_NS__::Exception& other)
{
    return this->GetExceptionId() != other.GetExceptionId();
}

tianyu::collection::CompareResult __TIANYU_EXCEPT_NS__::Exception::CompareTo(__TIANYU_EXCEPT_NS__::Exception& other)
{
    __TIANYU_EXCEPT_NS__::Exception& _this = (__PTR_TO_REF__ this);

    return _this == other
        ? tianyu::collection::CompareResult::EQUAL
        : _this > other
        ? tianyu::collection::CompareResult::GREAT
        : tianyu::collection::CompareResult::LESS;
}

bool __TIANYU_EXCEPT_NS__::Exception::operator<(__TIANYU_EXCEPT_NS__::Exception& other)
{
    return this->GetExceptionId() > other.GetExceptionId();
}

bool __TIANYU_EXCEPT_NS__::Exception::operator>(__TIANYU_EXCEPT_NS__::Exception& other)
{
    return this->GetExceptionId() < other.GetExceptionId();
}

bool __TIANYU_EXCEPT_NS__::Exception::operator<=(__TIANYU_EXCEPT_NS__::Exception& other)
{
    return this->GetExceptionId() >= other.GetExceptionId();
}

bool __TIANYU_EXCEPT_NS__::Exception::operator>=(__TIANYU_EXCEPT_NS__::Exception& other)
{
    return this->GetExceptionId() <= other.GetExceptionId();
}
#pragma endregion

// #######################################################
// Tianyu Null Pointer Exception
// #######################################################

#pragma region Tianyu Null Pointer Exception
__TIANYU_EXCEPT_NS__::NullPointerException::NullPointerException()
    : __TIANYU_EXCEPT_NS__::Exception()
{

}
__TIANYU_EXCEPT_NS__::NullPointerException::~NullPointerException()
{

}
uint64 __TIANYU_EXCEPT_NS__::NullPointerException::GetExceptionId()
{
    return _tianyu_except_generic_nullPointerException;
}
uint64 __TIANYU_EXCEPT_NS__::NullPointerException::GetTypeId()
{
    return tianyu::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Arithmetic Exception
// #######################################################

#pragma region Tianyu Arithmetic Exception
__TIANYU_EXCEPT_NS__::ArithmeticException::ArithmeticException()
    : __TIANYU_EXCEPT_NS__::Exception()
{

}
__TIANYU_EXCEPT_NS__::ArithmeticException::~ArithmeticException()
{

}
uint64 __TIANYU_EXCEPT_NS__::ArithmeticException::GetExceptionId()
{
    return _tianyu_except_generic_arithmeticException;
}
uint64 __TIANYU_EXCEPT_NS__::ArithmeticException::GetTypeId()
{
    return tianyu::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Index Out of Range Exception
// #######################################################

#pragma region Tianyu Index Out of Range Exception
__TIANYU_EXCEPT_NS__::IndexOutOfRangeException::IndexOutOfRangeException()
    : __TIANYU_EXCEPT_NS__::Exception()
{

}
__TIANYU_EXCEPT_NS__::IndexOutOfRangeException::~IndexOutOfRangeException()
{

}
uint64 __TIANYU_EXCEPT_NS__::IndexOutOfRangeException::GetExceptionId()
{
    return _tianyu_except_generic_indexOutOfRangeException;
}
uint64 __TIANYU_EXCEPT_NS__::IndexOutOfRangeException::GetTypeId()
{
    return tianyu::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Argument Exception
// #######################################################

#pragma region Tianyu Argument Exception
__TIANYU_EXCEPT_NS__::ArgumentException::ArgumentException()
    : __TIANYU_EXCEPT_NS__::Exception()
{

}
__TIANYU_EXCEPT_NS__::ArgumentException::~ArgumentException()
{

}
uint64 __TIANYU_EXCEPT_NS__::ArgumentException::GetExceptionId()
{
    return _tianyu_except_generic_argumentException;
}
uint64 __TIANYU_EXCEPT_NS__::ArgumentException::GetTypeId()
{
    return tianyu::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Argument Null Pointer Exception
// #######################################################

#pragma region Tianyu Argument Null Pointer Exception
__TIANYU_EXCEPT_NS__::ArgumentNullException::ArgumentNullException()
    : __TIANYU_EXCEPT_NS__::ArgumentException()
{

}
__TIANYU_EXCEPT_NS__::ArgumentNullException::~ArgumentNullException()
{

}
uint64 __TIANYU_EXCEPT_NS__::ArgumentNullException::GetExceptionId()
{
    return _tianyu_except_generic_argumentNullException;
}
uint64 __TIANYU_EXCEPT_NS__::ArgumentNullException::GetTypeId()
{
    return tianyu::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Argument Out of Range Exception
// #######################################################

#pragma region Tianyu Argument Out of Range Exception
__TIANYU_EXCEPT_NS__::ArgumentOutOfRangeException::ArgumentOutOfRangeException()
    : __TIANYU_EXCEPT_NS__::ArgumentException()
{

}
__TIANYU_EXCEPT_NS__::ArgumentOutOfRangeException::~ArgumentOutOfRangeException()
{

}
uint64 __TIANYU_EXCEPT_NS__::ArgumentOutOfRangeException::GetExceptionId()
{
    return _tianyu_except_generic_argumentOutOfRangeException;
}
uint64 __TIANYU_EXCEPT_NS__::ArgumentOutOfRangeException::GetTypeId()
{
    return tianyu::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Not Implementation Exception
// #######################################################

#pragma region Tianyu Not Implementation Exception
__TIANYU_EXCEPT_NS__::NotImplementationException::NotImplementationException()
    : __TIANYU_EXCEPT_NS__::Exception()
{

}
__TIANYU_EXCEPT_NS__::NotImplementationException::~NotImplementationException()
{

}
uint64 __TIANYU_EXCEPT_NS__::NotImplementationException::GetExceptionId()
{
    return _tianyu_except_generic_notImplementationException;
}
uint64 __TIANYU_EXCEPT_NS__::NotImplementationException::GetTypeId()
{
    return tianyu::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Operation Not Support Exception
// #######################################################

#pragma region Tianyu Operation Not Support Exception
__TIANYU_EXCEPT_NS__::OperationNotSupportException::OperationNotSupportException()
    : __TIANYU_EXCEPT_NS__::Exception()
{

}
__TIANYU_EXCEPT_NS__::OperationNotSupportException::~OperationNotSupportException()
{

}
uint64 __TIANYU_EXCEPT_NS__::OperationNotSupportException::GetExceptionId()
{
    return _tianyu_except_generic_operationNotSupportException;
}
uint64 __TIANYU_EXCEPT_NS__::OperationNotSupportException::GetTypeId()
{
    return tianyu::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Operation Failed Exception
// #######################################################

#pragma region Tianyu Operation Failed Exception
__TIANYU_EXCEPT_NS__::OperationFailedException::OperationFailedException()
    : __TIANYU_EXCEPT_NS__::Exception()
{

}
__TIANYU_EXCEPT_NS__::OperationFailedException::~OperationFailedException()
{

}
uint64 __TIANYU_EXCEPT_NS__::OperationFailedException::GetExceptionId()
{
    return _tianyu_except_generic_operationFailedException;
}
uint64 __TIANYU_EXCEPT_NS__::OperationFailedException::GetTypeId()
{
    return tianyu::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion
