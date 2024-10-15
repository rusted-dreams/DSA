#include <iostream>
#include<set>
#include<unordered_set>
using namespace std;



void explainSet() {
    // implemented using tree.
    // every operation take O(logN);

    set<int> st;
    st.insert(1);
    st.emplace(2);
    st.insert(2);
    st.insert(4);
    st.insert(3); 

    // Functionality of insert in vector
    // can be also, that only increases
    // efficiency

    // begin(), end(), rbegin(), rend(), size(),
    // empty(), and swap() are same as those of above
    
    // {1, 2, 3, 4, 5}
    auto it = st.find(3);

    // {1, 2, 3, 4, 5}
    auto it = st.find(6);

    // {1, 4, 5}
    st.erase(5); // erases 5, takes logarithmic time

    int cnt = st.count(1);

    auto it = st.find(3);
    st.erase(it); // it takes constant time

    // {1, 2, 3, 4, 5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2); // after erase {1, 4, 5} [first, last)

    // lower_bound() and upper_bound() funcction works in the same way
    // as in vector it does.

    // This is the syntax
    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);
}

void explainMultiSet() {
    // everything is same as set
    // stores duplicate elements too.

    multiset<int> ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1, 1}
    ms.insert(1); // {1, 1, 1}

    ms.erase(1); // all 1's erased

    int cnt = ms.count(1);

    // only a single one erased
    ms.erase(ms.find(1));

    // Erasing a specific range (without incorrect pointer arithmetic)
    auto it1 = ms.find(1);
    auto it2 = next(it1, 2); // advance iterator by 2 positions
    ms.erase(it1, it2);    // rest all function same as set
}

void explainUnorderedSet() {
    unordered_set<int> st;
    // all operations are mostly O(1) 
    //except lower_bound and Upper_bound funcition in worst case it goes O(N).

    // lower_bound and upper_bound function
    // does not works, rest all functions are same
    // as above, it does not stores in any
    // particular order it has a better complexity
    // than set in most cases, except some when collision happens
}

int main() {
    
}