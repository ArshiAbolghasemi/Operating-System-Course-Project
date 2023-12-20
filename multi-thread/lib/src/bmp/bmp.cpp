#include <fstream>
#include <iostream>
#include "../../include/bmp/bmp.hpp"

BMP::BMP(const std::string& fileName)
{
    std::ifstream file(fileName, std::ios::binary);
    if (!file || !file.is_open()) {
        throw new std::runtime_error("Failed to open " + fileName + "!");
    }

    this->loadFile(file);
    file.close();
}

BMP::~BMP() 
{
    delete[] this->pixels;
}

BMP::BMP(const BMP& bmp)
{
    this->fileHeader = bmp.fileHeader;
    this->infoHeader = bmp.infoHeader;
    this->pixels = new Pixel[this->infoHeader.width * this->infoHeader.height];
    std::copy(bmp.pixels, bmp.pixels + this->infoHeader.width * this->infoHeader.height, 
        this->pixels);
}

BMP& BMP::operator=(const BMP& bmp)
{
    if (this == &bmp) return *this;
    
    delete[] this->pixels;

    this->fileHeader = bmp.fileHeader;
    this->infoHeader = bmp.infoHeader;
    this->pixels = new Pixel[this->infoHeader.width * this->infoHeader.height];
    std::copy(bmp.pixels, bmp.pixels + this->infoHeader.width * this->infoHeader.height, 
        this->pixels);
        
    return *this;
}

Pixel& BMP::operator()(int row, int col)
{
    return this->pixels[row * this->getWidth() + col];
}

Pixel BMP::operator()(int row, int col) const
{
    return this->pixels[row * this->infoHeader.width + col];
}

size_t BMP::getHeight() { return this->infoHeader.height; }

size_t BMP::getWidth() { return this->infoHeader.width; }

void BMP::loadHeaders(std::ifstream& file)
{
    file.read(reinterpret_cast<char*>(&this->fileHeader), sizeof(BMPFileHeader));
    if (this->fileHeader.signature != BMP_SIGNATURE) {
        throw new std::runtime_error("Invalid BMP file");
    }

    file.read(reinterpret_cast<char*>(&this->infoHeader), sizeof(BMPInfoHeader));

    if (this->infoHeader.bitsPerPixel != NUMBER_OF_BITS_PER_PIXEL) {
        char errMsg[40];
        sprintf(errMsg, "Only %d-bit BMP files are supported!", NUMBER_OF_BITS_PER_PIXEL);
        throw new std::runtime_error(errMsg);
    }
}

void BMP::loadPixels(std::ifstream& file)
{
    std::size_t pixelDataSize = this->infoHeader.width * this->infoHeader.height;
    this->pixels = new Pixel[pixelDataSize];
    file.seekg(this->fileHeader.dataOffset);
    int padding = static_cast<int>(4 - (this->infoHeader.width * sizeof(Pixel)) % 4) % 4;
    for (int y = this->infoHeader.height - 1; y >= 0; --y) {
        file.read(
            reinterpret_cast<char*>(this->pixels + y * this->infoHeader.width),
            static_cast<std::streamsize >(this->infoHeader.width * sizeof(Pixel)));
        file.seekg(padding, std::ios::cur);
    }
}

void BMP::loadFile(std::ifstream& file)
{
    this->loadHeaders(file);
    this->loadPixels(file);
}

void BMP::save(const std::string& fileName)
{
    std::ofstream outputFile(fileName, std::ios::binary);
    if (!outputFile || !outputFile.is_open()) {
        throw new std::runtime_error("Failed to open " + fileName + "!");
    }

    outputFile.write(reinterpret_cast<char*>(&this->fileHeader), sizeof(BMPFileHeader));
    outputFile.write(reinterpret_cast<char*>(&this->infoHeader), sizeof(BMPInfoHeader));
    char paddingBuffer[4] = { 0 };
    int padding = static_cast<int>(4 - (this->infoHeader.width * sizeof(Pixel)) % 4) % 4;
    for (int y = this->infoHeader.height - 1; y >= 0; --y) {
        outputFile.write(
            reinterpret_cast<char*>(this->pixels + y * this->infoHeader.height), 
            static_cast<std::streamsize>(this->infoHeader.width * sizeof(Pixel)));
        outputFile.write(paddingBuffer, padding);
    }
}