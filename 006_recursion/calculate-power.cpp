#include <iostream>
using namespace std;

int power(int a, int b) {
    if (b==1)
        return a;
    int small = power(a, b-1);
    int big = a*small;
    return big;

}


int main() {
    int ans = power(2, 3);
    cout << ans << endl;
}