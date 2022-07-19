/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

//Left Root Right
void inorder(Node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//Root Left Right
void preorder(Node *root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//Left Right Root 
void postorder(Node *root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    struct Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    inorder(root);
    preorder(root);
    postorder(root);
    return 0;
}