#include "../../include/util/colors.hpp"

std::string Color::color(std::string text, std::string color)
{
    return color + text + colors::Reset;
}