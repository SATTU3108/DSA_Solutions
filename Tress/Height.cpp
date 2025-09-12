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
int height(Node *root) {
    if (root==NULL) return -1;
    int left_height=height(root->left);
    int right_height=height(root->right);
    return 1+max(left_height,right_height);
}
//time:O(n),space:O(h)

// Level Order Traversal
int height(Node *root) {
    queue<Node*> q;
    q.push(root);
    int depth=0;
    while (!q.empty()) {
        int level_size=q.size();
        for (int i=0;i<level_size;i++) {
            Node *curr=q.front();
            q.pop();
            if (curr->left!=NULL) q.push(curr->left);
            if (curr->right!=NULL) q.push(curr->right);
        }
        depth++;
    }
    return depth-1;
}
//time:O(n),space:O(n)