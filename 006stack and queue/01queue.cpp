#include <bits/stdc++.h>
using namespace std;


class Queue {
public:
    int start;
    int end;
    int maxSize;
    int * arr;
    int currSize;

    Queue(int size){
        start = 0;
        end = -1;
        maxSize =size;
        arr = new int[size];
        currSize = 0;
    }

    void push(int x) {
        if(currSize == maxSize) cout << "queue full!" << endl;
        else {
            arr[(end+1)%maxSize] = x;
            end = (end+1)%maxSize;
            currSize++;
            end++;
            // if(start == -1) start = 0;
        }
    }

    void pop() {
        if(currSize == 0) cout << "queue empty!" << endl;
        else {
            start = (start+1)%maxSize;
            currSize--;
            if(currSize == 0) {
                start = -1;
                end = -1;
            }
        }
    }

    int size() {
        return currSize;
    }

    int top() {
        return arr[start];
    }
};

int main() {
    Queue q(4);

    q.push(3);
    q.push(4);
    q.push(7);
    q.push(7);
    q.push(7);
    q.pop();
    int s = q.size();
    cout << s << endl;

}