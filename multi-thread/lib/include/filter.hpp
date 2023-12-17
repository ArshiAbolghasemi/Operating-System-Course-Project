#ifndef _FILTER_HPP_
#define _FILTET_HPP_

#include "bmp.hpp"

class Filter
{
private:
public:
    Filter();
    ~Filter();

    static void flipHorizontal(BMP& bmp);
};


#endif