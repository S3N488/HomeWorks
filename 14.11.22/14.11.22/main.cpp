#include <iostream>

int main() {
#ifdef WIN
    std::cout << "hi Windows" << std::endl;
#else
    std::cout << "hi Unix" << std::endl;
#endif
    return 0;
}
