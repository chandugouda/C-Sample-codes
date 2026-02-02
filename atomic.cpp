#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> counter(0);   // atomic counter

void increment() {
    for (int i = 0; i < 100000; i++) {
        counter++;             // atomic operation
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final counter value (atomic): "
              << counter << std::endl;

    return 0;
}
