/*

*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solve(vector<int> v, int k)
{
    int i = 0, j = 0, n = v.size();
    vector<int> result;
    queue<int> q;
    while (j < n)
    {
        if (v[j] < 0)
            q.push(v[j]);
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            if (q.size() == 0)
            {
                result.push_back(0);
            }
            else
            {
                result.push_back(q.front());
                if (v[i] == q.front())
                {
                    q.pop();
                }
            }
            i++;
            j++;
        }
    }
    return result;
}

int main()
{
    vector<int> v{12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    vector<int> result = solve(v, k);
    for (auto i : result)
    {
        cout << i << " ";
    }
    return 0;
}