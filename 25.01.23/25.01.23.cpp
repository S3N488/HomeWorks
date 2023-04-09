#include <iostream>
#include <string>

using namespace std;

class DomesticAnimal {
protected:
    string name;
    int age;
    bool isMale;
public:
    DomesticAnimal(string name, int age, bool isMale) {
        this->name = name;
        this->age = age;
        this->isMale = isMale;
    }
    virtual void sound() = 0;
};

class Dog : public DomesticAnimal {
public:
    Dog(string name, int age, bool isMale) : DomesticAnimal(name, age, isMale) {}
    void sound() override {
        cout << "Woof!" << endl;
    }
};

class Cat : public DomesticAnimal {
public:
    Cat(string name, int age, bool isMale) : DomesticAnimal(name, age, isMale) {}
    void sound() override {
        cout << "Meow!" << endl;
    }
};

class Parrot : public DomesticAnimal {
public:
    Parrot(string name, int age, bool isMale) : DomesticAnimal(name, age, isMale) {}
    void sound() override {
        cout << "Polly wants a cracker!" << endl;
    }
};

int main() {
    Dog dog("Rex", 5, true);
    Cat cat("Whiskers", 3, false);
    Parrot parrot("Polly", 2, false);

    dog.sound();
    cat.sound();
    parrot.sound();

    return 0;
}
