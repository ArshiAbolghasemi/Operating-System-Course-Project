#ifndef _APM_HPP_
#define _APM_HPP_

#include <iostream>
#include <string>
#include "time_service.hpp"

class APM
{
private:
public:
    APM();
    ~APM();

    static void logExecutionTime(std::chrono::time_point<std::chrono::high_resolution_clock>& start,
        std::chrono::time_point<std::chrono::high_resolution_clock>& end, 
        std::string name);
};

#endif