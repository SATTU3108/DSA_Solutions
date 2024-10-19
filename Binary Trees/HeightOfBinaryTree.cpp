//Also called maximum depth of the binary tree

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

int maxDepth(Node *root) {
    if (root==NULL) return 0;
    int leftHeight=maxDepth(root->left);
    int rightHeight=maxDepth(root->right);
    return 1+max(leftHeight,rightHeight);
}
//Time complxity:O(N)
//Space complexity:O(N)