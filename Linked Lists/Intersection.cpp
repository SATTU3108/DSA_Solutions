#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node (int x) {
            data=x;
            next=NULL;
        }
};

/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
*/

// Brute force
Node *intersectionPresent(Node *head1,Node *head2) {
    while (head2!=NULL) {
        Node *temp=head1;
        while (temp!=NULL) {
            if (temp==head2) return head2;
            temp=temp->next;
        }
        head2=head2->next;
    }
    return NULL;
}
//time:O(m*n),space:O(1)

// Better Approach
Node *intersectionPresent(Node *head1,Node *head2) {
    unordered_set <Node*> st;
    while (head1!=NULL) {
        st.insert(head1);
        head1=head1->next;
    }
    while (head2!=NULL) {
        if (st.find(head2)!=st.end()) return head2;
        head2=head2->next;
    }
    return NULL;
}
//time:O(n+m),space:O(n)

// Efficient Approach -> Difference in lengths
int getDifference(Node *head1,Node *head2) {
    int len1=0,len2=0;
    while (head1!=NULL) {
        len1++;
        head1=head1->next;
    }
    while (head2!=NULL) {
        len2++;
        head2=head2->next;
    }
    return (len1-len2); //+ve iif 1st list has greater length and is -ve id 2nd list has greater length
}
Node *intersectionPresent(Node *head1,Node *head2) {
    int diff=getDifference(head1,head2);
    if (diff<0) {
        diff++;
        head2=head2->next;
    }
    else {
        diff++;
        head1=head1->next;
    }
    while (head1!=NULL) {
        if (head1==head2) return head1;
        head1=head1->next;
        head2=head2->next;
    }
    return NULL;
}
//time:O(2max(l1,l2))+O(abs(l1-l2))+O(min(l1,l2)),space:O(1)

Node *intersectionPresent(Node *head1,Node *head2) {
    Node *d1=head1,*d2=head2;
    while (d1!=d2) {
        if (d1==NULL) d1=head2;
        else d1=d1->next;
        if (d2==NULL) d2=head1;
        else d2=d2->next;
    }
    return d1;
}
//time:O(2max(l1,l2)),space:O(1)