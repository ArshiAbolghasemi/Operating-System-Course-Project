#ifndef _PIXEL_HPP_
#define _PIXEL_HPP_

#include <cstdint>

#pragma pack(push, 1)
struct Pixel
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;

    Pixel& operator=(const Pixel& pixel);
};

#pragma pack(pop)

#endif