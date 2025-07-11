// problem - A. Extremely Round
// link - https://codeforces.com/problemset/problem/1766/A

#include <bits/stdc++.h>
using namespace std;


// optimised O(1) TC.
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int count = 0;
        while (n >= 10) {
            count += 9;
            n /= 10;
        }
        count += n;

        cout << count << endl;
    }
}

// optimised by precomputing the round nos.
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;
//     // precompute the round nos. before any test case:
//     vector<int> rounds;
//     for (int i = 1; i < 999999; i *= 10) {
//         for (int j = i; j < i * 10; j += i) {
//             rounds.push_back(j);
//         }
//     }

//     while (t--) {
//         int n;
//         cin >> n;
//         int ans = 0;
//         for (int it : rounds) {
//             if (it <= n) ans++;
//         }
//         cout << ans << endl;
//     }
// }


// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         int ans = 0;
//         for (int i = 1; i <= n; i *= 10) {
//             for (int j = i; j < i * 10 && j <= n; j += i) {
//                 ans++;
//             }
//         }
//         cout << ans << endl;
//     }
// }