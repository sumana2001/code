/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<limits.h>
#include<math.h>
using namespace std;

int minSubsetSum(vector<int> arr, int n, int sum){
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
    for(int i=0;i<n+1;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=sum){
                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    vector<int> result;
    for(int i=0;i<=(n+1)/2;i++){
        if(dp[n][i]==true)
            result.push_back(arr[i+1]);
    }
    int mn=INT_MAX;
    for(int i=0;i<result.size();i++){
        int x=2*result[i];
        mn=min(mn,abs(sum-x));
    }
    return mn;
}

int main(){
    vector<int> arr{2,7,1};
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    cout<<minSubsetSum(arr,n,sum);
    return 0;
}