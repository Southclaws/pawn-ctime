/* 
	CTime Library Plugin For Pawn
    Copyright © 2011 RyDeR`
*/

namespace Natives
{
	cell AMX_NATIVE_CALL CTime_clock(AMX *pAMX, cell *iParams);
	cell AMX_NATIVE_CALL CTime_difftime(AMX *pAMX, cell *iParams);
	cell AMX_NATIVE_CALL CTime_mktime(AMX *pAMX, cell *iParams);
	cell AMX_NATIVE_CALL CTime_asctime(AMX *pAMX, cell *iParams);
	cell AMX_NATIVE_CALL CTime_ctime(AMX *pAMX, cell *iParams);
	cell AMX_NATIVE_CALL CTime_gmtime(AMX *pAMX, cell *iParams);
	cell AMX_NATIVE_CALL CTime_localtime(AMX *pAMX, cell *iParams);
	cell AMX_NATIVE_CALL CTime_strftime(AMX *pAMX, cell *iParams);
};