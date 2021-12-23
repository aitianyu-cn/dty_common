/**
 * @file basetype.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-23
 *
 * @copyright Copyright (c) 2021
 *
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.char?view=net-6.0
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

#include "./core.hxx"

namespace dty
{
    class Char final : public virtual dty::TianyuObject, public virtual dty::IFormatter { };
    class UChar final : public virtual dty::TianyuObject, public virtual dty::IFormatter { };
    class Int8 final : public virtual dty::TianyuObject, public virtual dty::IFormatter { };
    class UInt8 final : public virtual dty::TianyuObject, public virtual dty::IFormatter { };
    class Int16 final : public virtual dty::TianyuObject, public virtual dty::IFormatter { };
    class UInt16 final : public virtual dty::TianyuObject, public virtual dty::IFormatter { };

    class Int32 final
        : public virtual dty::TianyuObject,
        public virtual dty::collection::ICompareable<Int32>,
        public virtual dty::collection::IEquatable<Int32>,
        public virtual dty::IFormatter
    {
        using CMPR = dty::collection::CompareResult;

        __PRI__ int32 __VARIABLE__ _Value;

        __PUB__ Int32();
        __PUB__ Int32(int32 __VARIABLE__ value);
        __PUB__ Int32(const Int32 __REFERENCE__ value);
        __PUB__ virtual ~Int32() override;

        __PUB__ virtual bool __VARIABLE__ Equals(TianyuObject __REFERENCE__ obj) override;
        __PUB__ virtual bool __VARIABLE__ operator==(TianyuObject __REFERENCE__ obj) override;

        __PUB__ virtual bool __VARIABLE__ Equals(Int32 __REFERENCE__ other) override;
        __PUB__ virtual CMPR __VARIABLE__ CompareTo(Int32 __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator ==(Int32 __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator !=(Int32 __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator <(Int32 __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator >(Int32 __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator <=(Int32 __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator >=(Int32 __REFERENCE__ other) override;

        __PUB__ operator int32();
        __PUB__ int32 __VARIABLE__ operator ++();
        __PUB__ int32 __VARIABLE__ operator --();
        __PUB__ int32 __VARIABLE__ operator ++(int);
        __PUB__ int32 __VARIABLE__ operator --(int);

        __PUB__ int32 __VARIABLE__ operator +(Int32 __REFERENCE__ value);
        __PUB__ int32 __VARIABLE__ operator -(Int32 __REFERENCE__ value);
        __PUB__ int32 __VARIABLE__ operator *(Int32 __REFERENCE__ value);
        __PUB__ int32 __VARIABLE__ operator /(Int32 __REFERENCE__ value);
        __PUB__ int32 __VARIABLE__ operator !();
        __PUB__ int32 __VARIABLE__ operator &(Int32 __REFERENCE__ value);
        __PUB__ int32 __VARIABLE__ operator |(Int32 __REFERENCE__ value);
        __PUB__ int32 __VARIABLE__ operator ~();
        __PUB__ int32 __VARIABLE__ operator ^(Int32 __REFERENCE__ value);
        __PUB__ int32 __VARIABLE__ operator <<(Int32 __REFERENCE__ value);
        __PUB__ int32 __VARIABLE__ operator >>(Int32 __REFERENCE__ value);
        __PUB__ int32 __VARIABLE__ operator =(Int32 __REFERENCE__ value);

        __PUB__ int32 __VARIABLE__ operator +=(Int32 __REFERENCE__ value);
        __PUB__ int32 __VARIABLE__ operator -=(Int32 __REFERENCE__ value);
        __PUB__ int32 __VARIABLE__ operator *=(Int32 __REFERENCE__ value);
        __PUB__ int32 __VARIABLE__ operator /=(Int32 __REFERENCE__ value);
        __PUB__ int32 __VARIABLE__ operator &=(Int32 __REFERENCE__ value);
        __PUB__ int32 __VARIABLE__ operator |=(Int32 __REFERENCE__ value);
        __PUB__ int32 __VARIABLE__ operator ^=(Int32 __REFERENCE__ value);
        __PUB__ int32 __VARIABLE__ operator <<=(Int32 __REFERENCE__ value);
        __PUB__ int32 __VARIABLE__ operator >>=(Int32 __REFERENCE__ value);

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() override;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() override;

        __PUB__ virtual ::string __VARIABLE__ ToString(const ::string __VARIABLE__ formatter) override;

        __PUB__ static int32 __VARIABLE__ Parse(const ::string __VARIABLE__ s);
        __PUB__ static bool  __VARIABLE__ TryParse(const ::string __VARIABLE__ s, int32 __REFERENCE__ result);
        __PUB__ static bool  __VARIABLE__ TryParse(const ::string __VARIABLE__ s, Int32 __REFERENCE__ result);

        __PUB__ const int32 __VARIABLE__ MaxValue = 2147483647;
        __PUB__ const int32 __VARIABLE__ MinValue = -2147483648;
    };

    class UInt32 final : public virtual dty::TianyuObject, public virtual dty::IFormatter { };
    class Int64 final : public virtual dty::TianyuObject, public virtual dty::IFormatter { };
    class UInt64 final : public virtual dty::TianyuObject, public virtual dty::IFormatter { };
    class Float final : public virtual dty::TianyuObject, public virtual dty::IFormatter { };
    class Double final : public virtual dty::TianyuObject, public virtual dty::IFormatter { };
    class Boolean final : public virtual dty::TianyuObject, public virtual dty::IFormatter { };
}

namespace dty
{

}

#endif // !__cplusplus

#endif // !__DTY_COMMON_NATIVE_PRIME_BASETYPE_H_PLUS_PLUS__