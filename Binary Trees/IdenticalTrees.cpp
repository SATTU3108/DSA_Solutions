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
//Time complexity:O(N1+N2)
//Space complexity:O(N) 

//If the question would be to find that if a tree is symmetric, i.e. has a central verical line about which the tree can be viewd as symmetric, then a similar approach to the above one would be used
bool areMirrorImages(Node *root1,Node *root2) {
    if (root1==NULL && root2==NULL) return true;
    if (root1==NULL || root2==NULL) return false;
    if (root1->data!=root2->data) return false;
    return (areMirrorImages(root1->left,root2->right) && areMirrorImages(root1->right,root2->left));
}
bool isSymmetric(Node *root) {
    if (root==NULL) return true;
    return areMirrorImages(root->left,root->right);
}
