#include"./error.hpp"
#include<string>

using namespace dty::except;

// #######################################################
// Tianyu Exception Base
// #######################################################

#pragma region Tianyu Exception Base
Exception::Exception()
    : dty::TianyuObject(),
    std::exception(),
    dty::collection::IEquatable<Exception>(),
    dty::collection::ICompareable<Exception>()
{ }
Exception::~Exception() { }
uint64 Exception::GetExceptionId()
{
    return DTY_Generic_Exception;
}
const char* Exception::what() const noexcept
{
    return std::exception::what();
}
string Exception::ToString() noexcept
{
    return ::null;
}
uint64 Exception::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}
bool Exception::Equals(Exception& other)
{
    return (__PTR_TO_REF__ this) == other;
}
bool Exception::operator==(Exception& other)
{
    return this->GetExceptionId() == other.GetExceptionId();
}
bool Exception::operator!=(Exception& other)
{
    return this->GetExceptionId() != other.GetExceptionId();
}

dty::collection::CompareResult Exception::CompareTo(Exception& other)
{
    Exception& _this = (__PTR_TO_REF__ this);

    return _this == other
        ? dty::collection::CompareResult::EQUAL
        : _this > other
        ? dty::collection::CompareResult::GREAT
        : dty::collection::CompareResult::LESS;
}
bool Exception::operator<(Exception& other)
{
    return this->GetExceptionId() > other.GetExceptionId();
}
bool Exception::operator>(Exception& other)
{
    return this->GetExceptionId() < other.GetExceptionId();
}
bool Exception::operator<=(Exception& other)
{
    return this->GetExceptionId() >= other.GetExceptionId();
}
bool Exception::operator>=(Exception& other)
{
    return this->GetExceptionId() <= other.GetExceptionId();
}
#pragma endregion

// #######################################################
// Tianyu Null Pointer Exception
// #######################################################

#pragma region Tianyu Null Pointer Exception
NullPointerException::NullPointerException()
    : Exception()
{

}
NullPointerException::~NullPointerException()
{

}
uint64 NullPointerException::GetExceptionId()
{
    return DTY_Generic_NullPointerException;
}
uint64 NullPointerException::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Arithmetic Exception
// #######################################################

#pragma region Tianyu Arithmetic Exception
ArithmeticException::ArithmeticException()
    : Exception()
{

}
ArithmeticException::~ArithmeticException()
{

}
uint64 ArithmeticException::GetExceptionId()
{
    return DTY_Generic_ArithmeticException;
}
uint64 ArithmeticException::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Index Out of Range Exception
// #######################################################

#pragma region Tianyu Index Out of Range Exception
IndexOutOfRangeException::IndexOutOfRangeException()
    : Exception()
{

}
IndexOutOfRangeException::~IndexOutOfRangeException()
{

}
uint64 IndexOutOfRangeException::GetExceptionId()
{
    return DTY_Generic_IndexOutOfRangeException;
}
uint64 IndexOutOfRangeException::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Argument Exception
// #######################################################

#pragma region Tianyu Argument Exception
ArgumentException::ArgumentException()
    : Exception()
{

}
ArgumentException::~ArgumentException()
{

}
uint64 ArgumentException::GetExceptionId()
{
    return DTY_Generic_ArgumentException;
}
uint64 ArgumentException::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Argument Null Pointer Exception
// #######################################################

#pragma region Tianyu Argument Null Pointer Exception
ArgumentNullException::ArgumentNullException()
    : ArgumentException()
{

}
ArgumentNullException::~ArgumentNullException()
{

}
uint64 ArgumentNullException::GetExceptionId()
{
    return DTY_Generic_ArgumentNullException;
}
uint64 ArgumentNullException::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Argument Out of Range Exception
// #######################################################

#pragma region Tianyu Argument Out of Range Exception
ArgumentOutOfRangeException::ArgumentOutOfRangeException()
    : ArgumentException()
{

}
ArgumentOutOfRangeException::~ArgumentOutOfRangeException()
{

}
uint64 ArgumentOutOfRangeException::GetExceptionId()
{
    return DTY_Generic_ArgumentOutOfRangeException;
}
uint64 ArgumentOutOfRangeException::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Not Implementation Exception
// #######################################################

#pragma region Tianyu Not Implementation Exception
NotImplementationException::NotImplementationException()
    : Exception()
{

}
NotImplementationException::~NotImplementationException()
{

}
uint64 NotImplementationException::GetExceptionId()
{
    return DTY_Generic_NotImplementationException;
}
uint64 NotImplementationException::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Operation Not Support Exception
// #######################################################

#pragma region Tianyu Operation Not Support Exception
OperationNotSupportException::OperationNotSupportException()
    : Exception()
{

}
OperationNotSupportException::~OperationNotSupportException()
{

}
uint64 OperationNotSupportException::GetExceptionId()
{
    return DTY_Generic_OperationNotSupportException;
}
uint64 OperationNotSupportException::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Operation Failed Exception
// #######################################################

#pragma region Tianyu Operation Failed Exception
OperationFailedException::OperationFailedException()
    : Exception()
{

}
OperationFailedException::~OperationFailedException()
{

}
uint64 OperationFailedException::GetExceptionId()
{
    return DTY_Generic_OperationFailedException;
}
uint64 OperationFailedException::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion
