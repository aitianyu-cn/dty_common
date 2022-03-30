#include "../common.hpp"

extern const byte UnusedValue;

extern const char CalcSym_Add;
extern const char CalcSym_Mul;

// #####################################################################
// each byte uses 0-19 total 20 numbers
// 0: unused byte
// 1: -9
// 2: -8
// 3: -7
// 4: -6
// 5: -5
// 6: -4
// 7: -3
// 8: -2
// 9: -1
// 10: 0
// 11: 1
// 12: 2
// 13: 3
// 14: 4
// 15: 5
// 16: 6
// 17: 7
// 18: 8
// 19: 9
// ---------------------------------------------------------------------
// considering 0-199 total 200 numbers
// 100 scaling
// ---------------------------------------------------------------------
// 0: 0
// 1: 1
// 2: 2
// 3: 3
// 4: 4
// 5: 5
// 6: 6
// 7: 7
// 8: 8
// 9: 9
// 255: unused byte
// ---------------------------------------------------------------------
// considering 0-99 total 100 numbers
// 100 scaling
// #####################################################################

#define _Get_End(length) (length - 1)
#define _Is_Out_Start(index) (0 > index)
#define _Is_Not_Out_Start(index) (0 <= index)
#define _Is_Out_End(index, length) (length <= index)
#define _Is_Not_Out_End(index, length) (length > index)

using CMPRes = dty::math::NumberCompareResult;
using MetaData = dty::math::BigNumCalcMetadata;

bool     __VARIABLE__ _internal_validate_op(MetaData __REFERENCE__ op);
bool     __VARIABLE__ _internal_validate_op(MetaData __REFERENCE__ op1, MetaData __REFERENCE__ op2);

MetaData __VARIABLE__ _internal_get_NaNValue();
MetaData __VARIABLE__ _internal_get_value_like(MetaData __REFERENCE__ likeOn);
MetaData __VARIABLE__ _internal_create_results(MetaData __REFERENCE__ op1, MetaData __REFERENCE__ op2, const char __VARIABLE__ growth = '\0');

void     __VARIABLE__ _internal_add(MetaData __REFERENCE__ op1, MetaData __REFERENCE__ op2, MetaData __REFERENCE__ res, bool  __VARIABLE__ carry);
void     __VARIABLE__ _internal_sub(MetaData __REFERENCE__ op1, MetaData __REFERENCE__ op2, MetaData __REFERENCE__ res, bool  __VARIABLE__ borrow);
void     __VARIABLE__ _internal_mul(MetaData __REFERENCE__ op1, MetaData __REFERENCE__ op2, MetaData __REFERENCE__ res);
void     __VARIABLE__ _internal_div(MetaData __REFERENCE__ op1, MetaData __REFERENCE__ op2, MetaData __REFERENCE__ res);
void     __VARIABLE__ _internal_mod(MetaData __REFERENCE__ op1, MetaData __REFERENCE__ op2, MetaData __REFERENCE__ res);

_internal_export bool   __VARIABLE__ _bytes_is_zero(MetaData __REFERENCE__ op)
{
    if (!::_internal_validate_op(op))
        return false;

    int32 startIndex = op._PhySize - op._MathSize;
    for (int i = startIndex; i < op._PhySize; ++i)
        if (0 != op._Value[i])
            return false;

    return true;
}
_internal_export CMPRes __VARIABLE__ _bytes_compare(MetaData __REFERENCE__ op1, MetaData __REFERENCE__ op2)
{
    if (::_internal_validate_op(op1, op2))
        return CMPRes::NaN;

    if (op1._MathSize > op2._MathSize)
        return CMPRes::GreatThan;

    if (op1._MathSize < op2._MathSize)
        return CMPRes::LessThan;

    int32 op1StartIndex = op1._PhySize - op1._MathSize;
    int32 op2StartIndex = op2._PhySize - op2._MathSize;
    for (; op1StartIndex < op1._PhySize && op2StartIndex < op2._PhySize; ++op1StartIndex, ++op2StartIndex)
    {
        if (op1._Value[op1StartIndex] > op2._Value[op2StartIndex])
            return CMPRes::GreatThan;
        else if (op1._Value[op1StartIndex] < op2._Value[op2StartIndex])
            return CMPRes::LessThan;
    }

    return CMPRes::Equal;
}
/**
 * @brief
 *
 * @param op1   {byte *}  provides the first operation number
 * @param op1_l {int32}   indicates the length of the first operation number
 * @param op2   {byte *}  provides the second operation number
 * @param op2_l {int32}   indicates the length of the second operation number
 * @param res_l {int32 &} to return the number length of the result
 * @param req_l {int32 &} to return the byte array length of the result
 * @return {byte} return the result bytes array
 */
_internal_export MetaData __VARIABLE__ _bytes_calc_add(MetaData __REFERENCE__ op1, MetaData __REFERENCE__ op2)
{
    if (!::_internal_validate_op(op1, op2))
        // if operation number is not valid, should return a invalid result
        return ::_internal_get_NaNValue();

    // calculating the result bytes length and create result set.
    MetaData resultData = ::_internal_create_results(op1, op2, CalcSym_Add);

    ::_internal_add(op1, op2, resultData, false);

    // return result
    return resultData;
}
/**
 * @brief
 *
 * @param op1   {byte *}  provides the first operation number
 * @param op1_l {int32}   indicates the length of the first operation number
 * @param op2   {byte *}  provides the second operation number
 * @param op2_l {int32}   indicates the length of the second operation number
 * @param res_l {int32 &} to return the number length of the result
 * @param req_l {int32 &} to return the byte array length of the result
 * @return {byte} return the result bytes array
 */
