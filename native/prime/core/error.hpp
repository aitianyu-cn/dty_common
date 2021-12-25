/**
 * @file error.hpp(prime/core)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-16
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_CORE_ERROR_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_CORE_ERROR_H_PLUS_PLUS__

#ifdef __cplusplus

#include "./internal.h"
#include <exception>

namespace dty::except
{
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

    class Exception :
        public virtual dty::TianyuObject,
        public virtual std::exception,
        public virtual collection::IEquatable<Exception>,
        public virtual collection::ICompareable<Exception>
    {
        __PUB__         Exception();
        __PUB__ virtual ~Exception() __override_func;

        __PUB__ virtual uint64     __VARIABLE__ GetExceptionId();
        __PUB__ virtual const char __POINTER__ what() const noexcept __override_func;

        __PUB__ virtual ::string   __VARIABLE__ ToString()  noexcept __override_func;
        __PUB__ virtual uint64     __VARIABLE__ GetTypeId() __override_func;

#pragma region Tianyu IEquatable Interface
        __PUB__ virtual bool __VARIABLE__ Equals(Exception __REFERENCE__ other)     __override_func;
        __PUB__ virtual bool __VARIABLE__ operator==(Exception __REFERENCE__ other) __override_func;
        __PUB__ virtual bool __VARIABLE__ operator!=(Exception __REFERENCE__ other) __override_func;
#pragma endregion
#pragma region Tianyu ICompareable Interface
        __PUB__ virtual collection::CompareResult __VARIABLE__ CompareTo(Exception __REFERENCE__ other)   __override_func;
        __PUB__ virtual bool                      __VARIABLE__ operator <(Exception __REFERENCE__ other)  __override_func;
        __PUB__ virtual bool                      __VARIABLE__ operator >(Exception __REFERENCE__ other)  __override_func;
        __PUB__ virtual bool                      __VARIABLE__ operator <=(Exception __REFERENCE__ other) __override_func;
        __PUB__ virtual bool                      __VARIABLE__ operator >=(Exception __REFERENCE__ other) __override_func;
#pragma endregion
    };

    class NullPointerException : public Exception
    {
        __PUB__         NullPointerException();
        __PUB__ virtual ~NullPointerException() __override_func;

#pragma region Tianyu Exception Base Function
        __PUB__ virtual uint64 __VARIABLE__ GetExceptionId() __override_func;
        __PUB__ virtual uint64 __VARIABLE__ GetTypeId()      __override_func;
#pragma endregion
    };

    class ArithmeticException : public Exception
    {
        __PUB__         ArithmeticException();
        __PUB__ virtual ~ArithmeticException() __override_func;

#pragma region Tianyu Exception Base Function
        __PUB__ virtual uint64 __VARIABLE__ GetExceptionId() __override_func;
        __PUB__ virtual uint64 __VARIABLE__ GetTypeId()      __override_func;
#pragma endregion
    };

    class IndexOutOfRangeException : public Exception
    {
        __PUB__         IndexOutOfRangeException();
        __PUB__ virtual ~IndexOutOfRangeException() __override_func;

#pragma region Tianyu Exception Base Function
        __PUB__ virtual uint64 __VARIABLE__ GetExceptionId() __override_func;
        __PUB__ virtual uint64 __VARIABLE__ GetTypeId()      __override_func;
#pragma endregion
    };

    class ArgumentException : public Exception
    {
        __PUB__         ArgumentException();
        __PUB__ virtual ~ArgumentException() __override_func;

#pragma region Tianyu Exception Base Function
        __PUB__ virtual uint64 __VARIABLE__ GetExceptionId() __override_func;
        __PUB__ virtual uint64 __VARIABLE__ GetTypeId()      __override_func;
#pragma endregion
    };

    class ArgumentNullException : public ArgumentException
    {
        __PUB__         ArgumentNullException();
        __PUB__ virtual ~ArgumentNullException() __override_func;

#pragma region Tianyu Exception Base Function
        __PUB__ virtual uint64 __VARIABLE__ GetExceptionId() __override_func;
        __PUB__ virtual uint64 __VARIABLE__ GetTypeId()      __override_func;
#pragma endregion
    };

    class ArgumentOutOfRangeException : public ArgumentException
    {
        __PUB__         ArgumentOutOfRangeException();
        __PUB__ virtual ~ArgumentOutOfRangeException() __override_func;

#pragma region Tianyu Exception Base Function
        __PUB__ virtual uint64 __VARIABLE__ GetExceptionId() __override_func;
        __PUB__ virtual uint64 __VARIABLE__ GetTypeId()      __override_func;
#pragma endregion
    };

    class NotImplementationException : public Exception
    {
        __PUB__         NotImplementationException();
        __PUB__ virtual ~NotImplementationException() __override_func;

#pragma region Tianyu Exception Base Function
        __PUB__ virtual uint64 __VARIABLE__ GetExceptionId() __override_func;
        __PUB__ virtual uint64 __VARIABLE__ GetTypeId()      __override_func;
#pragma endregion
    };

    class OperationNotSupportException : public Exception
    {
        __PUB__         OperationNotSupportException();
        __PUB__ virtual ~OperationNotSupportException() __override_func;

#pragma region Tianyu Exception Base Function
        __PUB__ virtual uint64 __VARIABLE__ GetExceptionId() __override_func;
        __PUB__ virtual uint64 __VARIABLE__ GetTypeId()      __override_func;
#pragma endregion
    };

    class OperationFailedException : public Exception
    {
        __PUB__         OperationFailedException();
        __PUB__ virtual ~OperationFailedException() __override_func;

#pragma region Tianyu Exception Base Function
        __PUB__ virtual uint64 __VARIABLE__ GetExceptionId() __override_func;
        __PUB__ virtual uint64 __VARIABLE__ GetTypeId()      __override_func;
#pragma endregion
    };
}

#endif // !__cplusplus

#endif // !__DTY_COMMON_NATIVE_PRIME_CORE_ERROR_H_PLUS_PLUS__