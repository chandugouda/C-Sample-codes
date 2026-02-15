1)check the kth position is set or not

#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    //bit =num&(1<<pos)
    int a=10;
    int pos;
    cout<<"Enter the position "<<endl;
    cin>>pos;
    if (a&(1<<pos))
    {
        cout<<"set"<<endl;
    }
    else {
        cout<<"Not set"<<endl;
    }
    return 0;
}

2)Set the particular bit of a number without affecting other bits.
#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    //byte|=(1<<pos)
    uint32_t a=10;
    uint32_t pos;
    cout<<"Enter the position "<<endl;
    cin>>pos;
    a=a|(1<<pos);
    cout <<a<<endl;
    return 0;
}

3)Clear the particular bit of a number.
#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    //byte|=(1<<pos)
    uint32_t a=10;
    uint32_t pos;
    cout<<"Enter the position "<<endl;
    cin>>pos;
    if(a&(1<<pos)){
        a=a&~(1<<pos);
    }
    else{
        cout<<"bit is already clear there "<<endl;
    }
    cout<<a<<endl;
}
4)Toggle the 2nd bit of a number
#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    //byte^=(1<<pos)
    uint32_t a=10;
    uint32_t pos;
    cout<<"Enter the position "<<endl;
    cin>>pos;
    a=a^(1<<pos);
    cout<<a<<endl;
}

5)extract lower nibble of byte
#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    uint8_t a = 0x31;   // 0011 0001

    uint8_t lowerNibble = a & 0x0F;

    cout << (int)lowerNibble << endl;
    return 0;
}


6)extract upper nibble
#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    //byte^=(1<<pos)
    uint32_t a=0x31;
    uint32_t t=(a>>4) &0xFF;
    
    cout<<t<<endl;
}

7)To count number of set bits
n*(n-1)

8️)Combine two uint8_t values into a single uint16_t.
#include <iostream> 
#include <cstdint> 
using namespace std; 
int main() { 
//(a<<8) |b 
uint8_t a=0x12; 
uint8_t b=0x34; 
uint16_t c = (a<<8) |b; 
cout<<c<<endl; 
return 0; 
}

9)Extract bits 3 to 7 from an 8-bit number.
#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    //(a>>4) &0xff
    uint16_t a=0x12;
    a=(a>>3) & 0x1F;
    cout<<a<<endl;
    return 0;
}
10)swap 2 nos
#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    //a^=b
    //b^=a
    //a^=b
    uint16_t a=5;
    uint16_t b=6;
    a^=b;
    b^=a;
    a^=b;
    cout<<a<<b<<endl;
    return 0;
}
