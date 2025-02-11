// problem - 3439. Reschedule Meetings for Maximum Free Time I
// link - https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/

// was a contest problem...

#include <bits/stdc++.h>
using namespace std;

int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    vector<int> gaps;  // Stores gaps between consecutive events where free time is available
    int n = startTime.size();

    // If there is free time before the first event, add it as a gap
    if (startTime[0] > 0) gaps.push_back(startTime[0]);

    // Calculate gaps between consecutive events
    for (int i = 0; i < startTime.size() - 1; i++) {
        gaps.push_back(startTime[i + 1] - endTime[i]);
    }

    // If there is free time after the last event before eventTime ends, add it
    if (endTime[n - 1] < eventTime) gaps.push_back(eventTime - endTime[n - 1]);

    // Sliding window approach to find the maximum sum of 'k' consecutive gaps
    int i = 0, j = k;  // i = window start, j = window end
    int maxGap = 0;
    int gap = 0;

    // Initialize the first window (sum of first k gaps)
    for (int i = 0; i <= j && i < gaps.size(); i++) {
        gap += gaps[i];
    }
    maxGap = gap;

    // Slide the window across the remaining gaps
    j++;
    while (j < gaps.size()) {
        gap += gaps[j];  // Include the next gap in the window
        gap -= gaps[i];  // Remove the first gap of the previous window
        maxGap = max(gap, maxGap);  // Update max free time found
        i++;
        j++;
    }

    return maxGap;
}

int main() {

}