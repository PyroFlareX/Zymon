#include "FileUtil.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

std::string getFileContents(const std::string& filePath)
{
    std::ifstream inFile(filePath);
    if(!inFile.is_open())
    {
        throw std::runtime_error("Unable to open file: " + filePath);
    }

    std::stringstream stream;

    stream << inFile.rdbuf();
    return stream.str();
}

const char* getFileContentsCStr(const std::string& filePath)
{
    std::ifstream inFile(filePath);
    if(!inFile.is_open())
    {
        throw std::runtime_error("Unable to open file: " + filePath);
    }

    std::stringstream stream;

    stream << inFile.rdbuf();
    return stream.str().c_str();
}

nlohmann::json getJsonFile(const std::string& filePath)
{
	nlohmann::json rjson;
	rjson = nlohmann::json::parse(getFileContents(filePath));
	return rjson;
}
