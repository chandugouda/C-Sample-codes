// max and min element in an array
#include <iostream>
#include<vector>
using namespace std;
int main() {
    int arr[5]={4,2,9,1,7};
    int max=arr[0];
    for(int i=1;i<5;i++){
        if(max<arr[i])  //min condition reverse
        {
            max=arr[i];
        }
    }
    cout<<max;
    return 0;
}

//reverse an array in place (2 pointer)
// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
int main() {
    int arr[5]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    int start=0;
    int end=size-1;
    while(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
    for(int i : arr ){
        cout<<i<<" ";
    }
    return 0;
}

//check sorted or not
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    bool isSorted = true;

    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {   
            isSorted = false;
            break;
        }
    }

    if (isSorted) {
        cout << "Array is sorted" << endl;
    } else {
        cout << "Array is not sorted" << endl;
    }

    return 0;
}

//count even and odd numbers in array
// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
int main() {
    int arr[6]={1,2,3,4,5,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    int even_count=0;
    int odd_count=0;
    for(int i=0;i<size;i++){
        if((arr[i] & 1) == 1){
            odd_count++;

        }
        else{
            even_count++;
        }
    }
    cout<<"Odd numbers in the array :"<<odd_count<<endl;
    cout<<"Even numbers in the array :"<<even_count<<endl;
    return 0;
}

//second large element
#include <iostream>
#include <climits>
using namespace std;

int main() {
    int arr[] = {10, 5, 20, 8, 20};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxVal = INT_MIN;
    int secondMax = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (arr[i] > maxVal) {
            secondMax = maxVal;
            maxVal = arr[i];
        }
        else if (arr[i] < maxVal && arr[i] > secondMax) {
            secondMax = arr[i];
        }
    }

    if (secondMax == INT_MIN) {
        cout << "No second largest element exists" << endl;
    } else {
        cout << "Second largest = " << secondMax << endl;
    }

    return 0;
}

//move all zeros to last
// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
int main() {
    int arr[5]={0, 1, 0, 3, 12 };
    int size=sizeof(arr)/sizeof(arr[0]);
    int k=0;
    for(int i=0;i<size;i++){
        if(arr[i] != 0){
            arr[k] = arr[i];
            k++;
        }
    }
    while(k<size){
        arr[k]=0;
        k++;
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

//remove duplicates from sorted array
// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
int main() {
    int arr[7]={1, 1, 2, 2, 3, 4, 4 };
    int size=sizeof(arr)/sizeof(arr[0]);
    int k=0;
    for(int i =1;i<size;i++){
        if(arr[i] != arr[k]){
            k++;
            arr[k]=arr[i];
        }
    }
    int new_size=k+1;
    for(int i=0;i<new_size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

//target match indices
// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
int main() {
    int arr[7]={2,7,11,15 };
    int size=sizeof(arr)/sizeof(arr[0]);
    int target =13;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]+arr[j] == target){
                cout<<i<<" "<<j<<endl;
                break;
            }
        }
    }
    return 0;
}

//missing number in array
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int N = size + 1;   // correct N

    int expectedSum = N * (N + 1) / 2;
    int actualSum = 0;

    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }

    cout << "Missing number = " << (expectedSum - actualSum) << endl;

    return 0;
}

//print all possible subarray
#include <iostream>
using namespace std;

int main() {
    int arr[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            for (int k = i; k <= j; k++) {
                cout << arr[k] <<" ";
            }
            cout << endl;
        }
        cout<<endl;
    }

    return 0;
}

//multiple missing number 
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    int a[]={1,3,5,7,10};
    int size =10;
    int j=0;
    for(int i=1;i<=size;i++){
        if(i!=a[j]){
            cout<<i<<" ";
            j++;
        }
    }
    return 0;
}

//First element whose frequency becomes 2 while scanning
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    int a[]={5, 2, 3, 5, 2};
    int size =sizeof(a)/sizeof(a[0]);
    int freq[256]={};
    for (int i : a){
        freq[i]++;
        if(freq[i] >= 2){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}

//find missing  and repeating number 
#include <iostream>
using namespace std;
int main() {
    int a[]= {1, 3, 3, 4, 5};
    int size =5;
    int freq[256]={};
    for (int i : a){
        freq[i]++;
    }
    for(int i=1;i<=size;i++){
        if(freq[i]==2){
            cout<<"Repeating number is :"<<i<<endl;
        }
        if(freq[i] == 0){
            cout<<"Missing number is :"<<i<<endl;
        }
    }
    return 0;
}


//Smallest subarray with sum strictly greater than K
#include <iostream>
#include <climits>
using namespace std;
int main() {
    int a[]= {1, 4, 45, 6, 0, 19};
    int size =sizeof(a)/sizeof(a[0]);
    int target=51;
    int sum=0;
    int count=0;
    int f=INT_MAX;
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            for(int k=i;k<=j;k++){
                //cout<<a[k]<<" ";
                count++;
                sum+=a[k];
            }
            if(sum>target){
                if(count<f){
                    f=count;
                }
            }
            sum=0;
            count=0;
        }
    }
    cout<<f<<endl;
    return 0;
}


