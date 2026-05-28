#include <string>
#include <stdexcept>
#include <algorithm>

class SimilarityChecker {
public:
    int Calculate(const std::string& a, const std::string& b) {
        Validate(a);
        Validate(b);
        return CalcLengthScore(a, b);
    }

private:
    bool IsUpperCase(char c) {
        return c >= 'A' && c <= 'Z';
    }

    void Validate(const std::string& str) {
        for (char c : str)
            if (!IsUpperCase(c))
                throw std::invalid_argument(
                    std::string("Invalid character '") + c + "': only uppercase letters are allowed.");
    }

    int CalcLengthScore(const std::string& a, const std::string& b) {
        int longer  = static_cast<int>(std::max(a.size(), b.size()));
        int shorter = static_cast<int>(std::min(a.size(), b.size()));

        if (longer >= shorter * 2)
            return 0;

        double ratio = 1.0 - static_cast<double>(longer - shorter) / shorter;
        return static_cast<int>(ratio * 60);
    }
};
