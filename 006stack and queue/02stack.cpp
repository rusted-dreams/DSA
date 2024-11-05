#include <bits/stdc++.h> 
using namespace std;

// solve using recursion
void ans(stack<int>& inputStack, int N, int count){

   // if it is the middle element then pop
   if(count == (N)/2) {
      inputStack.pop();
      return;
   }

   // if not the middle element, store it in temp and pop()
   int temp = inputStack.top();
   inputStack.pop();

   // recursively call the func with incrementing count
   ans(inputStack, N, count+1);
   inputStack.push(temp); // while backtracking push the temp again to the stack
}

void deleteMiddle(stack<int>&inputStack, int N){
	ans(inputStack, N, 0);
   
   
}