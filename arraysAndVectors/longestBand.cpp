/*
Given an array of integers, find the length of longest band. Band is defined
as a subsequence which can be reordered in such a manner all elements 
appear consecutive (i.e. +/-1)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

//sorting O(NlogN)
int solve1(vector<int> v)
{
    sort(v.begin(), v.end());
    int maximum = 0, count = 1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] + 1 == v[i + 1])
        {
            count++;
        }
        else
        {
            count = 1;
        }
        maximum = max(maximum, count);
    }
    return maximum;
}

//unordered set O(N)
int solve2(vector<int> v)
{
    int maximum = 1;
    unordered_set<int> s;
    for (int i = 0; i < v.size(); i++)
    {
        s.insert(v[i]);
    }
    for (auto ele : s)
    {
        int parent = ele - 1;
        if (s.find(parent) == s.end())
        {
            int count = 1;
            int nextNum = ele + 1;
            while (s.find(nextNum) != s.end())
            {
                nextNum++;
                count++;
            }
            maximum = max(maximum, count);
        }
    }
    return maximum;
}

int main()
{
    vector<int> v = {1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
    cout << solve1(v) << endl;
    cout << solve2(v) << endl;
    return 0;
}