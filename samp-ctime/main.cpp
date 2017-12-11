/* 
	CTime Library Plugin For Pawn
    Copyright © 2011 RyDeR`
*/

#include "SDK/amx/amx.h"
#include "SDK/plugincommon.h"

#include "main.h"
#include "natives.h"
#include "ctime.h"

CTime
	*g_CTime
;

logprintf_t 
    logprintf
;

extern void 
    *pAMXFunctions
;

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData) {
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];
	g_CTime = new CTime();

	logprintf(" \n » CTime Library Plugin For Pawn v%s - Copyright © 2011 RyDeR` \n ", VERSION);
	
	return 1;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload() {
	delete g_CTime;
}

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() {
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

AMX_NATIVE_INFO amx_Natives[] = {
	{ "clock", Natives::CTime_clock },
	{ "difftime", Natives::CTime_difftime },
	{ "mktime", Natives::CTime_mktime },
	{ "asctime", Natives::CTime_asctime },
	{ "ctime", Natives::CTime_ctime },
	{ "gmtime", Natives::CTime_gmtime },
	{ "localtime", Natives::CTime_localtime },
	{ "strftime", Natives::CTime_strftime },
	{0, 0}
};

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX *pAMX) {
	return amx_Register(pAMX, amx_Natives, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *pAMX) {
	return AMX_ERR_NONE;
}
