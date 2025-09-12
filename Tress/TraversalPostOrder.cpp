#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left,*right;
    Node (int val) {
        data=val;
        left=right=NULL;
    }
};

// Recursion
void postorderHelper(Node *root,vector<int> &arr) {
    if (root==NULL) return;
    postorderHelper(root->left,arr);
    postorderHelper(root->right,arr);
    arr.push_back(root->data);
}
vector<int> postOrder(Node *root) {
    vector<int> arr;
    postorderHelper(root,arr);
    return arr;
}
//time:O(n),space:O(h)

// Iterative Method - 2 stacks
vector<int> postorder(Node *root) {
    vector<int> ans;
    if (root==NULL) return ans;
    stack<Node*> st1,st2;
    st1.push(root);
    Node *curr;
    while (!st1.empty()) {
        curr=st1.top();
        st1.pop();
        st2.push(curr);
        if (curr->left!=NULL) st1.push(curr->left);
        if (curr->right!=NULL) st1.push(curr->right);
    }
    while (!st2.empty()) {
        curr=st2.top();
        st2.pop();
        ans.push_back(curr->data);
    }
    return ans;
}

// Iterative Method - 1 stack