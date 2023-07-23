#include <iostream>
using namespace std;


int main() {
    int n;
    cout << "Enter a no.: ";
    cin >> n;

    int m = n;

    int mask = 0;
    while(m) {
        mask = ( mask << 1 ) | 1;
        m = m >> 1;
    }
    // cout << mask;
    int ans = (~n) & mask;
    cout << "complement of " << n << " is " << ans << endl;
}