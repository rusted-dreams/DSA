#include <iostream>
using namespace std;

//added a comment!
int main() {
    int a, b, ans;
    char operation;

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter operation: ";
    cin >> operation;

    switch(operation) {
        case '+':
            ans = a + b;
            break;
        case '-':
            ans = a - b;
            break;
        case '*':
            ans = a * b;
            break;
        case '/':
            ans = a / b;
            break;
        case '%':
            ans = a % b;
            break;
    }
    cout << a << operation << b << " = " << ans << endl;


}