// problem -
// link - 

#include <bits/stdc++.h>
using namespace std;

bool helper(int x, int y, int z) {
    if (x + y > z && y + z > x && z + x > y) return true;
    return false;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int res = 0;
        int count = 0;
        if (x <= 4) {
            cout << -1 << endl;
            continue;
        }
        int y = x;
        int bit = 0;
        int prev = x & 1;

        int i = 0;
        int mask = 1;

        while (true) {
            bit = (x >> i) & 1;

            if (i > 0) {
                int prev = (x >> (i - 1)) & 1;
                if (bit != prev) {
                    y ^= mask;
                    break;
                }
            }

            y ^= mask;

            i++;
            mask <<= 1;
        }
        int z = x ^ y;
        if (z == 0) {
            cout << -1 << "\n";
            continue;
        }
        int result = min(y, z);
        if (result >= x || !helper(x, y, z)) result = -1;
        cout << result << endl;




        // else {
        //     while (x != 0) {
        //         int temp = 0;
        //         temp = (x & 1) ^ 1;
        //         res = res | (temp << count);
        //         x = x >> 1;
        //         count++;
        //     }
        //     if (res == 0) {
        //         cout << -1 << endl;
        //         continue;
        //     }
        //     // else {
        //     //     res += 1;
        //     //     cout << res << endl;
        //     // }
        //     int a = x;
        //     int count = 0;
        //     int digit = x&1;

        //     while(a) {
        //         if(a&1 == digit) count++;
        //         else break; 
        //     }
        //     int y = x;
        //     for(int i=0; i<=count; i++){
        //         y = y^(1<<count);
        //     }



        // }
    }
}