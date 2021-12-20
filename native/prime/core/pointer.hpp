/**
 * @file pointer.hpp(prime/core)
 * @author senyun.yao
 * @brief 用于天宇平台的智能指针，提供较为安全的指针类型操作
 * @brief Smart Pointer designed for Tianyu Platform to provide little more safe pointer operations.
 * @version 0.1
 * @date 2021-11-18
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_CORE_POINTER_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_CORE_POINTER_H_PLUS_PLUS__

#include"./internal.h"
#include"./error.hpp"

namespace dty
{
    template<typename T>
    class SmartPointer : public virtual TianyuObject
    {
#pragma region Tianyu SmartPointer Internal Block
        //
        // 智能指针类型：强指针与弱指针
        // SmartPointer Type: Strong Pointer and Weak Pointer
        // 强指针拥有对象指针的实际使用权，弱指针只是对象指针的副本，不保证访问的可靠性
        // Strong Pointers have the actual use of object Pointers, while weak Pointers 
        // are only copies of object Pointers and do not guarantee access reliability。
        //
        __PRI__ enum SPType
        {
            STRONG,
            WEAK
        };

        __PRI__ SPType __VARIABLE__ _SmartPointerType;

        /**
         * @brief 内部方法：释放对象的指针引用 
         * @brief Internal Function: Release object pointer reference
         */
        __PRI__ void __VARIABLE__ Release()
        {
            if (null == this->_Pointer)
                return;

            // 选择是释放单个对象还是多个数组
            // Choose whether the pointer is a single object or an array.
            if (1 == this->_Size)
                delete this->_Pointer;
            else
                delete [] this->_Pointer;
        }
        /**
         * @brief 内部方法：检测指定对象与当前对象是否为同一个对象
         * @brief Internal Function: Check whether the specified object is same with current instance.
         *
         * @param {SmartPointer<T>&} sp Specified Compared Object
         * @return {bool} return true if they are same object or one is child of another one.
         */
        __PRI__ bool __VARIABLE__ IsSame(SmartPointer<T> __REFERENCE__ sp)
        {
            // 检查是否为相同对象
            if (this->_Pointer == sp._Pointer)
                return true;

            // 检查是否为包含的对象
            if (this->operator&() + this->_Size > &sp && this->operator&() < &sp)
                return true;

            if (&sp + sp._Size > this->operator&() && &sp < this->operator&())
                return true;

            return false;
        }
#pragma endregion

        __PRI__ T     __POINTER__  _Pointer;
        __PRI__ int64 __VARIABLE__ _Size;

        /**
         * @brief 创建一个空指针对象
         * @brief Create a null pointer
         */
        __PUB__ explicit SmartPointer()
            : _SmartPointerType(SPType::STRONG),
            _Pointer(null),
            _Size(0)
        { }
        /**
         * @brief 由指定的指针创建智能指针对象
         * @brief Create a smart pointer from a specified pointer
         *
         * @exception dty::except::NullPointerException: throw an exception if the specified pointer is null
         */
        __PUB__ explicit SmartPointer(T __POINTER__ pointer)
        {
            if (null == pointer)
                throw dty::except::NullPointerException();

            // create a strong pointer in default.
            this->_SmartPointerType = SPType::STRONG;
            this->_Pointer = pointer;
            this->_Size = 1;
        }
        /**
         * @brief 由指定的指针和对象长度创建智能指针对象
         * @brief Create a smart pointer from a specified pointer and object size
         *
         * @exception dty::except::NullPointerException: throw an exception if the specified pointer is null
         * @exception dty::except::IndexOutOfRangeException: throw an exception if the specified pointer size is not more than zero.
         */
        __PUB__ explicit SmartPointer(T __POINTER__ pointer, int64 __VARIABLE__ size)
        {
            if (null == pointer)
                throw dty::except::NullPointerException();

            if (0 >= size)
                throw dty::except::IndexOutOfRangeException();

            // create a strong pointer in default.
            this->_SmartPointerType = SPType::STRONG;
            this->_Pointer = pointer;
            this->_Size = size;
        }
        /**
         * @brief 由指定的指针创建智能指针对象，并指定指针类型
         * @brief Create a smart pointer from a specified pointer and set the default pointer type
         *
         * @exception dty::except::NullPointerException: throw an exception if the specified pointer is null
         */
        __PUB__ explicit SmartPointer(T __POINTER__ pointer, bool __VARIABLE__ weak)
            : SmartPointer<T>(pointer)
        {
            // To reset pointer type only if weak is true
            if (weak)
                this->_SmartPointerType = SPType::WEAK;
        }
        /**
         * @brief 由指定的指针和对象长度创建智能指针对象，并指定指针类型
         * @brief Create a smart pointer from a specified pointer and object size and set the default pointer type
         *
         * @exception dty::except::NullPointerException: throw an exception if the specified pointer is null
         * @exception dty::except::IndexOutOfRangeException: throw an exception if the specified pointer size is not more than zero.
         */
        __PUB__ explicit SmartPointer(T __POINTER__ pointer, int64 __VARIABLE__ size, bool __VARIABLE__ weak)
            : SmartPointer<T>(pointer, size)
        {
            // To reset pointer type only if weak is true
            if (weak)
                this->_SmartPointerType = SPType::WEAK;
        }
        /**
         * @brief 从指定的智能指针对象创建新的智能指针对象
         * @brief Create a new smart pointer object from a specified smart pointer
         *
         * @param {const SmartPointer<T>&} sp specified source smart pointer.
         */
        __PUB__ SmartPointer(const SmartPointer<T> __REFERENCE__ sp)
            // to copy a weak smart pointer by copy constructor only when in __DTY_SMART_POINTER_COPY_WEAK_MODE__
            // and in __DTY_UNSAFE_MODE__ mode
