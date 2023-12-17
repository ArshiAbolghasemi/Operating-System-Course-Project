#ifndef _PIXEL_HPP_
#define _PIXEL_HPP_

#include <cstdint>

#pragma pack(push, 1)
struct pixel
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

#pragma pack(pop)

#endif