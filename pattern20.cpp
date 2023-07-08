#include <iostream>
using namespace std;

/*print the following pattern:
        1234
         234
          34
           4
         
*/

int main() {
    int n;
    cout << "enter no. of rows: ";
    cin >> n;
    int i = 1;
    while (i<=n) {
        int space = 1;
        while (space <= i-1) {
            cout << " ";
            space++;
        }
        int j = 1;
        while (j<=n-i+1) {
            cout << i+j-1;
            j++;
        }
        cout << endl;
        i++;
    }
}