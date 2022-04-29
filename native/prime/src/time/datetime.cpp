#include "../../times.hpp"
#include <ctime>

namespace dty
{
    extern const uint64 _dty_common_time_ticks_per_millisecond;
    extern const uint64 _dty_common_time_ticks_per_second;
    extern const uint64 _dty_common_time_ticks_per_minute;
    extern const uint64 _dty_common_time_ticks_per_hour;
    extern const uint64 _dty_common_time_ticks_per_day;

    extern void  __VARIABLE__ _dty_common_date_time_from_ticks
    (
        uint64 __VARIABLE__  ticks,
        uint32 __REFERENCE__ year,
        uint32 __REFERENCE__ month,
        uint32 __REFERENCE__ day,
        uint32 __REFERENCE__ hour,
        uint32 __REFERENCE__ minute,
        uint32 __REFERENCE__ second,
        uint32 __REFERENCE__ millisecond
    );

    extern uint64 __VARIABLE__ _dty_common_date_time_calc_ticks
    (
        uint32 __VARIABLE__ year,
        uint32 __VARIABLE__ month,
        uint32 __VARIABLE__ days,
        uint32 __VARIABLE__ hours,
        uint32 __VARIABLE__ minutes,
        uint32 __VARIABLE__ seconds,
        uint32 __VARIABLE__ milliseconds
    );

    extern ::string __VARIABLE__ _dty_common_date_time_format
    (
        uint32         __VARIABLE__ year,
        uint32         __VARIABLE__ month,
        uint32         __VARIABLE__ days,
        uint32         __VARIABLE__ hours,
        uint32         __VARIABLE__ minutes,
        uint32         __VARIABLE__ seconds,
        uint32         __VARIABLE__ milliseconds,
        const ::string __VARIABLE__ formatter
    );
}

#define __DTY_DATETIME_DEF__ dty::DateTime

__DTY_DATETIME_DEF__::DateTime()
    : dty::TianyuObject(),
    dty::collection::IEquatable<__DTY_DATETIME_DEF__>(),
    dty::collection::ICompareable<__DTY_DATETIME_DEF__>(),
    _TimeKind(dty::TimeKind::Local),
    _TimeTicks(0),
    _TimeYear(0),
    _TimeMonth(0),
    _TimeDay(0),
    _TimeHour(0),
    _TimeMinute(0),
    _TimeSecond(0),
    _TimeMillisecond(0),
    Kind(_TimeKind),
    Ticks(_TimeTicks),
    Year(_TimeYear),
    Month(_TimeMonth),
    Day(_TimeDay),
    Hour(_TimeHour),
    Minute(_TimeMinute),
    Second(_TimeSecond),
    Millisecond(_TimeMillisecond)
{ }

__DTY_DATETIME_DEF__::DateTime(uint64 ticks)
    : __DTY_DATETIME_DEF__(ticks, dty::TimeKind::Local)
{ }

__DTY_DATETIME_DEF__::DateTime(uint64 ticks, dty::TimeKind kind)
    : dty::TianyuObject(),
    dty::collection::IEquatable<__DTY_DATETIME_DEF__>(),
    dty::collection::ICompareable<__DTY_DATETIME_DEF__>(),
    _TimeKind(dty::TimeKind::Local),
    _TimeTicks(ticks),
    _TimeYear(0),
    _TimeMonth(0),
    _TimeDay(0),
    _TimeHour(0),
    _TimeMinute(0),
    _TimeSecond(0),
    _TimeMillisecond(0),
    Kind(_TimeKind),
    Ticks(_TimeTicks),
    Year(_TimeYear),
    Month(_TimeMonth),
    Day(_TimeDay),
    Hour(_TimeHour),
    Minute(_TimeMinute),
    Second(_TimeSecond),
    Millisecond(_TimeMillisecond)
{
    if (dty::TimeKind::UTC == kind)
        throw dty::except::NotImplementationException();

    if (0 == ticks)
        return;

    this->_AlignToTicks();
}

__DTY_DATETIME_DEF__::DateTime(int32 year, int32 month, int32 day)
    : dty::TianyuObject(),
    dty::collection::IEquatable<__DTY_DATETIME_DEF__>(),
    dty::collection::ICompareable<__DTY_DATETIME_DEF__>(),
    _TimeKind(dty::TimeKind::Local),
    _TimeTicks(0),
    _TimeYear(year),
    _TimeMonth(month),
    _TimeDay(day),
    _TimeHour(0),
    _TimeMinute(0),
    _TimeSecond(0),
    _TimeMillisecond(0),
    Kind(_TimeKind),
    Ticks(_TimeTicks),
    Year(_TimeYear),
    Month(_TimeMonth),
    Day(_TimeDay),
    Hour(_TimeHour),
    Minute(_TimeMinute),
    Second(_TimeSecond),
    Millisecond(_TimeMillisecond)
{
    this->_TimeTicks = dty::_dty_common_date_time_calc_ticks
    (
        this->Year,
        this->Month,
        this->Day,
        this->Hour,
        this->Minute,
        this->Second,
        this->Millisecond
    );
}

