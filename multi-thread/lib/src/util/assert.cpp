#include "../../include/util/assert.hpp"

Assert::Assert() {}

Assert::~Assert() {}

void Assert::isPowerOfTwo(int num)
{
    if ((num < 0) || ((num & (num - 1))) != 0) {
        throw new std::exception();
    }
}