#include <iostream>
#include <algorithm>
using namespace std;


/*
problem link - https://takeuforward.org/pattern/pattern-22-the-number-pattern/
             - https://www.codingninjas.com/codestudio/problems/ninja-and-the-number-pattern-i_6581959?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems

print the following pattern:


Input Format: N = 3
Result: 
3 3 3 3 3 
3 2 2 2 3 
3 2 1 2 3 
3 2 2 2 3 
3 3 3 3 3

Input Format: N = 6
Result:   
6 6 6 6 6 6 6 6 6 6 6 
6 5 5 5 5 5 5 5 5 5 6 
6 5 4 4 4 4 4 4 4 5 6 
6 5 4 3 3 3 3 3 4 5 6 
6 5 4 3 2 2 2 3 4 5 6 
6 5 4 3 2 1 2 3 4 5 6 
6 5 4 3 2 2 2 3 4 5 6 
6 5 4 3 3 3 3 3 4 5 6 
6 5 4 4 4 4 4 4 4 5 6 
6 5 5 5 5 5 5 5 5 5 6 
6 6 6 6 6 6 6 6 6 6 6


*/

int main() {
    int n;
    cout << "enter n : ";
    cin >> n;

    int i = 0;
    while (i<=2*n-2) {
        int j = 0;
        while (j<=2*n-2) {
            int top = i;
            int bottom = 2*n-2-i;
            int left = j;
            int right = 2*n-2-j;

            int distance = min({top, bottom, left, right});
            cout << n-distance;
            j++;

        }
        cout << endl;
        i++;
    }
}