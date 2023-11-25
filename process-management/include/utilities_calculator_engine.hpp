#ifndef _UTILITIES_CALCULATOR_ENGINE_HPP_
#define _UTILITIES_CALCULATOR_ENGINE_HPP_

#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <string>
#include <filesystem>
#include <sstream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <map>
#include "./util/log.hpp"
#include "./service/csv_reader.hpp"
#include "./service/file_service.hpp"
#include "./building.hpp"
#include "./util/table.hpp"

class UtilitiesCalculatorEngine
{
private:
    std::string buildingsDataPath;
    int buildingsCount;
    std::vector<Building*> buildings;
public:
    UtilitiesCalculatorEngine(int argc, char* argv[]);
    ~UtilitiesCalculatorEngine();

    void printBuildings();

    int run();
};

#endif