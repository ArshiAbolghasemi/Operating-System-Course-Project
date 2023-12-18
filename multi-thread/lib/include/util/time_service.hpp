#ifndef _TIME_SERVICE_HPP_
#define _TIME_SERVICE_HPP_

#include <chrono>

class TimeService
{
private:
public:
    TimeService();
    ~TimeService();

    std::chrono::time_point<std::chrono::high_resolution_clock> getNow();

    std::chrono::milliseconds diff(std::chrono::time_point<std::chrono::high_resolution_clock>& time1, 
        std::chrono::time_point<std::chrono::high_resolution_clock>& time2);
};

#endif