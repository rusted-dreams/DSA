// problem - 901. Online Stock Span
// link - https://leetcode.com/problems/online-stock-span/

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
1. Maintain a stack (`st`) to keep track of indices of previous prices.
2. Use an array (`prices`) to store all the stock prices.
3. For each new price:
   - Pop elements from the stack while the top element’s price is **less than or equal** to the current price.
   - Compute the span as the difference between the current day and the top element of the stack.
   - If the stack is empty, the span is `day + 1` (meaning all previous days had lower prices).
   - Push the current day index onto the stack.
4. This ensures that for each price, we efficiently find the number of consecutive days with a lower or equal price.
*/

class StockSpanner {
public:
    vector<int> prices; // Stores historical prices
    stack<int> st; // Stores indices of previous prices
    int day; // Tracks the current day index
    
    StockSpanner() {
        day = -1; // Initialize day index
    }
    
    int next(int price) {
        day++;
        prices.push_back(price);
        
        // Pop elements that are <= current price
        while (!st.empty() && prices[st.top()] <= price) {
            st.pop();
        }
        
        // Calculate span
        int span = st.empty() ? day + 1 : day - st.top();
        
        // Push the current day index onto the stack
        st.push(day);
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


int main() {
    StockSpanner obj;
    
}