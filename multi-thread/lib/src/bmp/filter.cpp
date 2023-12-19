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

void Filter::blur(BMP& bmp)
{
    std::vector<std::vector<double>> kernel = {
        {1.0 / 16, 2.0 / 16, 1.0 / 16},
        {2.0 / 16, 4.0 / 16, 2.0 / 16},
        {1.0 / 16, 2.0 / 16, 1.0 / 16}
    };
    Filter::convolution(bmp, kernel);
}

void Filter::purpleHaze(BMP& bmp)
{
    for (int row = 0; row < bmp.getHeight(); ++row) {
        for (int col = 0; col < bmp.getWidth(); ++col) {
            auto red = bmp(row, col).red;
            auto green = bmp(row, col).green;
            auto blue = bmp(row, col).blue;
            bmp(row, col).red = std::min(255, (int) (red * 0.5 + green * 0.3 + blue * 0.5));
            bmp(row, col).green = std::min(255, (int) (red * 0.16 + green * 0.5 + blue * 0.16));
            bmp(row, col).blue = std::min(255, (int) (red * 0.6 + green * 0.2 + blue * 0.8));
        }   
    }
}

void Filter::convolution(BMP& bmp, const std::vector<std::vector<double>>& kernel)
{
    BMP result = bmp;

    size_t kernelSize = static_cast<int>(kernel.size());
    size_t kernelRadius = kernelSize / 2;
            
    for (int row = 0; row < bmp.getHeight(); ++row) {
        for (int col = 0; col < bmp.getWidth(); ++col) {
            double red = 0.0;
            double green = 0.0;
            double blue = 0.0;

            for (int k = 0; k < kernel.size(); ++k) {
                for (int l = 0; l < kernel.size(); ++l) {
                    int x = col + l - kernel[k].size() / 2;
                    int y = row + k - kernel[k].size() / 2;
                    
                    if (x < 0 || x >= bmp.getWidth() || y < 0 || y >= bmp.getHeight()) continue;
                    
                    red += bmp(y, x).red * (kernel[k][l]);
                    green += bmp(y, x).green * (kernel[k][l]);
                    blue += bmp(y, x).blue * (kernel[k][l]);
                }
            }

            result(row, col).red = std::min(255, std::max(0, (int) red));
            result(row, col).green = std::min(255, std::max(0, (int) green));
            result(row, col).blue = std::min(255, std::max(0, (int) blue));
        }

        bmp = result;
    }
}