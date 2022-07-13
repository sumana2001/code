/*

*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool subsetSum(vector<int> arr, int n, int sum)
{
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(j==0){
                dp[i][j]=true;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=sum){
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            } else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    int n = 5;
    vector<int> arr{2, 3, 7, 8, 10};
    int sum = 11;
    cout << subsetSum(arr, n, sum);
    return 0;
}