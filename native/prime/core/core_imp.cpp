/**
 * @file core_imp.cpp(prime/core)
 * @author ysydty
 * @brief C++ 本地方法导出模块的实现部分（公共模块）
 * @brief native export module, common module (implementation part)
 * @version 0.1
 * @date 2022-05-05
 *
 * @copyright aitianyu.cn Copyright (c) 2022
 *
 */

 //
// import all of the base libraries
#include "./arghelper.hpp"
#include "./basetype.hpp"
#include "./error.hpp"
#include "./event.hpp"
#include "./formatter.hpp"
#include "./icollections.hpp"
#include "./iterator.hpp"
#include "./pointer.hpp"
#include "./property.hpp"

// import common libraries
#include <math.h>

#pragma region base data type - boolean

#define __DOUBLE_OPERATOR__(ret, type, operate) \
    ret type::operator operate(type & value)    \
    {                                           \
      return this->_Value operate value._Value; \
    }

dty::Boolean::Boolean()
    : dty::TianyuObject(), dty::collection::IEquatable<dty::Boolean>(), dty::IFormatter(),
    _Value(false)
{ }

dty::Boolean::Boolean(bool value)
    : dty::TianyuObject(), dty::collection::IEquatable<dty::Boolean>(), dty::IFormatter(),
    _Value(value)
{ }

dty::Boolean::Boolean(const dty::Boolean& value)
    : dty::TianyuObject(), dty::collection::IEquatable<dty::Boolean>(), dty::IFormatter(),
    _Value(value._Value)
{ }

dty::Boolean::~Boolean() { }

bool dty::Boolean::Equals(dty::TianyuObject& obj)
{
    if (this->GetTypeId() != obj.GetTypeId())
        return false;

    dty::Boolean& cast_obj = dynamic_cast<dty::Boolean&>(obj);
    return this->Equals(cast_obj);
}

bool dty::Boolean::operator==(dty::TianyuObject& obj)
{
    return this->Equals(obj);
}

bool dty::Boolean::Equals(dty::Boolean& obj)
{
    return this->_Value == obj._Value;
}

dty::Boolean::operator bool()
{
    return this->_Value;
}

dty::Boolean::operator int32()
{
    return this->_Value ? 1 : 0;
}

bool dty::Boolean::operator!()
{
    return !(this->_Value);
}

::string dty::Boolean::ToString() noexcept
{
    return this->ToString(::null);
}

uint64 dty::Boolean::GetTypeId()
{
    return dty::GetType<dty::Boolean>().Id();
}

uint64 dty::Boolean::GetHashCode()
{
    return (uint64)(this);
}

::string dty::Boolean::ToString(const ::string formatter)
{
    return dty::FormatHelper::Format(this->_Value, formatter);
}

bool dty::Boolean::Parse(const ::string s)
{
    bool result;
    dty::ParseHelper::Parse(s, result);
    return result;
}

bool dty::Boolean::TryParse(const ::string s, bool& result)
{
    try
    {
        dty::ParseHelper::Parse(s, result);
        return true;
    }
    catch (dty::except::Exception)
    {
        return false;
    }
}

bool dty::Boolean::TryParse(const ::string s, dty::Boolean& result)
{
    try
    {
        dty::ParseHelper::Parse(s, result._Value);
        return true;
    }
    catch (dty::except::Exception)
    {
        return false;
    }
}

__DOUBLE_OPERATOR__(bool, dty::Boolean, == )
__DOUBLE_OPERATOR__(bool, dty::Boolean, != )
__DOUBLE_OPERATOR__(bool, dty::Boolean, &&)
__DOUBLE_OPERATOR__(bool, dty::Boolean, || )

#undef __DOUBLE_OPERATOR__

#pragma endregion

#pragma region base data type - double

const double _dty_native_double_default_precision = 1e-10;
const double _dty_native_double_zero = 0.0;

#define __DOUBLE_OPERATE__(ret, type)                   \
    ret dty::Double::operator type(dty::Double & other) \
    {                                                   \
        return this->_Value type other._Value;          \
    }

#define __DOUBLE_EQ_OPERATE__(ret, type)                \
    ret dty::Double::operator type(dty::Double & other) \
    {                                                   \
        this->_Value = this->_Value type other._Value;  \
        return this->_Value;                            \
    }

dty::Double::Double()
    :dty::TianyuObject(), dty::collection::ICompareable<dty::Double>(),
    dty::collection::IEquatable<dty::Double>(), dty::IFormatter(),
    Precision(_dty_native_double_default_precision), _Value()
{ }

dty::Double::Double(double value)
    : dty::TianyuObject(), dty::collection::ICompareable<dty::Double>(),
    dty::collection::IEquatable<dty::Double>(), dty::IFormatter(),
    Precision(_dty_native_double_default_precision), _Value(value)
{ }

