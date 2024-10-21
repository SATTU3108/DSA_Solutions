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

vector <int> bottomView(Node *root) {
    vector <int> ans;
    if (root==NULL) return ans;
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while (!q.empty()) {
        auto it=q.front();
        q.pop();
        Node *node=it.first;
        int hd=it.second;
        mp[hd]=node->data; //Unlike top view of the binary tree, where we just use the first element that we found in the line, here we always overwrite the element
        if (node->left!=NULL) q.push({node->left,hd-1});
        if (node->right!=NULL) q.push({node->right,hd+1});
    }
    for (auto it:mp) ans.push_back(it.second);
    return ans;
}
//Time complexity:O(N)
//Space complexity:O(N)