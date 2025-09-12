#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node (int x) {
            data=x;
            next=nullptr;
        }
};

/*
Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.
*/

// Brute Force -> Stacks
Node *reverseLinkedList(Node *head) {
    Node *temp=head;
    stack<int> st;
    while (temp!=nullptr) {
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while (temp!=NULL) {
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}
//time:O(n),space:O(n)

// Iterative Method
Node* reverseLinkedList(Node *head) {
    Node *temp=head;
    Node *prev=NULL;
    while (temp!=NULL) {
        Node *front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
//time:O(n),space:O(1)

// Recursive method
Node *reverseLinkedList(Node *head) {
    if (head==NULL || head->next==NULL) return head;
    Node *newHead=reverseLinkedList(head->next);
    Node *front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}
//time:O(n),space:O(n)