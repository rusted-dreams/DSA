#include <iostream>
#include<vector>
using namespace std;


//dynamic size. - solves the issue of array's fixed size;
/*
size increases - how?
    suppose a vector of size 5 is full and you try to insert an item, so it will double the size of the vector and push the item at the back,
    i.e now the vector size is 10 and it appends the new item at index 5. 
*/
void explainVectors() {
    
    vector<int> v;
    v.push_back(69);
    v.emplace_back(420);

    vector<pair<int, int>> v2;
    v2.push_back({6, 9});
    v2.emplace_back(1, 0); // no need to give {} - braces automatically assumes to be a pair.

    vector<int> v3(5, 69); // initializes a vector v3 of size 5 and all values as 69 by default;
    vector<int> v4(5); // initializes with 0 or garbage values (compiler dependent)!

    // copying a vector:
    // this creates a copy of vector v3:
    vector<int> v3Copy(v3); // v3Copy is a copy of the vector v3.

    // accessing vector items:
    cout << v[0] << " or " << v.at(1) << endl;


    // or using the iterator:
    vector<string> fruits = {"apple", "melons", "mango", "peach", "litchi"};
    vector<string>::iterator fruit = fruits.begin();   // fruit is pointing to the memory address of fruits[0].
    fruit++;
    
    cout << *fruit << " "; // prints melons,  * is called de-reference operator, consider learning pointers.
    fruit += 2;
    cout << *fruit << " "; //prints peach
    cout <<endl << "-----------------------------------"<< endl; 


    // iterators other than begin():
    vector<int> vec = {10, 20, 30, 40, 50, 60};

    vector<int>::iterator it = vec.end();      // points to the address block just next to the last element of vec. and to get the last element of the vector we need to do it--.
    // vector<int>::iterator it = vec.rend();     // - reverse-end : points to the first element address.
    // vector<int>::iterator it = vec.rbegin();   // - revese-begin : points to the address block of the last element and doing it++ points to second last element.


    // printing vector items:
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
        cout << *(it) << " ";
    }
    cout <<endl << "-----------------------------------"<< endl; 

    for(auto it = vec.begin(); it != vec.end(); it++) {
        cout << *(it) << " ";
    }
    cout <<endl << "-----------------------------------"<< endl; 

    for(auto it : vec) {
        cout << it << " ";
    }
    cout <<endl << "-----------------------------------"<< endl; 



    // deletion in vector:
    
    // {10, 20, 30, 40, 50, 60}
    vec.erase(vec.begin()+1); // => {10, 30, 40, 50, 60}

    //{10, 20, 30, 40, 50, 60}
    vec.erase(vec.begin()+2, vec.begin()+4); // => {10, 20, 50, 60} i.e. end index is exclusive => range = [start, end).


    // INSERTION IN VECTORS:
    vector<int> v10(2, 100); // {100, 100}
    v10.insert(v10.begin(), 300); // {300, 100, 100} insert at an index.
    v10.insert(v10.begin() + 1, 2, 10); // {300, 10, 10, 100, 100} insert(start, no._of_element, element)

    vector<int> temp(2, 50); //insertion of a vector into another vector:
    v10.insert(v10.begin(), temp.begin(), temp.end()); // {50, 50, 300, 10, 10, 100, 100}

    // {50, 50, 300, 10, 10, 100, 100}
    cout << v10.size(); // 7
    v10.pop_back();     //{50, 50, 300, 10, 10, 100}


    vector<int> a = {10, 20};
    vector<int> b = {30, 40};

    a.swap(b); // a-> {30, 40}, b -> {10, 20}

    a.clear(); //erases the entire vector 

    cout << v.empty(); // is vector empyty? -> true/false.
}


int main() {
    explainVectors();
}