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

vector <int> topView(Node *root) {
    vector <int> ans;
    if (root==NULL) return ans;
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while (!q.empty()) {
        auto it=q.front();
        Node* node=it.first;
        int hd=it.second;
        if (mp.find(hd)==mp.end()) mp[hd]=node->data;  //If this is the first node observed in this level, then only consider this for the top view
        if (node->left!=NULL) q.push({node->left,hd-1});
        if (node->right!=NULL) q.push({node->right,hd+1});
    }
    for (auto it:mp) ans.push_back(it.second);
    return ans;
}
//Time complexity:O(N)
//Space complexity:O(N)