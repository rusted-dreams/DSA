#include <iostream>
using namespace std;


// using Euclid algorithm
// https://www.codingninjas.com/studio/library/gcd-euclidean-algorithm  for refs

int getGCD(int a, int b) {
    if (a==0) 
        return b;
    else if (b==0) 
        return a;
    else if (a == b) 
        return a;
    if (a>b) 
        getGCD(a-b, b);
    else 
        getGCD(b-a, a);
    return a;
}

// we can also get the lcm of the two nos. using the property gcd*lcm = product of the two nos.
int getLCM(int a, int b) {
    int gcd = getGCD(a, b);
    int lcm = a*b/gcd;
    return lcm;
}


int main() {
    cout << "enter a: ";
    int a;
    cin >> a;
    cout << "enter b: ";
    int b; 
    cin >> b;

    int gcd = getGCD(a, b);
    int lcm = getLCM(a, b);
    cout << "gcd of " << a << " and " << b << " is " << gcd << endl;
    cout << "lcm of " << a << " and " << b << " is " << lcm << endl;
}