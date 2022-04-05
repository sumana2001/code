/*
Find combinations in an array where sum is k. You can repeat digits as well
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void combinationSum(int idx, vector<int> ds, int arr[], int n, int k)
{
    if (idx >= n)
    {
        if (k == 0)
        {
            for (auto x : ds)
                cout << x << " ";
            cout << endl;
        }
        return;
    }
    if (arr[idx] <= k)
    {
        ds.push_back(arr[idx]);
        combinationSum(idx, ds, arr, n, k - arr[idx]);
        ds.pop_back();
    }
    combinationSum(idx + 1, ds, arr, n, k);
}

int main()
{
    int n = 4;
    int arr[] = {2, 3, 6, 7};
    int k = 7;
    vector<int> ds;
    combinationSum(0, ds, arr, n, k);
    return 0;
}