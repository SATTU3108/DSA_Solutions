#include <bits/stdc++.h>
using namespace std;

/*
Given a Binary Search Tree and a key, return the floor of the given key in the Binary Search Tree.

Floor of a value refers to the value of the largest node in the Binary Search Tree that is smaller than or equal to the given key.
If the floor node does not exist, return nullptr.
*/

struct Node {
    int data;
    Node *left,*right;
    Node (int val) {
        data=val;
        left=right=NULL;
    }
};

int findFloor(Node *root,int key) {
    int floor=-1;
    while (root!=NULL) {
        if (root->data==key) {
            floor=root->data;
            return floor;
        }
        if (key>root->data) {
            floor=root->data;
            root=root->right;
        }
        else root=root->left;
    }
    return floor;
}
//time:O(logn),space:O(1)