/*
Print all subsequences of an array which have a sum K
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void print(int idx, vector<int> &ds, int arr[], int n, int sum, int s)
{
    if (idx >= n)
    {
        if (sum == s)
        {
            for (auto x : ds)
                cout << x << " ";
            cout << endl;
        }
        return;
    }
    ds.push_back(arr[idx]);
    s += arr[idx];
    print(idx + 1, ds, arr, n, sum, s);
    ds.pop_back();
    s -= arr[idx];
    print(idx + 1, ds, arr, n, sum, s);
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