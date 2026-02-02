#include <iostream>
using namespace std;

class Sensor {
private:
    int x;

public:
    Sensor(int value) : x(value) {}

    friend void calibrate(Sensor& s);
};

void calibrate(Sensor& s) {
    s.x += 10;
}

int main() {
    Sensor s(10);
    calibrate(s);
    return 0;
}
