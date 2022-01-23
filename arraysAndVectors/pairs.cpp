/*
Given an array and target sum, find two distinct integers that can 
pair up to form the target sum. Assume there will be only one such pair
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

//brute force O(N^2)
void solve1(vector<int> v, int target)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] + v[j] == target)
            {
                cout << v[i] << "," << v[j] << endl;
                return;
            }
        }
    }
}

void bsearch(vector<int> v, int start, int target)
{
    int end = v.size() - 1;
    int num = start;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (v[mid] == target)
        {
            cout << v[num - 1] << "," << target << endl;
            return;
        }
        else if (v[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
}

//sorting and binary search O(NlogN)
void solve2(vector<int> v, int target)
{
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        int newtarget = target - v[i];
        bsearch(v, i + 1, newtarget);
    }
}

//unordered set O(N)
void solve3(vector<int> v, int target)
{
    unordered_set<int> s;
    for (int i = 0; i < v.size(); i++)
    {
        int x = target - v[i];
        if (s.find(x) != s.end())
        {
            cout << v[i] << "," << x << endl;
            return;
        }
        s.insert(v[i]);
    }
}

int main()
{
    vector<int> v = {10, 2, 4, 3, 6, -6, 5};
    int target = 4;
    solve1(v, target);
    solve2(v, target);
    solve3(v, target);
    return 0;
}