#include "filesystem.hpp"
#include <string.h>
#include <windows.h>

namespace OS {

std::string hayhaPath;
std::string binPath;
std::string cfgPath;
std::string libPath;
std::string profilesPath;
std::string libPrefix;
std::string libSuffix;
std::string scriptPath;
std::string routesPath;
std::string datasetPath;

void initPaths() {
    char buffer[0x800];
    GetModuleFileName(NULL, buffer, 0x800);
    int len = strlen(buffer);
    int count = 0;
    while (len--) {
        if (buffer[len] == '\\') {
            count++;
            if (count == 2) {
                buffer[len + 1] = '\0';
                break;
            }
        }
    }
    hayhaPath = buffer;

    cfgPath = hayhaPath + "cfg/";

    libPath = hayhaPath + "libs/";

    binPath = hayhaPath + "bin/";

    profilesPath = hayhaPath + "profiles/";

    scriptPath = hayhaPath + "scripts/";

    routesPath = hayhaPath + "routes/";

    datasetPath = hayhaPath + "dataset/";

    libPrefix = "";
    libSuffix = ".dll";
}

} // namespace OS