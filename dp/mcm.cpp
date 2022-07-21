/*

*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

int mcmRecursive(vector<int> arr, int i, int j)
{
    if (i >= j)
        return 0;
    int min = INT_MAX;
    int count;
    int k;
    for (k = i; k < j; k++)
    {
        count = mcmRecursive(arr, i, k) +
                mcmRecursive(arr, k + 1, j) +
                (arr[i - 1] * arr[k] * arr[j]);
        if (count < min)
            min = count;
    }
    return min;
}

vector<vector<int>> dp(100,vector<int>(100,-1));
int mcmMemoization(vector<int> arr,int i, int j){
    if(i>=j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int k;
    int count;
    int min=INT_MAX;
    for(k=i;k<j;k++){
        count=mcmMemoization(arr,i,k)+mcmMemoization(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        if(count<min)
            min=count;
    }
    dp[i][j]=min;
    return dp[i][j];
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 3};
    int n = arr.size();
    cout << mcmRecursive(arr, 1, n - 1)<<endl;
    cout << mcmMemoization(arr, 1, n - 1)<<endl;
    return 0;
}