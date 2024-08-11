#include <iostream>
using namespace std;

string sayDigits(int n) {
    //base case:
    string digits[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    if (n==0) return "";
    int digit = n%10;
    return (sayDigits(n/10) + " " + digits[digit]);

}


int main() {
    int n = 130;
    cout << sayDigits(n) << endl;
}