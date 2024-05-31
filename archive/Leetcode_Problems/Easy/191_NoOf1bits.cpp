#include <iostream>
using namespace std;



/* 
The following code works on leetcode but some for reason here the input we give in binary form is taken as integer and hence the answer comes to be wrong here. I will look into the issue sometime in the future.
*/

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