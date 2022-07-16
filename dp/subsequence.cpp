/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false
*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool solve(string x, string y, int m, int n){
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            } else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int lcs=dp[n][n];
    if(x.length()==lcs)   
        return true;
    else
        return false;
}

int main(){
    string x="abc";
    string y="ahbgdc";
    int m=x.length();
    int n=y.length();
    cout<<solve(x,y,m,n);
    return 0;
}