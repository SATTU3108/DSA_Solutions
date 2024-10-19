//Determine the maximum sum in a binary tree

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

/*Approach:
    1. For every node, just add the value of leftsum and rightsum and the current node's data; try to maximise this value
    2. And to determine whether to go in the left subtree part or the right subtree part, just check on the basis of which part's sum is greater
*/
int helperFunc(Node *root, int &sum) {
    if (root==NULL) return 0;
    int left_sum=max(0,helperFunc(root->left,sum));
    int right_sum=max(0,helperFunc(root->right,sum));
    sum=max(sum,left_sum+right_sum+root->data);
    return root->data+max(left_sum,right_sum);
}   
int maxPathSum(Node *root) {
    int sum=INT_MIN;
    int ans=helperFunc(root,sum);
    return sum;
}
//Time complexity:O(N)
//Space complexity:O(h)