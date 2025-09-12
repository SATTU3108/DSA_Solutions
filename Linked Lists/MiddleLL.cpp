#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node (int x) {
            data=x;
            next=nullptr;
        }
};

/*
Given the head of a linked list of integers, determine the middle node of the linked list. However, if the linked list has an even number of nodes, return the second middle node.
*/

Node* findMiddle(Node *head) {
    if (head==NULL || head->next==NULL) return head;
    Node *temp=head;
    int count=0;
    while (temp!=NULL) {
        count++;
        temp=temp->next;
    }
    int mid=count/2+1;
    temp=head;
    while (temp!=NULL) {
        mid=mid-1;
        if (mid==0) break;
        temp=temp->next;
    }
    return temp;
}
//time:O(n+n/2)
//space:O(1)

Node* findMiddle(Node* head) {
    Node* slow=head;
    Node* fast=head;
    while (fast!=NULL && fast->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
//time:O(n/2) -> requires only 1 traversal
//space:O(1)