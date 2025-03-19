// problem - 103. Binary Tree Zigzag Level Order Traversal
// link - https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

#include <bits/stdc++.h>
using namespace std;


//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) { }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) { }
};


class Solution {
public:
    // Function to perform Zigzag Level Order Traversal (BFS-based)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res; // Stores final zigzag order
        bool flag = false; // Controls direction of traversal (false = left->right, true = right->left)

        if (root == NULL) return res; // Edge case: Empty tree

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            // Process all nodes at the current level
            while (size) {
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp->val);

                if (temp->left != NULL) q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);

                size--;
            }

            if (flag) reverse(level.begin(), level.end()); // Reverse order for alternate levels
            flag = !flag; // Toggle flag for next level
            res.push_back(level);
        }

        return res;
    }
};


int main() {
    Solution sol;

}