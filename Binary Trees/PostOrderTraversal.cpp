//Post-order traversal is a DFS-based traversal where we visit nodes in the order:left->right->root

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

void postOrderHelper(Node *root,vector <int> &ans) {
    if (root!=NULL) {
        postOrderHelper(root->left,ans);
        postOrderHelper(root->right,ans);
        ans.push_back(root->data);
    }
}
vector <int> preOrderTraversal(Node *root) {
    vector <int> ans;
    postOrderHelper(root,ans);
    return ans;
}
//Time complexity:O(N)
//Space complexity:O(N)