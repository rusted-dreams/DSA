// 328. Odd Even Linked List
// link - https://leetcode.com/problems/odd-even-linked-list/description/


#include <iostream>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return head;

        ListNode* temp = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        while(even!=NULL && even->next != NULL){
            temp->next = even->next;
            temp = temp ->next;
            even->next = temp->next;
            even = even->next;
        }
        temp->next = evenHead;
        return head;
    }
};