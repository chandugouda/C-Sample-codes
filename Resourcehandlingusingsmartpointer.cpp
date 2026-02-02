#include <iostream>
#include <memory>
using namespace std;

template<typename T>
class Holder {
private:
    unique_ptr<T> p;

public:
    Holder(const T& value)
        : p(make_unique<T>(value)) {}

    T get() const {
        return *p;
    }
};

int main() {
    auto p = make_unique<Holder<int>>(10);
    cout<<p->get()<<endl;
    return 0;
}