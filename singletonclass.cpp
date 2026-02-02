#include <iostream>
using namespace std;

class Singleton {
private:
    // Private constructor
    Singleton() {
        cout << "Singleton Constructor Called\n";
    }

    // Delete copy constructor & assignment
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    static Singleton& getInstance() {
        static Singleton instance;  // Created once, thread-safe in C++11+
        return instance;
    }

    void show() {
        cout << "Hello from Singleton\n";
    }
};

int main() {
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    s1.show();

    cout << &s1 << endl;
    cout << &s2 << endl;  // Same address

    return 0;
}

///A Singleton ensures only one instance of a class exists and provides a global access point. 
///In modern C++, it’s best implemented using a static local variable inside a getInstance() method, 
///which is lazy and thread-safe since C++11.


#include <cstdint>
#include <iostream>

class Dcm {
private:
    // Private constructor → no external creation
    Dcm() {
        std::cout << "DCM initialized\n";
    }

    // Delete copy & assignment → no duplication
    Dcm(const Dcm&) = delete;
    Dcm& operator=(const Dcm&) = delete;

public:
    // Global access point
    static Dcm& getInstance() {
        static Dcm instance;   // static storage, no heap
        return instance;
    }

    // Example UDS service handler: 0x10 (Diagnostic Session Control)
    void handleSessionControl(uint8_t subFunction) {
        switch (subFunction) {
        case 0x01:
            std::cout << "Default Session\n";
            break;
        case 0x02:
            std::cout << "Programming Session\n";
            break;
        case 0x03:
            std::cout << "Extended Diagnostic Session\n";
            break;
        default:
            std::cout << "Negative Response: 0x12 (SubFunction Not Supported)\n";
            break;
        }
    }

    // Example UDS service handler: 0x22 (ReadDataByIdentifier)
    void handleRDBI(uint16_t did) {
        switch (did) {
        case 0xF190:
            std::cout << "VIN = ABCD123456789\n";
            break;
        case 0xF187:
            std::cout << "SW Version = v2.1.0\n";
            break;
        default:
            std::cout << "Negative Response: 0x31 (Request Out Of Range)\n";
            break;
        }
    }
};

int main() {
    Dcm& dcm1 = Dcm::getInstance();
    Dcm& dcm2 = Dcm::getInstance();

    std::cout << &dcm1 << std::endl;
    std::cout << &dcm2 << std::endl;  // same address

    dcm1.handleSessionControl(0x03);   // Extended session
    dcm2.handleRDBI(0xF190);            // VIN

    return 0;
}
