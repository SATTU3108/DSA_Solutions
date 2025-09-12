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
void preorderHelper(Node *root,vector<int> &arr) {
    if (root==NULL) return;
    arr.push_back(root->data);
    preorderHelper(root->left,arr);
    preorderHelper(root->right,arr);
}
vector<int> preorder(Node *root) {
    vector<int> arr;
    preorderHelper(root,arr);
    return arr;
}
//time:O(n),space:O(h)

// Iterative Method
vector<int> preorder(Node *root) {
    vector<int> ans;
    if (root==NULL) return ans;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        Node *curr=st.top();
        st.pop();
        ans.push_back(curr->data);
        if (curr->right!=NULL) st.push(curr->right);
        if (curr->left!=NULL) st.push(curr->left);
    }
    return ans;
}
// time:O(n),space:O(n)

// Method 2
vector<int> morrisPreorder(Node *root) {
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
            if (prev->right==curr) {
                prev->right=NULL;
                curr=curr->right;
            } 
            else {
                ans.push_back(curr->data);
                prev->right=curr;
                curr=curr->left;
            }
        }
    }
    return ans;
}
//time:O(n),sapce:O(h)