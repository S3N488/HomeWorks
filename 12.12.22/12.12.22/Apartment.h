#pragma once
#include <vector>
#include "Person.h"

class Apartment {
public:
    Apartment(int number) : number_(number) {}
    Apartment(const Apartment& other) : number_(other.number_), residents_(other.residents_) {}
    ~Apartment() {}

    int getNumber() const { return number_; }
    const std::vector<Person>& getResidents() const { return residents_; }
    void addResident(const Person& resident) { residents_.push_back(resident); }

private:
    int number_;
    std::vector<Person> residents_;
};


