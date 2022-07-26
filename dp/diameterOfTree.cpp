/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

int diameter(Node *root, int &res){
    if(root==NULL)
        return 0;
    int l=diameter(root->left,res);
    int r=diameter(root->right,res);
    int temp=max(l,r)+1;
    int ans=max(temp,1+l+r);
    res=max(res,ans);
    return temp;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    int res=INT_MAX;
    cout<<diameter(root,res);
    return 0;
}