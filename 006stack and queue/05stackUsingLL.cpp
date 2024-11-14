// problem link - https://www.geeksforgeeks.org/problems/implement-stack-using-linked-list/1
// implement stack using linked list


#include<bits/stdc++.h>
using namespace std;

struct StackNode {
    int data;
    StackNode *next;

    StackNode(int a) {
        data = a;
        next = NULL;
    }
};

class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        StackNode *temp = new StackNode(x);
        if(top == NULL) {
            top = temp;
        }
        else{
            temp->next = top;
            top = temp;
        }
    }

    int pop() {
        if(top == NULL) return NULL;
        StackNode* temp = top;
        top = top->next;
        int ans = temp->data;
        delete(temp);
        return ans;
    }

    MyStack() { top = NULL; }
};


