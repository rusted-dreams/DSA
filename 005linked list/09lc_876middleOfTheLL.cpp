//link - https://leetcode.com/problems/middle-of-the-linked-list/description/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) { }
    ListNode(int x) : val(x), next(nullptr) { }
    ListNode(int x, ListNode* next) : val(x), next(next) { }
};

ListNode* middleNode(ListNode* head) {
    ListNode* middle = head;
    if (head->next == NULL) return head;
    ListNode* temp = head;
    while (temp->next != NULL && temp->next->next != NULL) {
        middle = middle->next;
        temp = temp->next->next;
    }
    if (temp->next) {
        middle = middle->next;
        temp = temp->next;
    }
    return middle;

}

int main() {

}