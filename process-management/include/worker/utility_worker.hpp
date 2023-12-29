#ifndef _UTILITY_HPP_
#define _UTILITY_HPP_

#include <string>
#include "worker.hpp"
#include "../pipe/unnamed_pipe.hpp"
#include "../service/csv_reader.hpp"
#include "../enums/date_enums.hpp"

class UtilityWorker : public Worker
{
private:
    std::string filePath;
    UnnamedPipe* unnamedPipe;
public:
    UtilityWorker(pid_t _pid, std::string _name,
        std::string _filePath, UnnamedPipe* _unnmaedPipe);
    ~UtilityWorker();
    std::map<std::string, float> calculateUtilityConsumptionMonthStatistic(
        const std::map<int, std::map<std::string, std::string>>& utilityMonthConsumption);
    virtual int execute() override;
};

#endif