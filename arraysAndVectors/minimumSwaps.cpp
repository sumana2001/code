/*
Given an array find the minimum number of swaps needed to make the
array sorted.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSwaps(vector<int> v)
{
    int ans = 0;
    int n = v.size();
    pair<int, int> ap[n];
    for (int i = 0; i < v.size(); i++)
    {
        ap[i].first = v[i];
        ap[i].second = i;
    }
    sort(ap, ap + n);
    vector<bool> visited(n, 0);
    for (int i = 0; i < n; i++)
    {
        int old = ap[i].second;
        if (visited[i] == true || old == i)
            continue;
        int node = i, cycle = 0;
        while (!visited[node])
        {
            visited[node] = true;
            int nextNode = ap[node].second;
            node = nextNode;
            cycle++;
        }
        ans += (cycle - 1);
    }
    return ans;
}

int main()
{
    vector<int> v = {5, 4, 3, 2, 1};
    cout << minSwaps(v) << endl;
    return 0;
}