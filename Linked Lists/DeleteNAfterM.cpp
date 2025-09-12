#include <bits/stdc++.h>
using namespace std;

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
Given a linked list and two integers m and n, the task is to traverse the linked list such that you skip m nodes, then delete the next n nodes, and continue the same till end of the linked list.
*/

Node *skipMdeleteN(Node *head,int m,int n) {
    Node *curr=head,*t;
    while (curr!=NULL) {
        for (int i=1;i<m && curr!=NULL;i++) curr=curr->next;
        if (curr=NULL) return head;
        t=curr->next;
        for (int i=1;i<=n && t!=NULL;i++) {
            Node *temp=t;
            t=t->next;
            delete (temp);
        }
        curr->next=t;
    }
    return head;
}
//time:O(n),space:O(1)