__DTY_DATETIME_DEF__::DateTime
(
    int32 year,
    int32 month,
    int32 day,
    int32 hour,
    int32 minute,
    int32 second
)
    : dty::TianyuObject(),
    dty::collection::IEquatable<__DTY_DATETIME_DEF__>(),
    dty::collection::ICompareable<__DTY_DATETIME_DEF__>(),
    _TimeKind(dty::TimeKind::Local),
    _TimeTicks(0),
    _TimeYear(year),
    _TimeMonth(month),
    _TimeDay(day),
    _TimeHour(hour),
    _TimeMinute(minute),
    _TimeSecond(second),
    _TimeMillisecond(0),
    Kind(_TimeKind),
    Ticks(_TimeTicks),
    Year(_TimeYear),
    Month(_TimeMonth),
    Day(_TimeDay),
    Hour(_TimeHour),
    Minute(_TimeMinute),
    Second(_TimeSecond),
    Millisecond(_TimeMillisecond)
{
    this->_TimeTicks = dty::_dty_common_date_time_calc_ticks
    (
        this->Year,
        this->Month,
        this->Day,
        this->Hour,
        this->Minute,
        this->Second,
        this->Millisecond
    );
}

__DTY_DATETIME_DEF__::DateTime
(
    int32 year,
    int32 month,
    int32 day,
    int32 hour,
    int32 minute,
    int32 second,
    int32 millisecond
)
    : dty::TianyuObject(),
    dty::collection::IEquatable<__DTY_DATETIME_DEF__>(),
    dty::collection::ICompareable<__DTY_DATETIME_DEF__>(),
    _TimeKind(dty::TimeKind::Local),
    _TimeTicks(0),
    _TimeYear(year),
    _TimeMonth(month),
    _TimeDay(day),
    _TimeHour(hour),
    _TimeMinute(minute),
    _TimeSecond(second),
    _TimeMillisecond(millisecond),
    Kind(_TimeKind),
    Ticks(_TimeTicks),
    Year(_TimeYear),
    Month(_TimeMonth),
    Day(_TimeDay),
    Hour(_TimeHour),
    Minute(_TimeMinute),
    Second(_TimeSecond),
    Millisecond(_TimeMillisecond)
{
    this->_TimeTicks = dty::_dty_common_date_time_calc_ticks
    (
        this->Year,
        this->Month,
        this->Day,
        this->Hour,
        this->Minute,
        this->Second,
        this->Millisecond
    );
}

__DTY_DATETIME_DEF__::DateTime(const __DTY_DATETIME_DEF__& other)
    : dty::TianyuObject(),
    dty::collection::IEquatable<__DTY_DATETIME_DEF__>(),
    dty::collection::ICompareable<__DTY_DATETIME_DEF__>(),
    _TimeKind(dty::TimeKind::Local),
    _TimeTicks(other.Ticks),
    _TimeYear(other.Year),
    _TimeMonth(other.Year),
    _TimeDay(other.Day),
    _TimeHour(other.Hour),
    _TimeMinute(other.Minute),
    _TimeSecond(other.Second),
    _TimeMillisecond(other.Millisecond),
    Kind(_TimeKind),
    Ticks(_TimeTicks),
    Year(_TimeYear),
    Month(_TimeMonth),
    Day(_TimeDay),
    Hour(_TimeHour),
    Minute(_TimeMinute),
    Second(_TimeSecond),
    Millisecond(_TimeMillisecond)
{ }

__DTY_DATETIME_DEF__::~DateTime() { }

__DTY_DATETIME_DEF__ __DTY_DATETIME_DEF__::Date()
{
    return __DTY_DATETIME_DEF__(this->Year, this->Month, this->Day);
}

dty::TimeSpan __DTY_DATETIME_DEF__::TimeOfDay()
{
    return dty::TimeSpan(this->Hour, this->Minute, this->Second);
}

__DTY_DATETIME_DEF__ __DTY_DATETIME_DEF__::Add(dty::TimeSpan& span)
{
    return __DTY_DATETIME_DEF__(this->Ticks + span.Ticks);
}

__DTY_DATETIME_DEF__ __DTY_DATETIME_DEF__::AddDays(double days)
{
    bool isNegative = 0 > days;
    uint64 ticks = (uint64)((isNegative ? -days : days) * dty::_dty_common_time_ticks_per_day);

    return __DTY_DATETIME_DEF__(this->Ticks + (isNegative ? -ticks : ticks));
}

