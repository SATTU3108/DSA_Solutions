//Inorder traversal is a DFS-based traversal where we visit nodes in the order:left->root->right

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

void inOrderHelper(Node *root,vector <int> &ans) {
    if (root!=NULL) {
        inOrderHelper(root->left,ans);
        ans.push_back(root->data);
        inOrderHelper(root->right,ans);
    }
}
vector <int> preOrderTraversal(Node *root) {
    vector <int> ans;
    inOrderHelper(root,ans);
    return ans;
}
//Time complexity:O(N)
//Space complexity:O(N)