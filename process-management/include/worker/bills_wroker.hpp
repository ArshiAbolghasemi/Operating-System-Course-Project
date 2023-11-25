#ifndef _BILLS_WORKER_HPP_
#define _BILLS_WORKER_HPP_

#include "worker.hpp"
#include "../pipe/named_pipe.hpp"
#include "../pipe/unnamed_pipe.hpp"

class BillsWorker : public Worker
{
private:
    std::vector<NamedPipe*> namedPipes;
    
public:
    BillsWorker(pid_t _pid, std::string _name, std::vector<NamedPipe*> snamedPipes);
    ~BillsWorker();

    virtual int execute() override;
};

#endif