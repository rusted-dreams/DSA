#include <iostream>
using namespace std;

/*print the following pattern:
           1
          22
         333
        4444
*/

int main() {
    int n;
    cout << "enter no. of rows: ";
    cin >> n;

    int i = 1;

    while ( i <= n) {
        int s = n - i;
        while (s >= 1) {
            cout << " ";
            s--;
        }

        int j = 1;
        while (j<=i) {
            cout << i;
            j++;
        }
        cout << endl;
        i++;
    }
    
}