#include <iostream>
using namespace std;

/*print the following pattern:
1 
2 3 
4 5 6
7 8 9 10
*/
int main() {
    int n;
    cout << "enter no. of rows: ";
    cin >> n;
    int row = 1;
    int count = 1;
    while (row<=n) {
        int col = 1;
        while (col<=row) {
            cout << count << " ";
            count++;
            col++;
        }
        cout << endl;
        row++;
    }
}