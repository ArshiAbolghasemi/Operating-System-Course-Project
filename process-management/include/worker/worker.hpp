#ifndef _WORKER_HPP_
#define _WORKER_HPP_

#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <string>
#include "../util/log.hpp"
#include "../util/util.hpp"

class Worker
{
protected:
    pid_t pid;
    std::string name;
public:
    Worker(pid_t _pid, std::string _name);
    ~Worker();
    pid_t getPID();
    virtual int execute() = 0;
};


#endif