/**
 * @file formatter.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-23
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_CORE_FORMATTER_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_CORE_FORMATTER_H_PLUS_PLUS__

#ifdef __cplusplus

#include "./internal.h"

namespace dty
{
    _interface IFormatter : public virtual dty::TianyuObject
    {
        __PUB__ virtual ~IFormatter() { }

        __PUB__ virtual ::string __VARIABLE__ ToString(const ::string __VARIABLE__ formatter) = 0;
    };

    class FormatHandler final : public virtual dty::TianyuObject
    {

    };

    class FormatProcessor final : public virtual dty::TianyuObject
    {

    };
}

#endif // !__cplusplus

#endif // !__DTY_COMMON_NATIVE_PRIME_CORE_FORMATTER_H_PLUS_PLUS__