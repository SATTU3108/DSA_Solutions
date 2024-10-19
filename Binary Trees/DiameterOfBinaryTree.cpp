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
/*
Brute-force approach:
    1. Consider each node as a potential curving point
    2. Diameter for that node will be determined by 1+left subtree's height + right subtree's height
    3. Do this for left subtree and right subtree
*/
int height(Node *root) {
    if (root==NULL) return 0;
    return 1+max(height(root->left),height(root->right));
}
int maxDiameter(Node *root) {
    if (root==NULL) return 0;
    int left_height=height(root->left);
    int right_height=height(root->right);
    int left_diameter=maxDiameter(root->left);
    int right_diameter=maxDiameter(root->right);
    return max({left_height+right_height+1,left_diameter,right_diameter});
}
//Time complexity:O(N^2)
//Space complexity:O(h) -> recursive call stack

/*
Efficient approach -> use only one function to calculate the value(separate height function can be avoided)
*/
int getHeight(Node *root,int &diameter) {
    if (root==NULL) return 0;
    int leftHeight=getHeight(root->left,diameter);
    int rightHeight=getHeight(root->right,diameter);
    diameter=max(diameter,leftHeight+rightHeight);
    return 1+max(leftHeight,rightHeight);
}
int diameterOfBinaryTree(Node* root) {
    int diameter=0;
    getHeight(root,diameter);
    return diameter;
}
