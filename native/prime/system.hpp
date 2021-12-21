/**
 * @file system.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-20
 *
 * @copyright Copyright (c) 2021
 *
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.operatingsystem?view=net-6.0
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_SYSTEM_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_SYSTEM_H_PLUS_PLUS__

#include "./core.hxx"
#include "./version.hpp"

namespace dty
{
    class OperationSystem final : dty::TianyuObject
    {
        __PUB__ IPropertyGetter<dty::PlatformID> __REFERENCE__ Platform = this->_Platform;
        __PUB__ IPropertyGetter<dty::String>     __REFERENCE__ ServicePack = this->_ServicePack;
        __PUB__ IPropertyGetter<dty::Version>    __REFERENCE__ Version = this->_Version;

        __PRI__ Property<dty::PlatformID> __VARIABLE__ _Platform;
        __PRI__ Property<dty::String>     __VARIABLE__ _ServicePack;
        __PRI__ Property<dty::Version>    __VARIABLE__ _Version;

        __PUB__ OperationSystem(dty::PlatformID __VARIABLE__ platform, dty::Version __VARIABLE__ version);

        __PUB__ bool __VARIABLE__ IsIOS();
        __PUB__ bool __VARIABLE__ IsMacOS();
        __PUB__ bool __VARIABLE__ IsLinux();
        __PUB__ bool __VARIABLE__ IsWindows();

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() override;

        __PRI__ static Property<OperationSystem>        __VARIABLE__ _CurrentOS;
        __PUB__ static IPropertyGetter<OperationSystem> __VARIABLE__ CurrentOS;
    };
}

#endif // !__DTY_COMMON_NATIVE_PRIME_SYSTEM_H_PLUS_PLUS__