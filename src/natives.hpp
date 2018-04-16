#include <amx/amx2.h>
#include <chrono>
#include <ctime>
#include <string>

#include "common.hpp"

namespace Natives {
cell clock(AMX* pAMX, cell* iParams);
cell difftime(AMX* pAMX, cell* iParams);
cell mktime(AMX* pAMX, cell* iParams);
cell asctime(AMX* pAMX, cell* iParams);
cell ctime(AMX* pAMX, cell* iParams);
cell gmtime(AMX* pAMX, cell* iParams);
cell localtime(AMX* pAMX, cell* iParams);
cell strftime(AMX* pAMX, cell* iParams);
};
