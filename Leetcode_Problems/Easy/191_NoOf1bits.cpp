#include <iostream>
using namespace std;

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n)
    {
        if ((n & 1) == 1)
        {
            count += 1;
        }
        n = n >> 1;
    }
    return count;
}

int main() {
    uint32_t n;
    cout << "Enter a binary no.: ";
    cin >> n;

    cout << hammingWeight(n) << endl;
}