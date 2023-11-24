#ifndef _COLORS_HPP_
#define _COLORS_HPP_

#include <string>
#include <unistd.h>

namespace colors
{
    inline std::string Reset  = isatty(fileno(stdout)) ? "\033[0m"  : "";
    inline std::string Red    = isatty(fileno(stdout)) ? "\033[31m" : "";
    inline std::string Green  = isatty(fileno(stdout)) ? "\033[32m" : "";
    inline std::string Yellow = isatty(fileno(stdout)) ? "\033[33m" : "";
}

#endif