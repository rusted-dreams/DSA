#include <iostream>
using namespace std;

/*print the following pattern:
        A B C D
        E F G H
        H I J K
        L M N O
*/

int main() {
    int n;
    cout << "enter no. of rows: ";
    cin >> n;
    int i = 1;
    char ch = 'A';
    while (i <= n) {
        int j = 1;
        while (j <= n) {
            cout << ch << " ";
            ch++;
            j++;
        }
        cout << endl;
        i++;
    }
}