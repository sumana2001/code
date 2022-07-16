/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string printlcs(string x, string y, int m, int n){

    //lcs table
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

    //store string
    string s;
    int i=m,j=n;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            s.push_back(x[i-1]);
            i--;
            j--;
        } else {
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            } else {
                j--;
            }
        }
    }

    //reverse the string
    reverse(s.begin(),s.end());
    return s;
}

int main(){
    string x = "abcdgh";
    string y = "abedfhr";
    int m=x.length();
    int n=y.length();
    cout<<printlcs(x,y,m,n);
    return 0;
}