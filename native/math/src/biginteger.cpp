#include "../bignumber.hpp"

#define BIG_INT_CLASS_DEF dty::math::BigInteger

extern const char CalcSym_Add;
extern const char CalcSym_Sub;
extern const char CalcSym_SubBy;
extern const char CalcSym_Mul;
extern const char CalcSym_Div;
extern const char CalcSym_DivBy;
extern const char CalcSym_Mod;
extern const char CalcSym_ModBy;
extern const char CalcSym_And;
extern const char CalcSym_Or;
extern const char CalcSym_Xor;
extern const char CalcSym_Not;

extern byte __POINTER__ _bytes_calc_and(byte __POINTER__ op1, int32 __VARIABLE__ op1_l, byte __POINTER__ op2, int32 __VARIABLE__ op2_l, int32 __REFERENCE__ res_l);
extern byte __POINTER__ _bytes_calc_or(byte __POINTER__ op1, int32 __VARIABLE__ op1_l, byte __POINTER__ op2, int32 __VARIABLE__ op2_l, int32 __REFERENCE__ res_l);
extern byte __POINTER__ _bytes_calc_xor(byte __POINTER__ op1, int32 __VARIABLE__ op1_l, byte __POINTER__ op2, int32 __VARIABLE__ op2_l, int32 __REFERENCE__ res_l);
extern byte __POINTER__ _bytes_calc_not(byte __POINTER__ op1, int32 __VARIABLE__ op1_l, int32 __REFERENCE__ res_l);
extern byte __POINTER__ _bytes_calc_add(byte __POINTER__ op1, int32 __VARIABLE__ op1_l, byte __POINTER__ op2, int32 __VARIABLE__ op2_l, int32 __REFERENCE__ res_l);
extern byte __POINTER__ _bytes_calc_sub(byte __POINTER__ op1, int32 __VARIABLE__ op1_l, byte __POINTER__ op2, int32 __VARIABLE__ op2_l, int32 __REFERENCE__ res_l);
extern byte __POINTER__ _bytes_calc_mul(byte __POINTER__ op1, int32 __VARIABLE__ op1_l, byte __POINTER__ op2, int32 __VARIABLE__ op2_l, int32 __REFERENCE__ res_l);
extern byte __POINTER__ _bytes_calc_div(byte __POINTER__ op1, int32 __VARIABLE__ op1_l, byte __POINTER__ op2, int32 __VARIABLE__ op2_l, int32 __REFERENCE__ res_l);
extern byte __POINTER__ _bytes_calc_mod(byte __POINTER__ op1, int32 __VARIABLE__ op1_l, byte __POINTER__ op2, int32 __VARIABLE__ op2_l, int32 __REFERENCE__ res_l);

uint64 BIG_INT_CLASS_DEF::GetTypeId()
{
    return dty::GetType<BIG_INT_CLASS_DEF>().Id();
}

// ##############################################################
// Operator Function Part
// ##############################################################

#pragma region And Operator
void BIG_INT_CLASS_DEF::And(int32 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->And(opValue);
}
void BIG_INT_CLASS_DEF::And(int64 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->And(opValue);
}
void BIG_INT_CLASS_DEF::And(uint32 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->And(opValue);
}
void BIG_INT_CLASS_DEF::And(uint64 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->And(opValue);
}
void BIG_INT_CLASS_DEF::And(double value)
{
    BIG_INT_CLASS_DEF opValue((int64)value);

    this->And(opValue);
}
void BIG_INT_CLASS_DEF::And(::string value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->And(opValue);
}
void BIG_INT_CLASS_DEF::And(dty::math::BigNumber& value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->And(opValue);
}
void BIG_INT_CLASS_DEF::And(BIG_INT_CLASS_DEF& value)
{
    this->Calculation(CalcSym_And, value);
}
#pragma endregion

