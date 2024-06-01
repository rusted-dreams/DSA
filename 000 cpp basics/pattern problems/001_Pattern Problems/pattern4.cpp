#include <iostream>
using namespace std;

/*print the following pattern:
        1 2 3
        5 6 7
        8 9 10

*/

int main() {
    int n;
    cout << "enter no. of rows: ";
    cin >> n;
    
    int i = 1;
    int count = 1;
    while (i<=n) {
        int j = 1;
        while (j<=n) {
            cout << count << " ";
            count++, j++;
        }
        cout << endl;
        i++;
    }
}