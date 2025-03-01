#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    
    vector<int> ans;
    unordered_set<int> used;
    int cur_or = 0;

    // Add distinct numbers that contribute to the OR sum
    for (int i = 0; i < 30; i++) {
        if (x & (1 << i)) {
            ans.push_back(1 << i);
            used.insert(1 << i);
            cur_or |= (1 << i);
        }
    }

    // Fill the rest with smallest unused numbers
    int num = 0;
    while (ans.size() < n - 1) {
        while (used.count(num)) num++; // Find the smallest unused number
        ans.push_back(num);
        used.insert(num);
    }

    // The last element should ensure OR sum remains x
    int last_element = x ^ cur_or;
    if (used.count(last_element)) {
        // If last_element is already in use, we must adjust the second-last entry
        ans.pop_back();
        ans.push_back(ans.back() ^ last_element); // Ensure OR sum remains x
    }
    ans.push_back(last_element);

    // Print the answer
    for (int num : ans) cout << num << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
