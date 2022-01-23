/*
Given an array and target sum, find all triplets of distinct integers that can 
form the target sum. The numbers in each triplet should be ordered and all triplets
should also be ordered.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> result;

void pairSum(vector<int> v, int x, int start)
{
    int end = v.size() - 1;
    int num1 = start - 1;
    while (start < end)
    {
        if (v[start] + v[end] == x)
        {
            result.push_back({v[num1], v[start], v[end]});
            start++;
            end--;
        }
        else if (v[start] + v[end] > x)
            end--;
        else
            start++;
    }
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int target = 18;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 3; i++)
    {
        int x = target - v[i];
        pairSum(v, x, i + 1);
    }
    for (int i = 0; i < result.size(); i++)
    {
        for (int num : result[i])
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}