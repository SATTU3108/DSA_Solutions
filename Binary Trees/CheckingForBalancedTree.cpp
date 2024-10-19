//A balanced tree means that at every level, the difference between the height of the left subtree and height of the right subtree is not more than 1

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

/*Brute-force algorithm
    1. Check the height condition for the root, i.e. the difference is less than 1 or not
    2. If it is, then recursively check the same for left child of it and the right child of it as well
    3. If at atny point this becomes false, return false
*/
int height(Node *root) {
    if (root==NULL) return 0;
    return 1+max(height(root->left),height(root->right));
}
bool isBalanced(Node *root) {
    if (root==NULL) return true;
    int left_height=height(root->left);
    int right_height=height(root->right);
    if (abs(left_height-right_height)<=1 && isBalanced(root->left) && isBalanced(root->right)) return true;
    return false;
}
//Time complexity:O(N^2) -> height*isBalanced
//Space complexity:O(h) -> recursive call stack

/*Optimal approach
    1. The main reason that why this above approach is going O(N^2) is because we are using two functions, one to calculate the height and the other to check for balanced condition, both with O(N) time complexity
    2. So the best approach would be to judge the balanced condition on the basis of height calculate, if it is greater than zero, then return true
    3. But in the height function, we will make some changes, so that when at any point, the tree gets unbalanced, we return -1 in it
*/
int height(Node *root) {
    if (root==NULL) return 0;
    int left_height=height(root->left);
    if (left_height==-1) return -1;
    int right_height=height(root->right);
    if (right_height==-1) return -1;
    if (abs(left_height-right_height)>1) return -1;
    return 1+max(left_height,right_height);
}
