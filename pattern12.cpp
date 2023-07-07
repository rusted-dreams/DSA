#include <iostream>
using namespace std;

/*print the following pattern:
        A B C D
        B C D E
        C D E F
        D E F G
*/

int main() {
    int n;
    cout << "enter no. of rows: ";
    cin >> n;
    int i = 1;

    while (i <= n) {
        int j = 1;
        char ch = 'A' + i - 1;
        while (j <= n) {
            cout << ch << " ";
            ch++, j++;
        }
        cout << endl;
        i++;
    }
}