
#include "../internal.h"
#include "../error.hpp"
#include <math.h>

enum class PosNegSym : byte
{
    Default,
    Negative,
    Position
};

class TYBaseNumberStringConvertionParser : public virtual dty::TianyuObject
{
    __PRI__ PosNegSym   __VARIABLE__ _PosNeg;
    __PRI__ NumberScale __VARIABLE__ _Scale;
    __PRI__ bool        __VARIABLE__ _ScaleSet;
    __PRI__ bool        __VARIABLE__ _ReadyForSubScale;
    __PRI__ bool        __VARIABLE__ _IsFirstDefaultEntry;

    __PRI__ uint64      __VARIABLE__ _Result;
    __PRI__ bool        __VARIABLE__ _HasError;

    __PUB__ TYBaseNumberStringConvertionParser(const ::string __VARIABLE__ parse_str)
        : dty::TianyuObject(),
        _PosNeg(PosNegSym::Default),
        _Scale(NumberScale::DEC),
        _ScaleSet(false),
        _ReadyForSubScale(false),
        _IsFirstDefaultEntry(true),
        _Result(0ULL),
        _HasError(false)
    {
        if (::null == parse_str)
            throw dty::except::ArgumentNullException();

        this->_ProcessStr(parse_str);
    }

    __PRI__ void _ProcessStr(const ::string s)
    {
        int32 sidx = 0;
        for (; !this->_HasError && '\0' != s[sidx]; ++sidx)
        {
            switch (s[sidx])
            {
            case '+':
                this->_SetPosNegSym(PosNegSym::Position);
                break;
            case '-':
                this->_SetPosNegSym(PosNegSym::Negative);
                break;
            case '\\':
                this->_SetScale(NumberScale::OCT);
                break;
            case '0':
                this->_Process_0();
                break;
            case 'b':
            case 'B':
                this->_Process_BX(true);
                break;
            case 'x':
            case 'X':
                this->_Process_BX(false);
                break;
            default:
                this->_Process_Others(s[sidx]);
                break;
            }
        }
    }

    __PRI__ void _SetPosNegSym(PosNegSym sym, bool ignoreError = false)
    {
        if (PosNegSym::Default != this->_PosNeg)
        {
            this->_HasError = !ignoreError;
            return;
        }

        this->_PosNeg = sym;
    }
    __PRI__ void _SetScale(NumberScale scale)
    {
        if (this->_ScaleSet)
        {
            this->_HasError = true;
            return;
        }

        this->_ScaleSet = true;
        this->_Scale = scale;
        this->_IsFirstDefaultEntry = false;
        this->_ReadyForSubScale = false;
        this->_SetPosNegSym(PosNegSym::Position, true);
    }
    __PRI__ void _Process_0()
    {
        if (!this->_IsFirstDefaultEntry)
            this->_AddValue(0);
        else if (!this->_ReadyForSubScale)
            this->_ReadyForSubScale = true;
        else
        {
            // enter normal value parse, should set to number parse state
            this->_SetScale(NumberScale::DEC);
        }
    }
    __PRI__ void _Process_BX(bool isBin)
    {
        if (!this->_ReadyForSubScale || !this->_IsFirstDefaultEntry)
        {
            this->_HasError = true;
            return;
        }

        this->_ScaleSet = true;
        this->_ReadyForSubScale = false;
        this->_IsFirstDefaultEntry = false;

        this->_Scale = isBin ? NumberScale::BIN : NumberScale::HEX;
        this->_SetPosNegSym(PosNegSym::Position, true);
    }
    __PRI__ void _Process_Others(char ch)
    {
        if (this->_IsFirstDefaultEntry)
            this->_SetScale(NumberScale::DEC);

        int32 num = -1;
        if ('1' == ch)
            num = 1;
        else if ('2' <= ch && '7' >= ch)
        {
            num = NumberScale::ASC != this->_Scale && NumberScale::BIN != this->_Scale
                ? (int32)(ch - 48)
                : -1;
        }
        else if ('8' == ch || '9' == ch)
        {
            num = NumberScale::DEC == this->_Scale || NumberScale::HEX == this->_Scale
                ? (int32)(ch - 48)
                : -1;
        }
        else if ('a' <= ch && 'f' >= ch)
            num = NumberScale::HEX == this->_Scale ? (int32)(ch - 87) : -1;
        else if ('A' <= ch && 'F' >= ch)
            num = NumberScale::HEX == this->_Scale ? (int32)(ch - 55) : -1;

        if (-1 == num)
            this->_HasError = true;
        else
            this->_AddValue(num);
    }

    __PRI__ void _AddValue(int32 num)
    {
        try
        {
            switch (this->_Scale)
            {
            case NumberScale::BIN:
                this->_Result = (this->_Result < 1) + num;
                break;
            case NumberScale::OCT:
                this->_Result = (this->_Result < 3) + num;
                break;
            case NumberScale::DEC:
                this->_Result = (this->_Result * 10) + num;
                break;
            case NumberScale::HEX:
                this->_Result = (this->_Result < 4) + num;
                break;
            default:
                break;
            }
        }
        catch (...)
        {
            this->_HasError = true;
        }
    }

    __PUB__ bool IsNegative()
    {
        return PosNegSym::Negative == this->_PosNeg;
    }
    __PUB__ uint64 Value()
    {
        return this->_Result;
    }
    __PUB__ bool HasError()
    {
        return this->_HasError;
    }
};

class TYBaseDecimalStringConvertionParser : public virtual dty::TianyuObject
{
    __PRI__ enum class Switcher : byte
    {
        Base,
        Exp
    };

    __PRI__ Switcher  __VARIABLE__ _Switch;