#pragma region Or Operator
void BIG_INT_CLASS_DEF::Or(int32 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Or(opValue);
}
void BIG_INT_CLASS_DEF::Or(int64 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Or(opValue);
}
void BIG_INT_CLASS_DEF::Or(uint32 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Or(opValue);
}
void BIG_INT_CLASS_DEF::Or(uint64 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Or(opValue);
}
void BIG_INT_CLASS_DEF::Or(double value)
{
    BIG_INT_CLASS_DEF opValue((int64)value);

    this->Or(opValue);
}
void BIG_INT_CLASS_DEF::Or(::string value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Or(opValue);
}
void BIG_INT_CLASS_DEF::Or(dty::math::BigNumber& value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Or(opValue);
}
void BIG_INT_CLASS_DEF::Or(BIG_INT_CLASS_DEF& value)
{
    this->Calculation(CalcSym_Or, value);
}
#pragma endregion

#pragma region Xor Operator
void BIG_INT_CLASS_DEF::Xor(int32 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Xor(opValue);
}
void BIG_INT_CLASS_DEF::Xor(int64 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Xor(opValue);
}
void BIG_INT_CLASS_DEF::Xor(uint32 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Xor(opValue);
}
void BIG_INT_CLASS_DEF::Xor(uint64 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Xor(opValue);
}
void BIG_INT_CLASS_DEF::Xor(double value)
{
    BIG_INT_CLASS_DEF opValue((int64)value);

    this->Xor(opValue);
}
void BIG_INT_CLASS_DEF::Xor(::string value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Xor(opValue);
}
void BIG_INT_CLASS_DEF::Xor(dty::math::BigNumber& value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Xor(opValue);
}
void BIG_INT_CLASS_DEF::Xor(BIG_INT_CLASS_DEF& value)
{
    this->Calculation(CalcSym_Xor, value);
}
#pragma endregion

#pragma region Not Operator
void BIG_INT_CLASS_DEF::Not()
{
    this->Calculation(CalcSym_Not, __PTR_TO_REF__ this);
}
#pragma endregion

#pragma region Add Operator
void BIG_INT_CLASS_DEF::Add(int32 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Add(opValue);
}
void BIG_INT_CLASS_DEF::Add(int64 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Add(opValue);
}
void BIG_INT_CLASS_DEF::Add(uint32 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Add(opValue);
}
void BIG_INT_CLASS_DEF::Add(uint64 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Add(opValue);
}
void BIG_INT_CLASS_DEF::Add(double value)
{
    BIG_INT_CLASS_DEF opValue((int64)value);

    this->Add(opValue);
}
void BIG_INT_CLASS_DEF::Add(::string value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Add(opValue);
}
void BIG_INT_CLASS_DEF::Add(dty::math::BigNumber& value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Add(opValue);
}
void BIG_INT_CLASS_DEF::Add(BIG_INT_CLASS_DEF& value)
{
    this->Calculation(CalcSym_Add, value);
}
#pragma endregion

#pragma region Sub Operator
void BIG_INT_CLASS_DEF::Sub(int32 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Sub(opValue);
}
void BIG_INT_CLASS_DEF::Sub(int64 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Sub(opValue);
}
void BIG_INT_CLASS_DEF::Sub(uint32 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Sub(opValue);
}
void BIG_INT_CLASS_DEF::Sub(uint64 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Sub(opValue);
}
void BIG_INT_CLASS_DEF::Sub(double value)
{
    BIG_INT_CLASS_DEF opValue((int64)value);

    this->Sub(opValue);
}
void BIG_INT_CLASS_DEF::Sub(::string value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Sub(opValue);
}
void BIG_INT_CLASS_DEF::Sub(dty::math::BigNumber& value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Sub(opValue);
}
void BIG_INT_CLASS_DEF::Sub(BIG_INT_CLASS_DEF& value)
{
    this->Calculation(CalcSym_Sub, value);
}
#pragma endregion

