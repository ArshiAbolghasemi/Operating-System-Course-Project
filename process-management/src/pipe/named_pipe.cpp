#include "../../include/pipe/named_pipe.hpp"

NamedPipe::NamedPipe(std::string _fifoPath, mode_t __mode_t)
{
    this->fifoPath = _fifoPath;
    this->mode = __mode_t;
    if (mkfifo(this->fifoPath.c_str(), this->mode) < 0 && errno != EEXIST) {
        Log::error("failed to create named pipe %s",
            Color::color(this->fifoPath, colors::Red).c_str());
        throw new std::runtime_error("failed to create named pipe");
    }
    Log::info("named pipe %s is created successfully",
        Color::color(this->fifoPath, colors::CYAN).c_str());
}

NamedPipe::~NamedPipe() {}