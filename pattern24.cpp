#include <iostream>
using namespace std;

/*print the following pattern:
                1234554321
                1234**4321
                123****321
                12******21
                1********1
*/

int main() {
    int n;
    cout << "enter no. of rows: ";
    cin >> n;
    int i = 1;

    // print each row:
    while (i<=n) {

        // print the first triangle:
        int j = 1;
        while (j<=n-i+1) {
            cout << j;
            j++;
        }
        
        // print the 2nd triangle:
        int k = 1;
        while (k<=2*(i-1)) {
            cout << "*";
            k++;
        }

        // print the 3rd triangle:
        int l = n-i+1;
        while (l) {
            cout << l;
            l--;
        }
        cout << endl;
        i++;

    }
}