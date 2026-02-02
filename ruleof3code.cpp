#include <iostream>
using namespace std;

class A {
    public:
    int *p;
    A(int value =0){
        p=new int (value);
        cout<<"Constructor"<<endl;
    }
    A(const A& other ){
        p=new int (*other.p);
        cout<<"Copy constructor "<<endl;
    }
    A& operator=(const A& other){
        if(this != &other){
            delete p;
            p=new int (*other.p);
            cout<<"Copy Assignment "<<endl;
        }
        return *this;
    }
    ~A(){
        delete p;
        cout << "Destructor\n";
    }
    int get() const{
        return *p;
    }
};
int main(){
    cout << "Create b1\n";
    A b1(10);

    cout << "\nCreate b2 using copy constructor\n";
    A b2 = b1;      // Copy Constructor

    cout << "\nAssign b1 to b3\n";
    A b3;
    b3 = b1;             // Copy Assignment

    cout << "\nValues:\n";
    cout << "b1 = " << b1.get() << endl;
    cout << "b2 = " << b2.get() << endl;
    cout << "b3 = " << b3.get() << endl;

    cout << "\nEnd of main\n";
    return 0;
}
