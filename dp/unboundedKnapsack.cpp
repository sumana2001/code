/*
W = 100
val[]  = {1, 30}
wt[] = {1, 50}
*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int unboundedKnapsack(vector<int> val, vector<int> wt, int w, int n){
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            } else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}

int main(){
    vector<int> val{1,30};
    vector<int> wt{1,50};
    int n=val.size();
    int w=100;
    cout<<unboundedKnapsack(val,wt,w,n);
    return 0;
}