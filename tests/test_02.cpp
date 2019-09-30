#include <gtest/gtest.h>
#include <lab/complex.hpp>

#define TEST_SUIT_NAME Comparation

typedef Complex C;

TEST(TEST_SUIT_NAME, Equasion) {
    ASSERT_FALSE(3 + 13_i == 7 + -17_i);
    ASSERT_TRUE(0 + 1_i == 0 + 1_i);
}

TEST(TEST_SUIT_NAME, Compare) {
    ASSERT_EQ(Compare(3 + 13_i, 7 + -17_i), -1);
    ASSERT_EQ(Compare(0 + 1_i, 0 + 1_i),    0);
    ASSERT_EQ(Compare(0 + 2_i, 1 + 1_i),    1);
}