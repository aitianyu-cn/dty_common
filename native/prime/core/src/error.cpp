#include"../error.hpp"
#include<string>

#define __DTY_EXCEPT_NS__ dty::except

#pragma region Exception ID Macros
constexpr uint64 __VARIABLE__ DTY_Generic_Exception = 0x0000000000000001ULL;
constexpr uint64 __VARIABLE__ DTY_Generic_NullPointerException = 0x0000000000000002ULL;
constexpr uint64 __VARIABLE__ DTY_Generic_ArithmeticException = 0x0000000000000003ULL;
constexpr uint64 __VARIABLE__ DTY_Generic_IndexOutOfRangeException = 0x0000000000000004ULL;
constexpr uint64 __VARIABLE__ DTY_Generic_NotImplementationException = 0x0000000000000005ULL;

constexpr uint64 __VARIABLE__ DTY_Generic_ArgumentException = 0x1000000000000001ULL;
constexpr uint64 __VARIABLE__ DTY_Generic_ArgumentNullException = 0x1000000000000002ULL;
constexpr uint64 __VARIABLE__ DTY_Generic_ArgumentOutOfRangeException = 0x1000000000000003ULL;

constexpr uint64 __VARIABLE__ DTY_Generic_OperationNotSupportException = 0x2000000000000001ULL;

constexpr uint64 __VARIABLE__ DTY_Generic_OperationFailedException = 0x3000000000000001ULL;
#pragma endregion

// #######################################################
// Tianyu Exception Base
// #######################################################

#pragma region Tianyu Exception Base
__DTY_EXCEPT_NS__::Exception::Exception()
    : dty::TianyuObject(),
    std::exception(),
    dty::collection::IEquatable<Exception>(),
    dty::collection::ICompareable<Exception>()
{ }

__DTY_EXCEPT_NS__::Exception::~Exception() { }

uint64 __DTY_EXCEPT_NS__::Exception::GetExceptionId()
{
    return DTY_Generic_Exception;
}
const char* __DTY_EXCEPT_NS__::Exception::what() const noexcept
{
    return std::exception::what();
}

