/**
 * @file object.hpp(prime)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-19
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_OBJECT_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_OBJECT_H_PLUS_PLUS__

#include "./core.hxx"

namespace dty
{
    template <uint32 _Size>
    class Object : dty::TianyuObject,
        public collection::ICompareable<Object<_Size>>,
        public collection::IEquatable<Object<_Size>>
    {
        __PRO__ byte  __POINTER__  _Obj;

        __PUB__ explicit Object()
        {
            if (0 == _Size)
                this->_Obj = ::null;
            else
                this->_Obj = new byte[_Size];
        }
        __PUB__ explicit Object(Object<_Size> __REFERENCE__ other)
        {
            if (0 == _Size)
                this->_Obj = ::null;
            else
            {
                this->_Obj = new byte[_Size];
                for (int32 i = 0; i < _Size; ++i)
                    this->_Obj[i] = other._Obj[i];
            }
        }
        __PUB__ virtual ~Object()
        {
            this->_Destroy();
        }

        __PRI__ void _Destroy()
        {
            if (::null != this->_Obj)
                delete [] this->_Obj;
        }

        __PUB__ int32 __VARIABLE__ Size()
        {
            return (int32)_Size;
        }

        __PUB__ void __VARIABLE__ Clear()
        {
            this->SetAll((byte)0);
        }
        __PUB__ void __VARIABLE__ SetAll(byte __VARIABLE__ _value)
        {
            if (0 == _Size)
                return;

            this->SetAll(_value, 0);
        }
        __PUB__ void __VARIABLE__ SetAll(byte __VARIABLE__ _value, int32 __VARIABLE__ startIndex)
        {
            if (_Size <= startIndex)
                throw dty::except::ArgumentOutOfRangeException();

            for (int32 i = 0; i < _Size; ++i)
                this->_Obj[i] = _value;
        }
        __PUB__ void __VARIABLE__ Set(byte __VARIABLE__ _value)
        {
            if (0 == _Size)
                return;

            this->Set(_value, 0);
        }
        __PUB__ void __VARIABLE__ Set(byte __VARIABLE__ _value, int32 __VARIABLE__ startIndex)
        {
            if (_Size <= startIndex)
                throw dty::except::ArgumentOutOfRangeException();

            this->_Obj[i] = _value;
        }
        __PUB__ void __VARIABLE__ Set(char __VARIABLE__ _value)
        {
            if (0 == _Size)
                return;

            this->Set(_value, 0);
        }
        __PUB__ void __VARIABLE__ Set(char __VARIABLE__ _value, int32 __VARIABLE__ startIndex)
        {
            this->Set((byte)_value, startIndex);
        }
        __PUB__ void __VARIABLE__ Set(int16 __VARIABLE__ _value)
        {
            if (0 == _Size)
                return;

            this->Set(_value, 0);
        }
        __PUB__ void __VARIABLE__ Set(int16 __VARIABLE__ _value, int32 __VARIABLE__ startIndex)
        {
            if (_Size <= startIndex)
                throw dty::except::ArgumentOutOfRangeException();

            for (int32 i = 0; i < 2 && i < _Size - startIndex; ++i)
            {
                this->_Obj[i + startIndex] = (byte)(_value && 0xFF);
                _value >>= 8;
            }
        }
        __PUB__ void __VARIABLE__ Set(int32 __VARIABLE__ _value)
        {
            if (0 == _Size)
                return;

            this->Set(_value, 0);
        }
        __PUB__ void __VARIABLE__ Set(int32 __VARIABLE__ _value, int32 __VARIABLE__ startIndex)
        {
            if (_Size <= startIndex)
                throw dty::except::ArgumentOutOfRangeException();

            for (int32 i = 0; i < 4 && i < _Size - startIndex; ++i)
            {
                this->_Obj[i + startIndex] = (byte)(_value && 0xFF);
                _value >>= 8;
            }
        }
        __PUB__ void __VARIABLE__ Set(int64 __VARIABLE__ _value)
        {
            if (0 == _Size)
                return;

            this->Set(_value, 0);
        }
        __PUB__ void __VARIABLE__ Set(int64 __VARIABLE__ _value, int32 __VARIABLE__ startIndex)
        {
            if (_Size <= startIndex)
                throw dty::except::ArgumentOutOfRangeException();

            for (int32 i = 0; i < 8 && i < _Size - startIndex; ++i)
            {
                this->_Obj[i + startIndex] = (byte)(_value && 0xFF);
                _value >>= 8;
            }
        }
        __PUB__ void __VARIABLE__ Set(float __VARIABLE__ _value)
        {
            if (0 == _Size)
                return;

            this->Set(_value, 0);
        }
        __PUB__ void __VARIABLE__ Set(float __VARIABLE__ _value, int32 __VARIABLE__ startIndex)
        {
            this->Set(__PTR_TO_VAR__(int32 __POINTER__)(__VAR_TO_PTR__ _value), startIndex);
        }
        __PUB__ void __VARIABLE__ Set(double __VARIABLE__ _value)
        {
            if (0 == _Size)
                return;

            this->Set(_value, 0);
        }
        __PUB__ void __VARIABLE__ Set(double __VARIABLE__ _value, int32 __VARIABLE__ startIndex)
        {
            this->Set(__PTR_TO_VAR__(int64 __POINTER__)(__VAR_TO_PTR__ _value), startIndex);
        }
        __PUB__ void __VARIABLE__ Set(byte __POINTER__ _value, int32 __VARIABLE__ length)
        {
            if (0 == _Size)
                return;

            this->Set(_value, length, 0);
        }
        __PUB__ void __VARIABLE__ Set(byte __POINTER__ _value, int32 __VARIABLE__ length, int32 __VARIABLE__ startIndex)
        {
            if (::null == _value)
                throw dty::except::ArgumentNullException();
            if (_Size <= startIndex || 0 >= length)
                throw dty::except::ArgumentOutOfRangeException();

            for (int32 i = 0; i < length && i < _Size - startIndex; ++i)
                this->_Obj[i + startIndex] = _value[i];
        }

        __PUB__ byte   __VARIABLE__ ToByte()
        {
            if (0 == _Size)
                return (byte)0;

            return this->_Obj[0];
        }
        __PUB__ sbyte  __VARIABLE__ ToSByte()
        {
            if (0 == _Size)
                return (syte)0;

            return (sbyte __VARIABLE__)(this->ToByte(startIndex));
        }
        __PUB__ int16  __VARIABLE__ ToInt16()
        {
            if (0 == _Size)
                return (int16)0;

            return this->ToInt16(0);
        }
        __PUB__ uint16 __VARIABLE__ ToUInt16()
        {
            if (0 == _Size)
                return (uint16)0u;

            return this->ToUInt32(0);
        }
        __PUB__ int32  __VARIABLE__ ToInt32()
        {
            if (0 == _Size)
                return 0;

            return this->ToInt32(0);
        }
        __PUB__ uint32 __VARIABLE__ ToUInt32()
        {
            if (0 == _Size)
                return 0u;

            return this->ToUInt32(0);
        }
        __PUB__ int64  __VARIABLE__ ToInt64()
        {
            if (0 == _Size)
                return 0ll;

            return this->ToInt64(0);
        }
        __PUB__ uint64 __VARIABLE__ ToUInt64()
        {
            if (0 == _Size)
                return 0ull;

            return this->ToUInt64(0);
        }
        __PUB__ float  __VARIABLE__ ToFloat()
        {
            if (0 == _Size)
                return 0.0f;

            return this->ToFloat(0);
        }
        __PUB__ double __VARIABLE__ ToDouble()
        {
            if (0 == _Size)
                return 0.0lf;

            return this->ToDouble(0);
        }
        __PUB__ char   __VARIABLE__ ToChar()
        {
            if (0 == _Size)
                return (char)'\0';

            return (char __VARIABLE__)(this->ToByte());
        }
        __PUB__ uchar  __VARIABLE__ ToUChar()
        {
            if (0 == _Size)
                return (uchar)'\0';

            return (uchar __VARIABLE__)(this->ToByte());
        }
        __PUB__ string __VARIABLE__ ToString(IStringConverter __REFERENCE__ converter) const
        {
            if (0 == _Size)
                return ::null;

            return converter.TryConvert(this->_Obj, _Size);
        }
        __PUB__ object __VARIABLE__ ToObject()
        {
            return (object __VARIABLE__)(this->_Obj);
        }
        __PUB__ object __VARIABLE__ ToObject(IObjectConverter __REFERENCE__ converter)
        {
            return converter.TryConvert(this->_Obj, _Size);
        }

        __PUB__ byte   __VARIABLE__ ToByte(int32 __VARIABLE__ startIndex)
        {
            if (_Size <= startIndex)
                throw dty::except::ArgumentOutOfRangeException();

            return this->_Obj[startIndex];
        }
        __PUB__ sbyte  __VARIABLE__ ToSByte(int32 __VARIABLE__ startIndex)
        {
            return (sbyte __VARIABLE__)(this->ToByte(startIndex));
        }
        __PUB__ int16  __VARIABLE__ ToInt16(int32 __VARIABLE__ startIndex)
        {
            if (0 == _Size)
                return 0;

            if (_Size <= startIndex)
                throw dty::except::ArgumentOutOfRangeException();

            int32 result = 0;
            int32 endPoint = 2 + startIndex > _Size ? _Size : 2 + startIndex;
            for (int32 i = endPoint - 1; i >= startIndex; --i)
            {
                result <<= 8;
                result |= this->_Obj[i];
            }

            return (int16)(result && 0xFFFF);
        }
        __PUB__ uint16 __VARIABLE__ ToUInt16(int32 __VARIABLE__ startIndex)
        {
            return (uint16)(this->ToInt16(startIndex));
        }
        __PUB__ int32  __VARIABLE__ ToInt32(int32 __VARIABLE__ startIndex)
        {
            if (0 == _Size)
                return 0;

            if (_Size <= startIndex)
                throw dty::except::ArgumentOutOfRangeException();

            int32 result = 0;
            int32 endPoint = 4 + startIndex > _Size ? _Size : 4 + startIndex;
            for (int32 i = endPoint - 1; i >= startIndex; --i)
            {
                result <<= 8;
                result |= this->_Obj[i];
            }

            return result
        }
        __PUB__ uint32 __VARIABLE__ ToUInt32(int32 __VARIABLE__ startIndex)
        {
            return (uint32)(this->ToInt32(startIndex));
        }
        __PUB__ int64  __VARIABLE__ ToInt64(int32 __VARIABLE__ startIndex)
        {
            if (0 == _Size)
                return 0;

            if (_Size <= startIndex)
                throw dty::except::ArgumentOutOfRangeException();

            int64 result = 0;
            int32 endPoint = 8 + startIndex > _Size ? _Size : 8 + startIndex;
            for (int32 i = endPoint - 1; i >= startIndex; --i)
            {
                result <<= 8;
                result |= this->_Obj[i];
            }

            return result
        }
        __PUB__ uint64 __VARIABLE__ ToUInt64(int32 __VARIABLE__ startIndex)
        {
            return (uint64)(this->ToInt64(startIndex));
        }
        __PUB__ float  __VARIABLE__ ToFloat(int32 __VARIABLE__ startIndex)
        {
            int32 __VARIABLE__ result = this->ToInt32(startIndex);

            return __PTR_TO_VAR__(float __POINTER__)(__VAR_TO_PTR__ result);
        }
        __PUB__ double __VARIABLE__ ToDouble(int32 __VARIABLE__ startIndex)
        {
            int64 __VARIABLE__ result = this->ToInt64(startIndex);

            return __PTR_TO_VAR__(double __POINTER__)(__VAR_TO_PTR__ result);
        }
        __PUB__ char   __VARIABLE__ ToChar(int32 __VARIABLE__ startIndex)
        {
            return (char __VARIABLE__)(this->ToByte(startIndex));
        }
        __PUB__ uchar  __VARIABLE__ ToUChar(int32 __VARIABLE__ startIndex)
        {
            return (uchar __VARIABLE__)(this->ToByte(startIndex));
        }
        __PUB__ string __VARIABLE__ ToString(int32 __VARIABLE__ startIndex, IStringConverter __REFERENCE__ converter) const
        {
            if (_Size <= startIndex)
                throw dty::except::ArgumentOutOfRangeException();

            return converter.TryConvert(this->_Obj, _Size, startIndex);
        }
        __PUB__ object __VARIABLE__ ToObject(int32 __VARIABLE__ startIndex)
        {
            if (_Size <= startIndex)
                throw dty::except::ArgumentOutOfRangeException();

            return (object __VARIABLE__)((this->_Obj) + startIndex);
        }
        __PUB__ object __VARIABLE__ ToObject(int32 __VARIABLE__ startIndex, IObjectConverter __REFERENCE__ converter)
        {
            return converter.TryConvert(this->_Obj, _Size, startIndex);
        }

        __PUB__ Object<_Size> __REFERENCE__ operator=(Object<_Size> __REFERENCE__ other)
        {
            if (0 != _Size)
                for (int32 i = 0; i < _Size; ++i)
                    this->_Obj[i] = other._Obj[i];

            return (__PTR_TO_REF__ this);
        }

        __PUB__ virtual bool __VARIABLE__ Equals(Object<_Size> __REFERENCE__ other) override
        {
            return (__PTR_TO_REF__ this) == other;
        }
        __PUB__ virtual bool __VARIABLE__ operator ==(Object<_Size> __REFERENCE__ other) override
        {
            if (0 == _Size)
                return true;

            bool result = true;
            for (int32 i = 0; i < _Size && result; ++i)
                result &= this->_Obj[i] == other._Obj[i];

            return result;
        }
        __PUB__ virtual bool __VARIABLE__ operator !=(Object<_Size> __REFERENCE__ other) override
        {
            return !((__PTR_TO_REF__ this) == other);
        }

        __PUB__ virtual bool __VARIABLE__ operator <(Object<_Size> __REFERENCE__ other) override
        {
            if (0 == _Size)
                return false;

            for (int32 i = _Size - 1; 0 <= i; --i)
            {
                if (this->_Obj[i] > other._Obj[i])
                    return false;
                if (this->_Obj[i] < other._Obj[i])
                    return true;
            }

            return false;
        }
        __PUB__ virtual bool __VARIABLE__ operator >(Object<_Size> __REFERENCE__ other) override
        {
            if (0 == _Size)
                return false;

            for (int32 i = _Size - 1; 0 <= i; --i)
            {
                if (this->_Obj[i] < other._Obj[i])
                    return false;
                if (this->_Obj[i] > other._Obj[i])
                    return true;
            }

            return false;
        }
        __PUB__ virtual bool __VARIABLE__ operator <=(Object<_Size> __REFERENCE__ other) override
        {
            return !((__PTR_TO_REF__ this) > other);
        }
        __PUB__ virtual bool __VARIABLE__ operator >=(Object<_Size> __REFERENCE__ other) override
        {
            return !((__PTR_TO_REF__ this) < other);
        }

        __PUB__ virtual dty::collection::CompareResult __VARIABLE__ CompareTo(Object<_Size> __REFERENCE__ other) override
        {
            Object<_Size> __REFERENCE__ _this = (__PTR_TO_REF__ this);
            return _this == other ? dty::collection::CompareResult::EQUAL
                : _this > other ? dty::collection::CompareResult::GREAT
                : dty::collection::CompareResult::LESS;
        }

        __PUB__ byte __REFERENCE__ operator[](int32 __VARIABLE__ index)
        {
            if (_Size <= index)
                throw dty::except::ArgumentOutOfRangeException();

            return this->_Obj[index];
        }

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override
        {
            return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
        }
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() override
        {
            return dty::GetType(__PTR_TO_REF__ this).Id();
        }
    };

    using Byte = Object<1>;
    using Int16 = Object<2>;
    using Int32 = Object<4>;
    using Int64 = Object<8>;
}

#endif // !__DTY_COMMON_NATIVE_PRIME_OBJECT_H_PLUS_PLUS__