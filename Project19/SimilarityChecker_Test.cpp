#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

using StringPair = std::pair<std::string, std::string>;

class InvalidInputTest : public ::testing::TestWithParam<StringPair> {
protected:
    SimilarityChecker checker;
};

TEST_P(InvalidInputTest, ThrowWhenInputIsNotUpperCase) {
    auto [a, b] = GetParam();
    EXPECT_THROW(checker.Calculate(a, b), std::invalid_argument);
}

INSTANTIATE_TEST_SUITE_P(
    NonUpperCaseInputs,
    InvalidInputTest,
    ::testing::Values(
        StringPair{ "abc", "ABC" },
        StringPair{ "A1B", "AB"  },
        StringPair{ "A B", "AB"  },
        StringPair{ "A!B", "AB"  }
    ),
    [](const ::testing::TestParamInfo<StringPair>&info) -> std::string {
        switch (info.index) {
            case 0: return "LowerCase";
            case 1: return "Number";
            case 2: return "Space";
            case 3: return "SpecialChar";
            default: return "Unknown";
        }
    }
);