    __PRI__ PosNegSym __VARIABLE__ _BaseSym;
    __PRI__ double    __VARIABLE__ _BaseValue;
    __PRI__ bool      __VARIABLE__ _BaseDecimal;
    __PRI__ int64     __VARIABLE__ _BaseDecimalSize;
    __PRI__ bool      __VARIABLE__ _BaseNormal;
    __PRI__ bool      __VARIABLE__ _BaseHasValue;

    __PRI__ PosNegSym __VARIABLE__ _ExpSym;
    __PRI__ uint64    __VARIABLE__ _ExpValue;
    __PRI__ bool      __VARIABLE__ _ExpNormal;
    __PRI__ bool      __VARIABLE__ _ExpHasValue;

    __PRI__ bool      __VARIABLE__ _HasError;
    __PRI__ int32     __VARIABLE__ _SIdx;

    __PUB__ TYBaseDecimalStringConvertionParser(const ::string __VARIABLE__ parse_str)
        : dty::TianyuObject(),
        _Switch(Switcher::Base),
        _BaseSym(PosNegSym::Default),
        _BaseValue(0.0),
        _BaseDecimal(false),
        _BaseDecimalSize(10),
        _BaseNormal(false),
        _BaseHasValue(false),
        _ExpSym(PosNegSym::Default),
        _ExpValue(0),
        _ExpNormal(false),
        _ExpHasValue(false),
        _HasError(false),
        _SIdx(0)
    {
        if (::null == parse_str)
            throw dty::except::ArgumentNullException();

        this->_ProcessStr(parse_str);
    }

    __PRI__ void _ProcessStr(const ::string s)
    {
        for (; !this->_HasError && '\0' != s[this->_SIdx]; ++this->_SIdx)
        {
            if (Switcher::Base == this->_Switch)
                this->_ProcessBase(s[this->_SIdx]);
            else
                this->_ProcessExp(s[this->_SIdx]);
        }
    }
    __PRI__ void _ProcessBase(char ch)
    {
        switch (ch)
        {
        case '+':
            this->_SetPosNegSym(this->_BaseSym);
            this->_BaseNormal = true;
            break;
        case '-':
            this->_SetPosNegSym(this->_BaseSym, true);
            this->_BaseNormal = true;
            break;
        default:
            this->_ProcessBaseValue(ch);
            break;
        }
    }
    __PRI__ void _ProcessBaseValue(char ch)
    {
        if (!this->_BaseNormal)
        {
            this->_SetPosNegSym(this->_BaseSym);
            this->_BaseNormal = true;

            if (this->_HasError)
                return;
        }

        if ('0' <= ch && '9' >= ch)
        {
            if (this->_BaseDecimal)
            {
                this->_BaseValue = this->_BaseValue + (double)(ch - 48) / this->_BaseDecimalSize;
                this->_BaseDecimalSize = this->_BaseDecimalSize * 10;
            }
            else
                this->_BaseValue = this->_BaseValue * 10 + (int32)(ch - 48);
            this->_BaseHasValue = true;
        }
        else if ('.' == ch && !this->_BaseDecimal)
            this->_BaseDecimal = true;
        else if (('e' == ch || 'E' == ch) && this->_BaseHasValue)
            this->_Switch = Switcher::Exp;
        else
            this->_HasError = true;
    }
    __PRI__ void _ProcessExp(char ch)
    {
        switch (ch)
        {
        case '+':
            this->_SetPosNegSym(this->_ExpSym);
            this->_ExpNormal = true;
            break;
        case '-':
            this->_SetPosNegSym(this->_ExpSym, true);
            this->_ExpNormal = true;
            break;
        default:
            this->_ProcessExpValue(ch);
            break;
        }
    }
    __PRI__ void _ProcessExpValue(char ch)
    {
        if (!this->_ExpNormal)
        {
            this->_SetPosNegSym(this->_ExpSym);
            this->_ExpNormal = true;

            if (this->_HasError)
                return;
        }

        if ('0' <= ch && '9' >= ch)
        {
            this->_ExpValue = this->_ExpValue * 10 + (int32)(ch - 48);
            this->_ExpHasValue = true;
        }
        else
            this->_HasError = true;
    }

    __PRI__ void _SetPosNegSym(PosNegSym& value, bool isNeg = false)
    {
        if (PosNegSym::Default != value)
        {
            this->_HasError = true;
            return;
        }

        value = isNeg ? PosNegSym::Negative : PosNegSym::Position;
    }

    __PUB__ double Exp()
    {
        return PosNegSym::Negative == this->_ExpSym ? -(double)(this->_ExpValue) : (double)(this->_ExpValue);
    }
    __PUB__ double Base()
    {
        return PosNegSym::Negative == this->_BaseSym ? -this->_BaseValue : this->_BaseValue;
    }
    __PUB__ bool HasError()
    {
        return this->_HasError;
    }
    __PUB__ bool Result(double __REFERENCE__ value)
    {
        value = 0.0;
        if (this->_HasError)
            return false;

        // empty string should parse to 0.0
        if (0 == this->_SIdx)
            return true;

        if (!this->_BaseHasValue || Switcher::Exp == this->_Switch && !this->_ExpHasValue)
            return false;

        try
        {
            value = pow(this->Exp(), this->Base());

            return true;
        }
        catch (...)
        {
            return false;
        }
    }
};

// ######################################################
// Internal API Implementation
// ######################################################

bool _dty_core_parse_base(const ::string s, uint64& value, bool& negative)
{
    TYBaseNumberStringConvertionParser parser(s);

    value = parser.Value();
    negative = parser.IsNegative();

    return parser.HasError();
}

bool _dty_core_parse_base(const ::string s, double& value)
{
    TYBaseDecimalStringConvertionParser parser(s);

    return parser.Result(value);
}
