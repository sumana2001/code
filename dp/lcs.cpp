/*
Length of Longest Common Subsequence
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int lcsRecursive(string x, string y, int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (x[m - 1] == y[n - 1])
    {
        return 1 + lcsRecursive(x, y, m - 1, n - 1);
    }
    else
    {
        return max(lcsRecursive(x, y, m - 1, n), lcsRecursive(x, y, m, n - 1));
    }
}

vector<vector<int>> dp(100, vector<int>(101, -1));
int lcsBottomUp(string x, string y, int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    else
    {

        if (x[m - 1] == y[n - 1])
        {
            return dp[m][n] = 1 + lcsRecursive(x, y, m - 1, n - 1);
        }
        else
        {
            return dp[m][n] = max(lcsRecursive(x, y, m - 1, n), lcsRecursive(x, y, m, n - 1));
        }
    }
}

int lcsTopDown(string x, string y, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string x = "abcdgh";
    string y = "abedfhr";
    int m = x.length();
    int n = y.length();
    cout << lcsRecursive(x, y, m, n);
    cout << lcsBottomUp(x, y, m, n);
    cout << lcsTopDown(x, y, m, n);
    return 0;
}