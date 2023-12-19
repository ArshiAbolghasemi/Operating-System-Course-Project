#include "../../include/util/time_service.hpp"

TimeService::TimeService() {}

TimeService::~TimeService() {}

std::chrono::time_point<std::chrono::high_resolution_clock> TimeService::getNow()
{
    return std::chrono::high_resolution_clock::now();
}

std::chrono::duration<double, std::milli> TimeService::diff(std::chrono::time_point<std::chrono::high_resolution_clock>& time1,
    std::chrono::time_point<std::chrono::high_resolution_clock>& time2)
{
    return time1 - time2;
}