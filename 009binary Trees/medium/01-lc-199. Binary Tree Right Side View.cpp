// problem - 199. Binary Tree Right Side View
// link - https://leetcode.com/problems/binary-tree-right-side-view/

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
public:
    // Function to get the right-side view of a binary tree (BFS Level Order Traversal)
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res; // Stores rightmost elements at each level
        queue<TreeNode*> q; // Queue for level-order traversal (BFS)

        if (root == NULL) return res; // Edge case: Empty tree

        q.push(root);
        while (!q.empty()) {
            int size = q.size(); // Get number of nodes at current level
            while (size) {
                TreeNode* temp = q.front();
                q.pop();

                // Push children into the queue
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);

                size--;
                if (size == 0) res.push_back(temp->val); // Last node in level = rightmost node
            }
        }
        return res;
    }
};


int main() {
    Solution sol;

}