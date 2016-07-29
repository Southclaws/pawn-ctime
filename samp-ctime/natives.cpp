/* 
	CTime Library Plugin For Pawn
    Copyright © 2011 RyDeR`
*/

#define _CRT_SECURE_NO_WARNINGS

#include "SDK/amx/amx.h"
#include "SDK/plugincommon.h"

#include "natives.h"
#include "ctime.h"

cell AMX_NATIVE_CALL Natives::CTime_clock(AMX *pAMX, cell *iParams) {
	return clock();
}

cell AMX_NATIVE_CALL Natives::CTime_difftime(AMX *pAMX, cell *iParams) {
	return (int)difftime((time_t)iParams[1], (time_t)iParams[2]);
}

cell AMX_NATIVE_CALL Natives::CTime_mktime(AMX *pAMX, cell *iParams) {
	cell
		*iPhysAddr
	;
	amx_GetAddr(pAMX, iParams[1], &iPhysAddr);

	tm
		tmPtr
	;
	g_CTime->SetTimePointer(&tmPtr, iPhysAddr);
	
	time_t
		tTime = mktime(&tmPtr);
	;
	g_CTime->SetArrayAddress(iPhysAddr, &tmPtr);

	return (int)tTime;
}


cell AMX_NATIVE_CALL Natives::CTime_asctime(AMX *pAMX, cell *iParams) {
	cell
		*iPhysAddr
	;
	amx_GetAddr(pAMX, iParams[1], &iPhysAddr);

	tm
		tmPtr
	;
	g_CTime->SetTimePointer(&tmPtr, iPhysAddr);

	amx_GetAddr(pAMX, iParams[2], &iPhysAddr);
	amx_SetString(iPhysAddr, asctime(&tmPtr), 0, 0, iParams[3]);

	return 1;
}

cell AMX_NATIVE_CALL Natives::CTime_ctime(AMX *pAMX, cell *iParams) {
	cell
		*iPhysAddr
	;
	time_t
		tTime = (time_t)iParams[1]
	;
	amx_GetAddr(pAMX, iParams[2], &iPhysAddr);
	amx_SetString(iPhysAddr, ctime(&tTime), 0, 0, iParams[3]);

	return 1;
}

cell AMX_NATIVE_CALL Natives::CTime_gmtime(AMX *pAMX, cell *iParams) {
	cell
		*iPhysAddr
	;
	amx_GetAddr(pAMX, iParams[2], &iPhysAddr);

	time_t
		tTime = (time_t)iParams[1]
	;
	tm
		*tmPtr = NULL
	;
	tmPtr = gmtime(&tTime);

	g_CTime->SetArrayAddress(iPhysAddr, tmPtr);

	return 1;
}

cell AMX_NATIVE_CALL Natives::CTime_localtime(AMX *pAMX, cell *iParams) {
	cell
		*iPhysAddr
	;
	amx_GetAddr(pAMX, iParams[2], &iPhysAddr);

	time_t
		tTime = (time_t)iParams[1]
	;
	tm
		*tmPtr = NULL
	;
	tmPtr = localtime(&tTime);

	g_CTime->SetArrayAddress(iPhysAddr, tmPtr);

	return 1;
}

cell AMX_NATIVE_CALL Natives::CTime_strftime(AMX *pAMX, cell *iParams) {
	cell
		*iPhysAddr
	;
	amx_GetAddr(pAMX, iParams[4], &iPhysAddr);

	tm
		tmPtr
	;
	g_CTime->SetTimePointer(&tmPtr, iPhysAddr);

	int
		iSize = iParams[2]
	;
	char
		*szFormat = new char[iSize]
	;
	amx_GetAddr(pAMX, iParams[3], &iPhysAddr);
	amx_GetString(szFormat, iPhysAddr, 0, iSize);

	char
		*szBuf = new char[iSize]
	;
	strftime(szBuf, iSize, szFormat, &tmPtr);
	
	amx_GetAddr(pAMX, iParams[1], &iPhysAddr);
	amx_SetString(iPhysAddr, szBuf, 0, 0, iParams[2]);

	delete szFormat;
	delete szBuf;

	return 1;
}