#include "../../times.hpp"

namespace dty
{
    extern const uint64 _dty_common_time_ticks_per_millisecond;
    extern const uint64 _dty_common_time_ticks_per_second;
    extern const uint64 _dty_common_time_ticks_per_minute;
    extern const uint64 _dty_common_time_ticks_per_hour;
    extern const uint64 _dty_common_time_ticks_per_day;
    extern const uint64 _dty_common_time_ticks_per_year;
    extern const uint64 _dty_common_time_ticks_per_leap_year;

    extern void _dty_common_time_span_from_ticks
    (
        uint64 __VARIABLE__  ticks,
        uint32 __REFERENCE__ days,
        uint32 __REFERENCE__ hours,
        uint32 __REFERENCE__ minutes,
        uint32 __REFERENCE__ seconds,
        uint32 __REFERENCE__ milliseconds
    );

    extern uint64 __VARIABLE__ _dty_common_time_span_calc_ticks
    (
        uint32 __VARIABLE__ days,
        uint32 __VARIABLE__ hours,
        uint32 __VARIABLE__ minutes,
        uint32 __VARIABLE__ seconds,
        uint32 __VARIABLE__ milliseconds
    );

    extern ::string __VARIABLE__ _dty_common_time_format
    (
        uint32         __VARIABLE__ days,
        uint32         __VARIABLE__ hours,
        uint32         __VARIABLE__ minutes,
        uint32         __VARIABLE__ seconds,
        uint32         __VARIABLE__ milliseconds,
        const ::string __VARIABLE__ formatter
    );
}

#define __DTY_TIMESPAN_DEF__ dty::TimeSpan

__DTY_TIMESPAN_DEF__::TimeSpan()
    : dty::TianyuObject(),
    dty::collection::IEquatable<__DTY_TIMESPAN_DEF__>(),
    dty::collection::ICompareable<__DTY_TIMESPAN_DEF__>(),
    _TimeTicks(0),
    _TimeDays(0),
    _TimeHours(0),
    _TimeMinutes(0),
    _TimeSenonds(0),
    _TimeMilliseconds(0),
    IsNegative(false),
    Ticks(_TimeTicks),
    Days(_TimeDays),
    Hours(_TimeHours),
    Minutes(_TimeMinutes),
    Seconds(_TimeSenonds),
    Milliseconds(_TimeMilliseconds)
{ }

__DTY_TIMESPAN_DEF__::TimeSpan(uint64 ticks)
    : dty::TianyuObject(),
    dty::collection::IEquatable<__DTY_TIMESPAN_DEF__>(),
    dty::collection::ICompareable<__DTY_TIMESPAN_DEF__>(),
    _TimeTicks(ticks),
    _TimeDays(0),
    _TimeHours(0),
    _TimeMinutes(0),
    _TimeSenonds(0),
    _TimeMilliseconds(0),
    IsNegative(false),
    Ticks(_TimeTicks),
    Days(_TimeDays),
    Hours(_TimeHours),
    Minutes(_TimeMinutes),
    Seconds(_TimeSenonds),
    Milliseconds(_TimeMilliseconds)
{
    if (0 == ticks)
        return;

    this->_AlignToTicks();
}

__DTY_TIMESPAN_DEF__::TimeSpan(const __DTY_TIMESPAN_DEF__& span)
    : dty::TianyuObject(),
    dty::collection::IEquatable<__DTY_TIMESPAN_DEF__>(),
    dty::collection::ICompareable<__DTY_TIMESPAN_DEF__>(),
    _TimeTicks(span.Ticks),
    _TimeDays(span.Days),
    _TimeHours(span.Hours),
    _TimeMinutes(span.Minutes),
    _TimeSenonds(span.Seconds),
    _TimeMilliseconds(span.Milliseconds),
    IsNegative(span.IsNegative),
    Ticks(_TimeTicks),
    Days(_TimeDays),
    Hours(_TimeHours),
    Minutes(_TimeMinutes),
    Seconds(_TimeSenonds),
    Milliseconds(_TimeMilliseconds)
{ }

__DTY_TIMESPAN_DEF__::TimeSpan(int32 hours, int32 minutes, int32 seconds)
    : __DTY_TIMESPAN_DEF__(0, hours, minutes, seconds, 0)
{ }

__DTY_TIMESPAN_DEF__::TimeSpan(int32 hours, int32 minutes, int32 seconds, int32 milliseconds)
    : __DTY_TIMESPAN_DEF__(0, hours, minutes, seconds, milliseconds)
{ }

