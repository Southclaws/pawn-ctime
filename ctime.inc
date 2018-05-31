// built-in include guard removal
// just in case the user has a local dependency with the same file name
#if defined _inc_ctime
	#undef _inc_ctime
#endif
// custom include-guard to ensure we don't duplicate
#if defined _ctime_included
	#endinput
#endif
#define _ctime_included


#define STRFTIME_ISO6801_TIME       "H:%M:%S"            // 09:55:22
#define STRFTIME_ISO6801_DATE       "%Y-%m-%d"           // 2018-05-31
#define STRFTIME_ISO6801_FULL_UTC   "%Y-%m-%dT%H:%M:%SZ" // 2018-05-31T09:55:22Z
#define STRFTIME_ISO6801_FULL_LOCAL "%Y-%m-%dT%H:%M:%S"  // 2018-05-31T09:55:22


enum e_tm {
	tm_sec,
	tm_min,
	tm_hour,
	tm_mday,
	tm_mon,
	tm_year,
	tm_wday,
	tm_yday,
	tm_isdst
};

#define CLOCKS_PER_SEC (1000)

native clock();
native difftime(Time:a, Time:b);
native mktime(tm[e_tm]);
native asctime(tm[e_tm], buf[], const len = sizeof(buf));
native ctime(Time:timestamp, buf[], const len = sizeof(buf));
native gmtime(Time:timestamp, tm[e_tm]);
native localtime(Time:timestamp, tm[e_tm]);
native strftime(buf[], const len, const szFormat[], tm[e_tm]);
