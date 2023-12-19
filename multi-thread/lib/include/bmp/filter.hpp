#ifndef _FILTER_HPP_
#define _FILTET_HPP_

#include "bmp.hpp"
#include <algorithm>

class Filter
{
private:
public:
    Filter();
    ~Filter();

    static void verticalFlip(BMP& bmp);

    static void convolution(BMP& bmp, const std::vector<std::vector<double>>& kernel);
};


#endif