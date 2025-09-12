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

vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> ans;
    if (root==NULL) return ans;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size=q.size();
        vector<int> level;
        for (int i=0;i<size;i++) {
            Node *curr=q.front();
            q.pop();
            level.push_back(curr->data);
            if (curr->left!=NULL) q.push(curr->left);
            if (curr->right!=NULL) q.push(curr->right);
        }
        ans.push_back(level);
    }
    return ans;
}
//time:O(n),space:O(n)