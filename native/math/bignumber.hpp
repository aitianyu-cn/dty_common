/**
 * @file bignumber.hpp(math)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2022-03-17
 *
 * @copyright aitianyu.cn Copyright (c) 2022
 *
 */

#ifndef __DTY_COMMON_NATIVE_MATH_MATHEMATIC_BIGNUMBER_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_MATH_MATHEMATIC_BIGNUMBER_H_PLUS_PLUS__

#include "./common.hpp"

namespace dty::math
{
    // pre-define for friend class
    __PREDEFINE__ class BigInteger;
    __PREDEFINE__ class BigDecimal;

    //
    // Big Number Class
    // provides calculations of big integer and decimal.
    // all of the calculating results are big number that provides fractional part
    //
    class BigNumber : public virtual TianyuObject
    {
        /**
         * @brief Create a new big number object that equals 0
         *
         */
        __PUB__         __construction__ BigNumber();
        /**
         * @brief Create a new big number object that equals specified 32bit value.
         *
         * @param value {int32} specified value
         */
        __PUB__         __construction__ BigNumber(int32 __VARIABLE__ value);
        /**
         * @brief Create a new big number object that equals specified 64bit value.
         *
         * @param value {int64} specified value
         */
        __PUB__         __construction__ BigNumber(int64 __VARIABLE__ value);
        /**
         * @brief Create a new big number object that equals specified 32bit unsigned value.
         *
         * @param value {uint32} specified value
         */
        __PUB__         __construction__ BigNumber(uint32 __VARIABLE__ value);
        /**
         * @brief Create a new big number object that equals specified 64bit unsigned value.
         *
         * @param value {uint64} specified value
         */
        __PUB__         __construction__ BigNumber(uint64 __VARIABLE__ value);
        /**
         * @brief Create a new big number object that equals specified 64bit decimal.
         *
         * @param value {double} specified value
         */
        __PUB__         __construction__ BigNumber(double __VARIABLE__ value);
        /**
         * @brief Create a new big number object that the data is parsed from specified string.
         *
         * @param value {::string} specified value
         */
        __PUB__         __construction__ BigNumber(::string __VARIABLE__ value);

        /**
         * @brief Create a new big number object that equals specifed big number.
         *
         * @note use macro-define: __DTY_MATH_BIGNUMBER_PERF__ to replace copy constructor to move constructor to improve the performance
         *
         * @param bigNumber {dty::math::BigNumber} specified object
         */
        __PUB__         __cp_construct__ BigNumber(const BigNumber __REFERENCE__ bigNumber);

        /**
         * @brief Destroy the big number
         *
         */
        __PUB__ virtual __destruction__ ~BigNumber() __override_func;

        __PUB__ bool __VARIABLE__ IsZero();
        __PUB__ bool __VARIABLE__ IsNegative();

