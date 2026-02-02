
// Base class Vehicle

// Derived classes Car, Bike

// Factory function createVehicle(type)

// Client should NOT use new Car or new Bike

#include <iostream>
using namespace std;

enum class VehicleType {
    Bike,
    Car,
    Truck
};

class Vehicle {
public:
    virtual void start() = 0;
    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
public:
    void start() override {
        cout << "Car is started\n";
    }
};

class Bike : public Vehicle {
public:
    void start() override {
        cout << "Bike is started\n";
    }
};

class Truck : public Vehicle {
public:
    void start() override {
        cout << "Truck is started\n";
    }
};

Vehicle* createVehicle(VehicleType type) {
    if (type == VehicleType::Car)
        return new Car();
    else if (type == VehicleType::Bike)
        return new Bike();
    else if (type == VehicleType::Truck)
        return new Truck();

    return nullptr;
}

int main() {
    Vehicle* car   = createVehicle(VehicleType::Car);
    Vehicle* bike  = createVehicle(VehicleType::Bike);
    Vehicle* truck = createVehicle(VehicleType::Truck);

    car->start();
    bike->start();
    truck->start();

    delete car;
    delete bike;
    delete truck;
}
