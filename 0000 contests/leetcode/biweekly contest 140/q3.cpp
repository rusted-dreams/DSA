#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        vector<int> result;
        int idx = 0;  // Pointer for word1
        bool changeMade = false;  // To track if we've already made one change
        
        for (int i = 0; i < word2.length(); ++i) {
            char ch = word2[i];
            bool found = false;  // Track if we found a valid match in word1
            
            // Search for the lexicographically smallest valid index in word1 for current char in word2
            while (idx < word1.length()) {
                if (word1[idx] == ch) {
                    // Exact match, add the index to result
                    result.push_back(idx);
                    idx++;
                    found = true;
                    break;
                } else if (!changeMade) {
                    // Allow one mismatch to make word1 almost equal to word2
                    result.push_back(idx);
                    idx++;
                    found = true;
                    changeMade = true;  // Mark that we have used our one allowed change
                    break;
                }
                idx++;
            }
            
            // If no valid index was found, return an empty array
            if (!found) {
                return {};
            }
        }
        
        return result;
    }
};
