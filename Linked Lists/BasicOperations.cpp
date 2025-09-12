#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node (int x) {
            data=x;
            next=nullptr;
        }
};

/*Insertion at beginning*/
Node* insertAtFront(Node *head,int new_data) {
    Node *new_node=new Node(new_data);
    new_node->next=head;
    head=new_node;
    return head;
}

/*Deletion at tail*/
Node* deleteTail(Node *head) {
    if (head==NULL || head->next==NULL) return NULL;
    Node *temp=head;
    while (temp->next->next!=NULL) temp=temp->next;
    delete temp->next;
    temp->next=nullptr;
    return head;
}

/*Length of LL*/
int length(Node *head) {
    Node *temp=head;
    int count=0;
    while (temp!=NULL) {
        temp=temp->next;
        count++;
    }
    return count;
}

/*Searching Element in LL*/ 
bool checkIfPresent(Node *head,int element) {
    Node *temp=head;
    while (temp!=NULL) {
        if (temp->data==element) return true;
        temp=temp->next;
    }
    return false;
}