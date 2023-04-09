#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main() {
    std::string current_path = fs::current_path().string();
    std::cout << "Current directory: " << current_path << std::endl;
    std::string input;
    while (true) {
        std::cout << "Enter command: ";
        std::getline(std::cin, input);
        if (input == "..") {
            current_path = fs::path(current_path).parent_path().string();
        }
        else {
            fs::path path(input);
            if (fs::is_directory(path)) {
                current_path = path.string();
            }
            else if (fs::is_regular_file(path)) {
                std::ifstream file(path);
                std::string line;
                while (std::getline(file, line)) {
                    std::cout << line << std::endl;
                }
            }
            else {
                std::cout << "Invalid input." << std::endl;
            }
        }
        std::cout << "Current directory: " << current_path << std::endl;
    }
    return 0;
}
