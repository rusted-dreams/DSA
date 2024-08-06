#include <iostream>
using namespace std;

// Reference Variable: same address, different names.
// why do we need?
// because a function uses pass by value as arguments it creates a different var. with the value and has scope only upto the function block.
// but if we pass a varible as pass by reference it can have scope outside the function block.

void passByValue(int n) {
    n += 5;
}

void passByReference(int &n) {
    n += 5;
}



int main() {
    int i = 60;
    int &j = i;    // j also points to the same address as i. 

    cout << " i = " << i << " | and j = " << j << endl;
    cout << endl;

    int n = 10;
    passByValue(n);
    cout << " pass by value :" << n << endl; // here the value of n does not change since the fun. creates a different variable n inside the fun. and make changes to that variable and does not affect the main() n.

    passByReference(n);
    cout << " pass by reference :" << n << endl;  // here the value of n of main() is changed since it is passed as reference.


    /*
        You should never use reference as return type of a fun. since the var. scope is within the fun. block and after execution the address of the variable might be unavailable and hence might cause issues.
        eg. -: 
        wrong practice:
        int& function(int n) {
            n = 60;
            int &a = n;
            return a;
        }
    */

}