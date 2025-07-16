// problem - A. Everybody Likes Good Arrays!
// link - https://codeforces.com/problemset/problem/1777/A

#include <bits/stdc++.h>
using namespace std;

int makeGood(vector<int>& good, int x, int count) {
    if (good.empty() || (good.back() % 2 != x % 2)) {
        good.push_back(x);
        return count;
    }
    good.pop_back();
    count = makeGood(good, x, count + 1);
    return count;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        int res = 0;
        vector<int> good;
        good.push_back(arr[0] % 2);
        for (int i = 1; i < n; i++) {
            int b = arr[i] % 2;
            res += makeGood(good, b, 0);
        }
        cout << res << endl;
    }
}