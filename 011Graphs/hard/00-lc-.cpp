// problem - 127. Word Ladder
// link - https://leetcode.com/problems/word-ladder/

#include <bits/stdc++.h>
using namespace std;

// Approach: BFS (Breadth-First Search)
// Intuition: Each word is a node. An edge exists between two words if they differ by one character.
// Start BFS from beginWord and try transforming one character at a time.
// If a transformed word is in the wordList (treated as a set for O(1) lookup), it's a valid edge.
// The level (steps) in BFS represents the transformation sequence length.
// The first time we reach endWord, we return the number of steps taken.

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end()); // Set for fast lookup
        queue<pair<string, int>> q; // Queue stores current word and steps taken
        q.push({ beginWord, 1 }); // Start with beginWord and 1 step
        st.erase(beginWord); // Remove to avoid revisiting

        while (!q.empty()) {
            string word = q.front().first; // Current word
            int steps = q.front().second;  // Steps taken so far
            if (word == endWord) return steps; // Found the target word
            q.pop();

            for (int i = 0; i < word.size(); i++) {
                string original = word; // Backup original word
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch; // Try all possible one-letter transformations
                    if (st.find(word) != st.end()) {
                        q.push({ word, steps + 1 }); // Valid transformation, add to queue
                        st.erase(word); // Mark as visited
                    }
                }
                word = original; // Restore original word for next position
            }
        }
        return 0; // No valid transformation sequence found
    }
};


int main() {
    Solution sol;

}