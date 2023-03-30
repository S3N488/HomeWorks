#pragma once
#include <vector>
#include "Apartment.h"

class House {
public:
    House() : address_(new std::string) {}
    House(const std::string& address) : address_(new std::string(address)) {}
    House(const House& other) : address_(new std::string(*other.address_)), apartments_(other.apartments_) {}
    ~House() { delete address_; }

    const std::string& getAddress() const { return *address_; }
    const std::vector<Apartment>& getApartments() const { return apartments_; }
    void addApartment(const Apartment& apartment) { apartments_.push_back(apartment); }

private:
    std::string* address_;
    std::vector<Apartment> apartments_;
};

