// problem - 
// link - 
#include <bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// depth first search:
// - preorder traversal  => root, left, right
// - inorder traversal   => left, root, right
// - postorder traversal => left, right, root




// Preorder Traversal (recursive):
class Solution {
public:
    void helper(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;
        ans.push_back(root->val);
        helper(root->left, ans);
        helper(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};

// without using the helper function:
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         if(root == NULL) return {};
//         vector<int> res;
//         res.push_back(root->val);
//         vector<int> left = preorderTraversal(root->left);
//         vector<int> right = preorderTraversal(root->right);
//         res.insert(res.end(), left.begin(), left.end());
//         res.insert(res.end(), right.begin(), right.end());
//         return res;
//     }
// };


// inorder Traversal:
class Solution {
public:
    void helper(TreeNode* root, vector<int>& ans) {
        if(root == NULL) return;

        helper(root->left, ans);
        ans.push_back(root->val);
        helper(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }
};

// postorder traversal:
class Solution {
public:
    void helper(TreeNode* root, vector<int>& res){
        if(root == NULL) return;
        helper(root->left, res);
        helper(root->right, res);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
        
    }
};



int main() {
    Solution sol; 
}