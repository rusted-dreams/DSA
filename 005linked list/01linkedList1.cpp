// convert an array to a linked list {10, 20, 30, 40, 50}

#include <iostream>
#include<vector>
using namespace std;


// defining a linked list:
struct Node {
    int data;
    Node* next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    Node(int data, Node* &next){
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

// remove the tail of the linkList:
Node* deleteTail(Node* &head){
    Node* temp = head;
    if(head->next == NULL) {
        delete(temp);
        return NULL;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// delete Kth node of the LL:
/*
 - if k = 1, delete the head
 - if k > length(LL), delete nothing
 - if k->next = null, delete tail
 - else delete the node k
*/
Node* deleteNode(Node* &head, int k) {
    Node* temp = head;
    Node* prev = NULL;
    if (head == NULL || head->next == NULL) return NULL;
    if(k==1) {
        head = head->next;
        free(temp);
        return head;
    }
    int count = 0;
    while(temp != NULL) {
        count++;
        if(count == k) {
            prev->next = prev->next->next;
            delete(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// deleting a given value in a linked list:
Node* deleteValue(Node* &head, int key) {
    Node* temp = head;
    Node* prev = NULL;
    if (head == NULL || head->next == NULL) return NULL;
    if(head->data==key) {
        head = head->next;
        free(temp);
        return head;
    }
    while(temp != NULL) {
        if(temp -> data == key) {
            prev->next = prev->next->next;
            delete(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
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

// Insertion in linkedList:

// insertion at head:
Node* insertAtHead(Node* &head, int val){
    Node* newNode = new Node(val, head);
    return newNode;
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

// insert at any position k:
Node* insertAtPosition(Node* &head, int k, int val) {
    if(head == NULL && k == 1) return new Node(val);

    if(k==1) {
        Node* newNode = new Node(val, head);
        return newNode;
    }
    Node* temp = head;
    int count = 1;
    while(temp){
        count++;
        if(count == k){
            Node* newNode = new Node(val, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}


// insert an element before any given value x:
Node* insertBeforeX(Node* &head, int x, int val){
    if(head == NULL) return head;
    if(head->data == x) return new Node(val, head);
    Node* temp = head;
    while(temp->next->data != x){
        temp = temp->next;
    }
    Node* newNode = new Node(val, temp->next);
    temp->next = newNode;
    return head;
}

int main() {
    vector<int> arr = {20, 30, 40, 50, 60};

    Node* linkList = arrToLinkedList(arr);
    printLinkList(linkList);
    cout << endl;
    cout << endl << "lenght of LinkList: " << lengthOfLL(linkList) << endl;
    cout << endl << "search for 40 & 90 in the linkList: " << searchElement(linkList, 40) << ", " << searchElement(linkList, 90)<< endl;

    cout << endl <<" # INSERTION IN LINKED LIST :" << endl << endl;
    cout << "insert at head: ";
    linkList = insertAtHead(linkList, 10);
    printLinkList(linkList);

    insertAtTail(linkList, 70);
    cout<< "inserting 60 (a new node) at tail: ";
    printLinkList(linkList);

    cout << "insert a val at a position k: ";
    linkList = insertAtPosition(linkList, 3, 25);
    printLinkList(linkList);

    cout << "inserting a element before a value x: ";
    linkList = insertBeforeX(linkList, 40, 35);
    printLinkList(linkList);

    cout << endl << " # DELETION IN LINKED LIST: " << endl << endl;

    deleteTail(linkList);
    cout << "deleting tail which is 70: ";
    printLinkList(linkList);

    cout << "delete kth element: ";
    deleteNode(linkList, 3);
    printLinkList(linkList);

    cout << "delete a value from link list: ";
    deleteValue(linkList, 60);
    printLinkList(linkList);
}