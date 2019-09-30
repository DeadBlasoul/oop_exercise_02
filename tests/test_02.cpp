#include <gtest/gtest.h>
#include <lab/complex.hpp>

#define TEST_SUIT_NAME Comparation

typedef Complex C;

TEST(TEST_SUIT_NAME, Equasion) {
    ASSERT_FALSE(C(3, 13) == C(7, -17));
    ASSERT_TRUE(C(0, 1) == C(0, 1));
}

TEST(TEST_SUIT_NAME, Compare) {
    ASSERT_EQ(Compare(C(3, 13), C(7, -17)), -1);
    ASSERT_EQ(Compare(C(0, 1), C(0, 1)),    0);
    ASSERT_EQ(Compare(C(0, 2), C(1, 1)),    1);
}