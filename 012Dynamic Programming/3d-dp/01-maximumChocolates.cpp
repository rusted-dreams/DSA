// problem link: https://www.naukri.com/code360/problems/chocolate-pickup_3125885
// problem - Chocolate Pickup

#include <bits/stdc++.h> 
using namespace std;

/*
Approach:
- Two people start from (0,0) and (0,m-1).
- At every row, both can move to:
    col-1, col, col+1
- State:
    dp[row][a][b]
    = maximum chocolates collectable starting from:
      current row,
      Alice at column 'a',
      Bob at column 'b'

Transition:
- Try all 9 possible move combinations.
- If both land on same cell -> count once.
- Otherwise count both cells.

TC: O(n * m * m * 9)
SC: O(n * m * m)
*/


int solve(int row, int a, int b,
          int n, int m,
          vector<vector<vector<int>>> &dp,
          vector<vector<int>> &grid) {

    // out of bounds
    if(a < 0 || b < 0 || a >= m || b >= m)
        return -1e9;

    // last row
    if(row == n - 1) {
        if(a == b)
            return grid[row][a];

        return grid[row][a] + grid[row][b];
    }

    // memoized state
    if(dp[row][a][b] != -1e9)
        return dp[row][a][b];

    int maxChocolates = -1e9;

    // try all 9 move combinations
    for(int da = -1; da <= 1; da++) {
        for(int db = -1; db <= 1; db++) {

            int chocolates =
                solve(row + 1,
                      a + da,
                      b + db,
                      n, m, dp, grid);

            // same cell -> count once
            if(a == b)
                chocolates += grid[row][a];
            else
                chocolates += grid[row][a] + grid[row][b];

            maxChocolates = max(maxChocolates, chocolates);
        }
    }

    return dp[row][a][b] = maxChocolates;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {

    vector<vector<vector<int>>> dp(
        r,
        vector<vector<int>>(c, vector<int>(c, -1e9))
    );

    return solve(0, 0, c - 1, r, c, dp, grid);
}



int main() {
    
}