__DTY_DATETIME_DEF__ __DTY_DATETIME_DEF__::AddHours(double hours)
{
    bool isNegative = 0 > hours;
    uint64 ticks = (uint64)((isNegative ? -hours : hours) * dty::_dty_common_time_ticks_per_hour);

    return __DTY_DATETIME_DEF__(this->Ticks + (isNegative ? -ticks : ticks));
}

__DTY_DATETIME_DEF__ __DTY_DATETIME_DEF__::AddMinutes(double minutes)
{
    bool isNegative = 0 > minutes;
    uint64 ticks = (uint64)((isNegative ? -minutes : minutes) * dty::_dty_common_time_ticks_per_minute);

    return __DTY_DATETIME_DEF__(this->Ticks + (isNegative ? -ticks : ticks));
}

__DTY_DATETIME_DEF__ __DTY_DATETIME_DEF__::AddSeconds(double seconds)
{
    bool isNegative = 0 > seconds;
    uint64 ticks = (uint64)((isNegative ? -seconds : seconds) * dty::_dty_common_time_ticks_per_second);

    return __DTY_DATETIME_DEF__(this->Ticks + (isNegative ? -ticks : ticks));
}

__DTY_DATETIME_DEF__ __DTY_DATETIME_DEF__::AddMilliseconds(double milliseconds)
{
    bool isNegative = 0 > milliseconds;
    uint64 ticks = (uint64)((isNegative ? -milliseconds : milliseconds) * dty::_dty_common_time_ticks_per_millisecond);

    return __DTY_DATETIME_DEF__(this->Ticks + (isNegative ? -ticks : ticks));
}

__DTY_DATETIME_DEF__ __DTY_DATETIME_DEF__::AddYears(int32 years)
{
    bool isNegative = 0 > years;
    uint64 ticks = (uint64)((isNegative ? -years : years) * dty::_dty_common_time_ticks_per_millisecond);

    return __DTY_DATETIME_DEF__(this->Ticks + (isNegative ? -ticks : ticks));
}

__DTY_DATETIME_DEF__ __DTY_DATETIME_DEF__::AddMonths(int32 months)
{
    bool isNegative = 0 > months;
    uint64 ticks = (uint64)((isNegative ? -months : months) * dty::_dty_common_time_ticks_per_millisecond);

    return __DTY_DATETIME_DEF__(this->Ticks + (isNegative ? -ticks : ticks));
}

__DTY_DATETIME_DEF__ __DTY_DATETIME_DEF__::AddTicks(uint64 ticks)
{
    return __DTY_DATETIME_DEF__(this->Ticks + ticks);
}

dty::TimeSpan __DTY_DATETIME_DEF__::Subtract(__DTY_DATETIME_DEF__& date)
{
    return (__PTR_TO_VAR__ this) - date;
}

__DTY_DATETIME_DEF__ __DTY_DATETIME_DEF__::Subtract(dty::TimeSpan& time)
{
    return (__PTR_TO_VAR__ this) - time;
}

__DTY_DATETIME_DEF__ __DTY_DATETIME_DEF__::ToUniversalTime()
{
    throw dty::except::NotImplementationException();
}

::string __DTY_DATETIME_DEF__::ToString() noexcept
{
    return dty::_dty_common_date_time_format
    (
        this->Year,
        this->Month,
        this->Day,
        this->Hour,
        this->Minute,
        this->Second,
        this->Millisecond,
        ::null
    );
}

uint64 __DTY_DATETIME_DEF__::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

