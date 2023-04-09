#pragma once
class HelicopterDirector {
public:
    HelicopterDirector(HelicopterBuilder* builder) {
        this->builder = builder;
    }

    Helicopter* createHelicopter() {
        builder->setRotorCount();
        builder->setMaxSpeed();
        builder->setFuelCapacity();
        builder->setPassengerCapacity();
        return builder->getHelicopter();
    }

private:
    HelicopterBuilder* builder;
};


