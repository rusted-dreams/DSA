#include <iostream>
#include<vector>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> people;
        int input;
        for(int i=0; i<n; i++) {
            cin >> input;
            people.push_back(input);
        }
        int robinGold = 0;
        int count = 0;
        for(int i=0; i<n; i++){
            if(people[i] >= k) {
                robinGold += people[i];
            }
            else if(people[i] == 0 && robinGold) {
                robinGold--;
                count++;
            }
        }
        cout << count << endl;
    }
}