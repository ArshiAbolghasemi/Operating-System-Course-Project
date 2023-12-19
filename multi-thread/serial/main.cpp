#include <iostream>
#include <string>
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

    BMP copy1 = bmp;
    auto startVerticalFlip = timeService->getNow();
    Filter::verticalFlip(copy1);
    auto endVerticalFlip = timeService->getNow();
    APM::logExecutionTime(startVerticalFlip, endVerticalFlip, "Flip");
    copy1.save("vertical_flip.bmp");  

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