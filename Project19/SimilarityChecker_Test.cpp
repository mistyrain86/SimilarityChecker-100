#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

class SimilarityCheckerTest : public ::testing::Test {
protected:
    SimilarityChecker checker;
};

TEST_F(SimilarityCheckerTest, ThrowWhenInputIsNotUpperCase) {
    EXPECT_THROW(checker.Calculate("abc", "ABC"), std::invalid_argument);  // 소문자
    EXPECT_THROW(checker.Calculate("A1B", "AB"),  std::invalid_argument);  // 숫자
    EXPECT_THROW(checker.Calculate("A B", "AB"),  std::invalid_argument);  // 공백
    EXPECT_THROW(checker.Calculate("A!B", "AB"),  std::invalid_argument);  // 특수문자
}
