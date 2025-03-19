#include <bits/stdc++.h>
using namespace std;


// this is not the optimal solution explore why?
// consider the test case {1, 3, 4} and sum 6;
// we need to use recursion and for optimal we need to use dp with memoization.
int totalCoins(vector<int>& coins, int money) {
    int n = coins.size();
    int i = 0;
    int usedCoins = 0;
    while(i < n && money) {
        if(coins[i] > money) i++;
        else {
            usedCoins += money / coins[i];
            money = money % coins[i];
        }
    }
    return money? -1 : usedCoins;
}

// greedy recursive approach may give wrong ans as mentioned above:
// int totalCoins(vector<int>& coins, int money) {
//     int n = coins.size();
//     if(!money) return 0;
//     if(n == 0 || coins[n-1] > money) return -1;
//     int l=0;
//     int r = n-1;
//     int i = 0;
//     int mid;
//     while(l < r) {
//         mid = l+ (r-l)/2;
//         if(coins[mid] > money) l = mid+1;
//         else r = mid-1;
//     }
//     i = l;
//     if(i == n) return -1;
//     int usedCoins = money/coins[i];
//     money = money%coins[i];
//     int x = totalCoins(coins, money);
//     return x == -1 ? -1 : usedCoins + x;
// }

int main() {
    int n, money;
    cin >> n >> money;
    vector<int> coins(n);
    int ans = 0;
    for(int i=0; i<n; i++){
        cin >> coins[i];
    }
    sort(coins.rbegin(), coins.rend());
    int res = totalCoins(coins, money);
    cout << res << endl;
}