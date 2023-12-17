#ifndef _BMP_HPP_
#define _BMP_HPP_

#include <string>
#include <fstream>
#include <exception>
#include <vector>

#include "bmp_header.hpp"
#include "pixel.hpp"

class BMP
{
private:
    std::ifstream* file;
    BMPHeader* header;
    BMPInfoHeader* infoHeader;
    std::vector<Pixel*> pixels;

    void loadFile();
    void loadHeaders();
    void loadPixels();
public:
    explicit BMP(const std::string& fileName);
    ~BMP();
};

#endif