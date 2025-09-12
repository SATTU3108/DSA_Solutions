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
Node *rotateRight(Node *head,int k) {
    if (head==NULL || head->next==NULL) return head;
    for (int i=0;i<k;i++) {
        Node *temp=head;
        while (temp->next->next!=NULL) temp=temp->next;
        Node *end=temp->next;
        temp->next=NULL;
        end->next=head;
        head=end;
    }
    return head;
}


// Efficient Approach -> rotate list by k times
Node *rotateRight(Node *head,int k) {
    if (head==NULL || head->next==NULL || k==0) return head;
    Node *temp=head;
    int length=1;
    while (temp->next!=NULL) {
        length++;
        temp=temp->next;
    }
    temp->next=head;
    k=k%length;
    int end=length-k;
    while (end!=0) {
        temp=temp->next;
        end--;
    }
    head=head->next;
    temp->next=NULL;
    return head;
}