dty::Double::Double(double value, double precision)
    : dty::TianyuObject(), dty::collection::ICompareable<dty::Double>(),
    dty::collection::IEquatable<dty::Double>(), dty::IFormatter(),
    Precision(precision), _Value(value)
{ }

dty::Double::Double(const dty::Double& value)
    : dty::TianyuObject(), dty::collection::ICompareable<dty::Double>(),
    dty::collection::IEquatable<dty::Double>(), dty::IFormatter(),
    Precision(value.Precision), _Value(value._Value)
{ }

dty::Double::~Double() { }

::string dty::Double::ToString() noexcept
{
    return this->ToString(::null);
}

uint64 dty::Double::GetTypeId()
{
    return dty::GetType<dty::Double>().Id();
}

uint64 dty::Double::GetHashCode()
{
    return (uint64)(this);
}

::string dty::Double::ToString(const ::string formatter)
{
    return dty::FormatHelper::Format(this->_Value, formatter);
}

double dty::Double::Parse(const ::string s)
{
    double result;
    dty::ParseHelper::Parse(s, result);
    return result;
}

bool dty::Double::TryParse(const ::string s, double& result)
{
    try
    {
        dty::ParseHelper::Parse(s, result);
        return true;
    }
    catch (dty::except::Exception)
    {
        return false;
    }
}

bool dty::Double::TryParse(const ::string s, dty::Double& result)
{
    try
    {
        dty::ParseHelper::Parse(s, result._Value);
        return true;
    }
    catch (dty::except::Exception)
    {
        return false;
    }
}

bool dty::Double::Equals(dty::TianyuObject& obj)
{
    if (this->GetTypeId() != obj.GetTypeId())
        return false;

    dty::Double& cast_obj = dynamic_cast<dty::Double&>(obj);
    return this->Equals(cast_obj);
}

bool dty::Double::operator==(dty::TianyuObject& obj)
{
    return this->Equals(obj);
}

bool dty::Double::Equals(dty::Double& other)
{
    double sub = this->_Value - other._Value;
    sub = ::fabs(sub);
    return sub < this->Precision;
}

bool dty::Double::operator==(dty::Double& other)
{
    return this->Equals(other);
}

bool dty::Double::operator==(dty::Double& other)
{
    return !(this->Equals(other));
}

bool dty::Double::operator<(dty::Double& other)
{
    return !(*this >= other);
}

bool dty::Double::operator>(dty::Double& other)
{
    return !(*this <= other);
}

bool dty::Double::operator<=(dty::Double& other)
{
    if (*this == other)
        return true;

    return this->_Value < other._Value;
}

bool dty::Double::operator>=(dty::Double& other)
{
    if (*this == other)
        return true;

    return this->_Value > other._Value;
}

dty::Double::operator double()
{
    return this->_Value;
}

double dty::Double::operator++()
{
    this->_Value = this->_Value + 1.0;
    return this->_Value;
}

double dty::Double::operator--()
{
    this->_Value = this->_Value - 1.0;
    return this->_Value;
}

double dty::Double::operator++(int)
{
    double preValue = this->_Value;
    this->_Value = this->_Value + 1.0;
    return preValue;
}

double dty::Double::operator--(int)
{
    double preValue = this->_Value;
    this->_Value = this->_Value - 1.0;
    return preValue;
}

double dty::Double::operator =(dty::Double& other)
{
    this->_Value = other._Value;
    return this->_Value;
}

__DOUBLE_OPERATE__(double, +)
__DOUBLE_OPERATE__(double, -)
__DOUBLE_OPERATE__(double, *)
__DOUBLE_OPERATE__(double, / )

__DOUBLE_EQ_OPERATE__(double, +=)
__DOUBLE_EQ_OPERATE__(double, -=)
__DOUBLE_EQ_OPERATE__(double, *=)
__DOUBLE_EQ_OPERATE__(double, /=)

#undef __DOUBLE_OPERATE__
#undef __DOUBLE_EQ_OPERATE__

#pragma endregion

#pragma region base data type - float

const float _dty_native_float_default_precision = 1e-5;
const float _dty_native_float_zero = 0.0;

#define __FLOAT_OPERATE__(ret, type)                   \
    ret dty::Float::operator type(dty::Float & other) \
    {                                                   \
        return this->_Value type other._Value;          \
    }

#define __FLOAT_EQ_OPERATE__(ret, type)                \
    ret dty::Float::operator type(dty::Float & other) \
    {                                                   \
        this->_Value = this->_Value type other._Value;  \
        return this->_Value;                            \
    }

dty::Float::Float()
    :dty::TianyuObject(), dty::collection::ICompareable<dty::Float>(),
    dty::collection::IEquatable<dty::Float>(), dty::IFormatter(),
    Precision(_dty_native_float_default_precision), _Value()
{ }

