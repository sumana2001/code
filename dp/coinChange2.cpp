/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<limits.h>
using namespace std;

int coinChange(vector<int> coin, int n, int sum){
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    for(int j=0;j<sum+1;j++){
        dp[0][j]=INT_MAX-1;
    }
    for(int i=0;i<n+1;i++){
        dp[i][0]=0;
    }
    for(int j=1;j<sum+1;j++){
        if(j%coin[0]==0){
            dp[1][j]=j/coin[0];
        } else {
            dp[1][j]=INT_MAX-1;
        }
    }
    for(int i=2;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i-1]<=j){
                dp[i][j]=min(dp[i-1][j],1+dp[i][j-coin[i-1]]);
            } else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    vector<int> coin{3,4,5};
    int sum=5;
    int n=coin.size();
    cout<<coinChange(coin,n,sum);
    return 0;
}