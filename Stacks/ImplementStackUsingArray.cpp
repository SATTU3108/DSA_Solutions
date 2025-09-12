#include <bits/stdc++.h>
using namespace std;

class Stack {
    int top,cap;
    int *a;
    public:
        Stack(int cap) {
            this->cap=cap;
            top=-1;
            a=new int[cap];
        }
        ~Stack() {
            delete[] a;
        }
        bool push(int x) {
            if (top>=(cap-1)) {
                cout<<"Stack Overflow"<<endl;
                return false;
            }
            top++;
            a[top]=x;
            return true;
        }
        int pop() {
            if (top<0) {
                cout<<"Stack Underflow"<<endl;
                return 0;
            }
            int x=a[top];
            top--;
            return x;
        }
        int peek() {
            if (top<0) {
                cout<<"Stack Underflow"<<endl;
                return 0;
            }
            return a[top];
        }
        bool isEmpty() {
            return (top<0);
        }
};