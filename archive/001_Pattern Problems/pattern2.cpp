#include <iostream>
using namespace std;

/*
print the following pattern:
1111
2222
3333
4444
*/

int main() {
    int row;
    cout << "enter no. of rows: ";
    cin >> row;

    int i = 1;
    while (i <= row) {
        int col = 1;
        while (col <= row) {
            cout << i;
            col++;
        }
        i++;
        cout << endl;
    }
}