dty::String __DTY_DATETIME_DEF__::ToString(const ::string formatter)
{
    ::string result = dty::_dty_common_date_time_format
    (
        this->Year,
        this->Month,
        this->Day,
        this->Hour,
        this->Minute,
        this->Second,
        this->Millisecond,
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

dty::String __DTY_DATETIME_DEF__::ToString(dty::String formatter)
{
    ::string cstr_formatter = formatter.ToCStr();
    ::string result = dty::_dty_common_date_time_format
    (
        this->Year,
        this->Month,
        this->Day,
        this->Hour,
        this->Minute,
        this->Second,
        this->Millisecond,
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

void __DTY_DATETIME_DEF__::_AlignToTicks()
{
    uint32 year = 0;
    uint32 month = 0;
    uint32 day = 0;
    uint32 hour = 0;
    uint32 minute = 0;
    uint32 second = 0;
    uint32 millisecond = 0;

    dty::_dty_common_date_time_from_ticks(this->Ticks, year, month, day, hour, minute, second, millisecond);

    this->_TimeYear = year;
    this->_TimeMonth = month;
    this->_TimeDay = day;
    this->_TimeHour = hour;
    this->_TimeMinute = minute;
    this->_TimeSecond = second;
    this->_TimeMillisecond = millisecond;
}

bool __DTY_DATETIME_DEF__::Equals(dty::TianyuObject& obj)
{
    if (this->GetTypeId() != obj.GetTypeId())
        return false;

    __DTY_DATETIME_DEF__& cast_obj = dynamic_cast<__DTY_DATETIME_DEF__&>(obj);
    return this->Ticks.Get() == cast_obj.Ticks.Get();
}

bool __DTY_DATETIME_DEF__::operator==(dty::TianyuObject& obj)
{
    return this->Equals(obj);
}

bool __DTY_DATETIME_DEF__::Equals(__DTY_DATETIME_DEF__& other)
{
    return this->Ticks.Get() == other.Ticks.Get();
}

bool __DTY_DATETIME_DEF__::operator==(__DTY_DATETIME_DEF__& other)
{
    return this->Equals(other);
}

bool __DTY_DATETIME_DEF__::operator!=(__DTY_DATETIME_DEF__& other)
{
    return !this->Equals(other);
}

bool __DTY_DATETIME_DEF__::operator<(__DTY_DATETIME_DEF__& other)
{
    return this->Ticks.Get() < other.Ticks.Get();
}

bool __DTY_DATETIME_DEF__::operator<=(__DTY_DATETIME_DEF__& other)
{
    return this->Ticks.Get() <= other.Ticks.Get();
}

bool __DTY_DATETIME_DEF__::operator>(__DTY_DATETIME_DEF__& other)
{
    return this->Ticks.Get() > other.Ticks.Get();
}

bool __DTY_DATETIME_DEF__::operator>=(__DTY_DATETIME_DEF__& other)
{
    return this->Ticks.Get() >= other.Ticks.Get();
}

dty::collection::CompareResult __DTY_DATETIME_DEF__::CompareTo(__DTY_DATETIME_DEF__& other)
{
    return this->Ticks == other.Ticks
        ? dty::collection::CompareResult::EQUAL
        : this->Ticks > other.Ticks
        ? dty::collection::CompareResult::GREAT
        : dty::collection::CompareResult::LESS;
}

__DTY_DATETIME_DEF__ __DTY_DATETIME_DEF__::operator+(dty::TimeSpan& span)
{
    if (span.IsNegative)
    {
        if (this->Ticks < span.Ticks)
            return __DTY_DATETIME_DEF__(0);

        return __DTY_DATETIME_DEF__(this->Ticks - span.Ticks);
    }

    return __DTY_DATETIME_DEF__(this->Ticks + span.Ticks);
}

__DTY_DATETIME_DEF__ __DTY_DATETIME_DEF__::operator-(dty::TimeSpan& span)
{
    if (span.IsNegative)
        return __DTY_DATETIME_DEF__(this->Ticks + span.Ticks);

    if (this->Ticks < span.Ticks)
        return __DTY_DATETIME_DEF__(0);

    return __DTY_DATETIME_DEF__(this->Ticks - span.Ticks);
}

dty::TimeSpan __DTY_DATETIME_DEF__::operator-(__DTY_DATETIME_DEF__& date)
{
    if ((__PTR_TO_REF__ this) == date)
        return dty::TimeSpan(0);

    if (this->Ticks > date.Ticks)
        return dty::TimeSpan(this->Ticks - date.Ticks);

    dty::TimeSpan timespan(date.Ticks - this->Ticks);
    timespan.IsNegative = true;

    return timespan;
}

__DTY_DATETIME_DEF__ __DTY_DATETIME_DEF__::MaxValue()
{
    return __DTY_DATETIME_DEF__(9999, 12, 31, 23, 59, 59, 999);
}

__DTY_DATETIME_DEF__ __DTY_DATETIME_DEF__::MinValue()
{
    return __DTY_DATETIME_DEF__(1, 1, 1, 0, 0, 0, 0);
}

__DTY_DATETIME_DEF__ __DTY_DATETIME_DEF__::UnixEpoch()
{
    throw dty::except::NotImplementationException();
}

bool __DTY_DATETIME_DEF__::IsLeapYear(int32 year)
{
    if (0 >= year)
        throw dty::except::ArgumentOutOfRangeException();

    return 0 == year % 4
        && 0 != year % 100
        || 0 == year % 400;
}

dty::collection::CompareResult __DTY_DATETIME_DEF__::Compare(__DTY_DATETIME_DEF__& date1, __DTY_DATETIME_DEF__& date2)
{
    return date1.CompareTo(date2);
}




