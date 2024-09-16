#include <iostream>
#include<vector>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t){
        t--;
        int n;
        cin >> n;
        vector<string> beats(n);
        for(int i=0; i<n; i++) {
            cin >> beats[i];
        }

        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<4; j++){
                if(beats[i][j] == '#') {
                    cout << j+1 << " ";
                    break;
                }
            }
        }
        cout << endl;
    }
}