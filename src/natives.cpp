#include "natives.hpp"

cell Natives::clock(AMX* amx, cell* params)
{
    return ::clock();
}

cell Natives::difftime(AMX* amx, cell* params)
{
    return (int)::difftime((time_t)params[1], (time_t)params[2]);
}

cell Natives::mktime(AMX* amx, cell* params)
{
    cell* addr;
    amx_GetAddr(amx, params[1], &addr);

    tm timeData;
    timeData.tm_sec = *addr++;
    timeData.tm_min = *addr++;
    timeData.tm_hour = *addr++;
    timeData.tm_mday = *addr++;
    timeData.tm_mon = *addr++;
    timeData.tm_year = *addr++;
    timeData.tm_wday = *addr++;
    timeData.tm_yday = *addr++;
    timeData.tm_isdst = *addr;

    time_t timestamp = mktime(&timeData);

    return (int)timestamp;
}

cell Natives::asctime(AMX* amx, cell* params)
{
    cell* addr;
    amx_GetAddr(amx, params[1], &addr);

    tm timeData;
    timeData.tm_sec = *addr++;
    timeData.tm_min = *addr++;
    timeData.tm_hour = *addr++;
    timeData.tm_mday = *addr++;
    timeData.tm_mon = *addr++;
    timeData.tm_year = *addr++;
    timeData.tm_wday = *addr++;
    timeData.tm_yday = *addr++;
    timeData.tm_isdst = *addr;

    amx_GetAddr(amx, params[2], &addr);
    amx_SetString(addr, ::asctime(&timeData), 0, 0, params[3]);

    return 1;
}

cell Natives::ctime(AMX* amx, cell* params)
{
    cell* addr;
    time_t timestamp = (time_t)params[1];
    amx_GetAddr(amx, params[2], &addr);
    amx_SetString(addr, ::ctime(&timestamp), 0, 0, params[3]);

    return 1;
}

cell Natives::gmtime(AMX* amx, cell* params)
{
    cell* addr;
    amx_GetAddr(amx, params[2], &addr);

    time_t timestamp = (time_t)params[1];
    tm timeData = *::gmtime(&timestamp);
    *addr++ = timeData.tm_sec;
    *addr++ = timeData.tm_min;
    *addr++ = timeData.tm_hour;
    *addr++ = timeData.tm_mday;
    *addr++ = timeData.tm_mon;
    *addr++ = timeData.tm_year;
    *addr++ = timeData.tm_wday;
    *addr++ = timeData.tm_yday;
    *addr = timeData.tm_isdst;

    return 1;
}

cell Natives::localtime(AMX* amx, cell* params)
{
    cell* addr;
    amx_GetAddr(amx, params[2], &addr);

    time_t timestamp = (time_t)params[1];
    tm timeData = *::localtime(&timestamp);
    *addr++ = timeData.tm_sec;
    *addr++ = timeData.tm_min;
    *addr++ = timeData.tm_hour;
    *addr++ = timeData.tm_mday;
    *addr++ = timeData.tm_mon;
    *addr++ = timeData.tm_year;
    *addr++ = timeData.tm_wday;
    *addr++ = timeData.tm_yday;
    *addr = timeData.tm_isdst;

    return 1;
}

cell Natives::strftime(AMX* amx, cell* params)
{
    cell* addr;
    amx_GetAddr(amx, params[4], &addr);

    tm timeData;
    timeData.tm_sec = *addr++;
    timeData.tm_min = *addr++;
    timeData.tm_hour = *addr++;
    timeData.tm_mday = *addr++;
    timeData.tm_mon = *addr++;
    timeData.tm_year = *addr++;
    timeData.tm_wday = *addr++;
    timeData.tm_yday = *addr++;
    timeData.tm_isdst = *addr;

    int length = params[2];
    char* buffer = new char[length];
    std::string format = amx_GetCppString(amx, params[3]);

    std::strftime(buffer, length, format.c_str(), &timeData);

    amx_GetAddr(amx, params[1], &addr);
    amx_SetString(addr, buffer, 0, 0, params[2]);

    delete[] buffer;

    return 1;
}