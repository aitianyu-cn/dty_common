/**
 * @file error.hpp(core)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-16
 * @date 2023-07-31
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __TIANYU_COMMON_NATIVE_CORE_ERROR_H_PLUS_PLUS__
#define __TIANYU_COMMON_NATIVE_CORE_ERROR_H_PLUS_PLUS__

#ifdef __cplusplus

#include "./internal.h"
#include <exception>

namespace tianyu::except
{
    class Exception :
        public virtual tianyu::TianyuObject,
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

#endif // !__TIANYU_COMMON_NATIVE_CORE_ERROR_H_PLUS_PLUS__