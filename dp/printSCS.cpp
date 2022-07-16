/*
Given two strings X and Y, print the shortest string that has both X and Y as subsequences. If multiple shortest supersequence exists, print any one of them.

Examples:

Input: X = "AGGTAB",  Y = "GXTXAYB"
Output: "AGXGTXAYB" OR "AGGXTXAYB" 
OR Any string that represents shortest
supersequence of X and Y

Input: X = "HELLO",  Y = "GEEK"
Output: "GEHEKLLO" OR "GHEEKLLO"
OR Any string that represents shortest 
supersequence of X and Y
*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void printSCS(string x, string y, int m, int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    //lcs
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            } else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int i=m,j=n;
    string s;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            s.push_back(x[i-1]);
            i--;
            j--;
        } else {
            if(dp[i-1][j]>dp[i][j-1]){
                s.push_back(x[i-1]);
                i--;
            } else {
                s.push_back(y[j-1]);
                j--;
            }
        }
    }
    while(i>0){
        s.push_back(x[i-1]);
        i--;
    }
    while(j>0){
        s.push_back(y[j-1]);
        j--;
    }
    reverse(s.begin(),s.end());
    for(int i=0;i<s.length();i++){
        cout<<s[i];
    }
}

int main(){
    string x="AGGTAB";
    string y="GXTXAYB";
    int m=x.length();
    int n=y.length();
    printSCS(x,y,m,n);
    return 0;
}