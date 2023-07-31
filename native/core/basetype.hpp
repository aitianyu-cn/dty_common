/**
 * @file basetype.hpp
 * @author ysydty
 * @brief
 * @version 0.1
 * @date 2021-12-23
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.TB?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.byte?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.sbyte?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.int16?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.uint16?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.int32?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.uint32?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.int64?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.uint64?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.single?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.double?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean?view=net-6.0
 */

#ifndef __TIANYU_COMMON_NATIVE_CORE_BASETYPE_H_PLUS_PLUS__
#define __TIANYU_COMMON_NATIVE_CORE_BASETYPE_H_PLUS_PLUS__

#ifdef __cplusplus

#include "./internal.h"
#include "./formatter.hpp"
#include "./property.hpp"

namespace tianyu
{
    template<class TB, TB _Max, TB _Min>
    class TIntegerBase final :
        public virtual tianyu::TianyuObject,
        public virtual tianyu::collection::ICompareable<TIntegerBase<TB, _Max, _Min>>,
        public virtual tianyu::collection::IEquatable<TIntegerBase<TB, _Max, _Min>>,
        public virtual tianyu::IFormatter
    {
        using CMPR = tianyu::collection::CompareResult;

        __PRI__ TB __VARIABLE__ _Value;

        __PUB__         __construction__ TIntegerBase();
        __PUB__         __construction__ TIntegerBase(TB __VARIABLE__ value);
        __PUB__         __cp_construct__ TIntegerBase(const TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ virtual __destruction__  ~TIntegerBase() __override_func;

        // ###################################################################################
        // operators __override_func (compared)
        // ###################################################################################
        __PUB__ virtual bool __VARIABLE__ Equals(TianyuObject __REFERENCE__ obj)     __override_func;
        __PUB__ virtual bool __VARIABLE__ operator==(TianyuObject __REFERENCE__ obj) __override_func;

        __PUB__ virtual bool __VARIABLE__ Equals(TIntegerBase<TB, _Max, _Min> __REFERENCE__ other)      __override_func;
        __PUB__ virtual CMPR __VARIABLE__ CompareTo(TIntegerBase<TB, _Max, _Min> __REFERENCE__ other)   __override_func;
        __PUB__ virtual bool __VARIABLE__ operator ==(TIntegerBase<TB, _Max, _Min> __REFERENCE__ other) __override_func;
        __PUB__ virtual bool __VARIABLE__ operator !=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ other) __override_func;
        __PUB__ virtual bool __VARIABLE__ operator <(TIntegerBase<TB, _Max, _Min> __REFERENCE__ other)  __override_func;
        __PUB__ virtual bool __VARIABLE__ operator >(TIntegerBase<TB, _Max, _Min> __REFERENCE__ other)  __override_func;
        __PUB__ virtual bool __VARIABLE__ operator <=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ other) __override_func;
        __PUB__ virtual bool __VARIABLE__ operator >=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ other) __override_func;

        // ###################################################################################
        // operators __override_func (calculated)
        // ###################################################################################
        __PUB__ operator TB();
        __PUB__ TB __VARIABLE__ operator ++();
        __PUB__ TB __VARIABLE__ operator --();
        __PUB__ TB __VARIABLE__ operator ++(int);
        __PUB__ TB __VARIABLE__ operator --(int);

        __PUB__ TB __VARIABLE__ operator +(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator -(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator *(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator /(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator %(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator !();
        __PUB__ TB __VARIABLE__ operator &(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator |(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator ~();
        __PUB__ TB __VARIABLE__ operator ^(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator <<(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator >>(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator =(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);

        __PUB__ TB __VARIABLE__ operator +=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator -=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator *=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator /=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator %=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator &=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator |=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator ^=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator <<=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        __PUB__ TB __VARIABLE__ operator >>=(TIntegerBase<TB, _Max, _Min> __REFERENCE__ value);
        // ###################################################################################
        // operators __override_func end
        // ###################################################################################

        __PUB__ virtual ::string __VARIABLE__ ToString(const ::string __VARIABLE__ formatter) __override_func;
        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;

        // static functions
        __PUB__ static TB   __VARIABLE__ Parse(const ::string __VARIABLE__ s);
        __PUB__ static bool __VARIABLE__ TryParse(const ::string __VARIABLE__ s, TB __REFERENCE__ result);
        __PUB__ static bool __VARIABLE__ TryParse(const ::string __VARIABLE__ s, TIntegerBase<TB, _Max, _Min> __REFERENCE__ result);

        // const values
        __PUB__ const TB    __VARIABLE__ MaxValue = _Max;
        __PUB__ const TB    __VARIABLE__ MinValue = _Min;
    };

    class Float final :
        public virtual tianyu::TianyuObject,
        public virtual tianyu::collection::ICompareable<Float>,
        public virtual tianyu::collection::IEquatable<Float>,
        public virtual tianyu::IFormatter
    {
        using CMPR = tianyu::collection::CompareResult;

        __PUB__ tianyu::Property<double> __VARIABLE__ Precision;

        __PRI__ float __VARIABLE__ _Value;

        __PUB__         __construction__ Float();
        __PUB__         __construction__ Float(float __VARIABLE__ value, float __VARIABLE__ precision);
        __PUB__         __construction__ Float(float __VARIABLE__ value);
        __PUB__         __cp_construct__ Float(const Float __REFERENCE__ value);
        __PUB__ virtual __destruction__  ~Float() __override_func;

        // ###################################################################################
        // operators __override_func (compared)
        // ###################################################################################
        __PUB__ virtual bool __VARIABLE__ Equals(TianyuObject __REFERENCE__ obj)     __override_func;
        __PUB__ virtual bool __VARIABLE__ operator==(TianyuObject __REFERENCE__ obj) __override_func;

        __PUB__ virtual bool __VARIABLE__ Equals(Float __REFERENCE__ other)      __override_func;
        __PUB__ virtual CMPR __VARIABLE__ CompareTo(Float __REFERENCE__ other)   __override_func;
        __PUB__ virtual bool __VARIABLE__ operator ==(Float __REFERENCE__ other) __override_func;
        __PUB__ virtual bool __VARIABLE__ operator !=(Float __REFERENCE__ other) __override_func;
        __PUB__ virtual bool __VARIABLE__ operator <(Float __REFERENCE__ other)  __override_func;
        __PUB__ virtual bool __VARIABLE__ operator >(Float __REFERENCE__ other)  __override_func;
        __PUB__ virtual bool __VARIABLE__ operator <=(Float __REFERENCE__ other) __override_func;
        __PUB__ virtual bool __VARIABLE__ operator >=(Float __REFERENCE__ other) __override_func;

        // ###################################################################################
        // operators __override_func (calculated)
        // ###################################################################################
        __PUB__ operator float();
        __PUB__ float __VARIABLE__ operator ++();
        __PUB__ float __VARIABLE__ operator --();
        __PUB__ float __VARIABLE__ operator ++(int);
        __PUB__ float __VARIABLE__ operator --(int);

        __PUB__ float __VARIABLE__ operator +(Float __REFERENCE__ value);
        __PUB__ float __VARIABLE__ operator -(Float __REFERENCE__ value);
        __PUB__ float __VARIABLE__ operator *(Float __REFERENCE__ value);
        __PUB__ float __VARIABLE__ operator /(Float __REFERENCE__ value);
        __PUB__ float __VARIABLE__ operator =(Float __REFERENCE__ value);

        __PUB__ float __VARIABLE__ operator +=(Float __REFERENCE__ value);
        __PUB__ float __VARIABLE__ operator -=(Float __REFERENCE__ value);
        __PUB__ float __VARIABLE__ operator *=(Float __REFERENCE__ value);
        __PUB__ float __VARIABLE__ operator /=(Float __REFERENCE__ value);
        // ###################################################################################
        // operators __override_func end
        // ###################################################################################

        __PUB__ virtual ::string __VARIABLE__ ToString(const ::string __VARIABLE__ formatter) __override_func;
        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;

        // static functions
        __PUB__ static float __VARIABLE__ Parse(const ::string __VARIABLE__ s);
        __PUB__ static bool  __VARIABLE__ TryParse(const ::string __VARIABLE__ s, float __REFERENCE__ result);
        __PUB__ static bool  __VARIABLE__ TryParse(const ::string __VARIABLE__ s, Float __REFERENCE__ result);

        // const values
        __PUB__ const float  __VARIABLE__ Epsilon = 1.401298E-45;
        __PUB__ const float  __VARIABLE__ MaxValue = 3.40282347E+38;
        __PUB__ const float  __VARIABLE__ MinValue = -3.40282347E+38;
    };

    class Double final :
        public virtual tianyu::TianyuObject,
        public virtual tianyu::collection::ICompareable<Double>,
        public virtual tianyu::collection::IEquatable<Double>,
        public virtual tianyu::IFormatter
    {
        using CMPR = tianyu::collection::CompareResult;

        __PUB__ tianyu::Property<double> __VARIABLE__ Precision;

        __PRI__ double __VARIABLE__ _Value;

        __PUB__         __construction__ Double();
        __PUB__         __construction__ Double(double __VARIABLE__ value);
        __PUB__         __construction__ Double(double __VARIABLE__ value, double __VARIABLE__ precision);
        __PUB__         __cp_construct__ Double(const Double __REFERENCE__ value);
        __PUB__ virtual __destruction__  ~Double() __override_func;

        // ###################################################################################
        // operators __override_func (compared)
        // ###################################################################################
        __PUB__ virtual bool __VARIABLE__ Equals(TianyuObject __REFERENCE__ obj)     __override_func;
        __PUB__ virtual bool __VARIABLE__ operator==(TianyuObject __REFERENCE__ obj) __override_func;

        __PUB__ virtual bool __VARIABLE__ Equals(Double __REFERENCE__ other)      __override_func;
        __PUB__ virtual CMPR __VARIABLE__ CompareTo(Double __REFERENCE__ other)   __override_func;
        __PUB__ virtual bool __VARIABLE__ operator ==(Double __REFERENCE__ other) __override_func;
        __PUB__ virtual bool __VARIABLE__ operator !=(Double __REFERENCE__ other) __override_func;
        __PUB__ virtual bool __VARIABLE__ operator <(Double __REFERENCE__ other)  __override_func;
        __PUB__ virtual bool __VARIABLE__ operator >(Double __REFERENCE__ other)  __override_func;
        __PUB__ virtual bool __VARIABLE__ operator <=(Double __REFERENCE__ other) __override_func;
        __PUB__ virtual bool __VARIABLE__ operator >=(Double __REFERENCE__ other) __override_func;

        // ###################################################################################
        // operators __override_func (calculated)
        // ###################################################################################
        __PUB__ operator double();
        __PUB__ double __VARIABLE__ operator ++();
        __PUB__ double __VARIABLE__ operator --();
        __PUB__ double __VARIABLE__ operator ++(int);
        __PUB__ double __VARIABLE__ operator --(int);

        __PUB__ double __VARIABLE__ operator +(Double __REFERENCE__ value);
        __PUB__ double __VARIABLE__ operator -(Double __REFERENCE__ value);
        __PUB__ double __VARIABLE__ operator *(Double __REFERENCE__ value);
        __PUB__ double __VARIABLE__ operator /(Double __REFERENCE__ value);
        __PUB__ double __VARIABLE__ operator =(Double __REFERENCE__ value);

        __PUB__ double __VARIABLE__ operator +=(Double __REFERENCE__ value);
        __PUB__ double __VARIABLE__ operator -=(Double __REFERENCE__ value);
        __PUB__ double __VARIABLE__ operator *=(Double __REFERENCE__ value);
        __PUB__ double __VARIABLE__ operator /=(Double __REFERENCE__ value);
        // ###################################################################################
        // operators __override_func end
        // ###################################################################################

        __PUB__ virtual ::string __VARIABLE__ ToString(const ::string __VARIABLE__ formatter) __override_func;
        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;

        // static functions
        __PUB__ static double __VARIABLE__ Parse(const ::string __VARIABLE__ s);
        __PUB__ static bool   __VARIABLE__ TryParse(const ::string __VARIABLE__ s, double __REFERENCE__ result);
        __PUB__ static bool   __VARIABLE__ TryParse(const ::string __VARIABLE__ s, Double __REFERENCE__ result);

        // const values
        __PUB__ const double __VARIABLE__ Epsilon = 4.94065645841247E-324;
        __PUB__ const double __VARIABLE__ MaxValue = 1.7976931348623157E+308;
        __PUB__ const double __VARIABLE__ MinValue = -1.7976931348623157E+308;

    };

    class Boolean final :
        public virtual tianyu::TianyuObject,
        public virtual tianyu::collection::IEquatable<Boolean>,
        public virtual tianyu::IFormatter
    {
        using CMPR = tianyu::collection::CompareResult;

        __PRI__ bool __VARIABLE__ _Value;

        __PUB__         __construction__ Boolean();
        __PUB__         __construction__ Boolean(bool __VARIABLE__ value);
        __PUB__         __cp_construct__ Boolean(const Boolean __REFERENCE__ value);
        __PUB__ virtual __destruction__  ~Boolean() __override_func;

        // ###################################################################################
        // operators __override_func
        // ###################################################################################
        __PUB__ virtual bool __VARIABLE__ Equals(TianyuObject __REFERENCE__ obj)     __override_func;
        __PUB__ virtual bool __VARIABLE__ operator==(TianyuObject __REFERENCE__ obj) __override_func;

        __PUB__ virtual bool __VARIABLE__ Equals(Boolean __REFERENCE__ other)      __override_func;
        __PUB__ virtual bool __VARIABLE__ operator ==(Boolean __REFERENCE__ other) __override_func;
        __PUB__ virtual bool __VARIABLE__ operator !=(Boolean __REFERENCE__ other) __override_func;

        __PUB__ operator bool();
        __PUB__ operator int32();

        __PUB__ bool __VARIABLE__ operator !();
        __PUB__ bool __VARIABLE__ operator &&(Boolean __REFERENCE__ value);
        __PUB__ bool __VARIABLE__ operator ||(Boolean __REFERENCE__ value);
        __PUB__ bool __VARIABLE__ operator =(Boolean __REFERENCE__ value);
        // ###################################################################################
        // operators __override_func end
        // ###################################################################################

        __PUB__ virtual ::string __VARIABLE__ ToString(const ::string __VARIABLE__ formatter) __override_func;
        __PUB__ virtual ::string __VARIABLE__ ToString()    noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId()   __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() __override_func;

        // static functions
        __PUB__ static bool __VARIABLE__ Parse(const ::string __VARIABLE__ s);
        __PUB__ static bool __VARIABLE__ TryParse(const ::string __VARIABLE__ s, bool __REFERENCE__ result);
        __PUB__ static bool __VARIABLE__ TryParse(const ::string __VARIABLE__ s, Boolean __REFERENCE__ result);

        // const values
        __PUB__ const bool  __VARIABLE__ MaxValue = true;
        __PUB__ const bool  __VARIABLE__ MinValue = false;
    };
}

#pragma region template realization

// ##########################################################
// BaseTypes Implementation
// ##########################################################

#include "./error.hpp"
#include <type_traits>

#define __TEMPLATE_DEF__ template<class TB, TB _Max, TB _Min>
#define __TINTEGER_DEF__ tianyu::TIntegerBase<TB, _Max, _Min>

#define __OPERATOR_OVERRIDE_DEF__(ret, type)                                    \
    __TEMPLATE_DEF__ ret __TINTEGER_DEF__::operator type(__TINTEGER_DEF__& obj) \
    {                                                                           \
        return this->_Value type obj._Value;                                    \
    }

#define __OPERATOR_EQ_OVERRIDE_DEF__(ret, type)                                 \
    __TEMPLATE_DEF__ ret __TINTEGER_DEF__::operator type(__TINTEGER_DEF__& obj) \
    {                                                                           \
        this->_Value = this->_Value type obj._Value;                            \
        return this->_Value;                                                    \
    }

#define __STATIC_ASSERT_DEF__                       \
    static_assert(                                  \
        !(std::is_base_of<char, TB>::value          \
        || std::is_base_of<uchar, TB>::value        \
        || std::is_base_of<int16, TB>::value        \
        || std::is_base_of<uint16, TB>::value       \
        || std::is_base_of<int32, TB>::value        \
        || std::is_base_of<uint32, TB>::value       \
        || std::is_base_of<int64, TB>::value        \
        || std::is_base_of<uint64, TB>::value),     \
        "only basic value data type is supported"   \
    )

__TEMPLATE_DEF__ __construction__ __TINTEGER_DEF__::TIntegerBase() :
    tianyu::TianyuObject(),
    tianyu::collection::ICompareable<TIntegerBase<TB, _Max, _Min>>(),
    tianyu::collection::IEquatable<TIntegerBase<TB, _Max, _Min>>(),
    tianyu::IFormatter(),
    _Value()
{
    __STATIC_ASSERT_DEF__;
}

__TEMPLATE_DEF__ __construction__ __TINTEGER_DEF__::TIntegerBase(TB value) :
    tianyu::TianyuObject(),
    tianyu::collection::ICompareable<TIntegerBase<TB, _Max, _Min>>(),
    tianyu::collection::IEquatable<TIntegerBase<TB, _Max, _Min>>(),
    tianyu::IFormatter(),
    _Value(value)
{
    __STATIC_ASSERT_DEF__;
}

__TEMPLATE_DEF__ __cp_construct__ __TINTEGER_DEF__::TIntegerBase(const __TINTEGER_DEF__& value)
    : tianyu::TianyuObject(),
    tianyu::collection::ICompareable<TIntegerBase<TB, _Max, _Min>>(),
    tianyu::collection::IEquatable<TIntegerBase<TB, _Max, _Min>>(),
    tianyu::IFormatter(),
    _Value(value._Value)
{ }

__TEMPLATE_DEF__ __destruction__  __TINTEGER_DEF__::~TIntegerBase() { }

__TEMPLATE_DEF__ bool __TINTEGER_DEF__::Equals(tianyu::TianyuObject& obj)
{
    if (this->GetTypeId() != obj.GetTypeId())
        return false;

    __TINTEGER_DEF__& cast_obj = dynamic_cast<__TINTEGER_DEF__&>(obj);
    return this->Equals(cast_obj);
}

__TEMPLATE_DEF__ bool __TINTEGER_DEF__::operator==(tianyu::TianyuObject& obj)
{
    return this->Equals(obj);
}

__TEMPLATE_DEF__ bool __TINTEGER_DEF__::Equals(__TINTEGER_DEF__& obj)
{
    return this->_Value == obj._Value;
}

__TEMPLATE_DEF__ tianyu::collection::CompareResult __TINTEGER_DEF__::CompareTo(__TINTEGER_DEF__& obj)
{
    if (this->_Value == obj._Value)
        return tianyu::collection::CompareResult::EQUAL;

    return this->_Value > obj._Value
        ? tianyu::collection::CompareResult::GREAT
        : tianyu::collection::CompareResult::LESS;
}

__TEMPLATE_DEF__ __TINTEGER_DEF__::operator TB()
{
    return this->_Value;
}

__TEMPLATE_DEF__ TB __TINTEGER_DEF__::operator++()
{
    this->_Value = this->_Value + 1;
    return this->_Value;
}

__TEMPLATE_DEF__ TB __TINTEGER_DEF__::operator--()
{
    this->_Value = this->_Value - 1;
    return this->_Value;
}

__TEMPLATE_DEF__ TB __TINTEGER_DEF__::operator++(int)
{
    TB preValue = this->_Value;
    this->_Value = this->_Value + 1;
    return preValue;
}

__TEMPLATE_DEF__ TB __TINTEGER_DEF__::operator--(int)
{
    TB preValue = this->_Value;
    this->_Value = this->_Value - 1;
    return preValue;
}

__TEMPLATE_DEF__ TB __TINTEGER_DEF__::operator!()
{
    return !(this->_Value);
}

__TEMPLATE_DEF__ TB __TINTEGER_DEF__::operator~()
{
    return ~(this->_Value);
}

__TEMPLATE_DEF__ TB __TINTEGER_DEF__::operator=(__TINTEGER_DEF__& obj)
{
    this->_Value = obj._Value;
    return this->_Value;
}

__TEMPLATE_DEF__::string __TINTEGER_DEF__::ToString() noexcept
{
    return this->ToString((::string)"");
}

__TEMPLATE_DEF__ uint64 __TINTEGER_DEF__::GetTypeId()
{
    return tianyu::GetType<TB>().Id();
}

__TEMPLATE_DEF__ uint64 __TINTEGER_DEF__::GetHashCode()
{
    return (uint64)(this);
}

__TEMPLATE_DEF__::string __TINTEGER_DEF__::ToString(const ::string formatter)
{
    return tianyu::FormatHelper::Format(this->_Value, formatter);
}

__TEMPLATE_DEF__ TB __TINTEGER_DEF__::Parse(const ::string s)
{
    TB value;

    tianyu::ParseHelper::Parse(s, value);

    return value;
}

__TEMPLATE_DEF__ bool __TINTEGER_DEF__::TryParse(const ::string s, TB& result)
{
    try
    {
        tianyu::ParseHelper::Parse(s, result);

        return true;
    }
    catch (const tianyu::except::Exception&)
    {
        return false;
    }
}

__TEMPLATE_DEF__ bool __TINTEGER_DEF__::TryParse(const ::string s, __TINTEGER_DEF__& result)
{
    try
    {
        tianyu::ParseHelper::Parse(s, result._Value);

        return true;
    }
    catch (const tianyu::except::Exception&)
    {
        return false;
    }
}

// implement some operator by macro define
// because they have the totally same structure
__OPERATOR_OVERRIDE_DEF__(bool, == )
__OPERATOR_OVERRIDE_DEF__(bool, != )
__OPERATOR_OVERRIDE_DEF__(bool, <= )
__OPERATOR_OVERRIDE_DEF__(bool, >= )
__OPERATOR_OVERRIDE_DEF__(bool, > )
__OPERATOR_OVERRIDE_DEF__(bool, < );

//
__OPERATOR_OVERRIDE_DEF__(TB, +)
__OPERATOR_OVERRIDE_DEF__(TB, -)
__OPERATOR_OVERRIDE_DEF__(TB, *)
__OPERATOR_OVERRIDE_DEF__(TB, / )
__OPERATOR_OVERRIDE_DEF__(TB, %)
__OPERATOR_OVERRIDE_DEF__(TB, &)
__OPERATOR_OVERRIDE_DEF__(TB, | )
__OPERATOR_OVERRIDE_DEF__(TB, ^)
__OPERATOR_OVERRIDE_DEF__(TB, << )
__OPERATOR_OVERRIDE_DEF__(TB, >> )

__OPERATOR_EQ_OVERRIDE_DEF__(TB, +=)
__OPERATOR_EQ_OVERRIDE_DEF__(TB, -=)
__OPERATOR_EQ_OVERRIDE_DEF__(TB, *=)
__OPERATOR_EQ_OVERRIDE_DEF__(TB, /=)
__OPERATOR_EQ_OVERRIDE_DEF__(TB, %=)
__OPERATOR_EQ_OVERRIDE_DEF__(TB, &=)
__OPERATOR_EQ_OVERRIDE_DEF__(TB, |=)
__OPERATOR_EQ_OVERRIDE_DEF__(TB, ^=)
__OPERATOR_EQ_OVERRIDE_DEF__(TB, >>=)
__OPERATOR_EQ_OVERRIDE_DEF__(TB, <<=)

// to cancel the macro definitions
#undef __TEMPLATE_DEF__
#undef __TINTEGER_DEF__

#undef __OPERATOR_OVERRIDE_DEF__
#undef __OPERATOR_EQ_OVERRIDE_DEF__
#undef __STATIC_ASSERT_DEF__

#pragma endregion

namespace tianyu
{
    using Char = tianyu::TIntegerBase<char, __SIGNED_CHAR_MAX__, __SIGNED_CHAR_MIN__>;
    using UChar = tianyu::TIntegerBase<uchar, __UNSIGNED_CHAR_MAX__, __UNSIGNED_CHAR_MIN__>;

    using Byte = tianyu::TIntegerBase<byte, __UNSIGNED_CHAR_MAX__, __UNSIGNED_CHAR_MIN__>;
    using SByte = tianyu::TIntegerBase<sbyte, __SIGNED_CHAR_MAX__, __SIGNED_CHAR_MIN__>;

    using Int16 = tianyu::TIntegerBase<int16, __SIGNED_INT16_MAX__, __SIGNED_INT16_MIN__>;
    using UInt16 = tianyu::TIntegerBase<uint16, __UNSIGNED_INT16_MAX__, __UNSIGNED_INT16_MIN__>;

    using Short = tianyu::TIntegerBase<int16, __SIGNED_INT16_MAX__, __SIGNED_INT16_MIN__>;
    using UShort = tianyu::TIntegerBase<uint16, __UNSIGNED_INT16_MAX__, __UNSIGNED_INT16_MIN__>;

    using Int32 = tianyu::TIntegerBase<int32, __SIGNED_INT32_MAX__, __SIGNED_INT32_MIN__>;
    using UInt32 = tianyu::TIntegerBase<uint32, __UNSIGNED_INT32_MAX__, __UNSIGNED_INT32_MIN__>;

    using Int64 = tianyu::TIntegerBase<int64, __SIGNED_INT64_MAX__, __SIGNED_INT64_MIN__>;
    using UInt64 = tianyu::TIntegerBase<uint64, __UNSIGNED_INT64_MAX__, __UNSIGNED_INT64_MIN__>;

    using Long = tianyu::TIntegerBase<int64, __SIGNED_INT64_MAX__, __SIGNED_INT64_MIN__>;
    using ULong = tianyu::TIntegerBase<uint64, __UNSIGNED_INT64_MAX__, __UNSIGNED_INT64_MIN__>;
}

#endif // !__cplusplus

#endif // !__TIANYU_COMMON_NATIVE_CORE_BASETYPE_H_PLUS_PLUS__