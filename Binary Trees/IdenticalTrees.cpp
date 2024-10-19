//Given two roots of two different binary trees, determine that they are identical trees or not

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

bool areIdentical(Node *root1,Node *root2) {
    if (root1==NULL && root2==NULL) return true;
    if (root1==NULL || root2==NULL) return false;
    if (root1->data!=root2->data) return false;
    return (areIdentical(root1->left,root2->left) && areIdentical(root1->right,root2->right));
}
//Time complexoty:O(N1+N2)
//Space complexity:O(N) 