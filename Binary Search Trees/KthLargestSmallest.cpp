#include <bits/stdc++.h>
using namespace std;

/*
Given a Binary Search Tree and an integer ‘K’. Find and return the ‘K-th’ smallest and ‘K-th’ largest element in the given Binary Search Tree.
*/

struct Node {
    int data;
    Node *left,*right;
    Node (int x) {
        data=x;
        left=right=NULL;
    }
};

// Brute force approach
void inorder(Node *root,vector<int> &arr) {
    if (root==NULL) return;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
    return;
}
pair<int,int> findKth(Node *root,int k) {
    vector<int> arr;
    inorder(root,arr);
    int kLargest=arr[arr.size()-k];
    int kSmallest=arr[k-1];
    return {kSmallest,kLargest};
}
//time:O(n),space:O(n)

// Optimal approach
void reverseInorder(Node *root,int &counter,int k,int &kLargest) {
    if (root==NULL || counter>=k) return;
    reverseInorder(root->right,counter,k,kLargest);
    counter++;
    if (counter==k) {
        kLargest=root->data;
        return;
    }
    reverseInorder(root->left,counter,k,kLargest);
}
void inorder(Node *root,int &counter,int k,int &kSmallest) {
    if (root==NULL || counter>=k) return;
    inorder(root->left,counter,k,kSmallest);
    counter++;
    if (counter==k) {
        kSmallest=root->data;
        return;
    }
    inorder(root->right,counter,k,kSmallest);
}
pair<int,int> findKth(Node *root,int k) {
    int kSmallest=INT_MIN,kLargest=INT_MAX;
    int counter=0;
    inorder(root,counter,k,kSmallest);
    counter=0;
    reverseInorder(root,counter,k,kLargest);
    return {kSmallest,kLargest};
}
//time:O(n),space:O(h)