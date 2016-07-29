/* 
	CTime Library Plugin For Pawn
    Copyright © 2011 RyDeR`
*/

#include "SDK/amx/amx.h"
#include "SDK/plugincommon.h"

#include "ctime.h"

CTime::CTime() {
}

CTime::~CTime() {
	delete g_CTime;
}

void CTime::SetTimePointer(tm *tmPtr, cell *iPhysAddr) {
	tmPtr->tm_sec = *iPhysAddr++;
	tmPtr->tm_min = *iPhysAddr++;
	tmPtr->tm_hour = *iPhysAddr++;
	tmPtr->tm_mday = *iPhysAddr++;
	tmPtr->tm_mon = *iPhysAddr++;
	tmPtr->tm_year = *iPhysAddr++;
	tmPtr->tm_wday = *iPhysAddr++;
	tmPtr->tm_yday = *iPhysAddr++;
	tmPtr->tm_isdst = *iPhysAddr;
}

void CTime::SetArrayAddress(cell *iPhysAddr, tm *tmPtr) {
	*iPhysAddr++ = tmPtr->tm_sec;
	*iPhysAddr++ = tmPtr->tm_min;
	*iPhysAddr++ = tmPtr->tm_hour;
	*iPhysAddr++ = tmPtr->tm_mday;
	*iPhysAddr++ = tmPtr->tm_mon;
	*iPhysAddr++ = tmPtr->tm_year;
	*iPhysAddr++ = tmPtr->tm_wday;
	*iPhysAddr++ = tmPtr->tm_yday;
	*iPhysAddr = tmPtr->tm_isdst;
}