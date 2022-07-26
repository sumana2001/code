/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

int solve(int e, int f){
    if(f==0 || f==1 || e==1)
        return f;
    int mn=INT_MAX;
    for(int k=1;k<=f;k++){
        int temp=1+max(solve(e-1,k-1),solve(e,f-k));
        mn=min(temp,mn);
    }
    return mn;
}

vector<vector<int>> dp(101,vector<int>(101,-1));
int solveDP(int e,int f){
    if(f==0 || f==1 || e==1){
        return f;
    }
    if(dp[e][f]!=-1)
        return dp[e][f];
    int mn=INT_MAX;
    for(int k=1;k<=f;k++){
        int temp=1+max(solveDP(e-1,k-1),solve(e,f-k));
        mn=min(temp,mn);
    }
    return dp[e][f]=mn;
}

vector<vector<int>> t(101,vector<int>(101,-1));
int solveDPOptimized(int e,int f){
    if(f==0 || f==1 || e==1){
        return f;
    }
    if(t[e][f]!=-1)
        return t[e][f];
    int mn=INT_MAX;
    for(int k=1;k<=f;k++){
        int left=t[e-1][k-1]!=-1?t[e-1][k-1]:solveDPOptimized(e-1,k-1);
        int right=t[e][f-k]!=-1?t[e][f-k]:solveDPOptimized(e,f-k);
        int temp=1+max(left,right);
        mn=min(temp,mn);
    }
    return dp[e][f]=mn;
}

int main(){
    int f=10,e=2;
    cout<<solve(e,f);
    cout<<solveDP(e,f);
    cout<<solveDPOptimized(e,f);
    return 0;
}