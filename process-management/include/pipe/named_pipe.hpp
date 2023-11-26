#ifndef _NAMED_PIPE_HPP_
#define _NAMED_PIPE_HPP_

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

class NamedPipe
{
private:
    const char* fifoPath;
    mode_t mode;
public:
    NamedPipe(const char* _fifoPath, mode_t __mode_t);
    ~NamedPipe();
};

#endif