#include <iostream>

using namespace std;

char str1[100]{ "Hello" };
void task1();
void task2();


void main() {
    task1();
    task2();
}

void task1() {
    char* Uppercase(char* str1);
    int len = strlen(str1);
    for (int i = 0; i < len; i++) {
        str1[i] = toupper(str1[i]);
    }
    cout << str1 << endl;
}

void task2() {
    char* Lowercase(char* str1);
    int len = strlen(str1);
    for (int i = 0; i < len; i++) {
        str1[i] = tolower(str1[i]);
    }
    cout << str1 << endl;
}