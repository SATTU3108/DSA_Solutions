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
Check if given list is palindromic or not
*/

// Brute Force -> Stacks
bool isPalindrome(Node *head) {
    stack<int> st;
    Node *temp=head;
    while (temp!=NULL) {
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while (temp!=NULL) {
        if (temp->data!=st.top()) return false;
        st.pop();
        temp=temp->next;
    }
    return true;
}

// Efficient Approach
Node *reverseLinkedList(Node *head) {
    if (head==NULL || head->next==NULL) return head;
    Node *newHead=reverseLinkedList(head->next);
    Node *front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}
bool isPalindrome(Node *head) {
    if (head==NULL || head->next==NULL) return true;
    Node *slow=head,*fast=head;
    while (fast!=NULL && fast->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
    }
    Node *newHead=reverseLinkedList(slow->next);
    Node *first=head,*second=newHead;
    while (second!=NULL) {
        if (first->data!=second->data) {
            reverseLinkedList(newHead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverseLinkedList(newHead);
    return true;
}
