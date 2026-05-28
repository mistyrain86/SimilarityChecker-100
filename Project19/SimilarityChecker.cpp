#include <string>
#include <stdexcept>

class SimilarityChecker {
public:
    int Calculate(const std::string& a, const std::string& b) {
        Validate(a);
        Validate(b);
        return 0;
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
};
