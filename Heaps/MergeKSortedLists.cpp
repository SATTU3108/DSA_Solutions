/*
Given an array of k linked-lists, each linked-list is sorted in ascending order. Merge all the linked-lists into one sorted linked-list
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node (int x) {
        data=x;
        next=NULL;
    }
};

// Brute-force approach
Node *convertArrToLinkedList(vector<int> &arr) {
    Node *dummyNode=new Node(-1);
    Node *temp=dummyNode;
    for (int i=0;i<arr.size();i++) {
        temp->next=new Node(arr[i]);
        temp=temp->next;
    }
    return dummyNode->next;
}
Node *mergeKLists(vector<Node*> &listArray) {
    vector<int> arr;
    for (int i=0;i<listArray.size();i++) {
        Node *temp=listArray[i];
        while (temp!=NULL) {
            arr.push_back(temp->data);
            temp=temp->next;
        }
    }
    sort(arr.begin(),arr.end());
    return convertArrToLinkedList(arr);
}
//time:O(n*k*log(n*k)),space:O(n*k)

// Better Approach -> merge two sorted lists at a time
Node *mergeTwoSortedLinkedLists(Node *list1,Node* list2) {
    Node *dummyNode=new Node(-1);
    Node *temp=dummyNode;
    while (list1!=NULL && list2!=NULL) {
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
    while (list1!=NULL) {
        temp->next=list1;
        list1=list1->next;
        temp=temp->next;
    }
    while (list2!=NULL) {
        temp->next=list2;
        list2=list2->next;
        temp=temp->next;
    }
    return dummyNode->next;
}
Node *mergeKLists(vector<Node*> &listArray) {
    Node *head=listArray[0];
    for (int i=1;i<listArray.size();i++) {
        head=mergeTwoSortedLinkedLists(head,listArray[i]);
    }
    return head;
}
//time:O(n*k^2),space:O(1)

// Optimal Approach -> Add all heads in priority queue
Node *mergeKLists(vector<Node*> listArray) {
    priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>> pq;
    for (int i=0;i<listArray.size();i++) {
        if (listArray[i]) pq.push({listArray[i]->data,listArray[i]});
    }
    Node *dummyNode=new Node(-1);
    Node *temp=dummyNode;
    while (!pq.empty()) {
        auto it=pq.top();
        pq.pop();
        if (it.second->next!=NULL) pq.push({it.second->next->data,it.second->next});
        temp->next=it.second;
        temp=temp->next;
    }
    return dummyNode->next;
}
//time:O(n*k*log(k)),space:O(k)