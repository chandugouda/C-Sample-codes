#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

using namespace std;

vector<int>buffer;
const int max_size=5;

mutex m;
condition_variable cv;

void producer(){
    for(int i=0;i<10;i++){
        unique_lock<mutex> lock(m);
        cv.wait(lock,[]{
            return buffer.size()<max_size;
        });
        buffer.push_back(i);
        cout << "Produced: " << i << endl;
        cv.notify_one();
    }
    
}
void consumer() {
    for (int i = 1; i <= 10; i++) {
        unique_lock<mutex> lock(m);

        cv.wait(lock, [] {
            return !buffer.empty();
        });

        int item = buffer.front();
        buffer.erase(buffer.begin());   // remove first element

        cout << "Consumed: " << item << endl;

        cv.notify_one();  // wake producer
    }
}
int main() {
     thread t1(producer);
     thread t2(consumer);

     t1.join();
     t2.join();

    return 0;
}
