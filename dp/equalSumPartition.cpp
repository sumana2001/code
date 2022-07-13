/*

*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool equalSumPartition(vector<int> arr, int n, int sum)
{
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
            {
                dp[i][j] = true;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    vector<int> arr{1, 5, 11, 5, 12};
    int n = 4;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
    {
        cout << false;
    }
    else
    {
        int newSum = sum / 2;
        cout << equalSumPartition(arr, n, newSum);
    }
    return 0;
}