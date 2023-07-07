#include <iostream>
using namespace std;

/* print the following pattern:
1234        123456
1234        123456
1234        123456
1234        123456
            123456
            123456
*/


int main() {
    int n;
    cout << "Enter no. of rows: ";
    cin >> n;
    int i = 1;
    while (i<=n) {
        int j = 1;
        while (j<=n) {
            cout << j;
            j++;
        }
        cout << endl;
        i++;
    }
}