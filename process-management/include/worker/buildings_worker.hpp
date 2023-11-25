#ifndef _BUILDINGS_WORKER_HPP_
#define _BUILDINGS_WORKER_HPP_

#include "worker.hpp"

class BuildingsWorker : public Worker
{
private:
public:
    BuildingsWorker(pid_t pid, std::string name);
    ~BuildingsWorker();
};

#endif