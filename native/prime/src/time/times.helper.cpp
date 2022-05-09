#include "../../core.hxx"

namespace dty
{
    const uint64 _dty_common_time_ticks_per_millisecond = 1000UL;
    const uint64 _dty_common_time_ticks_per_second = 1000 * _dty_common_time_ticks_per_millisecond;
    const uint64 _dty_common_time_ticks_per_minute = 60 * _dty_common_time_ticks_per_second;
    const uint64 _dty_common_time_ticks_per_hour = 60 * _dty_common_time_ticks_per_minute;
    const uint64 _dty_common_time_ticks_per_day = 24 * _dty_common_time_ticks_per_hour;

    const uint64 _dty_common_time_ticks_per_month_b = 31 * _dty_common_time_ticks_per_day;
    const uint64 _dty_common_time_ticks_per_month_l = 30 * _dty_common_time_ticks_per_day;
    const uint64 _dty_common_time_ticks_per_month_2 = 28 * _dty_common_time_ticks_per_day;
    const uint64 _dty_common_time_ticks_per_month_2b = 29 * _dty_common_time_ticks_per_day;

    const uint64 _dty_common_time_ticks_per_year = 365 * _dty_common_time_ticks_per_day;
    const uint64 _dty_common_time_ticks_per_leap_year = _dty_common_time_ticks_per_year + _dty_common_time_ticks_per_day;

    void  __VARIABLE__ _dty_common_time_span_from_ticks
    (
        uint64 __VARIABLE__  ticks,
        uint32 __REFERENCE__ days,
        uint32 __REFERENCE__ hours,
        uint32 __REFERENCE__ minutes,
        uint32 __REFERENCE__ seconds,
        uint32 __REFERENCE__ milliseconds
    );

    uint64 __VARIABLE__ _dty_common_time_span_calc_ticks
    (
        uint32 __VARIABLE__ days,
        uint32 __VARIABLE__ hours,
        uint32 __VARIABLE__ minutes,
        uint32 __VARIABLE__ seconds,
        uint32 __VARIABLE__ milliseconds
    );

    void  __VARIABLE__ _dty_common_date_time_from_ticks
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

    uint64 __VARIABLE__ _dty_common_date_time_calc_ticks
    (
        uint32 __VARIABLE__ year,
        uint32 __VARIABLE__ month,
        uint32 __VARIABLE__ days,
        uint32 __VARIABLE__ hours,
        uint32 __VARIABLE__ minutes,
        uint32 __VARIABLE__ seconds,
        uint32 __VARIABLE__ milliseconds
    );
}