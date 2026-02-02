#include <thread>
#include <iostream>
#include<mutex>
using namespace std;
int counter = 0;
mutex m;

void increment() {
    lock_guard<mutex>lock(m);
    for (int i = 0; i < 100000; i++){
        counter++;
}
}
int main() {
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();

    cout << counter << endl;  
}



