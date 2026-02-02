//second largest
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    vector<int> v = {10, 40, 30, 20, 50};

    if (v.size() < 2) {
        cout << "No second largest\n";
        return 0;
    }

    int largest = numeric_limits<int>::min();
    int second  = numeric_limits<int>::min();

    for (int x : v) {
        if (x > largest) {
            second  = largest;
            largest = x;
        }
        else if (x < largest && x > second) {
            second = x;
        }
    }

    if (second == numeric_limits<int>::min()) {
        cout << "No second largest\n";
    } else {
        cout << "Second largest = " << second;
    }
}


//remove middle element
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40};

    int n = v.size();

    if (n == 0) return 0;

    if (n % 2 == 1) {
        int mid = n / 2;
        v.erase(v.begin() + mid);
    } else {
        int mid1 = n / 2 - 1;
        int mid2 = n / 2;

        v.erase(v.begin() + mid2);
        v.erase(v.begin() + mid1);
    }

    for (int x : v)
        cout << x << " ";
}

//remove element from end
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};
    int k=3;
    v.erase(v.end()-k);
    for(auto x : v){
        cout<<x<<" ";
    }
}

//rotate from kthe element
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};
    int k=2;
    reverse(v.begin(),v.end());
    reverse(v.begin(),v.begin()+k);
    reverse(v.begin()+k,v.end());
    for(auto x : v){
        cout<<x<<" ";
    }
}

//check is capacity changed
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    vector<int>v={1,2,2,4,5};
    int cap=v.capacity();
    v.push_back(10);
    if(cap == v.capacity()){
        cout<<"false"<<endl;
    }
    else{
        cout<<"true"<<endl;
    }
    return 0;
}
//check address after realocation
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    vector<int>v={1,2,2,4,5};
    auto *x =&v[0];
    cout<<x<<endl;
    v.push_back(10);
    x =&v[0];
    cout<<x<<endl;
    return 0;
}

//remove without using erase
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};
    int K = 2;   // index to remove (removes 30)

    // Check for valid index
    if (K < 0 || K >= v.size()) {
        cout << "Invalid index" << endl;
        return 0;
    }

    // Shift elements to the left
    for (int i = K; i < v.size() - 1; i++) {
        v[i] = v[i + 1];
    }

    // Reduce vector size
    v.pop_back();

    // Print result
    cout << "Vector after removal: ";
    for (int x : v) {
        cout << x << " ";
    }

    return 0;
}
