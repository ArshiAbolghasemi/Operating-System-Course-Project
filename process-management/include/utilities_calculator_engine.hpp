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
#include "./worker/worker.hpp"
#include "./worker/bills_worker.hpp"
#include "./worker/buildings_worker.hpp"
#include "./util/cli.hpp"
#include "./pipe/named_pipe.hpp"
#include "./pipe/unnamed_pipe.hpp"
#include "./util/colors.hpp"

class UtilitiesCalculatorEngine
{
private:
    std::string buildingsDataPath;
    int buildingsCount;
    std::vector<Building*> buildings;

    void printBuildings();
    std::vector<std::string> getBuildingsFromUser();
    std::vector<std::string> getUtilitiesFromUser();
    std::vector<NamedPipe*> createNamedPipes(std::vector<std::string> buildingNames);
    std::vector<UnnamedPipe*> createUnnamedPipes(int inputBuildingsCnt);
    int runWorkers(std::vector<std::string> inputBuildings, std::vector<std::string> inputUtilities);
public:
    UtilitiesCalculatorEngine(int argc, char* argv[]);
    ~UtilitiesCalculatorEngine();
    int run();
};

#endif