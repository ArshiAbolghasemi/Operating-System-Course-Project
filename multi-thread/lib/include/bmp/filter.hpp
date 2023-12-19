#ifndef _FILTER_HPP_
#define _FILTET_HPP_

#include "bmp.hpp"
#include <algorithm>
#include <vector>

class Filter
{
private:
    static void convolution(BMP& bmp, const std::vector<std::vector<double>>& kernel);
public:
    Filter();
    ~Filter();

    static void verticalFlip(BMP& bmp);
    static void blur(BMP& bmp);
    static void purpleHaze(BMP& bmp);
};


#endif