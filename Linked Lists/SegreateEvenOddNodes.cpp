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

Node *segregateEvenOdd(Node *head) {
    Node *evenStart=new Node(-1);
    Node *oddStart=new Node(-1);
    Node *evenEnd=evenStart;
    Node *oddEnd=oddStart;
    Node *temp=head;
    while (temp!=NULL) {
        int val=temp->data;
        if (val%2==0) {
            evenEnd->next=temp;
            evenEnd=evenEnd->next;
        }
        else {
            oddEnd->next=temp;
            oddEnd=oddEnd->next;
        }
        temp=temp->next;
    }
    oddEnd->next=NULL;
    evenEnd->next=oddStart->next;
    Node *newHead=evenStart->next;
    delete evenStart;
    delete oddStart;
    return newHead;
}