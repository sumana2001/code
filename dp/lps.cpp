/*
Longest Palindromic Subsequence
*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int lps(string x, string y,int n){
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
    return dp[n][n];
}   

int main(){
    string x="bbbab";
    int n=x.length();
    string y=x;
    reverse(y.begin(),y.end());
    cout<<lps(x,y,n);
    return 0;
}