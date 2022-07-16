/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int lcs(string x, string y, int m, int n){
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
    return dp[m][n];
}

int scs(string x, string y, int m, int n){
    return m+n-lcs(x,y,m,n);
}

int main(){
    string x = "geek"; 
    string y = "eke";
    int m=x.length();
    int n=y.length();
    cout<<scs(x,y,m,n);
    return 0;
}