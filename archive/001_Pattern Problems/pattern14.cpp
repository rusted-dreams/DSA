#include <iostream>
using namespace std;

/*print the following pattern:
        A 
        B C
        D E F
        G H I J
*/

int main() {
    int n;
    cout << "enter no. of rows: ";
    cin >> n;
    int i = 1;
    char ch = 'A';
    while (i<=n) {
        int j = 1;
        while (j<=i) {
            cout << ch << " ";
            j++, ch++;
        }
        i++;
        cout << endl;
    }
}