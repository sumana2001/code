/*
Print only 1 subsequence of an array which have a sum K
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool print(int idx, vector<int> &ds, int arr[], int n, int sum, int s)
{
    if (idx >= n)
    {
        if (sum == s)
        {
            for (auto x : ds)
                cout << x << " ";
            cout << endl;
            return true;
        }
        return false;
    }
    ds.push_back(arr[idx]);
    s += arr[idx];
    if (print(idx + 1, ds, arr, n, sum, s) == true)
        return true;
    ds.pop_back();
    s -= arr[idx];
    if (print(idx + 1, ds, arr, n, sum, s) == true)
        return true;
    return false;
}

int main()
{
    int n = 3;
    int arr[] = {1, 2, 1};
    int k = 2;
    vector<int> ds;
    print(0, ds, arr, n, k, 0);
    return 0;
}