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

int maxPathSum(Node *root, int &res){
    if(root==NULL)
        return 0;
    int l=maxPathSum(root->left,res);
    int r=maxPathSum(root->right,res);
    int temp=max(l,r)+root->data;
    if(root->left==NULL && root->right==NULL)
        temp=max(temp,root->data);
    int ans=max(temp,l+r+root->data);
    res=max(ans,res);
    return temp;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    int res=INT_MIN;
    int x=maxPathSum(root,res);
    cout<<res;
    return 0;
}