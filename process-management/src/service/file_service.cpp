#include "../../include/service/file_service.hpp"

std::tuple<int, std::vector<std::string>> FileService::getSubDirectories(
    std::string directory
)
{
    try {
        if (!std::filesystem::exists(directory) || !std::filesystem::is_directory(directory)) {
            throw new std::runtime_error("invalid directory path");
        }

        int subDirectoriesCnt = 0;
        std::vector<std::string> subDirectories;
        for (const auto& entry : std::filesystem::directory_iterator(directory)) {
            if (!std::filesystem::is_directory(entry.path())) continue;
            
            subDirectories.push_back(entry.path().filename());
            subDirectoriesCnt++;
        }

        return std::tuple<int, std::vector<std::string>>(subDirectoriesCnt, subDirectories);
    } catch (const std::filesystem::filesystem_error& exception) {
        Log::error("file system error: %s", exception.what());
        throw exception;
    } catch (const std::exception& exception) {
        Log::error("exception: %s", exception.what());
        throw exception;
    }
}