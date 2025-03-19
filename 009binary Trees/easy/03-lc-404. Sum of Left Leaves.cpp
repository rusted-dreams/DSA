// problem - 404. Sum of Left Leaves
// link - https://leetcode.com/problems/sum-of-left-leaves/

#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) { }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) { }
};


class Solution {
    // Helper function to recursively sum left leaf nodes
    int helper(TreeNode* root, bool isLeft) {
        if (root == NULL) return 0;  // Base case: If node is NULL, return 0

        // If current node is a left leaf, add its value to the sum
        if (root->left == NULL && root->right == NULL && isLeft) return root->val;

        // Recursively check left and right subtrees
        return helper(root->left, true) + helper(root->right, false);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false); // Root itself is not a left leaf
    }
};


int main() {
    Solution sol;

}