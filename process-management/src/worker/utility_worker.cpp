#include "../../include/worker/utility_worker.hpp"

UtilityWorker::UtilityWorker(pid_t _pid, std::string _name,
        std::string _filePath, NamedPipe* _nmaedPipe) :
        Worker(_pid, _name)
{
    this->filePath = _filePath;
    this->namedPipe = _nmaedPipe;
}

UtilityWorker::~UtilityWorker() {}

// std::map<std::string, float> BuildingsWorker::calculateUtilityConsumptionMonthStatistic(
//         const std::map<int, std::map<std::string, std::string>>& utilityMonthConsumption,
//         std::string utility)
// {
//     std::map<std::string, float> result;
//     std::map<std::string, int> allConsumptionsPerHour;
//     int allConsumption = 0;
//     float mean;
    
//     for (auto dailyConsumption : utilityMonthConsumption) {
//         for (auto hourConsumptions : Util::mapSlice(dailyConsumption.second, 4, 6)) {
//             allConsumption += std::stoi(hourConsumptions.second);
//             if (allConsumptionsPerHour.find(hourConsumptions.first) != allConsumptionsPerHour.end()) {
//                 allConsumptionsPerHour[hourConsumptions.first] += std::stoi(hourConsumptions.second);
//             } else {
//                 allConsumptionsPerHour[hourConsumptions.first] = std::stoi(hourConsumptions.second);
//             }
//         }   
//     }

//     mean = (float)allConsumption / (float)MONTH_DAYS;

//     return result;
// }    

int UtilityWorker::execute() 
{
    Log::info("hi %s", this->name.c_str());
    return EXIT_SUCCESS;
}