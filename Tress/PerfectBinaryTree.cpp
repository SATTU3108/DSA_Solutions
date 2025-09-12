// Finish Time: 01/07/2025, 11:21:21 WA
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

bool isPerfect(Node *root) {
    int required_nodes=1;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int s=q.size();
        int actual_nodes=0;
        for (int i=1;i<=s;i++) {
            Node *curr=q.front();
            q.pop();
            if (curr->left!=NULL) q.push(curr->left);
            if (curr->right!=NULL) q.push(curr->right);
            actual_nodes++;
        }
        if (actual_nodes!=required_nodes) return false;
        required_nodes*=2;
    }
    return true;
}
//time:O(n),space:O(n)