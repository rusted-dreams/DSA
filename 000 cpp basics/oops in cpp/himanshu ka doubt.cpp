#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int data){
        this -> data = data;
        this -> next = nullptr;
    }
};

int main() {
    node h(3);
    cout << sizeof(h.data) << endl;
    cout << sizeof(h.next) << endl;
}