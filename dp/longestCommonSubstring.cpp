/*
Length of longest common substring (continous)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int lcs(string x, string y, int m, int n)
{
    int result=0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                result=max(result,dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return result;
}

int main()
{
    string x = "abcdgh";
    string y = "abedfhr";
    int m = x.length();
    int n = y.length();
    cout << lcs(x, y, m, n);
    return 0;
}