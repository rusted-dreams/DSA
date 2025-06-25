// problem - C. Target Practice
// link - https://codeforces.com/problemset/problem/1873/C

#include <bits/stdc++.h>
using namespace std;

// optimal approach:
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        vector<vector<char>> target(10, vector<char>(10, '.'));
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cin >> target[i][j];
            }
        }
        int score = 0;
        for (int row = 0; row < 10; row++) {
            for (int col = 0; col < 10; col++) {
                if (target[row][col] == 'X') {
                    score += min({ row, col, 9 - row, 9 - col }) + 1;
                }
            }
        }
        cout << score << endl;
    }
    return 0;
}


// My approach:
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;
//     while (t--) {
//         vector<vector<char>> target(10, vector<char>(10, '.'));
//         for (int i = 0; i < 10; i++) {
//             for (int j = 0; j < 10; j++) {
//                 cin >> target[i][j];
//             }
//         }
//         int score = 0;
//         for (int row = 0; row < 10; row++) {
//             for (int col = 0; col < 10; col++) {
//                 if (target[row][col] == 'X') {
//                     int x = row;
//                     int y = col;
//                     if (row >= 5) x = 5 - (row % 5) - 1;
//                     if (col >= 5) y = 5 - (col % 5) - 1;
//                     score += min(x, y) + 1;
//                 }
//             }
//         }
//         cout << score << endl;
//     }
//     return 0;
// }