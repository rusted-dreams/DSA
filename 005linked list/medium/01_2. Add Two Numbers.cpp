// problem link : https://leetcode.com/problems/add-two-numbers/description/
// problem: 2. Add Two Numbers

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) { }
    ListNode(int x) : val(x), next(nullptr) { }
    ListNode(int x, ListNode* next) : val(x), next(next) { }
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* res = new ListNode();
        ListNode* temp3 = res;
        while (temp1 && temp2) {
            int val = (temp1->val + temp2->val + carry) % 10;
            carry = (temp1->val + temp2->val + carry) / 10;
            ListNode* node = new ListNode(val);
            temp3->next = node;
            temp3 = temp3->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while (temp1) {
            int val = (temp1->val + carry) % 10;
            carry = (temp1->val + carry) / 10;
            ListNode* node = new ListNode(val);
            temp3->next = node;
            temp3 = temp3->next;
            temp1 = temp1->next;
        }
        while (temp2) {
            int val = (temp2->val + carry) % 10;
            carry = (temp2->val + carry) / 10;
            ListNode* node = new ListNode(val);
            temp3->next = node;
            temp3 = temp3->next;
            temp2 = temp2->next;
        }
        if (carry != 0) {
            ListNode* node = new ListNode(carry);
            temp3->next = node;
        }
        return res->next;


    }
};



int main() {

}