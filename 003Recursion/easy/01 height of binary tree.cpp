#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { };
};

TreeNode* createSampleTree() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
       /
      7

    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);

    return root;
}

int height(TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int main() {
    TreeNode* root = createSampleTree();
    int h = height(root);
    cout << h << endl;
}