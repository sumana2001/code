/*
Minimum number of deletions to make a string palindrome
Given a string of size ‘n’. The task is to remove or delete minimum number of characters from the string so that the resultant string is palindrome.
Examples :

Input : aebcbda
Output : 2
Remove characters 'e' and 'd'
Resultant string will be 'abcba'
which is a palindromic string
*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solve(string x, string y, int n){
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
    int lcs=dp[n][n];
    int deletions=n-lcs;
    return deletions;
}

int main(){
    string x="aebcbda";
    int n=x.length();
    string y=x;
    reverse(y.begin(),y.end());
    cout<<solve(x,y,n);
    return 0;
}