#include <iostream>

#include "signal.h"

#define SIGNAL_SIZE 5

int main() {
    // Create two Signal objects with initial values
    Signal<double, SIGNAL_SIZE> signal_1(1.0);
    Signal<double, SIGNAL_SIZE> signal_2(2.0);

    // Print the initial values of the signals
    std::cout << "Initial values of signal_1: ";
    signal_1.print();
    std::cout << "Initial values of signal_2: ";
    signal_2.print();

    // Set the value of the signals using indexing
    for (size_t i = 0; i < SIGNAL_SIZE; ++i) {
        signal_1[i] = (double)(i + 1);
        signal_2[i] = (double)(i + 11);
    }
    std::cout << "Setting signal_1 and signal_2 using indexing" << std::endl;
    std::cout << "signal_1: ";
    signal_1.print();
    std::cout << "signal_2: ";
    signal_2.print();

    // Perform element-wise multiplication of the signals and print the result
    Signal<double, 5> result_multiply = signal_1 * signal_2;
    std::cout << "Result of signal_1 * signal_2: ";
    result_multiply.print();

    // Perform element-wise addition of the signals and print the result
    Signal<double, 5> result_add = signal_1 + signal_2;
    std::cout << "Result of signal_1 + signal_2: ";
    result_add.print();

    // Perform element-wise subtraction of the signals and print the result
    Signal<double, 5> result_subtract = signal_1 - signal_2;
    std::cout << "Result of signal_1 - signal_2: ";
    result_subtract.print();

    // Perform element-wise division of the signals and print the result
    Signal<double, 5> result_divide = signal_1 / signal_2;
    std::cout << "Result of signal_1 / signal_2: ";
    result_divide.print();

    return 0;
}
