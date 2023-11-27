#include "../include/utilities_calculator_engine.hpp"

int main(int argc, char* argv[])
{
    try {
        UtilitiesCalculatorEngine* calculatorEngine = new UtilitiesCalculatorEngine(argc, argv);
        calculatorEngine->run();
        delete calculatorEngine;
    } catch (const std::exception& exception) {
        std::cerr << "exception: " << exception.what() << std::endl;
        return EXIT_FAILURE;
    } catch (const std::runtime_error& exception) {
        std::cerr << "run time error exception: " << exception.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}