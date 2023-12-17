#include "../include/filter.hpp"

Filter::Filter() {}

Filter::~Filter() {}

void Filter::flipHorizontal(BMP& bmp)
{
    for (int y = 0; y < bmp.getHeight(); ++y) {
        for (int x = 0; x < bmp.getWidth() / 2; ++x) {
            std::swap(bmp(y, x), bmp(y, bmp.getWidth() - 1 - x));
        }
    }
}