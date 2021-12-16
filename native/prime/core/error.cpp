#include"./error.hpp"
#include<string>

using namespace dty::except;

#pragma region Tianyu Exception Base
Exception::Exception()
    : std::exception(),
    dty::collection::IEquatable<Exception>(),
    dty::collection::ICompareable<Exception>()
{

}

Exception::~Exception()
{

}

uint64 Exception::GetExceptionId()
{
    return DTY_Generic_Exception;
}
const char* Exception::what() const noexcept
{
    return std::exception::what();
}
string __VARIABLE__ Exception::ToString() noexcept
{
    return null;
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
#pragma endregion

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
#pragma endregion

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
#pragma endregion

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
#pragma endregion

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
#pragma endregion

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
#pragma endregion

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
#pragma endregion

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
#pragma endregion

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
#pragma endregion
