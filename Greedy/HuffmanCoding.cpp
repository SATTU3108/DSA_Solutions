#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char ch;
    int freq;
    Node *left,*right;
    Node(char c,int f) {
        ch=c;
        freq=f;
        left=right=NULL;
    }
};

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->freq>b->freq;
    }
};

void preOrder(Node* root,unordered_map<char,string> &huffman,string curr) {
    if (root==NULL) return;
    if (root->left==NULL && root->right==NULL) {
        huffman[root->ch]=curr;
        return;
    }
    preOrder(root->left,huffman,curr + "0");
    preOrder(root->right,huffman,curr+"1");
}

unordered_map<char, string> huffmanCodes(string s, vector<int> freq) {
    int n=s.length();
    priority_queue<Node*,vector<Node*>,Compare> pq;
    for (int i=0;i<n;i++) pq.push(new Node(s[i],freq[i]));
    while (pq.size()>1) {
        Node* l=pq.top(); 
        pq.pop();
        Node* r=pq.top(); 
        pq.pop();
        Node* merged=new Node('$',l->freq+r->freq); // '$' denotes internal node
        merged->left=l;
        merged->right=r;
        pq.push(merged);
    }

    Node* root = pq.top();
    unordered_map<char, string> huffman;
    preOrder(root,huffman,"");
    return huffman;
}
