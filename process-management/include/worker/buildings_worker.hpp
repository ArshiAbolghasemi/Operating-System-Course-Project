#ifndef _BUILDINGS_WORKER_HPP_
#define _BUILDINGS_WORKER_HPP_

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <vector>
#include "worker.hpp"
#include "../pipe/unnamed_pipe.hpp"
#include "../pipe/named_pipe.hpp"
#include "../service/csv_reader.hpp"
#include "../util/util.hpp"
#include "../enums/date_enums.hpp"
#include "utility_worker.hpp"

class BuildingsWorker : public Worker
{
private:
    int bid;
    NamedPipe* namedPipe;
    UnnamedPipe* unnamedPipe;
    std::vector<std::string> utilities;
    std::string buildingsDataFilePath;
public:
    BuildingsWorker(pid_t _pid, std::string _name, int _bid,
        NamedPipe* _namedPipe, UnnamedPipe* _unnamedPipe,
        std::vector<std::string> _utilities, std::string _buildingFilePath);
    ~BuildingsWorker();
    // std::map<std::string, float> calculateUtilityConsumptionMonthStatistic(
    //     const std::map<int, std::map<std::string, std::string>>& utilityMonthConsumption,
    //     std::string utility);
    virtual int execute() override;
};

#endif