#include <iostream>
using namespace std;

int subtractProductAndSum(int n) {
    int prod = 1;
    int sum = 0;
    while (n) {
        prod *= n%10;
        sum += n%10;
        n = n/10;
    }
    return prod-sum;
}


int main() {
    int n;
    cout << "Enter a no.: ";
    cin >> n;
    cout << "difference of product and sum of digits of " << n << " is " << subtractProductAndSum(n) << endl;
}