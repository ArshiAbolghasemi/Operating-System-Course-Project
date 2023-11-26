#ifndef _BILLS_WORKER_HPP_
#define _BILLS_WORKER_HPP_

#include <vector>
#include "worker.hpp"
#include "../pipe/named_pipe.hpp"
#include "../pipe/unnamed_pipe.hpp"

class BillsWorker : public Worker
{
private:
    std::vector<std::string> utilities;
    std::vector<NamedPipe*> namedPipes;
    UnnamedPipe* unnamedPipe;
public:
    BillsWorker(pid_t _pid, std::string _name, std::vector<std::string> _utilities,
        std::vector<NamedPipe*> _namedPipes, UnnamedPipe* _unnamedPipe);
    ~BillsWorker();
    virtual int execute() override;
};

#endif