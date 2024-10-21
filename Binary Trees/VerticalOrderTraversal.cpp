//The question states to find the vector that stores the output of vertical order traversal, i.e. elements on same vertical line printed together

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

/*Brute-force approach
    1. Traverse the tree once to get minimum and maximum horizontal distances with respect to root
    2. Then from min_value to the max_value of the horizontal distance, we find the nodes that lie on that level
*/
void findMinMax(Node *root,int hd,int &min_hd,int &max_hd) {
    if (root==NULL) return;
    min_hd=min(min_hd,hd);
    max_hd=max(max_hd,hd); 
    findMinMax(root->left,hd-1,min_hd,max_hd);
    findMinMax(root->right,hd+1,min_hd,max_hd);
}
void getNodesOnLevel(Node *root,int level,int hd,vector <int> &result) {
    if (root==NULL) return;
    if (hd==level) result.push_back(root->data);
    getNodesOnLevel(root->left,level,hd-1,result);
    getNodesOnLevel(root->right,level,hd+1,result);
}
vector <int> verticalOrderTraversal(Node *root) {
    vector <int> result;
    int min_hd=0,max_hd=0;
    findMinMax(root,0,min_hd,max_hd);
    for (int i=min_hd;i<=max_hd;i++) {
        getNodesOnLevel(root,i,0,result);
    }
    return result;
}
//Time complexity:O(N^2)

/*Ordered map approach:
    1. First store in a map of type {int,vector<int>}, for each level the nodes
    2. So here key is the level and the value is the vector of nodes in that vertical level
*/
void helperFunc(Node *root,int hd,map<int,vector<int>> mp) {
    if (root==NULL) return;
    mp[hd].push_back(root->data);
    helperFunc(root->left,hd-1,mp);
    helperFunc(root->right,hd+1,mp);
}
vector <vector<int>> levelOrderTraversal(Node *root) {
    vector <vector<int>> result;
    map<int,vector<int>> mp;
    helperFunc(root,0,mp);
    for (auto &entry:mp) {
        vector <int> temp;
        for (int key:entry.second) temp.push_back(key);
        result.push_back(temp);
    }
    return result;
}
//Time complexity:O(NlogN)

/*Unordered-map approach
    1. Only difference between this nethod and the above method is that we need to store the minimum vertical and horizontal distances as well
*/
void helperFunc(Node *root,int hd,unordered_map<int,vector<int>> mp,int &min_hd,int &max_hd) {
    if (root==NULL) return;
    mp[hd].push_back(root->data);
    min_hd=min(min_hd,hd);
    max_hd=max(max_hd,hd);
    helperFunc(root->left,hd-1,mp,min_hd,max_hd);
    helperFunc(root->right,hd+1,mp,min_hd,max_hd);
}
vector<vector<int>> levelOrderTraversal(Node *root) {
    if (root==NULL) return;
    int min_hd=0,max_hd=0;
    unordered_map<int,vector<int>> mp;
    helperFunc(root,0,mp,min_hd,max_hd);
    vector <vector<int>> result;
    for (int d=min_hd;d<=max_hd;d++) {
        vector <int> temp;
        for (int key:mp[d]) temp.push_back(key);
        result.push_back(temp);
    }
    return result;
}