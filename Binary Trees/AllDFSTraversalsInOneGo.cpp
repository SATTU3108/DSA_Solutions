#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left,*right;
    Node (int x) {
        left=right=NULL;
    }
};

/*Algorithm: 
    1. To solve this in one stack->the idea is that the stack will hold the node as well as a status code
    2. If status code is 1, it means that node is doing preorder traversal, 2 maens that node is doing node is doing inorder traversal and 3 means node is doing postorder traversal
    Status = 1:
        The node is in the preorder traversal phase (root, left, right).
        We:
            Update the status of the node to 2, meaning we will process it next in inorder.
            Add the node’s value to the preorder vector.
            If the node has a left child, push the left child onto the stack.
            This follows the root -> left part of preorder traversal.
    Status = 2:
        The node is in the inorder traversal phase (left,root,right).
        We:
            Update the status of the node to 3, meaning we will process it next in postorder.
            Add the node’s value to the inorder vector.
            If the node has a right child, push the right child onto the stack.
            This follows the left->root->right part of inorder traversal.
    Status = 3:
        The node is in the postorder traversal phase (left, right, root).
        We:
            Add the node’s value to the postorder vector.
            Remove (pop) the node from the stack, as it's completely processed.
            This follows the left->right-> root part of postorder traversal.
*/

vector <vector<int>> allTraversals(Node *root) {
    vector <int> preorder,inorder,postorder;
    stack <pair<Node*,int>> st;
    st.push({root,1}); //preorder status
    while (!st.empty()) {
        auto p=st.top();
        if (p.second==1) {
            st.top().second=2;
            preorder.push_back(p.first->data);
            if (p.first->left!=NULL) st.push({p.first->left,1});
        }
        else if (p.second==2) {
            st.top().second=3;
            inorder.push_back(p.first->data);
            if (p.first->right!=NULL) st.push({p.first->right,2});
        }
        else {
            postorder.push_back(p.first->data);
            st.pop();
        }
    }
}
//Time complexity:O(N)
//Space complxity:O(N)