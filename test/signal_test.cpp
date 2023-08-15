#include "signal.h"

#include "gtest/gtest.h"

#define SIGNAL_SIZE 5

// Function to check if all values in a Signal are equal
template <typename T, size_t Size>
bool signals_equal(const Signal<T, Size>& signal_1,
                   const Signal<T, Size>& signal_2, T tolerance = T(0)) {
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
class SignalTest : public ::testing::Test {
   public:
    using SignalType = Signal<T, SIGNAL_SIZE>;  // Adjust the size as needed

    SignalTest() {
        // Set the default divide by zero mode before creating the test signals
        Signal<T, SIGNAL_SIZE>::default_divide_by_zero_mode =
            DivideByZeroMode::MAX;
    }

    SignalType signal_1{T(8.0)};
    SignalType signal_2{T(2.0)};
    SignalType zero_signal{T(0.0)};

    SignalType expected_add_result{T(10.0)};
    SignalType expected_subtract_result{T(6.0)};
    SignalType expected_multiply_result{T(16.0)};
    SignalType expected_divide_result{T(4.0)};
    SignalType expected_divide_by_zero_mode_max_result{
        std::numeric_limits<T>::max()};
    SignalType expected_divide_by_zero_mode_zero_result{T(0.0)};

    static void set_divide_by_zero_mode_max() {
        Signal<T, SIGNAL_SIZE>::default_divide_by_zero_mode =
            DivideByZeroMode::MAX;
    }

    static void set_divide_by_zero_mode_zero() {
        Signal<T, SIGNAL_SIZE>::default_divide_by_zero_mode =
            DivideByZeroMode::ZERO;
    }
};

using SignalTypes = ::testing::Types<double, float, int>;
TYPED_TEST_SUITE(SignalTest, SignalTypes);

TYPED_TEST(SignalTest, Addition) {
    typename TestFixture::SignalType result = this->signal_1 + this->signal_2;
    ASSERT_TRUE(signals_equal(result, this->expected_add_result));
}

TYPED_TEST(SignalTest, Subtraction) {
    typename TestFixture::SignalType result = this->signal_1 - this->signal_2;
    ASSERT_TRUE(signals_equal(result, this->expected_subtract_result));
}

TYPED_TEST(SignalTest, Multiply) {
    typename TestFixture::SignalType result = this->signal_1 * this->signal_2;
    ASSERT_TRUE(signals_equal(result, this->expected_multiply_result));
}

TYPED_TEST(SignalTest, Divide) {
    typename TestFixture::SignalType result = this->signal_1 / this->signal_2;
    ASSERT_TRUE(signals_equal(result, this->expected_divide_result));
}

TYPED_TEST(SignalTest, DivideByZeroModeMax) {
    using T = typename TestFixture::SignalType;
    using SignalType = typename TestFixture::SignalType;
    this->set_divide_by_zero_mode_max();
    SignalType signal_1{T(8.0)};
    SignalType zero_signal{T(0.0)};
    SignalType result = signal_1 / zero_signal;
    ASSERT_TRUE(
        signals_equal(result, this->expected_divide_by_zero_mode_max_result));
}

TYPED_TEST(SignalTest, DivideByZeroModeZero) {
    using T = typename TestFixture::SignalType;
    using SignalType = typename TestFixture::SignalType;
    this->set_divide_by_zero_mode_zero();
    SignalType signal_1{T(8.0)};
    SignalType zero_signal{T(0.0)};
    SignalType result = signal_1 / zero_signal;
    ASSERT_TRUE(
        signals_equal(result, this->expected_divide_by_zero_mode_zero_result));
}
