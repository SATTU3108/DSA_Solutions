#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node (int new_data) {
            this->data=new_data;
            this->next=nullptr;
        }
};
class Stack {
    Node *head;
    public:
        Stack() {
            this->head=nullptr;
        }
        bool isEmpty() {
            return (head==nullptr);
        }
        void push(int new_data) {
            Node *new_node=new Node(new_data);
            if (!new_node) cout<<"Stack Overflow"<<endl;
            new_node->next=head;
            head=new_node;
        }
        void pop() {
            if (this->isEmpty()) cout<<"Stack Underflow"<<endl;
            else {
                Node *temp=head;
                head=head->next;
                delete temp;
            }
        }
        int peek() {
            if (!this->isEmpty()) return head->data;
            else {
                cout<<"Stack Underflow"<<endl;
                return INT_MIN;
            }
        }
};