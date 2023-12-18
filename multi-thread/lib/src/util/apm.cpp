#include "../../include/util/apm.hpp"

APM::APM() {}

APM::~APM() {}

void APM::logExecutionTime(std::chrono::time_point<std::chrono::high_resolution_clock>& start,
        std::chrono::time_point<std::chrono::high_resolution_clock>& end, 
        std::string name) 
{
    auto duration = (new TimeService())->diff(end, start);

    std::cout << name + ": " << duration.count() << " ms" << std::endl;
}