/*
A number is represented in linked list such that each digit corresponds to a node in linked list. The task is to add 1 to it.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node (int x) {
        data=x;
        next=NULL;
    }
};

Node *reverse(Node *head) {
    Node *curr=head,*prev=NULL;
    while (curr!=NULL) {
        Node *front=curr->next;
        curr->next=prev;
        prev=curr;
        curr=front;
    }
    return prev;
}
Node *addOneToReversed(Node *head) {
    Node *curr=head;
    int carry=1;
    while (curr!=NULL) {
        int sum=carry+curr->data;
        curr->data=sum%10;
        carry=sum/10;
        if (carry==0) break;
        if (curr->next==NULL && carry>0) {
            curr->next=new Node(carry);
            carry=0;
        }
        curr=curr->next;
    }
    return head;
}
Node *addOne(Node *head) {
    head=reverse(head);
    head=addOneToReversed(head);
    return reverse(head);
}