/**
 * @file async.hpp(prime)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-17
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_ASYNC_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_ASYNC_H_PLUS_PLUS__

#include "./core.hxx"

namespace dty
{
    _enum AsyncState : int32
    {
        Unknown,
        Success,
        Failure,
    };

    template<class T>
    class AsyncResult final : public TianyuObject
    {
        __PRI__ bool       __POINTER__  _IsCompleted;
        __PRI__ AsyncState __POINTER__  _State;
        __PRI__ T          __POINTER__  _Result;

        __PRI__ int32      __POINTER__  _Reference;

        __PUB__ AsyncResult()
            : _IsCompleted(new bool(false)),
            _State(new dty::thread::AsyncState(dty::thread::AsyncState::Unknown)),
            _Result(new T()),
            _Reference(new int32(1))
        { }
        __PUB__ AsyncResult(AsyncResult __REFERENCE__ other)
            : _IsCompleted(other.IsCompleted), _State(other._State), _Result(other._Result),
            _Reference(other._Reference)
        {
            (__PTR_TO_VAR__(this->_Reference)) += 1;
        }
        __PUB__ ~AsyncResult()
        {
            (__PTR_TO_VAR__(this->_Reference)) -= 1;

            if (0 == __PTR_TO_VAR__(this->_Reference))
            {
                delete this->_IsCompleted;
                delete this->_State;
                delete this->_Result;
                delete this->_Reference;
            }
        }

        __PUB__ bool       __VARIABLE__ IsCompleted()
        {
            return __PTR_TO_VAR__(this->_IsCompleted);
        }
        __PUB__ AsyncState __VARIABLE__ GetState()
        {
            return __PTR_TO_VAR__(this->_State);
        }

        __PUB__ void       __VARIABLE__ SetState(AsyncState __VARIABLE__ state)
        {
            __PTR_TO_VAR__(this->_State) = state;
        }
        __PUB__ void       __VARIABLE__ SetComplete()
        {
            __PTR_TO_VAR__(this->_IsCompleted) = true;
        }
        __PUB__ void       __VARIABLE__ SetResult(T __VARIABLE__ value)
        {
            __PTR_TO_VAR__(this->_Result) = value;
        }

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override
        {
            return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
        }
    };

    using ActionCallbackDelegate = void __VARIABLE__(__POINTER__)();

    template<class ... Args>
    class Action final : public TianyuObject
    {
        __PUB__ using ActionDelegate = void __VARIABLE__(__POINTER__)(Args ...);

        __PRI__ ActionDelegate __VARIABLE__ _Action;

        __PUB__ Action() : _Action(Action<Args>::ActionDefault) { }
        __PUB__ Action(ActionDelegate __VARIABLE__ action) : _Action(action) { }
        __PUB__ Action(Action<Args> __REFERENCE__ other) : _Action(other._Action) { }
        __PUB__ ~Action() { }

        __PUB__ void __VARIABLE__ Invoke(Args ...params)
        {
            this->_Action(params...);
        }
        __PUB__ void __VARIABLE__ BeginInvoke(Args ...params, ActionCallbackDelegate __VARIABLE__ callback)
        {
            this->_Action(params...);

            callback();
        }
        __PUB__ void __VARIABLE__ BeginInvoke(Args ...params, ActionCallbackDelegate __VARIABLE__ endInvoke, ActionCallbackDelegate __VARIABLE__ callback)
        {
            this->_Action(params...);

            endInvoke();
            callback();
        }

        __PRI__ static void __VARIABLE__ ActionDefault(Args ...)
        {
            throw dty::except::NotImplementationException();
        }

        __PUB__ Action<Args> __REFERENCE__ operator =(ActionDelegate __VARIABLE__ action)
        {
            this->_Action = action;

            return __PTR_TO_REF__ this;
        }
        __PUB__ void __VARIABLE__ operator ()(Args ...params)
        {
            this->_Action(params...);
        }

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override
        {
            return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
        }
    };

    template<class TReturn, class ... Args>
    class Func final : public dty::TianyuObject
    {
        __PUB__ using FuncDelegate = TReturn __VARIABLE__(__POINTER__)(Args ...);

        __PRI__ FuncDelegate __VARIABLE__ _Func;

        __PUB__ Func() : _Func(Func<TReturn, Args>::FuncDefault) { }
        __PUB__ Func(FuncDelegate __VARIABLE__ func) : _Func(func) { }
        __PUB__ Func(Func<TReturn, Args> __REFERENCE__ other) : _Func(other._Func) { }
        __PUB__ ~Func() { }

        __PUB__ TReturn              __VARIABLE__ Invoke(Args ...params)
        {
            return this->_Func(params...);
        }
        __PUB__ AsyncResult<TReturn> __VARIABLE__ BeginInvoke(Args ...params, ActionCallbackDelegate __VARIABLE__ endInvoke)
        {
            AsyncResult<TReturn> __VARIABLE__ result;

            result.SetComplete();
            try
            {
                result.SetResult(this->_Func(params...));
                result.SetState(dty::AsyncState::Success);
            }
            catch (std::exception)
            {
                result.SetState(dty::AsyncState::Failure);
            }

            return result;
        }

        __PRI__ static TReturn __VARIABLE__ FuncDefault(Args ...)
        {
            throw dty::except::NotImplementationException();
        }

        __PUB__ Func<TReturn, Args> __REFERENCE__ operator =(FuncDelegate __VARIABLE__ func)
        {
            this->_Func = func;
        }
        __PUB__ TReturn             __VARIABLE__  operator()(Args ...params)
        {
            return this->_Func(params...);
        }

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override
        {
            return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
        }
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()
        {
            return dty::GetType(__PTR_TO_REF__ this).Id();
        }
    };
}

#endif // !__DTY_COMMON_NATIVE_PRIME_ASYNC_H_PLUS_PLUS__