::string __DTY_EXCEPT_NS__::Exception::ToString() noexcept
{
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

uint64 __DTY_EXCEPT_NS__::Exception::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

bool __DTY_EXCEPT_NS__::Exception::Equals(__DTY_EXCEPT_NS__::Exception& other)
{
    return (__PTR_TO_REF__ this) == other;
}

bool __DTY_EXCEPT_NS__::Exception::operator==(__DTY_EXCEPT_NS__::Exception& other)
{
    return this->GetExceptionId() == other.GetExceptionId();
}

bool __DTY_EXCEPT_NS__::Exception::operator!=(__DTY_EXCEPT_NS__::Exception& other)
{
    return this->GetExceptionId() != other.GetExceptionId();
}

dty::collection::CompareResult __DTY_EXCEPT_NS__::Exception::CompareTo(__DTY_EXCEPT_NS__::Exception& other)
{
    __DTY_EXCEPT_NS__::Exception& _this = (__PTR_TO_REF__ this);

    return _this == other
        ? dty::collection::CompareResult::EQUAL
        : _this > other
        ? dty::collection::CompareResult::GREAT
        : dty::collection::CompareResult::LESS;
}

bool __DTY_EXCEPT_NS__::Exception::operator<(__DTY_EXCEPT_NS__::Exception& other)
{
    return this->GetExceptionId() > other.GetExceptionId();
}

bool __DTY_EXCEPT_NS__::Exception::operator>(__DTY_EXCEPT_NS__::Exception& other)
{
    return this->GetExceptionId() < other.GetExceptionId();
}

bool __DTY_EXCEPT_NS__::Exception::operator<=(__DTY_EXCEPT_NS__::Exception& other)
{
    return this->GetExceptionId() >= other.GetExceptionId();
}

bool __DTY_EXCEPT_NS__::Exception::operator>=(__DTY_EXCEPT_NS__::Exception& other)
{
    return this->GetExceptionId() <= other.GetExceptionId();
}
#pragma endregion

// #######################################################
// Tianyu Null Pointer Exception
// #######################################################

#pragma region Tianyu Null Pointer Exception
__DTY_EXCEPT_NS__::NullPointerException::NullPointerException()
    : __DTY_EXCEPT_NS__::Exception()
{

}
__DTY_EXCEPT_NS__::NullPointerException::~NullPointerException()
{

}
uint64 __DTY_EXCEPT_NS__::NullPointerException::GetExceptionId()
{
    return DTY_Generic_NullPointerException;
}
uint64 __DTY_EXCEPT_NS__::NullPointerException::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Arithmetic Exception
// #######################################################

#pragma region Tianyu Arithmetic Exception
__DTY_EXCEPT_NS__::ArithmeticException::ArithmeticException()
    : __DTY_EXCEPT_NS__::Exception()
{

}
__DTY_EXCEPT_NS__::ArithmeticException::~ArithmeticException()
{

}
uint64 __DTY_EXCEPT_NS__::ArithmeticException::GetExceptionId()
{
    return DTY_Generic_ArithmeticException;
}
uint64 __DTY_EXCEPT_NS__::ArithmeticException::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Index Out of Range Exception
// #######################################################

#pragma region Tianyu Index Out of Range Exception
__DTY_EXCEPT_NS__::IndexOutOfRangeException::IndexOutOfRangeException()
    : __DTY_EXCEPT_NS__::Exception()
{

}
__DTY_EXCEPT_NS__::IndexOutOfRangeException::~IndexOutOfRangeException()
{

}
uint64 __DTY_EXCEPT_NS__::IndexOutOfRangeException::GetExceptionId()
{
    return DTY_Generic_IndexOutOfRangeException;
}
uint64 __DTY_EXCEPT_NS__::IndexOutOfRangeException::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Argument Exception
// #######################################################

#pragma region Tianyu Argument Exception
__DTY_EXCEPT_NS__::ArgumentException::ArgumentException()
    : __DTY_EXCEPT_NS__::Exception()
{

}
__DTY_EXCEPT_NS__::ArgumentException::~ArgumentException()
{

}
uint64 __DTY_EXCEPT_NS__::ArgumentException::GetExceptionId()
{
    return DTY_Generic_ArgumentException;
}
uint64 __DTY_EXCEPT_NS__::ArgumentException::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Argument Null Pointer Exception
// #######################################################

#pragma region Tianyu Argument Null Pointer Exception
__DTY_EXCEPT_NS__::ArgumentNullException::ArgumentNullException()
    : __DTY_EXCEPT_NS__::ArgumentException()
{

}
__DTY_EXCEPT_NS__::ArgumentNullException::~ArgumentNullException()
{

}
uint64 __DTY_EXCEPT_NS__::ArgumentNullException::GetExceptionId()
{
    return DTY_Generic_ArgumentNullException;
}
uint64 __DTY_EXCEPT_NS__::ArgumentNullException::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Argument Out of Range Exception
// #######################################################

#pragma region Tianyu Argument Out of Range Exception
__DTY_EXCEPT_NS__::ArgumentOutOfRangeException::ArgumentOutOfRangeException()
    : __DTY_EXCEPT_NS__::ArgumentException()
{

}
__DTY_EXCEPT_NS__::ArgumentOutOfRangeException::~ArgumentOutOfRangeException()
{

}
uint64 __DTY_EXCEPT_NS__::ArgumentOutOfRangeException::GetExceptionId()
{
    return DTY_Generic_ArgumentOutOfRangeException;
}
uint64 __DTY_EXCEPT_NS__::ArgumentOutOfRangeException::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Not Implementation Exception
// #######################################################

#pragma region Tianyu Not Implementation Exception
__DTY_EXCEPT_NS__::NotImplementationException::NotImplementationException()
    : __DTY_EXCEPT_NS__::Exception()
{

}
__DTY_EXCEPT_NS__::NotImplementationException::~NotImplementationException()
{

}
uint64 __DTY_EXCEPT_NS__::NotImplementationException::GetExceptionId()
{
    return DTY_Generic_NotImplementationException;
}
uint64 __DTY_EXCEPT_NS__::NotImplementationException::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Operation Not Support Exception
// #######################################################

#pragma region Tianyu Operation Not Support Exception
__DTY_EXCEPT_NS__::OperationNotSupportException::OperationNotSupportException()
    : __DTY_EXCEPT_NS__::Exception()
{

}
__DTY_EXCEPT_NS__::OperationNotSupportException::~OperationNotSupportException()
{

}
uint64 __DTY_EXCEPT_NS__::OperationNotSupportException::GetExceptionId()
{
    return DTY_Generic_OperationNotSupportException;
}
uint64 __DTY_EXCEPT_NS__::OperationNotSupportException::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion

// #######################################################
// Tianyu Operation Failed Exception
// #######################################################

#pragma region Tianyu Operation Failed Exception
__DTY_EXCEPT_NS__::OperationFailedException::OperationFailedException()
    : __DTY_EXCEPT_NS__::Exception()
{

}
__DTY_EXCEPT_NS__::OperationFailedException::~OperationFailedException()
{

}
uint64 __DTY_EXCEPT_NS__::OperationFailedException::GetExceptionId()
{
    return DTY_Generic_OperationFailedException;
}
uint64 __DTY_EXCEPT_NS__::OperationFailedException::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}
#pragma endregion
