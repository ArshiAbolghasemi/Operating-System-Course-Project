#ifndef _UTILITY_HPP_
#define _UTILITY_HPP_

#include <string>
#include "worker.hpp"
#include "../pipe/named_pipe.hpp"

class UtilityWorker : public Worker
{
private:
    std::string filePath;
    NamedPipe* namedPipe;
public:
    UtilityWorker(pid_t _pid, std::string _name,
        std::string _filePath, NamedPipe* _nmaedPipe);
    ~UtilityWorker();
        // std::map<std::string, float> calculateUtilityConsumptionMonthStatistic(
    //     const std::map<int, std::map<std::string, std::string>>& utilityMonthConsumption,
    //     std::string utility);
    virtual int execute() override;
};

#endif