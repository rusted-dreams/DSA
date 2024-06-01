#include <iostream>
using namespace std;
/*
print the following star pattern:
**********
**********
**********
**********
**********
*/

int main() {
    int x = 5;
    while (x > 0) {
        cout << "**********" << endl;
        x--;
    }
}