#ifndef _BMP_HEADER_HPP_
#define _BMP_HEADER_HPP_

#include <cstdint>

#pragma pack(push, 1)

constexpr uint16_t BMP_SIGNATURE = 0x4D42; // "BMP"

struct BMPHeader
{
    uint16_t signature;  // "BMP"
    uint32_t fileSize;   // size of the BMP file in bytes
    uint32_t reserved;   // contains two 16-bit unused values
    uint32_t dataOffset; // offset from the beginning of the file to the bitmap data
};

struct BMPInfoHeader
{
    uint32_t headerSize;      // size of this header in bytes (40)
    int32_t  width;           // width of the bitmap in pixels
    int32_t  height;          // height of the bitmap in pixels
    uint16_t planes;          // number of color planes (must be 1)
    uint16_t bitsPerPixel;    // number of bits per pixel (must be 24)
    uint32_t compression;     // compression method being used
    uint32_t imageSize;       // size of the raw bitmap data in bytes
    int32_t  xPixelsPerMeter; // horizontal resolution of the image in pixels per meter
    int32_t  yPixelsPerMeter; // vertical resolution of the image in pixels per meter
    uint32_t colorsUsed;      // number of colors in the color palette
    uint32_t colorsImportant; // number of important colors used
};

#pragma pack(pop)
#endif