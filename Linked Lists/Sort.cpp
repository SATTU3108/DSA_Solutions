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
Given a linked list, sort its nodes based on the data value in them. Return the head of the sorted linked list.
*/

// Brute-force approach
Node *sortLL(Node *head) {
    vector<int> arr;
    Node *temp=head;
    while (temp!=NULL) {
        arr.push_back(temp->data);
        temp=temp->next;
    }
    sort(arr.begin(),arr.end());
    temp=head;
    for (int i=0;i<arr.size();i++) {
        temp->data=arr[i];
        temp=temp->next;
    }
    return head;
}
//time:O(n)+O(nlogn)+O(n)=O(nlogn),space:O(n)

// Efficient approach -> Merge Sort
Node *mergeTwoSortedLinkedLists(Node *list1,Node *list2) {
    Node *dummyNode=new Node(-1);
    Node *temp=dummyNode;
    while (list1!=nullptr && list2!=nullptr) {
        if (list1->data<=list2->data) {
            temp->next=list1;
            list1=list1->next;
        }
        else {
            temp->next=list2;
            list2=list2->next;
        }
        temp=temp->next;
    }
    while (list1!=nullptr) {
        temp->next=list1;
        list1=list1->next;
        temp=temp->next;
    }
    while (list2!=nullptr) {
        temp->next=list2;
        list2=list2->next;
        temp=temp->next;
    }
    return dummyNode->next;
    
}
Node *findMiddle(Node *head) {
    if (head==NULL || head==NULL) return head;
    Node *slow=head,*fast=head;
    while (fast!=NULL && fast->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node *sortLL(Node *head) {
    if (head==nullptr || head->next==nullptr) return head;
    Node *middle=findMiddle(head);
    Node *right=middle->next;
    middle->next=nullptr;
    Node *left=head;
    left=sortLL(left);
    right=sortLL(right);
    return mergeTwoSortedLinkedLists(left,right);
}