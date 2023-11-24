#ifndef _LOG_HPP_
#define _LOG_HPP_

#include <iostream>
#include <stdexcept>
#include <cstdarg>
#include "colors.hpp"
#include "log_level.hpp"

class Log
{
private:
    static void logMsg(const LogLevel logLevel, const std::string &format, va_list &args);
    static void logLevelMsg(const LogLevel logLevel);
public:
    static void info(const std::string &format, ...);
    static void warn(const std::string &format, ...);
    static void error(const std::string &format, ...);
};

#endif