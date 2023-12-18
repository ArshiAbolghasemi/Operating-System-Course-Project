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
    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;
    Pixel* pixels;

    void loadFile(std::ifstream& file);
    void loadHeaders(std::ifstream& file);
    void loadPixels(std::ifstream& file);
public:
    explicit BMP(const std::string& fileName);
    BMP(const BMP& bmp);
    ~BMP();

    BMP& operator=(const BMP& bmp);
    Pixel& operator()(int row, int col);
    Pixel operator()(int row, int col) const;

    size_t getHeight();
    size_t getWidth();

    void save(const std::string& fileName);
};

#endif