#include "House.h"

int main() {
    House house("123 Main St");

    Apartment apt1(101);
    apt1.addResident(Person("John Doe", 30));
    apt1.addResident(Person("Jane Smith", 25));

    Apartment apt2(102);
    apt2.addResident(Person("Bob Johnson", 50));

    house.addApartment(apt1);
    house.addApartment(apt2);

    for (const auto& apt : house.getApartments()) {
        std::cout << "Apartment " << apt.getNumber() << " residents:\n";
        for (const auto& resident : apt.getResidents()) {
            std::cout << "  " << resident << '\n';
        }
    }

    return 0;
}
