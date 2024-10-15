#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    Node *prev;
    int data;
    Node *next;
    Node(int data, Node *prev = NULL, Node *next = NULL)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

// traversal and printing in dll:
void printDLL(Node *&head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// arr to dll:
Node *arrToDLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i], temp);
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}

// deletion in DLL:
// delete kth node:
Node *deleteNode(Node *&head, int k)
{
    if (head == NULL)
        return head;
    if (head->next == NULL && k == 1)
    {
        delete (head);
        return NULL;
    }
    Node *temp = head;
    if (k == 1)
    {
        head = head->next;
        head->prev = NULL;
        delete (temp);
        return head;
    }
    int count = 0;
    while (temp != NULL)
    {
        count++;
        if (count == k)
        {
            Node *del = temp;
            // if k is not the last node:
            if (temp->next)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            // if k is last node:
            else
            {
                temp->prev->next = NULL;
            }
            temp = temp->next;
            delete (del);
            break;
        }
        temp = temp->next;
    }
    return head;
}

// insertion in DLL:

// insert a node after the pos node, (0 based indexing):
Node *addNode(Node *head, int pos, int data) {
        Node* node = new Node(data);
        if(pos == 0) {
            node->next = head;
            head->prev = node;
            return node;
        }
        Node* temp = head;
        for(int i=0; i<pos; i++){
            if(temp->next == NULL) return head;
            temp = temp->next;
        }
        node->prev = temp;
        if(temp->next != NULL){
            temp->next->prev = node;
            node->next = temp->next;
        }
        temp->next = node;
        return head;
    }

int main()
{
    Node *dll = arrToDLL({10, 20, 30, 40, 50, 60});
    printDLL(dll);

    cout << " # DELETION IN DLL: " << endl
         << endl;
    cout << " delete kth node: ";
    deleteNode(dll, 4);
    printDLL(dll);
    cout << endl;

    cout << " # INSERTION IN DLL" << endl;
    cout << " add 40 at 4th" << endl;
    addNode(dll, 2, 40);
    printDLL(dll);
}