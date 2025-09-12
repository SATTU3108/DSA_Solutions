#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node *child;
        Node (int x) {
            data=x;
            next=NULL;
            child=NULL;
        }
};

// Brute-force Approach
Node *convertArrToLinkedList(vector<int> &arr) {
    Node *dummyNode=new Node(-1);
    Node *temp=dummyNode;
    for (int i=0;i<arr.size();i++) {
        temp->child=new Node(arr[i]);
        temp=temp->child;
    }
    return dummyNode->child;
}

Node *flattenLinkedList(Node *head) {
    vector<int> arr;
    while (head!=NULL) {
        Node *t2=head;
        while (t2!=NULL) {
            arr.push_back(t2->data);
            t2=t2->child;
        }
        head=head->next;
    }
    sort(arr.begin(),arr.end());
    return convertArrToLinkedList(arr);
}

// Efficient Approach -> Merge Sort
Node *merge(Node *list1,Node *list2) {
    Node *dummyNode=new Node(-1);
    Node *res=dummyNode;
    while (list1!=NULL && list2!=NULL) {
        if (list1->data<list2->data) {
            res->child=list1;
            res=list1;
            list1=list1->child;
        }
        else {
            res->child=list2;
            res=list2;
            list2=list2->child;
        }
        res->next=NULL;
    }
    while (list1!=NULL) {
        res->child=list1;
        res=list1;
        list1=list1->child;
    }
    while (list2!=NULL) {
        res->child=list2;
        res=list2;
        list2=list2->child;
    }
    if (dummyNode->child!=NULL) dummyNode->child->next=NULL;
    return dummyNode->child;
}
Node *flattenLinkedList(Node *head) {
    if (head==NULL || head->next==NULL) return head;
    Node *mergedHead=flattenLinkedList(head->next);
    head=merge(head,mergedHead);
    return head;
}
//time:O(n*m),space:O(n) in recursive space