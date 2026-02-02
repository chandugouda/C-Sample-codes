#include <iostream>
using namespace std;

/* Control block that holds reference count */
struct ControlBlock {
    int refCount;

    ControlBlock() : refCount(1) {}
};

template <typename T>
class SharedPtr {
private:
    T* ptr;                // actual managed object
    ControlBlock* ctrl;    // shared control block

    // helper to reduce ref count
    void release() {
        if (ctrl) {
            ctrl->refCount--;

            if (ctrl->refCount == 0) {
                delete ptr;      // delete managed object
                delete ctrl;     // delete control block
            }
        }
    }

public:
    // 1. Constructor
    explicit SharedPtr(T* p = nullptr) : ptr(p) {
        ctrl = p ? new ControlBlock() : nullptr;
    }

    // 2. Copy constructor
    SharedPtr(const SharedPtr& other) {
        ptr = other.ptr;
        ctrl = other.ctrl;
        if (ctrl)
            ctrl->refCount++;
    }

    // 3. Copy assignment
    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            release();              // release current ownership
            ptr = other.ptr;
            ctrl = other.ctrl;
            if (ctrl)
                ctrl->refCount++;
        }
        return *this;
    }

    // 4. Destructor
    ~SharedPtr() {
        release();
    }

    // 5. Dereference operators
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }

    // 6. Utility
    int use_count() const {
        return ctrl ? ctrl->refCount : 0;
    }
};

int main() {
    SharedPtr<int> p1(new int(10));
    cout << "p1 count: " << p1.use_count() << endl;

    SharedPtr<int> p2 = p1;
    cout << "After p2 copy, count: " << p1.use_count() << endl;

    {
        SharedPtr<int> p3 = p2;
        cout << "Inside block, count: " << p1.use_count() << endl;
    } // p3 destroyed

    cout << "After block, count: " << p1.use_count() << endl;

    cout << "Value: " << *p1 << endl;

    return 0;
}
