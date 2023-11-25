#ifndef _UNNAMED_PIPE_HPP_
#define _UNNAMED_PIPE_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../util/log.hpp"

class UnnamedPipe
{
private:
    int fd[2];
public:
    UnnamedPipe();
    ~UnnamedPipe();
};

#endif