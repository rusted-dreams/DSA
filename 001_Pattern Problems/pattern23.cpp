#include <iostream>
using namespace std;

/*print the following pattern:
                   1
                  121
                 12321
                1234321
*/

int main() {
    int n;
    cout << "enter no. of rows: ";
    cin >> n;
    int i = 1;

    while (i<=n) {    //print each row

    // print the spaces (1st triangle).
        int space = 1;
        while (space <= n-i) { 
            cout << " ";
            space++;
        }

    // print the 2nd triangle.
        int j = 1;
        while (j<=i) {
            cout << j;
            j++;
        }

    // print the 3rd tringle.
        int k = i-1;
        while (k) {
            cout << k;
            k--;
        }
        cout << endl;
        i++;

    }
    
}