_internal_export MetaData __VARIABLE__ _bytes_calc_sub(MetaData __REFERENCE__ op1, MetaData __REFERENCE__ op2)
{
    if (!::_internal_validate_op(op1, op2))
        // if operation number is not valid, should return a invalid result
        return ::_internal_get_NaNValue();

    // calculating the result bytes length and create result set.
    MetaData resultData = ::_internal_create_results(op1, op2);

    ::_internal_add(op1, op2, resultData, false);

    // return result
    return resultData;
}
_internal_export byte __POINTER__ _bytes_calc_mul(byte __POINTER__ op1, int32 __VARIABLE__ op1_l, byte __POINTER__ op2, int32 __VARIABLE__ op2_l, int32 __REFERENCE__ res_l);
_internal_export byte __POINTER__ _bytes_calc_div(byte __POINTER__ op1, int32 __VARIABLE__ op1_l, byte __POINTER__ op2, int32 __VARIABLE__ op2_l, int32 __REFERENCE__ res_l);
_internal_export byte __POINTER__ _bytes_calc_mod(byte __POINTER__ op1, int32 __VARIABLE__ op1_l, byte __POINTER__ op2, int32 __VARIABLE__ op2_l, int32 __REFERENCE__ res_l);


// ##################################################################################
// internal calculation implementation
// ##################################################################################
bool     _internal_validate_op(MetaData& op)
{
    return ::null != op._Value
        && 0 < op._PhySize
        && 0 < op._MathSize
        && op._PhySize >= op._MathSize;
}
bool     _internal_validate_op(MetaData& op1, MetaData& op2)
{
    return ::_internal_validate_op(op1) && ::_internal_validate_op(op2);
}
MetaData _internal_get_NaNValue()
{
    MetaData NaNValue;
    NaNValue._Value = ::null;
    NaNValue._PhySize = 0;
    NaNValue._MathSize = 0;
    return NaNValue;
}
MetaData _internal_get_value_like(MetaData& likeOn)
{
    if (!::_internal_validate_op(likeOn))
        return ::_internal_get_NaNValue();

    MetaData newData;
    newData._MathSize = 0;
    newData._PhySize = likeOn._PhySize;

    newData._Value = new byte[newData._PhySize];
    return newData;
}
MetaData _internal_create_results(MetaData& op1, MetaData& op2, const char growth = '\0')
{
    MetaData data;
    data._Value = ::null;
    data._MathSize = 0;
    data._PhySize = 0;

    bool calculation_direction = op1._MathSize > op2._MathSize;
    // calculating the result bytes length and create result set.
    switch (growth)
    {
    case '+':
        data._PhySize = (calculation_direction ? op1._MathSize : op2._MathSize) + 1;
        break;
    case '*':
        data._PhySize = op1._MathSize + op2._MathSize + 2;
        break;
    default:
        data._PhySize = calculation_direction ? op1._MathSize : op2._MathSize;
        break;
    }
    data._Value = new byte[data._PhySize];

    return data;
}
void     _internal_add(MetaData& op1, MetaData& op2, MetaData& res, bool carry)
{
    /// using end align
    int32 indexResult = _Get_End(res._PhySize);
    int32 indexOP1 = _Get_End(op1._PhySize), indexOP2 = _Get_End(op2._PhySize);
    int32 startOP1 = op1._PhySize - op1._MathSize, startOP2 = op2._PhySize - op2._MathSize;
    for (
        ; startOP1 <= indexOP1 && startOP2 <= indexOP2
        ; --indexOP1, --indexOP2, --indexResult
        )
    {
        int32 value = op1._Value[indexOP1] + op2._Value[indexOP2] + (carry ? 1 : 0);
        if (10 <= value)
        {
            value = value - 10;
            carry = true;
        }
        else
            carry = false;
        res._Value[indexResult] = (byte)(value & 0xFF);
    }

    // step 2: to do add for longer op-number
    auto fnProcessLongerOP = [&](byte* opNum, int32& index, int32& start) -> void
    {
        for (; start <= index; --index, --indexResult)
        {
            int32 value = opNum[index] + (carry ? 1 : 0);
            if (10 <= value)
            {
                value = value - 10;
                carry = true;
            }
            else
                carry = false;
            res._Value[indexResult] = (byte)(value & 0xFF);
        }
    };

    if (startOP1 <= indexOP1)
        fnProcessLongerOP(op1._Value, indexOP1, startOP1);
    else if (startOP2 <= indexOP2)
        fnProcessLongerOP(op2._Value, indexOP2, startOP2);

    // over all of the existed value
    if (carry)
        res._Value[indexResult--] = 0x01;

    // set the results length
    res._MathSize = res._PhySize - indexResult - 1;
}
void     _internal_sub(MetaData& op1, MetaData& op2, MetaData& res, bool borrow)
{

}

