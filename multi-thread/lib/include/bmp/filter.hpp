#ifndef _FILTER_HPP_
#define _FILTET_HPP_

#include "bmp.hpp"
#include <algorithm>
#include <vector>

class Filter
{
private:
    static void convolution(BMP& bmp, const std::vector<std::vector<double>>& kernel);
    static void drawLine(BMP& bmp, int x1, int y1, int x2, int y2, const Pixel& color);
public:
    Filter();
    ~Filter();

    static void verticalFlip(BMP& bmp);
    static void blur(BMP& bmp);
    static void purpleHaze(BMP& bmp);
    static void diagonalHatch(BMP& bmp, Pixel lineColor);
};


#endif