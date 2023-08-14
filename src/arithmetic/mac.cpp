#include "arithmetic/mac.h"

int mac(int x, int y, int& sum) {
    sum += x * y;
    return sum;
}