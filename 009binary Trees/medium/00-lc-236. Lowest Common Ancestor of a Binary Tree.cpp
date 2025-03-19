// problem - 236. Lowest Common Ancestor of a Binary Tree
// link - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include <bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};


class Solution {
public:
    // Function to find the Lowest Common Ancestor (LCA) of two nodes in a binary tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) return root; // If root is NULL or matches p/q, return root

        // Recursively find LCA in left and right subtrees
        TreeNode* leftMatch = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightMatch = lowestCommonAncestor(root->right, p, q);

        if (leftMatch == NULL) return rightMatch; // If LCA is in right subtree
        if (rightMatch == NULL) return leftMatch; // If LCA is in left subtree

        return root; // If both left and right found p and q, current root is LCA
    }
};


int main() {
    Solution sol;

}