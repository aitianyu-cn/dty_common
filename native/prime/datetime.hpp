/**
 * @file datetime.hpp(prime)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-17
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_DATETIME_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_DATETIME_H_PLUS_PLUS__

#include "./core.hxx"
#include "./string.hpp"
#include <iostream>

namespace dty
{
    enum class WeekType : int32
    {
        Monday = 0,
        Tuesday = 1,
        Wednesday = 2,
        Thursday = 3,
        Firday = 4,
        Saturday = 5,
        Sunday = 6
    };
    enum class MonthType : int32
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
    enum class TimeLocal : int32
    {
        UTC,
        Local
    };
    class TimeSpan final : dty::collection::IEquatable<TimeSpan>,
        dty::collection::ICompareable<TimeSpan>
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

        __PUB__ String __VARIABLE__ ToString() const;
        __PUB__ String __VARIABLE__ ToString(const string __VARIABLE__ formatter) const;
        __PUB__ String __VARIABLE__ ToString(String __VARIABLE__ formatter) const;


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
    class DateTime final : dty::collection::IEquatable<DateTime>,
        dty::collection::ICompareable<DateTime>
    {
        __PUB__ DateTime();
        __PUB__ virtual ~DateTime() override;

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

        friend std::ostream __REFERENCE__ operator<<(std::ostream __REFERENCE__ os, DateTime __REFERENCE__ date);
    };

    std::ostream __REFERENCE__ operator<<(std::ostream __REFERENCE__ os, TimeSpan __REFERENCE__ span);
    std::ostream __REFERENCE__ operator<<(std::ostream __REFERENCE__ os, DateTime __REFERENCE__ date);
}

#endif // !__DTY_COMMON_NATIVE_PRIME_DATETIME_H_PLUS_PLUS__