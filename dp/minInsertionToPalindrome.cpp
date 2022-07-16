/*
Minimum number of insertions to make a string palindrome
Given a string, find the minimum number of characters to be inserted to form Palindrome string out of given string

Examples:
ab: Number of insertions required is 1. bab
aa: Number of insertions required is 0. aa
*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solve(string x,int n){
    string y=x;
    reverse(y.begin(),y.end());
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            } else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int insertions=n-dp[n][n];
    return insertions;
}

int main(){
    string x="aebcbda";
    int n=x.length();
    cout<<solve(x,n);
    return 0;
}