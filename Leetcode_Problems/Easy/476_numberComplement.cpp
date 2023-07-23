#include <iostream>
using namespace std;


int findComplement(int num) {
        if (num == 0) {
            return 1;
        }
        int m = num;
        int mask = 0;
        while(m) {
            mask = (mask << 1 ) | 1;
            m = m >> 1;
        }
        return ((~num) & mask);
    }

int main() {
    int num;
    cout << " Enter a no.: ";
    cin >> num;
    cout << "complement of " << num << " is " << findComplement(num) << endl;
}