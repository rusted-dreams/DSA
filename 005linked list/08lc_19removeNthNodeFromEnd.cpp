// link - https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) { }
    ListNode(int x) : val(x), next(nullptr) { }
    ListNode(int x, ListNode* next) : val(x), next(next) { }
};


ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* temp = head;
    if (head == NULL) return head;
    if (head->next == NULL) {
        delete(head);
        return NULL;
    }
    int len = 0;
    while (temp) {
        len++;
        temp = temp->next;
    }
    // cout << len<< endl;
    temp = head;
    int remove = len - n;
    if (remove == 0) {
        head = head->next;
        delete(temp);
        return head;
    }
    for (int i = 1; i < remove; i++) {
        temp = temp->next;
    }
    if (n == 1) {
        delete(temp->next);
        temp->next = NULL;
        return head;
    }
    ListNode* del = temp->next;
    temp->next = temp->next->next;
    delete(del);
    return head;
}


// delete in single traversal:
ListNode* removeNthFromEnd2(ListNode* head, int n) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return NULL;
    ListNode* tail = head;
    ListNode* del = head;


    for (int i = 1; i <= n; i++) {
        if (tail->next != NULL)
            tail = tail->next;
        else {
            head = head->next;
            delete(del);
            return head;
        }
    }

    while (tail->next != NULL) {
        del = del->next;
        tail = tail->next;
    }

    ListNode* temp = del->next;
    del->next = temp->next;
    temp->next = NULL;
    delete(temp);
    return head;
}
int main() {

}