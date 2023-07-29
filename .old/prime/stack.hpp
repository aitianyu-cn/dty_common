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

#include <functional> 
#include <queue>

#include "./core.hxx"
#include "./core/icollections.hpp"

#include "./array.hpp"

namespace dty::collection
{
    template<class T>
    _interface IStack : public virtual TianyuObject
    {
        __PUB__         IStack();
        __PUB__ virtual ~IStack() __override_func;

        __PUB__ virtual void     __VARIABLE__  Clear() __pure_virtual_fun;
        __PUB__ virtual bool     __VARIABLE__  Contains() __pure_virtual_fun;
        __PUB__ virtual T        __REFERENCE__ Peek() __pure_virtual_fun;
        __PUB__ virtual T        __REFERENCE__ Pop() __pure_virtual_fun;
        __PUB__ virtual void     __VARIABLE__  Push(T __REFERENCE__ value) __pure_virtual_fun;

        __PUB__ virtual Array<T> __VARIABLE__  ToArray() __pure_virtual_fun;
    };

    template<class T>
    class Stack final : public virtual TianyuObject, public virtual IStack, public virtual ICollections<T>
    {
        using _Growther_Delegate = std::function<int32 __VARIABLE__(int32 __VARIABLE__ current)>;

        __PUB__         Stack();
        __PUB__         Stack(const ICollections<T> __REFERENCE__ collect);
        __PUB__         Stack(int32 __VARIABLE__ initialCapacity);
        __PUB__ virtual ~Stack() __override_func;

        __PUB__ void __VARIABLE__ Growth(int32 __VARIABLE__ growthSize);
        __PUB__ void __VARIABLE__ Growth(_Growther_Delegate __VARIABLE__ growther);
    };

    template<class T>
    class LinkedStack final : public virtual TianyuObject, public virtual IStack, public virtual ICollections<T>
    {
        __PUB__         LinkedStack();
        __PUB__         LinkedStack(const ICollections<T> __REFERENCE__ collect);
        __PUB__         LinkedStack(int32 __VARIABLE__ initialCapacity);
        __PUB__ virtual ~LinkedStack() __override_func;
    };
}

#endif // !__DTY_COMMON_NATIVE_PRIME_STACK_H_PLUS_PLUS__