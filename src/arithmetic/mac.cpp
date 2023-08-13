#include "arithmetic/mac.hpp"

int mac(int x, int y, int& sum) {
    sum += x * y;
    return sum;
}