#pragma region SubBy Operator
void BIG_INT_CLASS_DEF::SubBy(int32 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->SubBy(opValue);
}
void BIG_INT_CLASS_DEF::SubBy(int64 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->SubBy(opValue);
}
void BIG_INT_CLASS_DEF::SubBy(uint32 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->SubBy(opValue);
}
void BIG_INT_CLASS_DEF::SubBy(uint64 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->SubBy(opValue);
}
void BIG_INT_CLASS_DEF::SubBy(double value)
{
    BIG_INT_CLASS_DEF opValue((int64)value);

    this->SubBy(opValue);
}
void BIG_INT_CLASS_DEF::SubBy(::string value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->SubBy(opValue);
}
void BIG_INT_CLASS_DEF::SubBy(dty::math::BigNumber& value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->SubBy(opValue);
}
void BIG_INT_CLASS_DEF::SubBy(BIG_INT_CLASS_DEF& value)
{
    this->Calculation(CalcSym_SubBy, value);
}
#pragma endregion

#pragma region Mul Operator
void BIG_INT_CLASS_DEF::Mul(int32 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Mul(opValue);
}
void BIG_INT_CLASS_DEF::Mul(int64 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Mul(opValue);
}
void BIG_INT_CLASS_DEF::Mul(uint32 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Mul(opValue);
}
void BIG_INT_CLASS_DEF::Mul(uint64 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Mul(opValue);
}
void BIG_INT_CLASS_DEF::Mul(double value)
{
    BIG_INT_CLASS_DEF opValue((int64)value);

    this->Mul(opValue);
}
void BIG_INT_CLASS_DEF::Mul(::string value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Mul(opValue);
}
void BIG_INT_CLASS_DEF::Mul(dty::math::BigNumber& value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Mul(opValue);
}
void BIG_INT_CLASS_DEF::Mul(BIG_INT_CLASS_DEF& value)
{
    this->Calculation(CalcSym_Mul, value);
}
#pragma endregion

#pragma region Div Operator
void BIG_INT_CLASS_DEF::Div(int32 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Div(opValue);
}
void BIG_INT_CLASS_DEF::Div(int64 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Div(opValue);
}
void BIG_INT_CLASS_DEF::Div(uint32 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Div(opValue);
}
void BIG_INT_CLASS_DEF::Div(uint64 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Div(opValue);
}
void BIG_INT_CLASS_DEF::Div(double value)
{
    BIG_INT_CLASS_DEF opValue((int64)value);

    this->Div(opValue);
}
void BIG_INT_CLASS_DEF::Div(::string value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Div(opValue);
}
void BIG_INT_CLASS_DEF::Div(dty::math::BigNumber& value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Div(opValue);
}
void BIG_INT_CLASS_DEF::Div(BIG_INT_CLASS_DEF& value)
{
    this->Calculation(CalcSym_Div, value);
}
#pragma endregion

#pragma region DivBy Operator
void BIG_INT_CLASS_DEF::DivBy(int32 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->DivBy(opValue);
}
void BIG_INT_CLASS_DEF::DivBy(int64 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->DivBy(opValue);
}
void BIG_INT_CLASS_DEF::DivBy(uint32 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->DivBy(opValue);
}
void BIG_INT_CLASS_DEF::DivBy(uint64 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->DivBy(opValue);
}
void BIG_INT_CLASS_DEF::DivBy(double value)
{
    BIG_INT_CLASS_DEF opValue((int64)value);

    this->DivBy(opValue);
}
void BIG_INT_CLASS_DEF::DivBy(::string value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->DivBy(opValue);
}
void BIG_INT_CLASS_DEF::DivBy(dty::math::BigNumber& value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->DivBy(opValue);
}
void BIG_INT_CLASS_DEF::DivBy(BIG_INT_CLASS_DEF& value)
{
    this->Calculation(CalcSym_DivBy, value);
}
#pragma endregion

#pragma region Mod Operator
void BIG_INT_CLASS_DEF::Mod(int32 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Mod(opValue);
}
void BIG_INT_CLASS_DEF::Mod(int64 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Mod(opValue);
}
void BIG_INT_CLASS_DEF::Mod(uint32 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Mod(opValue);
}
void BIG_INT_CLASS_DEF::Mod(uint64 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Mod(opValue);
}
void BIG_INT_CLASS_DEF::Mod(double value)
{
    BIG_INT_CLASS_DEF opValue((int64)value);

    this->Mod(opValue);
}
void BIG_INT_CLASS_DEF::Mod(::string value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Mod(opValue);
}
void BIG_INT_CLASS_DEF::Mod(dty::math::BigNumber& value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->Mod(opValue);
}
void BIG_INT_CLASS_DEF::Mod(BIG_INT_CLASS_DEF& value)
{
    this->Calculation(CalcSym_Mod, value);
}
#pragma endregion

