/*

*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int coinChange(vector<int> coin, int n, int sum)
{
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i-1]<=j){
                dp[i][j]=dp[i-1][j]+dp[i][j-coin[i-1]];
            } else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    vector<int> coin{1, 2, 3};
    int n = coin.size();
    int sum = 5;
    cout << coinChange(coin, n, sum);
    return 0;
}