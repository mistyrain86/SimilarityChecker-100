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
    void Validate(const std::string& str) {
        for (char c : str) {
            if (c < 'A' || c > 'Z')
                throw std::invalid_argument("Input must contain only uppercase letters.");
        }
    }
};
