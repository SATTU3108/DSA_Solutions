#include <bits/stdc++.h>
using namespace std;

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
*/

class minStack {
    stack<pair<int,int>> st;
    public:
        void push(int x) {
            int min_element;
            if (st.empty()) min_element=x;
            else min_element=min(st.top().second,x);
            st.push({x,min_element});
        }
        void pop() {
            st.pop();
        }
        int top() {
            return st.top().first;
        }
        int getMin() {
            return st.top().second;
        }
};
//time:O(1),space:O(2N)