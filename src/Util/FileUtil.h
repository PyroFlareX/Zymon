#ifndef FILEUTIL_H_INCLUDED
#define FILEUTIL_H_INCLUDED

#include <string>
#include "../nlohmann/json.hpp"

std::string getFileContents(const std::string& filePath);
const char* getFileContentsCStr(const std::string& filePath);
nlohmann::json getJsonFile(const std::string& filePath);

#endif // FILEUTIL_H_INCLUDED
