#include <bits/stdc++.h>
using namespace std;

/*Maximum sum path from leaf to root in binary tree*/
struct Node {
    int data;
    Node *left,*right;
    Node (int x) {
        data=x;
        left=right=NULL;
    }  
};
void findMaxSum(Node *root,int curr_sum,int &max_sum) {
    if (root==NULL) return;
    curr_sum+=root->data;
    if (root->left==NULL && root->right==NULL) {
        if (curr_sum>max_sum) max_sum=curr_sum;
    }
    findMaxSum(root->left,curr_sum,max_sum);
    findMaxSum(root->right,curr_sum,max_sum);
}
int maxPathSum(Node *root) {
    if (root==NULL) return 0;
    int max_sum=INT_MIN;
    findMaxSum(root,0,max_sum);
    return max_sum;
}
//time:O(n),space:O(n)

/*Maximum sum path from root to leaf in n-ary tree*/
