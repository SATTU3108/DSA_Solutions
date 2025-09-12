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
Given a linked list of 0s, 1s and 2s, The task is to sort the list in non-decreasing order.
*/

// Approach-1
Node *sortList(Node *head) {
    vector<int> count(3,0);
    Node *temp=head;
    while (temp!=NULL) {
        count[temp->data]++;
        temp=temp->next;
    }
    int idx=0;
    temp=head;
    while (temp!=NULL) {
        if (count[idx]==0) idx++;
        else {
            temp->data=idx;
            count[idx]--;
            temp=temp->next;
        }
    }
    return head;
}

// Approach-2
Node *sortList(Node *head) {
    if (head==NULL || head->next==NULL) return head;
    Node *zeroStart=new Node(-1);
    Node *oneStart=new Node(-1);
    Node *twoStart=new Node(-1);
    Node *zeroEnd=zeroStart;
    Node *oneEnd=oneStart;
    Node *twoEnd=twoStart;
    Node *temp=head;
    while (temp!=NULL) {
        if (temp->data==0) {
            zeroEnd->next=temp;
            zeroEnd=zeroEnd->next;
        }
        else if (temp->data==1) {
            oneEnd->next=temp;
            oneEnd=oneEnd->next;
        }
        else {
            twoEnd->next=temp;
            twoEnd=twoEnd->next;
        }
        temp=temp->next;
    }
    if (oneStart->next!=NULL) zeroEnd->next=oneStart->next;
    else zeroEnd->next=twoStart->next;
    oneEnd->next=twoStart->next;
    twoEnd->next=NULL;
    head=zeroStart->next;
    delete zeroStart;
    delete oneStart;
    delete twoStart;
    return head;
}