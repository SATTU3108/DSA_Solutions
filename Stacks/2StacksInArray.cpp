#include <bits/stdc++.h>
using namespace std;

/*
Create a data structure twoStacks that represent two stacks. Implementation of twoStacks should use only one array, i.e., both stacks should use the same array for storing elements. 
*/

// Naive Approach -> Dividing space into two halves
class twoStacks {
    int* arr;
    int size;
    int top1,top2;
    public:
        twoStacks(int n) {
            size=n;
            arr=new int[n];
            top1=n/2+1;
            top2=n/2;
        }
        void push1(int x) {
            if (top1<size) {
                top1++;
                arr[top1]=x;
            }
            else cout<<"Stack Overflow for stack1"<<endl;
        }
        void push2(int x) {
            if (top2>=0) {
                top2--;
                arr[top2]=x;
            }
            else cout<<"Stack Overflow for stack2"<<endl;
        }
        int pop1() {
            if (top1>size/2) {
                int x=arr[top1];
                top1--;
                return x;
            }
            else return -1;
        }
        int pop2() {
            if (top2<size/2) {
                int x=arr[top2];
                top2++;
                return x;
            }
            else return -1;
        }
};

// Efficient Approach 
class twoStacks {
    int* arr;
    int size;
    int top1,top2;
    public:
        twoStacks(int n) {
            size=n;
            arr=new int[n];
            top1=-1;
            top2=n;
        }
        void push1(int x) {
            if (top1<(top2-1)) {
                top1++;
                arr[top1]=x;
            }
        }
        void push2(int x) {
            if (top1<(top2-1)) {
                top2--;
                arr[top2]=x;
            }
        }
        int pop1() {
            if (top1>=0) {
                int x=arr[top1];
                top1--;
                return x;
            }
            else return -1;
        }
        int pop2() {
            if (top2<size) {
                int x=arr[top2];
                top2++;
                return x;
            }
            else return -1;
        }
};