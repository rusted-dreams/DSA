// problem - 543. Diameter of Binary Tree
// link - https://leetcode.com/problems/diameter-of-binary-tree/

#include <bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) { }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) { }
};


class Solution {
    // Helper function to compute depth and update diameter in a single pass
    int findDepth(TreeNode* root, int& diameter) {
        if (root == NULL) return 0;

        int leftDepth = findDepth(root->left, diameter);
        int rightDepth = findDepth(root->right, diameter);

        // Update diameter at each node
        diameter = max(diameter, leftDepth + rightDepth);

        // Return depth of this node
        return 1 + max(leftDepth, rightDepth);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        findDepth(root, diameter);
        return diameter;
    }

};


// redundant depth calculation
// class Solution {
//     // Helper function to find the depth (or height) of a binary tree
//     // Depth of a node is the maximum depth of its left or right subtree + 1
//     int findDepth(TreeNode* root) {
//         if (root == NULL) return 0; // Base case: If node is null, depth is 0
//         return 1 + max(findDepth(root->left), findDepth(root->right)); 
//     }

// public:
//     int diameter = 0; // Global variable to store the maximum diameter found

//     // Function to compute the diameter of the binary tree
//     int diameterOfBinaryTree(TreeNode* root) {
//         if (root == NULL) return 0; // Base case: If tree is empty, diameter is 0

//         // Diameter at the current node = sum of left and right subtree depths
//         int currDia = findDepth(root->left) + findDepth(root->right);

//         // Update the maximum diameter found so far
//         diameter = max(diameter, currDia);

//         // Recursively check for left and right subtrees
//         diameterOfBinaryTree(root->left);
//         diameterOfBinaryTree(root->right);

//         return diameter; // Return the final computed diameter
//     }
// };


int main() {
    Solution sol;

}