__DTY_TIMESPAN_DEF__::TimeSpan(int32 days, int32 hours, int32 minutes, int32 seconds, int32 milliseconds)
    : dty::TianyuObject(),
    dty::collection::IEquatable<__DTY_TIMESPAN_DEF__>(),
    dty::collection::ICompareable<__DTY_TIMESPAN_DEF__>(),
    _TimeTicks(0),
    _TimeDays(days),
    _TimeHours(hours),
    _TimeMinutes(minutes),
    _TimeSenonds(seconds),
    _TimeMilliseconds(milliseconds),
    IsNegative(false),
    Ticks(_TimeTicks),
    Days(_TimeDays),
    Hours(_TimeHours),
    Minutes(_TimeMinutes),
    Seconds(_TimeSenonds),
    Milliseconds(_TimeMilliseconds)
{
    this->_TimeTicks = dty::_dty_common_time_span_calc_ticks
    (
        this->Days,
        this->Hours,
        this->Minutes,
        this->Seconds,
        this->Milliseconds
    );
}

__DTY_TIMESPAN_DEF__::~TimeSpan() { }

double __DTY_TIMESPAN_DEF__::GetTotalDays()
{
    double total = this->Ticks;

    total = total / dty::_dty_common_time_ticks_per_day;

    return total;
}
double __DTY_TIMESPAN_DEF__::GetTotalHours()
{
    double total = this->Ticks;

    total = total / dty::_dty_common_time_ticks_per_hour;

    return total;
}
double __DTY_TIMESPAN_DEF__::GetTotalMinutes()
{
    double total = this->Ticks;

    total = total / dty::_dty_common_time_ticks_per_minute;

    return total;
}
double __DTY_TIMESPAN_DEF__::GetTotalSeconds()
{
    double total = this->Ticks;

    total = total / dty::_dty_common_time_ticks_per_second;

    return total;
}
double __DTY_TIMESPAN_DEF__::GetTotalMilliseconds()
{
    double total = this->Ticks;

    total = total / dty::_dty_common_time_ticks_per_millisecond;

    return total;
}

__DTY_TIMESPAN_DEF__& __DTY_TIMESPAN_DEF__::AddTicks(uint64 ticks)
{
    this->_TimeTicks = this->Ticks + ticks;
    this->_AlignToTicks();

    return __PTR_TO_REF__ this;
}
__DTY_TIMESPAN_DEF__& __DTY_TIMESPAN_DEF__::AddDays(int32 days)
{
    bool isNegative = 0 > days;
    uint64 ticks = (isNegative ? -days : days) * dty::_dty_common_time_ticks_per_day;

    this->_TimeTicks = this->Ticks + days * dty::_dty_common_time_ticks_per_day;

    return __PTR_TO_REF__ this;
}
__DTY_TIMESPAN_DEF__& __DTY_TIMESPAN_DEF__::AddHours(int32 hours)
{
    this->_TimeHours = this->Hours + hours;
    this->_TimeTicks = this->Ticks + hours * dty::_dty_common_time_ticks_per_hour;

    return __PTR_TO_REF__ this;
}
__DTY_TIMESPAN_DEF__& __DTY_TIMESPAN_DEF__::AddMinutes(int32 minutes)
{
    this->_TimeMinutes = this->Minutes + minutes;
    this->_TimeTicks = this->Ticks + minutes * dty::_dty_common_time_ticks_per_minute;

    return __PTR_TO_REF__ this;
}
__DTY_TIMESPAN_DEF__& __DTY_TIMESPAN_DEF__::AddSeconds(int32 seconds)
{
    this->_TimeSenonds = this->Seconds + seconds;
    this->_TimeTicks = this->Ticks + seconds * dty::_dty_common_time_ticks_per_second;

    return __PTR_TO_REF__ this;
}
__DTY_TIMESPAN_DEF__& __DTY_TIMESPAN_DEF__::AddMilliseconds(int32 milliseconds)
{
    this->_TimeMilliseconds = this->Milliseconds + milliseconds;
    this->_TimeTicks = this->Ticks + milliseconds * dty::_dty_common_time_ticks_per_millisecond;

    return __PTR_TO_REF__ this;
}
__DTY_TIMESPAN_DEF__& __DTY_TIMESPAN_DEF__::AddSpan(TimeSpan& span)
{
    this->_TimeTicks = this->Ticks + span.Ticks;
    this->_TimeDays = this->Days + span.Days;
    this->_TimeHours = this->Hours + span.Hours;
    this->_TimeMinutes = this->Minutes + span.Minutes;
    this->_TimeSenonds = this->Seconds + span.Seconds;
    this->_TimeMilliseconds = this->Milliseconds + span.Milliseconds;

    return __PTR_TO_REF__ this;
}

