#include <iostream>
using namespace std;

/*print the following pattern:
           1
          23
         456
        78910
*/

int main() {
    int n;
    cout << "enter no. of rows: ";
    cin >> n;

    int i = 1;
    int count = 1;

    while ( i <= n) {
        int space = n - i;
        while (space >= 1) {
            cout << " ";
            space--;
        }

        int j = 1;
        while (j<=i) {
            cout << count;
            j++, count++;
        }
        cout << endl;
        i++;
    }
    
}