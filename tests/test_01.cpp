#include <gtest/gtest.h>
#include <lab/complex.hpp>

#define TEST_SUIT_NAME BasicOperations

typedef Complex C;

TEST(TEST_SUIT_NAME, Addition) {
    ASSERT_TRUE((1 + 2_i) + (2 + 3_i) == (3 + 5_i));
    ASSERT_TRUE((0 + 0_i) + (2 + 3_i) == (2 + 3_i));
    ASSERT_TRUE((7 + 2_i) + (2 + 3_i) == (9 + 5_i));
    ASSERT_TRUE((-5 + 6_i) + (2 + 3_i) == (-3 + 9_i));
    ASSERT_TRUE((9 + 10_i) + (2 + 3_i) == (11 + 13_i));
    ASSERT_TRUE((0 + -20_i) + (2 + 3_i) == (2 + -17_i));
}

TEST(TEST_SUIT_NAME, Subtitution) {
    ASSERT_TRUE((1 + 2_i) - (2 + 3_i) == -1 + -1_i);
}

TEST(TEST_SUIT_NAME, Multiplication) {
    ASSERT_TRUE((1 + 2_i) * (2 + 3_i) == (-4 + 7_i));
}

TEST(TEST_SUIT_NAME, Division) {
    ASSERT_TRUE((3 + 13_i) / (7 + -17_i) == (
        -0.5917159763313609467455621301775147928994082840236686390 +
        0.4201183431952662721893491124260355029585798816568047337_i));
}

