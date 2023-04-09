#pragma once
class BasicHelicopterBuilder : public HelicopterBuilder {
public:
    BasicHelicopterBuilder() {
        helicopter = new Helicopter();
    }

    void setRotorCount() override {
        helicopter->setRotorCount(2);
    }

    void setMaxSpeed() override {
        helicopter->setMaxSpeed(250.0f);
    }

    void setFuelCapacity() override {
        helicopter->setFuelCapacity(500.0f);
    }

    void setPassengerCapacity() override {
        helicopter->setPassengerCapacity(4);
    }

    Helicopter* getHelicopter() override {
        return helicopter;
    }

private:
    Helicopter* helicopter;
};


