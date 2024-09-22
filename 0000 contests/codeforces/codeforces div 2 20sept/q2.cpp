#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve(vector<long long>& ratings) {
    int n = ratings.size();
    vector<long long> prefix_sum(n + 1, 0);
    
    // Calculate prefix sum
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + ratings[i];
    }
    
    long long max_rating = ratings[n - 1];
    long long current_sum = 0;
    
    for (int i = n - 1; i > 0; i--) {
        current_sum += ratings[i];
        max_rating = max(max_rating, ratings[i - 1] - (current_sum - ratings[i]));
    }
    
    return max_rating;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> ratings(n);
        for (int i = 0; i < n; i++) {
            cin >> ratings[i];
        }
        
        cout << solve(ratings) << "\n";
    }
    
    return 0;
}