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

namespace dty
{
    class Guid final : public virtual dty::collection::IEquatable<dty::Guid>,
        public virtual dty::collection::ICompareable<dty::Guid>
    {
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
    };
}

#endif // !__DTY_COMMON_NATIVE_PRIME_GUID_H_PLUS_PLUS__