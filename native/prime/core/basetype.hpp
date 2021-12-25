/**
 * @file basetype.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-23
 *
 * @copyright Copyright (c) 2021
 *
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.TB?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.byte?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.sbyte?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.int16?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.uint16?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.int32?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.uint32?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.int64?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.uint64?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.single?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.double?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean?view=net-6.0
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_BASETYPE_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_BASETYPE_H_PLUS_PLUS__

#ifdef __cplusplus

#include "./internal.h"
#include "./formatter.hpp"
#include "./property.hpp"

namespace dty
{
    template<class TB, TB _Max, TB _Min>
    class TIntegerBase final :
        public virtual dty::TianyuObject,
        public virtual dty::collection::ICompareable<TIntegerBase<TB, _Max, _Min>>,
        public virtual dty::collection::IEquatable<TIntegerBase<TB, _Max, _Min>>,
        public virtual dty::IFormatter
    {
        using CMPR = dty::collection::CompareResult;

        __PRI__ TB __VARIABLE__ _Value;

        __PUB__         __construction__ TIntegerBase();
        __PUB__         __construction__ TIntegerBase(TB __VARIABLE__ value);
        __PUB__         __cp_construct__ TIntegerBase(const TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ virtual __destruction__  ~TIntegerBase() __override_func;

        // ###################################################################################
        // operators __override_func (compared)
        // ###################################################################################
        __PUB__ virtual bool __VARIABLE__ Equals(TianyuObject __REFERENCE__ obj)     __override_func;
        __PUB__ virtual bool __VARIABLE__ operator==(TianyuObject __REFERENCE__ obj) __override_func;

        __PUB__ virtual bool __VARIABLE__ Equals(TIntegerBase<TB, _Max, _Min> __REFERENCE__ other)      __override_func;
        __PUB__ virtual CMPR __VARIABLE__ CompareTo(TIntegerBase<TB, _Max, _Min> __REFERENCE__ other)   __override_func;
        __PUB__ virtual bool __VARIABLE__ operator ==(TIntegerBase<TB, _Max, _Min> __REFERENCE__ other) __override_func;
        __PUB__ virtual bool __VARIABLE__ operator !=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ other) __override_func;
        __PUB__ virtual bool __VARIABLE__ operator <(TIntegerBase<TB, _Max, _Min> __REFERENCE__ other)  __override_func;
        __PUB__ virtual bool __VARIABLE__ operator >(TIntegerBase<TB, _Max, _Min> __REFERENCE__ other)  __override_func;
        __PUB__ virtual bool __VARIABLE__ operator <=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ other) __override_func;
        __PUB__ virtual bool __VARIABLE__ operator >=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ other) __override_func;

        // ###################################################################################
        // operators __override_func (calculated)
        // ###################################################################################
        __PUB__ operator TB();
        __PUB__ TB __VARIABLE__ operator ++();
        __PUB__ TB __VARIABLE__ operator --();
        __PUB__ TB __VARIABLE__ operator ++(int);
        __PUB__ TB __VARIABLE__ operator --(int);

        __PUB__ TB __VARIABLE__ operator +(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator -(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator *(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator /(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator %(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator !();
        __PUB__ TB __VARIABLE__ operator &(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator |(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator ~();
        __PUB__ TB __VARIABLE__ operator ^(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator <<(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator >>(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator =(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);

        __PUB__ TB __VARIABLE__ operator +=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator -=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator *=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator /=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator %=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator &=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator |=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator ^=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator <<=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator >>=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        // ###################################################################################
        // operators __override_func end
        // ###################################################################################

        __PUB__ virtual ::string __VARIABLE__ ToString(const ::string __VARIABLE__ formatter) __override_func;
        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;

        // static functions
        __PUB__ static TB   __VARIABLE__ Parse(const ::string __VARIABLE__ s);
        __PUB__ static bool __VARIABLE__ TryParse(const ::string __VARIABLE__ s, TB __REFERENCE__ result);
        __PUB__ static bool __VARIABLE__ TryParse(const ::string __VARIABLE__ s, TIntegerBase<TB, _Max, _Min> __REFERENCE__ result);

        // const values
        __PUB__ const TB    __VARIABLE__ MaxValue = _Max;
        __PUB__ const TB    __VARIABLE__ MinValue = _Min;
    };

    class Float final :
        public virtual dty::TianyuObject,
        public virtual dty::collection::ICompareable<Float>,
        public virtual dty::collection::IEquatable<Float>,
        public virtual dty::IFormatter
    {
        using CMPR = dty::collection::CompareResult;

        __PUB__ Property<double> __VARIABLE__ Precision;

        __PRI__ float __VARIABLE__ _Value;

        __PUB__         __construction__ Float();
        __PUB__         __construction__ Float(float __VARIABLE__ value, float __VARIABLE__ precision);
        __PUB__         __construction__ Float(float __VARIABLE__ value);
        __PUB__         __cp_construct__ Float(const Float __REFERENCE__ value);
        __PUB__ virtual __destruction__  ~Float() __override_func;

        // ###################################################################################
        // operators __override_func (compared)
        // ###################################################################################
        __PUB__ virtual bool __VARIABLE__ Equals(TianyuObject __REFERENCE__ obj)     __override_func;
        __PUB__ virtual bool __VARIABLE__ operator==(TianyuObject __REFERENCE__ obj) __override_func;

        __PUB__ virtual bool __VARIABLE__ Equals(Float __REFERENCE__ other)      __override_func;
        __PUB__ virtual CMPR __VARIABLE__ CompareTo(Float __REFERENCE__ other)   __override_func;
        __PUB__ virtual bool __VARIABLE__ operator ==(Float __REFERENCE__ other) __override_func;
        __PUB__ virtual bool __VARIABLE__ operator !=(Float __REFERENCE__ other) __override_func;
        __PUB__ virtual bool __VARIABLE__ operator <(Float __REFERENCE__ other)  __override_func;
        __PUB__ virtual bool __VARIABLE__ operator >(Float __REFERENCE__ other)  __override_func;
        __PUB__ virtual bool __VARIABLE__ operator <=(Float __REFERENCE__ other) __override_func;
        __PUB__ virtual bool __VARIABLE__ operator >=(Float __REFERENCE__ other) __override_func;

        // ###################################################################################
        // operators __override_func (calculated)
        // ###################################################################################
        __PUB__ operator float();
        __PUB__ float __VARIABLE__ operator ++();
        __PUB__ float __VARIABLE__ operator --();
        __PUB__ float __VARIABLE__ operator ++(int);
        __PUB__ float __VARIABLE__ operator --(int);

        __PUB__ float __VARIABLE__ operator +(Float __REFERENCE__ value);
        __PUB__ float __VARIABLE__ operator -(Float __REFERENCE__ value);
        __PUB__ float __VARIABLE__ operator *(Float __REFERENCE__ value);
        __PUB__ float __VARIABLE__ operator /(Float __REFERENCE__ value);
        __PUB__ float __VARIABLE__ operator %(Float __REFERENCE__ value);
        __PUB__ float __VARIABLE__ operator =(Float __REFERENCE__ value);

        __PUB__ float __VARIABLE__ operator +=(Float __REFERENCE__ value);
        __PUB__ float __VARIABLE__ operator -=(Float __REFERENCE__ value);
        __PUB__ float __VARIABLE__ operator *=(Float __REFERENCE__ value);
        __PUB__ float __VARIABLE__ operator /=(Float __REFERENCE__ value);
        __PUB__ float __VARIABLE__ operator %=(Float __REFERENCE__ value);
        // ###################################################################################
        // operators __override_func end
        // ###################################################################################

        __PUB__ virtual ::string __VARIABLE__ ToString(const ::string __VARIABLE__ formatter) __override_func;
        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;

        // static functions
        __PUB__ static float __VARIABLE__ Parse(const ::string __VARIABLE__ s);
        __PUB__ static bool  __VARIABLE__ TryParse(const ::string __VARIABLE__ s, float __REFERENCE__ result);
        __PUB__ static bool  __VARIABLE__ TryParse(const ::string __VARIABLE__ s, Float __REFERENCE__ result);

        // const values
        __PUB__ const float  __VARIABLE__ Epsilon = 1.401298E-45;
        __PUB__ const float  __VARIABLE__ MaxValue = 3.40282347E+38;
        __PUB__ const float  __VARIABLE__ MinValue = -3.40282347E+38;
    };

    class Double final :
        public virtual dty::TianyuObject,
        public virtual dty::collection::ICompareable<Double>,
        public virtual dty::collection::IEquatable<Double>,
        public virtual dty::IFormatter
    {
        using CMPR = dty::collection::CompareResult;

        __PUB__ Property<double> __VARIABLE__ Precision;

        __PRI__ double __VARIABLE__ _Value;

        __PUB__         __construction__ Double();
        __PUB__         __construction__ Double(double __VARIABLE__ value);
        __PUB__         __construction__ Double(double __VARIABLE__ value, double __VARIABLE__ precision);
        __PUB__         __cp_construct__ Double(const Double __REFERENCE__ value);
        __PUB__ virtual __destruction__  ~Double() __override_func;

        // ###################################################################################
        // operators __override_func (compared)
        // ###################################################################################
        __PUB__ virtual bool __VARIABLE__ Equals(TianyuObject __REFERENCE__ obj)     __override_func;
        __PUB__ virtual bool __VARIABLE__ operator==(TianyuObject __REFERENCE__ obj) __override_func;

        __PUB__ virtual bool __VARIABLE__ Equals(Double __REFERENCE__ other)      __override_func;
        __PUB__ virtual CMPR __VARIABLE__ CompareTo(Double __REFERENCE__ other)   __override_func;
        __PUB__ virtual bool __VARIABLE__ operator ==(Double __REFERENCE__ other) __override_func;
        __PUB__ virtual bool __VARIABLE__ operator !=(Double __REFERENCE__ other) __override_func;
        __PUB__ virtual bool __VARIABLE__ operator <(Double __REFERENCE__ other)  __override_func;
        __PUB__ virtual bool __VARIABLE__ operator >(Double __REFERENCE__ other)  __override_func;
        __PUB__ virtual bool __VARIABLE__ operator <=(Double __REFERENCE__ other) __override_func;
        __PUB__ virtual bool __VARIABLE__ operator >=(Double __REFERENCE__ other) __override_func;

        // ###################################################################################
        // operators __override_func (calculated)
        // ###################################################################################
        __PUB__ operator double();
        __PUB__ double __VARIABLE__ operator ++();
        __PUB__ double __VARIABLE__ operator --();
        __PUB__ double __VARIABLE__ operator ++(int);
        __PUB__ double __VARIABLE__ operator --(int);

        __PUB__ double __VARIABLE__ operator +(Double __REFERENCE__ value);
        __PUB__ double __VARIABLE__ operator -(Double __REFERENCE__ value);
        __PUB__ double __VARIABLE__ operator *(Double __REFERENCE__ value);
        __PUB__ double __VARIABLE__ operator /(Double __REFERENCE__ value);
        __PUB__ double __VARIABLE__ operator =(Double __REFERENCE__ value);

        __PUB__ double __VARIABLE__ operator +=(Double __REFERENCE__ value);
        __PUB__ double __VARIABLE__ operator -=(Double __REFERENCE__ value);
        __PUB__ double __VARIABLE__ operator *=(Double __REFERENCE__ value);
        __PUB__ double __VARIABLE__ operator /=(Double __REFERENCE__ value);
        // ###################################################################################
        // operators __override_func end
        // ###################################################################################

        __PUB__ virtual ::string __VARIABLE__ ToString(const ::string __VARIABLE__ formatter) __override_func;
        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;

        // static functions
        __PUB__ static double __VARIABLE__ Parse(const ::string __VARIABLE__ s);
        __PUB__ static bool   __VARIABLE__ TryParse(const ::string __VARIABLE__ s, double __REFERENCE__ result);
        __PUB__ static bool   __VARIABLE__ TryParse(const ::string __VARIABLE__ s, Double __REFERENCE__ result);

        // const values
        __PUB__ const double __VARIABLE__ Epsilon = 4.94065645841247E-324;
        __PUB__ const double __VARIABLE__ MaxValue = 1.7976931348623157E+308;
        __PUB__ const double __VARIABLE__ MinValue = -1.7976931348623157E+308;

    };

    class Boolean final :
        public virtual dty::TianyuObject,
        public virtual dty::collection::IEquatable<Boolean>,
        public virtual dty::IFormatter
    {
        using CMPR = dty::collection::CompareResult;

        __PRI__ bool __VARIABLE__ _Value;

        __PUB__         __construction__ Boolean();
        __PUB__         __construction__ Boolean(bool __VARIABLE__ value);
        __PUB__         __cp_construct__ Boolean(const Boolean __REFERENCE__ value);
        __PUB__ virtual __destruction__  ~Boolean() __override_func;

        // ###################################################################################
        // operators __override_func
        // ###################################################################################
        __PUB__ virtual bool __VARIABLE__ Equals(TianyuObject __REFERENCE__ obj)     __override_func;
        __PUB__ virtual bool __VARIABLE__ operator==(TianyuObject __REFERENCE__ obj) __override_func;

        __PUB__ virtual bool __VARIABLE__ Equals(Boolean __REFERENCE__ other)      __override_func;
        __PUB__ virtual bool __VARIABLE__ operator ==(Boolean __REFERENCE__ other) __override_func;
        __PUB__ virtual bool __VARIABLE__ operator !=(Boolean __REFERENCE__ other) __override_func;

        __PUB__ operator bool();
        __PUB__ operator int32();

        __PUB__ bool __VARIABLE__ operator !();
        __PUB__ bool __VARIABLE__ operator &&(Boolean __REFERENCE__ value);
        __PUB__ bool __VARIABLE__ operator ||(Boolean __REFERENCE__ value);
        __PUB__ bool __VARIABLE__ operator =(Boolean __REFERENCE__ value);
        // ###################################################################################
        // operators __override_func end
        // ###################################################################################

        __PUB__ virtual ::string __VARIABLE__ ToString(const ::string __VARIABLE__ formatter) __override_func;
        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;

        // static functions
        __PUB__ static bool __VARIABLE__ Parse(const ::string __VARIABLE__ s);
        __PUB__ static bool __VARIABLE__ TryParse(const ::string __VARIABLE__ s, bool __REFERENCE__ result);
        __PUB__ static bool __VARIABLE__ TryParse(const ::string __VARIABLE__ s, Boolean __REFERENCE__ result);

        // const values
        __PUB__ const bool  __VARIABLE__ MaxValue = true;
        __PUB__ const bool  __VARIABLE__ MinValue = false;
    };
}

// import implementation for integer base
#include "./res/basetype.cc"

namespace dty
{
    using Char = dty::TIntegerBase<char, __SIGNED_CHAR_MAX__, __SIGNED_CHAR_MIN__>;
    using UChar = dty::TIntegerBase<uchar, __UNSIGNED_CHAR_MAX__, __UNSIGNED_CHAR_MIN__>;

    using Byte = dty::TIntegerBase<byte, __UNSIGNED_CHAR_MAX__, __UNSIGNED_CHAR_MIN__>;
    using SByte = dty::TIntegerBase<sbyte, __SIGNED_CHAR_MAX__, __SIGNED_CHAR_MIN__>;

    using Int16 = dty::TIntegerBase<int16, __SIGNED_INT16_MAX__, __SIGNED_INT16_MIN__>;
    using UInt16 = dty::TIntegerBase<uint16, __UNSIGNED_INT16_MAX__, __UNSIGNED_INT16_MIN__>;

    using Short = dty::TIntegerBase<int16, __SIGNED_INT16_MAX__, __SIGNED_INT16_MIN__>;
    using UShort = dty::TIntegerBase<uint16, __UNSIGNED_INT16_MAX__, __UNSIGNED_INT16_MIN__>;

    using Int32 = dty::TIntegerBase<int32, __SIGNED_INT32_MAX__, __SIGNED_INT32_MIN__>;
    using UInt32 = dty::TIntegerBase<uint32, __UNSIGNED_INT32_MAX__, __UNSIGNED_INT32_MIN__>;

    using Int64 = dty::TIntegerBase<int64, __SIGNED_INT64_MAX__, __SIGNED_INT64_MIN__>;
    using UInt64 = dty::TIntegerBase<uint64, __UNSIGNED_INT64_MAX__, __UNSIGNED_INT64_MIN__>;

    using Long = dty::TIntegerBase<int64, __SIGNED_INT64_MAX__, __SIGNED_INT64_MIN__>;
    using ULong = dty::TIntegerBase<uint64, __UNSIGNED_INT64_MAX__, __UNSIGNED_INT64_MIN__>;
}

#endif // !__cplusplus

#endif // !__DTY_COMMON_NATIVE_PRIME_BASETYPE_H_PLUS_PLUS__