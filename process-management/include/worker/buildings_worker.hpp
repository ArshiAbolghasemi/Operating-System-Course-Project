#ifndef _BUILDINGS_WORKER_HPP_
#define _BUILDINGS_WORKER_HPP_

#include "worker.hpp"
#include "../pipe/unnamed_pipe.hpp"
#include "../pipe/named_pipe.hpp"

class BuildingsWorker : public Worker
{
private:
    int bid;
    NamedPipe* namedPipe;
    UnnamedPipe* unnamedPipe;
public:
    BuildingsWorker(pid_t _pid, std::string _name, int _bid,
        NamedPipe* _namedPipe, UnnamedPipe* _unnamedPipe);
    ~BuildingsWorker();
    virtual int execute() override;
};

#endif