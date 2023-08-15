#ifndef CONTROLSIGNAL_H
#define CONTROLSIGNAL_H

#include "signal.h"

template <typename T, size_t Size>
class ControlSignal : public Signal<T, Size> {
   public:
    using Signal<T, Size>::Signal;

    void set(const T& value) {
        for (size_t i = 0; i < Size; ++i) {
            this->operator[](i) = value;
        }
    }

    void ramp(const T& end) {
        T start_value = this->operator[](Size - 1);
        T delta = end - start_value;
        T step = delta / static_cast<T>(Size);

        for (size_t i = 0; i < Size; ++i) {
            this->operator[](i) = start_value + step * static_cast<T>(i + 1);
        }
    }
};

#endif  // CONTROLSIGNAL_H
