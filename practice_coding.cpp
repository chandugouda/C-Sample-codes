#include <iostream>
#include<string>
using namespace std;

//reverse string
// int main() {
//     int a[5]={1,2,3,4,5};
//     int len=sizeof(a)/sizeof(a[0]);
//     int start=0,end=(len-1);
//     while(start<end){
//         int temp=a[start];
//         a[start]=a[end];
//         a[end]=temp;
//         start++;
//         end--;
//     }
//     for(int i=0;i<len;i++){
//         cout<<a[i]<<" ";
//     }
//     return 0;
// }

//find duplicate

// int main(){
//     int a[7]={1,2,2,3,4,4,5};
//     int a1[10]={};
//     int len=sizeof(a)/sizeof(a[0]);
//     int k = 0;
//     for (int i = 1; i < len; i++) {
//         if (a[i] != a[i - 1]) {
//             a1[k++] = a[i-1];
//         }
//     }
//     a1[k++]=a[len-1];
//     for (int i = 0; i < k; i++) {
//         cout << a1[i] << " ";
//     }
//     return 0;
// }


// int main() {
//     int arr[] = {1, 2, 3, 5, 6,8,7};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     int N = n + 1;   // since one number missing
//     int expected = N * (N + 1) / 2;

//     int actual = 0;
//     for (int i = 0; i < n; i++) {
//         actual += arr[i];
//     }

//     cout << "Missing number: " << expected - actual;
// }

// int main() {
//     int arr[] = {1, 3, 6};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     int N = 6; // upper bound of range

//     int freq[7] = {0};  // size N+1

//     for (int i = 0; i < n; i++) {
//         freq[arr[i]] = 1;
//     }

//     cout << "Missing numbers: ";
//     for (int i = 1; i <= N; i++) {
//         if (freq[i] == 0) {
//             cout << i << " ";
//         }
//     }
// }


// int main(){
//     int n=1234;
//     int temp=n;
//     int rev=0;
//     while(n!=0){
//         int rem=n%10;
//         rev=(rev*10)+rem;
//         n=n/10;
//     }
//     cout<<rev<<endl;
//     if(temp == rev){
//         cout<<"Palindrome "<<endl;
//     }
//     else{
//         cout<<"Not palindrome "<<endl;
//     }
//     return 0;
// }
// int main(){
//     string s="chandu";
//     int len=s.length();
//     cout<<len;
//     string temp=s;
//     int start=0,end=len-1;
//     while(start<end){
//         int x= s[start];
//         s[start]=s[end];
//         s[end]=x;
//         start++;
//         end--;
//     }
//     cout<<s<<endl;
// }
int main()
{
    int x = 10;
    int* p = &x; 
    int** pp = &p;
    
    cout << **pp << " "; //10
    *p = 20;
    cout << **pp; //20



}

