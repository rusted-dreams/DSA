#include <iostream>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t) {
        t--;
        int a;
        int b;
        string result = "";
        cin >> a >> b;
        if(a%2 == 0 && b%2 == 0) {
            result = "yes";
        }
        else if(a>=2 && a%2 ==0) {
            result = "yes";
        }
        else {
            result = "no";
        }
        cout << result << endl;

    }
}