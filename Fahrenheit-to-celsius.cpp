#include <iostream>
using namespace std;

int main() {
    double f;
    cout << "enter temp. in fahrenheit: ";
    cin >> f;

    double c = (f-32)*5/9;
    cout << f << " degree fahrenheit = "<< c << " degree celsius"<< endl;
}