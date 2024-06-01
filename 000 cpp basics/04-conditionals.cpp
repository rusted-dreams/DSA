#include <iostream>
using namespace std;


int main() {
    char ch = 'd';
    if (ch >=65 && ch <=90) {
        cout << "upper case" << endl;
    }
    else if (ch >= 97 && ch <= 122) {
        cout << "lower case" << endl;
    }
    else if (ch >= 48 && ch <= 57) {
        cout << "numeric" << endl;
    }
}