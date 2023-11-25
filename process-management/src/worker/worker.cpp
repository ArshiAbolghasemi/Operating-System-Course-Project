#include "../../include/worker/worker.hpp"

Worker::Worker(pid_t _pid, std::string _name)
{
    this->pid = _pid;
    this->name = _name;
}

Worker::~Worker() {}

pid_t Worker::getPID()
{
    return this->pid;
}