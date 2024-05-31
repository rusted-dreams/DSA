#include <iostream>
using namespace std;

/*print the following pattern:
1
2 1
3 2 1
4 3 2 1
5 4 3 2 1
*/

int main() {
    int n;
    cout << "enter no. of rows: ";
    cin >> n;
    int row = 1;
    
    while (row<=n) {
        int col = 1;
        while (col<=row) {
            cout << row-col+1 << " ";
            col++;
        }
        cout << endl;
        row++;
    }
}