#include <iostream>
#include <string>
#include <vector>
#include "../lib/include/bmp/bmp.hpp"
#include "../lib/include/bmp/filter.hpp"
#include "../lib/include/util/time_service.hpp"
#include "../lib/include/util/apm.hpp"

void applyFilters(std::string fileName)
{
    TimeService* timeService = new TimeService();

    auto startRead = timeService->getNow();
    BMP bmp(fileName);
    auto endRead = timeService->getNow();
    APM::logExecutionTime(startRead, endRead, "Read");

    std::vector<std::string> filters = {
        "vertical_flip",
        "blur",
        "purple_haze",
        "diognal_hatch"
    };

    auto startTime = timeService->getNow();
    for (const auto& filter : filters) {
        BMP copy = bmp;

        auto startTime = timeService->getNow();

        if (filter == "vertical_flip") {
            Filter::verticalFlip(copy);
        } else if (filter == "blur") {
            Filter::blur(copy);
        } else if (filter == "purple_haze") {
            Filter::purpleHaze(copy);
        } else if (filter == "diognal_hatch") {
            Filter::diagonalHatch(copy, {0, 0, 0});
        } else {
            throw new std::runtime_error("invalid filter");
        }
        
        auto endTime = timeService->getNow();

        APM::logExecutionTime(startTime, endTime, filter);

        copy.save("output/" + filter + ".bmp");
    }
    auto endTime = timeService->getNow();
    APM::logExecutionTime(startTime, endTime,  "execution");

    delete timeService; 
}

int main(int argc, char* argv[]) 
{
    try{ 
        if (argc != 2) {
            std::cerr << "usage ./ImageFilters.out <bmp file path>" << std::endl;
        }

        std::string inputFileName = argv[1];
        applyFilters(inputFileName);

        return EXIT_SUCCESS;
    } catch (std::exception* e) {
        std::cout << e->what() << std::endl;
        return EXIT_FAILURE;
    }
}