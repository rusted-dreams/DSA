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

int main() {

    Node* node1 = new Node(55);
    cout << node1 -> data << endl;
    cout << node1 -> next << endl;

    Node* l1 = new Node(1);

    Node* head = l1;

    Node* l2 = new Node(2);

    l1 -> next = l2;    

}