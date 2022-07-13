/*
0/1 knapsack
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int knapsackRecursive(vector<int> val, vector<int> wt, int w, int n)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if (wt[n - 1] <= w)
    {
        return max(val[n - 1] + knapsackRecursive(val, wt, w - wt[n - 1], n - 1), knapsackRecursive(val, wt, w, n - 1));
    }
    else
    {
        return knapsackRecursive(val, wt, w, n - 1);
    }
}

vector<vector<int>> dp(100, vector<int>(100, -1));

int knapsackMemoize(vector<int> val, vector<int> wt, int w, int n)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }
    if (wt[n - 1] <= w)
    {
        return dp[n][w] = max(val[n - 1] + knapsackRecursive(val, wt, w - wt[n - 1], n - 1), knapsackRecursive(val, wt, w, n - 1));
    }
    else
    {
        return dp[n][w] = knapsackRecursive(val, wt, w, n - 1);
    }
}

int knapsackTopdown(vector<int> val, vector<int> wt, int w, int n)
{
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
}

int main()
{
    int n = 3;
    int w = 4;
    vector<int> val{1, 2, 3};
    vector<int> wt{4, 5, 1};
    cout << knapsackRecursive(val, wt, w, n);
    cout << knapsackMemoize(val, wt, w, n);
    cout << knapsackTopdown(val, wt, w, n);
    return 0;
}