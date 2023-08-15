#include "control_signal.h"

#include "gtest/gtest.h"

#define SIGNAL_SIZE 5

// Function to check if all values in a ControlSignal are equal
template <typename T, size_t Size>
bool control_signals_equal(const ControlSignal<T, Size>& signal_1,
                           const ControlSignal<T, Size>& signal_2,
                           T tolerance = T(0)) {
    for (size_t i = 0; i < Size; ++i) {
        if constexpr (std::is_floating_point<T>::value) {
            if (std::abs(signal_1[i] - signal_2[i]) > tolerance) {
                return false;
            }
        } else {
            if (signal_1[i] != signal_2[i]) {
                return false;
            }
        }
    }
    return true;
}

template <typename T>
class ControlSignalTest : public ::testing::Test {
   public:
    using ControlSignalType =
        ControlSignal<T, SIGNAL_SIZE>;  // Adjust the size as needed

    ControlSignalTest() {
        set_value = 10.0;
        ramp_start = 0.0;
        ramp_end = 20.0;
        ramp_delta = (ramp_end - ramp_start) / static_cast<T>(SIGNAL_SIZE);

        // Initialize the expected set and ramp result
        for (size_t i = 0; i < SIGNAL_SIZE; ++i) {
            expected_set_result[i] = set_value;
            expected_ramp_result[i] =
                ramp_start + ramp_delta * static_cast<T>(i + 1);
        }
    }

    ControlSignalType control_signal;
    T set_value;
    T ramp_start;
    T ramp_end;
    T ramp_delta;

    ControlSignalType expected_set_result;
    ControlSignalType expected_ramp_result;
};

using ControlSignalTypes = ::testing::Types<double, float, int>;
TYPED_TEST_SUITE(ControlSignalTest, ControlSignalTypes);

TYPED_TEST(ControlSignalTest, Set) {
    this->control_signal.set(this->set_value);
    ASSERT_TRUE(
        control_signals_equal(this->control_signal, this->expected_set_result));
}

TYPED_TEST(ControlSignalTest, Ramp) {
    this->control_signal.ramp(this->ramp_end);
    ASSERT_TRUE(control_signals_equal(this->control_signal,
                                      this->expected_ramp_result));
}
