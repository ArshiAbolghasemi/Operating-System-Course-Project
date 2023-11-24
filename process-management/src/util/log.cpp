#include "../../include/util/log.hpp"

void Log::logLevelMsg(const LogLevel logLevel)
{
    switch (logLevel)
    {
        case LogLevel::INFO:
            std::cout << colors::Green + "[INFO]" + colors::Reset << " ";
            break;
        case LogLevel::WARNING:
            std::cout << colors::Yellow + "[WARNING]" + colors::Reset << " ";    
            break;
        case LogLevel::ERROR:
            std::cout << colors::Red + "[ERROR]" + colors::Reset << " ";
        default:
            throw new std::runtime_error("Invalid log level!");
    }
}

void Log::logMsg(const LogLevel logLevel, const std::string &format, va_list &args)
{
    logLevelMsg(logLevel);
    vprintf(format.c_str(), args);
    std::cout << std::endl;
}

void Log::info(const std::string &format, ...)
{
    va_list args;
    va_start(args, format);
    logMsg(LogLevel::INFO, format, args);
    va_end(args);
}

void Log::warn(const std::string &format, ...)
{
    va_list args;
    va_start(args, format);
    logMsg(LogLevel::WARNING, format, args);
    va_end(args);
}

void Log::error(const std::string &format, ...)
{
    va_list args;
    va_start(args, format);
    logMsg(LogLevel::ERROR, format, args);
    va_end(args);
}