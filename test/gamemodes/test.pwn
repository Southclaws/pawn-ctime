#define RUN_TESTS

#include <a_samp>
#include <YSI\y_testing>

#include "../../ctime.inc"

main() {
    //
}

Test:clock() {
    ASSERT(clock() > 0);
}

Test:diff() {
    ASSERT(difftime(Time:1001, Time:1000) == 1);
    ASSERT(difftime(Time:1010, Time:1000) == 10);
    ASSERT(difftime(Time:1000, Time:1001) == -1);
    ASSERT(difftime(Time:1000, Time:1010) == -10);
}

Test:mktime() {
    new tm[e_tm];
    tm[tm_sec] = 45;
    tm[tm_min] = 55;
    tm[tm_hour] = 14;
    tm[tm_mday] = 16;
    tm[tm_mon] = 3;
    tm[tm_year] = 118;
    tm[tm_wday] = 1;
    tm[tm_yday] = 105;
    tm[tm_isdst] = 1;

    ASSERT(mktime(tm) == 1523886945);
}

Test:asctime() {
    new tm[e_tm];
    tm[tm_sec] = 45;
    tm[tm_min] = 55;
    tm[tm_hour] = 14;
    tm[tm_mday] = 16;
    tm[tm_mon] = 3;
    tm[tm_year] = 118;
    tm[tm_wday] = 1;
    tm[tm_yday] = 105;
    tm[tm_isdst] = 1;

    new buf[128];
    ASSERT(asctime(tm, buf, sizeof(buf)) == 1);
    ASSERT(!strcmp(buf, "Mon Apr 16 14:55:45 2018\n"));
}


Test:ctime() {
    new Time:timestamp = Time:1523886945;
    new buf[128];

    ASSERT(ctime(timestamp, buf, sizeof(buf)) == 1);
    ASSERT(!strcmp(buf, "Mon Apr 16 14:55:45 2018\n"));
}

Test:gmtime() {
    new Time:timestamp = Time:1523886945;
    new tm[e_tm];

    ASSERT(gmtime(timestamp, tm) == 1);
    ASSERT(tm[tm_sec] == 45);
    ASSERT(tm[tm_min] == 55);
    ASSERT(tm[tm_hour] == 13);
    ASSERT(tm[tm_mday] == 16);
    ASSERT(tm[tm_mon] == 3);
    ASSERT(tm[tm_year] == 118);
    ASSERT(tm[tm_wday] == 1);
    ASSERT(tm[tm_yday] == 105);
    ASSERT(tm[tm_isdst] == 0);
}

Test:localtime() {
    // localtime is dependent on locale so it's left out of unit tests.
}

Test:strftime() {
    new tm[e_tm];
    tm[tm_sec] = 45;
    tm[tm_min] = 55;
    tm[tm_hour] = 14;
    tm[tm_mday] = 16;
    tm[tm_mon] = 3;
    tm[tm_year] = 118;
    tm[tm_wday] = 1;
    tm[tm_yday] = 105;
    tm[tm_isdst] = 1;

    new buf[128];
    strftime(buf, sizeof(buf), "%a", tm);
    ASSERT(!strcmp(buf, "Mon"));

    strftime(buf, sizeof(buf), "%A", tm);
    ASSERT(!strcmp(buf, "Monday"));

    strftime(buf, sizeof(buf), "%b", tm);
    ASSERT(!strcmp(buf, "Apr"));

    strftime(buf, sizeof(buf), "%B", tm);
    ASSERT(!strcmp(buf, "April"));

    strftime(buf, sizeof(buf), "%c", tm);
    ASSERT(!strcmp(buf, "Mon Apr 16 14:55:45 2018"));

    strftime(buf, sizeof(buf), "%C", tm);
    ASSERT(!strcmp(buf, "20"));

    strftime(buf, sizeof(buf), "%d", tm);
    ASSERT(!strcmp(buf, "16"));

    strftime(buf, sizeof(buf), "%D", tm);
    ASSERT(!strcmp(buf, "04/16/18"));

    strftime(buf, sizeof(buf), "%e", tm);
    ASSERT(!strcmp(buf, "16"));

    strftime(buf, sizeof(buf), "%F", tm);
    ASSERT(!strcmp(buf, "2018-04-16"));

    strftime(buf, sizeof(buf), "%g", tm);
    ASSERT(!strcmp(buf, "18"));

    strftime(buf, sizeof(buf), "%G", tm);
    ASSERT(!strcmp(buf, "2018"));

    strftime(buf, sizeof(buf), "%h", tm);
    ASSERT(!strcmp(buf, "Apr"));

    strftime(buf, sizeof(buf), "%H", tm);
    ASSERT(!strcmp(buf, "14"));

    strftime(buf, sizeof(buf), "%I", tm);
    ASSERT(!strcmp(buf, "02"));

    strftime(buf, sizeof(buf), "%j", tm);
    ASSERT(!strcmp(buf, "106"));

    strftime(buf, sizeof(buf), "%m", tm);
    ASSERT(!strcmp(buf, "04"));

    strftime(buf, sizeof(buf), "%M", tm);
    ASSERT(!strcmp(buf, "55"));

    strftime(buf, sizeof(buf), "%n", tm);
    ASSERT(!strcmp(buf, "\n"));

    strftime(buf, sizeof(buf), "%p", tm);
    ASSERT(!strcmp(buf, "PM"));

    strftime(buf, sizeof(buf), "%r", tm);
    ASSERT(!strcmp(buf, "02:55:45 PM"));

    strftime(buf, sizeof(buf), "%R", tm);
    ASSERT(!strcmp(buf, "14:55"));

    strftime(buf, sizeof(buf), "%S", tm);
    ASSERT(!strcmp(buf, "45"));

    strftime(buf, sizeof(buf), "%t", tm);
    ASSERT(!strcmp(buf, "\t"));

    strftime(buf, sizeof(buf), "%T", tm);
    ASSERT(!strcmp(buf, "14:55:45"));

    strftime(buf, sizeof(buf), "%u", tm);
    ASSERT(!strcmp(buf, "1"));

    strftime(buf, sizeof(buf), "%U", tm);
    ASSERT(!strcmp(buf, "15"));

    strftime(buf, sizeof(buf), "%V", tm);
    ASSERT(!strcmp(buf, "16"));

    strftime(buf, sizeof(buf), "%w", tm);
    ASSERT(!strcmp(buf, "1"));

    strftime(buf, sizeof(buf), "%W", tm);
    ASSERT(!strcmp(buf, "16"));

    strftime(buf, sizeof(buf), "%x", tm);
    ASSERT(!strcmp(buf, "04/16/18"));

    strftime(buf, sizeof(buf), "%X", tm);
    ASSERT(!strcmp(buf, "14:55:45"));

    strftime(buf, sizeof(buf), "%y", tm);
    ASSERT(!strcmp(buf, "18"));

    strftime(buf, sizeof(buf), "%Y", tm);
    ASSERT(!strcmp(buf, "2018"));

    strftime(buf, sizeof(buf), "%z", tm);
    ASSERT(!strcmp(buf, "+0100"));

    strftime(buf, sizeof(buf), "%Z", tm);
    ASSERT(!strcmp(buf, "GMT Summer Time"));
}
