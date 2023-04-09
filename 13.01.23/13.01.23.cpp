#include <iostream>
#include <stack>
#include <cstring>

bool checkBrackets(const char* str) {
    std::stack<char> s;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            s.push(str[i]);
        }
        else if (str[i] == ')') {
            if (s.empty() || s.top() != '(') {
                return false;
            }
            s.pop();
        }
        else if (str[i] == '}') {
            if (s.empty() || s.top() != '{') {
                return false;
            }
            s.pop();
        }
        else if (str[i] == ']') {
            if (s.empty() || s.top() != '[') {
                return false;
            }
            s.pop();
        }
    }

    return s.empty();
}

int main() {
    const char* str1 = "({x-y-z}*[x+2y]-(z+4x));";
    const char* str2 = "([x-y-z}*[x+2y)-{z+4x)];";

    if (checkBrackets(str1)) {
        std::cout << "String is correct" << std::endl;
    }
    else {
        std::cout << "String is incorrect" << std::endl;
    }

    if (checkBrackets(str2)) {
        std::cout << "String is correct" << std::endl;
    }
    else {
        std::cout << "String is incorrect" << std::endl;
    }

    return 0;
}
