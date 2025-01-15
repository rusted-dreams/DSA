// problem - 1423. Maximum Points You Can Obtain from Cards
// link - https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

#include <bits/stdc++.h>
using namespace std;

// this is a constant sliding window problem.
int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size() - 1;
    int l = k - 1, r = n, score = 0;
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += cardPoints[i];
    }
    score = sum;
    for (l; l >= 0; l--) {
        sum -= cardPoints[l];
        sum += cardPoints[r];
        r--;
        score = max(score, sum);
    }
    return score;
}
int main() {

}