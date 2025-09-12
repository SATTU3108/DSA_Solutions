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

void inorderHelper(Node *root,vector<int> &arr) {
    if (root==NULL) return;
    inorderHelper(root->left,arr);
    arr.push_back(root->data);
    inorderHelper(root->right,arr);
}
vector<int> inorder(Node *root) {
    vector<int> arr;
    inorderHelper(root,arr);
    return arr;
}
//time:O(n),space:O(h)

// Using Stack
vector<int> inorder(Node *root) {
    vector<int> ans;
    stack<Node*> st;
    Node *curr=root;
    while (curr!=NULL || !st.empty()) {
        // reach the left most node of the curr node
        while (curr!=NULL) {
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        ans.push_back(curr->data);
        curr=curr->right;
    }
    return ans;
}
//time:O(n),space:O(h)

// Morris Traversal
vector<int> inorder(Node *root) {
    vector<int> ans;
    Node *curr=root;
    while (curr!=NULL) {
        if (curr->left==NULL) {
            ans.push_back(curr->data);
            curr=curr->right;
        }
        else {
            Node *prev=curr->left;
            while (prev->right!=NULL && prev->right!=curr) prev=prev->right;
            if (prev->right==NULL) {
                prev->right=curr;
                curr=curr->left;
            }
            else {
                prev->right=NULL;
                ans.push_back(curr->data);
                curr=curr->right;
            }
        }
    }
    return ans;
}
//time:O(n),space:O(1)