#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

class SimilarityCheckerTest : public ::testing::Test {
protected:
    SimilarityChecker checker;
};

// 입력 예외처리: 대문자 이외의 문자열이 들어올 경우 throw
TEST_F(SimilarityCheckerTest, ThrowWhenInputHasLowerCase) {
    EXPECT_THROW(checker.Calculate("abc", "ABC"), std::invalid_argument);
}

TEST_F(SimilarityCheckerTest, ThrowWhenInputHasNumber) {
    EXPECT_THROW(checker.Calculate("A1B", "AB"), std::invalid_argument);
}

TEST_F(SimilarityCheckerTest, ThrowWhenInputHasSpace) {
    EXPECT_THROW(checker.Calculate("A B", "AB"), std::invalid_argument);
}

TEST_F(SimilarityCheckerTest, ThrowWhenInputHasSpecialChar) {
    EXPECT_THROW(checker.Calculate("A!B", "AB"), std::invalid_argument);
}
