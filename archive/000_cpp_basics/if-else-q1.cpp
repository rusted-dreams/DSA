#include <iostream>
using namespace std;

int main() {
    char a;
    cin >> a;
    
    if ( (int) a >= 48 and (int) a <= 57) {
        cout << "you entered a numeric digit" << endl;
    }

    else if ((int) a >= 65 and (int) a <= 90 ) {
        cout << "you entered a capital letter" << endl;
    }

    else if ((int) a >= 97 and (int) a <=122 ) {
        cout << "you entered a small letter" << endl;
    }
}