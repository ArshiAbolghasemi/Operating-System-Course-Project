#include "../../include/worker/utility_worker.hpp"

UtilityWorker::UtilityWorker(pid_t _pid, std::string _name,
        std::string _filePath, NamedPipe* _nmaedPipe) :
        Worker(_pid, _name)
{
    this->filePath = _filePath;
    this->namedPipe = _nmaedPipe;
}

UtilityWorker::~UtilityWorker() {}

int UtilityWorker::execute() 
{
    Log::info("hi %s", this->name.c_str());
    return EXIT_SUCCESS;
}