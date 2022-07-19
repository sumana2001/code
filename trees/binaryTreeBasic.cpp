/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

void display(Node *root){
    if(root==NULL){
        return;
    } 
    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}


int main(){
    struct Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    display(root);
    return 0;
}