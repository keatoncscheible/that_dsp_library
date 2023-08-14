#include <iostream>

#include "signal.h"

int main() {
    Signal<double, 5> signal1;
    Signal<double, 5> signal2(2.0);
    Signal<double, 5> result = signal1 * signal2;
    result.print();

    return 0;
}