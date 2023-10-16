/**
 * @file test_main.cpp
 *
 * @brief This file contains the main test suite for the application.
 */

#include <gtest/gtest.h>

/**
 * @brief Test case for the main functionality of the application.
 *
 * This test case is part of the "MyTestSuite" test suite and checks a simple
 * condition using the EXPECT_EQ macro. It verifies that 1 is equal to 1, which
 * should always be true.
 */
TEST(MyTestSuite, MyTest) {
    EXPECT_EQ(1, 1); /**< Check if 1 is equal to 1. */
}
