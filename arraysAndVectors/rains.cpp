/*
Given n non-negative integers representing an elevation map where width
of each bar is 1, compute how much water it can trap after raining
*/
#include <iostream>
#include <vector>
using namespace std;

int trappedWater(vector<int> v)
{
    int n = v.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    int maxLeft = 0, maxRight = 0;
    for (int i = 0; i < n; i++)
    {
        left[i] = max(v[i], maxLeft);
        if (v[i] > maxLeft)
            maxLeft = v[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        right[i] = max(v[i], maxRight);
        if (v[i] > maxRight)
            maxRight = v[i];
    }
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int trap = min(left[i], right[i]) - v[i];
        count += trap;
    }
    return count;
}

int main()
{
    vector<int> water = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trappedWater(water) << endl;
    return 0;
}