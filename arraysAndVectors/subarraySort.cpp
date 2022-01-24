/*
Given an array of size atleast 2, find the smallest subarray that needs
to be sorted in place so that the entire input array is sorted. If input
array is already sorted, return [-1,-1]. Else return start and end index 
of smallest subarray
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//sorting O(NlogN)
pair<int, int> subarraySort1(vector<int> a)
{
    vector<int> b(a);
    int n = a.size();
    sort(a.begin(), a.end());
    int i = 0, j = n - 1;
    while (i < n && a[i] == b[i])
        i++;
    while (j >= 0 && a[j] == b[j])
        j--;
    if (i == n)
        return {-1, -1};
    return {i, j};
}

// find smallest and largest out of order O(N)
bool outOfOrder(vector<int> v, int i)
{
    int x = v[i];
    if (i == 0)
        return x > v[1];
    if (i == v.size() - 1)
        return x < v[i - 1];
    return x > v[i + 1] or x < v[i - 1];
}

pair<int, int> subarraySort2(vector<int> v)
{
    int n = v.size();
    int smallest = INT_MAX;
    int largest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int x = v[i];
        if (outOfOrder(v, i))
        {
            smallest = min(smallest, x);
            largest = max(largest, x);
        }
    }
    if (smallest == INT_MAX)
        return {-1, -1};
    int left = 0, right = n - 1;
    while (smallest >= v[left])
        left++;
    while (largest <= v[right])
        right--;
    return {left, right};
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 8, 7, 6, 9, 10, 11};
    auto p1 = subarraySort1(v);
    cout << p1.first << " " << p1.second << endl;
    auto p2 = subarraySort2(v);
    cout << p2.first << " " << p2.second << endl;
    return 0;
}