// problem link - https://www.geeksforgeeks.org/problems/implement-queue-using-linked-list/1
// Implement Queue using Linked List


#include<bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};


void MyQueue:: push(int x)
{
    QueueNode* temp = new QueueNode(x);
    if(front == NULL && rear == NULL) {
        front = temp;
        rear = temp;
    }
    else{
        rear ->next = temp;
        rear = temp;
    }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
    if(front == NULL) return -1;
    else{
        QueueNode * temp = front;
        int ans = front->data;
        if(front->next == NULL){
            front = NULL;
            rear = NULL;
            return ans;
        }else{
            front = front->next;
            delete temp;
            return ans;
        }
    }
    
}