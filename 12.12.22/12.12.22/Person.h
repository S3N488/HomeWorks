#pragma once
#include <string>
#include <iostream>

class Person {
public:
    Person() : name_(new std::string), age_(0) {}
    Person(const std::string& name, int age) : name_(new std::string(name)), age_(age) {}
    Person(const Person& other) : name_(new std::string(*other.name_)), age_(other.age_) {}
    ~Person() { delete name_; }

    const std::string& getName() const { return *name_; }
    int getAge() const { return age_; }
    void setName(const std::string& name) { *name_ = name; }
    void setAge(int age) { age_ = age; }

    friend std::ostream& operator<<(std::ostream& os, const Person& person);

private:
    std::string* name_;
    int age_;
};

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << person.getName() << ", " << person.getAge();
    return os;
}


