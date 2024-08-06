#include <iostream>
#include<list>
using namespace std;


/*
why list?
because to insert to front in vector you need to perform insert() operation
which is very costly and list provides push_front(), emplace_front() out of the box.

- vector implements singly linked list.
- list implements doublu linked list.
*/

void explainList() {
    list<int> ls;

    ls.push_back(2);  // {2}
    ls.emplace_back(4); // {2, 4}
    
    ls.push_front(5); // {5, 2, 4}
    ls.emplace_front(9); // {9, 5, 2, 4}

    // rest functions same as vector
    // begin, end, rbegin, rend, insert, size, swap

}

int main() {
    
}