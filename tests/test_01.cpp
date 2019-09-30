#include <gtest/gtest.h>
#include <lab/complex.hpp>

#define TEST_SUIT_NAME BasicOperations

typedef Complex C;

TEST(TEST_SUIT_NAME, Addition) {
    ASSERT_TRUE((C{ 1, 2 } + C{ 2, 3 } == C{3, 5}));
    ASSERT_TRUE((C{ 0, 0 } + C{ 2, 3 } == C{2, 3}));
    ASSERT_TRUE((C{ 7, 2 } + C{ 2, 3 } == C{9, 5}));
    ASSERT_TRUE((C{ -5, 6 } + C{ 2, 3 } == C{-3, 9}));
    ASSERT_TRUE((C{ 9, 10 } + C{ 2, 3 } == C{11, 13}));
    ASSERT_TRUE((C{ 0, -20 } + C{ 2, 3 } == C{2, -17}));
}

TEST(TEST_SUIT_NAME, Subtitution) {
    ASSERT_TRUE(C(1, 2) - C(2, 3) == C(-1, -1));
}

TEST(TEST_SUIT_NAME, Multiplication) {
    auto c = C(1, 2) * C(2, 3);
    ASSERT_TRUE(C(1, 2) * C(2, 3) == C(-4, 7));
}

TEST(TEST_SUIT_NAME, Division) {
    ASSERT_TRUE(C(3, 13) / C(7, -17) == C(
        -0.5917159763313609467455621301775147928994082840236686390,
        0.4201183431952662721893491124260355029585798816568047337));
}

/*
-0.5917159763313609467455621301775147928994082840236686390... +
0.4201183431952662721893491124260355029585798816568047337... i
*/