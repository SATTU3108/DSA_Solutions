#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node *back;
        Node (int x) {
            data=x;
            next=nullptr;
            back=nullptr;
        }
};

Node *reverseDLL(Node *head) {
    if (head==NULL || head->next==NULL) return head;
    Node *prev=NULL;
    Node *curr=head;
    while (curr!=NULL) {
        prev=curr->back;
        curr->back=curr->next;
        curr->next=prev;
        curr=curr->back; // Move to next node in original list
    }
    head=prev->back;
    return head;
}