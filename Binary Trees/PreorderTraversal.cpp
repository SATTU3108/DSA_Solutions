//Preorder traversal is a DFS-based traversal where we visit nodes in the order: root->left->right

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

//Recursive solution
void preorderHelper(Node *root,vector <int> &ans) {
    if (root!=NULL) {
        ans.push_back(root->data);
        preorderHelper(root->left,ans);
        preorderHelper(root->right,ans);
    }
}
vector <int> preOrderTraversal(Node *root) {
    vector <int> ans;
    preorderHelper(root,ans);
    return ans;
}
//Time complexity:O(N)
//Space complexity:O(N)


//Iterative solution:
/*Algorithm:
    1. create an empty stack and push the root in it
    2. make iterations until the stack is not empty
        i. pop the top item of the stack
        ii. push the right child of the removed node, if it exists and then the left child
        iii. this is done in order to preprocess the left node first and then the right node
*/
vector <int> preOrderTraversal(Node *root) {
    vector <int> preorder;
    if (root==NULL) return preorder;
    stack <Node*> st;
    st.push(root);
    while (!st.empty()) {
        Node *node=st.top();
        st.pop();
        preorder.push_back(root->data);
        if (root->right!=NULL) st.push(root->right);
        if (root->left!=NULL) st.push(root->left);
    }
}
//Time complexity:o(N)
//Space complexity:O(N)

//Although the space complexity for both iterative and recursive solution is the same, iterative solution is more favoured due to the fact that in the case of skewed trees with large depth, recursion call stack might get exhausted and can cause stack overflow
