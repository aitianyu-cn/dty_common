/**
 * @file operatingSystem.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-20
 *
 * @copyright Copyright (c) 2021
 *
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.operatingsystem?view=net-6.0
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_OPERATINGSYSTEM_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_OPERATINGSYSTEM_H_PLUS_PLUS__

#include "./core.hxx"
#include "./version.hpp"

namespace dty
{
    class OperationSystem final : dty::TianyuObject
    {
        __PUB__ OperationSystem(dty::PlatformID __VARIABLE__ platform, dty::Version __VARIABLE__ version);

        __PUB__ dty::PlatformID __VARIABLE__ Platform();
        __PUB__ dty::String     __VARIABLE__ ServicePack();
        __PUB__ dty::Version    __VARIABLE__ Version();
        __PUB__ dty::String     __VARIABLE__ VersionString();

        __PUB__ bool __VARIABLE__ IsIOS();
        __PUB__ bool __VARIABLE__ IsMacOS();
        __PUB__ bool __VARIABLE__ IsLinux();
        __PUB__ bool __VARIABLE__ IsWindows();

        __PRI__ const   ::string __VARIABLE__ ObjectName;
        __PRI__ virtual ::string __VARIABLE__ ToString() noexcept override;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() override;

        __PUB__ static OperationSystem __VARIABLE__ CurrentOS();
    };
}

#endif // !__DTY_COMMON_NATIVE_PRIME_OPERATINGSYSTEM_H_PLUS_PLUS__