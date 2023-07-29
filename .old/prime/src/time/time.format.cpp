#include "../../core.hxx"

namespace dty
{
    // ::string days = ::ul2str(this->Days);
    // ::string hours = ::ul2str(this->Hours);
    // ::string minutes = ::ul2str(this->Minutes);
    // ::string seconds = ::ul2str(this->Seconds);
    // ::string milliseconds = ::ul2str(this->Milliseconds);

    // int32 days_len = ::strlen(days);
    // int32 hours_len = ::strlen(hours);
    // int32 minutes_len = ::strlen(minutes);
    // int32 seconds_len = ::strlen(seconds);
    // int32 millseconds_len = ::strlen(milliseconds);

    ::string __VARIABLE__ _dty_common_time_format
    (
        uint32         __VARIABLE__ hours,
        uint32         __VARIABLE__ minutes,
        uint32         __VARIABLE__ seconds,
        uint32         __VARIABLE__ milliseconds,
        const ::string __VARIABLE__ formatter
    );

    ::string __VARIABLE__ _dty_common_time_format
    (
        uint32         __VARIABLE__ days,
        uint32         __VARIABLE__ hours,
        uint32         __VARIABLE__ minutes,
        uint32         __VARIABLE__ seconds,
        uint32         __VARIABLE__ milliseconds,
        const ::string __VARIABLE__ formatter
    );

    ::string __VARIABLE__ _dty_common_date_format
    (
        uint32         __VARIABLE__ year,
        uint32         __VARIABLE__ month,
        uint32         __VARIABLE__ day,
        const ::string __VARIABLE__ formatter
    );

    ::string __VARIABLE__ _dty_common_date_time_format
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