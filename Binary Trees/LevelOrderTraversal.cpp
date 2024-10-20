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

/*Algorithm:
    1. First make a queue and then push the root onto it
    2. Then make a loop that runs till the queue is empty
    3. In every iteration of the loop, pop the front node of the queue and while dpping so, enqueue the child nodes of it
    4. Also question, asks to return vector of vectors, where each vector signifies the order of nodes traversed in that particular level
*/

vector<vector<int>> levelOrderTraversal(Node *root) {
    vector <vector <int>> ans;
    if (root==NULL) return ans;
    queue <Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size=q.size();
        vector <int> level;
        for (int i=0;i<size;i++) {
            Node *node=q.front();
            q.pop();
            level.push_back(node->data);
            if (node->left!=NULL) q.push(node->left);
            if (node->right!=NULL) q.push(node->right);
        }
        ans.push_back(level);
    }
    return ans;
}
//Time complecxity:O(N)
//Space complexity:O(N)

//If the question would be to print the levels in spiral order(zigzag order), then on the basis or eventh iteration, either push the level array into the ans array as it is or first reverse it and then push it
vector <vector<int>> spralTraversal(Node *root) {
    vector<vector<int>> ans;
    if (root==NULL) return ans;
    queue <Node*> q;
    bool flag=true; //when this is true, traverse left to right and when this is false, traverse right to left
    q.push(root);
    while (!q.empty()) {
        int size=q.size();
        vector <int> row(size);
        for (int i=0;i<size;i++) {
            Node *node=q.front();
            q.pop();
            int index=flag?i:(size-i-1);
            row[index]=node->data;
            if (node->left!=NULL) q.push(node->left);
            if (node->right!=NULL) q.push(node->right);
        }
        flag=!flag;
        ans.push_back(row);
    }
    return ans;
}
