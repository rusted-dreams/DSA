// problem -
// link - 

#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int a = x;
        vector<int> ans;
        int count = 0;
        unordered_set<int> st;
        int maxi = -1;
        int size = 0;
        if(n == 1) {
            cout << x << endl;
            continue;
        }
        ans.push_back(x & x-1);
        st.insert(x & x-1);
        int last = 0;
        while(x) {
            if(n - ans.size() > 1){
                if(x&1) {
                    ans.push_back(1<<count);
                    st.insert(1<<count);
                }
                count++;
                x>>1;
            }
            else{
                while(x) {
                    if(x&1){
                        if(1<<count != a & (a-1))
                            last = last | (1<<count);
                        count++;
                        x>>1;
                    }
                }
                ans.push_back(last);
            }
        }

        int num = 0;
        while(ans.size() < n ){
            if(st.find(num)==st.end() && num < maxi){
                ans.push_back(num);
                num++;
                // cout << num << " ";
            }
            else if(num >= maxi){
                ans.push_back(0);
                // cout << 0 << " ";
            } 
            size++;
            num++;
        }
        for(int i: ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}