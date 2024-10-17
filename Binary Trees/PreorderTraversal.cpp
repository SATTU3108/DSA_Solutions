//Preorder traversal is a DFS-based traversal where we visit nodes in the order: root->left->right

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left,*right;
    Node (int x) {
        data=x;
        left=right=NULL;
    }
};

void preorderHelper(Node *root,vector <int> &ans) {
    if (root!=NULL) {
        ans.push_back(root->data);
        preorderHelper(root->left,ans);
        preorderHelper(root->right,ans);
    }
}
vector <int> preOrderTraversal(Node *root) {
    vector <int> ans;
    preorderHelper(root,ans);
    return ans;
}
//Time complexity:O(N)
//Space complexity:O(N)