class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 1, right = (long long)(*min_element(workerTimes.begin(), workerTimes.end())) * mountainHeight * (mountainHeight + 1) / 2;
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (canReduceHeight(mid, mountainHeight, workerTimes)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    bool canReduceHeight(long long time, int mountainHeight, const vector<int>& workerTimes) {
        long long totalReduction = 0;
        for (int workerTime : workerTimes) {
            long long reduction = 0;
            long long currentTime = 0;
            for (int i = 1; i <= mountainHeight; ++i) {
                currentTime += (long long)workerTime * i;
                if (currentTime > time) break;
                reduction = i;
            }
            totalReduction += reduction;
            if (totalReduction >= mountainHeight) return true;
        }
        return false;
    }
};