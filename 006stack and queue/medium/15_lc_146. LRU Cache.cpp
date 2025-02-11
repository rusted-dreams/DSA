// problem - 146. LRU Cache
// link - https://leetcode.com/problems/lru-cache/

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Use a doubly-linked list to maintain the order of usage (most recently used at the front).
- Use an unordered_map to achieve O(1) lookup for nodes by key.
- For get(key):
    * If the key exists, remove its node from the current position and move it to the front.
    * Return the value.
- For put(key, value):
    * If the key exists, update its value and move the node to the front.
    * If the key does not exist and the cache is at capacity, remove the node at the tail (least recently used) before inserting the new node at the front.
    * If there is still capacity, simply insert the new node at the front.
*/

class Node {
public:
    int key;    // The key stored in the node.
    int value;  // The value associated with the key.
    Node* prev; // Pointer to the previous node in the list.
    Node* next; // Pointer to the next node in the list.
    
    // Constructor: initializes the node with key, value, and optional prev/next pointers.
    Node(int key, int val, Node* prev = nullptr, Node* next = nullptr) {
        this->key = key;
        value = val;
        this->prev = prev;
        this->next = next;
    }
};

class LRUCache {
public:
    int capacity;    // Maximum capacity of the cache.
    int currSize;    // Current number of items in the cache.
    Node* head;      // Dummy head of the doubly-linked list.
    Node* tail;      // Dummy tail of the doubly-linked list.
    unordered_map<int, Node*> keys; // Hash map mapping keys to their corresponding node.
    
    // Constructor: initialize the cache with a given capacity and dummy head/tail nodes.
    LRUCache(int capacity) {
        this->capacity = capacity;
        currSize = 0;
        head = new Node(-1, -1);         // Dummy head.
        tail = new Node(-1, -1, head);     // Dummy tail linked to head.
        head->next = tail;
    }
    
    // Retrieve the value for the given key if it exists, else return -1.
    int get(int key) {
        if (keys.find(key) == keys.end())
            return -1;  // Key not found.
        else {
            Node* temp = keys[key];
            int res = temp->value;

            // Remove the node from its current position.
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;

            // Move the node to the front (right after the dummy head).
            temp->prev = head;
            temp->next = head->next;
            head->next->prev = temp;
            head->next = temp;
            return res;
        }
    }
    
    // Insert a new key-value pair or update an existing key.
    void put(int key, int value) {
        if (keys.find(key) != keys.end()) {
            // Key exists: update the value and move the node to the front.
            Node* temp = keys[key];

            // Remove node from its current position.
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            
            // Insert node right after the dummy head.
            temp->prev = head;
            temp->next = head->next;
            head->next->prev = temp;
            head->next = temp;
            temp->value = value;  // Update the value.
            keys[key] = temp;
        }
        else if (currSize == capacity) {
            // Cache is full: remove the least recently used node (node before dummy tail).
            Node* lru = tail->prev;
            keys.erase(lru->key);  // Remove key from hash map.

            // Remove the LRU node from the list.
            lru->next->prev = lru->prev;
            lru->prev->next = lru->next;
            delete lru;
            
            // Insert the new node at the front.
            Node* temp = new Node(key, value, head, head->next);
            head->next->prev = temp;
            head->next = temp;
            keys[key] = temp;
        }
        else {
            // There is available capacity: simply insert the new node at the front.
            Node* temp = new Node(key, value, head, head->next);
            head->next->prev = temp;
            head->next = temp;
            keys[key] = temp;
            currSize++;
        }
    }
};

/**
 * Usage:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key, value);
 */


int main() {

}