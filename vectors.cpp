//duplicates
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1,2,2,3,3,4,5};

    v.erase(unique(v.begin(), v.end()), v.end());

    for (int x : v)
        cout << x << " ";
}


//max and min 
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    vector<int>v={1,4,3,2,8,5};
    sort(v.begin(),v.end());
    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<endl;
    auto max=v.back();
    auto min=v.front();
    cout<<"Max element is "<<max<<endl;
    cout<<"Min element is "<<min<<endl;
    return 0;
}

//to check sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1,2,3,4,8,9};

    if (is_sorted(v.begin(), v.end()))
        cout << "Sorted\n";
    else
        cout << "Not sorted\n";

    return 0;
}

//remove value from vector
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    vector<int>v={1,2,3,2,4,2};
    int value=2;
    for(auto it = v.begin();it !=v.end();){
        if(*it ==value){
            it=v.erase(it);
        }
        else{
            ++it;
        }
    }
    for(auto it : v){
        cout<<it<< " ";
    }
    return 0;
}

//reverse string
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> v = {"hello", "world", "c++"};

    reverse(v.begin(), v.end());

    for ( auto& s : v)
        cout << s << " ";

    return 0;
}

//merge 2 vector
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {2,1,4,3};
    vector<int> v1 = {7,1,2,3};
    vector<int>result(v.size()+v1.size());
    sort(v.begin(),v.end());
    sort(v1.begin(),v1.end());
    merge(v.begin(),v.end(),v1.begin(),v1.end(),result.begin());
    for(auto it : result){
        cout<<it <<" ";
    }
    return 0;
}
