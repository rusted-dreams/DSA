#include <iostream>
using namespace std;

/*print the following pattern:
1 
2 3
3 4 5
4 5 6 7
5 6 7 8 9
*/

int main() {
    int n;
    cout << "enter no. of rows: ";
    cin >> n;
    int row = 1;
    
    while (row<=n) {
        int col = 1;
        int count = row;
        while (col<=row) {
            cout << count << " ";
            count++;
            col++;
        }
        cout << endl;
        row++;
    }
}

// # Alternate method without using the count variable:

// int main() {
//     int n;
//     cout << "enter no. of rows: ";
//     cin >> n;
//     int row = 1;
    
//     while (row<=n) {
//         int col = 1;
//         while (col<=row) {
//             cout << row + col - 1 << " ";
//             col++;
//         }
//         cout << endl;
//         row++;
//     }
// }