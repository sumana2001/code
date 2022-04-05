/*
Count the number of subsequences with sum K
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int print(int idx, int arr[], int n, int k, int s)
{
    if(s>k) return 0;
    if (idx >= n)
    {
        if (k == s)
            return 1;
        return 0;
    }
    s += arr[idx];
    int l = print(idx + 1, arr, n, k, s);
    s -= arr[idx];
    int r = print(idx + 1, arr, n, k, s);
    return l + r;
}

int main()
{
    int n = 3;
    int arr[] = {1, 2, 1};
    int k = 2;
    cout << print(0, arr, n, k, 0);
    return 0;
    return 0;
}