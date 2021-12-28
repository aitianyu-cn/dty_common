/**
 * @file stack.hpp(prime)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-22
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.stack?view=net-6.0
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_STACK_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_STACK_H_PLUS_PLUS__

#include "./core.hxx"
#include "./core/icollections.hpp"

namespace dty::collection
{
    template<class T>
    class Stack final : public virtual TianyuObject, public virtual ICollections<T>
    {
        __PUB__ Stack();
        __PUB__ Stack(const ICollections<T> __REFERENCE__ collect);
        __PUB__ Stack(int32 __VARIABLE__ initialCapacity);
    };
}

#endif // !__DTY_COMMON_NATIVE_PRIME_STACK_H_PLUS_PLUS__