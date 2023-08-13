
#include "arithmetic/square.hpp"

#include "gtest/gtest.h"

struct SquareTests : public ::testing::Test {
    int* x;

    int get_x() { return *x; }

    virtual void SetUp() override {
        printf("Setting up Square tests\n");
        x = new int(42);
        printf("Setting x to %d\n", *x);
    }
    virtual void TearDown() override {
        printf("Tearing down Square tests\n");
        delete x;
    }
};

TEST_F(SquareTests, square) {
    int x = get_x();
    int expected_square = x * x;
    EXPECT_EQ(expected_square, square(x));
}