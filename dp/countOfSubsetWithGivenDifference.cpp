/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int count(vector<int> arr, int n, int sum){
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    vector<int> arr{1,1,2,3};
    int n=arr.size();
    int diff=1;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int s1=(sum+diff)/2;
    cout<<count(arr,n,s1);
    return 0;
}