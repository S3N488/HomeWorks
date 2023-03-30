#include <iostream>
#include <cstring>

using namespace std;

class String {
public:
    static int getCount();

    String();
    String(int length);
    String(const char* str);

    ~String();

    void input();
    void output();

private:
    char* data_;
    int length_;

    static int count_;
};

int String::count_ = 0;

String::String() : String(80) {}

String::String(int length) : length_(length) {
    data_ = new char[length_];
    count_++;
}

String::String(const char* str) {
    length_ = strlen(str);
    data_ = new char[length_];
    strcpy(data_, str);
    count_++;
}

String::~String() {
    delete[] data_;
    count_--;
}

void String::input() {
    cout << "Enter string: ";
    cin >> data_;
}

void String::output() {
    cout << data_ << endl;
}

int String::getCount() {
    return count_;
}

int main() {
    String s1;
    String s2(50);
    String s3("Hello");

    cout << "Number of strings created: " << String::getCount() << endl;

    s1.input();
    s2.input();
    s3.input();

    s1.output();
    s2.output();
    s3.output();

    cout << "Number of strings created: " << String::getCount() << endl;

    return 0;
}
