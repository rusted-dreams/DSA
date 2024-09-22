class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        vector<int> word2Count(26, 0);
        for (char c : word2) {
            word2Count[c - 'a']++;
        }
        
        long long result = 0;
        vector<int> windowCount(26, 0);
        
        for (int right = 0; right < n; right++) {
            windowCount[word1[right] - 'a']++;
            
            int left = right - m + 1;
            if (left >= 0) {
                bool isValid = true;
                for (int i = 0; i < 26; i++) {
                    if (windowCount[i] < word2Count[i]) {
                        isValid = false;
                        break;
                    }
                }
                
                // 4eacfe1f29
                
                if (isValid) {
                    result += left + 1;
                }
                
                windowCount[word1[left] - 'a']--;
            }
        }
        
        return result;
    }
};