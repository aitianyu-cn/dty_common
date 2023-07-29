/**
 * @file guid.hpp(prime)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-16
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.guid?view=net-6.0
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_GUID_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_GUID_H_PLUS_PLUS__

#include "./core.hxx"
#include "./string.hpp"
#include "./array.hpp"

namespace dty
{
    class Guid final : public virtual TianyuObject,
        public virtual dty::collection::IEquatable<dty::Guid>,
        public virtual dty::collection::ICompareable<dty::Guid>
    {
        __PRI__::byte __VARIABLE__ _Guid[::dty_native_id_default_size];

        __PUB__ Guid(::byte __VARIABLE__ b[::dty_native_id_default_size]);
        __PUB__ Guid(String __VARIABLE__ g);
        __PUB__ Guid
        (
            int32  __VARIABLE__ a,
            int16  __VARIABLE__ b,
            int16  __VARIABLE__ c,
            ::byte __VARIABLE__ d,
            ::byte __VARIABLE__ e,
            ::byte __VARIABLE__ f,
            ::byte __VARIABLE__ g,
            ::byte __VARIABLE__ h,
            ::byte __VARIABLE__ i,
            ::byte __VARIABLE__ j,
            ::byte __VARIABLE__ k
        );
        __PUB__ Guid
        (
            uint32 __VARIABLE__ a,
            uint16 __VARIABLE__ b,
            uint16 __VARIABLE__ c,
            ::byte __VARIABLE__ d,
            ::byte __VARIABLE__ e,
            ::byte __VARIABLE__ f,
            ::byte __VARIABLE__ g,
            ::byte __VARIABLE__ h,
            ::byte __VARIABLE__ i,
            ::byte __VARIABLE__ j,
            ::byte __VARIABLE__ k
        );
        __PUB__ Guid(const Guid __REFERENCE__ other);
        __PUB__ virtual ~Guid() override;

        __PUB__ dty::collection::ByteArray __VARIABLE__ ToByteArray();

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() override;

        __PUB__ dty::String __VARIABLE__ ToString(const ::string __VARIABLE__ formatter);


#pragma region dty::collection::IEquatable and ICompareable interface
        __PUB__ virtual dty::collection::CompareResult __VARIABLE__ CompareTo(Guid __REFERENCE__ other) override;

        __PUB__ virtual bool __VARIABLE__ Equals(Guid __REFERENCE__ other) override;

        __PUB__ virtual bool __VARIABLE__ operator ==(Guid __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator !=(Guid __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator <(Guid __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator >(Guid __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator <=(Guid __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator >=(Guid __REFERENCE__ other) override;
#pragma endregion

        __PRI__ Guid();
        __PUB__ static Guid __VARIABLE__ Empty();
        __PUB__ static Guid __VARIABLE__ NewGuid();
        __PUB__ static Guid __VARIABLE__ Parse(dty::String  __VARIABLE__ guid);
        __PUB__ static Guid __VARIABLE__ Parse(const ::string __VARIABLE__ guid);
        __PUB__ static bool __VARIABLE__ TryParse(dty::String __VARIABLE__ guid, Guid __REFERENCE__ result);
        __PUB__ static bool __VARIABLE__ TryParse(const ::string __VARIABLE__ guid, Guid __REFERENCE__ result);
    };
}

#endif // !__DTY_COMMON_NATIVE_PRIME_GUID_H_PLUS_PLUS__