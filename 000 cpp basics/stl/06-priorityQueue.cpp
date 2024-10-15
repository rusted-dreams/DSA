#include <iostream>
#include<queue>
using namespace std;

void exlainPQ(){

    /*
    push - O(logN)
    top -> O(1)
    pop -> O(logN)
    */
    priority_queue<int> pq;

    pq.push(5); // {5}
    pq.push(2); // {5, 2}
    pq.push(8); // {8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2}

    cout << pq.top(); 

    pq.pop();

    cout << pq.top();

    // size swap empty functions same as others

    // min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5); // {5}
    pq.push(2); // {2, 5}
    pq.push(8); // {2, 5, 8}
    pq.emplace(10); // {2, 5, 8, 10}

    cout << pq.top(); // prints 2
}

int main() {
    
}