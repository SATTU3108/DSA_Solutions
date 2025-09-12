#include <bits/stdc++.h>
using namespace std;

/*
Given a string s representing an expression containing various types of brackets: {}, (), and [], the task is to determine whether the brackets in the expression are balanced or not. A balanced expression is one where every opening bracket has a corresponding closing bracket in the correct order.
*/

// Approach 1 -> Stacks
bool isBalanced(const string &s) {
    stack<char> st;
    for (int i=0;i<s.length();i++) {
        if (s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
        else {
            if (!st.empty() && ((st.top()=='(' && s[i]==')') || (st.top()=='{' && s[i]=='}') || (st.top()=='[' && s[i]==']'))) st.pop();
            else return false;
        }
    }
    return (st.empty());
} 
//time:O(n),space:O(n)

// Approach 2 -> Treating string as stack
bool checkMatch(char c1,char c2) {
    if (c1=='(' && c2==')') return true;
    if (c1=='{' && c2=='}') return true;
    if (c1=='[' && c2==']') return true;
    return false;
}
bool isBalanced(string &s) {
    int top=-1;
    for (int i=0;i<s.length();i++) {
        if (top<0 || !checkMatch(s[top],s[i])) {
            top++;
            s[top]=s[i];
        }
        else top--;
    }
    return (top==-1);
}