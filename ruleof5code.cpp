#include <iostream>
using namespace std;

class Buffer {
    int* data;

public:
    // 1️⃣ Constructor
    Buffer(int value =0) {
        data = new int(value);
    }

    // 2️⃣ Destructor
    ~Buffer() {
        delete data;
    }

    // 3️⃣ Copy Constructor (Deep Copy)
    Buffer(const Buffer& other) {
        data = new int(*other.data);
    }

    // 4️⃣ Copy Assignment Operator (Deep Copy)
    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }

    // 5️⃣ Move Constructor
    Buffer(Buffer&& other) noexcept {
        data = other.data;       // steal the resource
        other.data = nullptr;    // leave source in safe state
    }

    // 6️⃣ Move Assignment Operator
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete data;         // release current resource
            data = other.data;  // steal resource
            other.data = nullptr;
        }
        return *this;
    }

    // Helper to see value
    int get() const {
        return data ? *data : -1;
    }
};

int main() {

    cout << "---- Constructor ----\n";
    Buffer b1(10);          // Constructor

    cout << "b1 = " << b1.get() << endl;

    cout << "\n---- Copy Constructor ----\n";
    Buffer b2 = b1;         // Copy constructor

    cout << "b2 = " << b2.get() << endl;

    cout << "\n---- Move Constructor ----\n";
    Buffer b3 = move(b1);  // Move constructor

    cout << "b3 = " << b3.get() << endl;
    cout << "b1 = " << b1.get() << " (after move)\n";

    cout << "\n---- Copy Assignment ----\n";
    Buffer b4;
    b4 = b2;                // Copy assignment

    cout << "b4 = " << b4.get() << endl;

    cout << "\n---- Move Assignment ----\n";
    Buffer b5;
    b5 = move(b3);     // Move assignment

    cout << "b5 = " << b5.get() << endl;
    cout << "b3 = " << b3.get() << " (after move)\n";

    cout << "\n---- End of main ----\n";
    return 0;
}


