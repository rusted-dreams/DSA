#include<iostream>
#include<utility>
using namespace std;


//Pair - in utility library
void explainPair() {
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << endl;

    pair<int, int> p3;
    p3.first = 69;
    p3.second = 420;

    pair<int, pair<int, int>> p2 = {1, {2, 3}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second << endl;

    pair<int, int> arr[] = { {1, 2}, {3, 4}, {6, 9} };
    cout << arr[1].second << endl;
}

int main() {
    explainPair();
}