#include <iostream>
using namespace std;

template <typename T>
class UniquePtr {
private:
    T* ptr;   // raw pointer owning the resource

public:
    // 1. Constructor
    explicit UniquePtr(T* p = nullptr) : ptr(p) {}

    // 2. Destructor (RAII)
    ~UniquePtr() {
        delete ptr;
    }

    // 3. Disable copy (enforce unique ownership)
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    // 4. Move constructor (transfer ownership)
    UniquePtr(UniquePtr&& other) noexcept {
        ptr = other.ptr;
        other.ptr = nullptr;
    }

    // 5. Move assignment
    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this != &other) {
            delete ptr;          // delete current resource
            ptr = other.ptr;     // take ownership
            other.ptr = nullptr;
        }
        return *this;
    }

    // 6. Dereference operator
    T& operator*() const {
        return *ptr;
    }

    // 7. Get raw pointer (no ownership change)
    T* get() const {
        return ptr;
    }
};

int main() {
    UniquePtr<int> p1(new int(10));

    cout << "Value: " << *p1 << endl;

    // Transfer ownership
    UniquePtr<int> p2 = std::move(p1);

    if (p1.get() == nullptr)
        cout << "p1 is empty after move\n";

    cout << "Value in p2: " << *p2 << endl;

    return 0;
}
