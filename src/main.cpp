#include <amx/amx.h>
#include <plugincommon.h>

#include "common.hpp"
#include "natives.hpp"

logprintf_t logprintf;

extern "C" const AMX_NATIVE_INFO native_list[] = {
    { "clock", Natives::clock },
    { "difftime", Natives::difftime },
    { "mktime", Natives::mktime },
    { "asctime", Natives::asctime },
    { "ctime", Natives::ctime },
    { "gmtime", Natives::gmtime },
    { "localtime", Natives::localtime },
    { "strftime", Natives::strftime },
    { 0, 0 }
};

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
    return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData)
{
    pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
    logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];
    return true;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx)
{
    // return pawn_natives::AmxLoad(amx);
    return amx_Register(amx, native_list, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL Unload()
{
    return 1;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload()
{
    return 1;
}
