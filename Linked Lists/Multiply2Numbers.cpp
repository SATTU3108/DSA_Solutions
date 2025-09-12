#include <bits/stdc++.h>
using namespace std;
long long MOD=1e9+7;

class Node {
    public:
        int data;
        Node *next;
        Node (int x) {
            data=x;
            next=NULL;
        } 
};

/*
Given two numbers represented by linked lists, The task is to return the multiplication of these two linked lists.
*/

long long multiplyTwoLists(Node *first,Node *second) {
    long long num1=0,num2=0;
    // First number
    while (first!=NULL) {
        num1=(num1*10+first->data)%MOD;
        first=first->next;
    }
    // SEcond number
    while (second!=NULL) {
        num2=(num2*10+second->data)%MOD;
        second=second->next;
    }
    return (num1*num2)%MOD;
}
//time:O(max(n1,n2)),space:O(1)