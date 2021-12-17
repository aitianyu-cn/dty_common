/**
 * @file version.hpp(prime)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-16
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.version?view=net-6.0
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_VERSION_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_VERSION_H_PLUS_PLUS__

#include "./core.hxx"
#include "./string.hpp"

namespace dty
{
    class Version final : public virtual dty::collection::IEquatable<dty::Version>,
        public virtual dty::collection::ICompareable<dty::Version>
    {
        class ReadProperty : public dty::IPropertyGetter<int32>
        {
            __PRO__ int32 __VARIABLE__ _Value;

            __PUB__ ReadProperty() :_Value() { }
            __PUB__ virtual ~ReadProperty() override { }

            __PUB__ virtual int32 __VARIABLE__ Get() override
            {
                return this->_Value;
            }
            __PUB__ virtual operator int32() override
            {
                return this->_Value;
            }

            friend class Version;
        };

        class Int16Property : public dty::IPropertyGetter<int16>
        {
            using Int16PropertyDelegate = int16 __VARIABLE__(__POINTER__)();

            __PRI__ Int16PropertyDelegate __VARIABLE__ _Delegate;

            __PUB__ Int16Property(Int16PropertyDelegate __VARIABLE__ del)
                :_Delegate(del)
            { }
            __PUB__ virtual ~Int16Property() override { }

            __PUB__ virtual int16 __VARIABLE__ Get() override
            {
                return this->_Delegate();
            }
            __PUB__ virtual operator int16() override
            {
                return this->_Delegate();
            }

            friend class Version;
        };

        __PUB__ ReadProperty  __VARIABLE__ Major;
        __PUB__ ReadProperty  __VARIABLE__ Minor;
        __PUB__ ReadProperty  __VARIABLE__ Build;
        __PUB__ ReadProperty  __VARIABLE__ Revision;
        __PUB__ Int16Property __VARIABLE__ MajorRevision;
        __PUB__ Int16Property __VARIABLE__ MinorRevision;

        __PUB__ Version();
        __PUB__ Version(dty::String  __VARIABLE__ version);
        __PUB__ Version(const string __VARIABLE__ version);
        __PUB__ Version(int32 __VARIABLE__ major, int32 __VARIABLE__ minor);
        __PUB__ Version(int32 __VARIABLE__ major, int32 __VARIABLE__ minor, int32 __VARIABLE__ build);
        __PUB__ Version(int32 __VARIABLE__ major, int32 __VARIABLE__ minor, int32 __VARIABLE__ build, int32 __VARIABLE__ revision);

        __PUB__ Version __VARIABLE__ Parse(dty::String  __VARIABLE__ version);
        __PUB__ Version __VARIABLE__ Parse(const string __VARIABLE__ version);

        __PUB__ dty::String __VARIABLE__ ToString();
        __PUB__ dty::String __VARIABLE__ ToString(const string __VARIABLE__ formatter);

        __PUB__ bool __VARIABLE__ TryParse(dty::String __VARIABLE__ guid, Version __REFERENCE__ result);
        __PUB__ bool __VARIABLE__ TryParse(const string __VARIABLE__ guid, Version __REFERENCE__ result);

#pragma region dty::collection::IEquatable and ICompareable interface
        __PUB__ virtual dty::collection::CompareResult __VARIABLE__ CompareTo(Version __REFERENCE__ other) override;

        __PUB__ virtual bool __VARIABLE__ Equals(Version __REFERENCE__ other) override;

        __PUB__ virtual bool __VARIABLE__ operator ==(Version __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator !=(Version __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator <(Version __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator >(Version __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator <=(Version __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator >=(Version __REFERENCE__ other) override;
#pragma endregion
    };
}

#endif // !__DTY_COMMON_NATIVE_PRIME_VERSION_H_PLUS_PLUS__