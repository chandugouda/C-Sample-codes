//uppercase and lowercase
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HeLLo WoRLD";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] +32;  // or +32
        }
    }

    cout << s;   // hello world
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 32;  // or -32
        }
    }

    cout<<s<<endl;
    return 0;
}

//  first non-repeating character
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "swiss";
    int freq[256] = {0};

    // Step 1: Count frequency
    for (char c : s) {
        freq[c]++;
    }

    // Step 2: Find first non-repeating
    for (char c : s) {
        if (freq[c] == 1) {
            cout << c;
            break;
        }
    }

    return 0;
}

//duplicate
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "swiss";
    char b[10];
    int k = 0;

    for (int i = 0; i < s.length(); i++) {
        bool isDuplicate = false;

        for (int j = 0; j < i; j++) {
            if (s[i] == s[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            b[k++] = s[i];
        }
    }

    b[k] = '\0';   // null-terminate

    cout << b;
    return 0;
}


//reverse word in  a string 
#include <iostream>
using namespace std;

// Function to reverse characters between two indices
void reverse(char str[], int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char str[] = "I love embedded systems";

    int len = 0;
    while (str[len] != '\0')  // find length
        len++;

    // Step 1: Reverse whole string
    reverse(str, 0, len - 1);

    // Step 2: Reverse each word
    int start = 0;
    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            reverse(str, start, i - 1);
            start = i + 1;
        }
    }

    cout << str;
    return 0;
}

//onlydigits
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "123456";
    bool onlydigit=false;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9'){
            onlydigit=true;
            continue;
        }
        else {
            cout<<"not only digit "<<endl;
            break;
        }
    }
    if(onlydigit== true){
        cout<<"Onlydigit";
    }
    return 0;
}

//sustrings from string
 #include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "abc";
    int n=s.length();
    int len=(n*(n+1))/2; //how many passible
    cout<<len<<endl;
    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            for (int k = i; k <= j; k++) {
                cout << s[k];
            }
            cout << endl;
        }
    }

    return 0;
}


//count the words in string
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "chandu is right";
    int count = 0;

    for (int i = 0; i < s.length(); i++) {
        if ((i == 0 && s[i] != ' ') ||
            (s[i] != ' ' && s[i - 1] == ' ')) {
            count++;
        }
    }

    cout << count;
    return 0;
}

//remove spaces from string
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "chandu is right";
    string result = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            result += s[i];
        }
    }

    cout << result;
    return 0;
}

// find duplicate charecters in a string
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "chanduaa";
    int freq[256] = {0};

    // Count frequency
    for (char c : s) {
        freq[c]++;
    }

    // Print duplicates once
    for (char c : s) {
        if (freq[c] > 1) {
            cout << c << " ";
            freq[c] = 0;  // prevent re-printing
        }
    }

    return 0;
}

//frequency of each character
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "chanduaa";
    int freq[256] = {0};

    // Count frequency
    for (char c : s) {
        freq[c]++;
    }

    // Print frequency
    for (char c : s) {
        if (freq[c] != 0) {
            cout << c << " : " << freq[c] << endl;
            freq[c] = 0;  // avoid printing again
        }
    }

    return 0;
}
