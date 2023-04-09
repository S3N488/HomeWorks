#include <iostream>
#include <vector>
#include <algorithm>

class MinFinder {
public:
    int operator()(const std::vector<int>& v) const {
        if (v.empty()) {
            throw std::logic_error("Vector is empty");
        }
        return *std::min_element(v.begin(), v.end());
    }
};

int main() {
    std::vector<int> v = { 10, 5, 2, 8, 3, 7 };
    MinFinder finder;
    std::cout << "Minimum value: " << finder(v) << std::endl;
    return 0;
}
