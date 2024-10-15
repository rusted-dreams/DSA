#include <iostream>
#include <vector>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int* arr = new int[n];
        for(int i=0; i<n; i++) {
            cin >>  arr[i];
        }
        int partial = 0;
        int ans = 0;
        int maxi = INT32_MIN;
        vector<int> maxIndex;
        for(int i=0; i<n; i++){
            if(arr[i]> maxi) {
                maxi = arr[i];
            }
        }
        for(int i=0; i<n; i++){
            if(arr[i]= maxi) {
                maxIndex.push_back(i);
            }
        }

        for(int i=0; i<maxIndex.size(); i++){
            if(maxIndex[i]%2 == 0){
                partial = maxi + (n/2)+1;
            }
            else {
                partial = maxi + n/2;
            }
            if(partial >ans) {
                ans = partial;
            }
        }
        cout << ans << endl;
    }
}