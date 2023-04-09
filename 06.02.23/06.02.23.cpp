#include <string>
#include <stdexcept>
#include <iostream>

int stringToInt(const std::string& str) {
    try {
        size_t pos;
        int result = std::stoi(str, &pos);
        if (pos < str.length()) {
            throw std::invalid_argument("String contains non-numeric characters");
        }
        return result;
    }
    catch (const std::out_of_range& ex) {
        throw std::out_of_range("String represents a number out of range for int");
    }
    catch (const std::invalid_argument& ex) {
        throw std::invalid_argument("String is not a valid number");
    }
}



int main() {
    std::string str = "1234567890";
    try {
        int num = stringToInt(str);
        std::cout << "Number: " << num << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
    return 0;
}
