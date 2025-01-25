// problem - Two numbers with odd occurrences
// link - https://www.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1

#include <bits/stdc++.h>
using namespace std;


// using concept of buckets:
vector<long long int> twoOddNum(long long int Arr[], long long int N) {
    long long int xorAll = 0;
    for (long long int i = 0; i < N; i++) {
        xorAll = xorAll ^ Arr[i];
    }

    long long int bucket1 = 0;
    long long int bucket2 = 0;

    long long int rightMost = 0;
    while (xorAll > 0) {
        if (xorAll & 1) break;
        rightMost++;
        xorAll = xorAll >> 1;
    }

    for (long long int i = 0; i < N; i++) {
        if (Arr[i] & (1 << rightMost)) bucket1 = bucket1 ^ Arr[i];
        else bucket2 = bucket2 ^ Arr[i];
    }

    if (bucket1 > bucket2) return { bucket1, bucket2 };
    else return { bucket2, bucket1 };
}

int main() {

}