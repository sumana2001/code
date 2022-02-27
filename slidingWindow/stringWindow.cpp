/*
Given two strings, one big string and one small string
find the smallest window in the big string that contains all characters of the small string.
- Window can have additional characters than required.
- If small string has duplicates, then those duplicates must be present with same of higher count in window.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

string findWindow(string s, string p)
{
    int FP[256] = {0};
    int FS[256] = {0};
    for (int i = 0; i < p.length(); i++)
    {
        FP[p[i]]++;
    }
    int cnt = 0, start = 0, windowSize, minWindow=INT_MAX,startIdx=-1;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        FS[ch]++;
        if (FP[ch] != 0 and FS[ch] <= FP[ch])
        {
            cnt++;
        }
        if (cnt == p.length())
        {
            while (FP[s[start]] == 0 or FS[s[start]] > FP[s[start]])
            {
                FS[s[start]]--;
                start++;
            }
            windowSize = i - start + 1;
            if (windowSize < minWindow)
            {
                minWindow = windowSize;
                startIdx = start;
            }
        }
    }
    if(startIdx==-1){
        return "No window found";
    }
    return s.substr(startIdx,minWindow);
}

int main()
{
    string s, p;
    cin >> s >> p;
    cout << findWindow(s, p) << endl;
    return 0;
}