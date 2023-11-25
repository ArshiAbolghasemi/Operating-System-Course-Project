#include "../../include/pipe/named_pipe.hpp"

NamedPipe::NamedPipe(const char* _fifoPath, mode_t __mode_t)
{
    this->fifoPath = _fifoPath;
    this->mode = __mode_t;
    mkfifo(this->fifoPath, this->mode);
}

NamedPipe::~NamedPipe() {}