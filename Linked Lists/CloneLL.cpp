#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node *random;
        Node (int x) {
            data=x;
            next=NULL;
            random=NULL;
        }
};

// Brute Force Approach
Node *cloneLL(Node *head) {
    Node *temp=head;
    unordered_map<Node*,Node*> mp;
    while (temp!=NULL) {
        Node *newNode=new Node(temp->data);
        mp[temp]=newNode;
        temp=temp->next;
    }
    temp=head;
    while (temp!=NULL) {
        Node *copyNode=mp[temp];
        copyNode->next=mp[temp->next];
        copyNode->random=mp[temp->random];
        temp=temp->next;
    }
    return mp[head];
}
//time:O(N),space:O(N)

// Optimal Approach
void insertCopyInBetween(Node *head) {
    Node *temp=head;
    while (temp!=NULL) {
        Node *nextElement=temp->next;
        Node *copy=new Node(temp->data);
        copy->next=nextElement;
        temp->next=copy;
        temp=nextElement;
    }
}
void connectRandomPointers(Node *head) {
    Node *temp=head;
    while (temp!=NULL) {
        Node *copyNode=temp->next;
        if (temp->random!=NULL) {
            copyNode->random=temp->random->next;
        }
        else copyNode->random=NULL;
        temp=temp->next->next;
    }
}
Node *getDeepCopyList(Node *head) {
    Node *temp=head;
    Node *dummyNode=new Node(-1);
    Node *res=dummyNode;
    while (temp!=NULL) {
        res->next=temp->next;
        res=res->next;
        temp->next=temp->next->next;
        temp=temp->next;
    }
    return dummyNode->next;
}
Node *cloneLL(Node *head) {
    if (head==NULL) return NULL;
    insertCopyInBetween(head);
    connectRandomPointers(head);
    return getDeepCopyList(head);
}