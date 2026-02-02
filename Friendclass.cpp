1/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
class Acc{
    private:
    int balance;
    public:
    Acc(int x){
        balance =x;
    }
    friend class Bank;
};
class Bank{
    public:
    void deposit(Acc& a,int b){
        a.balance=a.balance + b;
        cout<<a.balance<<endl;
    }
    void withdraw(Acc& a, int c){
        a.balance=a.balance - c;
        cout<<a.balance<<endl;
    }
};
int main()
{
    Acc a(10000);
    Bank b;
    b.deposit(a,1000);
    b.withdraw(a,3000);
    return 0;
}