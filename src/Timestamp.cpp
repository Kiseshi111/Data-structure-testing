#include <time.h>
#include "../include/Timestamp.h"

Timestamp::Timestamp() : microSecondsSinceEpoch_(0)
{
}

Timestamp::Timestamp(int64_t microSecondsSinceEpoch)
    : microSecondsSinceEpoch_(microSecondsSinceEpoch)
{
}

Timestamp Timestamp::now()
{
    FILETIME ft;
    GetSystemTimeAsFileTime(&ft); // Get current system time as FILETIME
    ULARGE_INTEGER uli;
    uli.LowPart = ft.dwLowDateTime;
    uli.HighPart = ft.dwHighDateTime;

    return Timestamp(static_cast<int64_t>(uli.QuadPart) / 10 - 11644473600000000LL);
}
std::string Timestamp::toString() const
{
    char buf[128] = { 0 };
    time_t epochSeconds = static_cast<time_t>(microSecondsSinceEpoch_ / 1000000);
    tm tm_time;

    // Get local time using localtime_s
    localtime_s(&tm_time, &epochSeconds);

    snprintf(buf, 128, "%4d/%02d/%02d %02d:%02d:%02d",
        tm_time.tm_year + 1900,
        tm_time.tm_mon + 1,
        tm_time.tm_mday,
        tm_time.tm_hour,
        tm_time.tm_min,
        tm_time.tm_sec);

    return buf;
}

// #include <iostream>
// int main() {
//     std::cout << Timestamp::now().toString() << std::endl;
//     return 0;
// }