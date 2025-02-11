// problem - 
// link - 

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findCelebrity(vector<vector<int>>& people){
        int top = 0;
        int bottom = people.size()-1;
        while(bottom > top) {
            if(people[top][bottom] == 1){
                top++;
            }
            else if(people[bottom][top] == 1) {
                bottom--;
            }
            else if(people[top][bottom] == 0 && people[bottom][top] == 0) {
                top++;
                bottom--;
            }
        }
        bool isCeleb = true;
        for(int i=0; i<people.size(); i++) {
            if(top != i){
                if(people[top][i] == 1 || people[i][top] == 0) return -1;
            }
        }
        
        return top;
    }
};


int main() {
    Solution sol;
    
}