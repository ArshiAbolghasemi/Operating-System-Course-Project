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

void Filter::convolution(BMP& bmp, const std::vector<std::vector<double>>& kernel)
{
    size_t kernelSize = static_cast<int>(kernel.size());
    size_t kernelRadius = kernelSize / 2;
            
    for (int row = 0; row < bmp.getHeight(); ++row) {
        for (int col = 0; col < bmp.getWidth(); ++col) {
            double red = 0;
            double green = 0;
            double blue = 0;
            
            for (int k = 0; k < kernelSize; ++k) {
                for (int l = 0; l < kernelSize; ++l) {
                    int x = col + l - kernelRadius;
                    int y = row + k - kernelRadius;
                    
                    if (x < 0 || x >= bmp.getWidth() || y < 0 || y >= bmp.getHeight()) continue;
                    
                    red += bmp(y, x).red * kernel[k][l];
                    green += bmp(y, x).green * kernel[k][l];
                    blue += bmp(y, x).blue * kernel[k][l];
                }
            }

            bmp(row, col).red = std::min(255, std::max(0, (int) red));
            bmp(row, col).green = std::min(255, std::max(0, (int) green));
            bmp(row, col).blue = std::min(255, std::max(0, (int) blue));
        }
    }
}