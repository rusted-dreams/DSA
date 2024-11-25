// link - https://leetcode.com/problems/linked-list-cycle/
// detect loop in LL

#include <iostream>
#include<unordered_map>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) { }
};

// using hashing:
bool hasCycle(ListNode* head) {
    if (head == NULL || head->next == NULL) return NULL;
    unordered_map<ListNode*, int> mp;
    ListNode* temp = head;
    while (temp->next != NULL) {
        if (mp[temp] == 1) return temp;
        else {
            mp[temp]++;
            temp = temp->next;
        }
    }
    return NULL;
}



// using slow and fast pointer (optimal approach): 
bool hasLoop(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    // ListNode* temp = head;
    if (head == NULL || head->next == NULL) return false;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}



int main() {

}

