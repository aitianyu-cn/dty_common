/**
 * @file times.hpp(prime)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-17
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.timespan?view=net-6.0
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime?view=net-6.0
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_TIMES_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_TIMES_H_PLUS_PLUS__

#include "./core.hxx"
#include "./string.hpp"
#include <iostream>

namespace dty
{
    _enum WeekType : int32
    {
        Monday = 0,
        Tuesday = 1,
        Wednesday = 2,
        Thursday = 3,
        Firday = 4,
        Saturday = 5,
        Sunday = 6
    };
    _enum MonthType : int32
    {
        January = 0,
        February = 1,
        March = 2,
        April = 3,
        May = 4,
        June = 5,
        July = 6,
        August = 7,
        September = 8,
        October = 9,
        November = 10,
        December = 11
    };
    _enum TimeKind : int32
    {
        UTC,
        Local
    };
    class TimeSpan final : public virtual dty::TianyuObject,
        public virtual dty::collection::IEquatable<TimeSpan>,
        public virtual dty::collection::ICompareable<TimeSpan>
    {
        __PUB__ TimeSpan();
        __PUB__ TimeSpan(uint64 __VARIABLE__ ticks);
        __PUB__ TimeSpan(const TimeSpan __REFERENCE__ span);
        __PUB__ TimeSpan(int32 __VARIABLE__ hours, int32 __VARIABLE__ minutes, int32 __VARIABLE__ seconds);
        __PUB__ TimeSpan(int32 __VARIABLE__ hours, int32 __VARIABLE__ minutes, int32 __VARIABLE__ seconds, int32 __VARIABLE__ milliseconds);
        __PUB__ TimeSpan(int32 __VARIABLE__ days, int32 __VARIABLE__ hours, int32 __VARIABLE__ minutes, int32 __VARIABLE__ seconds, int32 __VARIABLE__ milliseconds);

        __PUB__ virtual ~TimeSpan() override;

        __PUB__ uint64 __VARIABLE__ TotalTicks();

        __PUB__ int32 __VARIABLE__ GetTotalDays();
        __PUB__ int32 __VARIABLE__ GetTotalHours();
        __PUB__ int32 __VARIABLE__ GetTotalMinutes();
        __PUB__ int32 __VARIABLE__ GetTotalSeconds();
        __PUB__ int32 __VARIABLE__ GetTotalMilliseconds();

        __PUB__ int32 __VARIABLE__ Days();
        __PUB__ int32 __VARIABLE__ Hours();
        __PUB__ int32 __VARIABLE__ Minutes();
        __PUB__ int32 __VARIABLE__ Seconds();
        __PUB__ int32 __VARIABLE__ Milliseconds();

        __PUB__ TimeSpan __REFERENCE__ AddTicks(uint64 __VARIABLE__ ticks);
        __PUB__ TimeSpan __REFERENCE__ AddDays(int32 __VARIABLE__ ticks);
        __PUB__ TimeSpan __REFERENCE__ AddHours(int32 __VARIABLE__ ticks);
        __PUB__ TimeSpan __REFERENCE__ AddMinutes(int32 __VARIABLE__ ticks);
        __PUB__ TimeSpan __REFERENCE__ AddSeconds(int32 __VARIABLE__ ticks);
        __PUB__ TimeSpan __REFERENCE__ AddMilliseconds(int32 __VARIABLE__ ticks);
        __PUB__ TimeSpan __REFERENCE__ AddSpan(TimeSpan __REFERENCE__ span);

        __PUB__ TimeSpan __REFERENCE__ operator+(TimeSpan __REFERENCE__ span);
        __PUB__ TimeSpan __REFERENCE__ operator+(uint64 __VARIABLE__ ticks);
        __PUB__ TimeSpan __REFERENCE__ operator-(TimeSpan __REFERENCE__ span);
        __PUB__ TimeSpan __REFERENCE__ operator-(uint64 __VARIABLE__ ticks);

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override;

        __PUB__ dty::String      __VARIABLE__ ToString(const string __VARIABLE__ formatter);
        __PUB__ dty::String      __VARIABLE__ ToString(String __VARIABLE__ formatter);


        __PUB__ static TimeSpan __VARIABLE__ Parse(String __VARIABLE__ source);
        __PUB__ static TimeSpan __VARIABLE__ Parse(const string __VARIABLE__ source);

        __PUB__ static bool __VARIABLE__ TryParse(String __VARIABLE__ source, TimeSpan __REFERENCE__ outSpan);
        __PUB__ static bool __VARIABLE__ TryParse(const string __VARIABLE__ source, TimeSpan __REFERENCE__ outSpan);

#pragma region collection::ICompareable & collection::IEquatable interfaces
        __PUB__ virtual bool __VARIABLE__ Equals(TimeSpan __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator ==(TimeSpan __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator !=(TimeSpan __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator <(TimeSpan __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator >(TimeSpan __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator <=(TimeSpan __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator >=(TimeSpan __REFERENCE__ other) override;

        __PUB__ virtual collection::CompareResult __VARIABLE__ CompareTo(TimeSpan __REFERENCE__ other) override;
#pragma endregion

        friend std::ostream __REFERENCE__ operator<<(std::ostream __REFERENCE__ os, TimeSpan __REFERENCE__ span);
    };
    class DateTime final : public virtual dty::TianyuObject,
        public virtual dty::collection::IEquatable<DateTime>,
        public virtual dty::collection::ICompareable<DateTime>
    {
        __PUB__ DateTime(uint64 __VARIABLE__ ticks);
        __PUB__ DateTime(uint64 __VARIABLE__ ticks, TimeKind __VARIABLE__ kind);
        __PUB__ DateTime(int32 __VARIABLE__ year, int32 __VARIABLE__ month, int32 __VARIABLE__ day);
        __PUB__ DateTime
        (
            int32 __VARIABLE__ year,
            int32 __VARIABLE__ month,
            int32 __VARIABLE__ day,
            int32 __VARIABLE__ hours,
            int32 __VARIABLE__ minutes,
            int32 __VARIABLE__ seconds
        );
        __PUB__ DateTime
        (
            int32    __VARIABLE__ year,
            int32    __VARIABLE__ month,
            int32    __VARIABLE__ day,
            int32    __VARIABLE__ hours,
            int32    __VARIABLE__ minutes,
            int32    __VARIABLE__ seconds,
            TimeKind __VARIABLE__ kind
        );
        __PUB__ DateTime
        (
            int32    __VARIABLE__ year,
            int32    __VARIABLE__ month,
            int32    __VARIABLE__ day,
            int32    __VARIABLE__ hours,
            int32    __VARIABLE__ minutes,
            int32    __VARIABLE__ seconds,
            int32    __VARIABLE__ milliseconds
        );
        __PUB__ DateTime
        (
            int32    __VARIABLE__ year,
            int32    __VARIABLE__ month,
            int32    __VARIABLE__ day,
            int32    __VARIABLE__ hours,
            int32    __VARIABLE__ minutes,
            int32    __VARIABLE__ seconds,
            int32    __VARIABLE__ milliseconds,
            TimeKind __VARIABLE__ kind
        );
        __PUB__ DateTime(const DateTime __REFERENCE__ other);
        __PUB__ virtual ~DateTime() override;

        __PUB__ DateTime __VARIABLE__ Date();
        __PUB__ TimeSpan __VARIABLE__ TimeOfDay();

        __PUB__ int32 __VARIABLE__ Year();
        __PUB__ int32 __VARIABLE__ Month();
        __PUB__ int32 __VARIABLE__ Day();
        __PUB__ int32 __VARIABLE__ Hour();
        __PUB__ int32 __VARIABLE__ Minute();
        __PUB__ int32 __VARIABLE__ Second();
        __PUB__ int32 __VARIABLE__ Millisecond();

        __PUB__ uint64   __VARIABLE__ Ticks();
        __PUB__ TimeKind __VARIABLE__ Kind();

        __PUB__ DateTime __VARIABLE__ Add(TimeSpan __REFERENCE__ span);
        __PUB__ DateTime __VARIABLE__ AddDays(double __VARIABLE__ days);
        __PUB__ DateTime __VARIABLE__ AddHours(double __VARIABLE__ hours);
        __PUB__ DateTime __VARIABLE__ AddMinutes(double __VARIABLE__ minutes);
        __PUB__ DateTime __VARIABLE__ AddSeconds(double __VARIABLE__ seconds);
        __PUB__ DateTime __VARIABLE__ AddMilliseconds(double __VARIABLE__ milliseconds);
        __PUB__ DateTime __VARIABLE__ AddYears(int32 __VARIABLE__ years);
        __PUB__ DateTime __VARIABLE__ AddMonths(int32 __VARIABLE__ months);
        __PUB__ DateTime __VARIABLE__ AddTicks(uint64 __VARIABLE__ ticks);

        __PUB__ TimeSpan __VARIABLE__ Subtract(DateTime __REFERENCE__ date);
        __PUB__ DateTime __VARIABLE__ Subtract(TimeSpan __REFERENCE__ span);
        __PUB__ DateTime __VARIABLE__ ToUniversalTime();

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() override;

        __PUB__ dty::String ToString(const ::string __VARIABLE__ formatter);
        __PUB__ dty::String ToString(dty::String __VARIABLE__ formatter);

#pragma region collection::ICompareable & collection::IEquatable interfaces
        __PUB__ virtual bool __VARIABLE__ Equals(DateTime __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator ==(DateTime __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator !=(DateTime __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator <(DateTime __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator >(DateTime __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator <=(DateTime __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator >=(DateTime __REFERENCE__ other) override;

        __PUB__ virtual collection::CompareResult __VARIABLE__ CompareTo(DateTime __REFERENCE__ other) override;
#pragma endregion

#pragma region operators
        __PUB__ DateTime __VARIABLE__ operator+(TimeSpan __REFERENCE__ span);
        __PUB__ DateTime __VARIABLE__ operator-(TimeSpan __REFERENCE__ span);
        __PUB__ TimeSpan __VARIABLE__ operator-(DateTime __REFERENCE__ date);
#pragma endregion

#pragma region static definitions
        __PUB__ static DateTime __VARIABLE__ MaxValue();
        __PUB__ static DateTime __VARIABLE__ MinValue();
        __PUB__ static DateTime __VARIABLE__ UnixEpoch();

        __PUB__ static DateTime __VARIABLE__ Now();
        __PUB__ static DateTime __VARIABLE__ UtcNow();
        __PUB__ static DateTime __VARIABLE__ Today();

        __PUB__ static DateTime __VARIABLE__ Parse(const ::string __VARIABLE__ date);
        __PUB__ static DateTime __VARIABLE__ Parse(dty::String    __VARIABLE__ date);

        __PUB__ static bool __VARIABLE__ IsLeapYear(int32 __VARIABLE__ year);

        __PUB__ static dty::collection::CompareResult __VARIABLE__ Compare(DateTime __REFERENCE__ date1, DateTime __REFERENCE__ date2);
#pragma endregion

        friend std::ostream __REFERENCE__ operator<<(std::ostream __REFERENCE__ os, DateTime __REFERENCE__ date);
    };

    std::ostream __REFERENCE__ operator<<(std::ostream __REFERENCE__ os, TimeSpan __REFERENCE__ span);
    std::ostream __REFERENCE__ operator<<(std::ostream __REFERENCE__ os, DateTime __REFERENCE__ date);
}

#endif // !__DTY_COMMON_NATIVE_PRIME_TIMES_H_PLUS_PLUS__