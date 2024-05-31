#include <iostream>
using namespace std;

int reverseInteger(int x) {
    int ans = 0;
    int digit;
    while(x) {
            digit = x%10;
            if(( ans > INT32_MAX/10 ) || (ans < INT32_MIN/10)) {
                return 0;
            }
            ans = ans * 10 + digit;
            x /= 10;
        }
        return ans;
}


int main() {
    int x;
    cout << "Enter a number: ";
    cin >> x;
    cout << reverseInteger(x) << endl;
}