#include <string>
#include <stdexcept>
#include <algorithm>

class SimilarityChecker {
public:
    int Calculate(const std::string& a, const std::string& b) {
        Validate(a);
        Validate(b);
        return 0;
    }

private:
    void Validate(const std::string& str) {
        bool isValid = std::all_of(str.begin(), str.end(), [](char c) {
            return c >= 'A' && c <= 'Z';
        });
        if (!isValid)
            throw std::invalid_argument("Input must contain only uppercase letters.");
    }
};
