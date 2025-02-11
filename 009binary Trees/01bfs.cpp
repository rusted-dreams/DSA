// problem - 102. Binary Tree Level Order Traversal
// link - https://leetcode.com/problems/binary-tree-level-order-traversal/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;  // Stores the final level order traversal result
        if(root == NULL) return res;  // Return empty if tree is empty
        
        queue<TreeNode*> q;  // Queue for BFS traversal
        q.push(root);  // Start with the root node
        
        while(!q.empty()) {
            vector<int> level;  // Stores values of the current level
            int n = q.size();  // Number of nodes at the current level
            
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();  // Get the front node
                q.pop();
                
                // Push children into the queue for the next level
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                
                level.push_back(node->val);  // Store current node's value
            }
            
            res.push_back(level);  // Add the level to the result
        }
        
        return res;
    }
};


int main() {
    Solution sol;
    
}