#include <fstream>
#include <iostream>
#include "../include/bmp.hpp"

BMP::BMP(const std::string& fileName)
{
    std::ifstream file(fileName);
    if (!file || !file.is_open()) {
        throw new std::runtime_error("Failed to open " + fileName + "!");
    }

    this->file = &file;
    this->loadFile();
}

BMP::~BMP() 
{
    delete this->header;
    delete this->infoHeader;
    delete this->file;
}

void BMP::loadFile()
{
    this->file->seekg(0, std::ios::end);
    std::streampos length = this->file->tellg();
    this->file->seekg(0, std::ios::beg);

    char* buffer = new char[length];
    this->file->read(&buffer[0], length);

    this->header = (BMPHeader*)(&buffer[0]);
    if (this->header->signature != BMP_SIGNATURE) {
        throw std::runtime_error("Invalid BMP file");
    }

    this->infoHeader = (BMPInfoHeader*)(&buffer[0] + sizeof(BMPInfoHeader));
    if (this->infoHeader->bitsPerPixel != NUMBER_OF_BITS_PER_PIXEL) {
        char errMsg[40];
        sprintf(errMsg, "Only %d-bit BMP files are supported!", NUMBER_OF_BITS_PER_PIXEL);
        throw std::runtime_error(errMsg);
    }
}