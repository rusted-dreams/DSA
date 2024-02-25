#include <iostream>
using namespace std;


int main() {
    int num = 5;

    cout << num << endl;

    // address of Operator:
    cout << "address of num is " << &num << endl;
    // cout << "can't be written as " << num& << endl;

    int *ptr = &num;
    int* p = &num;

    // ptr contains the address of the num block:
    cout << ptr << endl;

    // dereference operator (*) : prints the value at that address:
    cout << *ptr << endl;


    // copying a pointer:
    cout << "copying a pointer: " << endl;
    int *q = p;
    cout << p << " - " << q << endl;
    cout << *p << " - " << *q << endl;

    cout << p+1 << endl; // since int is of 4 byte, the p+1 will now point to the next address block which is 4 bytes after the current address of p

    int n = 6;
    int m = 8;
    
    int *a = &n;
    cout << *(a+1) << endl; //expecting 8
} 
