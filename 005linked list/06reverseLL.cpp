#include <iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    Node(int data, Node* next=nullptr) {
        this -> data = data;
        this -> next = next;
    }
};


//iterative method
Node* reverseList(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    Node* tail = head;
    Node* prev = NULL;
    Node* temp = NULL;
    while(tail->next){
        temp = tail->next;
        tail->next = prev;
        prev = tail;
        tail = temp;
    }
    tail->next = prev;
    return tail;
}

// recursive Method:
Node* recursiveReverse(Node* head) {
    
}


int main() {
    
}