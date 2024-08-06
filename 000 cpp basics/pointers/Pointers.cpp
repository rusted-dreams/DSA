#include <iostream>
using namespace std;





int main() {

    // & - address of operator.
    // * - de-reference operator.

    int num = 5;
    char sm = 's';
    
    int *p = &num; // p is a pointer to num;
    char *c = &sm; // c is a pointer to sm;

    // never do:
    int *garbagePtr; // will pick any garbage value very wrong practice.
    // instead do:
    int *nPTR = 0; // null ptr.


    cout << *p << endl; // will print the value at address p;
    cout << p << endl; // prints the address;
    cout << sizeof(p) << endl;


    // copying a ptr:
    int *ptr = &num;
    int *ptrCopy = ptr;


    cout << p+1 << endl; // since int is of 4 byte, the p+1 will now point to the next address block which is 4 bytes after the current address of p
    //lets compare:
    cout << p << " - " << p+1 <<  endl;
    

}