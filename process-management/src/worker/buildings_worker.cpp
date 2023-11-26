#include "../../include/worker/buildings_worker.hpp"

BuildingsWorker::BuildingsWorker(pid_t _pid, std::string _name, int _bid,
        NamedPipe* _namedPipe, UnnamedPipe* _unnamedPipe) :
        Worker(_pid, _name)
{
    this->bid = _bid;
    this->namedPipe = _namedPipe;
    this->unnamedPipe = _unnamedPipe;
}

BuildingsWorker::~BuildingsWorker() {}

int BuildingsWorker::execute()
{
    Log::info("hi from %d", this->pid);
    return EXIT_SUCCESS;
}
