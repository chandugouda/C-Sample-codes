#include <iostream>
#include<memory>
using namespace std;

enum class Vehicletype{
    Bike,
    Car,
    Truk
};

class Vehicle{
    public:
    virtual void show()=0;
    virtual ~Vehicle() = default;
};
class Car : public Vehicle{
    public:
    void show() override {
        cout<<"Car is started "<<endl;
    }
};
class Bike : public Vehicle{
    public:
    void show() override {
        cout<<"Bike is started "<<endl;
    }
};
class Truk : public Vehicle{
    public:
    void show() override {
        cout<<"Truk is started "<<endl;
    }
};
class FactoryVehicle{
    public:
    Vehicle * vehicletype(Vehicletype type){
        if(type==Vehicletype::Car){
            return new Car();
        }
        else if(type == Vehicletype :: Bike){
            return new Bike();
        }
        else{
            return new Truk();
        }
        return nullptr;
}
};
int main() {
    FactoryVehicle factory;
    Vehicle* car = factory.vehicletype(Vehicletype::Car);
    Vehicle* bike = factory.vehicletype(Vehicletype :: Bike);
    Vehicle* truk = factory.vehicletype(Vehicletype :: Truk);

    car->show();
    bike->show();
    truk ->show();

    // delete car;
    // delete bike;
    // delete truk;

    return 0;
}
    
