#include "../../include/worker/utility_worker.hpp"

UtilityWorker::UtilityWorker(pid_t _pid, std::string _name,
        std::string _filePath, UnnamedPipe* _unnmaedPipe) :
        Worker(_pid, _name)
{
    this->filePath = _filePath;
    this->unnamedPipe = _unnmaedPipe;
}

UtilityWorker::~UtilityWorker() {}

std::map<std::string, float> UtilityWorker::calculateUtilityConsumptionMonthStatistic(
    const std::map<int, std::map<std::string, std::string>>& utilityMonthConsumption)
{
    std::map<std::string, float> result;
    std::map<std::string, int> allConsumptionsPerHour;
    int allConsumption = 0;
    float mean;
    
    for (auto dailyConsumption : utilityMonthConsumption) {
        for (auto hourConsumptions : Util::mapSlice(dailyConsumption.second, 4, 6)) {
            allConsumption += std::stoi(hourConsumptions.second);
            if (allConsumptionsPerHour.find(hourConsumptions.first) != allConsumptionsPerHour.end()) {
                allConsumptionsPerHour[hourConsumptions.first] += std::stoi(hourConsumptions.second);
            } else {
                allConsumptionsPerHour[hourConsumptions.first] = std::stoi(hourConsumptions.second);
            }
        }   
    }

    mean = (float)allConsumption / (float)MONTH_DAYS;

    return result;
}

int UtilityWorker::execute() 
{
    Log::info("utility process %s with pid %s starts", 
        Color::color(this->name, colors::CYAN).c_str(),
        Color::color(std::to_string(this->pid), colors::CYAN).c_str());
    
    std::map<int ,std::map<std::string, std::string>> buildingUtilityConsumptionData = 
        CSVReader::read(this->filePath + CSV_EXTENSION);
    
    for (auto monthlyUtilityConsumptionData : Util::mapChunk(buildingUtilityConsumptionData, 30)) {

    }

    return EXIT_SUCCESS;
}