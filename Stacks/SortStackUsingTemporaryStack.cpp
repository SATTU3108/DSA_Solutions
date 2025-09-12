#include <bits/stdc++.h>
using namespace std;

/*
Given a stack of integers, sort it in ascending order using another temporary stack.
*/

stack<int> sortStack(stack<int> &input) {
    stack<int> tmpStack;
    while (!input.empty()) {
        int temp=input.top();
        input.pop();
        while (!tmpStack.empty() && tmpStack.top()<temp) {
            input.push(tmpStack.top());
            tmpStack.pop();
        }
        tmpStack.push(temp);
    }
}
//time:O(n^2),space:O(n)