        __PUB__ void __VARIABLE__ Copy(BigNumber __REFERENCE__ source);
        __PUB__ void __VARIABLE__ CopyTo(BigNumber __REFERENCE__ target);
        __PUB__ void __VARIABLE__ Move(BigNumber __REFERENCE__ source);
        __PUB__ void __VARIABLE__ MoveTo(BigNumber __REFERENCE__ target);

#pragma region self calculations
        __PUB__ void __VARIABLE__ Add(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Add(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Add(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Add(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Add(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Add(::string __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Add(BigNumber __REFERENCE__ value);

        __PUB__ void __VARIABLE__ Sub(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Sub(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Sub(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Sub(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Sub(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Sub(::string __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Sub(BigNumber __REFERENCE__ value);

        __PUB__ void __VARIABLE__ SubBy(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ SubBy(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ SubBy(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ SubBy(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ SubBy(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ SubBy(::string __VARIABLE__ value);
        __PUB__ void __VARIABLE__ SubBy(BigNumber __REFERENCE__ value);

        __PUB__ void __VARIABLE__ Mul(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mul(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mul(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mul(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mul(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mul(::string __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mul(BigNumber __REFERENCE__ value);

        __PUB__ void __VARIABLE__ Div(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Div(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Div(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Div(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Div(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Div(::string __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Div(BigNumber __REFERENCE__ value);

        __PUB__ void __VARIABLE__ DivBy(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ DivBy(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ DivBy(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ DivBy(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ DivBy(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ DivBy(::string __VARIABLE__ value);
        __PUB__ void __VARIABLE__ DivBy(BigNumber __REFERENCE__ value);

        __PRI__ void __VARIABLE__ Calculation(const char __VARIABLE__ calcType, BigNumber __REFERENCE__ value);
#pragma endregion

#pragma region operations override
        friend BigNumber __VARIABLE__ operator+ (BigNumber __REFERENCE__ op1, BigNumber __REFERENCE__ op2);
        friend BigNumber __VARIABLE__ operator- (BigNumber __REFERENCE__ op1, BigNumber __REFERENCE__ op2);
        friend BigNumber __VARIABLE__ operator* (BigNumber __REFERENCE__ op1, BigNumber __REFERENCE__ op2);
        friend BigNumber __VARIABLE__ operator/ (BigNumber __REFERENCE__ op1, BigNumber __REFERENCE__ op2);
#pragma endregion

        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;

        __PUB__ static BigNumber __VARIABLE__ E();
        __PUB__ static BigNumber __VARIABLE__ PI();
        __PUB__ static BigNumber __VARIABLE__ Tau();

        friend class BigInteger;
        friend class BigDecimal;
    };

    BigNumber __VARIABLE__ operator+ (BigNumber __REFERENCE__ op1, BigNumber __REFERENCE__ op2);
    BigNumber __VARIABLE__ operator- (BigNumber __REFERENCE__ op1, BigNumber __REFERENCE__ op2);
    BigNumber __VARIABLE__ operator* (BigNumber __REFERENCE__ op1, BigNumber __REFERENCE__ op2);
    BigNumber __VARIABLE__ operator/ (BigNumber __REFERENCE__ op1, BigNumber __REFERENCE__ op2);

    //
    // Big Integer Class
    // provides only integer calculations.
    // all of the calculating results are big integer that the fractional part is discarded.
    //
    class BigInteger : public virtual TianyuObject
    {
        __PRI__ byte  __POINTER__  _Bytes;
        __PRI__ int32 __VARIABLE__ _Actual;
        __PRI__ int32 __VARIABLE__ _Using;

        __PRI__ bool  __VARIABLE__ _Zero;
        __PRI__ bool  __VARIABLE__ _Neg;

        __PUB__         __construction__ BigInteger();
        __PUB__         __construction__ BigInteger(int32 __VARIABLE__ value);
        __PUB__         __construction__ BigInteger(int64 __VARIABLE__ value);
        __PUB__         __construction__ BigInteger(uint32 __VARIABLE__ value);
        __PUB__         __construction__ BigInteger(uint64 __VARIABLE__ value);
        __PUB__         __construction__ BigInteger(::string __VARIABLE__ value);
        __PUB__         __construction__ BigInteger(BigNumber __REFERENCE__ bigNumber);

        __PUB__         __cp_construct__ BigInteger(const BigInteger __REFERENCE__ bigNumber);

        __PUB__ virtual __destruction__ ~BigInteger() __override_func;

        __PUB__ bool __VARIABLE__ IsZero();
        __PUB__ bool __VARIABLE__ IsNegative();

        __PUB__ void __VARIABLE__ Copy(BigInteger __REFERENCE__ source);
        __PUB__ void __VARIABLE__ CopyTo(BigInteger __REFERENCE__ target);
        __PUB__ void __VARIABLE__ Move(BigInteger __REFERENCE__ source);
        __PUB__ void __VARIABLE__ MoveTo(BigInteger __REFERENCE__ target);

        __PUB__ BigNumber __VARIABLE__ ConvertTo();

#pragma region self calculations
        __PUB__ void __VARIABLE__ And(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ And(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ And(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ And(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ And(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ And(::string __VARIABLE__ value);
        __PUB__ void __VARIABLE__ And(BigNumber __REFERENCE__ value);
        __PUB__ void __VARIABLE__ And(BigInteger __REFERENCE__ value);

        __PUB__ void __VARIABLE__ Or(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Or(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Or(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Or(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Or(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Or(::string __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Or(BigNumber __REFERENCE__ value);
        __PUB__ void __VARIABLE__ Or(BigInteger __REFERENCE__ value);

        __PUB__ void __VARIABLE__ Xor(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Xor(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Xor(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Xor(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Xor(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Xor(::string __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Xor(BigNumber __REFERENCE__ value);
        __PUB__ void __VARIABLE__ Xor(BigInteger __REFERENCE__ value);

        __PUB__ void __VARIABLE__ Not();

        __PUB__ void __VARIABLE__ Add(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Add(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Add(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Add(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Add(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Add(::string __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Add(BigNumber __REFERENCE__ value);
        __PUB__ void __VARIABLE__ Add(BigInteger __REFERENCE__ value);

        __PUB__ void __VARIABLE__ Sub(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Sub(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Sub(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Sub(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Sub(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Sub(::string __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Sub(BigNumber __REFERENCE__ value);
        __PUB__ void __VARIABLE__ Sub(BigInteger __REFERENCE__ value);

        __PUB__ void __VARIABLE__ SubBy(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ SubBy(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ SubBy(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ SubBy(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ SubBy(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ SubBy(::string __VARIABLE__ value);
        __PUB__ void __VARIABLE__ SubBy(BigNumber __REFERENCE__ value);
        __PUB__ void __VARIABLE__ SubBy(BigInteger __REFERENCE__ value);

        __PUB__ void __VARIABLE__ Mul(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mul(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mul(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mul(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mul(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mul(::string __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mul(BigNumber __REFERENCE__ value);
        __PUB__ void __VARIABLE__ Mul(BigInteger __REFERENCE__ value);

        __PUB__ void __VARIABLE__ Div(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Div(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Div(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Div(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Div(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Div(::string __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Div(BigNumber __REFERENCE__ value);
        __PUB__ void __VARIABLE__ Div(BigInteger __REFERENCE__ value);

        __PUB__ void __VARIABLE__ DivBy(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ DivBy(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ DivBy(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ DivBy(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ DivBy(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ DivBy(::string __VARIABLE__ value);
        __PUB__ void __VARIABLE__ DivBy(BigNumber __REFERENCE__ value);
        __PUB__ void __VARIABLE__ DivBy(BigInteger __REFERENCE__ value);

        __PUB__ void __VARIABLE__ Mod(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mod(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mod(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mod(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mod(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mod(::string __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mod(BigNumber __REFERENCE__ value);
        __PUB__ void __VARIABLE__ Mod(BigInteger __REFERENCE__ value);

        __PUB__ void __VARIABLE__ ModBy(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ ModBy(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ ModBy(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ ModBy(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ ModBy(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ ModBy(::string __VARIABLE__ value);
        __PUB__ void __VARIABLE__ ModBy(BigNumber __REFERENCE__ value);
        __PUB__ void __VARIABLE__ ModBy(BigInteger __REFERENCE__ value);

        __PRI__ void __VARIABLE__ Calculation(const char __VARIABLE__ calcType, BigInteger __REFERENCE__ value);
#pragma endregion

#pragma region operations override
        friend BigInteger __VARIABLE__ operator+ (BigInteger __REFERENCE__ op1, BigInteger __REFERENCE__ op2);
        friend BigInteger __VARIABLE__ operator- (BigInteger __REFERENCE__ op1, BigInteger __REFERENCE__ op2);
        friend BigInteger __VARIABLE__ operator* (BigInteger __REFERENCE__ op1, BigInteger __REFERENCE__ op2);
        friend BigInteger __VARIABLE__ operator/ (BigInteger __REFERENCE__ op1, BigInteger __REFERENCE__ op2);
        friend BigInteger __VARIABLE__ operator% (BigInteger __REFERENCE__ op1, BigInteger __REFERENCE__ op2);
        friend BigInteger __VARIABLE__ operator& (BigInteger __REFERENCE__ op1, BigInteger __REFERENCE__ op2);
        friend BigInteger __VARIABLE__ operator| (BigInteger __REFERENCE__ op1, BigInteger __REFERENCE__ op2);
        friend BigInteger __VARIABLE__ operator^ (BigInteger __REFERENCE__ op1, BigInteger __REFERENCE__ op2);
        friend BigInteger __VARIABLE__ operator! (BigInteger __REFERENCE__ op1);
#pragma endregion

        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;
    };

    BigInteger __VARIABLE__ operator+ (BigInteger __REFERENCE__ op1, BigInteger __REFERENCE__ op2);
    BigInteger __VARIABLE__ operator- (BigInteger __REFERENCE__ op1, BigInteger __REFERENCE__ op2);
    BigInteger __VARIABLE__ operator* (BigInteger __REFERENCE__ op1, BigInteger __REFERENCE__ op2);
    BigInteger __VARIABLE__ operator/ (BigInteger __REFERENCE__ op1, BigInteger __REFERENCE__ op2);
    BigInteger __VARIABLE__ operator% (BigInteger __REFERENCE__ op1, BigInteger __REFERENCE__ op2);
    BigInteger __VARIABLE__ operator& (BigInteger __REFERENCE__ op1, BigInteger __REFERENCE__ op2);
    BigInteger __VARIABLE__ operator| (BigInteger __REFERENCE__ op1, BigInteger __REFERENCE__ op2);
    BigInteger __VARIABLE__ operator^ (BigInteger __REFERENCE__ op1, BigInteger __REFERENCE__ op2);
    BigInteger __VARIABLE__ operator! (BigInteger __REFERENCE__ op1);

    //
    // Big Decimal Class
    // floating point version for Big Number Class.
    // in order to enhance the performance, uses the floating point calculating ways to handle
    // big value.
    // Although this class is floating point type, the precision does not lose.
    //
    class BigDecimal : public virtual TianyuObject
    {
        __PUB__         __construction__ BigDecimal();
        __PUB__         __construction__ BigDecimal(int32 __VARIABLE__ value);
        __PUB__         __construction__ BigDecimal(int64 __VARIABLE__ value);
        __PUB__         __construction__ BigDecimal(uint32 __VARIABLE__ value);
        __PUB__         __construction__ BigDecimal(uint64 __VARIABLE__ value);
        __PUB__         __construction__ BigDecimal(float __VARIABLE__ value);
        __PUB__         __construction__ BigDecimal(double __VARIABLE__ value);
        __PUB__         __construction__ BigDecimal(::string __VARIABLE__ value);
        __PUB__         __construction__ BigDecimal(BigNumber __REFERENCE__ bigNumber);

        __PUB__         __cp_construct__ BigDecimal(const BigDecimal __REFERENCE__ bigNumber);

        __PUB__ virtual __destruction__ ~BigDecimal() __override_func;

        __PUB__ bool __VARIABLE__ IsZero();
        __PUB__ bool __VARIABLE__ IsNegative();

        __PUB__ void __VARIABLE__ Copy(BigDecimal __REFERENCE__ source);
        __PUB__ void __VARIABLE__ CopyTo(BigDecimal __REFERENCE__ target);
        __PUB__ void __VARIABLE__ Move(BigDecimal __REFERENCE__ source);
        __PUB__ void __VARIABLE__ MoveTo(BigDecimal __REFERENCE__ target);

        __PUB__ BigNumber __VARIABLE__ ConvertTo();

#pragma region self calculations
        __PUB__ void __VARIABLE__ Add(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Add(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Add(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Add(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Add(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Add(::string __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Add(BigNumber __REFERENCE__ value);
        __PUB__ void __VARIABLE__ Add(BigDecimal __REFERENCE__ value);

        __PUB__ void __VARIABLE__ Sub(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Sub(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Sub(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Sub(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Sub(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Sub(::string __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Sub(BigNumber __REFERENCE__ value);
        __PUB__ void __VARIABLE__ Sub(BigDecimal __REFERENCE__ value);

        __PUB__ void __VARIABLE__ SubBy(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ SubBy(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ SubBy(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ SubBy(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ SubBy(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ SubBy(::string __VARIABLE__ value);
        __PUB__ void __VARIABLE__ SubBy(BigNumber __REFERENCE__ value);
        __PUB__ void __VARIABLE__ SubBy(BigDecimal __REFERENCE__ value);

        __PUB__ void __VARIABLE__ Mul(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mul(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mul(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mul(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mul(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mul(::string __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Mul(BigNumber __REFERENCE__ value);
        __PUB__ void __VARIABLE__ Mul(BigDecimal __REFERENCE__ value);

        __PUB__ void __VARIABLE__ Div(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Div(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Div(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Div(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Div(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Div(::string __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Div(BigNumber __REFERENCE__ value);
        __PUB__ void __VARIABLE__ Div(BigDecimal __REFERENCE__ value);

        __PUB__ void __VARIABLE__ DivBy(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ DivBy(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ DivBy(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ DivBy(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ DivBy(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ DivBy(::string __VARIABLE__ value);
        __PUB__ void __VARIABLE__ DivBy(BigNumber __REFERENCE__ value);
        __PUB__ void __VARIABLE__ DivBy(BigDecimal __REFERENCE__ value);

        __PRI__ void __VARIABLE__ Calculation(const char __VARIABLE__ calcType, BigNumber __REFERENCE__ value);
#pragma endregion

#pragma region operations override
        friend BigDecimal __VARIABLE__ operator+ (BigDecimal __REFERENCE__ op1, BigDecimal __REFERENCE__ op2);
        friend BigDecimal __VARIABLE__ operator- (BigDecimal __REFERENCE__ op1, BigDecimal __REFERENCE__ op2);
        friend BigDecimal __VARIABLE__ operator* (BigDecimal __REFERENCE__ op1, BigDecimal __REFERENCE__ op2);
        friend BigDecimal __VARIABLE__ operator/ (BigDecimal __REFERENCE__ op1, BigDecimal __REFERENCE__ op2);
#pragma endregion

        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;
    };

    BigDecimal __VARIABLE__ operator+ (BigDecimal __REFERENCE__ op1, BigDecimal __REFERENCE__ op2);
    BigDecimal __VARIABLE__ operator- (BigDecimal __REFERENCE__ op1, BigDecimal __REFERENCE__ op2);
    BigDecimal __VARIABLE__ operator* (BigDecimal __REFERENCE__ op1, BigDecimal __REFERENCE__ op2);
    BigDecimal __VARIABLE__ operator/ (BigDecimal __REFERENCE__ op1, BigDecimal __REFERENCE__ op2);
}

#endif // !__DTY_COMMON_NATIVE_MATH_MATHEMATIC_BIGNUMBER_H_PLUS_PLUS__