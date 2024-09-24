// convert an array to a linked list {10, 20, 30, 40, 50}

#include <iostream>
#include<vector>
using namespace std;


// defining a linked list:
struct Node {
    int data;
    Node* next;
    Node(int data, Node* next=nullptr){
        this -> data = data;
        this -> next = next;
    }
};

// convert a given arr to linkList:
Node* arrToLinkedList(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i=1; i<arr.size(); i++){
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}


// Link List traversal and printing:
void printLinkList(Node* &head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


// insert a new node at tail of LL:
Node* insertAtTail(Node* &head, int val) {
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

// LL traversal and count no. of nodes in LL:
int lengthOfLL(Node* &head){
    if(head == NULL) return 0;
    int count = 0;
    Node* temp = head;
    while(temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

// searching for an element in a LL:
bool searchElement(Node* &head, int key) {
    if(head == NULL) return false;
    Node* temp = head;
    while(temp) {
        if(temp->data == key) return true;
        temp = temp->next;
    }
    return false;

}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};

    Node* linkList = arrToLinkedList(arr);
    printLinkList(linkList);
    cout << endl;


    insertAtTail(linkList, 60);
    cout<< "inserting 60 (a new node) at tail" << endl;
    printLinkList(linkList);

    cout << endl << "lenght of LinkList: " << lengthOfLL(linkList) << endl;

    cout << endl << "search for 40 & 90 in the linkList: " << searchElement(linkList, 40) << ", " << searchElement(linkList, 90)<< endl;
}