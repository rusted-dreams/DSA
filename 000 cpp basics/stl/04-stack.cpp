#include <iostream>
#include<stack>
using namespace std;


/*
LIFO - last in first out.

- indexing not available in stack.

time complexity of stack operation:
    O(1)
*/


void explainStack() {
    stack<int> st;
    st.push(1); // {1}
    st.push(2); // {2, 1}
    st.push(3); // {3, 2, 1}
    st.push(3); // {3, 3, 2, 1}
    st.emplace(5); // {5, 3, 3, 2, 1}

    cout<< st.top() << endl;  // prints 5 "** st[2] is invalid **"
    st.pop(); // st looks like {3, 3, 2, 1}

    cout << st.top(); // 3
    cout << st.size(); // 4
    cout << st.empty(); //false

    stack<int> st1, st2;
    st1.swap(st2);

    


}


int main() {
    
}