#ifndef _UTILITY_HPP_
#define _UTILITY_HPP_

#include <string>
#include "worker.hpp"
#include "../pipe/unnamed_pipe.hpp"

class UtilityWorker : public Worker
{
private:
    std::string filePath;
    UnnamedPipe* unnamedPipe;
public:
    UtilityWorker(pid_t _pid, std::string _name,
        std::string _filePath, UnnamedPipe* _unnmaedPipe);
    ~UtilityWorker();
};

#endif