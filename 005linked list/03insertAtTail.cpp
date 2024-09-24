#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int data, Node* &next){
            this->data = data;
            this->next = next;
        }
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

Node* insertAtTail(Node* &head, int val) {
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

int main() {

    
    
}