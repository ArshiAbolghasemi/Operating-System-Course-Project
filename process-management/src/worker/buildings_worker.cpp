#include "../../include/worker/buildings_worker.hpp"

BuildingsWorker::BuildingsWorker(pid_t _pid, std::string _name, int _bid,
        NamedPipe* _namedPipe, UnnamedPipe* _unnamedPipe,
        std::vector<std::string> _utilities, std::string _buildingsDataFilePath) :
        Worker(_pid, _name)
{
    this->bid = _bid;
    this->namedPipe = _namedPipe;
    this->unnamedPipe = _unnamedPipe;
    this->utilities = _utilities;
    this->buildingsDataFilePath = _buildingsDataFilePath;
}

BuildingsWorker::~BuildingsWorker() {}

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

int BuildingsWorker::execute()
{
    Log::info("worker %s with pid %s start to process",
        Color::color(this->name, colors::CYAN).c_str(),
        Color::color(std::to_string(this->pid), colors::CYAN).c_str());
    
    std::vector<UtilityWorker*> utilityWorkers;
    std::string buildingFilePath = this->buildingsDataFilePath + this->name;
    std::vector<NamedPipe*> utilityWorkersNamedPipes;
    for(auto utility : this->utilities) {
        pid_t pid = fork();
        if (pid < 0) {
            Log::error("failed to create utility %s process for building %s",
                Color::color(utility, colors::Red).c_str(),
                Color::color(this->name, colors::Red).c_str()
            );
            throw new std::runtime_error("failed to create process");
        } else if (pid > 0) {
            NamedPipe* pipe = new NamedPipe("/tmp/" + this->name + '_' + utility, 0666);
            utilityWorkersNamedPipes.push_back(namedPipe);
            UtilityWorker* worker = new UtilityWorker(pid, buildingFilePath,
                buildingFilePath, pipe);
            utilityWorkers.push_back(worker);    
            Log::info("create utility %s process with pid %s for building %s",
                Color::color(utility, colors::CYAN).c_str(),
                Color::color(std::to_string((int)pid), colors::CYAN).c_str(),
                Color::color(this->name, colors::CYAN).c_str());
            worker->execute();
            return EXIT_SUCCESS;
        }

        for (auto utilityWorker : utilityWorkers) {
            waitpid(utilityWorker->getPID(), NULL, 0);
        }
    }
    
    return EXIT_SUCCESS;
}
