#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node (int x) {
            data=x;
            next=nullptr;
        }
};

// Brute force approach
bool detectLoop(Node *head) {
    Node *temp=head;
    unordered_map<Node*,int> mp;
    while (temp!=NULL) {
        if (mp.find(temp)!=mp.end()) return true;
        mp[temp]=1;
        temp=temp->next;
    }
    return false;
}
//time:O(nlogn),space:O(n)

// Tortoise-Hare algorithm
bool detectCycle(Node *head) {
    Node *slow=head;
    Node *fast=head;
    while (fast!=NULL && fast->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast) return true;
    }
    return false;
}
//time:O(n),space:O(1)

// Starting point by Tortoise Hare Algorithm
Node *firstNode(Node *head) {
    Node *slow=head;
    Node*fast=head;
    while (fast!=NULL && fast->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast) {
            slow=head;
            while (slow!=fast) {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
//time:O(n),space:O(1)

// Length of loop by brute force hashing
int lengthOfLoop(Node *head) {
    unordered_map<Node*,int> mp;
    Node *temp=head;
    int timer=0;
    while (temp!=NULL) {
        if (mp.find(temp)!=mp.end()) {
            int length=timer-mp[temp];
            return length;
        }
        mp[temp]=timer;
        timer++;
        temp=temp->next;
    }
    return 0; // indicating that there is no loop
}

// Length of loop by Tortoise Hare algoithm
int lengthOfLoop(Node *head) {
    Node *slow=head,*fast=head;
    while (fast!=NULL && fast->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast) {
            int count=1;
            fast=fast->next;
            while (fast!=slow) {
                count++;
                fast=fast->next;
            }
            return count;
        }
    }
    return 0; // indicating that there is no loop
}

// Starting point of loop
Node *firstNode (Node *head) {
    Node *slow=head,*fast=head;
    while (fast!=NULL && fast->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast) {
            slow=head;
            while (slow!=fast) {
                slow=slow->next;
                fast=fast=fast->next;
            } 
            return slow;
        }
    }
    return NULL;
}