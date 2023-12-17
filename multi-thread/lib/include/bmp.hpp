#ifndef _BMP_HPP_
#define _BMP_HPP_

#include <string>
#include <fstream>
#include <exception>

#include "bmp_header.hpp"
#include "pixel.hpp"

class BMP
{
private:
    std::ifstream* file;
    BMPHeader* header;
    BMPInfoHeader* infoHeader;
    Pixel* pixels;

    void loadFile();
    void loadHeaders();
    void loadPixels();
public:
    explicit BMP(const std::string& fileName);
    ~BMP();

    Pixel& operator()(int r, int c);
    Pixel operator()(int r, int c) const;

    size_t getHeight();
    size_t getWidth();

    void save(const std::string& fileName);
};

#endif