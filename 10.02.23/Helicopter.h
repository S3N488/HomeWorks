#pragma once
class Helicopter {
public:
    void setRotorCount(int count) {
        rotorCount = count;
    }

    void setMaxSpeed(float speed) {
        maxSpeed = speed;
    }

    void setFuelCapacity(float fuel) {
        fuelCapacity = fuel;
    }

    void setPassengerCapacity(int passengers) {
        passengerCapacity = passengers;
    }

    void info() {
        std::cout << "Helicopter with " << rotorCount << " rotors, max speed " << maxSpeed << ", fuel capacity " << fuelCapacity << ", and passenger capacity " << passengerCapacity << std::endl;
    }

private:
    int rotorCount;
    float maxSpeed;
    float fuelCapacity;
    int passengerCapacity;
};


