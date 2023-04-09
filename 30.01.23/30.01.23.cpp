#include <iostream>
#include <queue>
#include <string>

class Animal {
public:
    virtual void cry() = 0;
};

class Dog : public Animal {
public:
    void cry() {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void cry() {
        std::cout << "Meow!" << std::endl;
    }
};

class Parrot : public Animal {
public:
    void cry() {
        std::cout << "Polly wants a cracker!" << std::endl;
    }
};

int main() {
    std::queue<Animal*> animalQueue;
    animalQueue.push(new Dog());
    animalQueue.push(new Cat());
    animalQueue.push(new Parrot());

    while (!animalQueue.empty()) {
        Animal* animal = animalQueue.front();
        animalQueue.pop();
        animal->cry();
        delete animal;
    }

    return 0;
}
