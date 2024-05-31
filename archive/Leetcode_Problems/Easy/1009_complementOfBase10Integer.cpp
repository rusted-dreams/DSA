#include <iostream>
using namespace std;


int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        int m = n;
        int mask = 0;
        while(m) {
            mask = (mask << 1 ) | 1;
            m = m >> 1;
        }
        return ((~n) & mask);
    }

int main() {
    int n;
    cout << "Enter a no.: ";
    cin >> n;
    cout << "Complement of " << n << " is " << bitwiseComplement(n) << endl;
}