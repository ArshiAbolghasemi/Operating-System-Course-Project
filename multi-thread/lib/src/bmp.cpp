#include <fstream>
#include <iostream>
#include "../include/bmp.hpp"

BMP::BMP(const std::string& fileName)
{
    std::ifstream file(fileName, std::ios::binary);
    if (!file || !file.is_open()) {
        throw new std::runtime_error("Failed to open " + fileName + "!");
    }

    this->file = &file;
    this->loadFile();
    this->file->close();
}

BMP::~BMP() 
{
    delete this->header;
    delete this->infoHeader;
    delete this->file;
    delete[] this->pixels;
}

void BMP::loadHeaders()
{
    this->header = new BMPHeader;
    this->file->read(reinterpret_cast<char*>(this->header), sizeof(BMPHeader));
    if (this->header->signature != BMP_SIGNATURE) {
        throw std::runtime_error("Invalid BMP file");
    }

    this->infoHeader = new BMPInfoHeader;
    this->file->read(reinterpret_cast<char*>(this->infoHeader), sizeof(BMPInfoHeader));

    if (this->infoHeader->bitsPerPixel != NUMBER_OF_BITS_PER_PIXEL) {
        char errMsg[40];
        sprintf(errMsg, "Only %d-bit BMP files are supported!", NUMBER_OF_BITS_PER_PIXEL);
        throw std::runtime_error(errMsg);
    }
}

void BMP::loadPixels()
{
    std::size_t pixelDataSize = this->infoHeader->width * this->infoHeader->height;
    this->pixels = new Pixel[pixelDataSize];
    this->file->read(reinterpret_cast<char*>(this->pixels), this->infoHeader->imageSize);
}

void BMP::loadFile()
{
    this->loadHeaders();
    this->loadPixels();
}

Pixel& BMP::operator()(int r, int c)
{
    return this->pixels[r * this->infoHeader->width + c];
}

Pixel BMP::operator()(int r, int c) const
{
    return this->pixels[r * this->infoHeader->width + c];
}

size_t BMP::getHeight()
{
    return this->infoHeader->height;
}

size_t BMP::getWidth()
{
    return this->infoHeader->width;
}

void BMP::save(const std::string& fileName)
{
    std::ofstream outputFile(fileName, std::ios::binary);
    if (!outputFile || outputFile.is_open()) {
        throw new std::runtime_error("Failed to open " + fileName + "!");
    }

    outputFile.write(reinterpret_cast<const char*>(this->header), sizeof(BMPHeader));
    outputFile.write(reinterpret_cast<const char*>(this->infoHeader), sizeof(BMPInfoHeader));
    outputFile.write(reinterpret_cast<const char*>(this->pixels), this->infoHeader->imageSize);
}