dty::Float::Float(float value)
    : dty::TianyuObject(), dty::collection::ICompareable<dty::Float>(),
    dty::collection::IEquatable<dty::Float>(), dty::IFormatter(),
    Precision(_dty_native_float_default_precision), _Value(value)
{ }

dty::Float::Float(float value, float precision)
    : dty::TianyuObject(), dty::collection::ICompareable<dty::Float>(),
    dty::collection::IEquatable<dty::Float>(), dty::IFormatter(),
    Precision(precision), _Value(value)
{ }

dty::Float::Float(const dty::Float& value)
    : dty::TianyuObject(), dty::collection::ICompareable<dty::Float>(),
    dty::collection::IEquatable<dty::Float>(), dty::IFormatter(),
    Precision(value.Precision), _Value(value._Value)
{ }

dty::Float::~Float() { }

::string dty::Float::ToString() noexcept
{
    return this->ToString(::null);
}

uint64 dty::Float::GetTypeId()
{
    return dty::GetType<dty::Float>().Id();
}

uint64 dty::Float::GetHashCode()
{
    return (uint64)(this);
}

::string dty::Float::ToString(const ::string formatter)
{
    return dty::FormatHelper::Format(this->_Value, formatter);
}

float dty::Float::Parse(const ::string s)
{
    float result;
    dty::ParseHelper::Parse(s, result);
    return result;
}

bool dty::Float::TryParse(const ::string s, float& result)
{
    try
    {
        dty::ParseHelper::Parse(s, result);
        return true;
    }
    catch (dty::except::Exception)
    {
        return false;
    }
}

bool dty::Float::TryParse(const ::string s, dty::Float& result)
{
    try
    {
        dty::ParseHelper::Parse(s, result._Value);
        return true;
    }
    catch (dty::except::Exception)
    {
        return false;
    }
}

bool dty::Float::Equals(dty::TianyuObject& obj)
{
    if (this->GetTypeId() != obj.GetTypeId())
        return false;

    dty::Float& cast_obj = dynamic_cast<dty::Float&>(obj);
    return this->Equals(cast_obj);
}

bool dty::Float::operator==(dty::TianyuObject& obj)
{
    return this->Equals(obj);
}

bool dty::Float::Equals(dty::Float& other)
{
    float sub = this->_Value - other._Value;
    sub = ::fabs(sub);
    return sub < this->Precision;
}

bool dty::Float::operator==(dty::Float& other)
{
    return this->Equals(other);
}

bool dty::Float::operator==(dty::Float& other)
{
    return !(this->Equals(other));
}

bool dty::Float::operator<(dty::Float& other)
{
    return !(*this >= other);
}

bool dty::Float::operator>(dty::Float& other)
{
    return !(*this <= other);
}

bool dty::Float::operator<=(dty::Float& other)
{
    if (*this == other)
        return true;

    return this->_Value < other._Value;
}

bool dty::Float::operator>=(dty::Float& other)
{
    if (*this == other)
        return true;

    return this->_Value > other._Value;
}

dty::Float::operator float()
{
    return this->_Value;
}

float dty::Float::operator++()
{
    this->_Value = this->_Value + 1.0;
    return this->_Value;
}

float dty::Float::operator--()
{
    this->_Value = this->_Value - 1.0;
    return this->_Value;
}

float dty::Float::operator++(int)
{
    float preValue = this->_Value;
    this->_Value = this->_Value + 1.0;
    return preValue;
}

float dty::Float::operator--(int)
{
    float preValue = this->_Value;
    this->_Value = this->_Value - 1.0;
    return preValue;
}

float dty::Float::operator =(dty::Float& other)
{
    this->_Value = other._Value;
    return this->_Value;
}

__FLOAT_OPERATE__(float, +)
__FLOAT_OPERATE__(float, -)
__FLOAT_OPERATE__(float, *)
__FLOAT_OPERATE__(float, / )

__FLOAT_EQ_OPERATE__(float, +=)
__FLOAT_EQ_OPERATE__(float, -=)
__FLOAT_EQ_OPERATE__(float, *=)
__FLOAT_EQ_OPERATE__(float, /=)

#undef __FLOAT_OPERATE__
#undef __FLOAT_EQ_OPERATE__

#pragma endregion

#pragma region event

dty::EventArgs::EventArgs() : dty::TianyuObject() { }

dty::EventArgs::~EventArgs() { }

::string dty::EventArgs::ToString() noexcept
{
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

uint64 dty::EventArgs::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

uint64 dty::EventArgs::GetHashCode()
{
    return (uint64)(this);
}

#pragma endregion

#pragma region errors

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

#undef __DTY_EXCEPT_NS__

#pragma endregion