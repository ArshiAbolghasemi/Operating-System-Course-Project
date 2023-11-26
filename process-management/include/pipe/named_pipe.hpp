#ifndef _NAMED_PIPE_HPP_
#define _NAMED_PIPE_HPP_

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include "../util/log.hpp"

class NamedPipe
{
private:
    std::string fifoPath;
    mode_t mode;
public:
    NamedPipe(std::string _fifoPath, mode_t __mode_t);
    ~NamedPipe();
};

#endif