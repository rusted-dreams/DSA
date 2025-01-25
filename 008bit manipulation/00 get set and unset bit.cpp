#include <iostream>
using namespace std;

int getBit(int num , int i) {
    // suppose you want 5th bit (0 indexed). then we take the bit wise and of the no. and (1 left shifted 5 times), if this no. is != 0 then it is a set bit.
    int bit = (num & (1<<i))!=0 ? 1:0;

    //alternate method:
    int bitAlternateMethod = (num>>i) & 1?1:0;
    return bit; 
}

int setBit(int num, int i) {
    return num | (1<<i);
}

int unsetBit(int num, int i) {
    return (num & (~(1<<i)));
}

int main() {
    int num = 70;
    int i = 2;

    int bit = getBit(num, i);
    cout << i << "th bit: " << bit << endl;

    num = setBit(num, i);
    cout << "after setting ith bit, num is: " << num << endl; 

    num = unsetBit(num, i);
    cout << "after unSetting ith bit, num is: " << num << endl; 
}