#ifndef _FILE_SERVICE_HPP
#define _FILE_SERVICE_HPP

#include <filesystem>
#include <tuple>
#include <vector>
#include "../util/log.hpp"

class FileService
{
private:
public:
    static std::tuple<int, std::vector<std::string>> getSubDirectories(
        std::string directory);
};

#endif