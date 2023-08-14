#include <algorithm>  // For std::transform
#include <array>
#include <iostream>

enum class DivideByZeroMode {
    MAX,   // Set result to the maximum value the type
    ZERO,  // Set result to 0
};

template <typename T, size_t Size>
class Signal {
   public:
    // Zero fill and set divide by zero mode to MAX
    Signal() : samples_{}, divide_by_zero_mode_(DivideByZeroMode::MAX) {}

    // Fill with value and set divide by zero mode to MAX
    explicit Signal(const T& value)
        : divide_by_zero_mode_(DivideByZeroMode::MAX) {
        samples_.fill(value);
    }

    // Zero fill and set divide by zero mode accordingly
    explicit Signal(DivideByZeroMode mode)
        : samples_{}, divide_by_zero_mode_(mode) {}

    // Fill with value and set divide by zero mode accordingly
    Signal(const T& value, DivideByZeroMode mode) : divide_by_zero_mode_(mode) {
        samples_.fill(value);
    }

    // Non-const index operator for accessing elements of the Signal
    T& operator[](size_t index) { return samples_[index]; }

    // Const index operator for accessing elements of the Signal (read-only)
    const T& operator[](size_t index) const { return samples_[index]; }

    // Element-wise addition
    Signal<T, Size> operator+(const Signal<T, Size>& other) const {
        Signal<T, Size> result;
        std::transform(samples_.begin(), samples_.end(), other.samples_.begin(),
                       result.samples_.begin(), std::plus<T>());
        return result;
    }

    // Element-wise subtraction
    Signal<T, Size> operator-(const Signal<T, Size>& other) const {
        Signal<T, Size> result;
        std::transform(samples_.begin(), samples_.end(), other.samples_.begin(),
                       result.samples_.begin(), std::minus<T>());
        return result;
    }

    // Element-wise multiplication
    Signal<T, Size> operator*(const Signal<T, Size>& other) const {
        Signal<T, Size> result;
        std::transform(samples_.begin(), samples_.end(), other.samples_.begin(),
                       result.samples_.begin(), std::multiplies<T>());
        return result;
    }

    // Element-wise division
    Signal<T, Size> operator/(const Signal<T, Size>& other) const {
        Signal<T, Size> result;
        for (size_t i = 0; i < Size; ++i) {
            // Protect against divide by zero
            if (other[i] != T{}) {
                result[i] = samples_[i] / other[i];
            } else {
                result[i] = T{};
                switch (this->divide_by_zero_mode_) {
                    case DivideByZeroMode::MAX:
                        result[i] = std::numeric_limits<T>::max();
                        break;
                    case DivideByZeroMode::ZERO:
                        result[i] = T{};
                        break;
                }
            }
        }
        return result;
    }

    // Print the Signal's elements using std::transform
    void print() const {
        std::transform(samples_.begin(), samples_.end(),
                       std::ostream_iterator<T>(std::cout, " "),
                       [](const T& value) { return value; });
        std::cout << std::endl;
    }

   private:
    std::array<T, Size> samples_;
    DivideByZeroMode divide_by_zero_mode_;
};
