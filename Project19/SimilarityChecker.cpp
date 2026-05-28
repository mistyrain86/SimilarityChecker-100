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
        auto it = std::find_if(str.begin(), str.end(), [](char c) {
            return !(c >= 'A' && c <= 'Z');
        });
        if (it != str.end())
            throw std::invalid_argument(std::string("Invalid character '") + *it + "': only uppercase letters are allowed.");
    }
};