#if defined(__DTY_SMART_POINTER_COPY_WEAK_MODE__) && defined(__DTY_UNSAFE_MODE__)
            : _SmartPointerType(SPType::WEAK),
            _Pointer(sp._Pointer),
            _Size(sp._Size)
        { }
#else

            // safe copy constructor mode is move pointer owner
            : _SmartPointerType(sp._SmartPointerType),
            _Pointer(sp._Pointer),
            _Size(sp._Size)
        {
            // move pointer from source pointer only when it is strong pointer
            // weak pointer just to copy
            if (SPType::STRONG == sp._SmartPointerType)
            {
                // unsafe mode should change const to normal reference
                // --dty-cpp-lint: unsafe-convert-constRef_to_Ref
                SmartPointer<T>& spMove = (SmartPointer<T> __REFERENCE__)sp;
                spMove._Pointer = null;
                spMove._Size = 0;
            }
        }
#endif // !defined(__DTY_SMART_POINTER_COPY_WEAK_MODE__) && defined(__DTY_UNSAFE_MODE__)

        /**
         * @brief 析构函数 
         * @brief disconstructor
         */
        __PUB__ virtual ~SmartPointer()
        {
            // to release pointer only when the current instance is strong type
            if (SPType::STRONG == this->_SmartPointerType)
                this->Release();
        }

        /**
         * @brief 获取一个bool值指示当前实例是否为空指针
         * @brief Get a bool value indicates whether the current pointer is null
         *
         * @return {bool} return true if current pointer is null, other wise is false
         */
        __PUB__ bool __VARIABLE__ IsNull()
        {
            return null == this->_Pointer;
        }
        /**
         * @brief 获取一个值指示当前指针实例的大小
         * @brief Get a int64 indicates the current pointer size
         *
         * @return {int64} return pointer size
         */
        __PUB__ int64  __VARIABLE__  Size() const
        {
            return this->_Size;
        }
        /**
         * @brief 运算符 & 重载：获取当前指针的绝对地址
         * @brief override operator &: Get the absoult address of current pointer.
         *
         * @return {uint64} return current address
         */
        __PUB__ uint64 __VARIABLE__  operator __REFERENCE__()
        {
            if (this->IsNull())
                return 0ULL;

            return (uint64)(this->_Pointer);
        }
        /**
         * @brief
         * @brief
         *
         * @return {T&}
         */
        __PUB__ T      __REFERENCE__ operator __POINTER__()
        {
            if (null == this->_Pointer)
                throw dty::except::NullPointerException();

            return __PTR_TO_REF__(this->_Pointer);
        }
        /**
         * @brief
         * @brief
         *
         * @return {T*}
         */
        __PUB__ T      __POINTER__   operator ->()
        {
            if (null == this->_Pointer)
                throw dty::except::NullPointerException();

            return this->_Pointer;
        }
        /**
         * @brief
         * @brief
         *
         * @return {T*}
         */
        __PUB__ T      __POINTER__   operator ->() const
        {
            if (null == this->_Pointer)
                throw dty::except::NullPointerException();

            return this->_Pointer;
        }
        /**
         * @brief
         * @brief
         *
         * @param {int64} index:
         * @return {T&}
         */
        __PUB__ T      __REFERENCE__ operator[] (int64 __VARIABLE__ index)
        {
            if (null == this->_Pointer)
                throw dty::except::NullPointerException();

            if (0 > index || this->_Size <= index)
                throw dty::except::ArgumentOutOfRangeException();

            return (this->_Pointer)[index];
        }
        /**
         * @brief
         * @brief
         *
         * @param {int64} index:
         * @return {T&}
         */
        __PUB__ T      __REFERENCE__ operator[] (int64 __VARIABLE__ index) const
        {
            if (null == this->_Pointer)
                throw dty::except::NullPointerException();

            if (0 > index || this->_Size <= index)
                throw dty::except::ArgumentOutOfRangeException();

            return (this->_Pointer)[index];
        }
        /**
         * @brief
         * @brief
         *
         * @return {SmartPointer<T>}
         */
        __PUB__ SmartPointer<T> __VARIABLE__ GetWeak()
        {
            return SmartPointer<T>(this->_Pointer, this->_Size, true);
        }
        /**
         * @brief
         * @brief
         *
         * @param {SmartPointer<T>&} sp
         * @return {bool}
         */
        __PUB__ bool            __VARIABLE__ Move(SmartPointer<T> __REFERENCE__ sp)
        {
            if (SPType::STRONG != sp._SmartPointerType)
                return false;

            if (this->_Pointer == sp._Pointer)
                return false;

            if (SPType::STRONG == this->_SmartPointerType && null != this->_Pointer)
            {
                if (1 < this->_Size)
                    delete [] this->_Pointer;
                else
                    delete this->_Pointer;
            }

            this->_SmartPointerType = sp._SmartPointerType;
            this->_Pointer = sp._Pointer;
            this->_Size = sp._Size;

            sp._Pointer = null;
            sp._Size = 0;

            return true;
        }
        /**
         * @brief
         * @brief
         *
         * @param {SmartPointer<T>&} other
         * @return {bool}
         */
        __PUB__ bool __VARIABLE__ operator ==(SmartPointer<T> __REFERENCE__ other)
        {
            try
            {
                return (__PTR_TO_REF__ this->_Pointer) == (__PTR_TO_REF__ other._Pointer);
            }
            catch (std::exception)
            {
                return this->_Pointer == other._Pointer;
            }

        }
        /**
         * @brief
         * @brief
         *
         * @param {SmartPointer<T>&} other
         * @return {bool}
         */
        __PUB__ bool __VARIABLE__ operator !=(SmartPointer<T> __REFERENCE__ other)
        {
            try
            {
                return (__PTR_TO_REF__ this->_Pointer) != (__PTR_TO_REF__ other._Pointer);
            }
            catch (std::exception)
            {
                return this->_Pointer != other._Pointer;
            }

        }
        /**
         * @brief
         * @brief
         *
         * @param {SmartPointer<T>&} other
         * @return {bool}
         */
        __PUB__ bool __VARIABLE__ operator ==(SmartPointer<T> __VARIABLE__ other)
        {
            try
            {
                return (__PTR_TO_REF__ this->_Pointer) == (__PTR_TO_REF__ other._Pointer);
            }
            catch (std::exception)
            {
                return this->_Pointer == other._Pointer;
            }

        }
        /**
         * @brief
         * @brief
         *
         * @param {SmartPointer<T>&} other
         * @return {bool}
         */
        __PUB__ bool __VARIABLE__ operator !=(SmartPointer<T> __VARIABLE__ other)
        {
            try
            {
                return (__PTR_TO_REF__ this->_Pointer) != (__PTR_TO_REF__ other._Pointer);
            }
            catch (std::exception)
            {
                return this->_Pointer != other._Pointer;
            }

        }

        __PUB__ virtual ::string __VARIABLE__ ToString() override
        {
            return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
        }
    };

#pragma region Pre-define default safe pointer
    using byte_ptr = SmartPointer<byte>;
    using bool_ptr = SmartPointer<bool>;
    using short_ptr = SmartPointer<int16>;
    using int_ptr = SmartPointer<int32>;
    using long_ptr = SmartPointer<int64>;
    using float_ptr = SmartPointer<float>;
    using double_ptr = SmartPointer<double>;
    using string_sp = SmartPointer<char>;
#pragma endregion
}

#endif // !__DTY_COMMON_NATIVE_PRIME_CORE_POINTER_H_PLUS_PLUS__