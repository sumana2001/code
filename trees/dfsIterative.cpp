/*

*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void inorder(Node *root)
{
    stack<Node *> s;
    Node *curr=root;
    while(!s.empty() || curr!=NULL){
        while(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr=curr->right;
    }
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *node = s.top();
        s.pop();
        cout << node->data << " ";
        if (node->right)
            s.push(node->right);
        if (node->left)
            s.push(node->left);
    }
}

void postorder(Node *root)
{
    if(root==NULL)
        return;
    stack<Node *> s1,s2;
    s1.push(root);
    while(!s1.empty()){
        Node *node=s1.top();
        s1.pop();
        s2.push(node);
        if(node->left)
            s1.push(node->left);
        if(node->right)
            s1.push(node->right);
    }
    while(!s2.empty()){
        Node *node=s2.top();
        s2.pop();
        cout<<node->data<<" ";
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    return 0;
}