#ifndef _BMP_HPP_
#define _BMP_HPP_

#include <string>
#include <fstream>
#include <exception>

#include "bmp_header.hpp"

class BMP
{
private:
    std::ifstream* file;
    char* fileBuffer;
    BMPHeader* header;
    BMPInfoHeader* infoHeader;

    void loadFile();
public:
    explicit BMP(const std::string& fileName);
    ~BMP();
};

#endif