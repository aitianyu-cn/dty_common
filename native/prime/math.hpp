/**
 * @file math.hpp(prime)
 * @author victor.yao
 * @brief
 * @version 0.1
 * @date 2021-12-13
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.math?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.mathf?view=net-6.0
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_MATH_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_MATH_H_PLUS_PLUS__

#include "./core.hxx"

namespace dty
{
    class Math final
    {
        __PUB__ Math() = delete;

        __PUB__ const double __VARIABLE__ E;
        __PUB__ const double __VARIABLE__ PI;
        __PUB__ const double __VARIABLE__ Tau;

        __PUB__ static double  __VARIABLE__ Abs(double __VARIABLE__ x);
        __PUB__ static float   __VARIABLE__ Abs(float __VARIABLE__ x);
        __PUB__ static ::sbyte __VARIABLE__ Abs(::sbyte __VARIABLE__ x);
        __PUB__ static int16   __VARIABLE__ Abs(int16 __VARIABLE__ x);
        __PUB__ static int32   __VARIABLE__ Abs(int32 __VARIABLE__ x);
        __PUB__ static int64   __VARIABLE__ Abs(int64 __VARIABLE__ x);

        __PUB__ static double __VARIABLE__ Acos(double __VARIABLE__ x);
        __PUB__ static double __VARIABLE__ Acosh(double __VARIABLE__ x);
        __PUB__ static double __VARIABLE__ Asin(double __VARIABLE__ x);
        __PUB__ static double __VARIABLE__ Asinh(double __VARIABLE__ x);
        __PUB__ static double __VARIABLE__ Atan(double __VARIABLE__ x);
        __PUB__ static double __VARIABLE__ Atan2(double __VARIABLE__ y, double __VARIABLE__ x);
        __PUB__ static double __VARIABLE__ Atanh(double __VARIABLE__ x);

        __PUB__ static int64 __VARIABLE__ BigMul(int32 __VARIABLE__ x, int32 __VARIABLE__ y);
        __PUB__ static int64 __VARIABLE__ BigMul(int64 __VARIABLE__ x, int64 __VARIABLE__ y, int64 __REFERENCE__ low);
        __PUB__ static uint64 __VARIABLE__ BigMul(uint64 __VARIABLE__ x, uint64 __VARIABLE__ y, uint64 __REFERENCE__ low);

        __PUB__ static double __VARIABLE__ Cbrt(double __VARIABLE__ x);
        __PUB__ static double __VARIABLE__ Ceiling(double __VARIABLE__ x);
        __PUB__ static double __VARIABLE__ CopySign(double __VARIABLE__ x, double __VARIABLE__ y);
        __PUB__ static double __VARIABLE__ Cos(double __VARIABLE__ x);
        __PUB__ static double __VARIABLE__ Cosh(double __VARIABLE__ x);

        __PUB__ static int32 __VARIABLE__ DivRem(int32 __VARIABLE__ x, int32 __VARIABLE__ y, int32 __REFERENCE__ result);
        __PUB__ static int64 __VARIABLE__ DivRem(int64 __VARIABLE__ x, int64 __VARIABLE__ y, int64 __REFERENCE__ result);

        __PUB__ static double __VARIABLE__ Exp(double __VARIABLE__ x);
        __PUB__ static double __VARIABLE__ Floor(double __VARIABLE__ x);
        __PUB__ static double __VARIABLE__ FusedMultiplyAdd(double __VARIABLE__ x, double __VARIABLE__ y, double __VARIABLE__ z);
        __PUB__ static double __VARIABLE__ ILogB(double __VARIABLE__ x);
        __PUB__ static double __VARIABLE__ Log(double __VARIABLE__ x);
        __PUB__ static double __VARIABLE__ Log(double __VARIABLE__ x, double __VARIABLE__ y);
        __PUB__ static double __VARIABLE__ Log10(double __VARIABLE__ x);
        __PUB__ static double __VARIABLE__ Log2(double __VARIABLE__ x);

        __PUB__ static float   __VARIABLE__ Max(float __VARIABLE__ x, float __VARIABLE__ y);
        __PUB__ static double  __VARIABLE__ Max(double __VARIABLE__ x, double __VARIABLE__ y);
        __PUB__ static ::byte  __VARIABLE__ Max(::byte __VARIABLE__ x, ::byte __VARIABLE__ y);
        __PUB__ static ::sbyte __VARIABLE__ Max(::sbyte __VARIABLE__ x, ::sbyte __VARIABLE__ y);
        __PUB__ static int16   __VARIABLE__ Max(int16 __VARIABLE__ x, int16 __VARIABLE__ y);
        __PUB__ static int32   __VARIABLE__ Max(int32 __VARIABLE__ x, int32 __VARIABLE__ y);
        __PUB__ static int64   __VARIABLE__ Max(int64 __VARIABLE__ x, int64 __VARIABLE__ y);

        __PUB__ static float   __VARIABLE__ Min(float __VARIABLE__ x, float __VARIABLE__ y);
        __PUB__ static double  __VARIABLE__ Min(double __VARIABLE__ x, double __VARIABLE__ y);
        __PUB__ static ::byte  __VARIABLE__ Min(::byte __VARIABLE__ x, ::byte __VARIABLE__ y);
        __PUB__ static ::sbyte __VARIABLE__ Min(::sbyte __VARIABLE__ x, ::sbyte __VARIABLE__ y);
        __PUB__ static int16   __VARIABLE__ Min(int16 __VARIABLE__ x, int16 __VARIABLE__ y);
        __PUB__ static int32   __VARIABLE__ Min(int32 __VARIABLE__ x, int32 __VARIABLE__ y);
        __PUB__ static int64   __VARIABLE__ Min(int64 __VARIABLE__ x, int64 __VARIABLE__ y);

        __PUB__ static double __VARIABLE__ Pow(double __VARIABLE__ x, double __VARIABLE__ y);
        __PUB__ static double __VARIABLE__ Round(double __VARIABLE__ x);
        __PUB__ static double __VARIABLE__ Round(double __VARIABLE__ x, int32 __VARIABLE__ digits);
        __PUB__ static double __VARIABLE__ ScaleB(double __VARIABLE__ x, int32 __VARIABLE__ n);

        __PUB__ static int32 __VARIABLE__ Sign(float __VARIABLE__ x);
        __PUB__ static int32 __VARIABLE__ Sign(double __VARIABLE__ x);
        __PUB__ static int32 __VARIABLE__ Sign(::sbyte __VARIABLE__ x);
        __PUB__ static int32 __VARIABLE__ Sign(int16 __VARIABLE__ x);
        __PUB__ static int32 __VARIABLE__ Sign(int32 __VARIABLE__ x);
        __PUB__ static int32 __VARIABLE__ Sign(int64 __VARIABLE__ x);

        __PUB__ static double __VARIABLE__ Sin(double __VARIABLE__ x);
        __PUB__ static double __VARIABLE__ Sinh(double __VARIABLE__ x);
        __PUB__ static double __VARIABLE__ Sqrt(double __VARIABLE__ x);
        __PUB__ static double __VARIABLE__ Tan(double __VARIABLE__ x);
        __PUB__ static double __VARIABLE__ Tanh(double __VARIABLE__ x);
        __PUB__ static double __VARIABLE__ Truncate(double __VARIABLE__ x);
    };

    class MathF final
    {
        __PUB__ MathF() = delete;

        __PUB__ const float __VARIABLE__ E;
        __PUB__ const float __VARIABLE__ PI;
        __PUB__ const float __VARIABLE__ Tau;

        __PUB__ static float __VARIABLE__ Abs(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ Acos(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ Acosh(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ Asin(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ Asinh(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ Atan(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ Atan2(float __VARIABLE__ y, float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ Atanh(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ Cbrt(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ Ceiling(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ CopySign(float __VARIABLE__ x, float __VARIABLE__ y);
        __PUB__ static float __VARIABLE__ Cos(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ Cosh(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ Exp(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ Floor(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ FusedMultiplyAdd(float __VARIABLE__ x, float __VARIABLE__ y, float __VARIABLE__ z);
        __PUB__ static float __VARIABLE__ ILogB(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ Log(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ Log(float __VARIABLE__ x, float __VARIABLE__ y);
        __PUB__ static float __VARIABLE__ Log10(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ Log2(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ Max(float __VARIABLE__ x, float __VARIABLE__ y);
        __PUB__ static float __VARIABLE__ Min(float __VARIABLE__ x, float __VARIABLE__ y);
        __PUB__ static float __VARIABLE__ Pow(float __VARIABLE__ x, float __VARIABLE__ y);
        __PUB__ static float __VARIABLE__ Round(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ Round(float __VARIABLE__ x, int32 __VARIABLE__ digits);
        __PUB__ static float __VARIABLE__ ScaleB(float __VARIABLE__ x, int32 __VARIABLE__ n);
        __PUB__ static int32 __VARIABLE__ Sign(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ Sin(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ Sinh(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ Sqrt(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ Tan(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ Tanh(float __VARIABLE__ x);
        __PUB__ static float __VARIABLE__ Truncate(float __VARIABLE__ x);
    };
}

#endif // !__DTY_COMMON_NATIVE_PRIME_MATH_H_PLUS_PLUS__