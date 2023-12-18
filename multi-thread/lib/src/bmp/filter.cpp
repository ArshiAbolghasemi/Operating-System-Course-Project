#include "../../include/bmp/filter.hpp"

Filter::Filter() {}

Filter::~Filter() {}

void Filter::verticalFlip(BMP& bmp)
{
    for (int row = 0; row < bmp.getHeight() / 2; ++row) {
        for (int col = 0; col < bmp.getWidth(); ++col) {
            std::swap(bmp(row, col), bmp(bmp.getHeight() - row - 1, col));
        }
    }
}