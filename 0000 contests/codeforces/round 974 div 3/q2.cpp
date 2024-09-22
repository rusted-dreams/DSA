#include <iostream>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        bool even = false;
        cin >> n >> k;
        // int oddCount = 0;
        int start = n-k+1;
        int firstOdd;
        start%2 == 0? firstOdd = start+1 : firstOdd = start;
        int lastOdd;
        n%2 == 0? lastOdd=n-1 : lastOdd=n;
        int oddCount = (lastOdd - firstOdd)/2 + 1;
        if(oddCount%2 == 0) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}