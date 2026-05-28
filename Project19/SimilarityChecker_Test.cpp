#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

class SimilarityCheckerTest : public ::testing::Test {
protected:
    SimilarityChecker checker;
};

TEST_F(SimilarityCheckerTest, ThrowWhenInputIsNotUpperCase) {
    EXPECT_THROW(checker.Calculate("abc", "ABC"), std::invalid_argument);
    EXPECT_THROW(checker.Calculate("A1B", "AB"),  std::invalid_argument);
    EXPECT_THROW(checker.Calculate("A B", "AB"),  std::invalid_argument);
    EXPECT_THROW(checker.Calculate("A!B", "AB"),  std::invalid_argument);
}

TEST_F(SimilarityCheckerTest, ReturnSixtyWhenLengthIsSame) {
    EXPECT_EQ(checker.Calculate("ASD", "DSA"), 60);
    EXPECT_EQ(checker.Calculate("A",   "A"),   60);
}

TEST_F(SimilarityCheckerTest, ReturnZeroWhenLengthIsDoubleOrMore) {
    EXPECT_EQ(checker.Calculate("A",   "BB"),     0);
    EXPECT_EQ(checker.Calculate("ABC", "ABCABC"), 0);
}

TEST_F(SimilarityCheckerTest, ReturnPartialScoreWhenLengthDiffIsLessThanDouble) {
    EXPECT_EQ(checker.Calculate("AB",    "ABC"), 30);
    EXPECT_EQ(checker.Calculate("AAABB", "BAA"), 20);
    EXPECT_EQ(checker.Calculate("AA",    "AAE"), 30);
}
