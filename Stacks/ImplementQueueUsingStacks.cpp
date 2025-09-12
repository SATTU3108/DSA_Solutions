#include <bits/stdc++.h>
using namespace std;

// Making Enqueue operation costly
struct Queue {
    stack<int> s1,s2;
    void enqueue(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int dequeue() {
        if (s1.empty()) return -1;
        int x=s1.top();
        s1.pop();
        return x;
    }
};

// Making dequeue operation costly
struct Queue {
    stack<int> s1,s2;
    void enqueue(int x) {
        s1.push(x);
    }
    int dequeue() {
        if (s1.empty() && s2.empty()) return -1;
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x=s2.top();
        s2.pop();
        return x;
    }
};

// Implementing queue using only one stack