__DTY_TIMESPAN_DEF__ __DTY_TIMESPAN_DEF__::operator+(__DTY_TIMESPAN_DEF__& span)
{
    return __DTY_TIMESPAN_DEF__(this->Ticks + span.Ticks);
}

__DTY_TIMESPAN_DEF__ __DTY_TIMESPAN_DEF__::operator+(uint64 ticks)
{
    return __DTY_TIMESPAN_DEF__(this->Ticks + ticks);
}

__DTY_TIMESPAN_DEF__ __DTY_TIMESPAN_DEF__::operator-(__DTY_TIMESPAN_DEF__& span)
{
    return __DTY_TIMESPAN_DEF__(this->Ticks - span.Ticks);
}

__DTY_TIMESPAN_DEF__ __DTY_TIMESPAN_DEF__::operator-(uint64 ticks)
{
    return __DTY_TIMESPAN_DEF__(this->Ticks - ticks);
}

::string __DTY_TIMESPAN_DEF__::ToString() noexcept
{
    return this->ToString(::null);
}

dty::String __DTY_TIMESPAN_DEF__::ToString(const ::string formatter)
{
    ::string result = dty::_dty_common_time_format
    (
        this->Days,
        this->Hours,
        this->Minutes,
        this->Seconds,
        this->Milliseconds,
        formatter
    );

    if (::null != result)
    {
        dty::String dStr(result);
        delete [] result;

        return dStr;
    }

    return dty::String();
}

dty::String __DTY_TIMESPAN_DEF__::ToString(dty::String formatter)
{
    ::string cstr_formatter = formatter;

    ::string result = dty::_dty_common_time_format
    (
        this->Days,
        this->Hours,
        this->Minutes,
        this->Seconds,
        this->Milliseconds,
        cstr_formatter
    );

    if (::null != cstr_formatter)
        delete [] cstr_formatter;

    if (::null != result)
    {
        dty::String dStr(result);
        delete [] result;

        return dStr;
    }

    return dty::String();
}

void __DTY_TIMESPAN_DEF__::_AlignToTicks()
{
    uint32 days = 0;
    uint32 hours = 0;
    uint32 minutes = 0;
    uint32 seconds = 0;
    uint32 milliseconds = 0;

    dty::_dty_common_time_span_from_ticks(this->Ticks, days, hours, minutes, seconds, milliseconds);

    this->_TimeDays = days;
    this->_TimeHours = hours;
    this->_TimeMinutes = minutes;
    this->_TimeSenonds = seconds;
    this->_TimeMilliseconds = milliseconds;
}

uint64 __DTY_TIMESPAN_DEF__::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

bool __DTY_TIMESPAN_DEF__::Equals(dty::TianyuObject& obj)
{
    if (this->GetTypeId() != obj.GetTypeId())
        return false;

    __DTY_TIMESPAN_DEF__& cast_obj = dynamic_cast<__DTY_TIMESPAN_DEF__&>(obj);
    return this->Ticks.Get() == cast_obj.Ticks.Get();
}

bool __DTY_TIMESPAN_DEF__::operator==(dty::TianyuObject& obj)
{
    return this->Equals(obj);
}

bool __DTY_TIMESPAN_DEF__::Equals(__DTY_TIMESPAN_DEF__& other)
{
    return this->Ticks.Get() == other.Ticks.Get();
}

bool __DTY_TIMESPAN_DEF__::operator==(__DTY_TIMESPAN_DEF__& other)
{
    return this->Equals(other);
}

bool __DTY_TIMESPAN_DEF__::operator!=(__DTY_TIMESPAN_DEF__& other)
{
    return !this->Equals(other);
}

bool __DTY_TIMESPAN_DEF__::operator<(__DTY_TIMESPAN_DEF__& other)
{
    return this->Ticks.Get() < other.Ticks.Get();
}

bool __DTY_TIMESPAN_DEF__::operator<=(__DTY_TIMESPAN_DEF__& other)
{
    return this->Ticks.Get() <= other.Ticks.Get();
}

bool __DTY_TIMESPAN_DEF__::operator>(__DTY_TIMESPAN_DEF__& other)
{
    return this->Ticks.Get() > other.Ticks.Get();
}

bool __DTY_TIMESPAN_DEF__::operator>=(__DTY_TIMESPAN_DEF__& other)
{
    return this->Ticks.Get() >= other.Ticks.Get();
}

dty::collection::CompareResult __DTY_TIMESPAN_DEF__::CompareTo(__DTY_TIMESPAN_DEF__& other)
{
    return this->Ticks == other.Ticks
        ? dty::collection::CompareResult::EQUAL
        : this->Ticks > other.Ticks
        ? dty::collection::CompareResult::GREAT
        : dty::collection::CompareResult::LESS;
}
