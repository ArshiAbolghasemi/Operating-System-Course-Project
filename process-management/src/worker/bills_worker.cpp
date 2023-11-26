#include "../../include/worker/bills_worker.hpp"

BillsWorker::BillsWorker(pid_t _pid, std::string _name, std::vector<std::string> _utilities,
        std::vector<NamedPipe*> _namedPipes, UnnamedPipe* _unnamedPipe)
        : Worker(_pid, _name)
{
    this->utilities = _utilities;
    this->namedPipes = _namedPipes;
    this->unnamedPipe = _unnamedPipe;
}

BillsWorker::~BillsWorker() {}

int BillsWorker::execute()
{
    Log::info("fuck from %d", this->pid);
    return EXIT_SUCCESS;
}