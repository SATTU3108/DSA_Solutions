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

// Brute-force approach
Node *deleteNthNodeFromEnd(Node *head,int N) {
    if (head==NULL) return NULL;
    int count=0;
    Node *temp=head;
    while (temp!=NULL) {
        count++;
        temp=temp->next;
    }
    if (count==N) {
        Node *newHead=head->next;
        delete head;
        return newHead;
    }
    int res=count-N;
    temp=head;
    while (temp!=NULL) {
        res--;
        if (res==0) break;
        temp=temp->next;
    }
    Node *delNode=temp->next;
    temp->next=delNode->next;
    delNode->next=NULL;
    delete delNode;
    return head;
}
//time:O(L)+O(L-N),space:O(1)

// Efficient Approach 
Node *deleteNthNodeFromEnd(Node *head,int N) {
    Node *fast=head,*slow=head;
    for (int i=0;i<N;i++) fast=fast->next;
    if (fast==NULL) {
        Node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    while (fast->next!=NULL) {
        fast=fast->next;
        slow=slow->next;
    }
    Node *delNode=slow->next;
    slow->next=delNode->next;
    delNode->next=NULL;
    delete delNode;
    return head;
}
//time complexlity:O(N),space:O(1)