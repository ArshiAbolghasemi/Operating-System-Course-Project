#include "../../include/worker/utility_worker.hpp"

UtilityWorker::UtilityWorker(pid_t _pid, std::string _name,
        std::string _filePath, UnnamedPipe* _unnmaedPipe) :
        Worker(_pid, _name)
{
    this->filePath = _filePath;
    this->unnamedPipe = _unnmaedPipe;
}

UtilityWorker::~UtilityWorker() {}

