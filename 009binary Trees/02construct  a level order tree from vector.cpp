// problem - Binary Tree Representation
// link - https://www.geeksforgeeks.org/problems/binary-tree-representation/1

#include <bits/stdc++.h>
using namespace std;

/*struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}*/

class Solution{
public:

    void create_tree(node* root0, vector<int> &vec){
        if(root0 == NULL) return;
        queue<node*> q;
        q.push(root0);
        int j= 1;
        while(j < vec.size()) {
            node* temp = q.front();
            q.pop();
            
            if(temp->left == NULL) {
                node* n = newNode(vec[j]);  // Ensure newNode is defined
                temp->left = n;
                q.push(n);
                j++;
            } 
            
            if(j < vec.size() && temp->right == NULL) {  // Ensure index is in bounds
                node* n = newNode(vec[j]);  
                temp->right = n;
                q.push(n);
                j++;
            }
        }
    }
};

int main() {
    Solution sol;
    
}