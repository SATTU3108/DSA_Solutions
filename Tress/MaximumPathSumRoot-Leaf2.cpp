#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    vector<Node*> child;
    Node (int x) {
        data=x;
    }
};
void DFS(Node *root,int sum,int &max_sum) {
    if (root==NULL) return;
    if (root->child.size()==0) {
        max_sum=max(max_sum,sum);
        return;
    }
    for (int i=0;i<root->child.size();i++) {
        DFS(root->child[i],sum+root->child[i]->data,max_sum);
    }
}
