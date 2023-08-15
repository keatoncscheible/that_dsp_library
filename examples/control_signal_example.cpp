
#include <iostream>

#include "control_signal.h"

int main() {
    // Define the size of the signal
    constexpr size_t SIGNAL_SIZE = 10;

    // Create a ControlSignal object with initial values of 0.0
    ControlSignal<double, SIGNAL_SIZE> controlSignal;

    // Print the initial values
    std::cout << "Initial values: ";
    controlSignal.print();

    // Set all values to 10.0
    controlSignal.set(10.0);
    std::cout << "After set(10.0): ";
    controlSignal.print();

    // Ramp from 10.0 to 20.0
    controlSignal.ramp(20.0);
    std::cout << "After ramp(20.0): ";
    controlSignal.print();

    // Ramp from 20.0 to 0.0
    controlSignal.ramp(0.0);
    std::cout << "After ramp(0.0): ";
    controlSignal.print();

    // Ramp from 0.0 to 100.0
    controlSignal.ramp(100.0);
    std::cout << "After ramp(100.0): ";
    controlSignal.print();

    return 0;
}
