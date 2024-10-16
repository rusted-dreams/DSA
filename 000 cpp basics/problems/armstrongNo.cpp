#include <iostream>
#include<cmath>
using namespace std;

bool armstrong(int num){
    int n = (int) (log10(num)+1);
    int temp = num;
    int sum = 0;
    while(temp>0) {
        sum += pow(sum%10, n);
        temp /= 10;
    }
    if(sum == num) return true;
    return false;
}

int main() {
    
}