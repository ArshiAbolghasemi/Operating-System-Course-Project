#include "../../include/util/cli.hpp"

std::vector<std::string> CLI::getCommaSeperatedInput()
{
    std::string input;
    std::getline(std::cin, input);

    std::istringstream iss(input);
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(iss, token, ',')) {
        tokens.push_back(token);
    }

    return tokens;
}
