#include "../../include/bmp/pixel.hpp"

Pixel& Pixel::operator=(const Pixel& pixel)
{
    if (this == &pixel) return *this;
    
    this->red = pixel.red;
    this->green = pixel.green;
    this->blue = pixel.blue;

    return *this;
}