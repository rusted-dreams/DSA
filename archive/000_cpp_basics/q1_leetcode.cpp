#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    int prod = 1;
    int sum = 0;
    while (n) {
        prod *= n%10;
        sum += n%10;
        n = n/10;
    }
    int ans = prod - sum;
    cout << "the answer is: " << ans << endl;
}