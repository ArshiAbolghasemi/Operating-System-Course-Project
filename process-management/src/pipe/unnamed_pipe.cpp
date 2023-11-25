#include "../../include/pipe/unnamed_pipe.hpp"

UnnamedPipe::UnnamedPipe()
{
    if (pipe(this->fd) < 0) {
        Log::error("failed to create named pipe");  
        throw new std::runtime_error("failed to create named pipe"); 
    }
}

UnnamedPipe::~UnnamedPipe() {}