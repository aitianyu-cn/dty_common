/**
 * @file thread.hpp
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-16
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.thread?view=net-6.0
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_CORE_THREAD_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_CORE_THREAD_H_PLUS_PLUS__

#include "./internal.h"
#include "./property.hpp"
#include "./error.hpp"

namespace dty::threading
{
    _enum ThreadPriority
    {
        Lowest = 0,
        BelowNormal = 1,
        Normal = 2,
        AboveNormal = 3,
        Highest = 4
    };

    _enum ThreadState
    {
        Running = 0,
        StopRequested = 1,
        SuspendRequested = 2,
        Background = 4,
        Unstarted = 8,
        Stopped = 16,
        WaitSleepJoin = 32,
        Suspended = 64,
        AbortRequested = 128,
        Skipped = 256,
    };

    typedef void __VARIABLE__(__POINTER__ ParameterizedThreadStart)(dty::TianyuObject __REFERENCE__ obj);
    typedef void __VARIABLE__(__POINTER__ ThreadStart)();

    class Thread final : public dty::TianyuObject
    {
        // public properties and getters definition

        __PUB__ IPropertyGetter<bool>  __REFERENCE__ IsAlive = this->_IsAlive;
        __PUB__ IPropertyGetter<bool>  __REFERENCE__ IsThreadPoolThread = this->_IsThreadPoolThread;
        __PUB__ IPropertyGetter<int32> __REFERENCE__ ManagedThreadId = this->_ManagedThreadId;

        __PUB__ Property<string>         __VARIABLE__ Name;
        __PUB__ Property<ThreadPriority> __VARIABLE__ Priority;
        __PUB__ Property<ThreadState>    __VARIABLE__ State;

        // private properties

        __PRI__ Property<bool>  __VARIABLE__ _IsAlive;
        __PRI__ Property<bool>  __VARIABLE__ _IsThreadPoolThread;
        __PRI__ Property<int32> __VARIABLE__ _ManagedThreadId;

        __PUB__         Thread(ThreadStart __VARIABLE__ start);
        __PUB__         Thread(ThreadStart __VARIABLE__ start, int32 __VARIABLE__ maxStackSize);
        __PUB__         Thread(ParameterizedThreadStart __VARIABLE__ start);
        __PUB__         Thread(ParameterizedThreadStart __VARIABLE__ start, int32 __VARIABLE__ maxStackSize);
        __PUB__ virtual ~Thread() __override_func;

        __PUB__ void __VARIABLE__ Abort();
        __PUB__ void __VARIABLE__ Interrupt();
        __PUB__ void __VARIABLE__ Join();
        __PUB__ void __VARIABLE__ ResetAbort();
        __PUB__ void __VARIABLE__ Resume();
        __PUB__ void __VARIABLE__ Sleep(int32 __VARIABLE__ milliseconds);
        __PUB__ void __VARIABLE__ Start();
        __PUB__ void __VARIABLE__ Start(dty::TianyuObject __REFERENCE__ obj);
        __PUB__ void __VARIABLE__ Suspend();

        __PUB__ virtual ::string __VARIABLE__ ToString()  noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() __override_func;

        // static object
        __PUB__ static Property<Thread __POINTER__> __VARIABLE__ CurrentThread;
    };

    _interface IRunnable : public virtual dty::TianyuObject
    {
        __PUB__ void __VARIABLE__ Run();

        __PRO__ virtual void __VARIABLE__ _Executor() __pure_virtual_fun;
    };

    template<class T>
    _interface IParameterizedRunnable : public virtual dty::TianyuObject
    {
        __PUB__ void __VARIABLE__ Run(T __VARIABLE__ value);

        __PRO__ virtual void __VARIABLE__ _Executor(T __VARIABLE__ value) __pure_virtual_fun;
    };

    class ThreadPool : public virtual dty::TianyuObject
    {
        __PUB__ virtual ::string __VARIABLE__ ToString()  noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() __override_func;
    };

    class Mutex : public virtual dty::TianyuObject
    {
        __PUB__ virtual ::string __VARIABLE__ ToString()  noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() __override_func;
    };

    class Timer final : public dty::TianyuObject
    {
        __PUB__ virtual ::string __VARIABLE__ ToString()  noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() __override_func;
    };
}

#endif // !__DTY_COMMON_NATIVE_PRIME_CORE_THREAD_H_PLUS_PLUS__