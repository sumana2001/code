/*

*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void brute(vector<vector<int> > &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == 0)
            {
                for (int k = 0; k < v.size(); k++)
                {
                    if (v[k][j] != 0)
                    {
                        v[k][j] = -1;
                    }
                }
                for (int l = 0; l < v[i].size(); l++)
                {
                    if (v[i][l] != 0)
                    {
                        v[i][l] = -1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == -1 || v[i][j] == 0)
            {
                v[i][j] = 0;
            }
        }
    }
}

int main()
{
    vector<vector<int> > v;
    v = {{1,1,1}, {1,0,1}, {1,1,1}};
    brute(v);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}