#include <iostream>
#include<vector>
using namespace std;

class Node{
public:
    Node *prev;
    int data;
    Node *next;
    Node(int data, Node *prev = NULL, Node *next = NULL){
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

void printDLL(Node *&head){
    Node *temp = head;
    while (temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *arrToDLL(vector<int> arr){
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++){
        Node *newNode = new Node(arr[i], temp);
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}

Node* reverseDLL(Node* head){
    Node* tail = head;
    Node* temp = tail;
    while(tail->next != NULL){
        tail = tail->next;
        temp->next = temp->prev;
        temp->prev = tail;
        temp = tail;
    }
    tail->next = tail->prev;
    tail->prev = NULL;
    return tail;
}

int main() {
    Node *dll = arrToDLL({10, 20, 30, 40, 50, 60});
    printDLL(dll);
    Node* ultaDLL = reverseDLL(dll);
    printDLL(ultaDLL);
}