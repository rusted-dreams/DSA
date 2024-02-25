// 204 count primes

/*
Given an integer n, return the number of prime numbers that are strictly less than n.

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2: 

Constraints:

0 <= n <= 5 * 106
*/



#include <iostream>
#include <vector>
using namespace std;


/*
This was the regular approach but got TLE because of time constraints:

int isPrime(int n) {
    for (int i=2; i<n/2; i++) {
        if (n%i) return false;
    }
    return true;
}

int countPrimeUsingRegularForLoopTLE(int n) {
    int count = 0;
    for (int i=0; i<n; i++) {
        if (isPrime(i)) 
        count ++;
    }
    return count;
}
*/

// correct code with time complexity in mind
int countPrime(int n) {
    int count = 0;
    vector<int> prime(n+1, true);
    prime[0] = prime[1] = false;  // since 0 and 1 are not prime
    
    // if i is prime then increase the count and mark all multiples of i as not prime (false)
    for(int i=2; i<n; i++) {
        if (prime[i]) {
            count ++;

            for (int j=2*i; j<n; j+=i) {
            prime[j] = 0;  // if i is prime then marking all multiples of i as not prime
            }
        }
    }
    return count;
}

int main() {
    cout << "enter a n: ";
    int n;
    cin >> n;
    cout << "There are " << countPrime(n) << " prime nos. which are less than " << n << endl;
}