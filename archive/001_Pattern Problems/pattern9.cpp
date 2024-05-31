#include <iostream>
using namespace std;

/*print the following pattern:
        A A A A
        B B B B
        C C C C
        D D D D
*/

int main() {
    int n;
    cout << "enter no. of rows: ";
    cin >> n;
    int i = 1;

    while (i<=n) {
        int j = 1;
        while (j<=n) {
            char ch = 'A'+i-1;
            cout << ch << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}