#include "arithmetic/mac.hpp"

#include <matplot/matplot.h>

#include "gtest/gtest.h"

struct MacTests : public ::testing::Test {
    int* x;
    int* y;

    int get_x() { return *x; }
    int get_y() { return *y; }

    virtual void SetUp() override {
        printf("Setting up MAC tests\n");
        x = new int(42);
        y = new int(16);
        printf("Setting x to %d\n", *x);
        printf("Setting y to %d\n", *y);
    }
    virtual void TearDown() override {
        printf("Tearing down MAC tests\n");
        delete x;
        delete y;
    }
};

TEST_F(MacTests, mac) {
    int x = get_x();
    int y = get_y();
    int sum = 100;
    int old_sum = sum;
    int expected_new_sum = old_sum + x * y;
    EXPECT_EQ(expected_new_sum, mac(x, y, sum));
    EXPECT_EQ(expected_new_sum, sum);
}