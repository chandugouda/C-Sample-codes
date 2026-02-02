#include <iostream>
using namespace std;

/* Control block */
struct ControlBlock {
    int sharedCount;
    int weakCount;

    ControlBlock() : sharedCount(1), weakCount(0) {}
};

template<typename T>
class WeakPtr;   // forward declaration

template<typename T>
class SharedPtr {
    T* ptr;
    ControlBlock* ctrl;

    void release() {
        if (ctrl) {
            ctrl->sharedCount--;

            if (ctrl->sharedCount == 0) {
                delete ptr;   // destroy object

                if (ctrl->weakCount == 0) {
                    delete ctrl;  // destroy control block
                }
            }
        }
    }

public:
    // constructor
    explicit SharedPtr(T* p = nullptr) : ptr(p) {
        ctrl = p ? new ControlBlock() : nullptr;
    }

    // copy constructor
    SharedPtr(const SharedPtr& other) {
        ptr = other.ptr;
        ctrl = other.ctrl;
        if (ctrl) ctrl->sharedCount++;
    }

    // destructor
    ~SharedPtr() {
        release();
    }

    T& operator*() const { return *ptr; }

    int use_count() const {
        return ctrl ? ctrl->sharedCount : 0;
    }

    friend class WeakPtr<T>;
};

template<typename T>
class WeakPtr {
    T* ptr;
    ControlBlock* ctrl;

public:
    // construct from SharedPtr
    WeakPtr(const SharedPtr<T>& sp) {
        ptr = sp.ptr;
        ctrl = sp.ctrl;
        if (ctrl) ctrl->weakCount++;
    }

    // destructor
    ~WeakPtr() {
        if (ctrl) {
            ctrl->weakCount--;
            if (ctrl->weakCount == 0 && ctrl->sharedCount == 0) {
                delete ctrl;
            }
        }
    }

    bool expired() const {
        return !ctrl || ctrl->sharedCount == 0;
    }

    SharedPtr<T> lock() const {
        if (expired())
            return SharedPtr<T>();

        ctrl->sharedCount++;
        return SharedPtr<T>(*this);
    }

private:
    // private constructor used by lock()
    WeakPtr(T* p, ControlBlock* c) : ptr(p), ctrl(c) {}
};

int main() {
    SharedPtr<int> sp1(new int(10));
    cout << "Shared count: " << sp1.use_count() << endl;

    {
        SharedPtr<int> sp2 = sp1;
        cout << "Shared count after copy: " << sp1.use_count() << endl;

        WeakPtr<int> wp = sp1;
        cout << "Weak pointer created\n";

        if (!wp.expired()) {
            cout << "Object is alive\n";
        }
    }

    cout << "Shared count after block: " << sp1.use_count() << endl;

    return 0;
}