#pragma region ModBy Operator
void BIG_INT_CLASS_DEF::ModBy(int32 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->ModBy(opValue);
}
void BIG_INT_CLASS_DEF::ModBy(int64 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->ModBy(opValue);
}
void BIG_INT_CLASS_DEF::ModBy(uint32 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->ModBy(opValue);
}
void BIG_INT_CLASS_DEF::ModBy(uint64 value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->ModBy(opValue);
}
void BIG_INT_CLASS_DEF::ModBy(double value)
{
    BIG_INT_CLASS_DEF opValue((int64)value);

    this->ModBy(opValue);
}
void BIG_INT_CLASS_DEF::ModBy(::string value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->ModBy(opValue);
}
void BIG_INT_CLASS_DEF::ModBy(dty::math::BigNumber& value)
{
    BIG_INT_CLASS_DEF opValue(value);

    this->ModBy(opValue);
}
void BIG_INT_CLASS_DEF::ModBy(BIG_INT_CLASS_DEF& value)
{
    this->Calculation(CalcSym_ModBy, value);
}
#pragma endregion

// ##############################################################
// Operator Implementation
// ##############################################################
BIG_INT_CLASS_DEF dty::math::operator+ (BIG_INT_CLASS_DEF& op1, BIG_INT_CLASS_DEF& op2)
{
    BIG_INT_CLASS_DEF newInteger;
    newInteger.Copy(op1);

    newInteger.Add(op2);

    return newInteger;
}
BIG_INT_CLASS_DEF dty::math::operator- (BIG_INT_CLASS_DEF& op1, BIG_INT_CLASS_DEF& op2)
{
    BIG_INT_CLASS_DEF newInteger;
    newInteger.Copy(op1);

    newInteger.Sub(op2);

    return newInteger;
}
BIG_INT_CLASS_DEF dty::math::operator* (BIG_INT_CLASS_DEF& op1, BIG_INT_CLASS_DEF& op2)
{
    BIG_INT_CLASS_DEF newInteger;
    newInteger.Copy(op1);

    newInteger.Mul(op2);

    return newInteger;
}
BIG_INT_CLASS_DEF dty::math::operator/ (BIG_INT_CLASS_DEF& op1, BIG_INT_CLASS_DEF& op2)
{
    BIG_INT_CLASS_DEF newInteger;
    newInteger.Copy(op1);

    newInteger.Div(op2);

    return newInteger;
}
BIG_INT_CLASS_DEF dty::math::operator& (BIG_INT_CLASS_DEF& op1, BIG_INT_CLASS_DEF& op2)
{
    BIG_INT_CLASS_DEF newInteger;
    newInteger.Copy(op1);

    newInteger.And(op2);

    return newInteger;
}
BIG_INT_CLASS_DEF dty::math::operator| (BIG_INT_CLASS_DEF& op1, BIG_INT_CLASS_DEF& op2)
{
    BIG_INT_CLASS_DEF newInteger;
    newInteger.Copy(op1);

    newInteger.Or(op2);

    return newInteger;
}
BIG_INT_CLASS_DEF dty::math::operator^ (BIG_INT_CLASS_DEF& op1, BIG_INT_CLASS_DEF& op2)
{
    BIG_INT_CLASS_DEF newInteger;
    newInteger.Copy(op1);

    newInteger.Xor(op2);

    return newInteger;
}
BIG_INT_CLASS_DEF dty::math::operator! (BIG_INT_CLASS_DEF& op1)
{
    BIG_INT_CLASS_DEF newInteger;
    newInteger.Copy(op1);

    newInteger.Not();

    return newInteger;
}