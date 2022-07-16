/*
Minimum number of deletions and insertions to transform one string into another
Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task is to remove/delete and insert minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.
Example:
Input : str1 = "geeksforgeeks", str2 = "geeks"
Output : Minimum Deletion = 8
        Minimum Insertion = 0 

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

pair<int,int> solve(string x, string y, int m,int n){
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            } else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int lcs=dp[m][n];
    pair<int,int> p;
    p.first=m-lcs;
    p.second=n-lcs;
    return p;
}

int main(){
    string x="geeksforgeeks";
    string y="geeks";
    int m=x.length();
    int n=y.length();
    pair<int,int> p=solve(x,y,m,n);
    cout<<p.first<<" "<<p.second;
    return 0;
}